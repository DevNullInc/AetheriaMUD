#ifndef MUD_MACROS_HPP
#define MUD_MACROS_HPP
#pragma once
#include "mud.hpp"

#define CODENAME "AetheriaMUD"
#define CODEVERSION "1.1.1"

// Backward compatibility for snippets and such.
#define mudstrlcpy strlcpy
#define mudstrlcat strlcat
#define str_dup strdup

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

#define HAS_SPELL_INDEX -1

#define AREA_VERSION_WRITE 1

#define MAX_FORCE_SKILL 24

#define MAX_FORCE_ALIGN 100
#define MIN_FORCE_ALIGN -100

#define MAX_KEY_HASH 2048
#define MAX_STRING_LENGTH 4096 /* buf */
#define MAX_INPUT_LENGTH 1024  /* arg */
#define MAX_INBUF_SIZE 1024

#define MSL MAX_STRING_LENGTH
#define MIL MAX_INPUT_LENGTH

#define HASHSTR /* use string hashing */

#define MAX_LAYERS 8 /* maximum clothing layers */
#define MAX_NEST 100 /* maximum container nesting */

#define MAX_KILLTRACK 20 /* track mob vnums killed */

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

#define TO_ROOM 0
#define TO_NOTVICT 1
#define TO_VICT 2
#define TO_CHAR 3
#define TO_MUD 4

#define INIT_WEAPON_CONDITION 12
#define MAX_ITEM_IMPACT 30

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

#define ACT_BOUND BV00  /* This is the bind flag */
#define ACT_JEDI BV01   /* This is a light jedi */
#define ACT_SITH BV02   /* This is a dark jedi */
#define ACT_GAGGED BV03 /* This is a gagged flag */

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

#define MAX_IFS 20 /* should always be generous */
#define IN_IF 0
#define IN_ELSE 1
#define DO_IF 2
#define DO_ELSE 3

#define MAX_PROG_NEST 20

#define MAX_TRADE 5

#define MAX_FIX 3
#define SHOP_FIX 1
#define SHOP_RECHARGE 2

#define PLANET_NOCAPTURE BV00

#define B_NONE 0
#define SINGLE_LASER 1
#define DUAL_LASER 2
#define TRI_LASER 3
#define QUAD_LASER 4
#define AUTOBLASTER 5

#define HEAVY_LASER 6
#define LIGHT_ION 7
#define REPEATING_ION 8
#define HEAVY_ION 9

#define LASER_DAMAGED -1
#define LASER_READY 0

#define PERS( ch, looker ) ( can_see( (looker), (ch) ) ?				\
				( IS_NPC(ch) ? (ch)->short_descr			\
				: (ch)->name ) : someone )

#define log_string( str )	log_string_plus( (str), LOG_NORMAL, LEVEL_LOG )

/*
 *  Globals.
 */
#define MAX_VNUMS (200000) /* max vnum */
#define MAX_INTERFACE 6

#define BOARD_PROMPT		"board> "

#define DEFAULT_MORPH_VNUM 10

#define PERS( ch, looker ) ( can_see( (looker), (ch) ) ?				\
				( IS_NPC(ch) ? (ch)->short_descr			\
				: (ch)->name ) : someone )

#define log_string( str )	log_string_plus( (str), LOG_NORMAL, LEVEL_LOG )

/* imm_host structure */
#define MAX_NAME_LENGTH 128
#define MAX_HOST_LENGTH 128

#define MAX_TOPICNAME		30
#define MAX_POSTTIME		20
#define MAX_BOARDNAME		30
#define BOARDS_VERSION		1

#define MAX_IFS			20		/* should always be generous */
#define IN_IF			0
#define IN_ELSE			1
#define DO_IF			2
#define DO_ELSE			3

#define MAX_PROG_NEST		20

#define MAX_MSGS		200	/* max # of messages posted to a channel */

#define MAX_PC_RACE		26
#define MAX_NPC_RACE		91
#define MAX_LEVEL		105
#define	LEVEL_AVATAR		(MAX_LEVEL - 15 )
#define LEVEL_IMMORTAL		(MAX_LEVEL - 14 )

#define MAX_CLAN		50
#define MAX_PLANET		255
#define MAX_SHIP		1000
#define MAX_BOUNTY		255
#define MAX_GOV 		255

#define	MAX_HERB		20

#define MAX_LAYER		8	/* maximum clothing layers */
#define MAX_TRIG		16	/* maximum room triggers   */