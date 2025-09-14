#!/usr/bin/env bash

# Core Dump Cleanup Script for SWR MUD
# THE FINAL EPISODE
#
# Manages core dump retention and cleanup

set -euo pipefail

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Get script directory and project paths
SCRIPT_DIR="$(dirname "$0")"
CORE_DIR="$(cd "$SCRIPT_DIR" && pwd)"

# Default retention period (days)
DEFAULT_RETENTION_DAYS=30

print_usage() {
    echo -e "${CYAN}Core Dump Cleanup Script${NC}"
    echo "Usage: $0 [options]"
    echo ""
    echo "Options:"
    echo "  -d, --days DAYS     Retention period in days (default: $DEFAULT_RETENTION_DAYS)"
    echo "  -n, --dry-run       Show what would be deleted without actually deleting"
    echo "  -v, --verbose       Verbose output"
    echo "  -h, --help          Show this help message"
    echo ""
    echo "Examples:"
    echo "  $0                          # Clean files older than 30 days"
    echo "  $0 -d 7                     # Clean files older than 7 days"
    echo "  $0 --dry-run                # Preview cleanup without deleting"
    echo "  $0 -d 14 --verbose          # Clean files older than 14 days with verbose output"
}

# Parse command line arguments
RETENTION_DAYS="$DEFAULT_RETENTION_DAYS"
DRY_RUN=false
VERBOSE=false

while [[ $# -gt 0 ]]; do
    case $1 in
        -d|--days)
            RETENTION_DAYS="$2"
            shift 2
            ;;
        -n|--dry-run)
            DRY_RUN=true
            shift
            ;;
        -v|--verbose)
            VERBOSE=true
            shift
            ;;
        -h|--help)
            print_usage
            exit 0
            ;;
        *)
            echo -e "${RED}Error: Unknown option '$1'${NC}"
            print_usage
            exit 1
            ;;
    esac
done

# Validate retention days
if ! [[ "$RETENTION_DAYS" =~ ^[0-9]+$ ]] || [[ "$RETENTION_DAYS" -lt 1 ]]; then
    echo -e "${RED}Error: Retention days must be a positive integer${NC}"
    exit 1
fi

echo -e "${CYAN}═══════════════════════════════════════════════════════════════════════════════${NC}"
echo -e "${CYAN}                            CORE DUMP CLEANUP${NC}"
echo -e "${CYAN}═══════════════════════════════════════════════════════════════════════════════${NC}"
echo
echo -e "${YELLOW}Core Directory:${NC} ${BLUE}$CORE_DIR${NC}"
echo -e "${YELLOW}Retention Period:${NC} ${GREEN}$RETENTION_DAYS days${NC}"
if [[ "$DRY_RUN" == true ]]; then
    echo -e "${YELLOW}Mode:${NC} ${BLUE}DRY RUN (no files will be deleted)${NC}"
fi
echo

# Find files to clean up
echo -e "${YELLOW}Scanning for old files...${NC}"

# Find core dumps older than retention period
OLD_CORES=$(find "$CORE_DIR" -name "core.swr.*" -type f -mtime +$RETENTION_DAYS 2>/dev/null || true)
OLD_ANALYSES=$(find "$CORE_DIR" -name "*.analysis.txt" -type f -mtime +$RETENTION_DAYS 2>/dev/null || true)

# Count and size calculations
CORE_COUNT=0
ANALYSIS_COUNT=0

if [[ -n "$OLD_CORES" ]]; then
    CORE_COUNT=$(echo "$OLD_CORES" | grep -c . || echo "0")
fi

if [[ -n "$OLD_ANALYSES" ]]; then
    ANALYSIS_COUNT=$(echo "$OLD_ANALYSES" | grep -c . || echo "0")
fi

if [[ "$CORE_COUNT" -eq 0 && "$ANALYSIS_COUNT" -eq 0 ]]; then
    echo -e "${GREEN}No files found older than $RETENTION_DAYS days.${NC}"
    echo -e "${CYAN}Cleanup complete - nothing to do!${NC}"
    exit 0
fi

# Calculate total size of files to be deleted
TOTAL_SIZE=0
if [[ -n "$OLD_CORES" ]]; then
    while IFS= read -r file; do
        if [[ -n "$file" && -f "$file" ]]; then
            SIZE=$(stat -c%s "$file" 2>/dev/null || echo "0")
            TOTAL_SIZE=$((TOTAL_SIZE + SIZE))
        fi
    done <<< "$OLD_CORES"
fi

