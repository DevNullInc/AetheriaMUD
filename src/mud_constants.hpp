#define CODENAME "AetheriaMUD"
#define CODEVERSION "1.0.0"

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

// Macro for safe fclose
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
// 32 USED! DO NOT ADD MORE! SB

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

#define MAX_FORCE_SKILL 24

#define MAX_FORCE_ALIGN 100
#define MIN_FORCE_ALIGN -100

/* Echo types for echo_to_all */
#define ECHOTAR_ALL 0
#define ECHOTAR_PC 1
#define ECHOTAR_IMM 2

/* defines for new do_who */
#define WT_MORTAL 0
#define WT_IMM 2
#define WT_AVATAR 1
#define WT_NEWBIE 3

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

/*
 * Shop types.
 */
#define MAX_TRADE 5

#define MAX_FIX 3
#define SHOP_FIX 1
#define SHOP_RECHARGE 2

/* Mob program structures and defines */
/* Moved these defines here from mud_prog.c as I need them -rkb */
#define MAX_IFS 20 /* should always be generous */
#define IN_IF 0
#define IN_ELSE 1
#define DO_IF 2
#define DO_ELSE 3

#define MAX_PROG_NEST 20

#define LASER_DAMAGED -1
#define LASER_READY 0

#define PLANET_NOCAPTURE BV00

/***************************************************************************
 *                                                                         *
 *                   VALUES OF INTEREST TO AREA BUILDERS                   *
 *                   (Start of section ... start here)                     *
 *                                                                         *
 ***************************************************************************/

/*
 * Well known mob virtual numbers.
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
