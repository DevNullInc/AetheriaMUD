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
 *********************************************************************************************************************************
 *                                                                                                                               *
 *                                             SmaugFUSS 1.9 copyright (c) 2009 by Roger Libiez                                  *
 *                                                                                                                               *
 *                                             (Samson) Als far as I know, the only original code is the stuff I wrote.        *
 *                                                                                                                               *
 *                                             But if I'm wrong and anything here is original Smaug code, then Thoric and     *
 *                                                                                                                               *
 *                                             the other Smaug coders naturally reserve their rights to it.                  *
 *                                                                                                                               *
 *********************************************************************************************************************************/
#ifndef MUD_FLAGS_HPP
#define MUD_FLAGS_HPP

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
#define RIS_MENTAL BV22
#define RIS_HOLY BV23
#define RIS_ORDER BV24
#define RIS_CHAOS BV25
#define RIS_NEGATIVE BV26
#define RIS_DROWNING BV27
/* RIS_s */

#define RIS_000 BV00
#define RIS_R00 BV01
#define RIS_0I0 BV02
#define RIS_RI0 BV03
#define RIS_00S BV04
#define RIS_R0S BV05
#define RIS_0IS BV06
#define RIS_RIS BV07

/*
 * Attack types
 */
#define ATCK_BITE BV00
#define ATCK_CLAWS BV01
#define ATCK_TAIL BV02
#define ATCK_STING BV03
#define ATCK_PUNCH BV04
#define ATCK_KICK BV05
#define ATCK_TRIP BV06
#define ATCK_BASH BV07
#define ATCK_STUN BV08
#define ATCK_GOUGE BV09
#define ATCK_BACKSTAB BV10
#define ATCK_FORCE BV11
#define ATCK_SHOOT BV12
#define ATCK_HIT BV13

/*
 * Defense types
 */
#define DFND_PARRY BV00
#define DFND_DODGE BV01
#define DFND_GRIP BV02
#define DFND_SHIELD BV03
#define DFND_DISARM BV04

/*
 * Body parts
 */
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
/* for combat */
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
#define PART_HUSK_SHELL BV30

/*
 * Autosave flags
 */
#define SV_DEATH BV00  /* auto after death */
#define SV_KILL BV01   /* auto after pk death */
#define SV_TIME BV02   /* auto on the hour */
#define SV_AUTO BV03   /* auto flag toggle */
#define SV_DROP BV04   /* auto after drop */
#define SV_PUT BV05    /* auto after put */
#define SV_AUCTION BV06  /* auto after auction */
#define SV_AUTO BV07   /* auto flag toggle */
#define SV_IDLE BV08   /* auto on idle */
#define SV_BACKUP BV09 /* backup on death */

/*
 * Pipe flags
 */
#define PIPE_TAMPED BV01
#define PIPE_LIT BV02
#define PIPE_HOT BV03
#define PIPE_DIRTY BV04
#define PIPE_FILTHY BV05
#define PIPE_GOINGOUT BV06
#define PIPE_BURNT BV07
#define PIPE_FULLOFASH BV08

/*
 * Flags for MUD rooms -- Shaddai
 */
#define ROOM_R1 BV00
#define ROOM_DARK BV00
#define ROOM_DEATH BV01
#define ROOM_NO_MOB BV02
#define ROOM_INDOORS BV03
#define ROOM_LAWFUL BV04
#define ROOM_NEUTRAL BV05
#define ROOM_CHAOTIC BV06
#define ROOM_NO_MAGIC BV07
#define ROOM_TUNNEL BV08
#define ROOM_PRIVATE BV09
#define ROOM_SAFE BV10
#define ROOM_SOLITARY BV11
#define ROOM_PET_SHOP BV12
#define ROOM_NO_RECALL BV13
#define ROOM_DONATION BV14
#define ROOM_NODROP BV15
#define ROOM_SILENCE BV16
#define ROOM_LOGSPEECH BV17
#define ROOM_NODROPALL BV18
#define ROOM_TELEPORT BV19
#define ROOM_CLANSTOREROOM BV20
#define ROOM_NO_DRIVING BV21
#define ROOM_NO_ASTRAL BV22
#define ROOM_AUCTION BV23
#define ROOM_NO_SUPPLICATE BV24
#define ROOM_ARENA BV25
#define ROOM_R6 BV26
#define ROOM_R7 BV27
#define ROOM_R8 BV28
#define ROOM_R9 BV29
#define ROOM_R10 BV30
#define ROOM_R11 BV31

/*
 * Flags for mud areas -- Shaddai
 */
