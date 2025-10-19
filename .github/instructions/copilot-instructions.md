---
applyTo: "**"
---

# AetheriaMUD AI Coding Guidelines

## Core Mandate & Motto

### Mission Statement

Modernize this **multi-file, multi-module legacy codebase** (AetheriaMUD, with AFKMud/DikuMUD/SMAUG origins) for **C++23 and x64**. Prioritize idiomatic C++ ownership, containers, safety, performance, and maintainability. Remove legacy patterns unless essential for persistence or compatibility. The codebase must evolve as a clean, modern C++23/x64 project—**not just by updating one file at a time**.

### Your Motto

**If it’s not C++23 and ready for x64, it’s getting deleted, rewritten, or replaced. No mercy. No C-lingo left behind. Build/test after every major edit. Narrate critical changes and respect user review for all big moves.**

---

## Commit Message Style: MAKE IT FUNNY

- Commit messages **MUST** be quirky, witty, or reference Star Wars or MUD humor.
- No dry, corporate messages allowed\!
- Use puns, jokes, or cheeky commentary.
- **Examples:**
  - "Made the code less buggy than a cheap roach motel"
  - "Refactored attributes—now with extra Aether alignment"
  - "Banished legacy pointers to the gomba pit"
  - "Renamed stuff so even Maskai would approve"
  - "Fixed a bug—Rax shot first"
- If unsure, err on the side of humor and fun.

---

## Project & Architecture Overview

### Project Context

AetheriaMUD is a C++ MUD server based on the SMAUG/SWR codebase with a Cyberspace/Cyberpunk theme. It features gridspace combat, hacking abilities, clan systems, and cyberpunk elements blending physical and digital realms. **The primary goal is transitioning to C++23 compliance.**

### Core Components

- **comm.cpp**: Main game loop, network handling, telnet/MCCP/MXP protocols
- **db.cpp**: World loading, area files (.are), mobiles, objects, rooms
- **interp.cpp**: Command interpreter and routing
- **space.cpp**: Space combat, ship systems, hyperspace travel
- **force.cpp**: Force powers, lightsaber combat, special abilities
- **clans.cpp**: Faction/guild management, territory control
- **planets.cpp**: Planetary systems, resource management
- **password.cpp/.hpp**: Modern Argon2-based password hashing system (replaces crypt())
- **mud.hpp**: The main brains of it all

### Key Data Structures

```cpp
CHAR_DATA* // Players and NPCs
OBJ_DATA* // Items and equipment
ROOM_DATA* // Locations
SHIP_DATA* // Spacecraft
PLANET_DATA* // Planetary systems
CLAN_DATA* // Factions
```

---

## Codebase Modernization Strategy

### 1\. Modernization Playbook (General Rules)

- **Strict C++23/x64:** Code must build with `-std=c++23 -m64 -Werror` and zero warnings.
- **Smart pointers:** Replace raw pointers with `std::unique_ptr`, `std::shared_ptr`, or `std::weak_ptr` everywhere except for legacy persistence or external APIs requiring raw pointers.
- **No manual memory (new/delete/malloc/free):** Only allowed in low-level wrappers or compatibility layers.
- **Replace C strings/buffers:** Use `std::string`, `std::string_view`, and safe C++ containers and formatting.
- **Encapsulate legacy structs:** Refactor C-style structs to classes with RAII, proper encapsulation, and member functions.
- **Replace macros:** Use `constexpr`, `inline` functions, or templates for type safety.
- **Refactor globals:** Remove global variables or convert them to singletons, except where persistence demands them.
- **Audit integer/pointer types for x64:** Remove 32-bit assumptions (`int` for pointers, etc.).
- **Refactor void\*/unsafe APIs:** Replace with type-safe alternatives like `std::variant` or templates.

### 2\. Header File Modularization (Project Specific)

The current `mud.hpp` file is a monolithic header. The planned strategy is to split it into logical domain-specific headers:

- `mud_types.hpp` - Core data structures (CHAR_DATA, OBJ_DATA, etc.)
- `mud_constants.hpp` - Game constants, limits, and enumerations
- `mud_functions.hpp` - Function declarations and prototypes
- `mud_macros.hpp` - Utility macros and helper functions
- `mud_network.hpp` - Network-related structures and protocols
- `mud_game.hpp` - Game-specific structures (ships, planets, clans)

### 3\. Naming Convention Modernization (Project Specific)

