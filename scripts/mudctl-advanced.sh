#!/bin/bash

# *********************************************************************************************************************************
# *                                                                                                                   ;           *
# *                                                                                                                  ED.          *
# *                        ,;                             ,;                                                  :      E#Wi         *
# *                      f#i          .    .            f#i j.         t                                      Ef     E###G.       *
# *             ..     .E#t  GEEEEEEELDi   Dt         .E#t  EW,        Ej             ..           ..       : E#t    E#fD#W;      *
# *            ;W,    i#W,   ,;;L#K;;.E#i  E#i       i#W,   E##j       E#,           ;W,          ,W,     .Et E#t    E#t t##L     *
# *           j##,   L#D.       t#E   E#t  E#t      L#D.    E###D.     E#t          j##,         t##,    ,W#t E#t    E#t  .E#K,   *
# *          G###, :K#Wfff;     t#E   E#t  E#t    :K#Wfff;  E#jG#W;    E#t         G###,        L###,   j###t E#t fi E#t    j##f  *
# *        :E####, i##WLLLLt    t#E   E########f. i##WLLLLt E#t t##f   E#t       :E####,      .E#j##,  G#fE#t E#t L#jE#t    :E#K: *
# *       ;W#DG##,  .E#L        t#E   E#j..K#j...  .E#L     E#t  :K#E: E#t      ;W#DG##,     ;WW; ##,:K#i E#t E#t L#LE#t   t##L   *
# *      j###DW##,    f#E:      t#E   E#t  E#t       f#E:   E#KDDDD###iE#t     j###DW##,    j#E.  ##f#W,  E#t E#tf#E:E#t .D#W;    *
# *     G##i,,G##,     ,WW;     t#E   E#t  E#t        ,WW;  E#f,t#Wi,,,E#t    G##i,,G##,  .D#L    ###K:   E#t E###f  E#tiW#G.     *
# *   :K#K:   L##,      .D#;    t#E   f#t  f#t         .D#; E#t  ;#W:  E#t  :K#K:   L##, :K#t     ##D.    E#t E#K,   E#K##i       *
# *  ;##D.    L##,        tt     fE    ii   ii           tt DWi   ,KK: E#t ;##D.    L##, ...      #G      ..  EL     E##D.        *
# *  ,,,      .,,                 :                                    ,;. ,,,      .,,           j           :      E#t          *
# *                                                                                                                  L:           *
# *********************************************************************************************************************************
# *                                                                                                                               *
# *                                                  AetheriaMUD code                                                             *
# *                               copyright (c) 2025 /dev/null Industries - StygianRenegade                                       *
# *                                                                                                                               *
# *********************************************************************************************************************************
# *                                    AetheriaMUD Server Advanced Interactive Controller                                         *
# *                       Enhanced version with live log streaming, FIFO pipes, and split-screen monitoring                       *
# *********************************************************************************************************************************

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
MAGENTA='\033[0;35m'
WHITE='\033[1;37m'
NC='\033[0m' # No Color
BOLD='\033[1m'
DIM='\033[2m'

# Terminal control
CLEAR='\033[2J'
HOME='\033[H'
HIDE_CURSOR='\033[?25l'
SHOW_CURSOR='\033[?25h'
SAVE_CURSOR='\033[s'
RESTORE_CURSOR='\033[u'

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
CHECK_SYSTEM_SCRIPT="$SCRIPT_DIR/check_system.sh"
MUDCTL_SCRIPT="$SCRIPT_DIR/mudctl.sh"

# FIFO and monitoring configuration
FIFO_DIR="/tmp/swr-monitor-$$"
MAIN_LOG_FIFO="$FIFO_DIR/main.fifo"
FALLBACK_LOG_FIFO="$FIFO_DIR/fallback.fifo"
COMBINED_LOG_FIFO="$FIFO_DIR/combined.fifo"

# Default settings
DEFAULT_PORT=4848
MONITOR_MODE=false
REFRESH_INTERVAL=2
LOG_LINES=100
SPLIT_MODE=false