#define AFLAG_NOPKILL BV00
#define AFLAG_FREEKILL BV01
#define AFLAG_NOTELEPORT BV02
#define AFLAG_SPELLLIMIT BV03
#define AFLAG_HIDDEN BV04
#define AFLAG_NOMAP BV05

/*
 * Sector types
 */
#define SECT_INSIDE 0
#define SECT_CITY 1
#define SECT_FIELD 2
#define SECT_FOREST 3
#define SECT_HILLS 4
#define SECT_MOUNTAIN 5
#define SECT_WATER_SWIM 6
#define SECT_WATER_NOSWIM 7
#define SECT_UNDERWATER 8
#define SECT_AIR 9
#define SECT_DESERT 10
#define SECT_DUNNO 11
#define SECT_OCEANFLOOR 12
#define SECT_UNDERGROUND 13
#define SECT_SCRUB 14
#define SECT_ROCKY 15
#define SECT_SAVANNA 16
#define SECT_TUNDRA 17
#define SECT_GLACIER 18
#define SECT_OCEAN 19
#define SECT_LAVA 20
#define SECT_SWAMP 21
#define SECT_MAX 22

/*
 * Equipment wear locations.
 * Used in #RESETS.
 */
#define WEAR_NONE -1
#define WEAR_LIGHT 0
#define WEAR_FINGER_L 1
#define WEAR_FINGER_R 2
#define WEAR_NECK_1 3
#define WEAR_NECK_2 4
#define WEAR_BODY 5
#define WEAR_HEAD 6
#define WEAR_LEGS 7
#define WEAR_FEET 8
#define WEAR_HANDS 9
#define WEAR_ARMS 10
#define WEAR_SHIELD 11
#define WEAR_ABOUT 12
#define WEAR_WAIST 13
#define WEAR_WRIST_L 14
#define WEAR_WRIST_R 15
#define WEAR_WIELD 16
#define WEAR_DUAL_WIELD 17
#define WEAR_HOLD 18
#define WEAR_MISSILE_WIELD 19
#define WEAR_EARS 20
#define WEAR_EYES 21
#define WEAR_BADGE 22
#define WEAR_NOSE 23
#define WEAR_FLOAT 24
#define WEAR_BACKPACK 25
#define WEAR_BELT1 26
#define WEAR_BELT2 27
#define WEAR_BELT3 28
#define WEAR_BELT4 29
#define WEAR_BELT5 30
#define WEAR_BELT6 31
#define WEAR_MAX 31

/*
 * Locations for damage.
 */
#define LOC_HEAD 0
#define LOC_LEGS 1
#define LOC_FEET 2
#define LOC_HANDS 3
#define LOC_ARMS 4
#define LOC_BODY 5
#define LOC_NONE 6

/* ***********************************************************************
 *  Values for the sector_type field (for rooms).
 *  Zero is for indoors, non-zero for outdoors.
 *************************************************************************
 */
#define SECT_INSIDE 0
#define SECT_CITY 1
#define SECT_FIELD 2
#define SECT_FOREST 3
#define SECT_HILLS 4
#define SECT_MOUNTAIN 5
#define SECT_WATER_SWIM 6
#define SECT_WATER_NOSWIM 7
#define SECT_UNDERWATER 8
#define SECT_AIR 9
#define SECT_DESERT 10
#define SECT_DUNNO 11
#define SECT_OCEANFLOOR 12
#define SECT_UNDERGROUND 13
#define SECT_SCRUB 14
#define SECT_ROCKY 15
#define SECT_SAVANNA 16
#define SECT_TUNDRA 17
#define SECT_GLACIER 18
#define SECT_OCEAN 19
#define SECT_LAVA 20
#define SECT_SWAMP 21
#define SECT_MAX 22

/*
 * Positions.
 */
#define POS_DEAD 0
#define POS_MORTAL 1
#define POS_INCAP 2
#define POS_STUNNED 3
#define POS_SLEEPING 4
#define POS_RESTING 5
#define POS_SITTING 6
#define POS_FIGHTING 7
#define POS_STANDING 8
#define POS_MOUNTED 9
#define POS_SHOVE 10
#define POS_DRAG 11

/*
 * Styles.
 */
#define STYLE_BERSERK 1
#define STYLE_AGGRESSIVE 2
#define STYLE_DEFENSIVE 3
#define STYLE_EVASIVE 4

/*
 * Channel bits.
 */
