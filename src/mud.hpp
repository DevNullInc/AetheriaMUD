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

#pragma once

#include <stdlib.h>
#include <limits.h>
#include <sys/cdefs.h>
#include <sys/time.h>
#include <math.h>
#ifdef __cplusplus
#include <typeinfo>
#endif
#include "mud_constants.hpp"

using namespace std;

#define CODENAME "SWFotEFUSS"
#define CODEVERSION "1.5.3"

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

// Include all the new header files
#include "mud_types.hpp"
#include "mud_macros.hpp"
#include "mud_constants.hpp"
#include "mud_flags.hpp"
#include "mud_structs.hpp"
#include "player.hpp"
#include "mud_functions.hpp"

#include "dns.hpp"
#include "pfiles.hpp"
#include "color.hpp"
#include "hotboot.hpp"

// Utility macros.
int umin(int check, int ncheck);
int umax(int check, int ncheck);
int urange(int mincheck, int check, int maxcheck);

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

/*
 * Memory allocation macros.
 */
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

#if defined(__FreeBSD__)
#define DISPOSE(point)          \
   do                           \
   {                            \
      if ((point))              \
      {                         \
         free((void *)(point)); \
         (point) = NULL;        \
      }                         \
   } while (0)
#else
#define DISPOSE(point)                                                                                \
   do                                                                                                 \
   {                                                                                                  \
      if ((point))                                                                                    \
      {                                                                                               \
         if (typeid((point)) == typeid(char *) || typeid((point)) == typeid(const char *))            \
         {                                                                                            \
            if (in_hash_table((char *)(point)))                                                       \
            {                                                                                         \
               log_printf("&RDISPOSE called on STRALLOC pointer: %s, line %d\n", __FILE__, __LINE__); \
               log_string("Attempting to correct.");                                                  \
               if (str_free((char *)(point)) == -1)                                                   \
                  log_printf("&RSTRFREEing bad pointer: %s, line %d\n", __FILE__, __LINE__);          \
            }                                                                                         \
            else                                                                                      \
               free((void *)(point));                                                                 \
         }                                                                                            \
         else                                                                                         \
            free((void *)(point));                                                                    \
         (point) = NULL;                                                                              \
      }                                                                                               \
      else                                                                                            \
         (point) = NULL;                                                                              \
   } while (0)
#endif

#define STRALLOC(point) str_alloc((point))
#define QUICKLINK(point) quick_link((point))
#if defined(__FreeBSD__)
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
#else
#define STRFREE(point)                                                                           \
   do                                                                                            \
   {                                                                                             \
      if ((point))                                                                               \
      {                                                                                          \
         if (!in_hash_table((point)))                                                            \
         {                                                                                       \
            log_printf("&RSTRFREE called on strdup pointer: %s, line %d\n", __FILE__, __LINE__); \
            log_string("Attempting to correct.");                                                \
            free((void *)(point));                                                               \
         }                                                                                       \
         else if (str_free((point)) == -1)                                                       \
            log_printf("&RSTRFREEing bad pointer: %s, line %d\n", __FILE__, __LINE__);           \
         (point) = NULL;                                                                         \
      }                                                                                          \
      else                                                                                       \
         (point) = NULL;                                                                         \
   } while (0)
#endif

/* double-linked list handling macros -Thoric */
/* Updated by Scion 8/6/1999 */
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