# Terminal dimensions
TERM_HEIGHT=$(tput lines 2>/dev/null || echo 24)
TERM_WIDTH=$(tput cols 2>/dev/null || echo 80)
LOG_HEIGHT=$((TERM_HEIGHT * 40 / 100))  # Top 40% for logs
MENU_HEIGHT=$((TERM_HEIGHT - LOG_HEIGHT - 2))  # Bottom 60% for menu (minus borders)

# Process tracking
LOG_TAIL_PIDS=()
FIFO_PROCESSOR_PIDS=()

# Cleanup on exit
cleanup() {
    echo -e "${SHOW_CURSOR}"
    stty echo
    
    # Kill all background processes
    for pid in "${LOG_TAIL_PIDS[@]}" "${FIFO_PROCESSOR_PIDS[@]}"; do
        if [[ -n "$pid" ]]; then
            kill "$pid" 2>/dev/null || true
        fi
    done
    
    # Clean up FIFOs
    if [[ -d "$FIFO_DIR" ]]; then
        rm -rf "$FIFO_DIR"
    fi
    
    clear
    exit 0
}

trap cleanup SIGINT SIGTERM EXIT

# Initialize FIFOs
setup_fifos() {
    mkdir -p "$FIFO_DIR"
    
    # Create FIFOs
    mkfifo "$MAIN_LOG_FIFO" 2>/dev/null || true
    mkfifo "$FALLBACK_LOG_FIFO" 2>/dev/null || true
    mkfifo "$COMBINED_LOG_FIFO" 2>/dev/null || true
    
    # Start log processors
    start_log_processors
}

