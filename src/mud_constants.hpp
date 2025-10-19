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
