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
 *                copyright (c) 2025 /dev/null Industries - StygianRenegade                                                     *
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

#ifndef MUD_CONSTANTS_HPP
#define MUD_CONSTANTS_HPP

#define CODENAME "SWFotEFUSS"
#define CODEVERSION "1.5.3"

// Backward compatibility for snippets and such.
#define mudstrlcpy strlcpy
#define mudstrlcat strlcat
#define str_dup strdup

const bool TRUE = true;
const bool FALSE = false;
const short BERR = 255;

#define KEY(literal, field, value) \
   if (!str_cmp(word, (literal)))  \
   {                               \
      (field) = (value);           \
      fMatch = TRUE;               \
      break;                       \
   }

/* Macro taken from DOTD codebase. Fcloses a file, then nulls its pointer for safety. */
#define FCLOSE(fp) \
   fclose((fp));   \
   (fp) = NULL;

#define DUR_CONV 23.333333333333333333333333
#define HIDDEN_TILDE '*'

#define BV00 (1 << 0)
#define BV01 (1 << 1)
#define BV02 (1 << 2)
#define BV03 (1 << 3)
#define BV04 (1 << 4)
#define BV05 (1 << 5)
#define BV06 (1 << 6)
#define BV07 (1 << 7)
#define BV08 (1 << 8)
#define BV09 (1 << 9)
#define BV10 (1 << 10)
#define BV11 (1 << 11)
#define BV12 (1 << 12)
#define BV13 (1 << 13)
#define BV14 (1 << 14)
#define BV15 (1 << 15)
#define BV16 (1 << 16)
#define BV17 (1 << 17)
#define BV18 (1 << 18)
#define BV19 (1 << 19)
#define BV20 (1 << 20)
#define BV21 (1 << 21)
#define BV22 (1 << 22)
#define BV23 (1 << 23)
#define BV24 (1 << 24)
#define BV25 (1 << 25)
#define BV26 (1 << 26)
#define BV27 (1 << 27)
#define BV28 (1 << 28)
#define BV29 (1 << 29)
#define BV30 (1 << 30)
#define BV31 (1 << 31)
/* 32 USED! DO NOT ADD MORE! SB */

/*
 * String and memory management parameters.
 */
#define MAX_KEY_HASH 2048
#define MAX_STRING_LENGTH 4096 /* buf */
#define MAX_INPUT_LENGTH 1024  /* arg */
#define MAX_INBUF_SIZE 1024

#define MSL MAX_STRING_LENGTH
#define MIL MAX_INPUT_LENGTH

#define MAX_MOB_COUNT 10

#define HASHSTR /* use string hashing */

#define MAX_LAYERS 8 /* maximum clothing layers */
#define MAX_NEST 100 /* maximum container nesting */

#define MAX_KILLTRACK 20 /* track mob vnums killed */

/*
 * Game parameters.
 * Increase the max'es if you add more of something.
 * Adjust the pulse numbers to suit yourself.
 */
#define MAX_EXP_WORTH 500000
#define MIN_EXP_WORTH 25

#define MAX_REXITS 20 /* Maximum exits allowed in 1 room */
#define MAX_SKILL 282
#define MAX_ABILITY 10
#define MAX_RL_ABILITY 8
#define MAX_RACE 41
#define MAX_PLANET_BASE_VALUE 100000
#define MAX_NPC_RACE 91
#define MAX_LEVEL 36
#define MAX_CLAN 50
#define MAX_PLANET 100
#define MAX_SHIP 1000
#define MAX_SHIP_ROOMS 25
#define MAX_BOUNTY 255
#define MAX_GOV 255

#define MAX_HERB 20

