#!/usr/bin/env bash

# Core Dump Analysis Script for SWR MUD
# THE FINAL EPISODE
#
# Usage: ./analyze_core.sh [corefile] [executable]
# If no arguments provided, analyzes the most recent core dump

set -euo pipefail

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Get script directory and project paths
SCRIPT_DIR="$(dirname "$0")"
CORE_DIR="$(cd "$SCRIPT_DIR" && pwd)"
BASE_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
SRC_DIR="$BASE_DIR/src"
DEFAULT_EXE="$SRC_DIR/swr"

print_usage() {
    echo -e "${CYAN}Core Dump Analysis Script${NC}"
    echo "Usage: $0 [corefile] [executable]"
    echo ""
    echo "Arguments:"
    echo "  corefile    - Path to core dump file (optional)"
    echo "  executable  - Path to executable (default: $DEFAULT_EXE)"
    echo ""
    echo "If no corefile is specified, analyzes the most recent core dump."
    echo ""
    echo "Examples:"
    echo "  $0                                    # Analyze latest core"
    echo "  $0 core.swr.12345                   # Analyze specific core"
    echo "  $0 core.swr.12345 /path/to/swr      # Specify both core and exe"
    exit 1
}

# Parse arguments
COREFILE=""
EXECUTABLE="$DEFAULT_EXE"

