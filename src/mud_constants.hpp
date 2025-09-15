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

/*
 * These are skill_lookup return values for basic skills and spells.
 */
extern short gsn_smallspace;
extern short gsn_mediumspace;
extern short gsn_largespace;
extern short gsn_weaponsystems;
extern short gsn_navigation;
extern short gsn_shipsystems;
extern short gsn_tractorbeams;
extern short gsn_spacecombat;
extern short gsn_spacecombat2;
extern short gsn_spacecombat3;
extern short gsn_bomb;

extern short gsn_shipdesign;

/* Technician skills */
extern short gsn_makemodule;
extern short gsn_installmodule;
extern short gsn_showmodules;
extern short gsn_shipmaintenance;
extern short gsn_scanbugs;
extern short gsn_removebug;
extern short gsn_removemodule;

/* These are bh skills */
extern short gsn_ambush;
extern short gsn_bind;
extern short gsn_gag;

extern short gsn_battle_command;
extern short gsn_reinforcements;
extern short gsn_postguard;

extern short gsn_addpatrol;
extern short gsn_eliteguard;
extern short gsn_specialforces;
extern short gsn_jail;
extern short gsn_smalltalk;
extern short gsn_propeganda;
extern short gsn_bribe;
extern short gsn_seduce;
extern short gsn_masspropeganda;
extern short gsn_gather_intelligence;

/* hunter assassin gsn ints */
extern short gsn_plantbug;
extern short gsn_showbugs;
extern short gsn_silent;
extern short gsn_retreat;

/* The gsn ints for the slicers */
extern short gsn_spy;
extern short gsn_makecommsystem;
extern short gsn_sabotage;
extern short gsn_commsystem;
extern short gsn_codecrack;
extern short gsn_slicebank;
extern short gsn_inquire;
extern short gsn_makedatapad;
extern short gsn_disable;
extern short gsn_assignpilot;
extern short gsn_checkprints;

extern short gsn_torture;
extern short gsn_snipe;
extern short gsn_throw;
extern short gsn_deception;
extern short gsn_disguise;
extern short gsn_mine;
extern short gsn_first_aid;

extern short gsn_beg;
extern short gsn_makeblade;
extern short gsn_makebug;
extern short gsn_makebeacon;
extern short gsn_makepike;
extern short gsn_makejewelry;
extern short gsn_makeblaster;
extern short gsn_makelight;
extern short gsn_makecomlink;
extern short gsn_makegrenade;
extern short gsn_makeshipbomb;
extern short gsn_makelandmine;
extern short gsn_makearmor;
extern short gsn_makeshield;
extern short gsn_makecontainer;
extern short gsn_gemcutting;
extern short gsn_makelightsaber;
extern short gsn_makeduallightsaber;
extern short gsn_repair;
extern short gsn_shiprepair;
extern short gsn_spice_refining;

extern short gsn_detrap;
extern short gsn_backstab;
extern short gsn_dualstab;
extern short gsn_bargain;
extern short gsn_circle;
extern short gsn_dodge;
extern short gsn_hide;
extern short gsn_concealment;
extern short gsn_peek;
extern short gsn_pick_lock;
extern short gsn_scan;
extern short gsn_sneak;
extern short gsn_steal;
extern short gsn_gouge;
extern short gsn_track;
extern short gsn_search;
extern short gsn_dig;
extern short gsn_mount;
extern short gsn_bashdoor;
extern short gsn_berserk;
extern short gsn_hitall;
extern short gsn_pickshiplock;
extern short gsn_hijack;

extern short gsn_disarm;
extern short gsn_enhanced_damage;
extern short gsn_kick;
extern short gsn_parry;
extern short gsn_rescue;
extern short gsn_second_attack;
extern short gsn_third_attack;
extern short gsn_dual_wield;
extern short gsn_reflect;

extern short gsn_aid;
extern short gsn_plantbeacon;
extern short gsn_showbeacons;
extern short gsn_checkbeacons;
extern short gsn_nullifybeacons;
extern short gsn_makebinders;
extern short gsn_launchers;
extern short gsn_makemissile;
extern short gsn_makegoggles;
extern short gsn_truesight;
extern short gsn_barrelroll;
extern short gsn_juke;