#define LEVEL_HERO (MAX_LEVEL - 4)
#define LEVEL_IMMORTAL (MAX_LEVEL - 4)
#define LEVEL_SUPREME MAX_LEVEL
#define LEVEL_INFINITE (MAX_LEVEL - 4)
#define LEVEL_ETERNAL (MAX_LEVEL - 4)
#define LEVEL_IMPLEMENTOR (MAX_LEVEL)
#define LEVEL_SUB_IMPLEM (MAX_LEVEL - 1)
#define LEVEL_ASCENDANT (MAX_LEVEL - 2)
#define LEVEL_GREATER (MAX_LEVEL - 3)
#define LEVEL_LESSER (MAX_LEVEL - 4)
#define LEVEL_RETIRED (MAX_LEVEL - 5)
#define LEVEL_GOD (MAX_LEVEL - 4)
#define LEVEL_TRUEIMM (MAX_LEVEL - 4)
#define LEVEL_DEMI (MAX_LEVEL - 4)
#define LEVEL_SAVIOR (MAX_LEVEL - 4)
#define LEVEL_CREATOR (MAX_LEVEL - 4)
#define LEVEL_ACOLYTE (MAX_LEVEL - 4)
#define LEVEL_NEOPHYTE (MAX_LEVEL - 4)
#define LEVEL_AVATAR (MAX_LEVEL - 5)

#define LEVEL_LOG LEVEL_LESSER
#define LEVEL_HIGOD LEVEL_GOD

#define OBJ_VNUM_DEED 67 /* vnum of deed */

#define PULSE_PER_SECOND 4
#define PULSE_MINUTE (60 * PULSE_PER_SECOND)
#define PULSE_VIOLENCE (3 * PULSE_PER_SECOND)
#define PULSE_MOBILE (4 * PULSE_PER_SECOND)
#define PULSE_TICK (70 * PULSE_PER_SECOND)
#define PULSE_AREA (60 * PULSE_PER_SECOND)
#define PULSE_AUCTION (10 * PULSE_PER_SECOND)
#define PULSE_SPACE (10 * PULSE_PER_SECOND)
#define PULSE_TAXES (60 * PULSE_MINUTE)
#define PULSE_ARENA (30 * PULSE_PER_SECOND)
#define PULSE_FORCE PULSE_MINUTE

/*
 * Stuff for area versions --Shaddai
 */
#define HAS_SPELL_INDEX -1

/*
Old Smaug area version identifiers:

Version 1: Stock 1.4a areas.
Version 2: Skipped - Probably won't ever see these, but originated from Smaug 1.8.
Version 3: Stock 1.8 areas.
*/

// This value has been reset due to the new KEY/Value based area format.
// It will not conflict with the above former area file versions.
#define AREA_VERSION_WRITE 1

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
 * Added by Thoric to get rid of bugs
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

/* Begin new force defines */
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

#define MAX_FORCE_SKILL 24

#define MAX_FORCE_ALIGN 100
#define MIN_FORCE_ALIGN -100

/* End force defines */

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

   /*
    * timer types ONLY below this point
    */
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
/*#define DIPLOMACY_ABILITY	5
#define LEADERSHIP_ABILITY	6*/
/*
 * Gonna replace the diplomacy and leadership abilities and make them POLITICIANs
 */
#define POLITICIAN_ABILITY 5
#define FORCE_ABILITY 6
#define SLICER_ABILITY 7
#define ASSASSIN_ABILITY 8
#define TECHNICIAN_ABILITY 9

/* the races */
#define RACE_HUMAN 0
#define RACE_WOOKIEE 1
#define RACE_TWI_LEK 2
#define RACE_RODIAN 3
#define RACE_HUTT 4
#define RACE_MON_CALAMARI 5
#define RACE_NOGHRI 6
#define RACE_GAMORREAN 7
#define RACE_JAWA 8
#define RACE_ADARIAN 9
#define RACE_EWOK 10
#define RACE_VERPINE 11
#define RACE_DEFEL 12
#define RACE_TRANDOSHAN 13
#define RACE_HAPAN 14
#define RACE_QUARREN 15
#define RACE_SHISTAVANEN 16
#define RACE_FALLEEN 17
#define RACE_ITHORIAN 18
#define RACE_DEVARONIAN 19
#define RACE_GOTAL 20
#define RACE_DROID 21
#define RACE_FIRRERREO 22
#define RACE_BARABEL 23
#define RACE_BOTHAN 24
#define RACE_TOGORIAN 25
#define RACE_DUG 26
#define RACE_KUBAZ 27
#define RACE_SELONIAN 28
#define RACE_GRAN 29
#define RACE_YEVETHA 30
#define RACE_GAND 31
#define RACE_DUROS 32
#define RACE_COYNITE 33
#define RACE_SULLUSTAN 34
#define RACE_PROTOCAL_DROID 35
#define RACE_ASSASSIN_DROID 36
#define RACE_GLADIATOR_DROID 37
#define RACE_ASTROMECH_DROID 38
#define RACE_INTERROGATION_DROID 39

