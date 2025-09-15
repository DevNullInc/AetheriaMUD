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
#include "mud_macros.hpp" // For BVxx bitvector macros

/*
 * Command logging types.
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

/*
 * Return types for move_char, damage, greet_trigger, etc, etc
 */
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

/* Force Defines */
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

/* Echo types for echo_to_all */
#define ECHOTAR_ALL 0
#define ECHOTAR_PC 1
#define ECHOTAR_IMM 2

/* short cut crash bug fix provided by gfinello@mail.karmanet.it*/
typedef enum
{
   relMSET_ON,
   relOSET_ON
} relation_type;

/* defines for new do_who */
#define WT_MORTAL 0
#define WT_IMM 2
#define WT_AVATAR 1
#define WT_NEWBIE 3

/*
 * Site ban structure.
 */
struct ban_data; // Forward declaration

/*
 * Time and weather stuff.
 */
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

/*
 * Connected state for a channel.
 */
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

/*
 * Character substates
 */
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

   /* timer types ONLY below this point */
   SUB_TIMER_DO_ABORT = 128,
   SUB_TIMER_CANT_ABORT
} char_substates;

/* ability classes */
#define ABILITY_NONE -1
#define COMBAT_ABILITY 0
#define PILOTING_ABILITY 1
#define ENGINEERING_ABILITY 2
#define HUNTING_ABILITY 3
#define SMUGGLING_ABILITY 4
#define POLITICIAN_ABILITY 5
#define FORCE_ABILITY 6
#define SLICER_ABILITY 7
#define ASSASSIN_ABILITY 8
#define TECHNICIAN_ABILITY 9

/* Languages */
#define LANG_BASIC BV00
#define LANG_WOOKIEE BV01
#define LANG_TWI_LEK BV02
#define LANG_RODIAN BV03
#define LANG_HUTT BV04
#define LANG_MON_CALAMARI BV05
#define LANG_NOGHRI BV06
#define LANG_EWOK BV07
#define LANG_ITHORIAN BV08
#define LANG_GOTAL BV09
#define LANG_DEVARONIAN BV10
#define LANG_BINARY BV11
#define LANG_FIRRERREO BV12
#define LANG_CLAN BV13
#define LANG_GAMORREAN BV14
#define LANG_TOGORIAN BV15
#define LANG_SHISTAVANEN BV16
#define LANG_JAWA BV17
#define LANG_KUBAZ BV18
#define LANG_ADARIAN BV19
#define LANG_VERPINE BV20
#define LANG_DEFEL BV21
#define LANG_TRANDOSHAN BV22
#define LANG_HAPAN BV23
#define LANG_QUARREN BV24
#define LANG_SULLUSTAN BV25
#define LANG_FALLEEN BV26
#define LANG_BARABEL BV27
#define LANG_YEVETHAN BV28
#define LANG_GAND BV29
#define LANG_DUROS BV30
#define LANG_COYNITE BV31
#define LANG_UNKNOWN 0
#define VALID_LANGS (LANG_BASIC | LANG_WOOKIEE | LANG_TWI_LEK | LANG_RODIAN | LANG_HUTT | LANG_MON_CALAMARI | LANG_NOGHRI | LANG_GAMORREAN | LANG_JAWA | LANG_ADARIAN | LANG_EWOK | LANG_VERPINE | LANG_DEFEL | LANG_TRANDOSHAN | LANG_HAPAN | LANG_QUARREN | LANG_SULLUSTAN | LANG_BINARY | LANG_FIRRERREO | LANG_CLAN | LANG_TOGORIAN | LANG_SHISTAVANEN | LANG_KUBAZ | LANG_YEVETHAN | LANG_GAND | LANG_DUROS | LANG_COYNITE | LANG_GOTAL | LANG_DEVARONIAN | LANG_FALLEEN | LANG_ITHORIAN | LANG_BARABEL)

/* Used to store sleeping mud progs. -rkb */
typedef enum
{
   MP_MOB,
   MP_ROOM,
   MP_OBJ
} mp_types;

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

#define PLANET_NOCAPTURE BV00

