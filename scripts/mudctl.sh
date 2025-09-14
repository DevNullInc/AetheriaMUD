#!/bin/bash

# SWR MUD Server Control Script
# Portable version that works from any directory

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Get paths relative to script location
SCRIPT_DIR="$(dirname "$0")"
BASE_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
SRC_DIR="$BASE_DIR/src"
AREA_DIR="$BASE_DIR/area"
LOG_DIR="$BASE_DIR/log"
CORE_DIR="$BASE_DIR/core"

# Server configuration
SWR_EXECUTABLE="$SRC_DIR/swr"
STARTUP_SCRIPT="$SRC_DIR/startup.sh"
FALLBACK_SCRIPT="$SRC_DIR/fallback_server.py"
CHECK_SYSTEM_SCRIPT="$SRC_DIR/check_system.sh"

# Default port
DEFAULT_PORT=4848

show_help() {
    echo "SWR MUD Server Control Script"
    echo ""
    echo "Usage: $0 [COMMAND] [OPTIONS]"
    echo ""
    echo "Commands:"
    echo "  status          Show server status and process information"
    echo "  start [port]    Start the server (default port: $DEFAULT_PORT)"
    echo "  stop            Stop the server gracefully"
    echo "  restart [port]  Restart the server"
    echo "  kill            Force kill all server processes"
    echo "  kill-all        Force kill all server and fallback processes"
    echo "  fallback [port] Start fallback server only"
    echo "  cleanup         Clean up old log files and core dumps"
    echo "  logs [count]    Show recent log entries (default: 20 lines)"
    echo "  tail            Follow the latest log file"
    echo "  check           Run system dependency check"
    echo "  setup           Setup account directories and permissions"
    echo "  interactive     Launch interactive menu interface"
    echo "  advanced        Launch advanced interface with live log streaming"
    echo "  help            Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0 start        # Start server on default port"
    echo "  $0 start 4949   # Start server on port 4949"
    echo "  $0 status       # Check server status"
    echo "  $0 logs 50      # Show last 50 log lines"
    echo "  $0 interactive  # Launch interactive menu interface"
    echo "  $0 advanced     # Launch advanced interface with live logs"
    echo ""
    echo "Interactive Modes:"
    echo "  The interactive mode provides a menu-driven interface with:"
    echo "  • Live server status monitoring"
    echo "  • Real-time system information"
    echo "  • Auto-refresh capabilities"
    echo "  • Easy command execution"
    echo ""
    echo "  The advanced mode adds:"
    echo "  • Live log streaming with FIFO pipes"
    echo "  • Split-screen monitoring (main + fallback logs)"
    echo "  • Error highlighting with color coding"
    echo "  • Configurable display (40% logs / 60% menu)"
    echo ""
    echo "Paths:"
    echo "  Base directory:   $BASE_DIR"
    echo "  Source directory: $SRC_DIR"
    echo "  Area directory:   $AREA_DIR"
    echo "  Log directory:    $LOG_DIR"
    echo "  Core directory:   $CORE_DIR"
}

log_message() {
    echo -e "${BLUE}[$(date '+%Y-%m-%d %H:%M:%S')]${NC} $1"
}

error_message() {
    echo -e "${RED}[ERROR]${NC} $1" >&2
}

success_message() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

warning_message() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