/*
 * Languages -- Altrag
 */
#define LANG_BASIC BV00 /* Human base language */
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
#define LANG_UNKNOWN 0 /* Anything that doesnt fit a category */
#define VALID_LANGS (LANG_BASIC | LANG_WOOKIEE | LANG_TWI_LEK | LANG_RODIAN | LANG_HUTT | LANG_MON_CALAMARI | LANG_NOGHRI | LANG_GAMORREAN | LANG_JAWA | LANG_ADARIAN | LANG_EWOK | LANG_VERPINE | LANG_DEFEL | LANG_TRANDOSHAN | LANG_HAPAN | LANG_QUARREN | LANG_SULLUSTAN | LANG_BINARY | LANG_FIRRERREO | LANG_CLAN | LANG_TOGORIAN | LANG_SHISTAVANEN | LANG_KUBAZ | LANG_YEVETHAN | LANG_GAND | LANG_DUROS | LANG_COYNITE | LANG_GOTAL | LANG_DEVARONIAN | LANG_FALLEEN | LANG_ITHORIAN | LANG_BARABEL)
/*  32 Languages */

/*
 * TO types for act.
 */
#define TO_ROOM 0
#define TO_NOTVICT 1
#define TO_VICT 2
#define TO_CHAR 3
#define TO_MUD 4

#define INIT_WEAPON_CONDITION 12
#define MAX_ITEM_IMPACT 30

/* Well known mob virtual numbers.
 * Defined in #MOBILES.
 */
#define MOB_VNUM_ANIMATED_CORPSE 5
#define MOB_VNUM_POLY_WOLF 10

#define MOB_VNUM_STORMTROOPER 20
#define MOB_VNUM_IMP_GUARD 21
#define MOB_VNUM_NR_GUARD 22
#define MOB_VNUM_NR_TROOPER 23
#define MOB_VNUM_MERCINARY 24
#define MOB_VNUM_BOUNCER 25
#define MOB_VNUM_IMP_ELITE 26
#define MOB_VNUM_IMP_PATROL 27
#define MOB_VNUM_IMP_FORCES 28
#define MOB_VNUM_NR_ELITE 29
#define MOB_VNUM_NR_PATROL 30
#define MOB_VNUM_NR_FORCES 31
#define MOB_VNUM_MERC_ELITE 32
#define MOB_VNUM_MERC_PATROL 33
#define MOB_VNUM_MERC_FORCES 34
#define MOB_VNUM_SHIP_GUARD 35
#define MOB_VNUM_SUPERMOB 3

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

/*
 * ACT bits for mobs.
 * Used in #MOBILES.
 */
#define ACT_IS_NPC BV00     /* Auto set for mobs */
#define ACT_SENTINEL BV01   /* Stays in one room */
#define ACT_SCAVENGER BV02  /* Picks up objects  */
#define ACT_NOFLEE BV03     /* Mobs don't flee. -T  */
#define ACT_AGGRESSIVE BV05 /* Attacks PC's      */
#define ACT_STAY_AREA BV06  /* Won't leave area  */
#define ACT_WIMPY BV07      /* Flees when hurt   */
#define ACT_PET BV08        /* Auto set for pets */
#define ACT_TRAIN BV09      /* Can train PC's */
#define ACT_PRACTICE BV10   /* Can practice PC's */
#define ACT_IMMORTAL BV11   /* Cannot be killed  */
#define ACT_DEADLY BV12     /* Has a deadly poison  */
#define ACT_POLYSELF BV13
#define ACT_META_AGGR BV14   /* Extremely aggressive */
#define ACT_GUARDIAN BV15    /* Protects master   */
#define ACT_RUNNING BV16     /* Hunts quickly  */
#define ACT_NOWANDER BV17    /* Doesn't wander */
#define ACT_MOUNTABLE BV18   /* Can be mounted */
#define ACT_MOUNTED BV19     /* Is mounted     */
#define ACT_SCHOLAR BV20     /* Can teach languages  */
#define ACT_SECRETIVE BV21   /* actions aren't seen  */
#define ACT_POLYMORPHED BV22 /* Mob is a ch    */
#define ACT_MOBINVIS BV23    /* Like wizinvis  */
#define ACT_NOASSIST BV24    /* Doesn't assist mobs  */
#define ACT_NOKILL BV25      /* Mob can't die */
#define ACT_DROID BV26       /* mob is a droid */
#define ACT_NOCORPSE BV27
#define ACT_PUEBLO BV28    /* This is the pueblo flag */
#define ACT_PROTOTYPE BV30 /* A prototype mob   */