/* Ship Flags */
#define SHIP_NOHIJACK BV00
#define SHIP_SHIELD_BOOST BV01
#define SHIP_TORP_BOOST BV02
#define SHIP_CHAFF_BOOST BV03
#define SHIP_HULL_BOOST BV04
#define SHIP_LASER_BOOST BV05
#define SHIP_MISSILE_BOOST BV06
#define SHIP_ROCKET_BOOST BV07
#define SHIP_SIMULATOR BV08
#define SHIP_NODESTROY BV09
#define SHIP_NOSLICER BV10
#define XSHIP_ION_LASERS BV11
#define XSHIP_ION_DRIVE BV12
#define XSHIP_ION_ION BV13
#define XSHIP_ION_TURRET1 BV14
#define XSHIP_ION_TURRET2 BV15
#define XSHIP_ION_TURRET3 BV16
#define XSHIP_ION_TURRET4 BV17
#define XSHIP_ION_TURRET5 BV18
#define XSHIP_ION_TURRET6 BV19
#define XSHIP_ION_TURRET7 BV20
#define XSHIP_ION_TURRET8 BV21
#define XSHIP_ION_TURRET9 BV22
#define XSHIP_ION_TURRET10 BV23
#define SHIP_RESPAWN BV24
#define XSHIP_ION_HYPER BV25
#define XSHIP_ION_MISSILES BV26
#define SHIP_CLOAK BV27

#define SHIP_DAMAGE_DRIVE BV00
#define SHIP_DAMAGE_HYPERDRIVE BV01
#define SHIP_DAMAGE_LASER BV02
#define SHIP_DAMAGE_ION BV03
#define SHIP_DAMAGE_TURRET1 BV04
#define SHIP_DAMAGE_TURRET2 BV05
#define SHIP_DAMAGE_TURRET3 BV06
#define SHIP_DAMAGE_TURRET4 BV07
#define SHIP_DAMAGE_TURRET5 BV08
#define SHIP_DAMAGE_TURRET6 BV09
#define SHIP_DAMAGE_TURRET7 BV10
#define SHIP_DAMAGE_TURRET8 BV11
#define SHIP_DAMAGE_TURRET9 BV12
#define SHIP_DAMAGE_TURRET10 BV13
#define SHIP_DAMAGE_SHIELD BV14
#define SHIP_DAMAGE_PLASMASHIELD BV15
#define SHIP_DAMAGE_LIFESUPPORT BV16
#define SHIP_DAMAGE_MISSILE BV17

/* ACT bits for mobs */
#define ACT_IS_NPC BV00
#define ACT_SENTINEL BV01
#define ACT_SCAVENGER BV02
#define ACT_NOFLEE BV03
#define ACT_AGGRESSIVE BV05
#define ACT_STAY_AREA BV06
#define ACT_WIMPY BV07
#define ACT_PET BV08
#define ACT_TRAIN BV09
#define ACT_PRACTICE BV10
#define ACT_IMMORTAL BV11
#define ACT_DEADLY BV12
#define ACT_POLYSELF BV13
#define ACT_META_AGGR BV14
#define ACT_GUARDIAN BV15
#define ACT_RUNNING BV16
#define ACT_NOWANDER BV17
#define ACT_MOUNTABLE BV18
#define ACT_MOUNTED BV19
#define ACT_SCHOLAR BV20
#define ACT_SECRETIVE BV21
#define ACT_POLYMORPHED BV22
#define ACT_MOBINVIS BV23
#define ACT_NOASSIST BV24
#define ACT_NOKILL BV25
#define ACT_DROID BV26
#define ACT_NOCORPSE BV27
#define ACT_PUEBLO BV28
#define ACT_PROTOTYPE BV30

/* Act2 Flags */
#define ACT_BOUND BV00
#define ACT_JEDI BV01
#define ACT_SITH BV02
#define ACT_GAGGED BV03

/* vip flags */
#define VIP_CORUSCANT BV00
#define VIP_YAVIN_IV BV01
#define VIP_TATOOINE BV02
#define VIP_KASHYYYK BV03
#define VIP_MON_CALAMARI BV04
#define VIP_ENDOR BV05
#define VIP_ORD_MANTELL BV06
#define VIP_NAL_HUTTA BV07
#define VIP_CORELLIA BV08
#define VIP_BAKURA BV09

