# Core Dump Management System

This directory contains core dumps and analysis tools for the SWR MUD server.

## Directory Structure

```text
core/
├── README.md           # This file
├── analyze_core.sh     # Core dump analysis script
├── cleanup_cores.sh    # Core dump cleanup utility
├── status.sh          # Show current core dump status
├── core.swr.YYYYMMDD_HHMMSS.PID    # Core dump files
└── core.swr.YYYYMMDD_HHMMSS.PID.analysis.txt  # Analysis reports
```

## Core Dump Files

Core dumps are automatically saved here when the MUD server crashes. They are named with the format:

- `core.swr.YYYYMMDD_HHMMSS.PID` - Where YYYYMMDD_HHMMSS is the timestamp and PID is the process ID

## Status Script

The `status.sh` script provides a quick overview of all core dumps:

```bash
# Show current status
./status.sh
```

### Status Features

- **File Counts**: Shows number of core dumps and analysis files
- **Size Information**: Total disk space used by core dumps
- **Recent Crashes**: Lists up to 10 most recent crashes with timestamps
- **Analysis Status**: Shows which dumps have been analyzed
- **Quick Commands**: Suggests relevant commands to run

## Cleanup Script

The `cleanup_cores.sh` script manages old core dumps:

```bash
# Clean files older than 30 days (default)
./cleanup_cores.sh

# Clean files older than 7 days
./cleanup_cores.sh --days 7

# Preview what would be deleted
./cleanup_cores.sh --dry-run

# Verbose output with file details
./cleanup_cores.sh --verbose
```

## Analysis Script

The `analyze_core.sh` script provides comprehensive analysis of core dumps:

### Usage

```bash
# Analyze the most recent core dump
./analyze_core.sh

# Analyze a specific core dump
./analyze_core.sh core.swr.20250830_142530.12345

# Specify both core dump and executable
./analyze_core.sh core.swr.20250830_142530.12345 /path/to/swr
```

### Features

- **Automatic Detection**: Finds the most recent core dump if none specified
- **Comprehensive Analysis**: Uses GDB to extract detailed crash information
- **Formatted Output**: Color-coded terminal output for easy reading
- **Saved Reports**: Creates detailed analysis files for future reference
- **Quick Summary**: Shows key crash information at a glance

### Analysis Report Contents

Each analysis includes:

- Crash location and signal information
- Register states at time of crash
- Complete backtrace (all threads)
- Local variables and function arguments
- Memory maps and shared libraries
- Stack and memory dumps
- Disassembly around crash point

## Requirements

- `gdb` - GNU Debugger (install with `sudo apt install gdb`)
- Core dumps must be generated with debug symbols for best results

## Manual Analysis

For interactive debugging, you can also run GDB manually:

```bash
gdb /path/to/swr core.swr.YYYYMMDD_HHMMSS.PID
```

## Maintenance

Core dumps can be large files. Consider periodically cleaning old dumps:

```bash
# Remove core dumps older than 30 days
find /workspaces/swtfe/core -name "core.*" -type f -mtime +30 -delete

# Remove analysis files older than 30 days
find /workspaces/swtfe/core -name "*.analysis.txt" -type f -mtime +30 -delete
```
