#pragma once

#include "mud_types.hpp"

/*
 * ACT bits for players.
 */
#define PLR_IS_NPC BV00 /* Don't EVER set.   */
#define PLR_EXEMPT BV01
#define PLR_SHOVEDRAG BV02
#define PLR_AUTOEXIT BV03
#define PLR_AUTOLOOT BV04
#define PLR_AUTOSAC BV05
#define PLR_BLANK BV06
#define PLR_OUTCAST BV07
#define PLR_BRIEF BV08
#define PLR_COMBINE BV09
#define PLR_PROMPT BV10
#define PLR_TELNET_GA BV11
#define PLR_HOLYLIGHT BV12
#define PLR_WIZINVIS BV13
#define PLR_ROOMVNUM BV14
#define PLR_SILENCE BV15
#define PLR_NO_EMOTE BV16
#define PLR_ATTACKER BV17
#define PLR_NO_TELL BV18
#define PLR_LOG BV19
#define PLR_DENY BV20
#define PLR_FREEZE BV21
#define PLR_KILLER BV22
#define PLR_WHOINVIS BV23
#define PLR_LITTERBUG BV24
#define PLR_ANSI BV25
#define PLR_SOUND BV26
#define PLR_NICE BV27
#define PLR_FLEE BV28
#define PLR_AUTOGOLD BV29
#define PLR_SLOG BV30
#define PLR_AFK BV31

/* Bits for pc_data->flags. */
#define PCFLAG_R1 BV00
/* #define PCFLAG_                BV01     extra flag */
#define PCFLAG_UNAUTHED BV02
#define PCFLAG_NORECALL BV03
#define PCFLAG_NOINTRO BV04
#define PCFLAG_GAG BV05
#define PCFLAG_RETIRED BV06
#define PCFLAG_GUEST BV07
#define PCFLAG_HASSLUG BV08
#define PCFLAG_PAGERON BV09
#define PCFLAG_NOTITLE BV10
#define PCFLAG_ROOM BV11

/*
 * Player-specific structures.
 */
struct hunt_hate_fear
{
   char *name;
   CHAR_DATA *who;
};

struct fighting_data
{
   CHAR_DATA *who;
   int xp;
   short align;
   short duration;
   short timeskilled;
};

struct extracted_char_data
{
   EXTRACT_CHAR_DATA *next;
   CHAR_DATA *ch;
   ROOM_INDEX_DATA *room;
   ch_ret retcode;
   bool extract;
};

struct killed_data
{
   int vnum;
   char count;
};

/*
 * Data which only PC's have.
 */
struct pc_data
{
   CLAN_DATA *clan;
   AREA_DATA *area;
   ROOM_INDEX_DATA *roomarena;
   char *homepage;
   char *screenname;
   char *image;
   char *clan_name;
   char *pwd;
   char *email;
   char *bamfin;
   char *bamfout;
   int lost_attacks;
   char *rank;
   int shipnum;
   char *shipname;
   char *title;
   char *disguise;
   char *bestowments; /* Special bestowed commands     */
   int act2;
   int flags;      /* Whether the player is deadly and whatever else we add.      */
   int pkills;     /* Number of pkills on behalf of clan */
   int pdeaths;    /* Number of times pkilled (legally)  */
   int mkills;     /* Number of mobs killed         */
   int mdeaths;    /* Number of deaths due to mobs       */
   int illegal_pk; /* Number of illegal pk's committed   */
   char *fiance;
   char *propose;
   char *proposed;
   char *spouse;
   int forcerank;
   char *last_name;
   long int outcast_time; /* The time at which the char was outcast */
   long int restore_time; /* The last time the char did a restore all */
   int r_range_lo;        /* room range */
   int r_range_hi;
   int m_range_lo; /* mob range  */
   int m_range_hi;
   int o_range_lo; /* obj range  */
   int o_range_hi;
   char *tell_snoop; /* Tell snoop */
   short wizinvis;   /* wizinvis level */
   short min_snoop;  /* minimum snoop level */
   short condition[MAX_CONDS];
   short learned[MAX_SKILL];
   KILLED_DATA killed[MAX_KILLTRACK];
   short quest_number; /* current *QUEST BEING DONE* DON'T REMOVE! */
   short quest_curr;   /* current number of quest points */
   int quest_accum;    /* quest points accumulated in players life */
   int auth_state;
   time_t release_date; /* Auto-helling.. Altrag */
   char *helled_by;
   char *bio;                    /* Personal Bio */
   char *authed_by;              /* what crazy imm authed this name ;) */
   SKILLTYPE *special_skills[5]; /* personalized skills/spells */
   char *prompt;                 /* User config prompts */
   char *subprompt;              /* Substate prompt */
   short pagerlen;               /* For pager (NOT menus) */
   bool openedtourney;
   short addiction[10];
   short drug_level[10];
   char *store_title;
   bool is_hacking;
   int wanted_flags;
   long bank;
   int salary;
   bool hotboot; /* hotboot tracker */
};