/* player wanted bits */
#define WANTED_CORUSCANT VIP_CORUSCANT
#define WANTED_YAVIN_IV VIP_YAVIN_IV
#define WANTED_TATOOINE VIP_TATOOINE
#define WANTED_KASHYYYK VIP_KASHYYYK
#define WANTED_MON_CALAMARI VIP_MON_CALAMARI
#define WANTED_ENDOR VIP_ENDOR
#define WANTED_ORD_MANTELL VIP_ORD_MANTELL
#define WANTED_NAL_HUTTA VIP_NAL_HUTTA
#define WANTED_CORELLIA VIP_CORELLIA
#define WANTED_BAKURA VIP_BAKURA

/* 'affected_by' bits */
#define AFF_NONE 0
#define AFF_BLIND BV00
#define AFF_INVISIBLE BV01
#define AFF_DETECT_EVIL BV02
#define AFF_DETECT_INVIS BV03
#define AFF_DETECT_MAGIC BV04
#define AFF_DETECT_HIDDEN BV05
#define AFF_WEAKEN BV06
#define AFF_SANCTUARY BV07
#define AFF_FAERIE_FIRE BV08
#define AFF_INFRARED BV09
#define AFF_CURSE BV10
#define AFF_COVER_TRAIL BV11
#define AFF_POISON BV12
#define AFF_PROTECT BV13
#define AFF_PARALYSIS BV14
#define AFF_SNEAK BV15
#define AFF_HIDE BV16
#define AFF_SLEEP BV17
#define AFF_CHARM BV18
#define AFF_FLYING BV19
#define AFF_PASS_DOOR BV20
#define AFF_FLOATING BV21
#define AFF_TRUESIGHT BV22
#define AFF_DETECTTRAPS BV23
#define AFF_SCRYING BV24
#define AFF_FIRESHIELD BV25
#define AFF_SHOCKSHIELD BV26
#define AFF_FASTHEAL BV27
#define AFF_ICESHIELD BV28
#define AFF_POSSESS BV29
#define AFF_BERSERK BV30
#define AFF_AQUA_BREATH BV31

/* Resistant Immune Susceptible flags */
#define RIS_FIRE BV00
#define RIS_COLD BV01
#define RIS_ELECTRICITY BV02
#define RIS_ENERGY BV03
#define RIS_BLUNT BV04
#define RIS_PIERCE BV05
#define RIS_SLASH BV06
#define RIS_ACID BV07
#define RIS_POISON BV08
#define RIS_DRAIN BV09
#define RIS_SLEEP BV10
#define RIS_CHARM BV11
#define RIS_HOLD BV12
#define RIS_NONMAGIC BV13
#define RIS_PLUS1 BV14
#define RIS_PLUS2 BV15
#define RIS_PLUS3 BV16
#define RIS_PLUS4 BV17
#define RIS_PLUS5 BV18
#define RIS_PLUS6 BV19
#define RIS_MAGIC BV20
#define RIS_PARALYSIS BV21

/* Attack types */
#define ATCK_BITE BV00
#define ATCK_CLAWS BV01
#define ATCK_TAIL BV02
#define ATCK_STING BV03
#define ATCK_PUNCH BV04
#define ATCK_KICK BV05
#define ATCK_TRIP BV06
#define ATCK_BACKSTAB BV10

/* Defense types */
#define DFND_PARRY BV00
#define DFND_DODGE BV01
#define DFND_DISARM BV19
#define DFND_GRIP BV21

/* Body parts */
#define PART_HEAD BV00
#define PART_ARMS BV01
#define PART_LEGS BV02
#define PART_HEART BV03
#define PART_BRAINS BV04
#define PART_GUTS BV05
#define PART_HANDS BV06
#define PART_FEET BV07
#define PART_FINGERS BV08
#define PART_EAR BV09
#define PART_EYE BV10
#define PART_LONG_TONGUE BV11
#define PART_EYESTALKS BV12
#define PART_TENTACLES BV13
#define PART_FINS BV14
#define PART_WINGS BV15
#define PART_TAIL BV16
#define PART_SCALES BV17
#define PART_CLAWS BV18
#define PART_FANGS BV19
#define PART_HORNS BV20
#define PART_TUSKS BV21
#define PART_TAILATTACK BV22
#define PART_SHARPSCALES BV23
#define PART_BEAK BV24
#define PART_HAUNCH BV25
#define PART_HOOVES BV26
#define PART_PAWS BV27
#define PART_FORELEGS BV28
#define PART_FEATHERS BV29

