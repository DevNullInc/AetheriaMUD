#!/usr/bin/env bash

# Fallback Telnet Server for SWR MUD
# THE FINAL EPISODE
#
# Simple maintenance server when main MUD is down

set -euo pipefail

# Configuration
PORT="${1:-4848}"
MAX_CONNECTIONS=10
MESSAGE="Star Wars Reality MUD - Server Temporarily Unavailable

The main game server is currently down for maintenance or experiencing technical difficulties.
Our administrators have been notified and are working to restore service.

Please check back in a few minutes.

For urgent issues, please contact: crashalert@renegadeinc.net

Connection will close in 30 seconds...
"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

echo -e "${CYAN}═══════════════════════════════════════════════════════════════════════════════${NC}"
echo -e "${YELLOW}                        SWR MUD FALLBACK SERVER${NC}"
echo -e "${CYAN}═══════════════════════════════════════════════════════════════════════════════${NC}"
echo
echo -e "${YELLOW}Port:${NC} ${GREEN}$PORT${NC}"
echo -e "${YELLOW}Max Connections:${NC} ${GREEN}$MAX_CONNECTIONS${NC}"
echo -e "${YELLOW}Status:${NC} ${RED}Main server is DOWN - Fallback active${NC}"
echo
echo -e "${BLUE}Listening for connections... (Ctrl+C to stop)${NC}"
echo

# Create temporary FIFO for communication
FIFO_DIR="/tmp/swr_fallback_$$"
mkdir -p "$FIFO_DIR"
FIFO="$FIFO_DIR/pipe"

# Cleanup function
cleanup() {
    echo
    echo -e "${YELLOW}Shutting down fallback server...${NC}"
    # Kill any background processes
    jobs -p | xargs -r kill 2>/dev/null || true
    # Remove FIFO directory
    rm -rf "$FIFO_DIR" 2>/dev/null || true
    echo -e "${GREEN}Fallback server stopped.${NC}"
    exit 0
}

# Set up signal handlers
trap cleanup SIGINT SIGTERM

# Handle client connections
handle_client() {
    local client_fd="$1"
    local client_ip="$2"
    local timestamp=$(date '+%Y-%m-%d %H:%M:%S')
    
    echo -e "${GREEN}[$timestamp] Client connected from: $client_ip${NC}"
    
    # Send the maintenance message
    echo -e "$MESSAGE" >&"$client_fd"
    
    # Wait 30 seconds then close
    sleep 30
    
    # Close the connection
    exec {client_fd}>&-
    
    echo -e "${YELLOW}[$timestamp] Client disconnected: $client_ip${NC}"
}

# Check if netcat is available
if ! command -v nc >/dev/null 2>&1; then
    echo -e "${RED}Error: netcat (nc) is not installed.${NC}"
    echo "Please install netcat: sudo apt install netcat-openbsd"
    exit 1
fi

# Check if port is already in use
if ss -tlnp | grep -q ":$PORT "; then
    echo -e "${RED}Error: Port $PORT is already in use.${NC}"
    echo "Please check if the main server is already running or choose a different port."
    exit 1
fi

# Start the fallback server
echo -e "${GREEN}Starting fallback server on port $PORT...${NC}"

# Use netcat to listen for connections
while true; do
    # Create a new FIFO for this connection
    mkfifo "$FIFO" 2>/dev/null || true
    
    # Listen for a connection and handle it
    nc -l -p "$PORT" -c "
        CLIENT_IP=\$(echo \$SSH_CLIENT | cut -d' ' -f1)
        if [[ -z \"\$CLIENT_IP\" ]]; then
            CLIENT_IP=\"unknown\"
        fi
        
        echo \"Star Wars Reality MUD - Server Temporarily Unavailable\"
        echo \"\"
        echo \"The main game server is currently down for maintenance or experiencing\"
        echo \"technical difficulties. Our administrators have been notified and are\"
        echo \"working to restore service.\"
        echo \"\"
        echo \"Please check back in a few minutes.\"
        echo \"\"
        echo \"For urgent issues, please contact: crashalert@renegadeinc.net\"
        echo \"\"
        echo \"Connection will close in 30 seconds...\"
        echo \"\"
        
        # Log the connection
        echo \"\$(date '+%Y-%m-%d %H:%M:%S') - Client connected from: \$CLIENT_IP\" >&2
        
        # Wait and then close
        sleep 30
        
        echo \"Connection closed.\"
        echo \"\$(date '+%Y-%m-%d %H:%M:%S') - Client disconnected: \$CLIENT_IP\" >&2
    " 2>&1 | while read line; do
        if [[ "$line" == *"Client connected"* ]] || [[ "$line" == *"Client disconnected"* ]]; then
            echo -e "${GREEN}$line${NC}"
        fi
    done &
    
    # Brief pause to prevent rapid looping
    sleep 1
done