#define CHANNEL_AUCTION BV00
#define CHANNEL_CHAT BV01
#define CHANNEL_QUEST BV02
#define CHANNEL_IMMTALK BV03
#define CHANNEL_PRAY BV04
#define CHANNEL_MUSIC BV05
#define CHANNEL_ASK BV06
#define CHANNEL_SHOUT BV07
#define CHANNEL_YELL BV08
#define CHANNEL_MONITOR BV09
#define CHANNEL_NEWBIE BV10
#define CHANNEL_OOC BV11
#define CHANNEL_INFO BV12
#define CHANNEL_GOSSIP BV13
#define CHANNEL_CLAN BV14
#define CHANNEL_FLAME BV15
#define CHANNEL_TELL BV16
#define CHANNEL_GRATS BV17
#define CHANNEL_GUILD BV18
#define CHANNEL_PNET BV19
#define CHANNEL_WARTALK BV20
#define CHANNEL_TRAFFIC BV21
#define CHANNEL_RPLOG BV22
#define CHANNEL_ADVERTISE BV23
#define CHANNEL_ROLEPLAY BV24
#define CHANNEL_COMLOG BV25
#define CHANNEL_LOG BV26
#define CHANNEL_BUILD BV27
#define CHANNEL_COMM BV28
#define CHANNEL_WARN BV29

/* Area flags - Narn Mar/96 */
#define AFLAG_NOPKILL BV00
#define AFLAG_FREEKILL BV01
#define AFLAG_NOTELEPORT BV02
#define AFLAG_SPELLLIMIT BV03
#define AFLAG_HIDDEN BV04
#define AFLAG_NOMAP BV05

/*
 * Prototype for a mob.
 * This is the in-memory version of #MOBILES.
 */

#define AREA_DELETED BV00
#define AREA_LOADED BV01

/*
 * Skills include spells as a particular case.
 */

/* deity structure */

#define DEITY_DEVOTION BV00
#define DEITY_RACE BV01
#define DEITY_ELEMENT BV02
#define DEITY_CLASS BV03
#define DEITY_SEX BV04
#define DEITY_SCORP BV05
#define DEITY_NPCHOSTILE BV06
#define DEITY_NPCFOE BV07
#define DEITY_NPCRACE BV08

/*
 * Auction states for use in update.c
 */
#define AUCTION_MEM 0   /* Must have this -- for valids */
#define AUCTION_NONE 1  /* Nothing being auctioned */
#define AUCTION_START 2 /* Just started an auction */
#define AUCTION_ONCE 3  /* Once */
#define AUCTION_TWICE 4 /* Twice */
#define AUCTION_SOLD 5  /* Sold */

/* for changes */
#define CHANGE_CHANGED 1
#define CHANGE_ADDED 2
#define CHANGE_REMOVED 3

/* for clans */
#define CLAN_PLAIN 0
#define CLAN_CRIME 1
#define CLAN_GUILD 2
#define CLAN_SUBCLAN 3
#define CLAN_CORPORATION 4

/* for planets */
#define PLANET_NOCAPTURE BV00

/* for ships */
#define PLAYER_SHIP 0
#define MOB_SHIP 1
#define SHIP_IMPERIAL 2
#define SHIP_REPUBLIC 3

#define SHIP_DOCKED 1
#define SHIP_READY 2
#define SHIP_BUSY 3
#define SHIP_BUSY_2 4
#define SHIP_BUSY_3 5
#define SHIP_REFUEL 6
#define SHIP_LAUNCH 7
#define SHIP_LAUNCH_2 8
#define SHIP_LAND 9
#define SHIP_LAND_2 10
#define SHIP_HYPERSPACE 11
#define SHIP_DISABLED 12
#define SHIP_FLYING 13

#define MISSILE_READY 0
#define MISSILE_FIRED 1
#define MISSILE_RELOAD 2
#define MISSILE_RELOAD_2 3
#define MISSILE_DAMAGED -1

#define LAND_VEHICLE 0
#define SHIP_FIGHTER 1
#define SHIP_BOMBER 2
#define SHIP_SHUTTLE 3
#define SHIP_FREIGHTER 4
#define SHIP_FRIGATE 5
#define SHIP_TT 6
#define SHIP_CORVETTE 7
#define SHIP_CRUISER 8
#define SHIP_DREADNAUGHT 9
#define SHIP_DESTROYER 10
#define SHIP_SPACE_STATION 11

/* For weapons */
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
#define CONCUSSION_MISSILE 0
#define PROTON_TORPEDO 1
#define HEAVY_ROCKET 2
#define HEAVY_BOMB 3
#define LASER_DAMAGED -1
#define LASER_READY 0

