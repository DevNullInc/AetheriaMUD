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

#define CODENAME "AetheriaMUD"
#define CODEVERSION "1.24b"

// Backward compatibility for snippets and such.
#define mudstrlcpy strlcpy
#define mudstrlcat strlcat
#define str_dup strdup

#ifdef __cplusplus
#define DECLARE_DO_FUN(fun) \
   extern "C"               \
   {                        \
      DO_FUN fun;           \
   }                        \
   DO_FUN fun##_mangled
#define DECLARE_SPEC_FUN(fun) \
   extern "C"                 \
   {                          \
      SPEC_FUN fun;           \
   }                          \
   SPEC_FUN fun##_mangled
#define DECLARE_SPELL_FUN(fun) \
   extern "C"                  \
   {                           \
      SPELL_FUN fun;           \
   }                           \
   SPELL_FUN fun##_mangled
#else
#define DECLARE_DO_FUN(fun) \
   DO_FUN fun;              \
   DO_FUN fun##_mangled
#define DECLARE_SPEC_FUN(fun) \
   SPEC_FUN fun;              \
   SPEC_FUN fun##_mangled
#define DECLARE_SPELL_FUN(fun) \
   SPELL_FUN fun;              \
   SPELL_FUN fun##_mangled
#endif

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
#define MAX_FORCE_SKILL 24
#define MAX_FORCE_ALIGN 100
#define MIN_FORCE_ALIGN -100
#define MAX_TRADE 5
#define MAX_FIX 3
#define SHOP_FIX 1
#define SHOP_RECHARGE 2
#define MAX_IFS 20
#define IN_IF 0
#define IN_ELSE 1
#define DO_IF 2
#define DO_ELSE 3
#define MAX_PROG_NEST 20

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

#define OBJ_VNUM_DEED 67

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

#define ALL_BITS INT_MAX
#define SDAM_MASK ALL_BITS & ~(BV00 | BV01 | BV02)
#define SACT_MASK ALL_BITS & ~(BV03 | BV04 | BV05)
#define SCLA_MASK ALL_BITS & ~(BV06 | BV07 | BV08)
#define SPOW_MASK ALL_BITS & ~(BV09 | BV10)

#define MAX_TRAPTYPE TRAP_TYPE_SEX_CHANGE

#define OBJ_VNUM_MONEY_ONE 2
#define OBJ_VNUM_MONEY_SOME 3
#define COMMSYS_VNUM 62
#define DATAPAD_VNUM 63
#define MODULE_VNUM 73
#define SABER_VNUM 72
#define OBJ_VNUM_DROID_CORPSE 9
#define OBJ_VNUM_CORPSE_NPC 10
#define OBJ_VNUM_CORPSE_PC 11
#define OBJ_VNUM_SEVERED_HEAD 12
#define OBJ_VNUM_TORN_HEART 13
#define OBJ_VNUM_SLICED_ARM 14
#define OBJ_VNUM_SLICED_LEG 15
#define OBJ_VNUM_SPILLED_GUTS 16
#define OBJ_VNUM_BLOOD 17
#define OBJ_VNUM_BLOODSTAIN 18
#define OBJ_VNUM_SCRAPS 19
#define OBJ_VNUM_MUSHROOM 20
#define OBJ_VNUM_LIGHT_BALL 21
#define OBJ_VNUM_SPRING 22
#define OBJ_VNUM_SLICE 24
#define OBJ_VNUM_SHOPPING_BAG 25
#define OBJ_VNUM_FIRE 30
#define OBJ_VNUM_TRAP 31
#define OBJ_VNUM_PORTAL 32
#define OBJ_VNUM_BLACK_POWDER 33
#define OBJ_VNUM_SCROLL_SCRIBING 34
#define OBJ_VNUM_FLASK_BREWING 35
#define OBJ_VNUM_NOTE 36
#define OBJ_VNUM_SCHOOL_MACE 10315
#define OBJ_VNUM_SCHOOL_DAGGER 10312
#define OBJ_VNUM_SCHOOL_SWORD 10313
#define OBJ_VNUM_SCHOOL_VEST 10308
#define OBJ_VNUM_SCHOOL_SHIELD 10310
#define OBJ_VNUM_SCHOOL_BANNER 10311
#define OBJ_VNUM_SCHOOL_DIPLOMA 10321
#define OBJ_VNUM_BLASTECH_E11 50
#define OBJ_VNUM_SHIPBOMB 68
#define AFFECT_PRIMARY 1
#define AFFECT_SECONDARY 2
#define AFFECT_MISSILE 3
#define AFFECT_ROCKET 4
#define AFFECT_TORPEDO 5
#define AFFECT_HULL 6
#define AFFECT_SHIELD 7
#define AFFECT_SPEED 8
#define AFFECT_HYPER 9
#define AFFECT_ENERGY 10
#define AFFECT_MANUEVER 11
#define AFFECT_CHAFF 12
#define AFFECT_ALARM 13

