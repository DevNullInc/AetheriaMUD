#!/bin/bash

# Setup account directory structure for SWR MUD server
# This script ensures all necessary account subdirectories exist with proper permissions

# Get the script directory and set up paths
SCRIPT_DIR="$(dirname "$0")"
BASE_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
ACCOUNT_DIR="$BASE_DIR/account"

echo "Setting up account directory structure..."
echo "Base directory: $BASE_DIR"
echo "Account directory: $ACCOUNT_DIR"

# Create main account directory if it doesn't exist
if [[ ! -d "$ACCOUNT_DIR" ]]; then
    echo "Creating main account directory..."
    mkdir -p "$ACCOUNT_DIR"
fi

# Create subdirectories for each letter a-z
echo "Creating/verifying account subdirectories..."
for letter in {a..z}; do
    letter_dir="$ACCOUNT_DIR/$letter"
    if [[ ! -d "$letter_dir" ]]; then
        echo "Creating directory: $letter_dir"
        mkdir -p "$letter_dir"
    else
        echo "Directory exists: $letter_dir"
    fi
    
    # Set proper permissions (readable/writable by owner, readable by group)
    chmod 755 "$letter_dir" 2>/dev/null || true
done

# Set permissions on main account directory
chmod 755 "$ACCOUNT_DIR" 2>/dev/null || true

echo ""
echo "Account directory structure setup complete!"
echo ""
echo "Directory listing:"
ls -la "$ACCOUNT_DIR"

echo ""
echo "Testing write permissions..."
# Test write permissions in a few directories
for test_letter in a r z; do
    test_file="$ACCOUNT_DIR/$test_letter/.write_test"
    if touch "$test_file" 2>/dev/null; then
        echo "✅ Write permission OK for $ACCOUNT_DIR/$test_letter"
        rm -f "$test_file"
    else
        echo "❌ Write permission FAILED for $ACCOUNT_DIR/$test_letter"
        echo "   You may need to run: chmod -R 755 $ACCOUNT_DIR"
    fi
done

echo ""
echo "Setup complete! The server should now be able to save account files."
