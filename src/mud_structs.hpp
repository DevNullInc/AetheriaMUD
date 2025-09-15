/*********************************************************************************************************************************
 *                                                                                                                   ;           *
 *                                                                                                                  ED.          *
 *                        ,;                             ,;                                                  :      E#Wi         *
 *                      f#i          .    .            f#i j.         t                                      Ef     E###G.       *
 *             ..     .E#t  GEEEEEEELDi   Dt         .E#t  EW,        Ej             ..           ..       : E#t    E#fD#W;      *
 *            ;W,    i#W,   ,;;L#K;;.E#i  E#i       i#W,   E##j       E#,           ;W,          ,W,     .Et E#t    E#t t##L     *
 *           j##,   L#D.       t#E   E#t  E#t      L#D.    E###D.     E#t          j##,         t##,    ,W#t E#t    E#t  .E#K,   *
 *          G###, :K#Wfff;     t#E   E#t  E#t    :K#Wfff;  E#jG#W;    E#t         G###,        L###,   j###t E#t fi E#t    j##f  *
 *        :E####, i##WLLLLt    t#E   E########f. i##WLLLLt E#t t##f   E#t       :E####,      .E#j##,  G#fE#t E#t L#jE#t    :E#K: *
 *       ;W#DG##,  .E#L        t#E   E#j..K#j...  .E#L     E#t  :K#E: E#t      ;W#DG##,     ;WW; ##,:K#i E#t E#t L#LE#t   t##L   *
 *      j###DW##,    f#E:      t#E   E#t  E#t       f#E:   E#KDDDD###iE#t     j###DW##,    j#E.  ##f#W,  E#t E#tf#E:E#t .D#W;    *
 *     G##i,,G##,     ,WW;     t#E   E#t  E#t        ,WW;  E#f,t#Wi,,,E#t    G##i,,G##,  .D#L    ###K:   E#t E###f  E#tiW#G.     *
 *   :K#K:   L##,      .D#;    t#E   f#t  f#t         .D#; E#t  ;#W:  E#t  :K#K:   L##, :K#t     ##D.    E#t E#K,   E#K##i       *
 *  ;##D.    L##,        tt     fE    ii   ii           tt DWi   ,KK: E#t ;##D.    L##, ...      #G      ..  EL     E##D.        *
 *  ,,,      .,,                 :                                    ,;. ,,,      .,,           j           :      E#t          *
 *                                                                                                                  L:           *
 *********************************************************************************************************************************
 *                                                                                                                               *
 *                AetheriaMUD additions and changes from the Star Wars Reality code                                              *
 *                copyright (c) 2025 /dev/null Industries - StygianRenegade                                                      *
 *                                                                                                                               *
 *                Star Wars Reality Code Additions and changes from the Smaug Code copyright (c) 1997                            *
 *                by Sean Cooper                                                                                                 *
 *                                                                                                                               *
 *           Starwars and Starwars Names copyright(c) Disney Enterprises, Inc.... All hail the mouse overlord!                   *
 *                                                                                                                               *
 *********************************************************************************************************************************
 *                                                                                                                               *
 *                                             SWR 1.0 copyright (c) 1997, 1998 was created by Sean Cooper                       *
 *                                                                                                                               *
 *                           Based on a concept and ideas from the original SWR immortals:                                       *
 *                Himself (Durga), Mark Matt (Merth), Jp Coldarone (Exar), Greg Baily (Thrawn),                                  *
 *                Ackbar, Satin, Streen and Bib as well as much input from our other builders and players.                       *
 *                                                                                                                               *
 *                           Original SMAUG 1.4a written by Thoric (Derek Snider) with:                                          *
 *                Altrag, Blodkai, Haus, Narn, Scryn, Swordbearer, Tricops, Gorog, Rennard,                                      *
 *                Grishnakh, Fireblade, and Nivek.                                                                               *
 *                                                                                                                               *
 *                           Original MERC 2.1 code by: Hatchet, Furey, and Kahn.                                                *
 *                                                                                                                               *
 *                           Original DikuMUD code by: Hans Staerfeldt, Katja Nyboe, Tom Madsen,                                 *
 *                Michael Seifert, and Sebastian Hammer.                                                                         *
 *                                                                                                                               *
 *********************************************************************************************************************************/

#pragma once

