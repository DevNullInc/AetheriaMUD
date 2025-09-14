#!/usr/bin/env bash

# Core Dump Status Script for SWR MUD
# THE FINAL EPISODE
#
# Shows current status of core dumps and analysis files

set -euo pipefail

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Get script directory
SCRIPT_DIR="$(dirname "$0")"
CORE_DIR="$(cd "$SCRIPT_DIR" && pwd)"

echo -e "${PURPLE}═══════════════════════════════════════════════════════════════════════════════${NC}"
echo -e "${CYAN}                            CORE DUMP STATUS${NC}"
echo -e "${PURPLE}═══════════════════════════════════════════════════════════════════════════════${NC}"
echo
echo -e "${YELLOW}Core Directory:${NC} ${BLUE}$CORE_DIR${NC}"
echo

# Find all core dumps and analysis files
CORE_FILES=$(find "$CORE_DIR" -name "core.swr.*" -not -name "*.analysis.txt" -type f 2>/dev/null | sort -r || true)
ANALYSIS_FILES=$(find "$CORE_DIR" -name "*.analysis.txt" -type f 2>/dev/null | sort -r || true)

# Count files
CORE_COUNT=0
ANALYSIS_COUNT=0
TOTAL_SIZE=0

if [[ -n "$CORE_FILES" ]]; then
    CORE_COUNT=$(echo "$CORE_FILES" | wc -l)
    
    # Calculate total size
    while IFS= read -r file; do
        if [[ -n "$file" && -f "$file" ]]; then
            SIZE=$(stat -c%s "$file" 2>/dev/null || echo "0")
            TOTAL_SIZE=$((TOTAL_SIZE + SIZE))
        fi
    done <<< "$CORE_FILES"
fi

if [[ -n "$ANALYSIS_FILES" ]]; then
    ANALYSIS_COUNT=$(echo "$ANALYSIS_FILES" | wc -l)
fi

echo -e "${YELLOW}Summary:${NC}"
echo -e "  Core dumps: ${GREEN}$CORE_COUNT files${NC}"
echo -e "  Analysis files: ${GREEN}$ANALYSIS_COUNT files${NC}"
echo -e "  Total size: ${GREEN}$(numfmt --to=iec --suffix=B $TOTAL_SIZE)${NC}"
echo

if [[ "$CORE_COUNT" -gt 0 ]]; then
    echo -e "${YELLOW}Recent Core Dumps:${NC}"
    echo
    
    COUNT=0
    while IFS= read -r file; do
        if [[ -n "$file" && -f "$file" ]]; then
            COUNT=$((COUNT + 1))
            if [[ $COUNT -gt 10 ]]; then
                REMAINING=$((CORE_COUNT - 10))
                echo -e "  ${BLUE}... and $REMAINING more files${NC}"
                break
            fi
            
            FILENAME=$(basename "$file")
            SIZE=$(stat -c%s "$file" 2>/dev/null || echo "0")
            DATE=$(stat -c%y "$file" 2>/dev/null | cut -d' ' -f1,2 | cut -d'.' -f1)
            
            # Extract timestamp and PID from filename
            if [[ "$FILENAME" =~ core\.swr\.([0-9]{8}_[0-9]{6})\.([0-9]+) ]]; then
                TIMESTAMP="${BASH_REMATCH[1]}"
                PID="${BASH_REMATCH[2]}"
                # Format timestamp for display
                FORMATTED_TIME="${TIMESTAMP:0:4}-${TIMESTAMP:4:2}-${TIMESTAMP:6:2} ${TIMESTAMP:9:2}:${TIMESTAMP:11:2}:${TIMESTAMP:13:2}"
                
                # Check if analysis exists
                ANALYSIS_FILE="${file}.analysis.txt"
                if [[ -f "$ANALYSIS_FILE" ]]; then
                    ANALYSIS_STATUS="${GREEN}✓ analyzed${NC}"
                else
                    ANALYSIS_STATUS="${RED}✗ not analyzed${NC}"
                fi
                
                echo -e "  ${BLUE}$FILENAME${NC}"
                echo -e "    Crash Time: ${YELLOW}$FORMATTED_TIME${NC}  PID: ${YELLOW}$PID${NC}  Size: ${YELLOW}$(numfmt --to=iec --suffix=B $SIZE)${NC}  $ANALYSIS_STATUS"
            else
                echo -e "  ${BLUE}$FILENAME${NC} (${DATE}, $(numfmt --to=iec --suffix=B $SIZE))"
            fi
        fi
    done <<< "$CORE_FILES"
    
    echo
    echo -e "${CYAN}Available Commands:${NC}"
    echo -e "  Analyze latest: ${BLUE}./analyze_core.sh${NC}"
    echo -e "  Analyze specific: ${BLUE}./analyze_core.sh $CORE_DIR/filename${NC}"
    echo -e "  Clean old files: ${BLUE}./cleanup_cores.sh${NC}"
    echo -e "  Preview cleanup: ${BLUE}./cleanup_cores.sh --dry-run${NC}"
else
    echo -e "${GREEN}No core dumps found - server is running cleanly!${NC}"
    echo
    echo -e "${CYAN}Available Commands:${NC}"
    echo -e "  Clean old files: ${BLUE}./cleanup_cores.sh${NC}"
    echo -e "  View help: ${BLUE}./analyze_core.sh --help${NC}"
fi

echo -e "${PURPLE}═══════════════════════════════════════════════════════════════════════════════${NC}"
