# Compiler and target
CC       := $(shell command -v g++ 2>/dev/null || command -v clang++)
STD      := -std=c++23 # Requires GCC 13+ or Clang++ 15+
ARCH     := -m64 # Force 64-bit build

# Feature toggles
WEB      ?= -DWEB # Enable web server support (requires libmicrohttpd)
IMC      ?= 1 # Enable IMC2 support
IMCFLAGS := -DIMC -DIMCSMAUG # Enable IMC2 support

# OS detection
OS := $(shell uname | cut -d _ -f 1)
ifeq ($(OS),CYGWIN)
		WIN := 1
endif

ifndef WIN
		DYNLIB := -ldl
endif

# Libs via pkg-config (with fallbacks)
ARGON2_CFLAGS := $(shell pkg-config --cflags argon2 2>/dev/null)
ARGON2_LIBS   := $(shell pkg-config --libs   argon2 2>/dev/null || echo -largon2)
ZLIB_CFLAGS   := $(shell pkg-config --cflags zlib   2>/dev/null)
ZLIB_LIBS     := $(shell pkg-config --libs   zlib   2>/dev/null || echo -lz)
CRYPT         := -lcrypt

# Build/indent
INDENT       := indent
INDENT_FLAGS := -ts4 -nut -bap -bli0 -di10 -l78 -lp -nbc -i8 -sc -cdb -c1 -cd1 -nbfda -npcs -bad -hnl -nce -npsl -bl

# Defines and debug
DEFINES  := -DMCCP -DMXP -DACCOUNT -DOLC_HOMES -DRESTORE -DOLC_SHUTTLE $(WEB)
DEBUG    ?= -g3

# C++23 optimization - go native x64 with LTO
ifndef DEBUG
		OPT_FLAG := -pipe -O3 -march=native -mtune=native -flto
endif

# C++23 hardcore warning flags - NO MERCY MODE
W_FLAGS := -Wall -Wextra -Wpedantic -Wshadow -Wpointer-arith -Wcast-qual \
					 -Wcast-align -Wformat-security -Wconversion -Wsign-conversion \
					 -Wold-style-cast -Woverloaded-virtual -Wnon-virtual-dtor \
					 -Wdeprecated -Wdeprecated-declarations -Werror

# NO LEGACY CRUTCHES - fix the code instead
ifeq ($(CC),clang++)
	C_FLAGS := $(STD) -stdlib=libc++ $(ARCH) $(OPT_FLAG) $(DEBUG) $(DEFINES) $(IMCFLAGS) \
		$(ARGON2_CFLAGS) $(ZLIB_CFLAGS) $(W_FLAGS) \
		-MMD -MP
	L_FLAGS := $(DYNLIB) $(ARGON2_LIBS) $(ZLIB_LIBS) $(CRYPT) -lm -flto -stdlib=libc++
else
	C_FLAGS := $(STD) $(ARCH) $(OPT_FLAG) $(DEBUG) $(DEFINES) $(IMCFLAGS) \
		$(ARGON2_CFLAGS) $(ZLIB_CFLAGS) $(W_FLAGS) \
		-MMD -MP
	L_FLAGS := $(DYNLIB) $(ARGON2_LIBS) $(ZLIB_LIBS) $(CRYPT) -lm -flto
endif
# Add LTO to linking for maximum optimization
L_FLAGS := $(DYNLIB) $(ARGON2_LIBS) $(ZLIB_LIBS) $(CRYPT) -lm -flto

# Source files
CPP_FILES := body.cpp account.cpp act_comm.cpp act_info.cpp act_move.cpp act_obj.cpp \
						 act_wiz.cpp alias.cpp arena.cpp autobuild.cpp ban.cpp bank.cpp bet.cpp \
						 boards.cpp bounty.cpp build.cpp changes.cpp channels.cpp clans.cpp cleanup.cpp color.cpp combat.cpp \
						 comm.cpp comments.cpp const.cpp db.cpp delivery.cpp designship.cpp dns.cpp editor.cpp \
						 fight.cpp finger.cpp grid_c.cpp handler.cpp hashstr.cpp homes.cpp hotboot.cpp immcomm.cpp \
						 implants.cpp installations.cpp interp.cpp magic.cpp makeobjs.cpp mccp.cpp \
						 medic.cpp misc.cpp msp.cpp mud_comm.cpp mud_prog.cpp mxp.cpp occupations.cpp olc_bounty.cpp \
						 olc-shuttle.cpp olc.cpp password.cpp pfiles.cpp pilot.cpp player.cpp quest.cpp races.cpp raceskills.cpp \
						 renumber.cpp reset.cpp restore.cpp save.cpp shell.cpp shops.cpp \
						 skills.cpp smuggling.cpp space.cpp space2.cpp special.cpp starsystem.cpp swskills.cpp \
						 tables.cpp track.cpp update.cpp vendor.cpp wedding.cpp grid.cpp greet.cpp \
						 imccustom.cpp

ifdef IMC # IMC2 support
		CPP_FILES += imc.cpp md5.cpp
endif
ifdef WEB # Web server support
		CPP_FILES += web-server.cpp
endif

# Object files and dependencies
O_DIR    := o
O_FILES  := $(patsubst %.cpp,$(O_DIR)/%.o,$(CPP_FILES))
DEPS     := $(O_FILES:.o=.d)

# Targets
ifeq ($(WIN),1)
		SWR      := swr.exe
		RESOLVER := resolver.exe
else
		SWR      := swr
		RESOLVER := resolver
endif

# Make rules
.PHONY: all clean dns neat indentclean resolver

# Build all targets
all: $(SWR)

# Build the DNS resolver
dns: $(RESOLVER)

# Main server
$(SWR): $(O_FILES)
		@echo "Linking $(SWR) for $(OS) (WIN=$(WIN))"
ifdef WIN # Windows needs a .def file for exports
		@dlltool --export-all --output-def swr.def $(O_FILES)
		@dlltool --dllname $(SWR) --output-exp swr.exp --def swr.def
		@$(CC) $(W_FLAGS) -o $(SWR) $(O_FILES) swr.exp $(L_FLAGS)
else # Linux/Mac just link normally
		@$(CC) $(W_FLAGS) -o $(SWR) $(O_FILES) $(L_FLAGS)
endif #endif
		@[ -f /usr/bin/bf ] && /usr/bin/bf -s $(SWR) && /usr/bin/bf -m $(SWR) || true
		@chmod g+w $(SWR) $(O_FILES)

# Resolver utility
$(RESOLVER): $(O_DIR)/resolver.o
		@echo "Linking $(RESOLVER)"
		@$(CC) $(DEFINES) -o $(RESOLVER) $(O_DIR)/resolver.o
		@chmod g+w $(RESOLVER) && chmod a+x $(RESOLVER) && chmod g+w $(O_DIR)/resolver.o

# Compile rule with auto dep generation
$(O_DIR)/%.o: %.cpp mud.hpp
		@mkdir -p $(O_DIR)
		@echo "Compiling $< -> $@"
		$(CC) $(C_FLAGS) -c $< -o $@

# NOTE: To use std::format, you must have GCC 13+ or Clang++ 15+ with libc++ 15+.

# Clean up build artifacts
clean:
		@echo "Cleaning objects and resolver artifacts"
		@rm -f $(O_FILES) $(DEPS) $(RESOLVER) $(O_DIR)/resolver.o

# Neatify source code
neat:
		$(INDENT) $(INDENT_FLAGS) $(CPP_FILES) $(wildcard *.hpp)

# Auto-include dependencies (safe if missing)
-include $(DEPS) # Include dependency files