#define MAX_ITEM_TYPE ITEM_EMP_GRENADE

#define REVERSE_APPLY 1000

#define ROOM_VNUM_LIMBO 2
#define ROOM_VNUM_POLY 3
#define ROOM_VNUM_CHAT 32144
#define ROOM_VNUM_TEMPLE 32144
#define ROOM_VNUM_ALTAR 32144
#define ROOM_VNUM_SCHOOL 115
#define ROOM_AUTH_START 10300
#define ROOM_START_HUMAN 211
#define ROOM_START_WOOKIEE 28600
#define ROOM_START_TWILEK 32148
#define ROOM_START_RODIAN 32148
#define ROOM_START_HUTT 32148
#define ROOM_START_MON_CALAMARIAN 21069
#define ROOM_START_NOGHRI 1015
#define ROOM_START_GAMORREAN 28100
#define ROOM_START_JAWA 31819
#define ROOM_START_ADARIAN 29000
#define ROOM_START_EWOK 32148
#define ROOM_START_VERPINE 32148
#define ROOM_START_DEFEL 32148
#define ROOM_START_TRANDOSHAN 32148
#define ROOM_START_HAPAN 32148
#define ROOM_START_DUINUOGWUIN 32148
#define ROOM_START_QUARREN 21069
#define ROOM_START_IMMORTAL 100
#define ROOM_LIMBO_SHIPYARD 45
#define ROOM_DEFAULT_CRASH 28025

#define ROOM_PLUOGUS_QUIT 905

#define ROOM_SHUTTLE_BUS 907   /* Sol */
#define ROOM_SHUTTLE_BUS_2 914 /* Monir */
#define ROOM_SHUTTLE_BUS_3 921 /* Fau */
#define ROOM_SHUTTLE_BUS_4 928 /* Taw */

#define ROOM_CORUSCANT_SHUTTLE 199
#define ROOM_SENATE_SHUTTLE 10197
#define ROOM_CORUSCANT_TURBOCAR 226

#define SHIP_AREA "shipvnum.are"

#define MAX_DIR DIR_SOUTHWEST    /* max for normal walking */
#define DIR_PORTAL DIR_SOMEWHERE /* portal direction    */
#define MAX_EXFLAG 26

#define TYPE_UNDEFINED -1
#define TYPE_MISSILE 111
#define TYPE_HIT 1000      /* allows for 1000 skills/spells */
#define TYPE_HERB 2000     /* allows for 1000 attack types  */
#define TYPE_PERSONAL 3000 /* allows for 1000 herb types    */

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

#define CD CHAR_DATA
#define MID MOB_INDEX_DATA
#define OD OBJ_DATA
#define OID OBJ_INDEX_DATA
#define RID ROOM_INDEX_DATA
#define SF SPEC_FUN
#define BD BOARD_DATA
#define CL CLAN_DATA
#define EDD EXTRA_DESCR_DATA
#define RD RESET_DATA
#define ED EXIT_DATA
#define ST SOCIALTYPE
#define DE DEITY_DATA
#define SK SKILLTYPE
#define SH SHIP_DATA

