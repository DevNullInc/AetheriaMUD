#pragma once

#ifdef __cplusplus
#define DECLARE_DO_FUN( fun )    extern "C" { DO_FUN    fun; } DO_FUN fun##_mangled
#define DECLARE_SPEC_FUN( fun )  extern "C" { SPEC_FUN  fun; } SPEC_FUN fun##_mangled
#define DECLARE_SPELL_FUN( fun ) extern "C" { SPELL_FUN fun; } SPELL_FUN fun##_mangled
#else
#define DECLARE_DO_FUN( fun )     DO_FUN    fun; DO_FUN fun##_mangled
#define DECLARE_SPEC_FUN( fun )   SPEC_FUN  fun; SPEC_FUN fun##_mangled
#define DECLARE_SPELL_FUN( fun )  SPELL_FUN fun; SPELL_FUN fun##_mangled
#endif

// Function prototypes from mud.hpp
void show_jack_pot( void );
void do_game( void );
int num_in_arena( void );
void find_game_winner( void );
void do_end_game( void );
void start_game( void );
void silent_end( void );
void write_fame_list( void );
void load_hall_of_fame( void );

// ---------------------------------------------------------------------------
// act_comm.cpp
// ---------------------------------------------------------------------------
void DoSay(CHAR_DATA *ch, const char *argument);
void DoShout(CHAR_DATA *ch, const char *argument);
void DoEmote(CHAR_DATA *ch, const char *argument);
DECLARE_DO_FUN(do_say);
DECLARE_DO_FUN(do_shout);
DECLARE_DO_FUN(do_emote);

// ---------------------------------------------------------------------------
// act_info.cpp
// ---------------------------------------------------------------------------
void DoLook(CHAR_DATA *ch, const char *argument);
void DoExamine(CHAR_DATA *ch, const char *argument);
DECLARE_DO_FUN(do_look);
DECLARE_DO_FUN(do_examine);

// ---------------------------------------------------------------------------
// act_move.cpp
// ---------------------------------------------------------------------------
void DoNorth(CHAR_DATA *ch, const char *argument);
void DoSouth(CHAR_DATA *ch, const char *argument);
void DoEast(CHAR_DATA *ch, const char *argument);
void DoWest(CHAR_DATA *ch, const char *argument);
DECLARE_DO_FUN(do_north);
DECLARE_DO_FUN(do_south);
DECLARE_DO_FUN(do_east);
DECLARE_DO_FUN(do_west);

// ---------------------------------------------------------------------------
// act_obj.cpp
// ---------------------------------------------------------------------------
void DoGet(CHAR_DATA *ch, const char *argument);
void DoDrop(CHAR_DATA *ch, const char *argument);
void DoPut(CHAR_DATA *ch, const char *argument);
DECLARE_DO_FUN(do_get);
DECLARE_DO_FUN(do_drop);
DECLARE_DO_FUN(do_put);

// ---------------------------------------------------------------------------
// act_wiz.cpp
// ---------------------------------------------------------------------------
void DoGoto(CHAR_DATA *ch, const char *argument);
void DoAt(CHAR_DATA *ch, const char *argument);
void DoTransfer(CHAR_DATA *ch, const char *argument);
DECLARE_DO_FUN(do_goto);
DECLARE_DO_FUN(do_at);
DECLARE_DO_FUN(do_transfer);

// ---------------------------------------------------------------------------
// boards.cpp
// ---------------------------------------------------------------------------
void DoBoard(CHAR_DATA *ch, const char *argument);
DECLARE_DO_FUN(do_board);

// ---------------------------------------------------------------------------
// build.cpp
// ---------------------------------------------------------------------------
void DoBuild(CHAR_DATA *ch, const char *argument);
DECLARE_DO_FUN(do_build);

// ---------------------------------------------------------------------------
// clans.cpp
// ---------------------------------------------------------------------------
void DoClan(CHAR_DATA *ch, const char *argument);
DECLARE_DO_FUN(do_clan);

// ---------------------------------------------------------------------------
// bounty.cpp
// ---------------------------------------------------------------------------
void DoBounty(CHAR_DATA *ch, const char *argument);
DECLARE_DO_FUN(do_bounty);

// ---------------------------------------------------------------------------
// force.cpp
// ---------------------------------------------------------------------------
void DoForce(CHAR_DATA *ch, const char *argument);
DECLARE_DO_FUN(do_force);

// ---------------------------------------------------------------------------
// space.cpp
// ---------------------------------------------------------------------------
void DoSpace(CHAR_DATA *ch, const char *argument);
DECLARE_DO_FUN(do_space);

// ---------------------------------------------------------------------------
// shops.cpp (placeholder)
// ---------------------------------------------------------------------------
// TODO: Add shops.cpp function prototypes here
