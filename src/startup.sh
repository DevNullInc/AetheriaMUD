#!/usr/bin/env bash
# Startup script for the SWR server - https://github.com/SWTFE/SWTFE
# Fail hard on script errors, but allow diagnostics to be best-effort
set -euo pipefail

port="${1:-4848}"

# Get the script directory (src) and set up paths
SCRIPT_DIR="$(dirname "$0")"
SRC_DIR="$(cd "$SCRIPT_DIR" && pwd)"
BASE_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
AREA_DIR="$BASE_DIR/area"
LOG_DIR="$BASE_DIR/log"
CORE_DIR="$BASE_DIR/core"

# Ensure log and core directories exist
mkdir -p "$LOG_DIR"
mkdir -p "$CORE_DIR"

# Change to area directory for game data access, but remember paths
cd "$AREA_DIR"

echo "Working directory: $(pwd)"
echo "SWR executable: $SRC_DIR/swr"
echo "Log directory: $LOG_DIR"
echo "Core dump directory: $CORE_DIR"
echo "Starting server on port $port"

# Check if port is already in use and handle conflicts
check_and_cleanup_port() {
    local target_port="$1"
    
    echo "Checking port $target_port availability..."
    
    # Find processes using the target port
    local port_users=$(ss -tlnp | grep ":$target_port " | awk '{print $6}' | grep -o 'pid=[0-9]*' | cut -d'=' -f2 | sort -u)
    
    if [[ -n "$port_users" ]]; then
        echo "Port $target_port is currently in use by the following processes:"
        for pid in $port_users; do
            if [[ -n "$pid" ]]; then
                local process_info=$(ps -p "$pid" -o pid,ppid,cmd --no-headers 2>/dev/null || echo "$pid unknown unknown")
                echo "  PID $process_info"
            fi
        done
        
        echo "Attempting to stop processes using port $target_port..."
        for pid in $port_users; do
            if [[ -n "$pid" ]]; then
                local process_name=$(ps -p "$pid" -o comm --no-headers 2>/dev/null || echo "unknown")
                echo "  Sending SIGTERM to PID $pid ($process_name)..."
                kill -TERM "$pid" 2>/dev/null || true
            fi
        done
        
        # Wait a moment for graceful shutdown
        sleep 3
        
        # Check if any processes are still running
        local remaining=$(ss -tlnp | grep ":$target_port " | awk '{print $6}' | grep -o 'pid=[0-9]*' | cut -d'=' -f2 | sort -u)
        if [[ -n "$remaining" ]]; then
            echo "Some processes still using port $target_port, sending SIGKILL..."
            for pid in $remaining; do
                if [[ -n "$pid" ]]; then
                    local process_name=$(ps -p "$pid" -o comm --no-headers 2>/dev/null || echo "unknown")
                    echo "  Force killing PID $pid ($process_name)..."
                    kill -KILL "$pid" 2>/dev/null || true
                fi
            done
            sleep 1
        fi
        
        # Final check
        local final_check=$(ss -tlnp | grep ":$target_port " || true)
        if [[ -n "$final_check" ]]; then
            echo "Warning: Port $target_port may still be in use:"
            echo "$final_check"
        else
            echo "Port $target_port is now available."
        fi
    else
        echo "Port $target_port is available."
    fi
}

# Clean up the target port before starting
check_and_cleanup_port "$port"

# Add executable and dependency checks before starting the server
check_server_executable() {
    local exe="$1"
    
    echo "Performing pre-startup checks..."
    
    # Check if executable exists
    if [[ ! -f "$exe" ]]; then
        echo "ERROR: Server executable not found: $exe"
        return 1
    fi
    
    # Check if executable is executable
    if [[ ! -x "$exe" ]]; then
        echo "ERROR: Server executable is not executable: $exe"
        echo "Try: chmod +x $exe"
        return 1
    fi
    
    # Check basic library dependencies
    if command -v ldd >/dev/null 2>&1; then
        echo "Checking library dependencies..."
        if ! ldd "$exe" >/dev/null 2>&1; then
            echo "WARNING: Library dependency check failed"
            echo "This may indicate missing libraries or architecture mismatch"
            echo "Run 'ldd $exe' to see specific issues"
        else
            local missing_libs=$(ldd "$exe" 2>&1 | grep "not found" || true)
            if [[ -n "$missing_libs" ]]; then
                echo "ERROR: Missing library dependencies:"
                echo "$missing_libs"
                echo ""
                echo "Please install the missing libraries or recompile the server"
                return 1
            fi
        fi
    fi
    
    echo "Pre-startup checks completed."
    return 0
}