# Check if we can find necessary files
check_environment() {
    local missing_files=()
    
    if [[ ! -f "$SWR_EXECUTABLE" ]]; then
        missing_files+=("Server executable: $SWR_EXECUTABLE")
    fi
    
    if [[ ! -f "$STARTUP_SCRIPT" ]]; then
        missing_files+=("Startup script: $STARTUP_SCRIPT")
    fi
    
    if [[ ! -d "$AREA_DIR" ]]; then
        missing_files+=("Area directory: $AREA_DIR")
    fi
    
    if [[ ${#missing_files[@]} -gt 0 ]]; then
        error_message "Missing required files/directories:"
        for file in "${missing_files[@]}"; do
            echo "  - $file"
        done
        echo ""
        echo "Please ensure you're running this script from the correct location"
        echo "and that the SWR server is properly installed."
        return 1
    fi
    
    return 0
}

get_server_processes() {
    # Find processes that might be the SWR server
    local processes
    processes=$(ps aux | grep -E "(swr|startup\.sh)" | grep -v grep | grep -v "$0" || true)
    echo "$processes"
}

get_fallback_processes() {
    # Find fallback server processes
    local processes
    processes=$(ps aux | grep -E "fallback_server\.py" | grep -v grep || true)
    echo "$processes"
}

get_port_usage() {
    local port="$1"
    if command -v ss >/dev/null 2>&1; then
        ss -tlnp | grep ":$port " || true
    elif command -v netstat >/dev/null 2>&1; then
        netstat -tlnp | grep ":$port " || true
    else
        warning_message "Neither ss nor netstat available - cannot check port usage"
        return 1
    fi
}

show_status() {
    log_message "Server Status Check"
    echo ""
    
    # Check server processes
    local server_procs
    server_procs=$(get_server_processes)
    
    if [[ -n "$server_procs" ]]; then
        success_message "Server processes found:"
        echo "$server_procs" | while read -r line; do
            echo "  $line"
        done
    else
        warning_message "No server processes found"
    fi
    
    echo ""
    
    # Check fallback processes
    local fallback_procs
    fallback_procs=$(get_fallback_processes)
    
    if [[ -n "$fallback_procs" ]]; then
        warning_message "Fallback server processes found:"
        echo "$fallback_procs" | while read -r line; do
            echo "  $line"
        done
    else
        echo "No fallback server processes found"
    fi
    
    echo ""
    
    # Check port usage
    local port_usage
    port_usage=$(get_port_usage "$DEFAULT_PORT")
    
    if [[ -n "$port_usage" ]]; then
        echo "Port $DEFAULT_PORT usage:"
        echo "$port_usage" | while read -r line; do
            echo "  $line"
        done
    else
        echo "Port $DEFAULT_PORT is available"
    fi
    
    echo ""
    
    # Check recent activity
    if [[ -d "$LOG_DIR" ]]; then
        local latest_log
        latest_log=$(ls -t "$LOG_DIR"/*.log 2>/dev/null | head -1 || true)
        
        if [[ -n "$latest_log" ]]; then
            echo "Latest log file: $(basename "$latest_log")"
            echo "Last modified: $(stat -c %y "$latest_log" 2>/dev/null || date -r "$latest_log" 2>/dev/null || echo "unknown")"
        else
            echo "No log files found"
        fi
    fi
    
    # Check for fallback status file
    if [[ -f "$BASE_DIR/fallback.status" ]]; then
        warning_message "Fallback status file exists:"
        cat "$BASE_DIR/fallback.status" | sed 's/^/  /'
    fi
}

start_server() {
    local port="${1:-$DEFAULT_PORT}"
    
    log_message "Starting SWR server on port $port"
    
    # Check if server is already running
    local existing_procs
    existing_procs=$(get_server_processes)
    
    if [[ -n "$existing_procs" ]]; then
        warning_message "Server processes already running:"
        echo "$existing_procs" | while read -r line; do
            echo "  $line"
        done
        echo ""
        echo "Use '$0 stop' to stop the server first, or '$0 restart' to restart"
        return 1
    fi
    
    # Change to src directory and start the server
    cd "$SRC_DIR"
    
    log_message "Executing: $STARTUP_SCRIPT $port"
    exec "$STARTUP_SCRIPT" "$port"
}

stop_server() {
    log_message "Stopping SWR server"
    
    # Find server processes
    local server_procs
    server_procs=$(get_server_processes)
    
    if [[ -z "$server_procs" ]]; then
        warning_message "No server processes found to stop"
        return 0
    fi
    
    # Extract PIDs and send SIGTERM
    local pids
    pids=$(echo "$server_procs" | awk '{print $2}' | sort -u)
    
    for pid in $pids; do
        if [[ -n "$pid" && "$pid" =~ ^[0-9]+$ ]]; then
            local proc_name
            proc_name=$(ps -p "$pid" -o comm --no-headers 2>/dev/null || echo "unknown")
            log_message "Sending SIGTERM to PID $pid ($proc_name)"
            kill -TERM "$pid" 2>/dev/null || true
        fi
    done
    
    # Wait for graceful shutdown
    sleep 3
    
    # Check if any processes are still running
    local remaining_procs
    remaining_procs=$(get_server_processes)
    
    if [[ -n "$remaining_procs" ]]; then
        warning_message "Some processes still running, sending SIGKILL"
        local remaining_pids
        remaining_pids=$(echo "$remaining_procs" | awk '{print $2}' | sort -u)
        
        for pid in $remaining_pids; do
            if [[ -n "$pid" && "$pid" =~ ^[0-9]+$ ]]; then
                local proc_name
                proc_name=$(ps -p "$pid" -o comm --no-headers 2>/dev/null || echo "unknown")
                log_message "Force killing PID $pid ($proc_name)"
                kill -KILL "$pid" 2>/dev/null || true
            fi
        done
        
        sleep 1
    fi
    
    # Final check
    local final_procs
    final_procs=$(get_server_processes)
    
    if [[ -z "$final_procs" ]]; then
        success_message "Server stopped successfully"
    else
        error_message "Some processes may still be running:"
        echo "$final_procs" | while read -r line; do
            echo "  $line"
        done
    fi
}

restart_server() {
    local port="${1:-$DEFAULT_PORT}"
    
    log_message "Restarting SWR server"
    
    stop_server
    sleep 2
    start_server "$port"
}

kill_all_processes() {
    log_message "Force killing all server and fallback processes"
    
    # Get all related processes
    local all_procs
    all_procs=$(ps aux | grep -E "(swr|startup\.sh|fallback_server\.py)" | grep -v grep | grep -v "$0" || true)
    
    if [[ -z "$all_procs" ]]; then
        warning_message "No processes found to kill"
        return 0
    fi
    
    # Extract PIDs and kill them
    local pids
    pids=$(echo "$all_procs" | awk '{print $2}' | sort -u)
    
    for pid in $pids; do
        if [[ -n "$pid" && "$pid" =~ ^[0-9]+$ ]]; then
            local proc_name
            proc_name=$(ps -p "$pid" -o comm --no-headers 2>/dev/null || echo "unknown")
            log_message "Force killing PID $pid ($proc_name)"
            kill -KILL "$pid" 2>/dev/null || true
        fi
    done
    
    sleep 1
    
    # Remove fallback status file if it exists
    if [[ -f "$BASE_DIR/fallback.status" ]]; then
        rm -f "$BASE_DIR/fallback.status"
        log_message "Removed fallback status file"
    fi
    
    success_message "All processes killed"
}

start_fallback() {
    local port="${1:-$DEFAULT_PORT}"
    
    log_message "Starting fallback server on port $port"
    
    # Check if fallback script exists
    if [[ ! -f "$FALLBACK_SCRIPT" ]]; then
        error_message "Fallback script not found: $FALLBACK_SCRIPT"
        return 1
    fi
    
    # Check if Python is available
    if ! command -v python3 >/dev/null 2>&1; then
        error_message "Python3 not available - cannot start fallback server"
        return 1
    fi
    
    # Check if port is in use
    local port_usage
    port_usage=$(get_port_usage "$port")
    
    if [[ -n "$port_usage" ]]; then
        warning_message "Port $port appears to be in use:"
        echo "$port_usage" | while read -r line; do
            echo "  $line"
        done
        echo ""
        echo "Continuing anyway - fallback server will handle conflicts"
    fi
    
    # Start fallback server
    cd "$SRC_DIR"
    log_message "Executing: python3 $FALLBACK_SCRIPT $port"
    exec python3 "$FALLBACK_SCRIPT" "$port"
}

cleanup_files() {
    log_message "Cleaning up old files"
    
    local cleaned_count=0
    
    # Clean up old log files (keep last 10)
    if [[ -d "$LOG_DIR" ]]; then
        local old_logs
        old_logs=$(ls -t "$LOG_DIR"/*.log 2>/dev/null | tail -n +11 || true)
        
        if [[ -n "$old_logs" ]]; then
            echo "$old_logs" | while read -r logfile; do
                if [[ -f "$logfile" ]]; then
                    rm -f "$logfile"
                    log_message "Removed old log: $(basename "$logfile")"
                    ((cleaned_count++))
                fi
            done
        fi
    fi
    
    # Clean up old core dumps (keep last 5)
    if [[ -d "$CORE_DIR" ]]; then
        local old_cores
        old_cores=$(ls -t "$CORE_DIR"/core.* 2>/dev/null | tail -n +6 || true)
        
        if [[ -n "$old_cores" ]]; then
            echo "$old_cores" | while read -r corefile; do
                if [[ -f "$corefile" ]]; then
                    rm -f "$corefile"
                    # Also remove associated analysis files
                    rm -f "${corefile}.analysis" "${corefile}-report-"*.txt
                    log_message "Removed old core dump: $(basename "$corefile")"
                    ((cleaned_count++))
                fi
            done
        fi
    fi
    
    # Remove fallback status file if server is not running
    if [[ -f "$BASE_DIR/fallback.status" ]]; then
        local fallback_procs
        fallback_procs=$(get_fallback_processes)
        
        if [[ -z "$fallback_procs" ]]; then
            rm -f "$BASE_DIR/fallback.status"
            log_message "Removed stale fallback status file"
            ((cleaned_count++))
        fi
    fi
    
    if [[ $cleaned_count -eq 0 ]]; then
        success_message "No cleanup needed"
    else
        success_message "Cleanup completed"
    fi
}

show_logs() {
    local line_count="${1:-20}"
    
    if [[ ! -d "$LOG_DIR" ]]; then
        error_message "Log directory not found: $LOG_DIR"
        return 1
    fi
    
    local latest_log
    latest_log=$(ls -t "$LOG_DIR"/*.log 2>/dev/null | head -1 || true)
    
    if [[ -z "$latest_log" ]]; then
        warning_message "No log files found in $LOG_DIR"
        return 1
    fi
    
    log_message "Showing last $line_count lines from $(basename "$latest_log")"
    echo ""
    tail -n "$line_count" "$latest_log"
}

tail_logs() {
    if [[ ! -d "$LOG_DIR" ]]; then
        error_message "Log directory not found: $LOG_DIR"
        return 1
    fi
    
    local latest_log
    latest_log=$(ls -t "$LOG_DIR"/*.log 2>/dev/null | head -1 || true)
    
    if [[ -z "$latest_log" ]]; then
        warning_message "No log files found in $LOG_DIR"
        return 1
    fi
    
    log_message "Following $(basename "$latest_log") (Press 'q' + Enter to quit)"
    echo ""
    
    # Start tail in background
    tail -f "$latest_log" &
    tail_pid=$!
    
    # Monitor for user input to quit
    while true; do
        read -t 1 -n 1 input 2>/dev/null
        if [[ "$input" == "q" ]]; then
            echo -e "\n${YELLOW}Log tail stopped. Returning to menu...${NC}"
            break
        fi
        # Check if tail process is still running
        if ! kill -0 $tail_pid 2>/dev/null; then
            break
        fi
    done
    
    # Clean up tail process and suppress exit code
    kill $tail_pid 2>/dev/null || true
    wait $tail_pid 2>/dev/null || true
}

run_system_check() {
    if [[ -f "$CHECK_SYSTEM_SCRIPT" ]]; then
        log_message "Running system dependency check"
        cd "$SRC_DIR"
        exec "$CHECK_SYSTEM_SCRIPT"
    else
        error_message "System check script not found: $CHECK_SYSTEM_SCRIPT"
        return 1
    fi
}

run_setup() {
    local setup_script="$SCRIPT_DIR/setup_account_dirs.sh"
    
    if [[ -f "$setup_script" ]]; then
        log_message "Setting up account directories and permissions..."
        "$setup_script"
    else
        error_message "Setup script not found: $setup_script"
        echo "Creating account directories manually..."
        
        # Create account directories manually if script is missing
        local account_dir="$BASE_DIR/account"
        mkdir -p "$account_dir"
        
        for letter in {a..z}; do
            mkdir -p "$account_dir/$letter"
            chmod 755 "$account_dir/$letter" 2>/dev/null || true
        done
        
        chmod 755 "$account_dir" 2>/dev/null || true
        success_message "Account directories created successfully"
    fi
}

launch_interactive_mode() {
    local interactive_script="$SCRIPT_DIR/mudctl-interactive.sh"
    
    if [[ -f "$interactive_script" ]]; then
        log_message "Launching interactive mode..."
        exec "$interactive_script"
    else
        error_message "Interactive script not found: $interactive_script"
        echo ""
        echo "Please ensure mudctl-interactive.sh is in the scripts directory."
        echo "You can still use the command-line interface."
        exit 1
    fi
}

launch_advanced_mode() {
    local advanced_script="$SCRIPT_DIR/mudctl-advanced.sh"
    
    if [[ -f "$advanced_script" ]]; then
        log_message "Launching advanced mode with live log streaming..."
        exec "$advanced_script"
    else
        error_message "Advanced script not found: $advanced_script"
        echo ""
        echo "Please ensure mudctl-advanced.sh is in the scripts directory."
        echo "Falling back to regular interactive mode..."
        launch_interactive_mode
    fi
}

# Main command processing
main() {
    local command="${1:-help}"
    
    # Check environment before proceeding (except for help)
    if [[ "$command" != "help" && "$command" != "--help" && "$command" != "-h" ]]; then
        if ! check_environment; then
            exit 1
        fi
    fi
    
    case "$command" in
        "status")
            show_status
            ;;
        "start")
            start_server "$2"
            ;;
        "stop")
            stop_server
            ;;
        "restart")
            restart_server "$2"
            ;;
        "kill")
            stop_server
            ;;
        "kill-all")
            kill_all_processes
            ;;
        "fallback")
            start_fallback "$2"
            ;;
        "cleanup")
            cleanup_files
            ;;
        "logs")
            show_logs "$2"
            ;;
        "tail")
            tail_logs
            ;;
        "check")
            run_system_check
            ;;
        "setup")
            run_setup
            ;;
        "interactive")
            launch_interactive_mode
            ;;
        "advanced")
            launch_advanced_mode
            ;;
        "help"|"--help"|"-h")
            show_help
            ;;
        *)
            error_message "Unknown command: $command"
            echo ""
            show_help
            exit 1
            ;;
    esac
}

# Run main function with all arguments
main "$@"
