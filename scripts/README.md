# Aetherium Server Management Scripts

This directory contains portable server management and utility scripts for the SWR MUD server.

## Scripts Overview

### `mudctl.sh` - Main Server Control Script

The primary script for managing the SWR server. Works from any directory by automatically detecting paths.

**Usage:**

```bash
## Available Scripts

### 1. mudctl.sh - Main Server Controller
The primary script for managing the SWR MUD server with comprehensive functionality.

**Usage:** `./mudctl.sh [COMMAND] [OPTIONS]`

**Commands:**
- `status` - Show server status and process information
- `start [port]` - Start the server (default port: 4848)
- `stop` - Stop the server gracefully
- `restart [port]` - Restart the server
- `kill` - Force kill all server processes
- `kill-all` - Force kill all server and fallback processes
- `fallback [port]` - Start fallback server only
- `cleanup` - Clean up old log files and core dumps
- `logs [count]` - Show recent log entries (default: 20 lines)
- `tail` - Follow the latest log file
- `check` - Run system dependency check
- `interactive` - Launch interactive menu interface
- `advanced` - Launch advanced interface with live log streaming
- `help` - Show help message

### 2. mudctl-interactive.sh - Interactive Menu Interface
Provides a menu-driven interface with live monitoring capabilities.

**Features:**
- Real-time server status display
- Auto-refresh system information
- Color-coded status indicators
- Non-blocking menu interface
- Easy command execution

### 3. mudctl-advanced.sh - Advanced Monitoring Interface
Sophisticated monitoring interface with live log streaming and split-screen display.

**Features:**
- FIFO-based real-time log streaming
- Split-screen monitoring (main + fallback logs)
- Error highlighting with color coding
- Configurable display layout (40% logs / 60% menu)
- Live process monitoring
- Terminal layout management
- Advanced error pattern detection

**Interface Layout:**
```

┌─────────────────────────────────────────────┐
│              Log Display (40%)              │
│                                             │
├─────────────────────────────────────────────┤
│                                             │
│              Menu Area (60%)                │
│                                             │
└─────────────────────────────────────────────┘

### 4. check_system.sh - System Dependency Checker

Validates system requirements and dependencies for the SWR MUD server.

**Commands:**

- `status` - Show server status and process information
- `start [port]` - Start the server (default port: 4848)
- `stop` - Stop the server gracefully
- `restart [port]` - Restart the server
- `kill` - Force kill server processes
- `kill-all` - Force kill all server and fallback processes
- `fallback [port]` - Start fallback server only
- `cleanup` - Clean up old log files and core dumps
- `logs [count]` - Show recent log entries (default: 20 lines)
- `tail` - Follow the latest log file
- `check` - Run system dependency check
- `interactive` - Launch interactive menu interface
- `help` - Show help message

**Examples:**

```bash
# Start server on default port
./scripts/mudctl.sh start

# Start server on custom port
./scripts/mudctl.sh start 4949

# Check server status
./scripts/mudctl.sh status

# View last 50 lines of logs
./scripts/mudctl.sh logs 50

# Follow live logs
./scripts/mudctl.sh tail

# Clean up old files
./scripts/mudctl.sh cleanup

# Launch interactive interface
./scripts/mudctl.sh interactive
```

### `mudctl-interactive.sh` - Interactive Menu Interface

An enhanced interactive version of the server controller that provides a menu-driven interface with live monitoring.

**Usage:**

```bash
./scripts/mudctl-interactive.sh
```

**Features:**

- **Live Status Display**: Real-time server status, process information, and system metrics
- **Auto-refresh Mode**: Toggleable monitor mode that updates the display automatically
- **Menu-driven Commands**: Number/letter-based command selection for easy navigation
- **System Information**: Live display of log status, core dumps, memory usage, and system load
- **Color-coded Status**: Visual indicators for server state (running/stopped/fallback)
- **Non-blocking Operation**: Monitor server while keeping the interface accessible

**Interface Elements:**

- Server status (running/stopped) with PID information
- Fallback server status and management
- Port usage monitoring
- Latest log file information and statistics
- Core dump count and latest dump info
- System metrics (load, memory, disk usage)
- Interactive command menu with help system

**Navigation:**

- Enter command numbers (1-9) or letters (c,m,r,h,q)
- Toggle auto-refresh with 'm' for continuous monitoring
- Use 'r' to manually refresh the display
- Press 'q' or Ctrl+C to exit

### `check_system.sh` - System Dependency Checker

Comprehensive system check to verify the server can run on the current system.

**Usage:**

```bash
./scripts/check_system.sh
```

**Features:**

- Checks for server executable and permissions
- Verifies library dependencies with `ldd`
- Analyzes GLIBC version compatibility
- Tests basic server execution
- Checks for additional tools (Python3, GDB, network tools)
- Provides colored output for easy reading
- Gives specific recommendations for fixing issues

## Directory Structure

These scripts work with the following assumed directory structure:

```txt
swtfe/
├── scripts/          # Management scripts (this directory)
│   ├── mudctl.sh     # Main server control
│   └── check_system.sh # System dependency check
├── src/              # Server source and executable
│   ├── swr           # Server executable
│   ├── startup.sh    # Server startup script
│   ├── fallback_server.py # Fallback server
│   └── ...
├── area/             # Game area files
├── log/              # Server logs
├── core/             # Core dump storage and analysis
└── ...
```

## Path Resolution

All scripts automatically detect their location and calculate relative paths:

- **Base Directory**: `../` relative to script location
- **Source Directory**: `../src/` (contains server executable)
- **Area Directory**: `../area/` (game data files)
- **Log Directory**: `../log/` (server logs)
- **Core Directory**: `../core/` (crash dumps)

This makes the scripts portable - they work regardless of:

- Where the SWR directory is located on the filesystem
- What the parent directory is named
- Whether you run them with relative or absolute paths

## Migration from src/ Scripts

The original scripts in `src/` directory had hardcoded paths. These new scripts replace them:

| Old Location | New Location | Status |
|--------------|-------------|--------|
| `src/mudctl.sh` | `scripts/mudctl.sh` | Replaced with portable version |
| `src/check_system.sh` | `scripts/check_system.sh` | Replaced with portable version |

The old scripts can be removed once you verify the new ones work correctly.

## Usage Examples

### Starting the Server

```bash
# From any directory:
/path/to/swtfe/scripts/mudctl.sh start

# From the swtfe directory:
./scripts/mudctl.sh start

# From the scripts directory:
./mudctl.sh start
```

### Checking System Compatibility

```bash
# Before first run, check if your system can run the server:
./scripts/check_system.sh

# If you see GLIBC errors, the server was compiled on a newer system
# You'll need to recompile or upgrade your system
```

### Daily Operations

```bash
# Check if server is running:
./scripts/mudctl.sh status

# View recent activity:
./scripts/mudctl.sh logs 100

# Follow live logs:
./scripts/mudctl.sh tail

# Clean up old files:
./scripts/mudctl.sh cleanup
```

### Troubleshooting

```bash
# Force kill everything and clean up:
./scripts/mudctl.sh kill-all
./scripts/mudctl.sh cleanup

# Start fallback server for maintenance:
./scripts/mudctl.sh fallback

# Check system dependencies:
./scripts/mudctl.sh check
```

## Error Handling

These scripts include comprehensive error handling:

- **Missing Files**: Scripts check for required files and give helpful error messages
- **Permission Issues**: Clear instructions for fixing permission problems
- **GLIBC Compatibility**: Specific detection and advice for version mismatches
- **Port Conflicts**: Automatic detection and cleanup of port usage
- **Process Management**: Safe process termination with fallback to force kill

## Features

- **Colored Output**: Easy-to-read status messages with color coding
- **Automatic Path Detection**: No hardcoded paths - works anywhere
- **Comprehensive Logging**: All actions are logged with timestamps
- **Safe Process Management**: Graceful shutdown with force-kill fallback
- **System Validation**: Thorough pre-flight checks before operations
- **Cleanup Tools**: Automatic management of old logs and core dumps

## Requirements

- **Bash**: All scripts require bash shell
- **Standard Unix Tools**: ps, kill, ss/netstat, etc.
- **Python3**: Required for fallback server functionality
- **GDB**: Optional, for core dump analysis
- **ldd**: Optional, for dependency checking

## Troubleshooting Errors

### "Command not found" errors

- Make sure scripts are executable: `chmod +x scripts/*.sh`
- Use absolute paths if relative paths don't work
- Check that bash is available: `which bash`

### GLIBC version errors

- The server was compiled on a newer system
- Either recompile the server on your system, or upgrade your OS
- Use `./scripts/check_system.sh` for detailed version analysis

### Permission denied

- Check file permissions: `ls -la src/swr`
- Fix with: `chmod +x src/swr`
- Ensure you have execute permissions on the directory

### Port conflicts

- Use `./scripts/mudctl.sh status` to see what's using the port
- Use `./scripts/mudctl.sh kill-all` to clean up stuck processes
- Try a different port: `./scripts/mudctl.sh start 4949`

## Advanced Usage

### Custom Port Management

```bash
# Start on different port
./scripts/mudctl.sh start 5000

# Check what's using a specific port
ss -tlnp | grep :5000
```

### Log Analysis

```bash
# Search for specific errors
./scripts/mudctl.sh logs 1000 | grep "ERROR"

# Monitor for crashes
./scripts/mudctl.sh tail | grep -i "crash\|segmentation\|core"
```

### Maintenance Mode

```bash
# Start fallback server while fixing main server
./scripts/mudctl.sh fallback

# Players can connect and see maintenance message
# Fix main server issues, then restart normally
./scripts/mudctl.sh kill-all
./scripts/mudctl.sh start
```