# Run pre-startup checks
if ! check_server_executable "$SRC_DIR/swr"; then
    echo "Pre-startup checks failed. Cannot start server."
    echo "Starting fallback server for maintenance..."
    
    fallback_pid=$(start_fallback_server $port)
    if [[ $fallback_pid -gt 0 ]]; then
        echo "Fallback server is running. Please fix the issues before restarting."
        echo "Fallback server PID: $fallback_pid"
        wait $fallback_pid
    fi
    
    exit 1
fi

ulimit -c unlimited

# The email address to send crash alerts to.
ALERT_EMAIL="crashalert@renegadeinc.net"

# Hotboot retry configuration
MAX_HOTBOOT_ATTEMPTS=3
HOTBOOT_DELAY=5  # seconds between hotboot attempts
FALLBACK_SERVER="$SRC_DIR/fallback_server.py"

# Define a function to send the email alert.
send_crash_alert() {
    # $1=coredump path, $2=logfile, $3=exe path, $4=pid
    local corefile="$1"
    local logfile="$2"
    local exe="$3"
    local pid="$4"

    local subject="CRITICAL: MUD Crash — PID ${pid}"


    # Extract the last player command from the log: prefer the line after "SEGMENTATION VIOLATION",
    # otherwise fall back to the last "** player: command" entry.
    local last_cmd=""
    if [[ -f "$logfile" ]]; then
        last_cmd=$(awk '/SEGMENTATION VIOLATION/{flag=1;next} flag && NF {print;flag=0}' "$logfile" | tail -n 1 || true)
        if [[ -z "$last_cmd" ]]; then
            last_cmd=$(grep -a "^\*\* " "$logfile" | tail -n 1 || true)
        fi
    fi


    # Obtain a concise crash location using gdb if available.
    local crash_loc=""
    local bt_summary=""
    if command -v gdb >/dev/null 2>&1; then
        # Full backtrace (all threads), then parse frame #0 from the crashing thread.
        bt_summary=$(gdb -q -n -batch \
            -ex "set pagination off" \
            -ex "thread apply all bt full" \
            --args "$exe" "$corefile" 2>&1)
        crash_loc=$(printf "%s\n" "$bt_summary" | awk '/^#0 /{print;exit}')
        # If #0 not present, fallback to first line containing " at .*:[0-9]+"
        if [[ -z "$crash_loc" ]]; then
            crash_loc=$(printf "%s\n" "$bt_summary" | grep -E " at .*:[0-9]+" | head -n1)
        fi
    else
        crash_loc="gdb not installed; unable to resolve source line"
        bt_summary="gdb not installed on host; detailed backtrace unavailable"
    fi


    local message_body="\
MUD server crash detected.\n\n
Timestamp: $(date)\n
Working Directory: $(pwd)\n
Executable: ${exe}\n
PID: ${pid}\n
Coredump File: ${corefile}\n
Log File: ${logfile}\n\n
Last Command: ${last_cmd}\n\nTop Frame: ${crash_loc}\n\n
--- Recent log tail ---\n$(tail -n 60 "$logfile" 2>/dev/null)\n
--- GDB backtrace ---\n${bt_summary}
"


    # Send the email, fallback to text file
    if command -v mail >/dev/null 2>&1; then
        printf "%s\n" "$message_body" | mail -s "$subject" "$ALERT_EMAIL" || true
    else
        (echo "$message_body" > "$corefile-report-${pid}.txt" || true)
    fi
}