#include "mud_types.hpp"
#include "mud_macros.hpp"
#include <ctime>
#include <string>
/*
 * Site ban structure.
 */
struct ban_data
{
   BAN_DATA *next;
   BAN_DATA *prev;
   char *name;
   int level;
   char *ban_time;
};

/*
 * Time and weather stuff.
 */
struct time_info_data
{
   int hour;
   int day;
   int month;
   int year;
};

struct hour_min_sec
{
   int hour;
   int min;
   int sec;
   int manual;
};

struct weather_data
{
   int mmhg;
   int change;
   int sky;
   int sunlight;
};

/*
 * Structure used to build wizlist
 */
struct wizent
{
   WIZENT *next;
   WIZENT *last;
   char *name;
   short level;
};

/*
 * Descriptor (channel) structure.
 */
struct descriptor_data
{
   DESCRIPTOR_DATA *next;
   DESCRIPTOR_DATA *prev;
   DESCRIPTOR_DATA *snoop_by;
   CHAR_DATA *character;
   CHAR_DATA *original;
   struct mccp_data *mccp; /* Mud Client Compression Protocol */
   bool can_compress;
   char *host;
   char *hostip;
   int port;
   int descriptor;
   short connected;
   short idle;
   short lines;
   short scrlen;
   bool fcommand;
   char inbuf[MAX_INBUF_SIZE];
   char incomm[MAX_INPUT_LENGTH];
   char inlast[MAX_INPUT_LENGTH];
   int repeat;
   char *outbuf;
   unsigned long outsize;
   int outtop;
   char *pagebuf;
   unsigned long pagesize;
   int pagetop;
   char *pagepoint;
   char pagecmd;
   char pagecolor;
   int newstate;
   unsigned char prevcolor;
   int ifd;
   pid_t ipid;
};

/*
 * Attribute bonus structures.
 */
struct str_app_type
{
   short tohit;
   short todam;
   short carry;
   short wield;
};

struct int_app_type
{
   short learn;
};

struct wis_app_type
{
   short practice;
};

struct dex_app_type
{
   short defensive;
};

struct con_app_type
{
   short hitp;
   short shock;
};

struct cha_app_type
{
   short charm;
};

struct lck_app_type
{
   short luck;
};

struct frc_app_type
{
   short force;
};

/*
 * Help table types.
 */
struct help_data
{
   HELP_DATA *next;
   HELP_DATA *prev;
   short level;
   char *keyword;
   char *text;
};

/*
 * Shop types.
 */
struct shop_data
{
   SHOP_DATA *next;
   SHOP_DATA *prev;
   int keeper;
   short buy_type[MAX_TRADE];
   short profit_buy;
   short profit_sell;
   short open_hour;
   short close_hour;
};

struct repairshop_data
{
   REPAIR_DATA *next;
   REPAIR_DATA *prev;
   int keeper;
   short fix_type[MAX_FIX];
   short profit_fix;
   short shop_type;
   short open_hour;
   short close_hour;
};

/* Mob program structures */
struct act_prog_data
{
   struct act_prog_data *next;
   void *vo;
};

struct mob_prog_act_list
{
   MPROG_ACT_LIST *next;
   char *buf;
   CHAR_DATA *ch;
   OBJ_DATA *obj;
   void *vo;
};

struct mob_prog_data
{
   MPROG_DATA *next;
   int type;
   bool triggered;
   int resetdelay;
   char *arglist;
   char *comlist;
   bool fileprog;
};

struct mpsleep_data
{
   MPSLEEP_DATA *next;
   MPSLEEP_DATA *prev;
   int timer;
   mp_types type;
   ROOM_INDEX_DATA *room;
   int ignorelevel;
   int iflevel;
   bool ifstate[MAX_IFS][DO_ELSE];
   char *com_list;
   CHAR_DATA *mob;
   CHAR_DATA *actor;
   OBJ_DATA *obj;
   void *vo;
   bool single_step;
};

/* race dedicated stuff */
struct race_type
{
   const char *race_name;
   int affected;
   short str_plus;
   short dex_plus;
   short wis_plus;
   short int_plus;
   short con_plus;
   short cha_plus;
   short lck_plus;
   short frc_plus;
   short hit;
   short mana;
   short resist;
   short suscept;
   int class_restriction;
   int language;
};

