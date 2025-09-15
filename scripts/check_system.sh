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
# *                                        System Dependency Check Script for SWR Server                                          *   
# *                                        Portable version that works from any directory                                         *
# *********************************************************************************************************************************

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
SWR_EXECUTABLE="$SRC_DIR/swr"

echo "========================================"
echo -e "${BLUE}SWR Server System Dependency Check${NC}"
echo "========================================"
echo ""

# Show paths being used
echo -e "${BLUE}Paths:${NC}"
echo "  Base directory:   $BASE_DIR"
echo "  Source directory: $SRC_DIR"
echo "  Server executable: $SWR_EXECUTABLE"
echo ""

# Basic system info
echo -e "${BLUE}System Information:${NC}"
echo "  OS: $(uname -s)"
echo "  Architecture: $(uname -m)"
echo "  Kernel: $(uname -r)"
echo "  Date: $(date)"
echo ""

# Check if server executable exists
echo -e "${BLUE}Server Executable Check:${NC}"
if [[ -f "$SWR_EXECUTABLE" ]]; then
    echo -e "  ${GREEN}✓${NC} Server executable found: $SWR_EXECUTABLE"
    
    # Check permissions
    if [[ -x "$SWR_EXECUTABLE" ]]; then
        echo -e "  ${GREEN}✓${NC} Server executable has execute permissions"
    else
        echo -e "  ${RED}✗${NC} Server executable is not executable"
        echo "    Fix with: chmod +x $SWR_EXECUTABLE"
        exit 1
    fi
    
    # Show file info
    if command -v ls >/dev/null 2>&1; then
        file_info=$(ls -lh "$SWR_EXECUTABLE" 2>/dev/null || echo "Cannot get file info")
        echo "    File info: $file_info"
    fi
else
    echo -e "  ${RED}✗${NC} Server executable not found: $SWR_EXECUTABLE"
    echo "    Please compile the server or check the path"
    echo "    Expected location relative to this script: ../src/swr"
    exit 1
fi

echo ""

# Check library dependencies
echo -e "${BLUE}Library Dependency Check:${NC}"
if command -v ldd >/dev/null 2>&1; then
    echo "  Checking with ldd..."
    
    # Capture ldd output
    ldd_output=$(ldd "$SWR_EXECUTABLE" 2>&1)
    ldd_exit_code=$?
    
    if [[ $ldd_exit_code -eq 0 ]]; then
        echo -e "  ${GREEN}✓${NC} Library dependency check completed"
        
        # Check for missing libraries
        missing_libs=$(echo "$ldd_output" | grep "not found" || true)
        if [[ -n "$missing_libs" ]]; then
            echo -e "  ${RED}✗${NC} Missing library dependencies:"
            echo "$missing_libs" | sed 's/^/    /'
            echo ""
            echo "  Common solutions:"
            echo "    - Install missing packages using your package manager"
            echo "    - Recompile the server on this system"
            echo "    - Use a compatible binary"
            exit 1
        else
            echo -e "  ${GREEN}✓${NC} All required libraries are available"
        fi
        
        # Check GLIBC version requirements
        echo ""
        echo "  GLIBC Version Analysis:"
        
        # Get required GLIBC versions from the executable
        if command -v objdump >/dev/null 2>&1; then
            glibc_reqs=$(objdump -T "$SWR_EXECUTABLE" 2>/dev/null | grep "GLIBC_" | sed 's/.*GLIBC_/GLIBC_/' | sed 's/).*//' | sort -V -u || true)
            if [[ -n "$glibc_reqs" ]]; then
                echo "    Required GLIBC versions:"
                echo "$glibc_reqs" | while read -r version; do
                    echo "      - $version"
                done
                
                # Find the highest required version
                highest_req=$(echo "$glibc_reqs" | tail -1)
                echo "    Highest requirement: $highest_req"
                
                # Get system GLIBC version
                if command -v ldd >/dev/null 2>&1; then
                    system_glibc=$(ldd --version 2>&1 | head -1 | grep -o '[0-9]\+\.[0-9]\+' | head -1 || echo "unknown")
                    echo "    System GLIBC version: $system_glibc"
                    
                    if [[ "$system_glibc" != "unknown" ]]; then
                        # Extract version numbers for comparison
                        req_version=$(echo "$highest_req" | sed 's/GLIBC_//')
                        
                        # Simple version comparison (assumes format X.Y)
                        if [[ -n "$req_version" ]]; then
                            req_major=$(echo "$req_version" | cut -d. -f1)
                            req_minor=$(echo "$req_version" | cut -d. -f2)
                            sys_major=$(echo "$system_glibc" | cut -d. -f1)
                            sys_minor=$(echo "$system_glibc" | cut -d. -f2)
                            
                            if [[ $sys_major -gt $req_major ]] || \
                               [[ $sys_major -eq $req_major && $sys_minor -ge $req_minor ]]; then
                                echo -e "    ${GREEN}✓${NC} System GLIBC version is compatible"
                            else
                                echo -e "    ${RED}✗${NC} System GLIBC version may be too old"
                                echo "      This is likely the cause of startup failures"
                                echo "      The server was compiled on a newer system"
                            fi
                        fi
                    fi
                fi
            else
                echo "    No specific GLIBC version requirements detected"
            fi
        else
            echo -e "    ${YELLOW}⚠${NC} objdump not available - cannot check GLIBC requirements"
        fi
        
    else
        echo -e "  ${RED}✗${NC} Library dependency check failed"
        echo "  Error output:"
        echo "$ldd_output" | sed 's/^/    /'
        
        # Check for common error patterns
        if echo "$ldd_output" | grep -q "not found"; then
            echo ""
            echo -e "  ${YELLOW}Common issue:${NC} Missing library dependencies"
            echo "  Try installing development packages for your distribution"
        elif echo "$ldd_output" | grep -q "GLIBC_"; then
            echo ""
            echo -e "  ${YELLOW}Common issue:${NC} GLIBC version mismatch"
            echo "  The server may have been compiled on a newer system"
        fi
        
        exit 1
    fi
