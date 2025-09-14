#!/bin/bash

# Character Authorization Helper Script
# This script helps authorize new characters when the spec_auth special function isn't working

# Get the script directory and set up paths
SCRIPT_DIR="$(dirname "$0")"
BASE_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

echo "SWR MUD Character Authorization Helper"
echo "====================================="
echo ""

echo "This script helps with character authorization when the automatic"
echo "system isn't working due to spec_auth special function issues."
echo ""

echo "To authorize a character manually:"
echo ""
echo "1. Start the server and create your immortal character"
echo "2. Have the new player create their character (they'll be stuck unauthorized)"
echo "3. Login as an immortal and use: authorize <playername> yes"
echo ""

echo "Example immortal commands:"
echo "  authorize Rokkwarr yes     - Authorize player named Rokkwarr"
echo "  authorize                  - List all pending authorizations"
echo ""

echo "The authorize command will:"
echo "  ✅ Remove PCFLAG_UNAUTHED flag"
echo "  ✅ Set auth_state to 3 (fully authorized)"
echo "  ✅ Record who authorized them"
echo "  ✅ Allow them to play normally"
echo ""

echo "Alternative: Fix the spec_auth function by rebuilding the server"
echo "  cd $BASE_DIR/src"
echo "  make clean"
echo "  make"
echo ""

echo "The authorization system should work automatically when:"
echo "  - Players go through the training hall (rooms 227-248)"
echo "  - They reach the Academy Steward (mob #248)"
echo "  - The spec_auth special function processes them"
echo "  - They get a school diploma and full authorization"
echo ""

read -p "Press Enter to continue..."