/* Autosave flags */
#define SV_DEATH BV00
#define SV_KILL BV01
#define SV_PASSCHG BV02
#define SV_DROP BV03
#define SV_PUT BV04
#define SV_GIVE BV05
#define SV_AUTO BV06
#define SV_ZAPDROP BV07
#define SV_AUCTION BV08
#define SV_GET BV09
#define SV_RECEIVE BV10
#define SV_IDLE BV11
#define SV_BACKUP BV12

/* Pipe flags */
#define PIPE_TAMPED BV01
#define PIPE_LIT BV02
#define PIPE_HOT BV03
#define PIPE_DIRTY BV04
#define PIPE_FILTHY BV05
#define PIPE_GOINGOUT BV06
#define PIPE_BURNT BV07
#define PIPE_FULLOFASH BV08

/* Skill/Spell flags */
#define SF_WATER BV11
#define SF_EARTH BV12
#define SF_AIR BV13
#define SF_ASTRAL BV14
#define SF_AREA BV15
#define SF_DISTANT BV16
#define SF_REVERSE BV17
#define SF_SAVE_HALF_DAMAGE BV18
#define SF_SAVE_NEGATES BV19
#define SF_ACCUMULATIVE BV20
#define SF_RECASTABLE BV21
#define SF_NOSCRIBE BV22
#define SF_NOBREW BV23
#define SF_GROUPSPELL BV24
#define SF_OBJECT BV25
#define SF_CHARACTER BV26
#define SF_SECRETSKILL BV27
#define SF_PKSENSITIVE BV28
#define SF_STOPONFAIL BV29

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

/* Sex */
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

#define TRAP_ROOM BV00
#define TRAP_OBJ BV01
#define TRAP_ENTER_ROOM BV02
#define TRAP_LEAVE_ROOM BV03
#define TRAP_OPEN BV04
#define TRAP_CLOSE BV05
#define TRAP_GET BV06
#define TRAP_PUT BV07
#define TRAP_PICK BV08
#define TRAP_UNLOCK BV09
#define TRAP_N BV10
#define TRAP_S BV11
#define TRAP_E BV12
#define TRAP_W BV13
#define TRAP_U BV14
#define TRAP_D BV15
#define TRAP_EXAMINE BV16
#define TRAP_NE BV17
#define TRAP_NW BV18
#define TRAP_SE BV19
#define TRAP_SW BV20

/* Item types. */
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

/* Extra flags for objects */
#define ITEM_GLOW BV00
#define ITEM_HUM BV01
#define ITEM_DARK BV02
#define ITEM_HUTT_SIZE BV03
#define ITEM_CONTRABAND BV04
#define ITEM_INVIS BV05
#define ITEM_MAGIC BV06
#define ITEM_NODROP BV07
#define ITEM_BLESS BV08
#define ITEM_ANTI_GOOD BV09
#define ITEM_ANTI_EVIL BV10
#define ITEM_ANTI_NEUTRAL BV11
#define ITEM_NOREMOVE BV12
#define ITEM_INVENTORY BV13
#define ITEM_ANTI_SOLDIER BV14
#define ITEM_ANTI_THIEF BV15
#define ITEM_ANTI_HUNTER BV16
#define ITEM_ANTI_JEDI BV17
#define ITEM_SMALL_SIZE BV18
#define ITEM_LARGE_SIZE BV19
#define ITEM_DONATION BV20
#define ITEM_CLANOBJECT BV21
#define ITEM_ANTI_CITIZEN BV22
#define ITEM_ANTI_SITH BV23
#define ITEM_ANTI_PILOT BV24
#define ITEM_HIDDEN BV25
#define ITEM_POISONED BV26
#define ITEM_COVERING BV27
#define ITEM_DEATHROT BV28
#define ITEM_BURRIED BV29
#define ITEM_PROTOTYPE BV30
#define ITEM_HUMAN_SIZE BV31

/* Magic flags */
#define ITEM_RETURNING BV00
#define ITEM_BACKSTABBER BV01
#define ITEM_BANE BV02
#define ITEM_LOYAL BV03
#define ITEM_HASTE BV04
#define ITEM_DRAIN BV05
#define ITEM_LIGHTNING_BLADE BV06