#define start_editing(ch, data) \
   start_editing_nolimit(ch, data, MAX_STRING_LENGTH)

#define OS_CARRY 0
#define OS_CORPSE 1

/* Utility macros */
#define UMIN(a, b) (umin((a), (b)))
#define UMAX(a, b) (umax((a), (b)))
#define URANGE(a, b, c) (urange((a), (b), (c)))
#define LOWER(c) ((c) >= 'A' && (c) <= 'Z' ? (c) + 'a' - 'A' : (c))
#define UPPER(c) ((c) >= 'a' && (c) <= 'z' ? (c) + 'A' - 'a' : (c))
#define IS_SET(flag, bit) ((flag) & (bit))
#define SET_BIT(var, bit) ((var) |= (bit))
#define REMOVE_BIT(var, bit) ((var) &= ~(bit))
#define TOGGLE_BIT(var, bit) ((var) ^= (bit))
#define CH(d) ((d)->original ? (d)->original : (d)->character)

/* Memory allocation and link-list macros */
#define CREATE(result, type, number)                                      \
   do                                                                     \
   {                                                                      \
      if (!((result) = (type *)calloc((number), sizeof(type))))           \
      {                                                                   \
         perror("malloc failure");                                        \
         fprintf(stderr, "Malloc failure @ %s:%d\n", __FILE__, __LINE__); \
         abort();                                                         \
      }                                                                   \
   } while (0)

#define RECREATE(result, type, number)                                      \
   do                                                                       \
   {                                                                        \
      if (!((result) = (type *)realloc((result), sizeof(type) * (number)))) \
      {                                                                     \
         perror("realloc failure");                                         \
         fprintf(stderr, "Realloc failure @ %s:%d\n", __FILE__, __LINE__);  \
         abort();                                                           \
      }                                                                     \
   } while (0)

#define DISPOSE(point)          \
   do                           \
   {                            \
      if ((point))              \
      {                         \
         free((void *)(point)); \
         (point) = NULL;        \
      }                         \
   } while (0)

#define STRALLOC(point) str_alloc((point))
#define QUICKLINK(point) quick_link((point))
#define STRFREE(point)                                                                      \
   do                                                                                       \
   {                                                                                        \
      if ((point))                                                                          \
      {                                                                                     \
         if (str_free((point)) == -1)                                                       \
            bug("%s: &RSTRFREEing bad pointer: %s, line %d", __func__, __FILE__, __LINE__); \
         (point) = NULL;                                                                    \
      }                                                                                     \
   } while (0)

#define LINK(link, first, last, next, prev) \
   do                                       \
   {                                        \
      if (!(first))                         \
      {                                     \
         (first) = (link);                  \
         (last) = (link);                   \
      }                                     \
      else                                  \
         (last)->next = (link);             \
      (link)->next = NULL;                  \
      if ((first) == (link))                \
         (link)->prev = NULL;               \
      else                                  \
         (link)->prev = (last);             \
      (last) = (link);                      \
   } while (0)

#define INSERT(link, insert, first, next, prev) \
   do                                           \
   {                                            \
      (link)->prev = (insert)->prev;            \
      if (!(insert)->prev)                      \
         (first) = (link);                      \
      else                                      \
         (insert)->prev->next = (link);         \
      (insert)->prev = (link);                  \
      (link)->next = (insert);                  \
   } while (0)

#define UNLINK(link, first, last, next, prev) \
   do                                         \
   {                                          \
      if (!(link)->prev)                      \
      {                                       \
         (first) = (link)->next;              \
         if ((first))                         \
            (first)->prev = NULL;             \
      }                                       \
      else                                    \
      {                                       \
         (link)->prev->next = (link)->next;   \
      }                                       \
      if (!(link)->next)                      \
      {                                       \
         (last) = (link)->prev;               \
         if ((last))                          \
            (last)->next = NULL;              \
      }                                       \
      else                                    \
      {                                       \
         (link)->next->prev = (link)->prev;   \
      }                                       \
   } while (0)