/* used to do specific lookups */
extern short gsn_first_spell;
extern short gsn_first_skill;
extern short gsn_first_weapon;
extern short gsn_first_tongue;
extern short gsn_top_sn;

/* spells */
extern short gsn_blindness;
extern short gsn_charm_person;
extern short gsn_aqua_breath;
extern short gsn_invis;
extern short gsn_mass_invis;
extern short gsn_poison;
extern short gsn_sleep;
extern short gsn_possess;
extern short gsn_fireball;       /* for fireshield  */
extern short gsn_lightning_bolt; /* for shockshield */

/* newer attack skills */
extern short gsn_punch;
extern short gsn_bash;
extern short gsn_stun;

extern short gsn_poison_weapon;
extern short gsn_climb;

extern short gsn_blasters;
extern short gsn_force_pikes;
extern short gsn_bowcasters;
extern short gsn_lightsabers;
extern short gsn_vibro_blades;
extern short gsn_flexible_arms;
extern short gsn_talonous_arms;
extern short gsn_bludgeons;

extern short gsn_grip;

/* languages */
extern short gsn_basic;
extern short gsn_wookiee;
extern short gsn_twilek;
extern short gsn_rodian;
extern short gsn_hutt;
extern short gsn_mon_calamari;
extern short gsn_noghri;
extern short gsn_ewok;
extern short gsn_ithorian;
extern short gsn_gotal;
extern short gsn_devaronian;
extern short gsn_binary;
extern short gsn_firrerreo;
extern short gsn_gamorrean;
extern short gsn_togorian;
extern short gsn_shistavanen;
extern short gsn_jawa;
extern short gsn_kubaz;
extern short gsn_verpine;
extern short gsn_defel;
extern short gsn_trandoshan;
extern short gsn_hapan;
extern short gsn_quarren;
extern short gsn_sullustan;
extern short gsn_falleen;
extern short gsn_barabel;
extern short gsn_yevethan;
extern short gsn_gand;
extern short gsn_coynite;
extern short gsn_duinuogwuin;

/*
 * Global constants.
 */
extern time_t last_restore_all_time;
extern time_t boot_time; /* this should be moved down */
extern HOUR_MIN_SEC *set_boot_time;
extern struct tm *new_boot_time;
extern time_t new_boot_time_t;
extern bool mud_down;
extern FILE *fpArea;
extern char strArea[MAX_INPUT_LENGTH];

extern const struct str_app_type str_app[26];
extern const struct int_app_type int_app[26];
extern const struct wis_app_type wis_app[26];
extern const struct dex_app_type dex_app[30];
extern const struct con_app_type con_app[26];
extern const struct cha_app_type cha_app[26];
extern const struct lck_app_type lck_app[26];
extern const struct frc_app_type frc_app[26];
extern struct race_type race_table[MAX_RACE];
extern const struct liq_type liq_table[LIQ_MAX];
extern const char *const attack_table[13];
extern const char *const ability_name[MAX_ABILITY];
extern const char *const height_name[4];
extern const char *const build_name[6];
extern const char *const droid_name[8];

extern const char *const skill_tname[];
extern short const movement_loss[SECT_MAX];
extern const char *const dir_name[];
extern const char *const where_name[];
extern const short rev_dir[];
extern const int trap_door[];
extern const char *const r_flags[];
extern const char *const r_flags2[];
extern const char *const w_flags[];
extern const char *const o_flags[];
extern const char *const a_flags[];
extern const char *const o_types[];
extern const char *const a_types[];
extern const char *const cmd_flags[];
extern const char *const act_flags[];
extern const char *const planet_flags[];
extern const char *const mprog_flags[];
extern const char *const weapon_table[13];
extern const char *const spice_table[];
extern const char *const plr_flags[];
extern const char *const pc_flags[];
extern const char *const trap_flags[];
extern const char *const ris_flags[];
extern const char *const trig_flags[];
extern const char *const part_flags[];
extern const char *const npc_race[];
extern const char *const defense_flags[];
extern const char *const attack_flags[];
extern const char *const area_flags[];
extern const char *const wear_locs[];
extern int const lang_array[];
extern const char *const lang_names[];
extern const char *const lang_names_save[];
extern const char *sector_name[SECT_MAX];

extern bool bootup;
extern char namefreq[MAX_STRING_LENGTH];
extern char bname[MAX_STRING_LENGTH];

