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

/*
 * Basic return type aliases.
 */
typedef int ch_ret;
typedef int obj_ret;

/*
 * Forward declarations for all structure types.
 * This allows pointers to these types to be used in any struct
 * without needing the full definition yet.
 */
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
typedef struct member_data MEMBER_DATA;
typedef struct member_list MEMBER_LIST;
typedef struct membersort_data MS_DATA;
typedef struct specfun_list SPEC_LIST;
typedef struct force_skills_struct FORCE_SKILL;
typedef struct force_help_struct FORCE_HELP;
typedef struct rel_data REL_DATA;
typedef struct tourney_data TOURNEY_DATA;
typedef struct timerset TIMERSET;

/*
 * Enumerations
 */
typedef enum
{
   LOG_NORMAL,
   LOG_ALWAYS,
   LOG_NEVER,
   LOG_BUILD,
   LOG_HIGH,
   LOG_COMM,
   LOG_ALL
} log_types;

typedef enum
{
   rNONE,
   rCHAR_DIED,
   rVICT_DIED,
   rBOTH_DIED,
   rCHAR_QUIT,
   rVICT_QUIT,
   rBOTH_QUIT,
   rSPELL_FAILED,
   rOBJ_SCRAPPED,
   rOBJ_EATEN,
   rOBJ_EXPIRED,
   rOBJ_TIMER,
   rOBJ_SACCED,
   rOBJ_QUAFFED,
   rOBJ_USED,
   rOBJ_EXTRACTED,
   rOBJ_DRUNK,
   rCHAR_IMMUNE,
   rVICT_IMMUNE,
   rCHAR_AND_OBJ_EXTRACTED = 128,
   rERROR = 255
} ret_types;

typedef enum
{
   FORCE_INROOM,
   FORCE_ANYWHERE
} force_locations;

typedef enum
{
   FORCE_SKILL_REFRESH,
   FORCE_SKILL_FINFO,
   FORCE_SKILL_STUDENT,
   FORCE_SKILL_MASTER,
   FORCE_SKILL_IDENTIFY,
   FORCE_SKILL_PROMOTE,
   FORCE_SKILL_INSTRUCT,
   FORCE_SKILL_HEAL,
   FORCE_SKILL_PROTECT,
   FORCE_SKILL_SHIELD,
   FORCE_SKILL_WHIRLWIND,
   FORCE_SKILL_STRIKE,
   FORCE_SKILL_SQUEEZE,
   FORCE_SKILL_FORCE_LIGHTNING,
   FORCE_SKILL_DISGUISE,
   FORCE_SKILL_MAKELIGHTSABER,
   FORCE_SKILL_PARRY,
   FORCE_SKILL_FINISH,
   FORCE_SKILL_FHELP,
   FORCE_SKILL_DUALLIGHTSABER,
   FORCE_SKILL_REFLECT,
   FORCE_SKILL_CONVERT,
   FORCE_SKILL_MAKEDUALSABER,
   FORCE_SKILL_AWARENESS
} force_skills_type;

typedef enum
{
   FORCE_NONCOMBAT,
   FORCE_COMBAT,
   FORCE_NORESTRICT
} force_skill_types;

typedef enum
{
   FORCE_NONE,
   FORCE_APPRENTICE,
   FORCE_KNIGHT,
   FORCE_MASTER
} force_level_type;

typedef enum
{
   FORCE_GENERAL,
   FORCE_JEDI,
   FORCE_SITH
} force_skills_class;

typedef enum
{
   relMSET_ON,
   relOSET_ON
} relation_type;

typedef enum
{
   SUN_DARK,
   SUN_RISE,
   SUN_LIGHT,
   SUN_SET
} sun_positions;

typedef enum
{
   SKY_CLOUDLESS,
   SKY_CLOUDY,
   SKY_RAINING,
   SKY_LIGHTNING
} sky_conditions;