if [[ $# -eq 0 ]]; then
    # Find most recent core dump
    COREFILE=$(find "$CORE_DIR" -name "core.*" -type f -printf "%T@ %p\n" 2>/dev/null | sort -n | tail -1 | cut -d' ' -f2- || true)
    if [[ -z "$COREFILE" ]]; then
        echo -e "${RED}Error: No core dumps found in $CORE_DIR${NC}"
        exit 1
    fi
elif [[ $# -eq 1 ]]; then
    if [[ "$1" == "-h" || "$1" == "--help" ]]; then
        print_usage
    fi
    COREFILE="$1"
elif [[ $# -eq 2 ]]; then
    COREFILE="$1"
    EXECUTABLE="$2"
else
    print_usage
fi

# Validate inputs
if [[ ! -f "$COREFILE" ]]; then
    echo -e "${RED}Error: Core file '$COREFILE' not found${NC}"
    exit 1
fi

if [[ ! -f "$EXECUTABLE" ]]; then
    echo -e "${RED}Error: Executable '$EXECUTABLE' not found${NC}"
    exit 1
fi

if ! command -v gdb >/dev/null 2>&1; then
    echo -e "${RED}Error: gdb is not installed. Please install gdb to analyze core dumps.${NC}"
    echo "On Ubuntu/Debian: sudo apt install gdb"
    exit 1
fi

# Get core file info
COREFILE_ABS="$(realpath "$COREFILE")"
COREFILE_SIZE=$(stat -c%s "$COREFILE_ABS")
COREFILE_DATE=$(stat -c%y "$COREFILE_ABS")

echo -e "${PURPLE}═══════════════════════════════════════════════════════════════════════════════${NC}"
echo -e "${CYAN}                            CORE DUMP ANALYSIS REPORT${NC}"
echo -e "${PURPLE}═══════════════════════════════════════════════════════════════════════════════${NC}"
echo
echo -e "${YELLOW}Core File Information:${NC}"
echo -e "  File: ${BLUE}$COREFILE_ABS${NC}"
echo -e "  Size: ${GREEN}$(numfmt --to=iec --suffix=B $COREFILE_SIZE)${NC}"
echo -e "  Date: ${GREEN}$COREFILE_DATE${NC}"
echo
echo -e "${YELLOW}Executable:${NC} ${BLUE}$EXECUTABLE${NC}"
echo

# Create analysis output file
ANALYSIS_FILE="${COREFILE_ABS%.core}.analysis.txt"
echo -e "${YELLOW}Analysis will be saved to:${NC} ${BLUE}$ANALYSIS_FILE${NC}"
echo

# Start GDB analysis
echo -e "${PURPLE}═══════════════════════════════════════════════════════════════════════════════${NC}"
echo -e "${CYAN}                                 GDB ANALYSIS${NC}"
echo -e "${PURPLE}═══════════════════════════════════════════════════════════════════════════════${NC}"

# Create GDB command file for comprehensive analysis
GDB_COMMANDS=$(mktemp)
cat > "$GDB_COMMANDS" << 'EOF'
set pagination off
set print pretty on
set print array on
set print array-indexes on

echo \n=== CRASH SUMMARY ===\n
info program
echo \n=== SIGNAL INFORMATION ===\n
info signals
echo \n=== REGISTERS ===\n
info registers
echo \n=== CURRENT FRAME ===\n
frame
echo \n=== LOCAL VARIABLES ===\n
info locals
echo \n=== FUNCTION ARGUMENTS ===\n
info args
echo \n=== BACKTRACE (CURRENT THREAD) ===\n
bt full
echo \n=== ALL THREADS ===\n
info threads
echo \n=== BACKTRACE (ALL THREADS) ===\n
thread apply all bt
echo \n=== MEMORY MAP ===\n
info proc mappings
echo \n=== SHARED LIBRARIES ===\n
info sharedlibrary
echo \n=== DISASSEMBLY (CRASH LOCATION) ===\n
x/20i $pc-40
echo \n=== STACK DUMP ===\n
x/32xw $sp
quit
EOF

# Run GDB analysis and capture output
echo -e "${GREEN}Running comprehensive analysis...${NC}"
{
    echo "CORE DUMP ANALYSIS REPORT"
    echo "========================="
    echo "Generated: $(date)"
    echo "Core File: $COREFILE_ABS"
    echo "Executable: $EXECUTABLE"
    echo "Size: $(numfmt --to=iec --suffix=B $COREFILE_SIZE)"
    echo ""
    
    gdb -q -batch -x "$GDB_COMMANDS" "$EXECUTABLE" "$COREFILE_ABS" 2>&1
} | tee "$ANALYSIS_FILE"

# Clean up
rm -f "$GDB_COMMANDS"

echo
echo -e "${PURPLE}═══════════════════════════════════════════════════════════════════════════════${NC}"
echo -e "${GREEN}Analysis complete! Report saved to: ${BLUE}$ANALYSIS_FILE${NC}"
echo -e "${PURPLE}═══════════════════════════════════════════════════════════════════════════════${NC}"

# Offer to show key information
echo
echo -e "${YELLOW}Key Information Summary:${NC}"
echo

# Extract crash location
CRASH_FRAME=$(grep -A 1 "=== CURRENT FRAME ===" "$ANALYSIS_FILE" | tail -n 1 || echo "Unknown")
echo -e "${GREEN}Crash Location:${NC} $CRASH_FRAME"

# Extract signal info
SIGNAL_INFO=$(grep -A 5 "=== SIGNAL INFORMATION ===" "$ANALYSIS_FILE" | grep -E "(SIGSEGV|SIGABRT|SIGFPE|SIGILL)" | head -n 1 || echo "Unknown signal")
echo -e "${GREEN}Signal:${NC} $SIGNAL_INFO"

# Extract first few backtrace frames
echo -e "${GREEN}Top Backtrace Frames:${NC}"
grep -A 10 "=== BACKTRACE (CURRENT THREAD) ===" "$ANALYSIS_FILE" | grep -E "^#[0-9]" | head -n 5 | while read line; do
    echo -e "  ${BLUE}$line${NC}"
done

echo
echo -e "${CYAN}To view the full analysis: ${BLUE}less '$ANALYSIS_FILE'${NC}"
echo -e "${CYAN}To re-run interactively: ${BLUE}gdb '$EXECUTABLE' '$COREFILE_ABS'${NC}"