struct planet_data
{
   PLANET_DATA *next;
   PLANET_DATA *prev;
   PLANET_DATA *next_in_system;
   PLANET_DATA *prev_in_system;
   AREA_DATA *next_in_area;
   AREA_DATA *prev_in_area;
   GUARD_DATA *first_guard;
   AREA_DATA *first_area;
   AREA_DATA *last_area;
   GUARD_DATA *last_guard;
   SPACE_DATA *starsystem;
   AREA_DATA *area;
   char *name;
   char *filename;
   CLAN_DATA *governed_by;
   int population;
   float pop_support;
   int sector;
   int x, y, z;
   int size;
   bool flags;
   int base_value;
   int citysize;
   int wilderness;
   int wildlife;
   int farmland;
   int barracks;
   int controls;
};

struct cargo_data
{
   int cargo0;
   int cargo1;
   int cargo2;
   int cargo3;
   int cargo4;
   int cargo5;
   int cargo6;
   int cargo7;
   int cargo8;
   int cargo9;
   int orgcargo0;
   int orgcargo1;
   int orgcargo2;
   int orgcargo3;
   int orgcargo4;
   int orgcargo5;
   int orgcargo6;
   int orgcargo7;
   int orgcargo8;
   int orgcargo9;
   int price0;
   int price1;
   int price2;
   int price3;
   int price4;
   int price5;
   int price6;
   int price7;
   int price8;
   int price9;
   bool smug;
};

struct space_data
{
   SPACE_DATA *next;
   SPACE_DATA *prev;
   SHIP_DATA *first_ship;
   SHIP_DATA *last_ship;
   MISSILE_DATA *first_missile;
   MISSILE_DATA *last_missile;
   PLANET_DATA *first_planet;
   PLANET_DATA *last_planet;
   char *filename;
   char *name;
   char *star1;
   char *star2;
   char *planet1;
   char *planet2;
   char *planet3;
   char *location1a;
   char *location2a;
   char *location3a;
   char *location1b;
   char *location2b;
   char *location3b;
   char *location1c;
   char *location2c;
   char *location3c;
   int xpos;
   int ypos;
   int zpos;
   int s1x;
   int s1y;
   int s1z;
   int s2x;
   int s2y;
   int s2z;
   int doc1a;
   int doc2a;
   int doc3a;
   int doc1b;
   int doc2b;
   int doc3b;
   int doc1c;
   int doc2c;
   int doc3c;
   bool seca;
   bool secb;
   bool secc;
   int p1x;
   bool trainer;
   int p1y;
   int p1z;
   int p2x;
   int p2y;
   int p2z;
   int p3x;
   int p3y;
   int p3z;
   int gravitys1;
   int gravitys2;
   int gravityp1;
   int gravityp2;
   int gravityp3;
   int p1_low;
   int p1_high;
   int p2_low;
   int p2_high;
   int p3_low;
   int p3_high;
   int crash;
};

struct bounty_data
{
   BOUNTY_DATA *next;
   BOUNTY_DATA *prev;
   char *target;
   long int amount;
};

struct blackmarket_data
{
   BMARKET_DATA *next;
   BMARKET_DATA *prev;
   char *filename;
   int quantity;
};

struct guard_data
{
   GUARD_DATA *next;
   GUARD_DATA *prev;
   GUARD_DATA *next_on_planet;
   GUARD_DATA *prev_on_planet;
   CHAR_DATA *mob;
   ROOM_INDEX_DATA *reset_loc;
   PLANET_DATA *planet;
};

struct senate_data
{
   SENATE_DATA *next;
   SENATE_DATA *prev;
   char *name;
};

struct clan_data
{
   CLAN_DATA *next;
   CLAN_DATA *prev;
   CLAN_DATA *next_subclan;
   CLAN_DATA *prev_subclan;
   CLAN_DATA *first_subclan;
   CLAN_DATA *last_subclan;
   CLAN_DATA *mainclan;
   char *acro;
   char *filename;
   char *shortname;
   char *name;
   char *description;
   char *leader;
   char *number1;
   char *number2;
   int pkills;
   int pdeaths;
   int mkills;
   int mdeaths;
   short clan_type;
   char *atwar;
   short members;
   int board;
   int storeroom;
   int guard1;
   int guard2;
   int patrol1;
   int patrol2;
   int trooper1;
   int trooper2;
   long int funds;
   int spacecraft;
   int troops;
   int vehicles;
   int jail;
   char *tmpstr;
};

