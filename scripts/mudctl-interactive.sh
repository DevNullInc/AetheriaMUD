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
# *                                         AetheriaMud Server Interactive Control Script                                         *
# *                                       Menu-driven interface with live server monitoring                                       *
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

# Default port
DEFAULT_PORT=4848

# Global state
MONITOR_MODE=false
REFRESH_INTERVAL=2
LAST_UPDATE=""

# Cleanup on exit
cleanup() {
    echo -e "${SHOW_CURSOR}"
    stty echo
    clear
    exit 0
}

trap cleanup SIGINT SIGTERM

# Initialize terminal
init_terminal() {
    stty -echo
    echo -e "${HIDE_CURSOR}${CLEAR}${HOME}"
}

# Restore terminal
restore_terminal() {
    echo -e "${SHOW_CURSOR}"
    stty echo
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

# Get latest log info
get_latest_log_info() {
    if [[ -d "$LOG_DIR" ]]; then
        local latest_log
        latest_log=$(ls -t "$LOG_DIR"/*.log 2>/dev/null | head -1 || true)
        
        if [[ -n "$latest_log" ]]; then
            local log_name=$(basename "$latest_log")
            local log_size=$(stat -c%s "$latest_log" 2>/dev/null || echo "0")
            local log_modified=$(stat -c %y "$latest_log" 2>/dev/null | cut -d. -f1 || echo "unknown")
            local log_lines=$(wc -l < "$latest_log" 2>/dev/null || echo "0")
            
            echo "$log_name|$log_size|$log_modified|$log_lines"
        else
            echo "none|0|never|0"
        fi
    else
        echo "no_dir|0|never|0"
    fi
}

# Get core dump info
get_core_info() {
    if [[ -d "$CORE_DIR" ]]; then
        local core_count=$(ls -1 "$CORE_DIR"/core.* 2>/dev/null | wc -l || echo "0")
        local latest_core=""
        
        if [[ $core_count -gt 0 ]]; then
            latest_core=$(ls -t "$CORE_DIR"/core.* 2>/dev/null | head -1 | xargs basename 2>/dev/null || echo "none")
        else
            latest_core="none"
        fi
        
        echo "$core_count|$latest_core"
    else
        echo "0|no_dir"
    fi
}

# Get system load
get_system_load() {
    if [[ -f /proc/loadavg ]]; then
        local load=$(cat /proc/loadavg | cut -d' ' -f1-3)
        echo "$load"
    else
        echo "unknown"
    fi
}

# Get memory usage
get_memory_usage() {
    if command -v free >/dev/null 2>&1; then
        local mem_info=$(free -h 2>/dev/null | grep "^Mem:" | awk '{print $3"/"$2" ("$7" free)"}' || echo "unknown")
        echo "$mem_info"
    else
        echo "unknown"
    fi
}

# Get disk usage for relevant directories
get_disk_usage() {
    if command -v df >/dev/null 2>&1; then
        local base_usage=$(df -h "$BASE_DIR" 2>/dev/null | tail -1 | awk '{print $5}' || echo "??%")
        echo "$base_usage"
    else
        echo "unknown"
    fi
}

# Format status line with proper alignment
format_status_line() {
    local content="$1"
    local box_width=78  # Total width minus border characters (2)
    
    # Strip ANSI codes to get actual content length
    local clean_content=$(echo -e "$content" | sed 's/\x1b\[[0-9;]*m//g')
    local content_length=${#clean_content}
    
    # Calculate padding needed
    local padding=$((box_width - content_length))
    
    # Create padding string
    local pad_string=""
    for ((i=0; i<padding; i++)); do
        pad_string+=" "
    done
    
    echo -e "${BOLD}${BLUE}║${NC} $content$pad_string ${BLUE}║${NC}"
}

# Display header with live server status
display_header() {
    local current_time=$(date '+%Y-%m-%d %H:%M:%S')
    
    echo -e "${CLEAR}${HOME}"
    echo -e "${BOLD}${BLUE}╔════════════════════════════════════════════════════════════════════════════════╗${NC}"
    echo -e "${BOLD}${BLUE}║${WHITE}                        SWR SEC Server Interactive Controller                   ${BLUE}║${NC}"
    echo -e "${BOLD}${BLUE}║${WHITE}                                                                                ${BLUE}║${NC}"
    format_status_line "${DIM}Updated: $current_time${NC}"
    echo -e "${BOLD}${BLUE}╠════════════════════════════════════════════════════════════════════════════════╣${NC}"
    
    # Server Status Section
    local server_procs=$(get_server_processes)
    local fallback_procs=$(get_fallback_processes)
    local port_usage=$(get_port_usage "$DEFAULT_PORT")
    
    if [[ -n "$server_procs" ]]; then
        local server_count=$(echo "$server_procs" | wc -l)
        local main_pid=$(echo "$server_procs" | grep "swr" | head -1 | awk '{print $2}' || echo "unknown")
        format_status_line "${GREEN}●${NC} ${BOLD}SERVER STATUS: ${GREEN}RUNNING${NC} ${DIM}(PID: $main_pid, Processes: $server_count)${NC}"
    else
        format_status_line "${RED}●${NC} ${BOLD}SERVER STATUS: ${RED}STOPPED${NC}"
    fi
    
    if [[ -n "$fallback_procs" ]]; then
        local fallback_pid=$(echo "$fallback_procs" | head -1 | awk '{print $2}')
        format_status_line "${YELLOW}●${NC} ${BOLD}FALLBACK STATUS: ${YELLOW}ACTIVE${NC} ${DIM}(PID: $fallback_pid)${NC}"
    else
        format_status_line "${DIM}○${NC} ${BOLD}FALLBACK STATUS: ${DIM}INACTIVE${NC}"
    fi
    
    # Port Status
    if [[ -n "$port_usage" ]]; then
        local port_pid=$(echo "$port_usage" | grep -o 'pid=[0-9]*' | cut -d'=' -f2 | head -1 || echo "unknown")
        format_status_line "${GREEN}●${NC} ${BOLD}PORT $DEFAULT_PORT: ${GREEN}IN USE${NC} ${DIM}(PID: $port_pid)${NC}"
    else
        format_status_line "${DIM}○${NC} ${BOLD}PORT $DEFAULT_PORT: ${DIM}AVAILABLE${NC}"
    fi
    
    echo -e "${BOLD}${BLUE}╠════════════════════════════════════════════════════════════════════════════════╣${NC}"
    
    # System Information
    local log_info=$(get_latest_log_info)
    IFS='|' read -r log_name log_size log_modified log_lines <<< "$log_info"
    
    local core_info=$(get_core_info)
    IFS='|' read -r core_count latest_core <<< "$core_info"
    
    local system_load=$(get_system_load)
    local memory_usage=$(get_memory_usage)
    local disk_usage=$(get_disk_usage)
    
    format_status_line "${CYAN}Latest Log:${NC} ${WHITE}$log_name${NC} ${DIM}($log_lines lines, $(numfmt --to=iec $log_size 2>/dev/null || echo ${log_size}b))${NC}"
    format_status_line "${CYAN}Core Dumps:${NC} ${WHITE}$core_count total${NC} ${DIM}(latest: $latest_core)${NC}"
    format_status_line "${CYAN}System Load:${NC} ${WHITE}$system_load${NC} ${DIM}| Memory: $memory_usage | Disk: $disk_usage${NC}"
    echo -e "${BOLD}${BLUE}╚════════════════════════════════════════════════════════════════════════════════╝${NC}"
    echo ""
}

# Display main menu
display_menu() {
    echo -e "${BOLD}${WHITE}Available Commands:${NC}"
    echo ""
    echo -e "  ${GREEN}1)${NC} ${BOLD}start${NC} [port]     - Start the server (default: $DEFAULT_PORT)"
    echo -e "  ${GREEN}2)${NC} ${BOLD}stop${NC}             - Stop the server gracefully"
    echo -e "  ${GREEN}3)${NC} ${BOLD}restart${NC} [port]   - Restart the server"
    echo -e "  ${GREEN}4)${NC} ${BOLD}status${NC}           - Show detailed server status"
    echo -e "  ${GREEN}5)${NC} ${BOLD}logs${NC} [count]     - Show recent log entries (default: 20)"
    echo -e "  ${GREEN}6)${NC} ${BOLD}tail${NC}             - Follow live logs (Press 'q' to return)"
    echo -e "  ${GREEN}7)${NC} ${BOLD}fallback${NC} [port]  - Start fallback server"
    echo -e "  ${GREEN}8)${NC} ${BOLD}cleanup${NC}          - Clean up old files"
    echo -e "  ${GREEN}9)${NC} ${BOLD}kill-all${NC}         - Force kill all processes"
    echo -e "  ${YELLOW}c)${NC} ${BOLD}check${NC}            - Run system dependency check"
    echo -e "  ${CYAN}m)${NC} ${BOLD}monitor${NC}           - Toggle auto-refresh monitor mode"
    echo -e "  ${CYAN}r)${NC} ${BOLD}refresh${NC}           - Refresh display manually"
    echo -e "  ${MAGENTA}h)${NC} ${BOLD}help${NC}             - Show detailed help"
    echo -e "  ${RED}q)${NC} ${BOLD}quit${NC}             - Exit this interface"
    echo ""
    
    if [[ "$MONITOR_MODE" == "true" ]]; then
        echo -e "${DIM}Monitor mode: ${GREEN}ON${NC} ${DIM}(auto-refresh every ${REFRESH_INTERVAL}s)${NC}"
    else
        echo -e "${DIM}Monitor mode: ${RED}OFF${NC} ${DIM}(manual refresh only)${NC}"
    fi
    echo ""
}

# Display help
display_help() {
    clear
    echo -e "${BOLD}${BLUE}SWR MUD Server Interactive Controller - Help${NC}"
    echo ""
    echo -e "${BOLD}Navigation:${NC}"
    echo "  • Type a command number or letter and press Enter"
    echo "  • Commands can include optional parameters (e.g., 'start 4949')"
    echo "  • Use 'q' or Ctrl+C to exit"
    echo ""
    echo -e "${BOLD}Monitor Mode:${NC}"
    echo "  • Toggle with 'm' - automatically refreshes server status"
    echo "  • Useful for monitoring server health in real-time"
    echo "  • Can still execute commands while monitoring"
    echo ""
    echo -e "${BOLD}Server Commands:${NC}"
    echo "  start [port]  - Starts the main server (automatically handles port conflicts)"
    echo "  stop          - Gracefully stops the server with SIGTERM"
    echo "  restart       - Stops and starts the server"
    echo "  kill-all      - Emergency force-kill all related processes"
    echo ""
    echo -e "${BOLD}Monitoring Commands:${NC}"
    echo "  status        - Detailed process and port information"
    echo "  logs [count]  - Shows recent log entries (default 20 lines)"
    echo "  tail          - Follows live log output (Press 'q' + Enter to return to menu)"
    echo ""
    echo -e "${BOLD}Maintenance Commands:${NC}"
    echo "  fallback      - Starts the maintenance/fallback server"
    echo "  cleanup       - Removes old log files and core dumps"
    echo "  check         - Runs system compatibility check"
    echo ""
    echo -e "${BOLD}Status Indicators:${NC}"
    echo -e "  ${GREEN}●${NC} Green - Service running/available"
    echo -e "  ${RED}●${NC} Red - Service stopped/unavailable"
    echo -e "  ${YELLOW}●${NC} Yellow - Warning/fallback active"
    echo -e "  ${DIM}○${NC} Gray - Service inactive"
    echo ""
    echo -e "Press any key to return to main menu..."
    read -n 1 -s
}

# Execute command using the regular mudctl script
execute_command() {
    local cmd="$1"
    shift
    local args="$@"
    
    echo -e "${BOLD}${BLUE}Executing: $cmd $args${NC}"
    echo ""
    
    case "$cmd" in
        "start"|"stop"|"restart"|"status"|"logs"|"tail"|"fallback"|"cleanup"|"kill-all"|"check")
            "$MUDCTL_SCRIPT" "$cmd" $args
            ;;
        *)
            echo -e "${RED}Unknown command: $cmd${NC}"
            return 1
            ;;
    esac
    
    local exit_code=$?
    echo ""
    if [[ $exit_code -eq 0 ]]; then
        echo -e "${GREEN}Command completed successfully.${NC}"
    else
        echo -e "${RED}Command failed with exit code $exit_code.${NC}"
    fi
    
    echo ""
    echo -e "Press any key to continue..."
    read -n 1 -s
}

# Monitor mode loop
monitor_loop() {
    local counter=0
    
    while [[ "$MONITOR_MODE" == "true" ]]; do
        display_header
        display_menu
        
        echo -e "${DIM}Auto-refresh in progress... Press any key for menu${NC}"
        
        # Non-blocking read with timeout
        if read -t $REFRESH_INTERVAL -n 1 -s input; then
            # User pressed a key, exit monitor mode and process input
            MONITOR_MODE=false
            process_input "$input"
            return
        fi
        
        counter=$((counter + 1))
    done
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
            echo -n "Enter number of lines (default 20): "
            read lines
            execute_command "logs" "${lines:-20}"
            ;;
        "6")
            echo -e "${YELLOW}Starting log tail... Press 'q' + Enter to return to menu${NC}"
            sleep 2
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
        "m"|"M")
            if [[ "$MONITOR_MODE" == "true" ]]; then
                MONITOR_MODE=false
                echo -e "${YELLOW}Monitor mode disabled${NC}"
            else
                MONITOR_MODE=true
                echo -e "${GREEN}Monitor mode enabled - auto-refresh every ${REFRESH_INTERVAL}s${NC}"
                sleep 1
                return # Let main loop handle monitor mode
            fi
            sleep 1
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

# Check if required files exist
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
        echo "and that the SWR server is properly installed."
        exit 1
    fi
}

# Main program
main() {
    # Check environment
    check_environment
    
    # Initialize terminal
    init_terminal
    
    # Show initial welcome
    clear
    echo -e "${BOLD}${BLUE}Initializing SWR MUD Server Interactive Controller...${NC}"
    sleep 1
    
    # Main loop
    while true; do
        if [[ "$MONITOR_MODE" == "true" ]]; then
            monitor_loop
        else
            display_header
            display_menu
            
            echo -n "Enter command: "
            restore_terminal
            read input
            init_terminal
            
            process_input "$input"
        fi
    done
}

# Show usage if called with arguments
if [[ $# -gt 0 ]]; then
    echo "SWR MUD Server Interactive Controller"
    echo ""
    echo "This script provides a menu-driven interface for server management."
    echo ""
    echo "Usage: $0"
    echo ""
    echo "For command-line usage, use: $MUDCTL_SCRIPT [command] [options]"
    echo ""
    echo "Interactive features:"
    echo "  • Live server status monitoring"
    echo "  • Menu-driven command interface"
    echo "  • Auto-refresh monitor mode"
    echo "  • Real-time system information"
    echo ""
    exit 0
fi

# Start the interface
main