/* for cargo */
#define CARGO_SPICE 0
#define CARGO_GEM 1
#define CARGO_NORMAL 2
#define CARGO_WEAPON 3
#define CARGO_ARMOR 4
#define CARGO_COMLINK 5
#define CARGO_DURASTEEL 6
#define CARGO_DURAPLAST 7
#define CARGO_CLOTHING 8
#define CARGO_REPAIR 9

/* for bounties */
#define BOUNTY_PLAYER 0
#define BOUNTY_CLAN 1

/* for blackmarket */
#define BLACKMARKET_LOCAL 0
#define BLACKMARKET_GLOBAL 1

/* for rooms */
#define ROOM_DARK BV00
#define ROOM_DEATH BV01
#define ROOM_NO_MOB BV02
#define ROOM_INDOORS BV03
#define ROOM_LAWFUL BV04
#define ROOM_NEUTRAL BV05
#define ROOM_CHAOTIC BV06
#define ROOM_NO_MAGIC BV07
#define ROOM_TUNNEL BV08
#define ROOM_PRIVATE BV09
#define ROOM_SAFE BV10
#define ROOM_SOLITARY BV11
#define ROOM_PET_SHOP BV12
#define ROOM_NO_RECALL BV13
#define ROOM_DONATION BV14
#define ROOM_NODROP BV15
#define ROOM_SILENCE BV16
#define ROOM_LOGSPEECH BV17
#define ROOM_NODROPALL BV18
#define ROOM_TELEPORT BV19
#define ROOM_CLANSTOREROOM BV20
#define ROOM_NO_DRIVING BV21
#define ROOM_NO_ASTRAL BV22
#define ROOM_AUCTION BV23
#define ROOM_NO_SUPPLICATE BV24
#define ROOM_ARENA BV25
#define ROOM_R6 BV26
#define ROOM_R7 BV27
#define ROOM_R8 BV28
#define ROOM_R9 BV29
#define ROOM_R10 BV30
#define ROOM_R11 BV31

/* for exits */
#define EX_ISDOOR BV00
#define EX_CLOSED BV01
#define EX_LOCKED BV02
#define EX_SECRET BV03
#define EX_PICKPROOF BV04
#define EX_FLY BV05
#define EX_CLIMB BV06
#define EX_DIG BV07
#define EX_EATKEY BV08
#define EX_NOPASSDOOR BV09
#define EX_HIDDEN BV10
#define EX_PASSAGE BV11
#define EX_PORTAL BV12
#define EX_RES1 BV13
#define EX_RES2 BV14
#define EX_xCLIMB BV15
#define EX_xENTER BV16
#define EX_xLEAVE BV17
#define EX_xSEARCHABLE BV18
#define EX_BASHED BV19
#define EX_BASHPROOF BV20
#define EX_NOMOB BV21
#define EX_WINDOW BV22
#define EX_xLOOK BV23
#define MAX_EXFLAG 23

/* for items */
#define ITEM_GLOW BV00
#define ITEM_HUM BV01
#define ITEM_DARK BV02
#define ITEM_LOCK BV03
#define ITEM_EVIL BV04
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
#define ITEM_ANTI_PILOT BV17
#define ITEM_SMALL_SIZE BV18
#define ITEM_LARGE_SIZE BV19
#define ITEM_DONATION BV20
#define ITEM_CLANOBJECT BV21
#define ITEM_ANTI_SITH BV22
#define ITEM_ANTI_JEDI BV23
#define ITEM_HIDDEN BV24
#define ITEM_POISONED BV25
#define ITEM_COVERING BV26
#define ITEM_DEATHROT BV27
#define ITEM_BURRIED BV28 /* item is burried */
#define ITEM_PROTOTYPE BV29
#define ITEM_NODISARM BV30
#define ITEM_NOPURGE BV31
#define ITEM_REPAIRABLE BV32
#define ITEM_UNBREAKABLE BV33

/* for containers */
#define CONT_CLOSEABLE BV01
#define CONT_PICKPROOF BV02
#define CONT_CLOSED BV03
#define CONT_LOCKED BV04