struct ship_prototype_data
{
   SHIP_PROTOTYPE *next;
   SHIP_PROTOTYPE *prev;
   char *filename;
   char *name;
   char *description;
   short sclass;
   short model;
   short hyperspeed;
   short realspeed;
   short maxbombs;
   short maxmissiles;
   short maxtorpedos;
   short maxrockets;
   int max_modules;
   short lasers;
   CLAN_DATA *clan;
   short tractorbeam;
   short manuever;
   int weight;
   int maxenergy;
   int maxshield;
   int maxhull;
   short maxchaff;
   short maxmods;
};

struct turret_data
{
   TURRET_DATA *next;
   TURRET_DATA *prev;
   ROOM_INDEX_DATA *room;
   SHIP_DATA *target;
   short laserstate;
};

struct hanger_data
{
   HANGER_DATA *next;
   HANGER_DATA *prev;
   ROOM_INDEX_DATA *room;
   bool bayopen;
   int type;
};

struct module_data
{
   MODULE_DATA *next;
   MODULE_DATA *prev;
   int affect;
   int ammount;
};

struct ship_data
{
   SHIP_DATA *next;
   SHIP_DATA *prev;
   SHIP_DATA *next_in_starsystem;
   SHIP_DATA *prev_in_starsystem;
   SHIP_DATA *next_in_room;
   SHIP_DATA *prev_in_room;
   ROOM_INDEX_DATA *in_room;
   SPACE_DATA *starsystem;
   SHIP_DATA *inship;
   char *filename;
   char *name;
   char *protoname;
   char *clanowner;
   char *home;
   char *description;
   char *owner;
   char *pilot;
   char *copilot;
   char *dest;
   char *pbeacon;
   short type;
   short sclass;
   short comm;
   int cost;
   short sensor;
   short astro_array;
   short hyperspeed;
   int hyperdistance;
   short realspeed;
   short currspeed;
   short shipstate;
   short hyperstate;
   bool juking;
   bool rolling;
   short primaryState;
   short secondaryState;
   short primaryType;
   short secondaryType;
   bool primaryLinked;
   bool secondaryLinked;
   bool warheadLinked;
   short primaryCount;
   short secondaryCount;
   short statet1;
   short statet2;
   short statet3;
   short statet4;
   short statet5;
   short statet6;
   short statet7;
   short statet8;
   short statet9;
   short statet10;
   short missiletype;
   short missilestate;
   short torpedostate;
   short rocketstate;
   short bombs;
   short maxbombs;
   short alarm;
   short missiles;
   short maxmissiles;
   short torpedos;
   short maxtorpedos;
   short rockets;
   short maxrockets;
   short maxmod;
   short tractorbeam;
   short manuever;
   bool bayopen;
   bool hatchopen;
   bool autorecharge;
   bool autotrack;
   bool autospeed;
   float vx, vy, vz;
   float hx, hy, hz;
   float jx, jy, jz;
   int maxenergy;
   int energy;
   int shield;
   int maxshield;
   int hull;
   int maxhull;
   int cockpit;
   int turret1;
   int turret2;
   int turret3;
   int turret4;
   int turret5;
   int turret6;
   int turret7;
   int turret8;
   int turret9;
   int turret10;
   int location;
   int lastdoc;
   int shipyard;
   int entrance;
   int engineroom;
   int firstroom;
   int lastroom;
   int navseat;
   int pilotseat;
   int coseat;
   int gunseat;
   long collision;
   SHIP_DATA *target0;
   SHIP_DATA *target1;
   SHIP_DATA *target2;
   SHIP_DATA *target3;
   SHIP_DATA *target4;
   SHIP_DATA *target5;
   SHIP_DATA *target6;
   SHIP_DATA *target7;
   SHIP_DATA *target8;
   SHIP_DATA *target9;
   SHIP_DATA *target10;
   SPACE_DATA *currjump;
   short chaff;
   short maxchaff;
   short chaff_released;
   bool autopilot;
   int channel;
   int password;
   int flags;
   MODULE_DATA *first_module;
   MODULE_DATA *last_module;
   short maxmods;
   TURRET_DATA *first_turret;
   TURRET_DATA *last_turret;
   int hanger1;
   int hanger2;
   int hanger3;
   int hanger4;
   int exlocation;
   int sim_vnum;
   int max_modules;
   int baycode;
   int hibombstr;
   int lowbombstr;
   SHIP_DATA *tractored_by;
   SHIP_DATA *tractoring;
};