typedef enum
{
   CON_GET_NAME = -99,
   CON_GET_OLD_PASSWORD,
   CON_CONFIRM_NEW_NAME,
   CON_GET_NEW_PASSWORD,
   CON_CONFIRM_NEW_PASSWORD,
   CON_GET_NEW_SEX,
   CON_READ_MOTD,
   CON_GET_NEW_RACE,
   CON_GET_EMULATION,
   CON_GET_WANT_RIPANSI,
   CON_TITLE,
   CON_PRESS_ENTER,
   CON_WAIT_1,
   CON_WAIT_2,
   CON_WAIT_3,
   CON_ACCEPTED,
   CON_GET_PKILL,
   CON_READ_IMOTD,
   CON_GET_NEW_EMAIL,
   CON_GET_MSP,
   CON_GET_NEW_CLASS,
   CON_GET_NEW_SECOND,
   CON_ROLL_STATS,
   CON_STATS_OK,
   CON_GET_PUEBLO,
   CON_GET_HEIGHT,
   CON_GET_BUILD,
   CON_GET_DROID,
   CON_COPYOVER_RECOVER,
   CON_PLAYING = 0,
   CON_EDITING
} connection_types;

typedef enum
{
   SUB_NONE,
   SUB_PAUSE,
   SUB_PERSONAL_DESC,
   SUB_OBJ_SHORT,
   SUB_OBJ_LONG,
   SUB_OBJ_EXTRA,
   SUB_MOB_LONG,
   SUB_MOB_DESC,
   SUB_ROOM_DESC,
   SUB_ROOM_EXTRA,
   SUB_ROOM_EXIT_DESC,
   SUB_WRITING_NOTE,
   SUB_MPROG_EDIT,
   SUB_HELP_EDIT,
   SUB_WRITING_MAP,
   SUB_PERSONAL_BIO,
   SUB_REPEATCMD,
   SUB_RESTRICTED,
   SUB_DEITYDESC,
   SUB_SHIPDESC,
   SUB_FORCE_CH0,
   SUB_FORCE_CH1,
   SUB_FORCE_CH2,
   SUB_FORCE_CH3,
   SUB_FORCE_CH4,
   SUB_FORCE_ROOM0,
   SUB_FORCE_ROOM1,
   SUB_FORCE_ROOM2,
   SUB_FORCE_ROOM3,
   SUB_FORCE_ROOM4,
   SUB_FORCE_VICTIM0,
   SUB_FORCE_VICTIM1,
   SUB_FORCE_VICTIM2,
   SUB_FORCE_VICTIM3,
   SUB_FORCE_VICTIM4,
   SUB_FORCE_HELP,
   SUB_TIMER_DO_ABORT = 128,
   SUB_TIMER_CANT_ABORT
} char_substates;

typedef enum
{
   CLAN_PLAIN,
   CLAN_CRIME,
   CLAN_GUILD,
   CLAN_SUBCLAN,
   CLAN_CORPORATION
} clan_types;

typedef enum
{
   PLAYER_SHIP,
   MOB_SHIP,
   SHIP_IMPERIAL,
   SHIP_REPUBLIC
} ship_types;

typedef enum
{
   SHIP_DOCKED,
   SHIP_READY,
   SHIP_BUSY,
   SHIP_BUSY_2,
   SHIP_BUSY_3,
   SHIP_REFUEL,
   SHIP_LAUNCH,
   SHIP_LAUNCH_2,
   SHIP_LAND,
   SHIP_LAND_2,
   SHIP_HYPERSPACE,
   SHIP_DISABLED,
   SHIP_FLYING
} ship_states;

typedef enum
{
   MISSILE_READY,
   MISSILE_FIRED,
   MISSILE_RELOAD,
   MISSILE_RELOAD_2,
   MISSILE_DAMAGED
} missile_states;

typedef enum
{
   LAND_VEHICLE,
   SHIP_FIGHTER,
   SHIP_BOMBER,
   SHIP_SHUTTLE,
   SHIP_FREIGHTER,
   SHIP_FRIGATE,
   SHIP_TT,
   SHIP_CORVETTE,
   SHIP_CRUISER,
   SHIP_DREADNAUGHT,
   SHIP_DESTROYER,
   SHIP_SPACE_STATION
} ship_classes;