#define ASSIGN_GSN(gsn, skill)                                \
   do                                                         \
   {                                                          \
      if (((gsn) = skill_lookup((skill))) == -1)              \
         fprintf(stderr, "ASSIGN_GSN: Skill %s not found.\n", \
                 (skill));                                    \
   } while (0)

#define CHECK_SUBRESTRICTED(ch)                                                            \
   do                                                                                      \
   {                                                                                       \
      if ((ch)->substate == SUB_RESTRICTED)                                                \
      {                                                                                    \
         send_to_char("You cannot use this command from within another command.\r\n", ch); \
         return;                                                                           \
      }                                                                                    \
   } while (0)

/* Character and Object macros */
#define IS_NPC(ch) (IS_SET((ch)->act, ACT_IS_NPC))
#define IS_IMMORTAL(ch) (get_trust((ch)) >= LEVEL_IMMORTAL)
#define IS_DROID(ch) (ch->race == RACE_DROID || ch->race == RACE_PROTOCAL_DROID || ch->race == RACE_ASSASSIN_DROID || ch->race == RACE_GLADIATOR_DROID || ch->race == RACE_ASTROMECH_DROID || ch->race == RACE_INTERROGATION_DROID)
#define IS_HERO(ch) (get_trust((ch)) >= LEVEL_HERO)
#define IS_AFFECTED(ch, sn) (IS_SET((ch)->affected_by, (sn)))
#define HAS_BODYPART(ch, part) ((ch)->xflags == 0 || IS_SET((ch)->xflags, (part)))
#define IS_GOOD(ch) ((ch)->alignment >= 350)
#define IS_EVIL(ch) ((ch)->alignment <= -350)
#define IS_NEUTRAL(ch) (!IS_GOOD(ch) && !IS_EVIL(ch))
#define IS_AWAKE(ch) ((ch)->position > POS_SLEEPING)
#define GET_AC(ch) ((ch)->armor + (IS_AWAKE(ch) ? dex_app[get_curr_dex(ch)].defensive : 0) - ((ch)->race == RACE_DEFEL ? (ch)->skill_level[COMBAT_ABILITY] * 7 + 5 : (ch)->skill_level[COMBAT_ABILITY] / 2))
#define GET_HITROLL(ch) ((ch)->hitroll + str_app[get_curr_str(ch)].tohit + (2 - (abs((ch)->mental_state) / 10)))
#define GET_DAMROLL(ch) ((ch)->damroll + str_app[get_curr_str(ch)].todam + (((ch)->mental_state > 5 && (ch)->mental_state < 15) ? 1 : 0))
#define IS_OUTSIDE(ch) (!IS_SET((ch)->in_room->room_flags, ROOM_INDOORS) && !IS_SET((ch)->in_room->room_flags, ROOM_SPACECRAFT))
#define IS_DRUNK(ch, drunk) (number_percent() < ((ch)->pcdata->condition[COND_DRUNK] * 2 / (drunk)))
#define IS_CLANNED(ch) (!IS_NPC((ch)) && (ch)->pcdata->clan)
#define WAIT_STATE(ch, npulse) ((ch)->wait = UMAX((ch)->wait, (npulse)))
#define EXIT(ch, door) (get_exit((ch)->in_room, door))
#define CAN_GO(ch, door) (EXIT((ch), (door)) && (EXIT((ch), (door))->to_room != NULL) && !IS_SET(EXIT((ch), (door))->exit_info, EX_CLOSED))
#define IS_VALID_SN(sn) ((sn) >= 0 && (sn) < MAX_SKILL && skill_table[(sn)] && skill_table[(sn)]->name)
#define IS_VALID_HERB(sn) ((sn) >= 0 && (sn) < MAX_HERB && herb_table[(sn)] && herb_table[(sn)]->name)
#define SPELL_FLAG(skill, flag) (IS_SET((skill)->flags, (flag)))
#define SPELL_DAMAGE(skill) (((skill)->flags) & 7)
#define SPELL_ACTION(skill) (((skill)->flags >> 3) & 7)
#define SPELL_CLASS(skill) (((skill)->flags >> 6) & 7)
#define SPELL_POWER(skill) (((skill)->flags >> 9) & 3)
#define SET_SDAM(skill, val) ((skill)->flags = ((skill)->flags & SDAM_MASK) + ((val) & 7))
#define SET_SACT(skill, val) ((skill)->flags = ((skill)->flags & SACT_MASK) + (((val) & 7) << 3))
#define SET_SCLA(skill, val) ((skill)->flags = ((skill)->flags & SCLA_MASK) + (((val) & 7) << 6))
#define SET_SPOW(skill, val) ((skill)->flags = ((skill)->flags & SPOW_MASK) + (((val) & 3) << 9))
#define IS_RETIRED(ch) (ch->pcdata && IS_SET(ch->pcdata->flags, PCFLAG_RETIRED))
#define IS_GUEST(ch) (ch->pcdata && IS_SET(ch->pcdata->flags, PCFLAG_GUEST))
#define IS_FIRE(dt) (IS_VALID_SN(dt) && SPELL_DAMAGE(skill_table[(dt)]) == SD_FIRE)
#define IS_COLD(dt) (IS_VALID_SN(dt) && SPELL_DAMAGE(skill_table[(dt)]) == SD_COLD)
#define IS_ACID(dt) (IS_VALID_SN(dt) && SPELL_DAMAGE(skill_table[(dt)]) == SD_ACID)
#define IS_ELECTRICITY(dt) (IS_VALID_SN(dt) && SPELL_DAMAGE(skill_table[(dt)]) == SD_ELECTRICITY)
#define IS_ENERGY(dt) (IS_VALID_SN(dt) && SPELL_DAMAGE(skill_table[(dt)]) == SD_ENERGY)
#define IS_DRAIN(dt) (IS_VALID_SN(dt) && SPELL_DAMAGE(skill_table[(dt)]) == SD_DRAIN)
#define IS_POISON(dt) (IS_VALID_SN(dt) && SPELL_DAMAGE(skill_table[(dt)]) == SD_POISON)
#define NOT_AUTHED(ch) (!IS_NPC(ch) && ch->pcdata->auth_state <= 3 && IS_SET(ch->pcdata->flags, PCFLAG_UNAUTHED))
#define HAS_SLUG(ch) (!IS_NPC(ch) && IS_SET(ch->pcdata->flags, PCFLAG_HASSLUG))
#define IS_WAITING_FOR_AUTH(ch) (!IS_NPC(ch) && ch->desc && ch->pcdata->auth_state == 1 && IS_SET(ch->pcdata->flags, PCFLAG_UNAUTHED))
#define CAN_WEAR(obj, part) (IS_SET((obj)->wear_flags, (part)))
#define IS_OBJ_STAT(obj, stat) (IS_SET((obj)->extra_flags, (stat)))
#define log_string(txt) (log_string_plus((txt), LOG_NORMAL, LEVEL_LOG))
#define GET_BETTED_ON(ch) ((ch)->betted_on)
#define GET_BET_AMT(ch) ((ch)->bet_amt)
#define IN_ARENA(ch) (IS_SET((ch)->in_room->room_flags2, ROOM_ARENA))
#define VCHECK_ROOM 0
#define VCHECK_OBJ 1
#define VCHECK_MOB 2

/*
 * Liquids.
 */
#define LIQ_WATER 0
#define LIQ_MAX 19

/* Macros for accessing strings in player files */
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