struct missile_data
{
   MISSILE_DATA *next;
   MISSILE_DATA *prev;
   MISSILE_DATA *next_in_starsystem;
   MISSILE_DATA *prev_in_starsystem;
   SPACE_DATA *starsystem;
   SHIP_DATA *target;
   SHIP_DATA *fired_from;
   char *fired_by;
   short missiletype;
   short age;
   int speed;
   int mx, my, mz;
};

struct tourney_data
{
   int open;
   int low_level;
   int hi_level;
};

struct note_data
{
   NOTE_DATA *next;
   NOTE_DATA *prev;
   char *sender;
   char *date;
   char *to_list;
   char *subject;
   int voting;
   char *yesvotes;
   char *novotes;
   char *abstentions;
   char *text;
};

struct board_data
{
   BOARD_DATA *next;
   BOARD_DATA *prev;
   NOTE_DATA *first_note;
   NOTE_DATA *last_note;
   char *note_file;
   char *read_group;
   char *post_group;
   char *extra_readers;
   char *extra_removers;
   int board_obj;
   short num_posts;
   short min_read_level;
   short min_post_level;
   short min_remove_level;
   short max_posts;
   int type;
};

struct affect_data
{
   AFFECT_DATA *next;
   AFFECT_DATA *prev;
   short type;
   int duration;
   short location;
   int modifier;
   int bitvector;
};

struct smaug_affect
{
   SMAUG_AFF *next;
   SMAUG_AFF *prev;
   char *duration;
   short location;
   char *modifier;
   int bitvector;
};

struct mob_index_data
{
   MOB_INDEX_DATA *next;
   MOB_INDEX_DATA *next_sort;
   SPEC_FUN *spec_fun;
   SPEC_FUN *spec_2;
   SHOP_DATA *pShop;
   REPAIR_DATA *rShop;
   MPROG_DATA *mudprogs;
   int progtypes;
   char *player_name;
   char *short_descr;
   char *long_descr;
   char *description;
   char *spec_funname;
   char *spec_funname2;
   int vnum;
   short count;
   short killed;
   short sex;
   short level;
   int act;
   int affected_by;
   short alignment;
   short mobthac0;
   short ac;
   short hitnodice;
   short hitsizedice;
   short hitplus;
   short damnodice;
   short damsizedice;
   short damplus;
   short numattacks;
   int gold;
   int exp;
   int xflags;
   int resistant;
   int immune;
   int susceptible;
   int attacks;
   int defenses;
   int speaks;
   int speaking;
   short position;
   short defposition;
   short height;
   short weight;
   short race;
   short hitroll;
   short damroll;
   short perm_str;
   short perm_int;
   short perm_wis;
   short perm_dex;
   short perm_con;
   short perm_cha;
   short perm_lck;
   short perm_frc;
   short saving_poison_death;
   short saving_wand;
   short saving_para_petri;
   short saving_breath;
   short saving_spell_staff;
   int vip_flags;
};

struct obj_index_data
{
   OBJ_INDEX_DATA *next;
   OBJ_INDEX_DATA *next_sort;
   EXTRA_DESCR_DATA *first_extradesc;
   EXTRA_DESCR_DATA *last_extradesc;
   AFFECT_DATA *first_affect;
   AFFECT_DATA *last_affect;
   MPROG_DATA *mudprogs;
   int progtypes;
   char *name;
   char *short_descr;
   char *description;
   char *action_desc;
   int vnum;
   short level;
   short item_type;
   int extra_flags;
   int magic_flags;
   int wear_flags;
   short count;
   short weight;
   int cost;
   int value[6];
   int serial;
   short layers;
   int rent;
};