# Enhanced log processor with error highlighting
process_main_logs() {
    local latest_log
    
    while true; do
        # Find the latest log file
        latest_log=$(ls -t "$LOG_DIR"/*.log 2>/dev/null | head -1 || echo "")
        
        if [[ -n "$latest_log" && -f "$latest_log" ]]; then
            # Process log with error highlighting and timestamp formatting
            tail -n "$LOG_LINES" -F "$latest_log" 2>/dev/null | while IFS= read -r line; do
                local colored_line="$line"
                local timestamp=$(date '+%H:%M:%S')
                
                # Highlight critical errors and important events
                if echo "$line" | grep -qi "error\|segmentation\|violation\|crash\|abort\|fatal\|critical"; then
                    colored_line="${RED}${BOLD}$line${NC}"
                elif echo "$line" | grep -qi "warning\|warn"; then
                    colored_line="${YELLOW}$line${NC}"
                elif echo "$line" | grep -qi "connected\|login\|logout\|enter\|quit"; then
                    colored_line="${GREEN}$line${NC}"
                elif echo "$line" | grep -qi "command\|say\|tell\|chat"; then
                    colored_line="${CYAN}$line${NC}"
                elif echo "$line" | grep -qi "save\|load\|boot"; then
                    colored_line="${BLUE}$line${NC}"
                fi
                
                # Add timestamp and send to FIFO
                echo -e "${DIM}[$timestamp]${NC} $colored_line" > "$MAIN_LOG_FIFO"
            done &
            
            LOG_TAIL_PIDS+=($!)
            break
        else
            # No log file available
            echo -e "${DIM}[$(date '+%H:%M:%S')] ${YELLOW}No main server log available${NC}" > "$MAIN_LOG_FIFO"
            sleep 2
        fi
    done
}

# Process fallback server logs
process_fallback_logs() {
    # Check for fallback server log or create placeholder
    local fallback_log="/tmp/fallback-server-$$.log"
    
    # Monitor fallback processes and their output
    while true; do
        local fallback_procs=$(ps aux | grep -E "fallback_server\.py" | grep -v grep || true)
        
        if [[ -n "$fallback_procs" ]]; then
            # Fallback is running, show its status
            local timestamp=$(date '+%H:%M:%S')
            local pid=$(echo "$fallback_procs" | head -1 | awk '{print $2}')
            echo -e "${DIM}[$timestamp]${NC} ${YELLOW}Fallback server active (PID: $pid)${NC}" > "$FALLBACK_LOG_FIFO"
            
            # Try to capture fallback output if available
            if [[ -f "$fallback_log" ]]; then
                tail -n 5 -F "$fallback_log" 2>/dev/null | while IFS= read -r line; do
                    echo -e "${DIM}[$(date '+%H:%M:%S')]${NC} ${YELLOW}FB:${NC} $line" > "$FALLBACK_LOG_FIFO"
                done &
                LOG_TAIL_PIDS+=($!)
            fi
        else
            # No fallback running
            echo -e "${DIM}[$(date '+%H:%M:%S')]${NC} ${DIM}Fallback server: inactive${NC}" > "$FALLBACK_LOG_FIFO"
        fi
        
        sleep 5
    done &
    
    FIFO_PROCESSOR_PIDS+=($!)
}

# Combine logs for unified view
combine_logs() {
    while true; do
        # Read from both FIFOs and merge with prefixes
        {
            timeout 1 cat "$MAIN_LOG_FIFO" 2>/dev/null | sed 's/^/[MAIN] /' || true
            timeout 1 cat "$FALLBACK_LOG_FIFO" 2>/dev/null | sed 's/^/[FALL] /' || true
        } | head -n "$LOG_LINES" > "$COMBINED_LOG_FIFO"
        
        sleep 0.5
    done &
    
    FIFO_PROCESSOR_PIDS+=($!)
}

# Start all log processors
start_log_processors() {
    process_main_logs &
    FIFO_PROCESSOR_PIDS+=($!)
    
    process_fallback_logs &
    
    if [[ "$SPLIT_MODE" == "false" ]]; then
        combine_logs
    fi
}

# Display log area (top 40% of screen)
display_log_area() {
    local start_line=1
    local end_line=$LOG_HEIGHT
    
    # Position cursor at top of screen
    echo -ne "\033[${start_line};1H"
    
    if [[ "$SPLIT_MODE" == "true" ]]; then
        # Split screen mode - show both logs side by side
        display_split_logs
    else
        # Single log view
        display_single_log
    fi
    
    # Draw separator line
    echo -ne "\033[$((LOG_HEIGHT + 1));1H"
    printf '%*s\n' "$TERM_WIDTH" '' | tr ' ' '─'
}

# Display logs in split mode
display_split_logs() {
    local half_width=$((TERM_WIDTH / 2 - 1))
    local line_num=1
    
    # Headers
    echo -ne "\033[${line_num};1H"
    printf "%-${half_width}s${BOLD}${BLUE}│${NC}%-${half_width}s" \
           "${BOLD}${GREEN} MAIN SERVER LOGS ${NC}" \
           "${BOLD}${YELLOW} FALLBACK LOGS ${NC}"
    ((line_num++))
    
    # Content area
    while [[ $line_num -le $LOG_HEIGHT ]]; do
        echo -ne "\033[${line_num};1H"
        
        # Read one line from each FIFO
        local main_line=$(timeout 0.1 head -n 1 "$MAIN_LOG_FIFO" 2>/dev/null | cut -c1-$half_width || echo "")
        local fallback_line=$(timeout 0.1 head -n 1 "$FALLBACK_LOG_FIFO" 2>/dev/null | cut -c1-$half_width || echo "")
        
        printf "%-${half_width}s${BLUE}│${NC}%-${half_width}s" "$main_line" "$fallback_line"
        ((line_num++))
    done
}

# Display single combined log
display_single_log() {
    local line_num=1
    
    # Header
    echo -ne "\033[${line_num};1H"
    echo -e "${BOLD}${GREEN} LIVE SERVER LOGS ${NC}${DIM}(last $LOG_LINES lines)${NC}"
    ((line_num++))
    
    # Content
    while [[ $line_num -le $LOG_HEIGHT ]]; do
        echo -ne "\033[${line_num};1H"
        
        local log_line=""
        if [[ -p "$COMBINED_LOG_FIFO" ]]; then
            log_line=$(timeout 0.1 head -n 1 "$COMBINED_LOG_FIFO" 2>/dev/null || echo "")
        fi
        
        if [[ -z "$log_line" ]]; then
            log_line="${DIM}Waiting for log data...${NC}"
        fi
        
        # Truncate line to fit screen width
        printf "%-${TERM_WIDTH}s" "${log_line:0:$TERM_WIDTH}"
        ((line_num++))
    done
}

# Get server processes
get_server_processes() {
    ps aux | grep -E "(swr|startup\.sh)" | grep -v grep | grep -v "$0" | grep -v "mudctl" || true
}

# Get fallback processes
get_fallback_processes() {
    ps aux | grep -E "fallback_server\.py" | grep -v grep || true
}

# Get port usage
get_port_usage() {
    local port="$1"
    if command -v ss >/dev/null 2>&1; then
        ss -tlnp | grep ":$port " || true
    elif command -v netstat >/dev/null 2>&1; then
        netstat -tlnp | grep ":$port " || true
    fi
}

# Display compact status bar
display_status_bar() {
    local status_line=$((LOG_HEIGHT + 2))
    echo -ne "\033[${status_line};1H"
    
    local server_procs=$(get_server_processes)
    local fallback_procs=$(get_fallback_processes)
    local port_usage=$(get_port_usage "$DEFAULT_PORT")
    local current_time=$(date '+%H:%M:%S')
    
    # Compact status display
    local server_status="${RED}STOPPED${NC}"
    local fallback_status="${DIM}OFF${NC}"
    local port_status="${DIM}FREE${NC}"
    
    if [[ -n "$server_procs" ]]; then
        local main_pid=$(echo "$server_procs" | grep "swr" | head -1 | awk '{print $2}' || echo "?")
        server_status="${GREEN}RUNNING${NC}${DIM}($main_pid)${NC}"
    fi
    
    if [[ -n "$fallback_procs" ]]; then
        fallback_status="${YELLOW}ACTIVE${NC}"
    fi
    
    if [[ -n "$port_usage" ]]; then
        port_status="${GREEN}:$DEFAULT_PORT${NC}"
    fi
    
    local monitor_indicator=""
    if [[ "$MONITOR_MODE" == "true" ]]; then
        monitor_indicator="${GREEN}●${NC}"
    else
        monitor_indicator="${DIM}○${NC}"
    fi
    
    local split_indicator=""
    if [[ "$SPLIT_MODE" == "true" ]]; then
        split_indicator="${CYAN}SPLIT${NC}"
    else
        split_indicator="${DIM}SINGLE${NC}"
    fi
    
    printf " ${BOLD}${BLUE}SWR${NC} ${server_status} | ${CYAN}FB${NC} ${fallback_status} | ${MAGENTA}PORT${NC} ${port_status} | ${monitor_indicator} ${split_indicator} | ${DIM}%s${NC}" "$current_time"
    
    # Clear rest of line
    echo -ne "\033[K"
}

# Display menu area (bottom 60% of screen)
display_menu_area() {
    local menu_start=$((LOG_HEIGHT + 3))
    local current_line=$menu_start
    
    echo -ne "\033[${current_line};1H"
    echo -e "${BOLD}${WHITE}Commands:${NC}"
    ((current_line++))
    
    echo -ne "\033[${current_line};1H"
    echo -e "  ${GREEN}1)${NC} start [port]   ${GREEN}2)${NC} stop         ${GREEN}3)${NC} restart [port]   ${GREEN}4)${NC} status"
    ((current_line++))
    
    echo -ne "\033[${current_line};1H"
    echo -e "  ${GREEN}5)${NC} logs [lines]   ${GREEN}6)${NC} tail         ${GREEN}7)${NC} fallback [port]  ${GREEN}8)${NC} cleanup"
    ((current_line++))
    
    echo -ne "\033[${current_line};1H"
    echo -e "  ${GREEN}9)${NC} kill-all       ${YELLOW}c)${NC} check        ${CYAN}s)${NC} split-mode       ${CYAN}m)${NC} monitor"
    ((current_line++))
    
    echo -ne "\033[${current_line};1H"
    echo -e "  ${CYAN}r)${NC} refresh        ${CYAN}l)${NC} log-lines    ${MAGENTA}h)${NC} help             ${RED}q)${NC} quit"
    ((current_line++))
    
    echo -ne "\033[${current_line};1H"
    echo ""
    ((current_line++))
    
    if [[ "$MONITOR_MODE" == "true" ]]; then
        echo -ne "\033[${current_line};1H"
        echo -e "${DIM}Monitor: ${GREEN}ON${NC} ${DIM}(auto-refresh every ${REFRESH_INTERVAL}s) | Split: $([[ "$SPLIT_MODE" == "true" ]] && echo "${CYAN}ON${NC}" || echo "${DIM}OFF${NC}") | Lines: ${WHITE}$LOG_LINES${NC}${NC}"
    else
        echo -ne "\033[${current_line};1H"
        echo -e "${DIM}Monitor: ${RED}OFF${NC} ${DIM}(manual refresh) | Split: $([[ "$SPLIT_MODE" == "true" ]] && echo "${CYAN}ON${NC}" || echo "${DIM}OFF${NC}") | Lines: ${WHITE}$LOG_LINES${NC}${NC}"
    fi
    ((current_line++))
    
    echo -ne "\033[${current_line};1H"
    echo ""
}

# Main display function
update_display() {
    # Update terminal dimensions
    TERM_HEIGHT=$(tput lines 2>/dev/null || echo 24)
    TERM_WIDTH=$(tput cols 2>/dev/null || echo 80)
    LOG_HEIGHT=$((TERM_HEIGHT * 40 / 100))
    MENU_HEIGHT=$((TERM_HEIGHT - LOG_HEIGHT - 2))
    
    echo -e "${CLEAR}${HOME}"
    display_log_area
    display_status_bar
    display_menu_area
}

# Execute command using the regular mudctl script
execute_command() {
    local cmd="$1"
    shift
    local args="$@"
    
    # Clear the command area
    local cmd_line=$((TERM_HEIGHT - 3))
    echo -ne "\033[${cmd_line};1H\033[K"
    echo -e "${BOLD}${BLUE}Executing: $cmd $args${NC}"
    
    # Save cursor and execute command
    echo -e "${SAVE_CURSOR}"
    
    case "$cmd" in
        "start"|"stop"|"restart"|"status"|"logs"|"fallback"|"cleanup"|"kill-all"|"check")
            "$MUDCTL_SCRIPT" "$cmd" $args
            ;;
        "tail")
            echo -e "${YELLOW}Log tail mode - press Ctrl+C to return${NC}"
            "$MUDCTL_SCRIPT" "tail"
            ;;
        *)
            echo -e "${RED}Unknown command: $cmd${NC}"
            return 1
            ;;
    esac
    
    local exit_code=$?
    
    # Restore cursor and show result
    echo -e "${RESTORE_CURSOR}"
    echo -ne "\033[${cmd_line};1H\033[K"
    
    if [[ $exit_code -eq 0 ]]; then
        echo -e "${GREEN}Command completed successfully.${NC} Press any key to continue..."
    else
        echo -e "${RED}Command failed.${NC} Press any key to continue..."
    fi
    
    read -n 1 -s
    
    # Restart log processors if needed
    if [[ "$cmd" == "start" || "$cmd" == "restart" ]]; then
        sleep 2  # Give server time to start
        setup_fifos
    fi
}

# Process user input
process_input() {
    local input="$1"
    
    case "$input" in
        "1")
            echo -n "Enter port (default $DEFAULT_PORT): "
            read port
            execute_command "start" "${port:-$DEFAULT_PORT}"
            ;;
        "2")
            execute_command "stop"
            ;;
        "3")
            echo -n "Enter port (default $DEFAULT_PORT): "
            read port
            execute_command "restart" "${port:-$DEFAULT_PORT}"
            ;;
        "4")
            execute_command "status"
            ;;
        "5")
            echo -n "Enter number of lines (default $LOG_LINES): "
            read lines
            if [[ -n "$lines" && "$lines" =~ ^[0-9]+$ ]]; then
                LOG_LINES="$lines"
                echo "Log lines updated to $LOG_LINES"
                sleep 1
            else
                execute_command "logs" "${lines:-$LOG_LINES}"
            fi
            ;;
        "6")
            execute_command "tail"
            ;;
        "7")
            echo -n "Enter port (default $DEFAULT_PORT): "
            read port
            execute_command "fallback" "${port:-$DEFAULT_PORT}"
            ;;
        "8")
            execute_command "cleanup"
            ;;
        "9")
            execute_command "kill-all"
            ;;
        "c"|"C")
            execute_command "check"
            ;;
        "s"|"S")
            if [[ "$SPLIT_MODE" == "true" ]]; then
                SPLIT_MODE=false
                echo -e "${YELLOW}Split mode disabled${NC}"
            else
                SPLIT_MODE=true
                echo -e "${GREEN}Split mode enabled${NC}"
            fi
            # Restart log processing for new mode
            cleanup_processors
            setup_fifos
            sleep 1
            ;;
        "m"|"M")
            if [[ "$MONITOR_MODE" == "true" ]]; then
                MONITOR_MODE=false
                echo -e "${YELLOW}Monitor mode disabled${NC}"
            else
                MONITOR_MODE=true
                echo -e "${GREEN}Monitor mode enabled${NC}"
            fi
            sleep 1
            ;;
        "l"|"L")
            echo -n "Enter log lines to display (current: $LOG_LINES): "
            read new_lines
            if [[ -n "$new_lines" && "$new_lines" =~ ^[0-9]+$ ]]; then
                LOG_LINES="$new_lines"
                echo "Log lines updated to $LOG_LINES"
                sleep 1
            fi
            ;;
        "r"|"R")
            echo -e "${CYAN}Refreshing...${NC}"
            sleep 0.5
            ;;
        "h"|"H")
            display_help
            ;;
        "q"|"Q")
            echo -e "${YELLOW}Exiting...${NC}"
            cleanup
            ;;
        "")
            # Just refresh on empty input
            ;;
        *)
            echo -e "${RED}Invalid option: $input${NC}"
            sleep 1
            ;;
    esac
}

# Cleanup processors
cleanup_processors() {
    for pid in "${LOG_TAIL_PIDS[@]}" "${FIFO_PROCESSOR_PIDS[@]}"; do
        if [[ -n "$pid" ]]; then
            kill "$pid" 2>/dev/null || true
        fi
    done
    LOG_TAIL_PIDS=()
    FIFO_PROCESSOR_PIDS=()
}

# Display help
display_help() {
    clear
    echo -e "${BOLD}${BLUE}SWR MUD Server Advanced Interactive Controller - Help${NC}"
    echo ""
    echo -e "${BOLD}Live Log Monitoring:${NC}"
    echo "  • Top 40% of screen shows live server logs with color-coded events"
    echo "  • Errors/crashes highlighted in red, warnings in yellow"
    echo "  • Player activity in green, commands in cyan, system events in blue"
    echo "  • Press 's' to toggle split-screen mode (main + fallback logs)"
    echo ""
    echo -e "${BOLD}Monitor Modes:${NC}"
    echo "  • Single mode: Combined log stream from all sources"
    echo "  • Split mode: Main server logs | Fallback logs side-by-side"
    echo "  • Auto-refresh: Toggle with 'm' for continuous updates"
    echo "  • Log lines: Use 'l' to adjust number of lines displayed"
    echo ""
    echo -e "${BOLD}Status Bar:${NC}"
    echo "  • Shows server status, fallback status, port usage, and current time"
    echo "  • Green indicators = active, Red = stopped, Yellow = warning"
    echo ""
    echo -e "${BOLD}Commands (bottom 60%):${NC}"
    echo "  • All standard server management commands"
    echo "  • Enhanced with live log integration"
    echo "  • Split-screen and monitor mode controls"
    echo ""
    echo -e "${BOLD}Advanced Features:${NC}"
    echo "  • FIFO-based log streaming for real-time updates"
    echo "  • Error pattern matching with grep --color highlighting"
    echo "  • Resize-aware interface (40%/60% split)"
    echo "  • Background log processing with minimal CPU usage"
    echo ""
    echo -e "Press any key to return to main interface..."
    read -n 1 -s
}

# Monitor mode loop
monitor_loop() {
    while [[ "$MONITOR_MODE" == "true" ]]; do
        update_display
        
        local input=""
        # Non-blocking read with timeout
        if read -t $REFRESH_INTERVAL -n 1 -s input 2>/dev/null; then
            # User pressed a key, process input
            process_input "$input"
            
            # If user didn't quit, continue monitoring
            if [[ "$input" != "q" && "$input" != "Q" ]]; then
                continue
            else
                break
            fi
        fi
    done
}

# Check environment
check_environment() {
    local missing_files=()
    
    if [[ ! -f "$SWR_EXECUTABLE" ]]; then
        missing_files+=("Server executable: $SWR_EXECUTABLE")
    fi
    
    if [[ ! -f "$MUDCTL_SCRIPT" ]]; then
        missing_files+=("Management script: $MUDCTL_SCRIPT")
    fi
    
    if [[ ! -d "$AREA_DIR" ]]; then
        missing_files+=("Area directory: $AREA_DIR")
    fi
    
    if [[ ${#missing_files[@]} -gt 0 ]]; then
        echo -e "${RED}Missing required files/directories:${NC}"
        for file in "${missing_files[@]}"; do
            echo "  - $file"
        done
        echo ""
        echo "Please ensure you're running this script from the correct location"
        exit 1
    fi
}

# Initialize terminal
init_terminal() {
    stty -echo
    echo -e "${HIDE_CURSOR}${CLEAR}${HOME}"
    
    # Check terminal size
    if [[ $TERM_HEIGHT -lt 20 || $TERM_WIDTH -lt 80 ]]; then
        echo -e "${YELLOW}Warning: Terminal too small. Recommended: 80x20 or larger${NC}"
        echo "Current size: ${TERM_WIDTH}x${TERM_HEIGHT}"
        sleep 2
    fi
}

# Main program
main() {
    # Check environment
    check_environment
    
    # Initialize terminal and FIFOs
    init_terminal
    setup_fifos
    
    # Show initial welcome
    echo -e "${BOLD}${BLUE}Initializing SWR MUD Server Advanced Controller...${NC}"
    echo -e "${DIM}Setting up live log monitoring with FIFO pipes...${NC}"
    sleep 2
    
    # Main loop
    while true; do
        if [[ "$MONITOR_MODE" == "true" ]]; then
            monitor_loop
        else
            update_display
            
            local input=""
            echo -ne "\033[$((TERM_HEIGHT-1));1H"
            echo -n "Enter command: "
            stty echo
            read input
            stty -echo
            
            process_input "$input"
        fi
    done
}

# Show usage if called with arguments
if [[ $# -gt 0 ]]; then
    echo "SWR MUD Server Advanced Interactive Controller"
    echo ""
    echo "Enhanced version with live log streaming and split-screen monitoring"
    echo ""
    echo "Usage: $0"
    echo ""
    echo "Features:"
    echo "  • Live log streaming with FIFO pipes"
    echo "  • Error highlighting with grep --color patterns"
    echo "  • Split-screen mode: main logs | fallback logs"
    echo "  • Configurable screen layout (40% logs / 60% menu)"
    echo "  • Auto-refresh monitor mode"
    echo "  • Real-time status indicators"
    echo ""
    exit 0
fi

# Start the interface
main