/* Blaster settings */
#define BLASTER_NORMAL 0
#define BLASTER_HALF 2
#define BLASTER_FULL 5
#define BLASTER_LOW 1
#define BLASTER_STUN 3
#define BLASTER_HIGH 4

/* Weapon Types */
#define WEAPON_NONE 0
#define WEAPON_VIBRO_AXE 1
#define WEAPON_VIBRO_BLADE 2
#define WEAPON_LIGHTSABER 3
#define WEAPON_WHIP 4
#define WEAPON_CLAW 5
#define WEAPON_BLASTER 6
#define WEAPON_BLUDGEON 8
#define WEAPON_BOWCASTER 9
#define WEAPON_FORCE_PIKE 11
#define WEAPON_DUAL_LIGHTSABER 12

/* Lever/dial/switch/button/pullchain flags */
#define TRIG_UP BV00
#define TRIG_UNLOCK BV01
#define TRIG_LOCK BV02
#define TRIG_D_NORTH BV03
#define TRIG_D_SOUTH BV04
#define TRIG_D_EAST BV05
#define TRIG_D_WEST BV06
#define TRIG_D_UP BV07
#define TRIG_D_DOWN BV08
#define TRIG_DOOR BV09
#define TRIG_CONTAINER BV10
#define TRIG_OPEN BV11
#define TRIG_CLOSE BV12
#define TRIG_PASSAGE BV13
#define TRIG_OLOAD BV14
#define TRIG_MLOAD BV15
#define TRIG_TELEPORT BV16
#define TRIG_TELEPORTALL BV17
#define TRIG_TELEPORTPLUS BV18
#define TRIG_DEATH BV19
#define TRIG_CAST BV20
#define TRIG_FAKEBLADE BV21
#define TRIG_RAND4 BV22
#define TRIG_RAND6 BV23
#define TRIG_TRAPDOOR BV24
#define TRIG_ANOTHEROOM BV25
#define TRIG_USEDIAL BV26
#define TRIG_ABSOLUTEVNUM BV27
#define TRIG_SHOWROOMDESC BV28
#define TRIG_AUTORETURN BV29

#define TELE_SHOWDESC BV00
#define TELE_TRANSALL BV01
#define TELE_TRANSALLPLUS BV02

/* drug types */
#define SPICE_GLITTERSTIM 0
#define SPICE_CARSANUM 1
#define SPICE_RYLL 2
#define SPICE_ANDRIS 3

/* crystal types */
#define GEM_NON_ADEGEN 0
#define GEM_KATHRACITE 1
#define GEM_RELACITE 2
#define GEM_DANITE 3
#define GEM_MEPHITE 4
#define GEM_PONITE 5
#define GEM_ILLUM 6
#define GEM_CORUSCA 7

/* Wear flags */
#define ITEM_TAKE BV00
#define ITEM_WEAR_FINGER BV01
#define ITEM_WEAR_NECK BV02
#define ITEM_WEAR_BODY BV03
#define ITEM_WEAR_HEAD BV04
#define ITEM_WEAR_LEGS BV05
#define ITEM_WEAR_FEET BV06
#define ITEM_WEAR_HANDS BV07
#define ITEM_WEAR_ARMS BV08
#define ITEM_WEAR_SHIELD BV09
#define ITEM_WEAR_ABOUT BV10
#define ITEM_WEAR_WAIST BV11
#define ITEM_WEAR_WRIST BV12
#define ITEM_WIELD BV13
#define ITEM_HOLD BV14
#define ITEM_DUAL_WIELD BV15
#define ITEM_WEAR_EARS BV16
#define ITEM_WEAR_EYES BV17
#define ITEM_MISSILE_WIELD BV18
#define ITEM_WEAR_BACK BV19
#define ITEM_WEAR_HOLSTER1 BV20
#define ITEM_WEAR_HOLSTER2 BV21
#define ITEM_WEAR_BOTHWRISTS BV22

/* Apply types (for affects) */
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

/* Values for containers (value[1]) */
#define CONT_CLOSEABLE 1
#define CONT_PICKPROOF 2
#define CONT_CLOSED 4
#define CONT_LOCKED 8