Gradually convert C-style `SNAKE_CASE` to C++ `PascalCase` conventions.

- `CHAR_DATA` → `CharData`
- `do_command()` → `DoCommand()`
- **No mass rename scripts**: Changes must be done contextually during refactoring.

---

## AI Agent Workflow & Rules of Engagement

### Agent Workflow

- **Within the open file:** Batch-fix all matching errors, warnings, and legacy patterns per modernization rules. Narrate intentions; do NOT pause for each individual edit.
- **Batch previews:** Use batch preview/review features so the user sees all proposed changes in one coherent diff before applying.
- **Multi-file/global edits:** Prepare and preview the complete change list. Request explicit user review/confirmation before proceeding.
- **Destructive/global actions:** Always halt and request user sign-off before mass renames, deletions, or global refactors.
- **Editing commands:** Review `/area/help.are` first; update/add help entries as commands are changed.
- **After batch changes:** Trigger `"buildclean"` and `"clangcheck"` for verification.

### Header File (hpp) Error Handling Rule

- **ALWAYS cross-reference errors/warnings with the `.hpp` files included in the file being edited.**
- If pointer/type errors, mismatches, or macro issues are detected, first check if the root cause is in the relevant `.hpp` file(s).
- **Fix the root cause in the header file(s)** if possible, rather than patching each individual error in every `.cpp` file.
- **Do NOT** blindly fix errors line-by-line in the current file when a header change could resolve the issue globally.

### Limiting the Range of Edits

- You are **disallowed** from using the `insert_edit_into_file` tool on its own for large files.
- **You MUST** use the `read_file` tool with `limit` and `offset` parameters to read only the relevant section of a file, providing a smaller context window for edits.

### Prohibited Actions

- Never run or suggest terminal-wide regex, shell scripts, or batch refactors without previewed diffs and user consent.
- Do not edit command structures without reviewing `/area/help.are` and updating documentation.
- Do not preserve legacy identifiers except for persistence/scripts.
- Never automate mass deletions or refactors without explicit preview and user approval.

---

## Build, Analysis & Server Management

### Build System & Commands

- **Primary Build:** `cd src && make all`
- **Full Rebuild (Clean & Log):** `"buildclean"` (maps to `cd src && make clean && make all 2>&1 | tee ../build.log`)
- **Debug Build:** `DEBUG=-g3 make all`

### Static Analysis

- **Primary Check:** `"clangcheck <file>"` (maps to the detailed script below)
- **Full Command:**

<!-- end list -->