typedef enum
{
   B_NONE,
   SINGLE_LASER,
   DUAL_LASER,
   TRI_LASER,
   QUAD_LASER,
   AUTOBLASTER,
   HEAVY_LASER,
   LIGHT_ION,
   REPEATING_ION,
   HEAVY_ION
} beam_types;

typedef enum
{
   CONCUSSION_MISSILE,
   PROTON_TORPEDO,
   HEAVY_ROCKET,
   HEAVY_BOMB
} missile_types;

typedef enum
{
   SS_NONE,
   SS_POISON_DEATH,
   SS_ROD_WANDS,
   SS_PARA_PETRI,
   SS_BREATH,
   SS_SPELL_STAFF
} save_types;

typedef enum
{
   SD_NONE,
   SD_FIRE,
   SD_COLD,
   SD_ELECTRICITY,
   SD_ENERGY,
   SD_ACID,
   SD_POISON,
   SD_DRAIN
} spell_dam_types;

typedef enum
{
   SA_NONE,
   SA_CREATE,
   SA_DESTROY,
   SA_RESIST,
   SA_SUSCEPT,
   SA_DIVINATE,
   SA_OBSCURE,
   SA_CHANGE
} spell_act_types;

typedef enum
{
   SP_NONE,
   SP_MINOR,
   SP_GREATER,
   SP_MAJOR
} spell_power_types;

typedef enum
{
   SC_NONE,
   SC_LUNAR,
   SC_SOLAR,
   SC_TRAVEL,
   SC_SUMMON,
   SC_LIFE,
   SC_DEATH,
   SC_ILLUSION
} spell_class_types;

typedef enum
{
   SEX_NEUTRAL,
   SEX_MALE,
   SEX_FEMALE
} sex_types;

typedef enum
{
   TRAP_TYPE_POISON_GAS = 1,
   TRAP_TYPE_POISON_DART,
   TRAP_TYPE_POISON_NEEDLE,
   TRAP_TYPE_POISON_DAGGER,
   TRAP_TYPE_POISON_ARROW,
   TRAP_TYPE_BLINDNESS_GAS,
   TRAP_TYPE_SLEEPING_GAS,
   TRAP_TYPE_FLAME,
   TRAP_TYPE_EXPLOSION,
   TRAP_TYPE_ACID_SPRAY,
   TRAP_TYPE_ELECTRIC_SHOCK,
   TRAP_TYPE_BLADE,
   TRAP_TYPE_SEX_CHANGE
} trap_types;

