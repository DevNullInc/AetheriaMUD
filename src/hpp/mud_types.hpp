#pragma once

// All struct, enum, typedef, and class definitions from mud.hpp
// Forward declarations for all major structs
typedef struct affect_data AFFECT_DATA;
typedef struct area_data AREA_DATA;
typedef struct auction_data AUCTION_DATA;
typedef struct ban_data BAN_DATA;
typedef struct extracted_char_data EXTRACT_CHAR_DATA;
typedef struct bug_data BUG_DATA;
typedef struct contract_data CONTRACT_DATA;
typedef struct fellow_data FELLOW_DATA;
typedef struct char_data CHAR_DATA;
typedef struct hunt_hate_fear HHF_DATA;
typedef struct fighting_data FIGHT_DATA;
typedef struct descriptor_data DESCRIPTOR_DATA;
typedef struct exit_data EXIT_DATA;
typedef struct extra_descr_data EXTRA_DESCR_DATA;
typedef struct help_data HELP_DATA;
typedef struct mob_index_data MOB_INDEX_DATA;
typedef struct note_data NOTE_DATA;
typedef struct board_data BOARD_DATA;
typedef struct obj_data OBJ_DATA;
typedef struct obj_index_data OBJ_INDEX_DATA;
typedef struct pc_data PC_DATA;
typedef struct reset_data RESET_DATA;
typedef struct room_index_data ROOM_INDEX_DATA;
typedef struct shop_data SHOP_DATA;
typedef struct repairshop_data REPAIR_DATA;
typedef struct time_info_data TIME_INFO_DATA;
typedef struct hour_min_sec HOUR_MIN_SEC;
typedef struct weather_data WEATHER_DATA;
typedef struct bounty_data BOUNTY_DATA;
typedef struct blackmarket_data BMARKET_DATA;
typedef struct cargo_data CARGO_DATA;
typedef struct planet_data PLANET_DATA;
typedef struct storeroom STOREROOM;
typedef struct guard_data GUARD_DATA;
typedef struct space_data SPACE_DATA;
typedef struct clan_data CLAN_DATA;
typedef struct senate_data SENATE_DATA;
typedef struct ship_data SHIP_DATA;
typedef struct module_data MODULE_DATA;
typedef struct hanger_data HANGER_DATA;
typedef struct turret_data TURRET_DATA;
typedef struct ship_prototype_data SHIP_PROTOTYPE;
typedef struct missile_data MISSILE_DATA;
typedef struct mob_prog_data MPROG_DATA;
typedef struct mob_prog_act_list MPROG_ACT_LIST;
typedef struct mpsleep_data MPSLEEP_DATA;
typedef struct editor_data EDITOR_DATA;
typedef struct teleport_data TELEPORT_DATA;
typedef struct timer_data TIMER;
typedef struct system_data SYSTEM_DATA;
typedef struct smaug_affect SMAUG_AFF;
typedef struct who_data WHO_DATA;
typedef struct skill_type SKILLTYPE;
typedef struct social_type SOCIALTYPE;
typedef struct cmd_type CMDTYPE;
typedef struct killed_data KILLED_DATA;
typedef struct wizent WIZENT;
typedef struct member_data MEMBER_DATA;   /* Individual member data */
typedef struct member_list MEMBER_LIST;   /* List of members in clan */
typedef struct membersort_data MS_DATA;   /* List for sorted roster list */
typedef struct specfun_list SPEC_LIST;

// Enums
typedef enum { LOG_NORMAL, LOG_ALWAYS, LOG_NEVER, LOG_BUILD, LOG_HIGH, LOG_COMM, LOG_ALL } log_types;
typedef enum { rNONE, rCHAR_DIED, rVICT_DIED, rBOTH_DIED, rCHAR_QUIT, rVICT_QUIT, rBOTH_QUIT, rSPELL_FAILED, rOBJ_SCRAPPED, rOBJ_EATEN, rOBJ_EXPIRED, rOBJ_TIMER, rOBJ_SACCED, rOBJ_QUAFFED, rOBJ_USED, rOBJ_EXTRACTED, rOBJ_DRUNK, rCHAR_IMMUNE, rVICT_IMMUNE, rCHAR_AND_OBJ_EXTRACTED = 128, rERROR = 255 } ret_types;

// Structs
struct force_skills_struct { int type; int index; char *name; char *room_effect[5]; char *victim_effect[5]; char *ch_effect[5]; int cost; int control; int alter; int sense; char *code; int status; int wait_state; int disabled; int notskill; int mastertrain; DO_FUN *do_fun; FORCE_SKILL *next; FORCE_SKILL *prev; };
struct force_help_struct { char *name; int status; int type; char *desc; int skill; FORCE_HELP *next; FORCE_HELP *prev; };
struct rel_data { void *Actor; void *Subject; REL_DATA *next; REL_DATA *prev; relation_type Type; };
struct who_data { WHO_DATA *prev; WHO_DATA *next; char *text; int type; };
struct ban_data { BAN_DATA *next; BAN_DATA *prev; char *name; int level; char *ban_time; };
struct time_info_data { int hour; int day; int month; int year; };
struct hour_min_sec { int hour; int min; int sec; int manual; };
struct weather_data { int mmhg; int change; int sky; int sunlight; };
struct wizent { WIZENT *next; WIZENT *last; char *name; short level; };
struct descriptor_data { DESCRIPTOR_DATA *next; DESCRIPTOR_DATA *prev; DESCRIPTOR_DATA *snoop_by; CHAR_DATA *character; CHAR_DATA *original; struct mccp_data *mccp; bool can_compress; char *host; char *hostip; int port; int descriptor; short connected; short idle; short lines; short scrlen; bool fcommand; char inbuf[MAX_INBUF_SIZE]; char incomm[MAX_INPUT_LENGTH]; char inlast[MAX_INPUT_LENGTH]; int repeat; char *outbuf; unsigned long outsize; int outtop; char *pagebuf; unsigned long pagesize; int pagetop; char *pagepoint; char pagecmd; char pagecolor; int newstate; unsigned char prevcolor; int ifd; pid_t ipid; };
// ...all other struct definitions from mud.hpp...

// Typedefs
// ...existing code...

// Classes (if any)
// ...existing code...
