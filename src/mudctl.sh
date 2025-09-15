#!/usr/bin/env bash

 #*********************************************************************************************************************************
 #*                                                                                                                   ;           *
 #*                                                                                                                  ED.          *
 #*                        ,;                             ,;                                                  :      E#Wi         *
 #*                      f#i          .    .            f#i j.         t                                      Ef     E###G.       *
 #*             ..     .E#t  GEEEEEEELDi   Dt         .E#t  EW,        Ej             ..           ..       : E#t    E#fD#W;      *
 #*            ;W,    i#W,   ,;;L#K;;.E#i  E#i       i#W,   E##j       E#,           ;W,          ,W,     .Et E#t    E#t t##L     *
 #*           j##,   L#D.       t#E   E#t  E#t      L#D.    E###D.     E#t          j##,         t##,    ,W#t E#t    E#t  .E#K,   *
 #*          G###, :K#Wfff;     t#E   E#t  E#t    :K#Wfff;  E#jG#W;    E#t         G###,        L###,   j###t E#t fi E#t    j##f  *
 #*        :E####, i##WLLLLt    t#E   E########f. i##WLLLLt E#t t##f   E#t       :E####,      .E#j##,  G#fE#t E#t L#jE#t    :E#K: *
 #*       ;W#DG##,  .E#L        t#E   E#j..K#j...  .E#L     E#t  :K#E: E#t      ;W#DG##,     ;WW; ##,:K#i E#t E#t L#LE#t   t##L   *
 #*      j###DW##,    f#E:      t#E   E#t  E#t       f#E:   E#KDDDD###iE#t     j###DW##,    j#E.  ##f#W,  E#t E#tf#E:E#t .D#W;    *
 #*     G##i,,G##,     ,WW;     t#E   E#t  E#t        ,WW;  E#f,t#Wi,,,E#t    G##i,,G##,  .D#L    ###K:   E#t E###f  E#tiW#G.     *
 #*   :K#K:   L##,      .D#;    t#E   f#t  f#t         .D#; E#t  ;#W:  E#t  :K#K:   L##, :K#t     ##D.    E#t E#K,   E#K##i       *
 #*  ;##D.    L##,        tt     fE    ii   ii           tt DWi   ,KK: E#t ;##D.    L##, ...      #G      ..  EL     E##D.        *
 #*  ,,,      .,,                 :                                    ,;. ,,,      .,,           j           :      E#t          *
 #*                                                                                                                  L:           *
 #*********************************************************************************************************************************
 #*                                                                                                                               *
 #*                                            AetheriaMUD Mud Control Panel additions                                            *
 #*                                     copyright (c) 2025 /dev/null Industries - StygianRenegade                                 *
 #*********************************************************************************************************************************
# AetheriaMUD Server Management Utility

set -euo pipefail

# Default port
DEFAULT_PORT=4848

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m'

# Get script directory and project paths
SCRIPT_DIR="$(dirname "$0")"
SRC_DIR="$(cd "$SCRIPT_DIR" && pwd)"
BASE_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

print_usage() {
    echo -e "${CYAN}SWR MUD Server Management Utility${NC}"
    echo "Usage: $0 <command> [options]"
    echo ""
    echo "Commands:"
    echo "  status [port]           Show server and port status"
    echo "  stop [port]             Stop all processes using the port"
    echo "  start [port]            Start the main server"
    echo "  restart [port]          Stop and start the server"
    echo "  fallback [port]         Start fallback server manually"
    echo "  cleanup [port]          Clean up port conflicts"
    echo "  kill-all                Kill all swr and fallback processes"
    echo ""
    echo "Options:"
    echo "  port                    Port number (default: $DEFAULT_PORT)"
    echo ""
    echo "Examples:"
    echo "  $0 status               # Check status on default port"
    echo "  $0 stop 4848            # Stop processes on port 4848"
    echo "  $0 restart              # Restart server on default port"
    echo "  $0 fallback 4849        # Start fallback on port 4849"
}

get_port_processes() {
    local port="$1"
    ss -tlnp | grep ":$port " | awk '{print $6}' | grep -o 'pid=[0-9]*' | cut -d'=' -f2 | sort -u
}

show_status() {
    local port="${1:-$DEFAULT_PORT}"
    
    echo -e "${CYAN}═══════════════════════════════════════════════════════════════════════════════${NC}"
    echo -e "${YELLOW}                            SWR MUD SERVER STATUS${NC}"
    echo -e "${CYAN}═══════════════════════════════════════════════════════════════════════════════${NC}"
    echo
    echo -e "${YELLOW}Port:${NC} ${GREEN}$port${NC}"
    echo -e "${YELLOW}Timestamp:${NC} ${GREEN}$(date)${NC}"
    echo
    
    # Check port usage
    local port_users=$(get_port_processes "$port")
    if [[ -n "$port_users" ]]; then
        echo -e "${YELLOW}Processes using port $port:${NC}"
        for pid in $port_users; do
            if [[ -n "$pid" ]]; then
                local process_info=$(ps -p "$pid" -o pid,ppid,user,cmd --no-headers 2>/dev/null || echo "$pid ? ? (process not found)")
                echo -e "  ${GREEN}$process_info${NC}"
            fi
        done
    else
        echo -e "${GREEN}Port $port is available${NC}"
    fi
    echo
    
    # Check for SWR processes
    echo -e "${YELLOW}SWR processes:${NC}"
    local swr_procs=$(pgrep -f "swr.*$port" 2>/dev/null || true)
    if [[ -n "$swr_procs" ]]; then
        for pid in $swr_procs; do
            local process_info=$(ps -p "$pid" -o pid,ppid,user,cmd --no-headers 2>/dev/null || true)
            if [[ -n "$process_info" ]]; then
                echo -e "  ${GREEN}$process_info${NC}"
            fi
        done
    else
        echo -e "  ${YELLOW}No SWR processes found${NC}"
    fi
    echo
    
    # Check for fallback processes
    echo -e "${YELLOW}Fallback server processes:${NC}"
    local fallback_procs=$(pgrep -f "fallback_server.*$port" 2>/dev/null || true)
    if [[ -n "$fallback_procs" ]]; then
        for pid in $fallback_procs; do
            local process_info=$(ps -p "$pid" -o pid,ppid,user,cmd --no-headers 2>/dev/null || true)
            if [[ -n "$process_info" ]]; then
                echo -e "  ${GREEN}$process_info${NC}"
            fi
        done
    else
        echo -e "  ${YELLOW}No fallback server processes found${NC}"
    fi
    echo
    
    # Check fallback status file
    if [[ -f "$BASE_DIR/fallback.status" ]]; then
        echo -e "${YELLOW}Fallback status:${NC}"
        while IFS= read -r line; do
            echo -e "  ${BLUE}$line${NC}"
        done < "$BASE_DIR/fallback.status"
        echo
    fi
    
    echo -e "${CYAN}═══════════════════════════════════════════════════════════════════════════════${NC}"
}