typedef enum
{
   ITEM_NONE,
   ITEM_LIGHT,
   ITEM_SCROLL,
   ITEM_WAND,
   ITEM_STAFF,
   ITEM_WEAPON,
   ITEM_FIREWEAPON,
   ITEM_MISSILE,
   ITEM_TREASURE,
   ITEM_ARMOR,
   ITEM_POTION,
   ITEM_WORN,
   ITEM_FURNITURE,
   ITEM_TRASH,
   ITEM_OLDTRAP,
   ITEM_CONTAINER,
   ITEM_NOTE,
   ITEM_DRINK_CON,
   ITEM_KEY,
   ITEM_FOOD,
   ITEM_MONEY,
   ITEM_PEN,
   ITEM_BOAT,
   ITEM_CORPSE_NPC,
   ITEM_CORPSE_PC,
   ITEM_FOUNTAIN,
   ITEM_PILL,
   ITEM_BLOOD,
   ITEM_BLOODSTAIN,
   ITEM_SCRAPS,
   ITEM_PIPE,
   ITEM_HERB_CON,
   ITEM_HERB,
   ITEM_INCENSE,
   ITEM_FIRE,
   ITEM_BOOK,
   ITEM_SWITCH,
   ITEM_LEVER,
   ITEM_PULLCHAIN,
   ITEM_BUTTON,
   ITEM_DIAL,
   ITEM_RUNE,
   ITEM_RUNEPOUCH,
   ITEM_MATCH,
   ITEM_TRAP,
   ITEM_MAP,
   ITEM_PORTAL,
   ITEM_PAPER,
   ITEM_TINDER,
   ITEM_LOCKPICK,
   ITEM_SPIKE,
   ITEM_DISEASE,
   ITEM_OIL,
   ITEM_FUEL,
   ITEM_SHORT_BOW,
   ITEM_LONG_BOW,
   ITEM_CROSSBOW,
   ITEM_AMMO,
   ITEM_QUIVER,
   ITEM_SHOVEL,
   ITEM_SALVE,
   ITEM_RAWSPICE,
   ITEM_LENS,
   ITEM_CRYSTAL,
   ITEM_DURAPLAST,
   ITEM_BATTERY,
   ITEM_TOOLKIT,
   ITEM_DURASTEEL,
   ITEM_OVEN,
   ITEM_MIRROR,
   ITEM_CIRCUIT,
   ITEM_SUPERCONDUCTOR,
   ITEM_COMLINK,
   ITEM_MEDPAC,
   ITEM_FABRIC,
   ITEM_RARE_METAL,
   ITEM_MAGNET,
   ITEM_THREAD,
   ITEM_SPICE,
   ITEM_SMUT,
   ITEM_DEVICE,
   ITEM_SPACECRAFT,
   ITEM_GRENADE,
   ITEM_LANDMINE,
   ITEM_GOVERNMENT,
   ITEM_DROID_CORPSE,
   ITEM_BOLT,
   ITEM_CHEMICAL,
   ITEM_COMMSYSTEM,
   ITEM_DATAPAD,
   ITEM_MODULE,
   ITEM_BUG,
   ITEM_BEACON,
   ITEM_GLAUNCHER,
   ITEM_RLAUNCHER,
   ITEM_BINDERS,
   ITEM_GOGGLES,
   ITEM_SHIPBOMB,
   ITEM_EMP_GRENADE
} item_types;

typedef enum
{
   APPLY_NONE,
   APPLY_STR,
   APPLY_DEX,
   APPLY_INT,
   APPLY_WIS,
   APPLY_CON,
   APPLY_SEX,
   APPLY_NULL,
   APPLY_LEVEL,
   APPLY_AGE,
   APPLY_HEIGHT,
   APPLY_WEIGHT,
   APPLY_MANA,
   APPLY_HIT,
   APPLY_MOVE,
   APPLY_GOLD,
   APPLY_EXP,
   APPLY_AC,
   APPLY_HITROLL,
   APPLY_DAMROLL,
   APPLY_SAVING_POISON,
   APPLY_SAVING_ROD,
   APPLY_SAVING_PARA,
   APPLY_SAVING_BREATH,
   APPLY_SAVING_SPELL,
   APPLY_CHA,
   APPLY_AFFECT,
   APPLY_RESISTANT,
   APPLY_IMMUNE,
   APPLY_SUSCEPTIBLE,
   APPLY_WEAPONSPELL,
   APPLY_LCK,
   APPLY_BACKSTAB,
   APPLY_PICK,
   APPLY_TRACK,
   APPLY_STEAL,
   APPLY_SNEAK,
   APPLY_HIDE,
   APPLY_PALM,
   APPLY_DETRAP,
   APPLY_DODGE,
   APPLY_PEEK,
   APPLY_SCAN,
   APPLY_GOUGE,
   APPLY_SEARCH,
   APPLY_MOUNT,
   APPLY_DISARM,
   APPLY_KICK,
   APPLY_PARRY,
   APPLY_BASH,
   APPLY_STUN,
   APPLY_PUNCH,
   APPLY_CLIMB,
   APPLY_GRIP,
   APPLY_SCRIBE,
   APPLY_COVER_TRAIL,
   APPLY_WEARSPELL,
   APPLY_REMOVESPELL,
   APPLY_EMOTION,
   APPLY_MENTALSTATE,
   APPLY_STRIPSN,
   APPLY_REMOVE,
   APPLY_DIG,
   APPLY_FULL,
   APPLY_THIRST,
   APPLY_DRUNK,
   APPLY_BLOOD,
   MAX_APPLY_TYPE
} apply_types;