check_for_coredump() {
    local pid="$1"
    local exe="$2"
    local logfile="$3"
    local hotboot_attempts="${4:-0}"  # Track hotboot attempts

    wait $pid
    local exit_code=$?

    # Look for core dumps in current directory (area) - they'll be moved to core directory
    local latest_core=$(ls -t core.* 2>/dev/null | head -n 1 || true)

    # Check for immediate exit with error codes that indicate system issues
    if [[ $exit_code -eq 127 ]]; then
        echo "ERROR: Command not found or missing dependencies (exit code 127)"
        echo "This usually indicates missing libraries or the executable is not found"
        if [[ -f "$logfile" ]]; then
            echo "Last few lines from log:"
            tail -5 "$logfile" || true
        fi
        return 2  # Special code for system errors
    elif [[ $exit_code -eq 126 ]]; then
        echo "ERROR: Permission denied or executable format error (exit code 126)"
        return 2  # Special code for system errors
    elif [[ $exit_code -gt 0 && $exit_code -lt 125 ]]; then
        echo "Server exited with error code $exit_code"
        # Check if this was a very quick exit (less than 5 seconds might indicate config issues)
        if [[ -f "$logfile" ]]; then
            local log_size=$(stat -c%s "$logfile" 2>/dev/null || echo "0")
            if [[ $log_size -lt 1000 ]]; then
                echo "Server exited very quickly with minimal logging - likely a configuration error"
                echo "Log contents:"
                cat "$logfile" || true
                return 2  # Treat as system error
            fi
        fi
    fi

    # Send alert and move core dump if detected
    if [[ -n "$latest_core" ]]; then
        # Create timestamped filename for the core dump
        local timestamp=$(date +"%Y%m%d_%H%M%S")
        local new_core_name="core.swr.${timestamp}.${pid}"
        local new_core_path="$CORE_DIR/$new_core_name"
        
        # Move core dump to core directory with timestamped name
        mv "$latest_core" "$new_core_path"
        echo "Core dump moved to: $new_core_path"
        
        # Update the corefile path for the alert
        send_crash_alert "$new_core_path" "$logfile" "$exe" "$pid"
        
        # Automatically run analysis if the script exists
        if [[ -x "$CORE_DIR/analyze_core.sh" ]]; then
            echo "Running automatic core dump analysis..."
            "$CORE_DIR/analyze_core.sh" "$new_core_path" "$exe" || true
        fi
        
        return 1  # Indicate crash occurred
    fi
    
    # If we reach here with non-zero exit code, it's an error exit without core dump
    if [[ $exit_code -ne 0 ]]; then
        return 1  # Treat as crash for recovery purposes
    fi
    
    return 0  # Normal exit
}

# Attempt hotboot recovery
attempt_hotboot() {
    local attempt_num="$1"
    local logfile="$2"
    
    echo "Attempting hotboot recovery (attempt $attempt_num/$MAX_HOTBOOT_ATTEMPTS)..."
    
    # Check if hotboot file exists (created by previous crash)
    local hotboot_file="$BASE_DIR/system/copyover.dat"
    
    if [[ ! -f "$hotboot_file" ]]; then
        echo "No hotboot data file found - attempting normal restart instead"
        return $(attempt_normal_restart "$attempt_num" "$logfile")
    fi
    
    echo "Hotboot data file found, attempting recovery..."
    
    # Brief delay before starting
    sleep "$HOTBOOT_DELAY"
    
    # Start server with hotboot recovery arguments
    # The MUD expects: swr <port> hotboot <control_socket> <imc_socket>
    # We'll use dummy values for sockets since we don't have the original ones
    echo "Starting server with hotboot recovery..."
    "$SRC_DIR/swr" $port hotboot -1 -1 >"$logfile" 2>&1 &
    local pid=$!
    
    # Give the server a bit more time to start up with hotboot
    sleep 15
    
    # Check if process is still running
    if kill -0 "$pid" 2>/dev/null; then
        echo "Hotboot attempt $attempt_num appears successful (PID: $pid)"
        return $pid
    else
        echo "Hotboot attempt $attempt_num failed - trying normal restart"
        # Remove the corrupt hotboot file
        rm -f "$hotboot_file"
        return $(attempt_normal_restart "$attempt_num" "$logfile")
    fi
}