/* for liquids */
#define LIQ_WATER 0
#define LIQ_BEER 1
#define LIQ_WINE 2
#define LIQ_ALE 3
#define LIQ_DARKALE 4
#define LIQ_WHISKY 5
#define LIQ_LEMONADE 6
#define LIQ_FIREBRT 7
#define LIQ_LOCALSPC 8
#define LIQ_SLIME 9
#define LIQ_MILK 10
#define LIQ_TEA 11
#define LIQ_COFFE 12
#define LIQ_BLOOD 13
#define LIQ_SALTWATER 14
#define LIQ_CLEARWATER 15
#define LIQ_COKE 16
#define LIQ_ROOTBEER 17
#define LIQ_CHOCOMILK 18
#define LIQ_GRAPEJUICE 19
#define LIQ_ORANGEJUICE 20
#define LIQ_MOONSHINE 21
#define LIQ_VODKA 22
#define LIQ_CHAMPAGNE 23
#define LIQ_RTAVIS 24
#define LIQ_BLUEPUNCH 25
#define LIQ_FRUITPUNCH 26
#define LIQ_LEMONPUNCH 27
#define LIQ_LIMESLUSH 28
#define LIQ_CHERRYSODA 29
#define LIQ_SLIMEMOLDJUICE 30
#define LIQ_MAX 31

/* for apply types */
#define APPLY_NONE 0
#define APPLY_STR 1
#define APPLY_DEX 2
#define APPLY_INT 3
#define APPLY_WIS 4
#define APPLY_CON 5
#define APPLY_CHA 6
#define APPLY_LCK 7
#define APPLY_SEX 8
#define APPLY_CLASS 9
#define APPLY_LEVEL 10
#define APPLY_AGE 11
#define APPLY_HEIGHT 12
#define APPLY_WEIGHT 13
#define APPLY_MANA 14
#define APPLY_HIT 15
#define APPLY_MOVE 16
#define APPLY_GOLD 17
#define APPLY_EXP 18
#define APPLY_AC 19
#define APPLY_HITROLL 20
#define APPLY_DAMROLL 21
#define APPLY_SAVING_POISON 22
#define APPLY_SAVING_ROD 23
#define APPLY_SAVING_PARA 24
#define APPLY_SAVING_BREATH 25
#define APPLY_SAVING_SPELL 26
#define APPLY_AFFECT 27
#define APPLY_RESISTANT 28
#define APPLY_IMMUNE 29
#define APPLY_SUSCEPTIBLE 30
#define APPLY_WEAPONSPELL 31
#define APPLY_REMOVE 32
#define APPLY_FULL 33
#define APPLY_THIRST 34
#define APPLY_DRUNK 35
#define APPLY_BLOOD 36
#define APPLY_STRIPSN 37
#define APPLY_MENTALSTATE 38
#define APPLY_EMOTION 39
#define APPLY_CONTAGIOUS 40
#define APPLY_ODOR 41
#define APPLY_ROOMFLAG 42
#define APPLY_SECTORTYPE 43
#define APPLY_ROOMLIGHT 44
#define APPLY_TELEVNUM 45
#define APPLY_TELEDELAY 46
#define APPLY_ABSORB 47
#define APPLY_FRC 48
#define APPLY_SAVING_FORCE 49
#define APPLY_SAVING_FIRE 50
#define APPLY_SAVING_COLD 51
#define APPLY_SAVING_ENERGY 52
#define APPLY_SAVING_ACID 53
#define APPLY_SAVING_MAGIC 54
#define APPLY_SAVING_NONMAGIC 55
#define APPLY_SAVING_POISON 56
#define APPLY_SAVING_ILLUSION 57
#define APPLY_SAVING_MENTAL 58
#define APPLY_SAVING_PHYSICAL 59
#define APPLY_ATTACK 60
#define APPLY_DEFENSE 61
#define APPLY_CARRY_NUMBER 62
#define APPLY_CARRY_WEIGHT 63
#define APPLY_MAX_STR 64
#define APPLY_MAX_DEX 65
#define APPLY_MAX_INT 66
#define APPLY_MAX_WIS 67
#define APPLY_MAX_CON 68
#define APPLY_MAX_CHA 69
#define APPLY_MAX_LCK 70
#define APPLY_MAX_FRC 71
#define APPLY_ALL 72

/* for mobprogs */
#define MP_MOB BV00
#define MP_ROOM BV01
#define MP_OBJ BV02

/* for obj programs */
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

/* for roomprog */
#define OPROG_ACT_TRIGGER
#define RPROG_ACT_TRIGGER

/* for cmd flags */
#define CMD_POSSESS BV00
#define CMD_ACTION BV01  /* Samson 7-7-00 */
#define CMD_MUDPROG BV02 /* Command is only used by mudprogs. Prevents display on help/commands. Samson 11-26-03 */
#define CMD_NOFORCE BV03 /* Command can't be forced using either the force command or mpforce - Samson 3-3-04 */
#define CMD_OOC BV04
#define CMD_BUILD BV05
#define CMD_PLR_ONLY BV06
#define CMD_FULLNAME BV07 // You have to use the fullname of the command

#endif // MUD_FLAGS_HPP