stop_port_processes() {
    local port="${1:-$DEFAULT_PORT}"
    
    echo -e "${YELLOW}Stopping all processes using port $port...${NC}"
    
    local port_users=$(get_port_processes "$port")
    if [[ -n "$port_users" ]]; then
        for pid in $port_users; do
            if [[ -n "$pid" ]]; then
                local process_name=$(ps -p "$pid" -o comm --no-headers 2>/dev/null || echo "unknown")
                echo -e "  Stopping PID $pid ($process_name)..."
                kill -TERM "$pid" 2>/dev/null || true
            fi
        done
        
        sleep 3
        
        # Force kill if still running
        local remaining=$(get_port_processes "$port")
        if [[ -n "$remaining" ]]; then
            echo -e "${YELLOW}Force killing remaining processes...${NC}"
            for pid in $remaining; do
                if [[ -n "$pid" ]]; then
                    local process_name=$(ps -p "$pid" -o comm --no-headers 2>/dev/null || echo "unknown")
                    echo -e "  Force killing PID $pid ($process_name)..."
                    kill -KILL "$pid" 2>/dev/null || true
                fi
            done
        fi
        
        echo -e "${GREEN}Port $port cleanup complete.${NC}"
    else
        echo -e "${GREEN}No processes found using port $port.${NC}"
    fi
}

start_server() {
    local port="${1:-$DEFAULT_PORT}"
    
    echo -e "${YELLOW}Starting SWR MUD server on port $port...${NC}"
    
    # Change to src directory and start
    cd "$SRC_DIR"
    if [[ -x "./startup.sh" ]]; then
        exec "./startup.sh" "$port"
    else
        echo -e "${RED}Error: startup.sh not found or not executable${NC}"
        return 1
    fi
}

start_fallback() {
    local port="${1:-$DEFAULT_PORT}"
    
    echo -e "${YELLOW}Starting fallback server on port $port...${NC}"
    
    if [[ -x "$SRC_DIR/fallback_server.py" ]]; then
        exec "$SRC_DIR/fallback_server.py" "$port"
    else
        echo -e "${RED}Error: fallback_server.py not found or not executable${NC}"
        return 1
    fi
}

kill_all_processes() {
    echo -e "${YELLOW}Killing all SWR and fallback processes...${NC}"
    
    # Kill all SWR processes
    local swr_procs=$(pgrep -f "swr" 2>/dev/null || true)
    if [[ -n "$swr_procs" ]]; then
        echo -e "  Killing SWR processes..."
        for pid in $swr_procs; do
            kill -TERM "$pid" 2>/dev/null || true
        done
    fi
    
    # Kill all fallback processes
    local fallback_procs=$(pgrep -f "fallback_server" 2>/dev/null || true)
    if [[ -n "$fallback_procs" ]]; then
        echo -e "  Killing fallback processes..."
        for pid in $fallback_procs; do
            kill -TERM "$pid" 2>/dev/null || true
        done
    fi
    
    sleep 2
    
    # Force kill if needed
    swr_procs=$(pgrep -f "swr" 2>/dev/null || true)
    fallback_procs=$(pgrep -f "fallback_server" 2>/dev/null || true)
    
    if [[ -n "$swr_procs" || -n "$fallback_procs" ]]; then
        echo -e "  Force killing remaining processes..."
        for pid in $swr_procs $fallback_procs; do
            if [[ -n "$pid" ]]; then
                kill -KILL "$pid" 2>/dev/null || true
            fi
        done
    fi
    
    # Clean up status files
    rm -f "$BASE_DIR/fallback.status"
    
    echo -e "${GREEN}All processes stopped.${NC}"
}

# Parse command line
if [[ $# -eq 0 ]]; then
    print_usage
    exit 1
fi

COMMAND="$1"
shift

case "$COMMAND" in
    status)
        show_status "$@"
        ;;
    stop)
        stop_port_processes "$@"
        ;;
    start)
        start_server "$@"
        ;;
    restart)
        PORT="${1:-$DEFAULT_PORT}"
        stop_port_processes "$PORT"
        sleep 2
        start_server "$PORT"
        ;;
    fallback)
        start_fallback "$@"
        ;;
    cleanup)
        stop_port_processes "$@"
        ;;
    kill-all)
        kill_all_processes
        ;;
    help|--help|-h)
        print_usage
        ;;
    *)
        echo -e "${RED}Error: Unknown command '$COMMAND'${NC}"
        print_usage
        exit 1
        ;;
esac