struct obj_data
{
   OBJ_DATA *next;
   OBJ_DATA *prev;
   OBJ_DATA *next_content;
   OBJ_DATA *prev_content;
   OBJ_DATA *first_content;
   OBJ_DATA *last_content;
   OBJ_DATA *in_obj;
   CHAR_DATA *carried_by;
   EXTRA_DESCR_DATA *first_extradesc;
   EXTRA_DESCR_DATA *last_extradesc;
   AFFECT_DATA *first_affect;
   AFFECT_DATA *last_affect;
   OBJ_INDEX_DATA *pIndexData;
   ROOM_INDEX_DATA *in_room;
   char *armed_by;
   char *name;
   char *short_descr;
   char *description;
   char *action_desc;
   short item_type;
   short mpscriptpos;
   int extra_flags;
   int magic_flags;
   int wear_flags;
   int blaster_setting;
   MPROG_ACT_LIST *mpact;
   int mpactnum;
   short wear_loc;
   short weight;
   char *killer;
   int cost;
   short level;
   short timer;
   int value[6];
   short count;
   int serial;
   int room_vnum;
};

struct exit_data
{
   EXIT_DATA *prev;
   EXIT_DATA *next;
   EXIT_DATA *rexit;
   ROOM_INDEX_DATA *to_room;
   char *keyword;
   char *description;
   int vnum;
   int rvnum;
   int exit_info;
   int key;
   short vdir;
   short distance;
};

struct reset_data
{
   RESET_DATA *next;
   RESET_DATA *prev;
   RESET_DATA *first_reset;
   RESET_DATA *last_reset;
   RESET_DATA *next_reset;
   RESET_DATA *prev_reset;
   char command;
   int extra;
   int arg1;
   int arg2;
   int arg3;
   bool sreset;
};

struct area_data
{
   AREA_DATA *next;
   AREA_DATA *prev;
   AREA_DATA *next_sort;
   AREA_DATA *prev_sort;
   AREA_DATA *next_sort_name;
   AREA_DATA *prev_sort_name;
   ROOM_INDEX_DATA *first_room;
   ROOM_INDEX_DATA *last_room;
   PLANET_DATA *planet;
   AREA_DATA *next_on_planet;
   AREA_DATA *prev_on_planet;
   char *name;
   char *filename;
   int flags;
   short version;
   short status;
   short age;
   short nplayer;
   short reset_frequency;
   int low_r_vnum;
   int hi_r_vnum;
   int low_o_vnum;
   int hi_o_vnum;
   int low_m_vnum;
   int hi_m_vnum;
   int low_soft_range;
   int hi_soft_range;
   int low_hard_range;
   int hi_hard_range;
   char *author;
   char *resetmsg;
   RESET_DATA *last_mob_reset;
   RESET_DATA *last_obj_reset;
   short max_players;
   int mkills;
   int mdeaths;
   int pkills;
   int pdeaths;
   int gold_looted;
   int illegal_pk;
   int high_economy;
   int low_economy;
};

struct system_data
{
   int maxplayers;
   int alltimemax;
   char *time_of_max;
   bool NO_NAME_RESOLVING;
   bool DENY_NEW_PLAYERS;
   bool WAIT_FOR_AUTH;
   short newbie_purge;
   short regular_purge;
   bool CLEANPFILES;
   short read_all_mail;
   short read_mail_free;
   short write_mail_free;
   short take_others_mail;
   short muse_level;
   short think_level;
   short build_level;
   short log_level;
   short level_modify_proto;
   short level_override_private;
   short level_mset_player;
   short stun_plr_vs_plr;
   short stun_regular;
   short dam_plr_vs_plr;
   short dam_plr_vs_mob;
   short dam_mob_vs_plr;
   short dam_mob_vs_mob;
   short level_getobjnotake;
   short level_forcepc;
   short max_sn;
   char *guild_overseer;
   char *guild_advisor;
   int save_flags;
   short save_frequency;
   void *dlHandle;
};

struct room_index_data
{
   ROOM_INDEX_DATA *next;
   ROOM_INDEX_DATA *next_sort;
   CHAR_DATA *first_person;
   CHAR_DATA *last_person;
   OBJ_DATA *first_content;
   OBJ_DATA *last_content;
   EXTRA_DESCR_DATA *first_extradesc;
   EXTRA_DESCR_DATA *last_extradesc;
   AREA_DATA *area;
   EXIT_DATA *first_exit;
   EXIT_DATA *last_exit;
   RESET_DATA *first_reset;
   RESET_DATA *last_reset;
   RESET_DATA *last_mob_reset;
   RESET_DATA *last_obj_reset;
   ROOM_INDEX_DATA *next_aroom;
   ROOM_INDEX_DATA *prev_aroom;
   ROOM_INDEX_DATA *next_in_area;
   ROOM_INDEX_DATA *prev_in_area;
   ROOM_INDEX_DATA *next_in_ship;
   ROOM_INDEX_DATA *prev_in_ship;
   char *name;
   int exvnum;
   SHIP_DATA *first_ship;
   SHIP_DATA *last_ship;
   char *description;
   int vnum;
   int room_flags;
   int room_flags2;
   MPROG_ACT_LIST *mpact;
   int mpactnum;
   MPROG_DATA *mudprogs;
   short mpscriptpos;
   int progtypes;
   short light;
   short sector_type;
   int tele_vnum;
   short tele_delay;
   short tunnel;
};