/*
 * One character (PC or NPC).
 */
struct char_data
{
   CHAR_DATA *next;
   CHAR_DATA *prev;
   CHAR_DATA *next_in_room;
   CHAR_DATA *prev_in_room;
   CHAR_DATA *master;
   CHAR_DATA *leader;
   FIGHT_DATA *fighting;
   CHAR_DATA *reply;
   char *owner;
   ROOM_INDEX_DATA *home;
   CHAR_DATA *switched;
   BUG_DATA *first_bug;
   BUG_DATA *last_bug;
   CONTRACT_DATA *first_contract;
   CONTRACT_DATA *last_contract;
   FELLOW_DATA *first_fellow;
   FELLOW_DATA *last_fellow;
   CHAR_DATA *mount;
   HHF_DATA *hunting;
   HHF_DATA *fearing;
   HHF_DATA *hating;
   SPEC_FUN *spec_fun;
   SPEC_FUN *spec_2;
   char *spec_funname;
   char *spec_funname2;
   MPROG_ACT_LIST *mpact;
   int mpactnum;
   unsigned short mpscriptpos;
   MOB_INDEX_DATA *pIndexData;
   DESCRIPTOR_DATA *desc;
   AFFECT_DATA *first_affect;
   AFFECT_DATA *last_affect;
   NOTE_DATA *pnote;
   NOTE_DATA *comments;
   OBJ_DATA *first_carrying;
   OBJ_DATA *last_carrying;
   ROOM_INDEX_DATA *in_room;
   ROOM_INDEX_DATA *was_in_room;
   ROOM_INDEX_DATA *was_sentinel;
   ROOM_INDEX_DATA *plr_home;
   PC_DATA *pcdata;
   DO_FUN *last_cmd;
   DO_FUN *prev_cmd; /* mapping */
   CHAR_DATA *challenged;
   CHAR_DATA *betted_on;
   int bet_amt;
   void *dest_buf;
   void *dest_buf_2;
   void *spare_ptr;
   int tempnum;
   EDITOR_DATA *editor;
   TIMER *first_timer;
   TIMER *last_timer;
   char *name;
   char *short_descr;
   char *long_descr;
   char *description;
   short num_fighting;
   short substate;
   short sex;
   short race;
   short top_level;
   short skill_level[MAX_ABILITY];
   short bonus[MAX_ABILITY];
   short trust;
   int played;
   time_t logon;
   time_t save_time;
   short timer;
   short wait;
   short hit;
   short max_hit;
   int force_skill[MAX_FORCE_SKILL];
   short force_control;
   short force_sense;
   short force_alter;
   short force_chance;
   short force_identified;
   short force_level_status;
   short force_align;
   short force_converted;
   short force_type;
   char *force_master;
   char *force_temp_master;
   char *force_disguise;
   int force_disguise_count;
   int wait_state;
   short mana;
   short max_mana;
   short move;
   short max_move;
   short numattacks;
   int gold;
   long experience[MAX_ABILITY];
   int act;
   int affected_by;
   int carry_weight;
   int carry_number;
   int xflags;
   int resistant;
   int immune;
   int susceptible;
   int attacks;
   int defenses;
   int speaks;
   int speaking;
   short saving_poison_death;
   short saving_wand;
   short saving_para_petri;
   short saving_breath;
   short saving_spell_staff;
   short alignment;
   short barenumdie;
   short baresizedie;
   short mobthac0;
   short hitroll;
   short damroll;
   short hitplus;
   short damplus;
   short position;
   short defposition;
   short height;
   short weight;
   short armor;
   short wimpy;
   int deaf;
   short perm_str;
   short perm_int;
   short perm_wis;
   short perm_dex;
   short perm_con;
   short perm_cha;
   short perm_lck;
   short perm_frc;
   short mod_str;
   short mod_int;
   short mod_wis;
   short mod_dex;
   short mod_con;
   short mod_cha;
   short mod_lck;
   short mod_frc;
   short mental_state;    /* simplified */
   short emotional_state; /* simplified */
   int retran;
   int regoto;
   short mobinvis; /* Mobinvis level SB */
   int vip_flags;
   short backup_wait; /* reinforcements */
   int backup_mob;    /* reinforcements */
   short was_stunned;
   char *mob_clan; /* for spec_clan_guard.. set by postguard */
   GUARD_DATA *guard_data;
   short main_ability;
   short secondary_ability;
   short rppoints;
   char *comfreq;
   char *rank;
   int pheight, build;
   CHAR_DATA *aiming_at;
   short colors[MAX_COLORS];
   int home_vnum; /* hotboot tracker */
   int resetvnum;
   int resetnum;
};

