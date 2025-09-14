# AetheriaMUD AI Coding Guidelines

## Project Overview
AetheriaMUD is a C++ MUD server based on SMAUG/SWR codebase with Star Wars Rebellion theme. It features space combat, force powers, clan systems, and cyberpunk elements blending physical and digital realms. **Currently transitioning to C++23 compliance.**

## Architecture Overview

### Core Components
- **comm.cpp**: Main game loop, network handling, telnet/MCCP/MXP protocols
- **db.cpp**: World loading, area files (.are), mobiles, objects, rooms
- **interp.cpp**: Command interpreter and routing
- **space.cpp**: Space combat, ship systems, hyperspace travel
- **force.cpp**: Force powers, lightsaber combat, special abilities
- **clans.cpp**: Faction/guild management, territory control
- **planets.cpp**: Planetary systems, resource management
- **password.cpp/.hpp**: Modern Argon2-based password hashing system (replaces crypt())

### Data Flow
1. **Boot Sequence**: `startup.sh` → `db.cpp::boot_db()` loads areas from `/area/*.are`
2. **Game Loop**: `comm.cpp::game_loop()` processes network I/O and game ticks
3. **Command Processing**: Player input → `interp.cpp` → specific command handlers
4. **World Updates**: `update.cpp` handles time progression, mob AI, weather

### Key Data Structures
```cpp
CHAR_DATA*  // Players and NPCs
OBJ_DATA*   // Items and equipment
ROOM_DATA*  // Locations
SHIP_DATA*  // Spacecraft
PLANET_DATA* // Planetary systems
CLAN_DATA*  // Factions
```

## Codebase Architecture & Modernization

### Header File Modularization
The current `mud.hpp` file is a monolithic header containing **47,844 tokens** (20,366 words, 135,436 characters without spaces, 173,719 characters with spaces/tabs). This exceeds most LLM context windows and hinders maintainability.

**Planned Modularization Strategy:**
- Split `mud.hpp` into logical domain-specific headers:
  - `mud_types.hpp` - Core data structures (CHAR_DATA, OBJ_DATA, etc.)
  - `mud_constants.hpp` - Game constants, limits, and enumerations
  - `mud_functions.hpp` - Function declarations and prototypes
  - `mud_macros.hpp` - Utility macros and helper functions
  - `mud_network.hpp` - Network-related structures and protocols
  - `mud_game.hpp` - Game-specific structures (ships, planets, clans)

**Benefits:**
- Improved LLM compatibility (smaller, focused files)
- Faster compilation times
- Better code organization and maintainability
- Easier debugging and testing
- Reduced header dependencies

**Migration Approach:**
- Maintain backward compatibility during transition
- Update includes gradually across source files
- Preserve existing functionality while improving structure

### Naming Convention Modernization
The codebase currently uses C-style `SNAKE_CASE` naming conventions inherited from the original SMAUG codebase. As part of the C++ modernization effort, identifiers will be gradually converted to C++ `PascalCase` conventions:

**Current → Target Examples:**
- `CHAR_DATA` → `CharData`
- `OBJ_DATA` → `ObjData` 
- `ROOM_DATA` → `RoomData`
- `SHIP_DATA` → `ShipData`
- `do_command()` → `DoCommand()`
- `get_char_room()` → `GetCharRoom()`

**Migration Strategy:**
- Convert identifiers gradually during refactoring
- Use `using` declarations for backward compatibility during transition
- Update function names when modifying related code
- Maintain C-style names for external API compatibility where needed
- **No mass rename scripts**: Changes like `sh_int` → `short` should be done contextually, not via batch/shell/Python scripts

**Important**: Each section of code should be reviewed in context when making naming convention changes. Automated mass renaming can introduce subtle bugs and break code that depends on specific naming patterns.

## Build System

### Primary Build Command
```bash
cd src && make all
```
- **Currently**: Uses older C++ standard (transitioning to C++23)
- **Target**: C++23 with GCC 13+/Clang 15+ (Makefile configured but code not yet compliant)
- Links against: zlib, argon2, crypt, math, dl
- Produces `swr` executable in `/src/`

### Build Variants
```bash
buildclean  # Full rebuild (cleans, builds, and logs warnings/errors to build.log)
make dns               # Build DNS resolver utility
WEB= make all          # Enable web server (libmicrohttpd)
```

### Debug Build
```bash
DEBUG=-g3 make all     # Full debug symbols
```
```bash
DEBUG=-g3 make all     # Full debug symbols
```

## Server Management

### Essential Commands
```bash
# Start server (from project root)
./scripts/mudctl.sh start [port]

# Interactive management (requires running server)
./scripts/mudctl.sh interactive

# Advanced monitoring with live logs (requires running server)
./scripts/mudctl.sh advanced

# Check system dependencies
./scripts/check_system.sh
```

**Note**: Most scripts in `/scripts/` require the MUD server to be running and operational.

### Log Management
- Logs: `/log/` directory
- Core dumps: `/core/` with analysis tools
- Use `./core/analyze_core.sh` for crash investigation

## Development Workflow

### Adding New Features
1. **Commands**: Add to `interp.cpp::interp_fun()` and implement handler
2. **Areas**: Create `.are` files in `/area/` following existing format
3. **Items/Mobs**: Define in area files or use OLC system
4. **Systems**: Extend existing modules (force, space, clans)
5. **Authentication**: Use `password.hpp` functions for secure password handling:
   - `hash_password()` for new password hashing
   - `verify_password()` for authentication (supports both Argon2 and legacy crypt)
   - `migrate_password()` for upgrading old crypt hashes to Argon2