struct teleport_data
{
   TELEPORT_DATA *next;
   TELEPORT_DATA *prev;
   ROOM_INDEX_DATA *room;
   short timer;
};

struct skill_type
{
   char *name;
   SPELL_FUN *spell_fun;
   char *spell_fun_name;
   DO_FUN *skill_fun;
   char *skill_fun_name;
   short target;
   short minimum_position;
   short slot;
   short min_mana;
   short beats;
   char *noun_damage;
   char *msg_off;
   short guild;
   short min_level;
   short type;
   int flags;
   char *hit_char;
   char *hit_vict;
   char *hit_room;
   char *miss_char;
   char *miss_vict;
   char *miss_room;
   char *die_char;
   char *die_vict;
   char *die_room;
   char *imm_char;
   char *imm_vict;
   char *imm_room;
   char *dice;
   int value;
   char saves;
   char difficulty;
   SMAUG_AFF *first_affect;
   SMAUG_AFF *last_affect;
   char *components;
   char *teachers;
   char participants;
   struct timerset userec;
   int alignment;
};

struct auction_data
{
   OBJ_DATA *item;
   CHAR_DATA *seller;
   CHAR_DATA *buyer;
   int bet;
   short going;
   short pulse;
   int starting;
};

struct cmd_type
{
   CMDTYPE *next;
   char *name;
   DO_FUN *do_fun;
   char *fun_name;
   short position;
   short level;
   short log;
   int flags;
   struct timerset userec;
};

struct social_type
{
   SOCIALTYPE *next;
   char *name;
   char *char_no_arg;
   char *others_no_arg;
   char *char_found;
   char *others_found;
   char *vict_found;
   char *char_auto;
   char *others_auto;
};

struct specfun_list
{
   SPEC_LIST *next;
   SPEC_LIST *prev;
   char *name;
};

struct liq_type
{
   const char *liq_name;
   const char *liq_color;
   short liq_affect[4];
};

struct extra_descr_data
{
   EXTRA_DESCR_DATA *next;
   EXTRA_DESCR_DATA *prev;
   char *keyword;
   char *description;
};

struct timerset
{
   int num_uses;
   struct timeval total_time;
   struct timeval min_time;
   struct timeval max_time;
};

struct rel_data
{
   void *Actor;
   void *Subject;
   REL_DATA *next;
   REL_DATA *prev;
   relation_type Type;
};

struct force_skills_struct
{
   int type;
   int index;
   char *name;
   char *room_effect[5];
   char *victim_effect[5];
   char *ch_effect[5];
   int cost;
   int control;
   int alter;
   int sense;
   char *code;
   int status;
   int wait_state;
   int disabled;
   int notskill;
   int mastertrain;
   DO_FUN *do_fun;
   FORCE_SKILL *next;
   FORCE_SKILL *prev;
};

struct force_help_struct
{
   char *name;
   int status;
   int type;
   char *desc;
   int skill;
   FORCE_HELP *next;
   FORCE_HELP *prev;
};

struct who_data
{
   WHO_DATA *prev;
   WHO_DATA *next;
   char *text;
   int type;
};

struct editor_data
{
   short numlines;
   short on_line;
   short size;
   char *line[49];
};

struct bug_data
{
   char *name;
   BUG_DATA *next_in_bug;
   BUG_DATA *prev_in_bug;
};

struct contract_data
{
   char *target;
   int amount;
   CONTRACT_DATA *next_in_contract;
   CONTRACT_DATA *prev_in_contract;
};

struct fellow_data
{
   char *victim;
   char *knownas;
   FELLOW_DATA *next;
   FELLOW_DATA *prev;
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