/* Room flags */
#define ROOM_DARK BV00
#define ROOM_NO_MOB BV02
#define ROOM_INDOORS BV03
#define ROOM_CAN_LAND BV04
#define ROOM_CAN_FLY BV05
#define ROOM_NO_DRIVING BV06
#define ROOM_NO_MAGIC BV07
#define ROOM_BANK BV08
#define ROOM_PRIVATE BV09
#define ROOM_SAFE BV10
#define ROOM_SOLITARY BV11
#define ROOM_PET_SHOP BV12
#define ROOM_NO_RECALL BV13
#define ROOM_DONATION BV14
#define ROOM_NODROPALL BV15
#define ROOM_SILENCE BV16
#define ROOM_LOGSPEECH BV17
#define ROOM_NODROP BV18
#define ROOM_CLANSTOREROOM BV19
#define ROOM_PLR_HOME BV20
#define ROOM_EMPTY_HOME BV21
#define ROOM_TELEPORT BV22
#define ROOM_HOTEL BV23
#define ROOM_NOFLOOR BV24
#define ROOM_REFINERY BV25
#define ROOM_FACTORY BV26
#define ROOM_R_RECRUIT BV27
#define ROOM_E_RECRUIT BV28
#define ROOM_SPACECRAFT BV29
#define ROOM_PROTOTYPE BV30
#define ROOM_AUCTION BV31

/* Second Set of Room Flags */
#define ROOM_EMPTY_SHOP BV00
#define ROOM_PLR_SHOP BV01
#define ROOM_SHIPYARD BV02
#define ROOM_GARAGE BV03
#define ROOM_BARRACKS BV04
#define ROOM_CONTROL BV05
#define ROOM_CLANLAND BV06
#define ROOM_ARENA BV07
#define ROOM_CLANJAIL BV08
#define ROOM_BLACKMARKET BV09
#define ROOM_HIDDENPAD BV10

/* Directions */
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

/* Exit flags */
#define EX_ISDOOR BV00
#define EX_CLOSED BV01
#define EX_LOCKED BV02
#define EX_SECRET BV03
#define EX_SWIM BV04
#define EX_PICKPROOF BV05
#define EX_FLY BV06
#define EX_CLIMB BV07
#define EX_DIG BV08
#define EX_RES1 BV09
#define EX_NOPASSDOOR BV10
#define EX_HIDDEN BV11
#define EX_PASSAGE BV12
#define EX_PORTAL BV13
#define EX_RES2 BV14
#define EX_RES3 BV15
#define EX_xCLIMB BV16
#define EX_xENTER BV17
#define EX_xLEAVE BV18
#define EX_xAUTO BV19
#define EX_RES4 BV20
#define EX_xSEARCHABLE BV21
#define EX_BASHED BV22
#define EX_BASHPROOF BV23
#define EX_NOMOB BV24
#define EX_WINDOW BV25
#define EX_xLOOK BV26

/* Sector types */
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

/* Equipment wear locations */
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

/* Board Types */
typedef enum
{
   BOARD_NOTE,
   BOARD_MAIL
} board_types;

/* Auth Flags */
#define FLAG_WRAUTH 1
#define FLAG_AUTH 2

/* Conditions */
typedef enum
{
   COND_DRUNK,
   COND_FULL,
   COND_THIRST,
   COND_BLOODTHIRST,
   MAX_CONDS
} conditions;

/* Positions */
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

/* ACT bits for players */
#define PLR_IS_NPC BV00
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

typedef enum
{
   TIMER_NONE,
   TIMER_RECENTFIGHT,
   TIMER_SHOVEDRAG,
   TIMER_DO_FUN,
   TIMER_APPLIED,
   TIMER_PKILLED
} timer_types;