/* Act2 Flags */
#define ACT_BOUND BV00  /* This is the bind flag */
#define ACT_JEDI BV01   /* This is a light jedi */
#define ACT_SITH BV02   /* This is a dark jedi */
#define ACT_GAGGED BV03 /* This is a gagged flag */
/* 21 acts */

/* bits for vip flags */

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

/*
 * Bits for 'affected_by'.
 * Used in #MOBILES.
 */
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

/* 31 aff's (1 left.. :P) */
/* make that none - ugh - time for another field? :P */

/*
 * Resistant Immune Susceptible flags
...(truncated 86232 characters)...;
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

/*
 * mudprograms stuff
 */
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

#define OPROG_ACT_TRIGGER
#define RPROG_ACT_TRIGGER

#define GET_BETTED_ON(ch) ((ch)->betted_on)
#define GET_BET_AMT(ch) ((ch)->bet_amt)
#define IN_ARENA(ch) (IS_SET((ch)->in_room->room_flags2, ROOM_ARENA))

#define VCHECK_ROOM 0
#define VCHECK_OBJ 1
#define VCHECK_MOB 2

/*
 *  Defines for the command flags. --Shaddai
 */
#define CMD_POSSESS BV00
#define CMD_ACTION BV01  /* Samson 7-7-00 */
#define CMD_MUDPROG BV02 /* Command is only used by mudprogs. Prevents display on help/commands. Samson 11-26-03 */
#define CMD_NOFORCE BV03 /* Command can't be forced using either the force command or mpforce - Samson 3-3-04 */
#define CMD_OOC BV04
#define CMD_BUILD BV05
#define CMD_PLR_ONLY BV06
#define CMD_FULLNAME BV07 // You have to use the fullname of the command

#define IS_CMD_MPROG(cmd) (IS_SET((cmd)->flags, CMD_MUDPROG))
#define IS_CMDFLAG(cmd, flag) (IS_SET((cmd)->flags, (flag)))

/*
 * Data files used by the server.
 *
 * AREA_LIST contains a list of areas to boot.
 * All files are read in completely at bootup.
 * Most output files (bug, idea, typo, shutdown) are append-only.
 *
 */