else
    echo -e "  ${YELLOW}⚠${NC} ldd command not available - cannot check dependencies"
fi

echo ""

# Test basic execution (very brief)
echo -e "${BLUE}Basic Execution Test:${NC}"
echo "  Testing if server can start (will exit quickly)..."

# Try to run the server with immediate exit
# Change to the area directory first (where the server expects to run)
cd "$BASE_DIR/area" 2>/dev/null || cd "$BASE_DIR"

timeout 3s "$SWR_EXECUTABLE" --help >/dev/null 2>&1 || true
exit_code=$?

case $exit_code in
    0|1|2)
        echo -e "  ${GREEN}✓${NC} Server executable can run (exit code: $exit_code)"
        ;;
    124)
        echo -e "  ${GREEN}✓${NC} Server started successfully (timeout reached)"
        ;;
    126)
        echo -e "  ${RED}✗${NC} Permission denied when trying to execute"
        echo "    Fix with: chmod +x $SWR_EXECUTABLE"
        exit 1
        ;;
    127)
        echo -e "  ${RED}✗${NC} Command not found or missing dependencies"
        echo "    Check library dependencies above"
        echo "    This often indicates GLIBC version mismatch"
        exit 1
        ;;
    *)
        echo -e "  ${YELLOW}⚠${NC} Unexpected exit code: $exit_code"
        echo "    This may indicate system compatibility issues"
        
        # Try to get more information about the failure
        echo "    Attempting detailed error check..."
        error_output=$("$SWR_EXECUTABLE" 2>&1 | head -5 || true)
        if [[ -n "$error_output" ]]; then
            echo "    Error output:"
            echo "$error_output" | sed 's/^/      /'
        fi
        ;;
esac

echo ""

# Check for additional dependencies
echo -e "${BLUE}Additional Dependency Check:${NC}"

# Check for Python (needed for fallback server)
if command -v python3 >/dev/null 2>&1; then
    python_version=$(python3 --version 2>&1 | sed 's/Python //')
    echo -e "  ${GREEN}✓${NC} Python3 available: $python_version"
else
    echo -e "  ${YELLOW}⚠${NC} Python3 not available"
    echo "    Fallback server will not work without Python3"
fi

# Check for GDB (needed for core dump analysis)
if command -v gdb >/dev/null 2>&1; then
    gdb_version=$(gdb --version 2>&1 | head -1 | sed 's/GNU gdb //' | awk '{print $1}')
    echo -e "  ${GREEN}✓${NC} GDB available: $gdb_version"
else
    echo -e "  ${YELLOW}⚠${NC} GDB not available"
    echo "    Core dump analysis will be limited"
fi

# Check for network tools
if command -v ss >/dev/null 2>&1; then
    echo -e "  ${GREEN}✓${NC} ss (network monitoring) available"
elif command -v netstat >/dev/null 2>&1; then
    echo -e "  ${GREEN}✓${NC} netstat (network monitoring) available"
else
    echo -e "  ${YELLOW}⚠${NC} Neither ss nor netstat available"
    echo "    Port conflict detection will be limited"
fi

echo ""
echo "========================================"
echo -e "${BLUE}System Check Complete${NC}"
echo "========================================"

# Final assessment
echo -e "${BLUE}Overall Assessment:${NC}"
if [[ -f "$SWR_EXECUTABLE" ]] && [[ -x "$SWR_EXECUTABLE" ]]; then
    if command -v ldd >/dev/null 2>&1; then
        missing_libs=$(ldd "$SWR_EXECUTABLE" 2>&1 | grep "not found" || true)
        if [[ -z "$missing_libs" ]]; then
            echo -e "  ${GREEN}✓ System appears ready to run SWR server${NC}"
            echo ""
            echo "You can now start the server with:"
            echo "  cd $SRC_DIR && ./startup.sh"
            echo "  or"
            echo "  $BASE_DIR/scripts/mudctl.sh start"
            echo ""
            echo "For help with server management:"
            echo "  $BASE_DIR/scripts/mudctl.sh help"
        else
            echo -e "  ${RED}✗ Missing dependencies prevent server startup${NC}"
            echo "  Please resolve the library issues shown above"
            echo ""
            echo "  If you see GLIBC version errors:"
            echo "    - The server was compiled on a newer system"
            echo "    - You need to recompile the server on this system"
            echo "    - Or upgrade your system's GLIBC (may require OS upgrade)"
        fi
    else
        echo -e "  ${YELLOW}⚠ Cannot fully verify - ldd not available${NC}"
        echo "  Try starting the server to see if it works"
    fi
else
    echo -e "  ${RED}✗ Server executable issues prevent startup${NC}"
    echo "  Please resolve the file permission issues shown above"
fi

echo ""