#define CHECK_LINKS(first, last, next, prev, type)                         \
   do                                                                      \
   {                                                                       \
      type *ptr, *pptr = NULL;                                             \
      if (!(first) && !(last))                                             \
         break;                                                            \
      if (!(first))                                                        \
      {                                                                    \
         bug("%s: CHECK_LINKS: last with NULL first!  %s.",                \
             __func__, __STRING(first));                                   \
         for (ptr = (last); ptr->prev; ptr = ptr->prev)                    \
            ;                                                              \
         (first) = ptr;                                                    \
      }                                                                    \
      else if (!(last))                                                    \
      {                                                                    \
         bug("%s: CHECK_LINKS: first with NULL last!  %s.",                \
             __func__, __STRING(first));                                   \
         for (ptr = (first); ptr->next; ptr = ptr->next)                   \
            ;                                                              \
         (last) = ptr;                                                     \
      }                                                                    \
      if ((first))                                                         \
      {                                                                    \
         for (ptr = (first); ptr; ptr = ptr->next)                         \
         {                                                                 \
            if (ptr->prev != pptr)                                         \
            {                                                              \
               bug("%s: CHECK_LINKS(%s): %p:->prev != %p.  Fixing.",       \
                   __func__, __STRING(first), ptr, pptr);                  \
               ptr->prev = pptr;                                           \
            }                                                              \
            if (ptr->prev && ptr->prev->next != ptr)                       \
            {                                                              \
               bug("%s: CHECK_LINKS(%s): %p:->prev->next != %p.  Fixing.", \
                   __func__, __STRING(first), ptr, ptr);                   \
               ptr->prev->next = ptr;                                      \
            }                                                              \
            pptr = ptr;                                                    \
         }                                                                 \
         pptr = NULL;                                                      \
      }                                                                    \
      if ((last))                                                          \
      {                                                                    \
         for (ptr = (last); ptr; ptr = ptr->prev)                          \
         {                                                                 \
            if (ptr->next != pptr)                                         \
            {                                                              \
               bug("%s: CHECK_LINKS (%s): %p:->next != %p.  Fixing.",      \
                   __func__, __STRING(first), ptr, pptr);                  \
               ptr->next = pptr;                                           \
            }                                                              \
            if (ptr->next && ptr->next->prev != ptr)                       \
            {                                                              \
               bug("%s: CHECK_LINKS(%s): %p:->next->prev != %p.  Fixing.", \
                   __func__, __STRING(first), ptr, ptr);                   \
               ptr->next->prev = ptr;                                      \
            }                                                              \
            pptr = ptr;                                                    \
         }                                                                 \
      }                                                                    \
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

/*
 * Character macros.
 */
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

#define IS_OUTSIDE(ch) (!IS_SET(                       \
                            (ch)->in_room->room_flags, \
                            ROOM_INDOORS) &&           \
                        !IS_SET(                       \
                            (ch)->in_room->room_flags, \
                            ROOM_SPACECRAFT))

#define IS_DRUNK(ch, drunk) (number_percent() < \
                             ((ch)->pcdata->condition[COND_DRUNK] * 2 / (drunk)))

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

/* Retired and guest imms. */
#define IS_RETIRED(ch) (ch->pcdata && IS_SET(ch->pcdata->flags, PCFLAG_RETIRED))
#define IS_GUEST(ch) (ch->pcdata && IS_SET(ch->pcdata->flags, PCFLAG_GUEST))

/* RIS by gsn lookups. -- Altrag.
   Will need to add some || stuff for spells that need a special GSN. */

#define IS_FIRE(dt) (IS_VALID_SN(dt) && \
                     SPELL_DAMAGE(skill_table[(dt)]) == SD_FIRE)
#define IS_COLD(dt) (IS_VALID_SN(dt) && \
                     SPELL_DAMAGE(skill_table[(dt)]) == SD_COLD)
#define IS_ACID(dt) (IS_VALID_SN(dt) && \
                     SPELL_DAMAGE(skill_table[(dt)]) == SD_ACID)
#define IS_ELECTRICITY(dt) (IS_VALID_SN(dt) && \
                            SPELL_DAMAGE(skill_table[(dt)]) == SD_ELECTRICITY)
#define IS_ENERGY(dt) (IS_VALID_SN(dt) && \
                       SPELL_DAMAGE(skill_table[(dt)]) == SD_ENERGY)

#define IS_DRAIN(dt) (IS_VALID_SN(dt) && \
                      SPELL_DAMAGE(skill_table[(dt)]) == SD_DRAIN)

#define IS_POISON(dt) (IS_VALID_SN(dt) && \
                       SPELL_DAMAGE(skill_table[(dt)]) == SD_POISON)

#define NOT_AUTHED(ch) (!IS_NPC(ch) && ch->pcdata->auth_state <= 3 && IS_SET(ch->pcdata->flags, PCFLAG_UNAUTHED))

#define HAS_SLUG(ch) (!IS_NPC(ch) && IS_SET(ch->pcdata->flags, \
                                            PCFLAG_HASSLUG))
#define IS_WAITING_FOR_AUTH(ch) (!IS_NPC(ch) && ch->desc && ch->pcdata->auth_state == 1 && IS_SET(ch->pcdata->flags, PCFLAG_UNAUTHED))

/*
 * Object macros.
 */
#define CAN_WEAR(obj, part) (IS_SET((obj)->wear_flags, (part)))
#define IS_OBJ_STAT(obj, stat) (IS_SET((obj)->extra_flags, (stat)))

#define log_string(txt) (log_string_plus((txt), LOG_NORMAL, LEVEL_LOG))

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
 * defines for use with this get_affect function
 */
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
extern CHAR_DATA *supermob;
extern OBJ_DATA *supermob_obj;

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

#define GET_BETTED_ON(ch) ((ch)->betted_on)
#define GET_BET_AMT(ch) ((ch)->bet_amt)
#define IN_ARENA(ch) (IS_SET((ch)->in_room->room_flags2, ROOM_ARENA))

#define VCHECK_ROOM 0
#define VCHECK_OBJ 1
#define VCHECK_MOB 2

/*
 * Defines for the command flags. --Shaddai
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
extern bool DONT_UPPER;