# Attempt normal server restart (fallback when hotboot fails)
attempt_normal_restart() {
    local attempt_num="$1"
    local logfile="$2"
    
    echo "Attempting normal server restart (recovery attempt $attempt_num/$MAX_HOTBOOT_ATTEMPTS)..."
    
    # Brief delay before starting
    sleep "$HOTBOOT_DELAY"
    
    # Start server normally
    echo "Starting server normally..."
    "$SRC_DIR/swr" $port >"$logfile" 2>&1 &
    local pid=$!
    
    # Give the server time to start
    sleep 10
    
    # Check if process is still running
    if kill -0 "$pid" 2>/dev/null; then
        echo "Normal restart attempt $attempt_num appears successful (PID: $pid)"
        return $pid
    else
        echo "Normal restart attempt $attempt_num failed - process died immediately"
        return 0
    fi
}

# Start the fallback server
start_fallback_server() {
    local fallback_port="$1"
    
    echo "All hotboot attempts failed. Starting fallback server..."
    echo "Fallback server will accept connections on port $fallback_port"
    echo "Players will be notified that the server is down for maintenance."
    
    # First, ensure the port is clear for the fallback server
    echo "Ensuring port $fallback_port is available for fallback server..."
    check_and_cleanup_port "$fallback_port"
    
    # Check if Python is available for the fallback server
    if command -v python3 >/dev/null 2>&1 && [[ -x "$FALLBACK_SERVER" ]]; then
        echo "Starting Python-based fallback server on port $fallback_port..."
        "$FALLBACK_SERVER" "$fallback_port" &
        local fallback_pid=$!
        echo "Fallback server started (PID: $fallback_pid)"
        
        # Wait a moment to ensure it started successfully
        sleep 2
        if kill -0 "$fallback_pid" 2>/dev/null; then
            echo "Fallback server is running successfully."
            
            # Create a status file so admins know fallback is running
            {
                echo "Fallback server running on port $fallback_port (PID: $fallback_pid)"
                echo "Started: $(date)"
                echo "Main server failed after $MAX_HOTBOOT_ATTEMPTS hotboot attempts"
                echo "Startup script PID: $$"
                echo "Port cleanup performed: yes"
            } > "$BASE_DIR/fallback.status"
            
            return $fallback_pid
        else
            echo "Error: Fallback server failed to start or died immediately."
            return 0
        fi
    else
        echo "Error: Python3 not available or fallback server script not found."
        echo "Cannot start fallback server. Manual intervention required."
        return 0
    fi
}