/* Channel bits */
#define CHANNEL_AUCTION BV00
#define CHANNEL_CHAT BV01
#define CHANNEL_QUEST BV02
#define CHANNEL_IMMTALK BV03
#define CHANNEL_MUSIC BV04
#define CHANNEL_ASK BV05
#define CHANNEL_SHOUT BV06
#define CHANNEL_YELL BV07
#define CHANNEL_MONITOR BV08
#define CHANNEL_LOG BV09
#define CHANNEL_104 BV10
#define CHANNEL_CLAN BV11
#define CHANNEL_BUILD BV12
#define CHANNEL_105 BV13
#define CHANNEL_AVTALK BV14
#define CHANNEL_PRAY BV15
#define CHANNEL_COUNCIL BV16
#define CHANNEL_GUILD BV17
#define CHANNEL_COMM BV18
#define CHANNEL_TELLS BV19
#define CHANNEL_ORDER BV20
#define CHANNEL_NEWBIE BV21
#define CHANNEL_WARTALK BV22
#define CHANNEL_OOC BV23
#define CHANNEL_SHIP BV24
#define CHANNEL_SYSTEM BV25
#define CHANNEL_SPACE BV26
#define CHANNEL_103 BV27
#define CHANNEL_SPORTS BV28
#define CHANNEL_HOLONET BV31
#define CHANNEL_CLANTALK CHANNEL_CLAN

/* Area defines */
#define AREA_DELETED BV00
#define AREA_LOADED BV01

/* Area flags */
#define AFLAG_NOPKILL BV00
#define AFLAG_PROTOTYPE BV01

/* Target types. */
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

/* RIS for get_affect */
#define RIS_000 BV00
#define RIS_R00 BV01
#define RIS_0I0 BV02
#define RIS_RI0 BV03
#define RIS_00S BV04
#define RIS_R0S BV05
#define RIS_0IS BV06
#define RIS_RIS BV07
#define GA_AFFECTED BV09
#define GA_RESISTANT BV10
#define GA_IMMUNE BV11
#define GA_SUSCEPTIBLE BV12
#define GA_RIS BV30

/* mud prog defines */
#define ERROR_PROG -1
#define IN_FILE_PROG 0
#define ACT_PROG BV00
#define SPEECH_PROG BV01
#define RAND_PROG BV02
#define FIGHT_PROG BV03
#define RFIGHT_PROG BV03
#define DEATH_PROG BV04
#define RDEATH_PROG BV04
#define HITPRCNT_PROG BV05
#define ENTRY_PROG BV06
#define ENTER_PROG BV06
#define GREET_PROG BV07
#define RGREET_PROG BV07
#define OGREET_PROG BV07
#define ALL_GREET_PROG BV08
#define GIVE_PROG BV09
#define BRIBE_PROG BV10
#define HOUR_PROG BV11
#define TIME_PROG BV12
#define WEAR_PROG BV13
#define REMOVE_PROG BV14
#define SAC_PROG BV15
#define LOOK_PROG BV16
#define EXA_PROG BV17
#define CUSTOM_PROG BV18
#define GET_PROG BV19
#define DROP_PROG BV20
#define DAMAGE_PROG BV21
#define REPAIR_PROG BV22
#define RANDIW_PROG BV23
#define SPEECHIW_PROG BV24
#define PULL_PROG BV25
#define PUSH_PROG BV26
#define SLEEP_PROG BV27
#define REST_PROG BV28
#define LEAVE_PROG BV29
#define SCRIPT_PROG BV30
#define USE_PROG BV31

/* Defines for the command flags */
#define CMD_POSSESS BV00
#define CMD_ACTION BV01
#define CMD_MUDPROG BV02
#define CMD_NOFORCE BV03
#define CMD_OOC BV04
#define CMD_BUILD BV05
#define CMD_PLR_ONLY BV06
#define CMD_FULLNAME BV07
#define CMD_SOCIAL BV08
#define CMD_WIZONLY BV09
#define CMD_DEITY BV10
#define CMD_GUEST BV11
#define CMD_NOGHOST BV12
#define CMD_NOSUMMON BV13
#define CMD_OLC BV14
#define CMD_LOG BV15
#define CMD_NOALIAS BV16
#define CMD_NOSHOW BV17
#define CMD_NOPRAC BV18
#define CMD_NOQUEST BV19
#define CMD_NOSNEAK BV20
#define CMD_NOMOUNT BV21
#define CMD_NOLOOT BV22
#define CMD_NOSLAG BV23
#define CMD_NOCLAN BV24
#define CMD_KEEPTARGET BV25
#define CMD_NOCHANS BV26
#define CMD_NOSTORE BV27
#define CMD_NODISARM BV28
#define CMD_NOLOCKPICK BV29
#define CMD_NOFORAGE BV30
#define CMD_NODRIVE BV31