```bash
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

### Server Management Scripts

- Start server: `./scripts/mudctl.sh start [port]`
- Interactive management: `./scripts/mudctl.sh interactive`
- Advanced monitoring: `./scripts/mudctl.sh advanced`

### Terminal Rules

- Only run terminal/batch commands after explicit user instruction.
- ALWAYS make a versioned backup before any mass/batch operation.

---

## Legacy MUD Codebase Considerations

- **Game Data & Persistence:** Never break save/load formats without explicit user approval. Batch-preview changes affecting file I/O or player data.
- **Networking:** Legacy socket code may use outdated APIs. Suggest modern, portable abstractions but always preview protocol or buffer changes.
- **Threading:** Old code is likely single-threaded. Recommend modern concurrency carefully and batch-preview related changes.
- **Command/Scripting:** If command tables or scripts are present, review and update `/area/help.are` with each change.
- **Testing:** Propose adding automated tests (e.g., Google Test) and modern CI/CD configurations.
- **Documentation:** Add Doxygen-style comments to legacy code as it is modernized.
- **Dead Code Audit:** Regularly propose batch removal of obsolete or unused code, with user sign-off.
- **Magic Numbers & Hardcoded Limits:** Flag these for review and refactoring into named constants or configurable values.

# AetheriaMUD AI Coding Guidelines

## Core Mandate & Motto

### Mission Statement

Modernize this **multi-file, multi-module legacy codebase** (AetheriaMUD, with AFKMud/DikuMUD/SMAUG origins) for **C++23 and x64**. Prioritize idiomatic C++ ownership, containers, safety, performance, and maintainability. Remove legacy patterns unless essential for persistence or compatibility. The codebase must evolve as a clean, modern C++23/x64 project—**not just by updating one file at a time**.

### Your Motto

**If it’s not C++23 and ready for x64, it’s getting deleted, rewritten, or replaced. No mercy. No C-lingo left behind. Build/test after every major edit. Narrate critical changes and respect user review for all big moves.**

## Commit Message Style: MAKE IT FUNNY

- Commit messages **MUST** be quirky, witty, or reference Star Wars or MUD humor.
- No dry, corporate messages allowed!
- Use puns, jokes, or cheeky commentary.
- **Examples:**
  - "Made the code less buggy than a Tatooine cantina"
  - "Refactored attributes—now with extra Force alignment"
  - "Banished legacy pointers to the Sarlacc pit"
  - "Renamed stuff so even Yoda would approve"
  - "Fixed a bug—Han shot first"
- If unsure, err on the side of humor and fun.

## Project & Architecture Overview

### Project Context

AetheriaMUD is a C++ MUD server based on the SMAUG/SWR codebase with a Star Wars Rebellion theme. It features space combat, force powers, clan systems, and cyberpunk elements blending physical and digital realms. **The primary goal is transitioning to C++23 compliance.**

### Core Components

- **comm.cpp**: Main game loop, network handling, telnet/MCCP/MXP protocols
- **db.cpp**: World loading, area files (.are), mobiles, objects, rooms
- **interp.cpp**: Command interpreter and routing
- **space.cpp**: Space combat, ship systems, hyperspace travel
- **force.cpp**: Force powers, lightsaber combat, special abilities
- **clans.cpp**: Faction/guild management, territory control
- **planets.cpp**: Planetary systems, resource management
- **password.cpp/.hpp**: Modern Argon2-based password hashing system (replaces crypt())

### Key Data Structures

```cpp
CHAR_DATA* // Players and NPCs
OBJ_DATA* // Items and equipment
ROOM_DATA* // Locations
SHIP_DATA* // Spacecraft
PLANET_DATA* // Planetary systems
CLAN_DATA* // Factions
```

## Codebase Modernization Strategy

### 1. Modernization Playbook (General Rules)

- **Strict C++23/x64:** Code must build with `-std=c++23 -m64 -Werror` and zero warnings.
- **Smart pointers:** Replace raw pointers with `std::unique_ptr`, `std::shared_ptr`, or `std::weak_ptr` everywhere except for legacy persistence or external APIs requiring raw pointers.
- **No manual memory (new/delete/malloc/free):** Only allowed in low-level wrappers or compatibility layers.
- **Replace C strings/buffers:** Use `std::string`, `std::string_view`, and safe C++ containers and formatting.
- **Encapsulate legacy structs:** Refactor C-style structs to classes with RAII, proper encapsulation, and member functions.
- **Replace macros:** Use `constexpr`, `inline` functions, or templates for type safety.
- **Refactor globals:** Remove global variables or convert them to singletons, except where persistence demands them.
- **Audit integer/pointer types for x64:** Remove 32-bit assumptions (`int` for pointers, etc.).
- **Refactor void\*/unsafe APIs:** Replace with type-safe alternatives like `std::variant` or templates.

### 2. Header File Modularization (Project Specific)

The current `mud.hpp` file is a monolithic header. The planned strategy is to split it into logical domain-specific headers:

- `mud_types.hpp` - Core data structures (CHAR_DATA, OBJ_DATA, etc.)
- `mud_constants.hpp` - Game constants, limits, and enumerations
- `mud_functions.hpp` - Function declarations and prototypes
- `mud_macros.hpp` - Utility macros and helper functions
- `mud_network.hpp` - Network-related structures and protocols
- `mud_game.hpp` - Game-specific structures (ships, planets, clans)

### 3. Naming Convention Modernization (Project Specific)

Gradually convert C-style `SNAKE_CASE` to C++ `PascalCase` conventions.

- `CHAR_DATA` → `CharData`
- `do_command()` → `DoCommand()`
- **No mass rename scripts**: Changes must be done contextually during refactoring.

## AI Agent Workflow & Rules of Engagement

### Agent Workflow

- **Within the open file:** Batch-fix all matching errors, warnings, and legacy patterns per modernization rules. Narrate intentions; do NOT pause for each individual edit.
- **Batch previews:** Use batch preview/review features so the user sees all proposed changes in one coherent diff before applying.
- **Multi-file/global edits:** Prepare and preview the complete change list. Request explicit user review/confirmation before proceeding.
- **Destructive/global actions:** Always halt and request user sign-off before mass renames, deletions, or global refactors.
- **Editing commands:** Review `/area/help.are` first; update/add help entries as commands are changed.
- **After batch changes:** Trigger `"buildclean"` and `"clangcheck"` for verification.

### Header File (hpp) Error Handling Rule

- **ALWAYS cross-reference errors/warnings with the `.hpp` files included in the file being edited.**
- If pointer/type errors, mismatches, or macro issues are detected, first check if the root cause is in the relevant `.hpp` file(s).
- **Fix the root cause in the header file(s)** if possible, rather than patching each individual error in every `.cpp` file.
- **Do NOT** blindly fix errors line-by-line in the current file when a header change could resolve the issue globally.

### Limiting the Range of Edits

- You are **disallowed** from using the `insert_edit_into_file` tool on its own for large files.
- **You MUST** use the `read_file` tool with `limit` and `offset` parameters to read only the relevant section of a file, providing a smaller context window for edits.

### Prohibited Actions

- Never run or suggest terminal-wide regex, shell scripts, or batch refactors without previewed diffs and user consent.
- Do not edit command structures without reviewing `/area/help.are` and updating documentation.
- Do not preserve legacy identifiers except for persistence/scripts.
- Never automate mass deletions or refactors without explicit preview and user approval.

## Build, Analysis & Server Management

### Build System & Commands

- **Primary Build:** `cd src && make all`
- **Full Rebuild (Clean & Log):** `"buildclean"` (maps to `cd src && make clean && make all 2>&1 | tee ../build.log`)
- **Debug Build:** `DEBUG=-g3 make all`

### Static Analysis

- **Primary Check:** `"clangcheck <file>"` (maps to the detailed script below)
- **Full Command:**

```bash
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