# Main server startup function
start_main_server() {
    # Ensure port is available before starting main server
    echo "Performing pre-startup checks..."
    check_and_cleanup_port "$port"

    echo "Checking library dependencies..."
    # Run dependency check if available
    if [[ -f "$BASE_DIR/scripts/check_system.sh" ]]; then
        if ! "$BASE_DIR/scripts/check_system.sh" >/dev/null 2>&1; then
            echo "Warning: System dependency check found issues"
            echo "Continuing with startup, but server may fail..."
        fi
    fi
    echo "Pre-startup checks completed."

    echo "Preparing to start main server..."
    check_and_cleanup_port "$port"

    echo "Starting main server (attempt 1)..."
    # Launch server from src directory but run in area directory for data access
    "$SRC_DIR/swr" $port >"$logfile" 2>&1 &
    pid=$!
    echo "Main server started (PID: $pid)"

    # Give the server time to initialize (check every few seconds for up to 30 seconds)
    local startup_timeout=30
    local check_interval=3
    local elapsed=0
    local server_running=false
    
    echo "Monitoring server startup..."
    while [[ $elapsed -lt $startup_timeout ]]; do
        if kill -0 "$pid" 2>/dev/null; then
            # Server is still running, check if it's listening on the port
            if ss -tuln 2>/dev/null | grep -q ":$port " || netstat -tuln 2>/dev/null | grep -q ":$port "; then
                echo "Server successfully started and listening on port $port"
                server_running=true
                break
            fi
            echo "Server running, waiting for port to become active..."
        else
            # Server process has died, check for crash
            echo "Server process died during startup"
            break
        fi
        
        sleep $check_interval
        elapsed=$((elapsed + check_interval))
    done
    
    if [[ "$server_running" == true ]]; then
        echo "Server startup successful! Server is running normally."
        echo "Server PID: $pid"
        echo "Port: $port"
        echo "Log file: $logfile"
        exit 0
    fi
    
    # If we get here, the server didn't start properly
    echo "Server failed to start properly within $startup_timeout seconds"
    
    # Check what happened - did it crash or just fail to bind to port?
    if kill -0 "$pid" 2>/dev/null; then
        echo "Server process is still running but not responding on port $port"
        echo "This might indicate a configuration issue or port binding problem"
        kill "$pid" 2>/dev/null || true
        wait "$pid" 2>/dev/null || true
        exit 1
    fi

    # Server process died - check for crash or system errors
    wait "$pid" 2>/dev/null || true
    local exit_code=$?
    
    # Check for core dump and system errors
    local latest_core=$(ls -t core.* 2>/dev/null | head -n 1 || true)
    
    # Handle system errors first
    if [[ $exit_code -eq 127 ]]; then
        echo "ERROR: Command not found or missing dependencies (exit code 127)"
        echo "This usually indicates missing libraries or the executable is not found"
        if [[ -f "$logfile" ]]; then
            echo "Last few lines from log:"
            tail -5 "$logfile" || true
        fi
        start_fallback_for_system_error
        exit 1
    elif [[ $exit_code -eq 126 ]]; then
        echo "ERROR: Permission denied or executable format error (exit code 126)"
        start_fallback_for_system_error
        exit 1
    elif [[ $exit_code -gt 0 && $exit_code -lt 125 ]]; then
        echo "Server exited with error code $exit_code"
        # Check if this was a very quick exit (less than 5 seconds might indicate config issues)
        if [[ -f "$logfile" ]]; then
            local log_size=$(stat -c%s "$logfile" 2>/dev/null || echo "0")
            if [[ $log_size -lt 1000 ]]; then
                echo "Server exited very quickly with minimal logging - likely a configuration error"
                echo "Log contents:"
                cat "$logfile" || true
                start_fallback_for_system_error
                exit 1
            fi
        fi
    fi

    # Handle core dump
    if [[ -n "$latest_core" ]]; then
        # Create timestamped filename for the core dump
        local timestamp=$(date +"%Y%m%d_%H%M%S")
        local new_core_name="core.swr.${timestamp}.${pid}"
        local new_core_path="$CORE_DIR/$new_core_name"
        
        # Move core dump to core directory with timestamped name
        mv "$latest_core" "$new_core_path"
        echo "Core dump moved to: $new_core_path"
        
        # Send alert and run analysis
        send_crash_alert "$new_core_path" "$logfile" "$SRC_DIR/swr" "$pid"
        
        if [[ -x "$CORE_DIR/analyze_core.sh" ]]; then
            echo "Running automatic core dump analysis..."
            "$CORE_DIR/analyze_core.sh" "$new_core_path" "$SRC_DIR/swr" || true
        fi
        
        echo "Server crashed! Beginning recovery process..."
        start_recovery_process
        exit 1
    fi
    
    # If we reach here, server exited without core dump
    if [[ $exit_code -ne 0 ]]; then
        echo "Server exited with error (no core dump)"
        start_recovery_process
        exit 1
    else
        echo "Server exited normally (unusual for a MUD server)"
        echo "Check the log file: $logfile"
        exit 0
    fi
}