/*
 * Global variables.
 */
extern MPSLEEP_DATA *first_mpwait;   /* Storing sleeping mud progs */
extern MPSLEEP_DATA *last_mpwait;    /* - */
extern MPSLEEP_DATA *current_mpwait; /* - */
extern int numobjsloaded;
extern int nummobsloaded;
extern int physicalobjects;
extern int num_descriptors;
extern struct system_data sysdata;
extern int top_sn;
extern int top_vroom;
extern int top_herb;

extern CMDTYPE *command_hash[126];

extern SKILLTYPE *skill_table[MAX_SKILL];
extern SOCIALTYPE *social_index[27];
extern CHAR_DATA *cur_char;
extern ROOM_INDEX_DATA *cur_room;
extern bool cur_char_died;
extern ch_ret global_retcode;
extern SKILLTYPE *herb_table[MAX_HERB];

extern int cur_obj;
extern int cur_obj_serial;
extern bool cur_obj_extracted;
extern obj_ret global_objcode;

extern HELP_DATA *first_help;
extern HELP_DATA *last_help;
extern SHOP_DATA *first_shop;
extern SHOP_DATA *last_shop;
extern REPAIR_DATA *first_repair;
extern REPAIR_DATA *last_repair;

extern BAN_DATA *first_ban;
extern BAN_DATA *last_ban;
extern CHAR_DATA *first_char;
extern CHAR_DATA *last_char;
extern DESCRIPTOR_DATA *first_descriptor;
extern DESCRIPTOR_DATA *last_descriptor;
extern BOARD_DATA *first_board;
extern BOARD_DATA *last_board;
extern OBJ_DATA *first_object;
extern OBJ_DATA *last_object;
extern CLAN_DATA *first_clan;
extern CLAN_DATA *last_clan;
extern GUARD_DATA *first_guard;
extern GUARD_DATA *last_guard;
extern SHIP_DATA *first_ship;
extern SHIP_DATA *last_ship;
extern SHIP_PROTOTYPE *first_ship_prototype;
extern SHIP_PROTOTYPE *last_ship_prototype;
extern SPACE_DATA *first_starsystem;
extern SPACE_DATA *last_starsystem;
extern PLANET_DATA *first_planet;
extern PLANET_DATA *last_planet;
extern SENATE_DATA *first_senator;
extern SENATE_DATA *last_senator;
extern BOUNTY_DATA *first_bounty;
extern BOUNTY_DATA *last_bounty;
extern BOUNTY_DATA *first_disintegration;
extern BOUNTY_DATA *last_disintegration;
extern AREA_DATA *first_area;
extern AREA_DATA *last_area;
extern AREA_DATA *first_build;
extern AREA_DATA *last_build;
extern AREA_DATA *first_asort;
extern AREA_DATA *last_asort;
extern AREA_DATA *first_bsort;
extern AREA_DATA *last_bsort;
extern AREA_DATA *first_area_name; /*alphanum. sort */
extern AREA_DATA *last_area_name;  /* Fireblade */
extern SPEC_LIST *first_specfun;
extern SPEC_LIST *last_specfun;

extern TELEPORT_DATA *first_teleport;
extern TELEPORT_DATA *last_teleport;
extern OBJ_DATA *extracted_obj_queue;
extern EXTRACT_CHAR_DATA *extracted_char_queue;
extern OBJ_DATA *save_equipment[MAX_WEAR][MAX_LAYERS];
extern CHAR_DATA *quitting_char;
extern CHAR_DATA *loading_char;
extern CHAR_DATA *saving_char;
extern OBJ_DATA *all_obj;

extern time_t current_time;
extern bool fLogAll;
extern bool fLogPC;
extern char log_buf[];
extern TIME_INFO_DATA time_info;
extern WEATHER_DATA weather_info;

extern AUCTION_DATA *auction;
extern struct act_prog_data *mob_act_list;

extern BMARKET_DATA *first_market_ship;
extern BMARKET_DATA *last_market_ship;

/*
 * mudprograms stuff
 */
extern CHAR_DATA *supermob;
extern OBJ_DATA *supermob_obj;
extern bool DONT_UPPER;

const bool TRUE = true;
const bool FALSE = false;
const short BERR = 255;