if [[ -n "$OLD_ANALYSES" ]]; then
    while IFS= read -r file; do
        if [[ -n "$file" && -f "$file" ]]; then
            SIZE=$(stat -c%s "$file" 2>/dev/null || echo "0")
            TOTAL_SIZE=$((TOTAL_SIZE + SIZE))
        fi
    done <<< "$OLD_ANALYSES"
fi

echo -e "${YELLOW}Files to clean up:${NC}"
echo -e "  Core dumps: ${GREEN}$CORE_COUNT files${NC}"
echo -e "  Analysis files: ${GREEN}$ANALYSIS_COUNT files${NC}"
echo -e "  Total size: ${GREEN}$(numfmt --to=iec --suffix=B $TOTAL_SIZE)${NC}"
echo

# Show detailed list if verbose or dry run
if [[ "$VERBOSE" == true || "$DRY_RUN" == true ]]; then
    echo -e "${YELLOW}Files to be deleted:${NC}"
    
    if [[ -n "$OLD_CORES" ]]; then
        echo -e "${BLUE}Core dumps:${NC}"
        while IFS= read -r file; do
            if [[ -n "$file" && -f "$file" ]]; then
                SIZE=$(stat -c%s "$file" 2>/dev/null || echo "0")
                DATE=$(stat -c%y "$file" 2>/dev/null | cut -d' ' -f1)
                echo -e "  ${file} (${DATE}, $(numfmt --to=iec --suffix=B $SIZE))"
            fi
        done <<< "$OLD_CORES"
        echo
    fi
    
    if [[ -n "$OLD_ANALYSES" ]]; then
        echo -e "${BLUE}Analysis files:${NC}"
        while IFS= read -r file; do
            if [[ -n "$file" && -f "$file" ]]; then
                SIZE=$(stat -c%s "$file" 2>/dev/null || echo "0")
                DATE=$(stat -c%y "$file" 2>/dev/null | cut -d' ' -f1)
                echo -e "  ${file} (${DATE}, $(numfmt --to=iec --suffix=B $SIZE))"
            fi
        done <<< "$OLD_ANALYSES"
        echo
    fi
fi

# Confirm deletion (unless dry run)
if [[ "$DRY_RUN" == false ]]; then
    echo -e "${YELLOW}Proceed with deletion? [y/N]:${NC} "
    read -r response
    if [[ ! "$response" =~ ^[Yy]$ ]]; then
        echo -e "${BLUE}Cleanup cancelled.${NC}"
        exit 0
    fi
    echo
fi

# Perform cleanup
DELETED_COUNT=0
DELETED_SIZE=0

if [[ "$DRY_RUN" == false ]]; then
    echo -e "${YELLOW}Deleting files...${NC}"
    
    # Delete core dumps
    if [[ -n "$OLD_CORES" ]]; then
        while IFS= read -r file; do
            if [[ -n "$file" && -f "$file" ]]; then
                SIZE=$(stat -c%s "$file" 2>/dev/null || echo "0")
                if rm -f "$file" 2>/dev/null; then
                    DELETED_COUNT=$((DELETED_COUNT + 1))
                    DELETED_SIZE=$((DELETED_SIZE + SIZE))
                    if [[ "$VERBOSE" == true ]]; then
                        echo -e "  ${GREEN}Deleted:${NC} $file"
                    fi
                else
                    echo -e "  ${RED}Failed to delete:${NC} $file"
                fi
            fi
        done <<< "$OLD_CORES"
    fi
    
    # Delete analysis files
    if [[ -n "$OLD_ANALYSES" ]]; then
        while IFS= read -r file; do
            if [[ -n "$file" && -f "$file" ]]; then
                SIZE=$(stat -c%s "$file" 2>/dev/null || echo "0")
                if rm -f "$file" 2>/dev/null; then
                    DELETED_COUNT=$((DELETED_COUNT + 1))
                    DELETED_SIZE=$((DELETED_SIZE + SIZE))
                    if [[ "$VERBOSE" == true ]]; then
                        echo -e "  ${GREEN}Deleted:${NC} $file"
                    fi
                else
                    echo -e "  ${RED}Failed to delete:${NC} $file"
                fi
            fi
        done <<< "$OLD_ANALYSES"
    fi
    
    echo
    echo -e "${GREEN}Cleanup complete!${NC}"
    echo -e "  Files deleted: ${GREEN}$DELETED_COUNT${NC}"
    echo -e "  Space freed: ${GREEN}$(numfmt --to=iec --suffix=B $DELETED_SIZE)${NC}"
else
    echo -e "${BLUE}Dry run complete - no files were deleted.${NC}"
fi

echo -e "${CYAN}═══════════════════════════════════════════════════════════════════════════════${NC}"