typedef enum
{
   DIR_NORTH,
   DIR_EAST,
   DIR_SOUTH,
   DIR_WEST,
   DIR_UP,
   DIR_DOWN,
   DIR_NORTHEAST,
   DIR_NORTHWEST,
   DIR_SOUTHEAST,
   DIR_SOUTHWEST,
   DIR_SOMEWHERE
} dir_types;

typedef enum
{
   SECT_INSIDE,
   SECT_CITY,
   SECT_FIELD,
   SECT_FOREST,
   SECT_HILLS,
   SECT_MOUNTAIN,
   SECT_WATER_SWIM,
   SECT_WATER_NOSWIM,
   SECT_UNDERWATER,
   SECT_AIR,
   SECT_DESERT,
   SECT_DUNNO,
   SECT_OCEANFLOOR,
   SECT_UNDERGROUND,
   SECT_SCRUB,
   SECT_ROCKY,
   SECT_SAVANNA,
   SECT_TUNDRA,
   SECT_GLACIAL,
   SECT_RAINFOREST,
   SECT_JUNGLE,
   SECT_SWAMP,
   SECT_WETLANDS,
   SECT_BRUSH,
   SECT_STEPPE,
   SECT_FARMLAND,
   SECT_VOLCANIC,
   SECT_MAX
} sector_types;

typedef enum
{
   WEAR_NONE = -1,
   WEAR_LIGHT = 0,
   WEAR_FINGER_L,
   WEAR_FINGER_R,
   WEAR_NECK_1,
   WEAR_NECK_2,
   WEAR_BODY,
   WEAR_HEAD,
   WEAR_LEGS,
   WEAR_FEET,
   WEAR_HANDS,
   WEAR_ARMS,
   WEAR_SHIELD,
   WEAR_ABOUT,
   WEAR_WAIST,
   WEAR_WRIST_L,
   WEAR_WRIST_R,
   WEAR_WIELD,
   WEAR_HOLD,
   WEAR_DUAL_WIELD,
   WEAR_EARS,
   WEAR_EYES,
   WEAR_MISSILE_WIELD,
   WEAR_BACK,
   WEAR_HOLSTER_L,
   WEAR_HOLSTER_R,
   WEAR_BOTH_WRISTS,
   MAX_WEAR
} wear_locations;

typedef enum
{
   BOARD_NOTE,
   BOARD_MAIL
} board_types;

typedef enum
{
   COND_DRUNK,
   COND_FULL,
   COND_THIRST,
   COND_BLOODTHIRST,
   MAX_CONDS
} conditions;

typedef enum
{
   POS_DEAD,
   POS_MORTAL,
   POS_INCAP,
   POS_STUNNED,
   POS_SLEEPING,
   POS_RESTING,
   POS_SITTING,
   POS_FIGHTING,
   POS_STANDING,
   POS_MOUNTED,
   POS_SHOVE,
   POS_DRAG
} positions;

typedef enum
{
   TIMER_NONE,
   TIMER_RECENTFIGHT,
   TIMER_SHOVEDRAG,
   TIMER_DO_FUN,
   TIMER_APPLIED,
   TIMER_PKILLED
} timer_types;

typedef enum
{
   TAR_IGNORE,
   TAR_CHAR_OFFENSIVE,
   TAR_CHAR_DEFENSIVE,
   TAR_CHAR_SELF,
   TAR_OBJ_INV
} target_types;

typedef enum
{
   SKILL_UNKNOWN,
   SKILL_SPELL,
   SKILL_SKILL,
   SKILL_WEAPON,
   SKILL_TONGUE,
   SKILL_HERB
} skill_types;

typedef enum
{
   MP_MOB,
   MP_ROOM,
   MP_OBJ
} mp_types;

/*
 * Function pointer types.
 */
typedef void DO_FUN(CHAR_DATA *ch, const char *argument);
typedef bool SPEC_FUN(CHAR_DATA *ch);
typedef ch_ret SPELL_FUN(int sn, int level, CHAR_DATA *ch, void *vo);