#define PLAYER_DIR "../player/" /* Player files         */
#define BACKUP_DIR "../backup/" /* Backup Player files    */
#define GOD_DIR "../gods/"      /* God Info Dir         */
#define BOARD_DIR "../boards/"  /* Board data dir    */
#define CLAN_DIR "../clans/"    /* Clan data dir     */
#define SHIP_DIR "../space/"
#define SPACE_DIR "../space/"
#define SHIP_PROTOTYPE_DIR "../ships/"
#define FORCE_DIR "../force/"
#define FORCE_HELP_DIR "../force/help/"
#define PLANET_DIR "../planets/"
#define GUARD_DIR "../planets/"
#define GUILD_DIR "../guilds/"          /* Guild data dir               */
#define BUILD_DIR "../building/"        /* Online building save dir     */
#define SYSTEM_DIR "../system/"         /* Main system files    */
#define PROG_DIR "../mudprogs/"         /* MUDProg files     */
#define CORPSE_DIR "../corpses/"        /* Corpses        */
#define PROFILE_DIR "../html/profiles/" /* Player Profiles */
#define AREA_LIST "area.lst"            /* List of areas     */
#define BAN_LIST "ban.lst"              /* List of bans                 */
#define CLAN_LIST "clan.lst"            /* List of clans     */
#define SHIP_LIST "ship.lst"
#define PROTOTYPE_LIST "prototype.lst"
#define PLANET_LIST "planet.lst"
#define SPACE_LIST "space.lst"
#define BOUNTY_LIST "bounty.lst"
#define disintegration_LIST "disintegration.lst"
#define SENATE_LIST "senate.lst" /* List of senators     */
#define GUILD_LIST "guild.lst"   /* List of guilds               */
#define GUARD_LIST "guard.lst"
#define BOARD_FILE "boards.txt"      /* For bulletin boards   */
#define SHUTDOWN_FILE "shutdown.txt" /* For 'shutdown'  */
#define RIPSCREEN_FILE SYSTEM_DIR "mudrip.rip"
#define RIPTITLE_FILE SYSTEM_DIR "mudtitle.rip"
#define ANSITITLE_FILE SYSTEM_DIR "mudtitle.ans"
#define ASCTITLE_FILE SYSTEM_DIR "mudtitle.asc"
#define BOOTLOG_FILE SYSTEM_DIR "boot.txt"     /* Boot up error file  */
#define IDEA_FILE SYSTEM_DIR "ideas.txt"       /* For 'idea'       */
#define CHANGE_FILE SYSTEM_DIR "changes.txt"   /* Changes file - txt  */
#define CHANGEHTML_FILE "../html/changes.html" /* Changes file - html */
#define DEBUG_FILE SYSTEM_DIR "debug.txt"      /* Catch-all for debug */
#define TYPO_FILE SYSTEM_DIR "typos.txt"       /* For 'typo'       */
#define BUG_FILE SYSTEM_DIR "pbugs.txt"        /* For player bug command */
#define LOG_FILE SYSTEM_DIR "log.txt"          /* For talking in logged rooms */
#define WIZLIST_FILE SYSTEM_DIR "WIZLIST"      /* Wizlist       */
#define WEBWIZLIST_FILE "../html/WEBWIZLIST"   /* Web Wizlist    */
#define WHO_FILE SYSTEM_DIR "../html/WHO"      /* Who output file  */
#define WEBWHO_FILE "../html/WEBWHO"           /* Web Who File   */
#define REQUEST_PIPE SYSTEM_DIR "REQUESTS"     /* Request FIFO  */
#define SKILL_FILE SYSTEM_DIR "skills.dat"     /* Skill table   */
#define HERB_FILE SYSTEM_DIR "herbs.dat"       /* Herb table       */
#define SOCIAL_FILE SYSTEM_DIR "socials.dat"   /* Socials       */
#define COMMAND_FILE SYSTEM_DIR "commands.dat" /* Commands      */
#define NAMEBAN_FILE SYSTEM_DIR "nameban.dat"  /* Nameban       */
#define USAGE_FILE SYSTEM_DIR "usage.txt"      /* How many people are on      \
                                                * every half hour - trying to \
                                                * determine best reboot time */
#define TEMP_FILE SYSTEM_DIR "charsave.tmp"    /* More char save protect */
#define SLOG_FILE "../.slog/slog.txt"          /* Secret Log       */

/*
 * Mob program structures
 */

/* Mob program structures and defines */
/* Moved these defines here from mud_prog.c as I need them -rkb */
#define MAX_IFS 20 /* should always be generous */
#define IN_IF 0
#define IN_ELSE 1
#define DO_IF 2
#define DO_ELSE 3

#define MAX_PROG_NEST 20

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
   // 0         1            2           3          4            5
   B_NONE,
   SINGLE_LASER,
   DUAL_LASER,
   TRI_LASER,
   QUAD_LASER,
   AUTOBLASTER,

   //   6           7           8            9
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

#define LASER_DAMAGED -1
#define LASER_READY 0

#define PLANET_NOCAPTURE BV00

#define MAX_TRADE 5

#define MAX_FIX 3
#define SHOP_FIX 1
#define SHOP_RECHARGE 2

#endif // MUD_CONSTANTS_HPP