### Code Style Conventions
- **Functions**: `void do_command(CHAR_DATA* ch, const char* argument)`
- **Macros**: `KEY(literal, field, value)` for config parsing
- **Bitvectors**: `BV00` through `BV31` for flags
- **Strings**: Use `MAX_STRING_LENGTH` (4096) limits

### Common Patterns
```cpp
// Command handler pattern
void do_mycommand(CHAR_DATA* ch, const char* argument) {
    if (IS_NPC(ch)) return;
    if (!argument || argument[0] == '\0') {
        send_to_char("Usage: mycommand <target>\n\r", ch);
        return;
    }
    // Implementation
}

// Affect application
AFFECT_DATA* af = new_affect();
af->type = gsn_myability;
af->duration = 10;
af->modifier = 5;
af->location = APPLY_STR;
affect_to_char(ch, af);
```

## Game Systems

### Space Combat
- Ships defined in `/ships/` directory
- Combat handled in `space.cpp`
- Hyperspace travel with "Grid-Drives"
- Ship systems: shields, weapons, engines

### Force Powers
- Skills in `/force/` directory
- Combat integration in `fight.cpp`
- Special abilities: lightsabers, mind tricks, healing

### Economy & Clans
- Planetary control in `planets.cpp`
- Resource management and taxation
- Clan territories and influence

## Configuration Files

### System Configuration
- `/system/sysdata.dat`: Core settings (levels, flags, purge settings)
- `/system/skills.dat`: Skill definitions and costs
- `/system/commands.dat`: Command permissions

### Game World
- `/area/*.are`: Area definitions (rooms, mobiles, objects)
- `/planets/*.planet`: Planetary data
- `/clans/*.clan`: Faction definitions

## Testing & Debugging

### Runtime Debugging
```bash
# Attach debugger to running server
gdb -p $(pgrep swr)

# Analyze core dump
./core/analyze_core.sh core.swr.TIMESTAMP.PID
```

### Static Analysis
```bash
# Clang static analysis (matches Makefile configuration)
cd /workspaces/AetheriaMUD/src && clear && clang-check-18 "$1" -- \
  -std=c++23 -stdlib=libc++ -m64 \
  $(pkg-config --cflags argon2 2>/dev/null) \
  $(pkg-config --cflags zlib 2>/dev/null) \
  -DMCCP -DMXP -DACCOUNT -DOLC_HOMES -DRESTORE -DOLC_SHUTTLE -DWEB -DIMC -DIMCSMAUG \
  -Wall -Wextra -Wpedantic -Wshadow -Wpointer-arith -Wcast-qual \
  -Wcast-align -Wformat-security -Wconversion -Wsign-conversion \
  -Wold-style-cast -Woverloaded-virtual -Wnon-virtual-dtor \
  -Wdeprecated -Wdeprecated-declarations \
  2>&1 | grep -E "[0-9]+:[0-9]+:.*(warning|error)"
```

### Log Analysis
```bash
# Follow live logs
./scripts/mudctl.sh tail

# Search logs for patterns
grep "ERROR" /log/*.log
```

### Memory Management
- Uses custom allocation for game objects
- Extract queues for cleanup: `extracted_obj_queue`, `extracted_char_queue`
- String hashing enabled (`HASHSTR`)

## Integration Points

### External Systems
- **MCCP**: Mud Client Compression Protocol
- **MXP**: Mud eXtension Protocol for enhanced clients
- **MSSP**: Mud Server Status Protocol
- **Web Interface**: Optional web server for WHO lists

### Security Systems
- **Argon2 Password Hashing**: Modern password security via `password.cpp/.hpp`
  - Replaces vulnerable crypt() functions with memory-hard Argon2id algorithm
  - Configurable time/memory costs for performance tuning
  - Automatic salt generation and legacy hash migration
  - Resistant to GPU/ASIC attacks and rainbow table attacks

### File Formats
- **Area Files**: Custom text format with # sections
- **Player Files**: Binary saves in `/player/` subdirectories
- **Configuration**: Key-value pairs with ~ termination

## Common Pitfalls

### Memory Management
- Always use `STRALLOC`/`STRFREE` for strings
- Clean up affects with `affect_remove`
- Extract characters/objects properly to avoid leaks

### Network Handling
- Use `send_to_char` for player output
- Handle buffer limits (`MAX_STRING_LENGTH`)
- Respect telnet protocol sequences

### Game Balance
- Test force powers don't break combat
- Verify ship combat balance
- Check clan influence mechanics

## Performance Considerations

### Optimization Targets
- Network I/O in main loop
- Area loading at startup
- Combat calculations
- String processing

### Profiling
```bash
# Use gprof for performance analysis
make DEBUG="-pg" all
./swr
gprof swr gmon.out > profile.txt
```

## Deployment

### Production Setup
1. Build optimized: `make all` (no DEBUG)
2. Configure system settings in `/system/`
3. Set up log rotation
4. Configure core dump handling
5. Start with `./scripts/mudctl.sh start`

### Backup Strategy
- Player data: `/player/` directory
- World data: `/area/`, `/planets/`, `/ships/`
- Configuration: `/system/` directory
- Logs: `/log/` for analysis

## Getting Help

### Documentation
- `/doc/` directory contains design documents
- `/README.md` for project overview
- Inline code comments for complex systems

### Community Resources
- Based on SMAUG/SWR codebase
- Active development transitioning to C++23 compliance
- Extensive mudprog scripting system</content>
<parameter name="filePath">/workspaces/AetheriaMUD/.github/copilot-instructions.md