### Server Management Scripts

- Start server: `./scripts/mudctl.sh start [port]`
- Interactive management: `./scripts/mudctl.sh interactive`
- Advanced monitoring: `./scripts/mudctl.sh advanced`

### Terminal Rules

- Only run terminal/batch commands after explicit user instruction.
- ALWAYS make a versioned backup before any mass/batch operation.

## Legacy MUD Codebase Considerations

- **Game Data & Persistence:** Never break save/load formats without explicit user approval. Batch-preview changes affecting file I/O or player data.
- **Networking:** Legacy socket code may use outdated APIs. Suggest modern, portable abstractions but always preview protocol or buffer changes.
- **Threading:** Old code is likely single-threaded. Recommend modern concurrency carefully and batch-preview related changes.
- **Command/Scripting:** If command tables or scripts are present, review and update `/area/help.are` with each change.
- **Testing:** Propose adding automated tests (e.g., Google Test) and modern CI/CD configurations.
- **Documentation:** Add Doxygen-style comments to legacy code as it is modernized.
- **Dead Code Audit:** Regularly propose batch removal of obsolete or unused code, with user sign-off.
- **Magic Numbers & Hardcoded Limits:** Flag these for review and refactoring into named constants or configurable values.

## Development Workflow

### Adding New Features

1. **Commands**: Add to `interp.cpp::interp_fun()` and implement handler.
2. **Areas**: Create `.are` files in `/area/` following existing format.
3. **Items/Mobs**: Define in area files or use OLC system.
4. **Systems**: Extend existing modules (force, space, clans).
5. **Authentication**: Use `password.hpp` functions for secure password handling:
   - `hash_password()` for new password hashing
   - `verify_password()` for authentication (supports both Argon2 and legacy crypt)
   - `migrate_password()` for upgrading old crypt hashes to Argon2.

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

## Integration Points

### External Systems

- **MCCP**: Mud Client Compression Protocol
- **MXP**: Mud eXtension Protocol for enhanced clients
- **MSSP**: Mud Server Status Protocol
- **Web Interface**: Optional web server for WHO lists

### Security Systems

- **Argon2 Password Hashing**: Modern password security via `password.cpp/.hpp`

## Common Pitfalls

### Memory Management

- Always use `STRALLOC`/`STRFREE` for strings.
- Clean up affects with `affect_remove`.
- Extract characters/objects properly to avoid leaks.

### Network Handling

- Use `send_to_char` for player output.
- Handle buffer limits (`MAX_STRING_LENGTH`).
- Respect telnet protocol sequences.

## Getting Help

### Documentation

- `/doc/` directory contains design documents
- `/README.md` for project overview
- Inline code comments for complex systems

### Community Resources

- Based on SMAUG/SWR codebase
- Active development transitioning to C++23 compliance
- Extensive mudprog scripting system