# Helper function for system error fallback
start_fallback_for_system_error() {
    echo "FATAL: System error detected - cannot start server!"
    echo "This appears to be a configuration or dependency issue."
    echo "Please check:"
    echo "  - Server executable exists and has correct permissions"
    echo "  - All required libraries are available"
    echo "  - System configuration is correct"
    echo ""
    echo "Common issues:"
    echo "  - Missing glibc version (check: ldd $SRC_DIR/swr)"
    echo "  - Wrong architecture (32-bit vs 64-bit)"
    echo "  - Missing shared libraries"
    echo ""
    echo "Starting fallback server for maintenance..."
    
    local fallback_pid=$(start_fallback_server $port)
    if [[ $fallback_pid -gt 0 ]]; then
        echo "Fallback server is running. Please fix the system issues before restarting."
        echo "Fallback server PID: $fallback_pid" 
        wait $fallback_pid
    fi
}

# Helper function for crash recovery
start_recovery_process() {
    # Initialize hotboot attempt counter
    local hotboot_attempts=0
    local recovery_successful=false
    
    # Try hotboot recovery up to MAX_HOTBOOT_ATTEMPTS times
    while [[ $hotboot_attempts -lt $MAX_HOTBOOT_ATTEMPTS ]]; do
        hotboot_attempts=$((hotboot_attempts + 1))
        
        # Find next log index for hotboot attempt
        local i=1000
        while [[ -f "$LOG_DIR/$i.log" ]]; do
            i=$((i + 1))
        done
        local hotboot_logfile="$LOG_DIR/$i.log"
        
        # Attempt hotboot
        local hotboot_pid=$(attempt_hotboot $hotboot_attempts "$hotboot_logfile")
        
        if [[ $hotboot_pid -gt 0 ]]; then
            echo "Hotboot successful! Monitoring server..."
            # Check if the hotboot server stays alive for reasonable time
            sleep 15
            if kill -0 "$hotboot_pid" 2>/dev/null; then
                echo "Hotboot recovery successful - server running normally"
                recovery_successful=true
                break
            else
                echo "Hotboot server crashed again (attempt $hotboot_attempts)"
            fi
        fi
        
        if [[ $hotboot_attempts -lt $MAX_HOTBOOT_ATTEMPTS ]]; then
            echo "Waiting before next hotboot attempt..."
            sleep $((HOTBOOT_DELAY * 2))  # Longer delay between attempts
        fi
    done
    
    # If all hotboot attempts failed, start fallback server
    if [[ "$recovery_successful" == false ]]; then
        echo "All recovery attempts failed!"
        
        # Start fallback server
        local fallback_pid=$(start_fallback_server $port)
        
        if [[ $fallback_pid -gt 0 ]]; then
            echo "Fallback server is running. Manual intervention required to restore main server."
            echo "Fallback server PID: $fallback_pid"
            echo "To stop fallback: kill $fallback_pid"
            echo "To restart main server: restart this script after fixing issues"
            
            # Wait for fallback server (it runs indefinitely)
            wait $fallback_pid
        fi
        
        echo "Fallback server stopped. Exiting startup script."
    fi
}

# Main execution starts here
# Validate arguments
if [[ $# -eq 0 ]]; then
    echo "Usage: $0 <port>"
    exit 1
fi

port="$1"

# Validate port number
if ! [[ "$port" =~ ^[0-9]+$ ]] || [[ "$port" -lt 1024 ]] || [[ "$port" -gt 65535 ]]; then
    echo "Error: Port must be a number between 1024 and 65535"
    exit 1
fi

# Find next available log file
i=1000
while [[ -f "$LOG_DIR/$i.log" ]]; do
    i=$((i + 1))
done
logfile="$LOG_DIR/$i.log"

echo "Working directory: $AREA_DIR"
echo "SWR executable: $SRC_DIR/swr"
echo "Log directory: $LOG_DIR"
echo "Core dump directory: $CORE_DIR"
echo "Starting server on port $port"

# Ensure we're in the area directory
cd "$AREA_DIR" || {
    echo "Error: Cannot change to area directory: $AREA_DIR"
    exit 1
}

# Start the server
start_main_server