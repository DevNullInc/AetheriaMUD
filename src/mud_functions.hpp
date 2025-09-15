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
 * It's very likely that the function signatures will depend on types
 * and structs defined in these other headers, so we should include them.
 */
#include "mud_types.hpp"
#include "mud_structs.hpp"

/*
 * Function prototypes.
 * * greet_trigger is defined in mob_cmds.c
 * I'm just putting it here for simplicity's sake - every file that needs it
 * can just include mud.hpp and not worry about it.
 */
bool greet_trigger(CHAR_DATA *ch);

/* Stuff from newarena.c */
void show_jack_pot(void);
void do_game(void);
int num_in_arena(void);
void find_game_winner(void);
void do_end_game(void);
void start_game(void);
void silent_end(void);
void write_fame_list(void);
void load_hall_of_fame(void);

/*
 * Command functions.
 * Defined in act_*.c (mostly).
 */
DECLARE_DO_FUN(do_buymobship);
DECLARE_DO_FUN(do_aaccept);
DECLARE_DO_FUN(do_ahall);
DECLARE_DO_FUN(do_arena);
DECLARE_DO_FUN(do_awho);
DECLARE_DO_FUN(do_bet);
DECLARE_DO_FUN(do_challenge);
DECLARE_DO_FUN(do_chaos);
DECLARE_DO_FUN(do_cut);
DECLARE_DO_FUN(do_adecline);
DECLARE_DO_FUN(do_setmssp);
DECLARE_DO_FUN(do_setplanet);
DECLARE_DO_FUN(do_setrank);
DECLARE_DO_FUN(do_setinfrared);
DECLARE_DO_FUN(do_makefree);
DECLARE_DO_FUN(do_makeplanet);
DECLARE_DO_FUN(do_makeprototypeship);
DECLARE_DO_FUN(do_planets);
DECLARE_DO_FUN(do_teach);
DECLARE_DO_FUN(do_gather_intelligence);
DECLARE_DO_FUN(do_generate_market);
DECLARE_DO_FUN(do_add_patrol);
DECLARE_DO_FUN(do_special_forces);
DECLARE_DO_FUN(do_jail);
DECLARE_DO_FUN(do_checkwar);
DECLARE_DO_FUN(do_elite_guard);
DECLARE_DO_FUN(do_smalltalk);
DECLARE_DO_FUN(do_propeganda);
DECLARE_DO_FUN(do_bribe);
DECLARE_DO_FUN(do_bind);
DECLARE_DO_FUN(do_seduce);
DECLARE_DO_FUN(do_mass_propeganda);
DECLARE_DO_FUN(do_copyship);
DECLARE_DO_FUN(do_sound);
DECLARE_DO_FUN(do_autopilot);
DECLARE_DO_FUN(do_allspeeders);
DECLARE_DO_FUN(do_speeders);
DECLARE_DO_FUN(do_suicide);
DECLARE_DO_FUN(do_gain);
DECLARE_DO_FUN(do_train);
DECLARE_DO_FUN(do_beg);
DECLARE_DO_FUN(do_bank);
DECLARE_DO_FUN(do_battle_command);
DECLARE_DO_FUN(do_hijack);
DECLARE_DO_FUN(do_pickshiplock);
DECLARE_DO_FUN(do_shipstat);
DECLARE_DO_FUN(do_shiptalk);
DECLARE_DO_FUN(do_clone);
DECLARE_DO_FUN(do_systemtalk);
DECLARE_DO_FUN(do_spacetalk);
DECLARE_DO_FUN(do_hail);
DECLARE_DO_FUN(do_allships);
DECLARE_DO_FUN(do_newclan);
DECLARE_DO_FUN(do_appoint);
DECLARE_DO_FUN(do_demote);
DECLARE_DO_FUN(do_empower);
DECLARE_DO_FUN(do_capture);
DECLARE_DO_FUN(do_arm);
DECLARE_DO_FUN(do_addchange);
DECLARE_DO_FUN(do_changes);
DECLARE_DO_FUN(do_chaff);
DECLARE_DO_FUN(do_clan_donate);
DECLARE_DO_FUN(do_clan_withdraw);
DECLARE_DO_FUN(do_fly);
DECLARE_DO_FUN(do_drive);
DECLARE_DO_FUN(do_bomb);
DECLARE_DO_FUN(do_setblaster);
DECLARE_DO_FUN(do_ammo);
DECLARE_DO_FUN(do_ambush);
DECLARE_DO_FUN(do_takedrug);
DECLARE_DO_FUN(do_use);
DECLARE_DO_FUN(do_link);
DECLARE_DO_FUN(do_unlink);
DECLARE_DO_FUN(do_load);
DECLARE_DO_FUN(do_unload);
DECLARE_DO_FUN(do_enlist);
DECLARE_DO_FUN(do_resign);
DECLARE_DO_FUN(do_retune);
DECLARE_DO_FUN(do_retreat);
DECLARE_DO_FUN(do_reward);
DECLARE_DO_FUN(do_pluogus);
DECLARE_DO_FUN(do_makemodule);
DECLARE_DO_FUN(do_showmodules);
DECLARE_DO_FUN(do_installmodule);
DECLARE_DO_FUN(do_removebug);
DECLARE_DO_FUN(do_removemodule);
DECLARE_DO_FUN(do_tractorbeam);
DECLARE_DO_FUN(do_makearmor);
DECLARE_DO_FUN(do_makejewelry);
DECLARE_DO_FUN(do_makegrenade);
DECLARE_DO_FUN(do_makeshipbomb);
DECLARE_DO_FUN(do_makelandmine);
DECLARE_DO_FUN(do_makelight);
DECLARE_DO_FUN(do_makecomlink);
DECLARE_DO_FUN(do_makeshield);
DECLARE_DO_FUN(do_makecontainer);
DECLARE_DO_FUN(do_makemissile);
DECLARE_DO_FUN(do_gemcutting);
DECLARE_DO_FUN(do_reinforcements);
DECLARE_DO_FUN(do_postguard);
DECLARE_DO_FUN(do_torture);
DECLARE_DO_FUN(do_snipe);
DECLARE_DO_FUN(do_throw);
DECLARE_DO_FUN(do_deception);
DECLARE_DO_FUN(do_disguise);
DECLARE_DO_FUN(do_mine);
DECLARE_DO_FUN(do_first_aid);
DECLARE_DO_FUN(do_make_master);
DECLARE_DO_FUN(do_makeblade);
DECLARE_DO_FUN(do_makebeacon);
DECLARE_DO_FUN(do_makebinders);
DECLARE_DO_FUN(do_makebug);
DECLARE_DO_FUN(do_makegoggles);
DECLARE_DO_FUN(do_spousetalk);
DECLARE_DO_FUN(do_makepike);
DECLARE_DO_FUN(do_makeblaster);
DECLARE_DO_FUN(do_makelightsaber);
DECLARE_DO_FUN(do_makeduallightsaber);
DECLARE_DO_FUN(do_makespice);
DECLARE_DO_FUN(do_closebay);
DECLARE_DO_FUN(do_openbay);
DECLARE_DO_FUN(do_autotrack);
DECLARE_DO_FUN(do_jumpvector);
DECLARE_DO_FUN(do_reload);
DECLARE_DO_FUN(do_radar);
DECLARE_DO_FUN(do_recall);
DECLARE_DO_FUN(do_buyship);
DECLARE_DO_FUN(do_buytroops);
DECLARE_DO_FUN(do_buyhome);
DECLARE_DO_FUN(do_setforcer);
DECLARE_DO_FUN(do_clanbuyship);
DECLARE_DO_FUN(do_clangiveship);
DECLARE_DO_FUN(do_clansalvage);
DECLARE_DO_FUN(do_clanbuytroops);
DECLARE_DO_FUN(do_gatherclans);
DECLARE_DO_FUN(do_sellship);
DECLARE_DO_FUN(do_autorecharge);
DECLARE_DO_FUN(do_openhatch);
DECLARE_DO_FUN(do_closehatch);
DECLARE_DO_FUN(do_status);
DECLARE_DO_FUN(do_std);
DECLARE_DO_FUN(do_info);
DECLARE_DO_FUN(do_introduce);
DECLARE_DO_FUN(do_remember);
DECLARE_DO_FUN(do_describe);
DECLARE_DO_FUN(do_hyperspace);
DECLARE_DO_FUN(do_target);
DECLARE_DO_FUN(do_fire);
DECLARE_DO_FUN(do_calculate);
DECLARE_DO_FUN(do_recharge);
DECLARE_DO_FUN(do_shiprepair);
DECLARE_DO_FUN(do_shipmaintenance);
DECLARE_DO_FUN(do_shiplist);
DECLARE_DO_FUN(do_refuel);
DECLARE_DO_FUN(do_addpilot);
DECLARE_DO_FUN(do_rempilot);
DECLARE_DO_FUN(do_remclan);
DECLARE_DO_FUN(do_removeship);
DECLARE_DO_FUN(do_trajectory);
DECLARE_DO_FUN(do_accelerate);
DECLARE_DO_FUN(do_launch);
DECLARE_DO_FUN(do_land);
DECLARE_DO_FUN(do_leaveship);
DECLARE_DO_FUN(do_setstarsystem);
DECLARE_DO_FUN(do_makestarsystem);
DECLARE_DO_FUN(do_makesimulator);
DECLARE_DO_FUN(do_makemobship);
DECLARE_DO_FUN(do_starsystems);
DECLARE_DO_FUN(do_showstarsystem);
DECLARE_DO_FUN(skill_notfound);
DECLARE_DO_FUN(do_aassign);
DECLARE_DO_FUN(do_addbounty);
DECLARE_DO_FUN(do_contract);
DECLARE_DO_FUN(do_showcontracts);
DECLARE_DO_FUN(do_remcontract);
DECLARE_DO_FUN(do_vassign);
DECLARE_DO_FUN(do_advance);
DECLARE_DO_FUN(do_affected);
DECLARE_DO_FUN(do_afk);
DECLARE_DO_FUN(do_aid);
DECLARE_DO_FUN(do_rembounty);
DECLARE_DO_FUN(do_allow);
DECLARE_DO_FUN(do_ansi);
DECLARE_DO_FUN(do_answer);
DECLARE_DO_FUN(do_apply);
DECLARE_DO_FUN(do_appraise);
DECLARE_DO_FUN(do_areas);
DECLARE_DO_FUN(do_aset);
DECLARE_DO_FUN(do_ask);
DECLARE_DO_FUN(do_astat);
DECLARE_DO_FUN(do_at);
DECLARE_DO_FUN(do_auction);
DECLARE_DO_FUN(do_authorize);
DECLARE_DO_FUN(do_avtalk);
DECLARE_DO_FUN(do_backstab);
DECLARE_DO_FUN(do_backup);
DECLARE_DO_FUN(do_balzhur);
DECLARE_DO_FUN(do_bamfin);
DECLARE_DO_FUN(do_bamfout);
DECLARE_DO_FUN(do_ban);
DECLARE_DO_FUN(do_bash);
DECLARE_DO_FUN(do_bashdoor);
DECLARE_DO_FUN(do_beep);
DECLARE_DO_FUN(do_berserk);
DECLARE_DO_FUN(do_bestow);
DECLARE_DO_FUN(do_bestowarea);
DECLARE_DO_FUN(do_bio);
DECLARE_DO_FUN(do_bite);
DECLARE_DO_FUN(do_board);
DECLARE_DO_FUN(do_boards);
DECLARE_DO_FUN(do_bodybag);
DECLARE_DO_FUN(do_bounties);
DECLARE_DO_FUN(do_brandish);
DECLARE_DO_FUN(do_brew);
DECLARE_DO_FUN(do_bset);
DECLARE_DO_FUN(do_bstat);
DECLARE_DO_FUN(do_bug);
DECLARE_DO_FUN(do_bury);
DECLARE_DO_FUN(do_buy);
DECLARE_DO_FUN(do_cast);
DECLARE_DO_FUN(do_cedit);
DECLARE_DO_FUN(do_channels);
DECLARE_DO_FUN(do_chat);
DECLARE_DO_FUN(do_ooc);
DECLARE_DO_FUN(do_check_vnums);
DECLARE_DO_FUN(do_circle);
DECLARE_DO_FUN(do_clans);
DECLARE_DO_FUN(do_clanstat);
DECLARE_DO_FUN(do_ships);
DECLARE_DO_FUN(do_clantalk);
DECLARE_DO_FUN(do_claw);
DECLARE_DO_FUN(do_cleanroom);
DECLARE_DO_FUN(do_climb);
DECLARE_DO_FUN(do_close);
DECLARE_DO_FUN(do_cmdtable);
DECLARE_DO_FUN(do_cmenu);
DECLARE_DO_FUN(do_commands);
DECLARE_DO_FUN(do_comment);
DECLARE_DO_FUN(do_compare);
DECLARE_DO_FUN(do_config);
DECLARE_DO_FUN(do_consider);
DECLARE_DO_FUN(do_senate);
DECLARE_DO_FUN(do_addsenator);
DECLARE_DO_FUN(do_remsenator);
DECLARE_DO_FUN(do_concealment);
DECLARE_DO_FUN(do_credits);
DECLARE_DO_FUN(do_cset);
DECLARE_DO_FUN(do_deities);
DECLARE_DO_FUN(do_deny);
DECLARE_DO_FUN(do_description);
DECLARE_DO_FUN(do_destro);
DECLARE_DO_FUN(do_destroy);
DECLARE_DO_FUN(do_detrap);
DECLARE_DO_FUN(do_devote);
DECLARE_DO_FUN(do_dig);
DECLARE_DO_FUN(do_disarm);
DECLARE_DO_FUN(do_disconnect);
DECLARE_DO_FUN(do_dismount);
DECLARE_DO_FUN(do_dmesg);
DECLARE_DO_FUN(do_down);
DECLARE_DO_FUN(do_drag);
DECLARE_DO_FUN(do_drink);
DECLARE_DO_FUN(do_drop);
DECLARE_DO_FUN(do_droptroops);
DECLARE_DO_FUN(do_diagnose);
DECLARE_DO_FUN(do_dualstab);
DECLARE_DO_FUN(do_east);
DECLARE_DO_FUN(do_eat);
DECLARE_DO_FUN(do_echo);
DECLARE_DO_FUN(do_email);
DECLARE_DO_FUN(do_emote);
DECLARE_DO_FUN(do_empty);
DECLARE_DO_FUN(do_enter);
DECLARE_DO_FUN(do_equipment);
DECLARE_DO_FUN(do_examine);
DECLARE_DO_FUN(do_exempt);
DECLARE_DO_FUN(do_exits);
DECLARE_DO_FUN(do_endsimulator);
DECLARE_DO_FUN(do_feed);
DECLARE_DO_FUN(do_fill);
DECLARE_DO_FUN(do_fixchar);
DECLARE_DO_FUN(do_flee);
DECLARE_DO_FUN(do_foldarea);
DECLARE_DO_FUN(do_follow);
DECLARE_DO_FUN(do_for);
DECLARE_DO_FUN(do_force);
DECLARE_DO_FUN(do_fset);
DECLARE_DO_FUN(do_forceclose);
DECLARE_DO_FUN(do_fquit); /* Gorog */
DECLARE_DO_FUN(do_form_password);
DECLARE_DO_FUN(do_freeze);
DECLARE_DO_FUN(do_fslay);
DECLARE_DO_FUN(do_gag);
DECLARE_DO_FUN(do_get);
DECLARE_DO_FUN(do_give);
DECLARE_DO_FUN(do_giveship);
DECLARE_DO_FUN(do_giveslug);
DECLARE_DO_FUN(do_glance);
DECLARE_DO_FUN(do_gold);
DECLARE_DO_FUN(do_goto);
DECLARE_DO_FUN(do_gouge);
DECLARE_DO_FUN(do_group);
DECLARE_DO_FUN(do_grub);
DECLARE_DO_FUN(do_gtell);
DECLARE_DO_FUN(do_guilds);
DECLARE_DO_FUN(do_guildtalk);
DECLARE_DO_FUN(do_hedit);
DECLARE_DO_FUN(do_hell);
DECLARE_DO_FUN(do_help);
DECLARE_DO_FUN(do_hide);
DECLARE_DO_FUN(do_hitall);
DECLARE_DO_FUN(do_hlist);
DECLARE_DO_FUN(do_holylight);
DECLARE_DO_FUN(do_holonet);
DECLARE_DO_FUN(do_homepage);
DECLARE_DO_FUN(do_hset);
DECLARE_DO_FUN(do_i103);
DECLARE_DO_FUN(do_i104);
DECLARE_DO_FUN(do_i105);
DECLARE_DO_FUN(do_ide);
DECLARE_DO_FUN(do_idea);
DECLARE_DO_FUN(do_idealog);
DECLARE_DO_FUN(do_immortalize);
DECLARE_DO_FUN(do_immtalk);
DECLARE_DO_FUN(do_induct);
DECLARE_DO_FUN(do_installarea);
DECLARE_DO_FUN(do_instaroom);
DECLARE_DO_FUN(do_instazone);
DECLARE_DO_FUN(do_inventory);
DECLARE_DO_FUN(do_invis);
DECLARE_DO_FUN(do_kick);
DECLARE_DO_FUN(do_kill);
DECLARE_DO_FUN(do_languages);
DECLARE_DO_FUN(do_last);
DECLARE_DO_FUN(do_leave);
DECLARE_DO_FUN(do_level);
DECLARE_DO_FUN(do_light);
DECLARE_DO_FUN(do_list);
DECLARE_DO_FUN(do_litterbug);
DECLARE_DO_FUN(do_loadarea);
DECLARE_DO_FUN(do_loadup);
DECLARE_DO_FUN(do_lock);
DECLARE_DO_FUN(do_log);
DECLARE_DO_FUN(do_look);
DECLARE_DO_FUN(do_low_purge);
DECLARE_DO_FUN(do_mailroom);
DECLARE_DO_FUN(do_make);
DECLARE_DO_FUN(do_makeboard);
DECLARE_DO_FUN(do_makeclan);
DECLARE_DO_FUN(do_makeship);
DECLARE_DO_FUN(do_makeship2);
DECLARE_DO_FUN(do_makeguild);
DECLARE_DO_FUN(do_makerepair);
DECLARE_DO_FUN(do_makeshop);
DECLARE_DO_FUN(do_makewizlist);
DECLARE_DO_FUN(do_members);
DECLARE_DO_FUN(do_memory);
DECLARE_DO_FUN(do_mcreate);
DECLARE_DO_FUN(do_mdelete);
DECLARE_DO_FUN(do_mfind);
DECLARE_DO_FUN(do_minvoke);
DECLARE_DO_FUN(do_mlist);
DECLARE_DO_FUN(do_mount);
DECLARE_DO_FUN(do_mset);
DECLARE_DO_FUN(do_mstat);
DECLARE_DO_FUN(do_murde);
DECLARE_DO_FUN(do_murder);
DECLARE_DO_FUN(do_music);
DECLARE_DO_FUN(do_mwhere);
DECLARE_DO_FUN(do_name);
DECLARE_DO_FUN(do_newbiechat);
DECLARE_DO_FUN(do_newbieset);
DECLARE_DO_FUN(do_newzones);
DECLARE_DO_FUN(do_noemote);
DECLARE_DO_FUN(do_noresolve);
DECLARE_DO_FUN(do_north);
DECLARE_DO_FUN(do_northeast);
DECLARE_DO_FUN(do_northwest);
DECLARE_DO_FUN(do_notell);
DECLARE_DO_FUN(do_notitle);
DECLARE_DO_FUN(do_noteroom);
DECLARE_DO_FUN(do_ocreate);
DECLARE_DO_FUN(do_odelete);
DECLARE_DO_FUN(do_ofind);
DECLARE_DO_FUN(do_ogrub);
DECLARE_DO_FUN(do_oinvoke);
DECLARE_DO_FUN(do_oldmstat);
DECLARE_DO_FUN(do_oldscore);
DECLARE_DO_FUN(do_olist);
DECLARE_DO_FUN(do_open);
DECLARE_DO_FUN(do_opentourney);
DECLARE_DO_FUN(do_order);
DECLARE_DO_FUN(do_orders);
DECLARE_DO_FUN(do_ordership);
DECLARE_DO_FUN(do_orderclanship);
DECLARE_DO_FUN(do_ordertalk);
DECLARE_DO_FUN(do_oset);
DECLARE_DO_FUN(do_ostat);
DECLARE_DO_FUN(do_ot);
DECLARE_DO_FUN(do_outcast);
DECLARE_DO_FUN(do_outlaw);
DECLARE_DO_FUN(do_owhere);
DECLARE_DO_FUN(do_pager);
DECLARE_DO_FUN(do_pardon);
DECLARE_DO_FUN(do_password);
DECLARE_DO_FUN(do_peace);
DECLARE_DO_FUN(do_pick);
DECLARE_DO_FUN(do_poison_weapon);
DECLARE_DO_FUN(do_pose);
DECLARE_DO_FUN(do_practice);
DECLARE_DO_FUN(do_prompt);
DECLARE_DO_FUN(do_pull);
DECLARE_DO_FUN(do_punch);
DECLARE_DO_FUN(do_purge);
DECLARE_DO_FUN(do_push);
DECLARE_DO_FUN(do_put);
DECLARE_DO_FUN(do_qpset);
DECLARE_DO_FUN(do_quaff);
DECLARE_DO_FUN(do_quest);
DECLARE_DO_FUN(do_qui);
DECLARE_DO_FUN(do_quit);
DECLARE_DO_FUN(do_rank);
DECLARE_DO_FUN(do_rat);
DECLARE_DO_FUN(do_rdelete);
DECLARE_DO_FUN(do_reboo);
DECLARE_DO_FUN(do_reboot);
DECLARE_DO_FUN(do_recho);
DECLARE_DO_FUN(do_recite);
DECLARE_DO_FUN(do_redit);
DECLARE_DO_FUN(do_regoto);
DECLARE_DO_FUN(do_remove);
DECLARE_DO_FUN(do_rent);
DECLARE_DO_FUN(do_mobrepair);
DECLARE_DO_FUN(do_repair);
DECLARE_DO_FUN(do_repairset);
DECLARE_DO_FUN(do_repairshops);
DECLARE_DO_FUN(do_repairstat);
DECLARE_DO_FUN(do_reply);
DECLARE_DO_FUN(do_report);
DECLARE_DO_FUN(do_rescue);
DECLARE_DO_FUN(do_rest);
DECLARE_DO_FUN(do_reset);
DECLARE_DO_FUN(do_resetship);
DECLARE_DO_FUN(do_restore);
DECLARE_DO_FUN(do_restorefile);
DECLARE_DO_FUN(do_restoretime);
DECLARE_DO_FUN(do_restrict);
DECLARE_DO_FUN(do_request);
DECLARE_DO_FUN(do_retire);
DECLARE_DO_FUN(do_retran);
DECLARE_DO_FUN(do_return);
DECLARE_DO_FUN(do_revert);
DECLARE_DO_FUN(do_rip);
DECLARE_DO_FUN(do_rlist);
DECLARE_DO_FUN(do_rset);
DECLARE_DO_FUN(do_rstat);
DECLARE_DO_FUN(do_sacrifice);
DECLARE_DO_FUN(do_save);
DECLARE_DO_FUN(do_savearea);
DECLARE_DO_FUN(do_say);
DECLARE_DO_FUN(do_scan);
DECLARE_DO_FUN(do_scanbugs);
DECLARE_DO_FUN(do_score);
DECLARE_DO_FUN(do_screenname);
DECLARE_DO_FUN(do_scribe);
DECLARE_DO_FUN(do_search);
DECLARE_DO_FUN(do_sedit);
DECLARE_DO_FUN(do_sell);
DECLARE_DO_FUN(do_sellhome);
DECLARE_DO_FUN(do_set_boot_time);
DECLARE_DO_FUN(do_setclan);
DECLARE_DO_FUN(do_setship);
DECLARE_DO_FUN(do_shops);
DECLARE_DO_FUN(do_shopset);
DECLARE_DO_FUN(do_shopstat);
DECLARE_DO_FUN(do_shout);
DECLARE_DO_FUN(do_shove);
DECLARE_DO_FUN(do_showclan);
DECLARE_DO_FUN(do_showship);
DECLARE_DO_FUN(do_showplanet);
DECLARE_DO_FUN(do_showsocial);
DECLARE_DO_FUN(do_shutdow);
DECLARE_DO_FUN(do_shutdown);
DECLARE_DO_FUN(do_silence);
DECLARE_DO_FUN(do_sit);
DECLARE_DO_FUN(do_tune);
DECLARE_DO_FUN(do_shiplock);
DECLARE_DO_FUN(do_salvage);
DECLARE_DO_FUN(do_plantbug);
DECLARE_DO_FUN(do_plantbeacon);
DECLARE_DO_FUN(do_showbugs);
DECLARE_DO_FUN(do_showbeacons);
DECLARE_DO_FUN(do_checkbeacons);
DECLARE_DO_FUN(do_nullifybeacons);
DECLARE_DO_FUN(do_juke);
DECLARE_DO_FUN(do_barrel_roll);
DECLARE_DO_FUN(do_launch2);
DECLARE_DO_FUN(do_sabotage);
DECLARE_DO_FUN(do_freeship);
DECLARE_DO_FUN(do_hale);
DECLARE_DO_FUN(do_wwwimage);
DECLARE_DO_FUN(do_whisper);
DECLARE_DO_FUN(do_marry);
DECLARE_DO_FUN(do_propose);
DECLARE_DO_FUN(do_divorce);
DECLARE_DO_FUN(do_accept);
DECLARE_DO_FUN(do_decline);
DECLARE_DO_FUN(do_tellsnoop);
DECLARE_DO_FUN(do_makecommsystem);
DECLARE_DO_FUN(do_makedatapad);
DECLARE_DO_FUN(do_codecrack);
DECLARE_DO_FUN(do_inquire);
DECLARE_DO_FUN(do_checkprints);
DECLARE_DO_FUN(do_disableship);
DECLARE_DO_FUN(do_assignpilot);
DECLARE_DO_FUN(do_setwage);
DECLARE_DO_FUN(do_sla);
DECLARE_DO_FUN(do_slay);
DECLARE_DO_FUN(do_slicebank);
DECLARE_DO_FUN(do_sleep);
DECLARE_DO_FUN(do_slist);
DECLARE_DO_FUN(do_slog);
DECLARE_DO_FUN(do_slookup);
DECLARE_DO_FUN(do_smoke);
DECLARE_DO_FUN(do_sneak);
DECLARE_DO_FUN(do_snoop);
DECLARE_DO_FUN(do_sober);
DECLARE_DO_FUN(do_socials);
DECLARE_DO_FUN(do_south);
DECLARE_DO_FUN(do_southeast);
DECLARE_DO_FUN(do_southwest);
DECLARE_DO_FUN(do_speak);
DECLARE_DO_FUN(do_split);
DECLARE_DO_FUN(do_sset);
DECLARE_DO_FUN(do_stand);
DECLARE_DO_FUN(do_starttourney);
DECLARE_DO_FUN(do_steal);
DECLARE_DO_FUN(do_sting);
DECLARE_DO_FUN(do_stun);
DECLARE_DO_FUN(do_supplicate);
DECLARE_DO_FUN(do_switch);
DECLARE_DO_FUN(do_tail);
DECLARE_DO_FUN(do_tamp);
DECLARE_DO_FUN(do_tell);
DECLARE_DO_FUN(do_time);
DECLARE_DO_FUN(do_timecmd);
DECLARE_DO_FUN(do_title);
DECLARE_DO_FUN(do_track);
DECLARE_DO_FUN(do_transfer);
DECLARE_DO_FUN(do_transship);
DECLARE_DO_FUN(do_transshipss);
DECLARE_DO_FUN(do_trust);
DECLARE_DO_FUN(do_typo);
DECLARE_DO_FUN(do_unhell);
DECLARE_DO_FUN(do_unbind);
DECLARE_DO_FUN(do_ungag);
DECLARE_DO_FUN(do_unlock);
DECLARE_DO_FUN(do_unsilence);
DECLARE_DO_FUN(do_unoutlaw);
DECLARE_DO_FUN(do_up);
DECLARE_DO_FUN(do_users);
DECLARE_DO_FUN(do_value);
DECLARE_DO_FUN(do_viewskills);
DECLARE_DO_FUN(do_visible);
DECLARE_DO_FUN(do_vnums);
DECLARE_DO_FUN(do_vsearch);
DECLARE_DO_FUN(do_wake);
DECLARE_DO_FUN(do_wartalk);
DECLARE_DO_FUN(do_war);
DECLARE_DO_FUN(do_prototypes);
DECLARE_DO_FUN(do_setprototype);
DECLARE_DO_FUN(do_showprototype);
DECLARE_DO_FUN(do_designship);
DECLARE_DO_FUN(do_wear);
DECLARE_DO_FUN(do_weather);
DECLARE_DO_FUN(do_west);
DECLARE_DO_FUN(do_where);
DECLARE_DO_FUN(do_who);
DECLARE_DO_FUN(do_whoinvis);
DECLARE_DO_FUN(do_whois);
DECLARE_DO_FUN(do_wimpy);
DECLARE_DO_FUN(do_wizhelp);
DECLARE_DO_FUN(do_wizlist);
DECLARE_DO_FUN(do_wizlock);
DECLARE_DO_FUN(do_yell);
DECLARE_DO_FUN(do_zap);
DECLARE_DO_FUN(do_zones);

/* mob prog stuff */
DECLARE_DO_FUN(do_mp_close_passage);
DECLARE_DO_FUN(do_mp_damage);
DECLARE_DO_FUN(do_mp_restore);
DECLARE_DO_FUN(do_mp_open_passage);
DECLARE_DO_FUN(do_mp_practice);
DECLARE_DO_FUN(do_mp_slay);
DECLARE_DO_FUN(do_mpadvance);
DECLARE_DO_FUN(do_mpasound);
DECLARE_DO_FUN(do_mpat);
DECLARE_DO_FUN(do_mpdream);
DECLARE_DO_FUN(do_mp_deposit);
DECLARE_DO_FUN(do_mp_withdraw);
DECLARE_DO_FUN(do_mpecho);
DECLARE_DO_FUN(do_mpechoaround);
DECLARE_DO_FUN(do_mpechoat);
DECLARE_DO_FUN(do_mpedit);
DECLARE_DO_FUN(do_mrange);
DECLARE_DO_FUN(do_opedit);
DECLARE_DO_FUN(do_orange);
DECLARE_DO_FUN(do_rpconvert);
DECLARE_DO_FUN(do_rpedit);
DECLARE_DO_FUN(do_mpforce);
DECLARE_DO_FUN(do_mpinvis);
DECLARE_DO_FUN(do_mpgoto);
DECLARE_DO_FUN(do_mpjunk);
DECLARE_DO_FUN(do_mpkill);
DECLARE_DO_FUN(do_mpmload);
DECLARE_DO_FUN(do_mpmset);
DECLARE_DO_FUN(do_mpnothing);
DECLARE_DO_FUN(do_mpoload);
DECLARE_DO_FUN(do_mposet);
DECLARE_DO_FUN(do_mppurge);
DECLARE_DO_FUN(do_mpstat);
DECLARE_DO_FUN(do_opstat);
DECLARE_DO_FUN(do_rpstat);
DECLARE_DO_FUN(do_mptransfer);
DECLARE_DO_FUN(do_mpapply);
DECLARE_DO_FUN(do_mpapplyb);
DECLARE_DO_FUN(do_mppkset);
DECLARE_DO_FUN(do_mpgain);

/*
 * Spell functions.
 * Defined in magic.c.
 */
DECLARE_SPELL_FUN(spell_null);
DECLARE_SPELL_FUN(spell_notfound);
DECLARE_SPELL_FUN(spell_acid_blast);
DECLARE_SPELL_FUN(spell_animate_dead);
DECLARE_SPELL_FUN(spell_astral_walk);
DECLARE_SPELL_FUN(spell_blindness);
DECLARE_SPELL_FUN(spell_burning_hands);
DECLARE_SPELL_FUN(spell_call_lightning);
DECLARE_SPELL_FUN(spell_cause_critical);
DECLARE_SPELL_FUN(spell_cause_light);
DECLARE_SPELL_FUN(spell_cause_serious);
DECLARE_SPELL_FUN(spell_change_sex);
DECLARE_SPELL_FUN(spell_charm_person);
DECLARE_SPELL_FUN(spell_chill_touch);
DECLARE_SPELL_FUN(spell_colour_spray);
DECLARE_SPELL_FUN(spell_control_weather);
DECLARE_SPELL_FUN(spell_create_food);
DECLARE_SPELL_FUN(spell_create_water);
DECLARE_SPELL_FUN(spell_cure_blindness);
DECLARE_SPELL_FUN(spell_cure_poison);
DECLARE_SPELL_FUN(spell_curse);
DECLARE_SPELL_FUN(spell_detect_poison);
DECLARE_SPELL_FUN(spell_dispel_evil);
DECLARE_SPELL_FUN(spell_dispel_magic);
DECLARE_SPELL_FUN(spell_dream);
DECLARE_SPELL_FUN(spell_earthquake);
DECLARE_SPELL_FUN(spell_enchant_weapon);
DECLARE_SPELL_FUN(spell_energy_drain);
DECLARE_SPELL_FUN(spell_faerie_fire);
DECLARE_SPELL_FUN(spell_faerie_fog);
DECLARE_SPELL_FUN(spell_farsight);
DECLARE_SPELL_FUN(spell_fireball);
DECLARE_SPELL_FUN(spell_flamestrike);
DECLARE_SPELL_FUN(spell_gate);
DECLARE_SPELL_FUN(spell_knock);
DECLARE_SPELL_FUN(spell_injure);
DECLARE_SPELL_FUN(spell_identify);
DECLARE_SPELL_FUN(spell_invis);
DECLARE_SPELL_FUN(spell_know_alignment);
DECLARE_SPELL_FUN(spell_lightning_bolt);
DECLARE_SPELL_FUN(spell_locate_object);
DECLARE_SPELL_FUN(spell_magic_missile);
DECLARE_SPELL_FUN(spell_mist_walk);
DECLARE_SPELL_FUN(spell_pass_door);
DECLARE_SPELL_FUN(spell_plant_pass);
DECLARE_SPELL_FUN(spell_poison);
DECLARE_SPELL_FUN(spell_polymorph);
DECLARE_SPELL_FUN(spell_possess);
DECLARE_SPELL_FUN(spell_recharge);
DECLARE_SPELL_FUN(spell_remove_curse);
DECLARE_SPELL_FUN(spell_remove_invis);
DECLARE_SPELL_FUN(spell_remove_trap);
DECLARE_SPELL_FUN(spell_shocking_grasp);
DECLARE_SPELL_FUN(spell_sleep);
DECLARE_SPELL_FUN(spell_smaug);
DECLARE_SPELL_FUN(spell_solar_flight);
DECLARE_SPELL_FUN(spell_summon);
DECLARE_SPELL_FUN(spell_teleport);
DECLARE_SPELL_FUN(spell_ventriloquate);
DECLARE_SPELL_FUN(spell_weaken);
DECLARE_SPELL_FUN(spell_word_of_recall);
DECLARE_SPELL_FUN(spell_acid_breath);
DECLARE_SPELL_FUN(spell_fire_breath);
DECLARE_SPELL_FUN(spell_frost_breath);
DECLARE_SPELL_FUN(spell_gas_breath);
DECLARE_SPELL_FUN(spell_lightning_breath);
DECLARE_SPELL_FUN(spell_spiral_blast);
DECLARE_SPELL_FUN(spell_scorching_surge);
DECLARE_SPELL_FUN(spell_helical_flow);
DECLARE_SPELL_FUN(spell_transport);
DECLARE_SPELL_FUN(spell_portal);

DECLARE_SPELL_FUN(spell_ethereal_fist);
DECLARE_SPELL_FUN(spell_spectral_furor);
DECLARE_SPELL_FUN(spell_hand_of_chaos);
DECLARE_SPELL_FUN(spell_disruption);
DECLARE_SPELL_FUN(spell_sonic_resonance);
DECLARE_SPELL_FUN(spell_mind_wrack);
DECLARE_SPELL_FUN(spell_mind_wrench);
DECLARE_SPELL_FUN(spell_revive);
DECLARE_SPELL_FUN(spell_sulfurous_spray);
DECLARE_SPELL_FUN(spell_caustic_fount);
DECLARE_SPELL_FUN(spell_acetum_primus);
DECLARE_SPELL_FUN(spell_galvanic_whip);
DECLARE_SPELL_FUN(spell_magnetic_thrust);
DECLARE_SPELL_FUN(spell_quantum_spike);
DECLARE_SPELL_FUN(spell_black_hand);
DECLARE_SPELL_FUN(spell_black_fist);
DECLARE_SPELL_FUN(spell_black_lightning);
DECLARE_SPELL_FUN(spell_calm);
DECLARE_SPELL_FUN(spell_forcepush);
DECLARE_SPELL_FUN(spell_force_disarm);
DECLARE_SPELL_FUN(spell_steal_life);
DECLARE_SPELL_FUN(spell_midas_touch);

DECLARE_SPELL_FUN(spell_suggest);
DECLARE_SPELL_FUN(spell_cure_addiction);

DECLARE_DO_FUN(fskill_convert);
DECLARE_DO_FUN(fskill_awareness);
DECLARE_DO_FUN(fskill_fdisguise);
DECLARE_DO_FUN(fskill_finfo);
DECLARE_DO_FUN(fskill_fhelp);
DECLARE_DO_FUN(fskill_finish);
DECLARE_DO_FUN(fskill_force_lightning);
DECLARE_DO_FUN(fskill_fshield);
DECLARE_DO_FUN(fskill_heal);
DECLARE_DO_FUN(fskill_identify);
DECLARE_DO_FUN(fskill_instruct);
DECLARE_DO_FUN(fskill_master);
DECLARE_DO_FUN(fskill_makelightsaber);
DECLARE_DO_FUN(fskill_promote);
DECLARE_DO_FUN(fskill_protect);
DECLARE_DO_FUN(fskill_refresh);
DECLARE_DO_FUN(fskill_squeeze);
DECLARE_DO_FUN(fskill_student);
DECLARE_DO_FUN(fskill_slash);
DECLARE_DO_FUN(fskill_whirlwind);
DECLARE_DO_FUN(fskill_makedualsaber);

/* editor.c cronel new editor */
void start_editing_nolimit(CHAR_DATA *ch, char *data, short max_size);
void stop_editing(CHAR_DATA *ch);
void edit_buffer(CHAR_DATA *ch, char *argument);
char *copy_buffer(CHAR_DATA *ch);
void set_editor_desc(CHAR_DATA *ch, char *desc);
void editor_desc_printf(CHAR_DATA *ch, const char *desc_fmt, ...);

/* pfiles.c */
void remove_member(char *name, char *shortname);
void add_member(char *name, char *shortname);

/* act_comm.c */
bool check_parse_name(const char *name);
void sound_to_room(ROOM_INDEX_DATA *room, const char *argument);
bool circle_follow(CHAR_DATA *ch, CHAR_DATA *victim);
void add_follower(CHAR_DATA *ch, CHAR_DATA *master);
void stop_follower(CHAR_DATA *ch);
void die_follower(CHAR_DATA *ch);
bool is_same_group(CHAR_DATA *ach, CHAR_DATA *bch);
void send_rip_screen(CHAR_DATA *ch);
void send_rip_title(CHAR_DATA *ch);
void send_ansi_title(CHAR_DATA *ch);
void send_ascii_title(CHAR_DATA *ch);
void to_channel(const char *argument, int channel, const char *verb, short level);
void talk_auction(char *argument);
bool knows_language(CHAR_DATA *ch, int language, CHAR_DATA *cch);
bool can_learn_lang(CHAR_DATA *ch, int language);
int countlangs(int languages);
char *obj_short(OBJ_DATA *obj);

/* act_info.c */
int get_door(const char *arg);
char *format_obj_to_char(OBJ_DATA *obj, CHAR_DATA *ch, bool fShort);
void show_list_to_char(OBJ_DATA *list, CHAR_DATA *ch, bool fShort, bool fShowNothing);

/* act_move.c */
void clear_vrooms(void);
EXIT_DATA *find_door(CHAR_DATA *ch, const char *arg, bool quiet);
EXIT_DATA *get_exit(ROOM_INDEX_DATA *room, short dir);
EXIT_DATA *get_exit_to(ROOM_INDEX_DATA *room, short dir, int vnum);
EXIT_DATA *get_exit_num(ROOM_INDEX_DATA *room, short count);
ch_ret move_char(CHAR_DATA *ch, EXIT_DATA *pexit, int fall);
void teleport(CHAR_DATA *ch, int room, int flags);
short encumbrance(CHAR_DATA *ch, short move);
bool will_fall(CHAR_DATA *ch, int fall);
int wherehome(CHAR_DATA *ch);

/* act_obj.c */
obj_ret damage_obj(OBJ_DATA *obj);
short get_obj_resistance(OBJ_DATA *obj);
bool remove_obj(CHAR_DATA *ch, int iWear, bool fReplace);
void save_clan_storeroom(CHAR_DATA *ch, CLAN_DATA *clan);
void obj_fall(OBJ_DATA *obj, bool through);

/* act_wiz.c */
void close_area(AREA_DATA *pArea);
AREA_DATA *get_area(const char *argument);
ROOM_INDEX_DATA *find_location(CHAR_DATA *ch, char *arg);
void echo_to_room(short AT_COLOR, ROOM_INDEX_DATA *room, const char *argument);
void echo_to_all(short AT_COLOR, const char *argument, short tar);
void get_reboot_string(void);
struct tm *update_time(struct tm *old_time);
void free_social(SOCIALTYPE *social);
void add_social(SOCIALTYPE *social);
void free_command(CMDTYPE *command);
void unlink_command(CMDTYPE *command);
void add_command(CMDTYPE *command);

/* boards.c */
void load_boards(void);
BOARD_DATA *get_board(OBJ_DATA *obj);
void free_note(NOTE_DATA *pnote);

/* build.c */
const char *flag_string(int bitvector, const char *const flagarray[]);
char *strip_cr(const char *str);
int get_vip_flag(const char *flag);
int get_wanted_flag(const char *flag);
int get_flag(const char *, const char *const flagarray[], int);
int get_otype(const char *type);
int get_atype(const char *type);
int get_aflag(const char *flag);
int get_oflag(const char *flag);
int get_wflag(const char *flag);
int get_risflag(const char *flag);
int get_attackflag(const char *flag);
int get_defenseflag(const char *flag);
int get_langnum(const char *flag);
int get_langnum_save(const char *flag);
int get_langflag(const char *flag);
int get_exflag(const char *flag);
int get_rflag(const char *flag);
int get_rflag2(const char *flag);
int get_secflag(const char *flag);
int get_actflag(const char *flag);
int get_cmdflag(const char *flag);
int get_npc_race(const char *type);
int get_pc_race(const char *type);
int get_npc_sex(const char *sex);
int get_areaflag(const char *flag);
int get_mpflag(const char *flag);
int get_trigflag(const char *flag);
int get_dir(const char *txt);
int get_partflag(const char *flag);
int get_npc_position(const char *position);

/* clans.c */
CLAN_DATA *get_clan(const char *name);
void load_clans(void);
void save_clan(CLAN_DATA *clan);
void load_senate(void);
void save_senate(void);
PLANET_DATA *get_planet(const char *name);
void load_planets(void);
void save_planet(PLANET_DATA *planet);
long get_taxes(PLANET_DATA *planet);

/* bounty.c */
BOUNTY_DATA *get_disintegration(const char *target);
void load_bounties(void);
void save_bounties(void);
void save_disintegrations(void);
void remove_disintegration(BOUNTY_DATA *bounty);
void claim_disintegration(CHAR_DATA *ch, CHAR_DATA *victim);
bool is_disintegration(CHAR_DATA *victim);

/* force.c */
bool check_reflect(CHAR_DATA *ch, CHAR_DATA *victim, int dam);
void write_all_forceskills(void);
void save_forceskill(FORCE_SKILL *fskill);
void write_forceskill_list(void);
bool load_forceskill(const char *forceskillfile);
void fread_forceskill(FORCE_SKILL *fskill, FILE *fp);
void write_all_forcehelps(void);
void save_forcehelp(FORCE_HELP *fhelp);
void write_forcehelp_list(void);
bool load_forcehelp(const char *forcehelpfile);
void fread_forcehelp(FORCE_HELP *fhelp, FILE *fp);
int check_force_skill(CHAR_DATA *ch, const char *command, const char *argument);
void load_force_skills(void);
void load_force_help(void);
DO_FUN *get_force_skill_function(const char *name);
FORCE_SKILL *get_force_skill(const char *argument);
FORCE_HELP *get_force_help(const char *fname, const char *type);
void force_send_to_room(CHAR_DATA *ch, CHAR_DATA *victim, const char *msg);
CHAR_DATA *force_get_victim(CHAR_DATA *ch, const char *argument, int loc);
const char *force_get_possessive(CHAR_DATA *ch);
const char *force_get_objective(CHAR_DATA *ch);
const char *force_get_pronoun(CHAR_DATA *ch);
char *force_parse_string(CHAR_DATA *ch, CHAR_DATA *victim, const char *msg);
void force_learn_from_failure(CHAR_DATA *ch, FORCE_SKILL *fskill);
void force_learn_from_success(CHAR_DATA *ch, FORCE_SKILL *fskill);
FORCE_SKILL *force_test_skill_use(const char *skill_name, CHAR_DATA *ch, int skill_type);
const char *force_get_level(CHAR_DATA *ch);
int force_promote_ready(CHAR_DATA *ch);
void draw_force_line(CHAR_DATA *ch, int length);
void draw_force_line_rev(CHAR_DATA *ch, int length);
void update_force(void);

/* space.c */
SHIP_DATA *get_ship(const char *name);
void load_ships(void);
void placeships(void);
void save_ship(SHIP_DATA *ship);
void load_space(void);
void save_starsystem(SPACE_DATA *starsystem);
SPACE_DATA *starsystem_from_name(const char *name);
SPACE_DATA *starsystem_from_room(ROOM_INDEX_DATA *room);
SHIP_DATA *ship_from_entrance(int vnum);
SHIP_DATA *ship_from_room(int vnum);
SHIP_DATA *ship_from_hanger(int vnum);
SHIP_DATA *ship_from_pilotseat(int vnum);
SHIP_DATA *ship_from_cockpit(int vnum);
SHIP_DATA *ship_from_turret(int vnum);
SHIP_DATA *ship_from_engine(int vnum);
SHIP_DATA *ship_from_pilot(const char *name);
SHIP_DATA *get_ship_here(const char *name, SPACE_DATA *starsystem);
void showstarsystem(CHAR_DATA *ch, SPACE_DATA *starsystem);
void update_space(void);
void recharge_ships(void);
void move_ships(void);
void update_bus(void);
void update_traffic(void);
bool check_pilot(CHAR_DATA *ch, SHIP_DATA *ship);
bool is_rental(CHAR_DATA *ch, SHIP_DATA *ship);
void echo_to_ship(int color, SHIP_DATA *ship, const char *argument);
void echo_to_cockpit(int color, SHIP_DATA *ship, const char *argument);
void echo_to_system(int color, SHIP_DATA *ship, const char *argument, SHIP_DATA *ignore);
bool extract_ship(SHIP_DATA *ship);
bool ship_to_room(SHIP_DATA *ship, int vnum);
bool ship_to_room2(SHIP_DATA *ship, ROOM_INDEX_DATA *shipto);
long get_ship_value(SHIP_DATA *ship);
bool rent_ship(CHAR_DATA *ch, SHIP_DATA *ship);
void damage_ship(SHIP_DATA *ship, int min, int max);
void damage_ship_ch(SHIP_DATA *ship, int min, int max, CHAR_DATA *ch);
void destroy_ship(SHIP_DATA *ship, CHAR_DATA *ch, const char *reason);
void ship_to_starsystem(SHIP_DATA *ship, SPACE_DATA *starsystem);
void ship_from_starsystem(SHIP_DATA *ship, SPACE_DATA *starsystem);
void new_missile(SHIP_DATA *ship, SHIP_DATA *target, CHAR_DATA *ch, int missiletype);
void extract_missile(MISSILE_DATA *missile);
SHIP_DATA *ship_in_room(ROOM_INDEX_DATA *room, const char *name);

/* morespace.c */
SHIP_PROTOTYPE *get_ship_prototype(char *name);
void load_prototypes(void);
void save_ship_protoype(SHIP_PROTOTYPE *prototype);
long int get_prototype_value(SHIP_PROTOTYPE *prototype);
void create_ship_rooms(SHIP_DATA *ship);

/* comm.c */
const char *PERS(CHAR_DATA *ch, CHAR_DATA *looker);
FELLOW_DATA *knowsof(CHAR_DATA *ch, CHAR_DATA *victim);
void close_socket(DESCRIPTOR_DATA *dclose, bool force);
bool write_to_descriptor(DESCRIPTOR_DATA *d, const char *txt, int length);
void write_to_buffer(DESCRIPTOR_DATA *d, const char *txt, size_t length);
void write_to_pager(DESCRIPTOR_DATA *d, const char *txt, size_t length);
void send_to_char(const char *txt, CHAR_DATA *ch);
void send_to_char_color(const char *txt, CHAR_DATA *ch);
void send_to_char_noand(const char *txt, CHAR_DATA *ch);
void send_to_pager(const char *txt, CHAR_DATA *ch);
void send_to_pager_color(const char *txt, CHAR_DATA *ch);
void ch_printf(CHAR_DATA *ch, const char *fmt, ...);
char *chrmax(char *src, int length);
int strlen_color(char *argument);
char *format_str(char *str, int len);
void pager_printf(CHAR_DATA *ch, const char *fmt, ...);
void log_string_plus(const char *str, short log_type, short level);
void log_printf_plus(short log_type, short level, const char *fmt, ...);
void log_printf(const char *fmt, ...);
void descriptor_printf(DESCRIPTOR_DATA *d, const char *fmt, ...);
void buffer_printf(DESCRIPTOR_DATA *d, const char *fmt, ...);
void act(short AType, const char *format, CHAR_DATA *ch, const void *arg1, const void *arg2, int type);

/* reset.c */
RESET_DATA *make_reset(char letter, int extra, int arg1, int arg2, int arg3);
RESET_DATA *add_reset(ROOM_INDEX_DATA *room, char letter, int extra, int arg1, int arg2, int arg3);
void reset_area(AREA_DATA *pArea);

/* db.c */
char *fread_flagstring(FILE *fp);
void show_file(CHAR_DATA *ch, const char *filename);
bool is_valid_filename(CHAR_DATA *ch, const char *direct, const char *filename);
const char *centertext(const char *text, size_t size);
void boot_db(bool fCopyOver);
void area_update(void);
void add_char(CHAR_DATA *ch);
CHAR_DATA *create_mobile(MOB_INDEX_DATA *pMobIndex);
OBJ_DATA *create_object(OBJ_INDEX_DATA *pObjIndex, int level);
void clear_char(CHAR_DATA *ch);
void free_char(CHAR_DATA *ch);
char *get_extra_descr(const char *name, EXTRA_DESCR_DATA *ed);
MOB_INDEX_DATA *get_mob_index(int vnum);
OBJ_INDEX_DATA *get_obj_index(int vnum);
ROOM_INDEX_DATA *get_room_index(int vnum);
char fread_letter(FILE *fp);
int fread_number(FILE *fp);
float fread_float(FILE *fp);
char *fread_string(FILE *fp);
char *fread_string_nohash(FILE *fp);
void fread_to_eol(FILE *fp);
char *fread_word(FILE *fp);
char *fread_line(FILE *fp);
int number_fuzzy(int number);
int number_range(int from, int to);
int number_percent(void);
int number_door(void);
int number_bits(int width);
int number_mm(void);
int dice(int number, int size);
int interpolate(int level, int value_00, int value_32);
void smash_tilde(char *str);
const char *smash_tilde(const char *str);
char *smash_tilde_copy(const char *str);
void hide_tilde(char *str);
char *show_tilde(const char *str);
bool str_cmp(const char *astr, const char *bstr);
bool str_prefix(const char *astr, const char *bstr);
bool str_infix(const char *astr, const char *bstr);
bool str_suffix(const char *astr, const char *bstr);
char *capitalize(const char *str);
char *strlower(const char *str);
char *strupper(const char *str);
const char *aoran(const char *str);
void append_file(CHAR_DATA *ch, const char *file, const char *str);
void append_to_file(const char *file, const char *str);
void prepend_to_file(const char *file, const char *str);
void bug(const char *str, ...);
ROOM_INDEX_DATA *make_room(int vnum, AREA_DATA *area);
ROOM_INDEX_DATA *make_ship_room(SHIP_DATA *ship, int vnum);
OBJ_INDEX_DATA *make_object(int vnum, int cvnum, const char *name);
MOB_INDEX_DATA *make_mobile(int vnum, int cvnum, const char *name);
EXIT_DATA *make_exit(ROOM_INDEX_DATA *pRoomIndex, ROOM_INDEX_DATA *to_room, short door);
void add_help(HELP_DATA *pHelp);
void fix_area_exits(AREA_DATA *tarea);
void load_area_file(AREA_DATA *tarea, const char *filename);
void randomize_exits(ROOM_INDEX_DATA *room, short maxdir);
void make_wizlist(void);
void tail_chain(void);
void delete_room(ROOM_INDEX_DATA *room);
void delete_obj(OBJ_INDEX_DATA *obj);
void delete_mob(MOB_INDEX_DATA *mob);
void sort_area(AREA_DATA *pArea, bool proto);
void sort_area_by_name(AREA_DATA *pArea); /* Fireblade */

/* build.c */
bool can_rmodify(CHAR_DATA *ch, ROOM_INDEX_DATA *room);
bool can_omodify(CHAR_DATA *ch, OBJ_DATA *obj);
bool can_mmodify(CHAR_DATA *ch, CHAR_DATA *mob);
bool can_medit(CHAR_DATA *ch, MOB_INDEX_DATA *mob);
void free_reset(AREA_DATA *are, RESET_DATA *res);
void free_area(AREA_DATA *are);
void assign_area(CHAR_DATA *ch);
EXTRA_DESCR_DATA *SetRExtra(ROOM_INDEX_DATA *room, const char *keywords);
bool DelRExtra(ROOM_INDEX_DATA *room, const char *keywords);
EXTRA_DESCR_DATA *SetOExtra(OBJ_DATA *obj, const char *keywords);
bool DelOExtra(OBJ_DATA *obj, const char *keywords);
EXTRA_DESCR_DATA *SetOExtraProto(OBJ_INDEX_DATA *obj, const char *keywords);
bool DelOExtraProto(OBJ_INDEX_DATA *obj, const char *keywords);
void fold_area(AREA_DATA *tarea, const char *filename, bool install);
void RelCreate(relation_type, void *, void *);
void RelDestroy(relation_type, void *, void *);

/* fight.c */
int max_fight(CHAR_DATA *ch);
void violence_update(void);
ch_ret multi_hit(CHAR_DATA *ch, CHAR_DATA *victim, int dt);
short ris_damage(CHAR_DATA *ch, short dam, int ris);
ch_ret damage(CHAR_DATA *ch, CHAR_DATA *victim, int dam, int dt);
void update_pos(CHAR_DATA *victim);
void set_fighting(CHAR_DATA *ch, CHAR_DATA *victim);
void stop_fighting(CHAR_DATA *ch, bool fBoth);
void free_fight(CHAR_DATA *ch);
CHAR_DATA *who_fighting(CHAR_DATA *ch);
void check_killer(CHAR_DATA *ch, CHAR_DATA *victim);
void check_attacker(CHAR_DATA *ch, CHAR_DATA *victim);
void death_cry(CHAR_DATA *ch);
void stop_hunting(CHAR_DATA *ch);
void stop_hating(CHAR_DATA *ch);
void stop_fearing(CHAR_DATA *ch);
void start_hunting(CHAR_DATA *ch, CHAR_DATA *victim);
void start_hating(CHAR_DATA *ch, CHAR_DATA *victim);
void start_fearing(CHAR_DATA *ch, CHAR_DATA *victim);
bool is_hunting(CHAR_DATA *ch, CHAR_DATA *victim);
bool is_hating(CHAR_DATA *ch, CHAR_DATA *victim);
bool is_fearing(CHAR_DATA *ch, CHAR_DATA *victim);
bool is_safe(CHAR_DATA *ch, CHAR_DATA *victim);
bool is_safe_nm(CHAR_DATA *ch, CHAR_DATA *victim);
bool legal_loot(CHAR_DATA *ch, CHAR_DATA *victim);
bool check_illegal_pk(CHAR_DATA *ch, CHAR_DATA *victim);
OBJ_DATA *raw_kill(CHAR_DATA *ch, CHAR_DATA *victim);
bool in_arena(CHAR_DATA *ch);

/* makeobjs.c */
OBJ_DATA *make_corpse(CHAR_DATA *ch, char *killer);
void make_blood(CHAR_DATA *ch);
void make_bloodstain(CHAR_DATA *ch);
void make_scraps(OBJ_DATA *obj);
void make_fire(ROOM_INDEX_DATA *in_room, short timer);
OBJ_DATA *make_trap(int v0, int v1, int v2, int v3);
OBJ_DATA *create_money(int amount);

/* misc.c */
void actiondesc(CHAR_DATA *ch, OBJ_DATA *obj, void *vo);
void jedi_checks(CHAR_DATA *ch);
void jedi_bonus(CHAR_DATA *ch);
void sith_penalty(CHAR_DATA *ch);

/* mud_comm.c */
const char *mprog_type_to_name(int type);

/* mud_prog.c */
void mprog_wordlist_check(const char *arg, CHAR_DATA *mob, CHAR_DATA *actor, OBJ_DATA *object, void *vo, int type);
void mprog_percent_check(CHAR_DATA *mob, CHAR_DATA *actor, OBJ_DATA *object, void *vo, int type);
void mprog_act_trigger(char *buf, CHAR_DATA *mob, CHAR_DATA *ch, OBJ_DATA *obj, void *vo);
void mprog_bribe_trigger(CHAR_DATA *mob, CHAR_DATA *ch, int amount);
void mprog_entry_trigger(CHAR_DATA *mob);
void mprog_give_trigger(CHAR_DATA *mob, CHAR_DATA *ch, OBJ_DATA *obj);
void mprog_greet_trigger(CHAR_DATA *mob);
void mprog_fight_trigger(CHAR_DATA *mob, CHAR_DATA *ch);
void mprog_hitprcnt_trigger(CHAR_DATA *mob, CHAR_DATA *ch);
void mprog_death_trigger(CHAR_DATA *killer, CHAR_DATA *mob);
void mprog_random_trigger(CHAR_DATA *mob);
void mprog_speech_trigger(const char *txt, CHAR_DATA *mob);
void mprog_script_trigger(CHAR_DATA *mob);
void mprog_hour_trigger(CHAR_DATA *mob);
void mprog_time_trigger(CHAR_DATA *mob);
void progbug(const char *str, CHAR_DATA *mob);
void rset_supermob(ROOM_INDEX_DATA *room);
void release_supermob(void);
void mpsleep_update(void);

/* player.c */
void set_title(CHAR_DATA *ch, const char *title);

/* skills.c */
bool check_skill(CHAR_DATA *ch, const char *command, const char *argument);
void learn_from_success(CHAR_DATA *ch, int sn);
void learn_from_failure(CHAR_DATA *ch, int sn);
bool check_parry(CHAR_DATA *ch, CHAR_DATA *victim);
bool check_dodge(CHAR_DATA *ch, CHAR_DATA *victim);
bool check_grip(CHAR_DATA *ch, CHAR_DATA *victim);
void disarm(CHAR_DATA *ch, CHAR_DATA *victim);
void trip(CHAR_DATA *ch, CHAR_DATA *victim);

/* handler.c */
void free_obj(OBJ_DATA *obj);
void explode(OBJ_DATA *obj);
int get_exp(CHAR_DATA *ch, int ability);
int get_exp_worth(CHAR_DATA *ch);
int exp_level(short level);
short get_trust(CHAR_DATA *ch);
short get_age(CHAR_DATA *ch);
short get_curr_str(CHAR_DATA *ch);
short get_curr_int(CHAR_DATA *ch);
short get_curr_wis(CHAR_DATA *ch);
short get_curr_dex(CHAR_DATA *ch);
short get_curr_con(CHAR_DATA *ch);
short get_curr_cha(CHAR_DATA *ch);
short get_curr_lck(CHAR_DATA *ch);
short get_curr_frc(CHAR_DATA *ch);
bool can_take_proto(CHAR_DATA *ch);
int can_carry_n(CHAR_DATA *ch);
int can_carry_w(CHAR_DATA *ch);
bool is_name(const char *str, const char *namelist);
bool is_name_prefix(const char *str, const char *namelist);
bool nifty_is_name(const char *str, const char *namelist);
bool nifty_is_name_prefix(const char *str, const char *namelist);
void affect_modify(CHAR_DATA *ch, AFFECT_DATA *paf, bool fAdd);
void affect_to_char(CHAR_DATA *ch, AFFECT_DATA *paf);
void affect_remove(CHAR_DATA *ch, AFFECT_DATA *paf);
void affect_strip(CHAR_DATA *ch, int sn);
bool is_affected(CHAR_DATA *ch, int sn);
void affect_join(CHAR_DATA *ch, AFFECT_DATA *paf);
void char_from_room(CHAR_DATA *ch);
void char_to_room(CHAR_DATA *ch, ROOM_INDEX_DATA *pRoomIndex);
OBJ_DATA *obj_to_char(OBJ_DATA *obj, CHAR_DATA *ch);
void obj_from_char(OBJ_DATA *obj);
int apply_ac(OBJ_DATA *obj, int iWear);
OBJ_DATA *get_eq_char(CHAR_DATA *ch, int iWear);
void equip_char(CHAR_DATA *ch, OBJ_DATA *obj, int iWear);
void unequip_char(CHAR_DATA *ch, OBJ_DATA *obj);
int count_obj_list(OBJ_INDEX_DATA *pObjIndex, OBJ_DATA *list);
int count_mob_in_room(MOB_INDEX_DATA *mob, ROOM_INDEX_DATA *list);
void obj_from_room(OBJ_DATA *obj);
OBJ_DATA *obj_to_room(OBJ_DATA *obj, ROOM_INDEX_DATA *pRoomIndex);
OBJ_DATA *obj_to_obj(OBJ_DATA *obj, OBJ_DATA *obj_to);
void obj_from_obj(OBJ_DATA *obj);
void extract_obj(OBJ_DATA *obj);
void extract_exit(ROOM_INDEX_DATA *room, EXIT_DATA *pexit);
void extract_room(ROOM_INDEX_DATA *room);
void clean_room(ROOM_INDEX_DATA *room);
void clean_obj(OBJ_INDEX_DATA *obj);
void clean_mob(MOB_INDEX_DATA *mob);
void clean_resets(ROOM_INDEX_DATA *room);
void extract_char(CHAR_DATA *ch, bool fPull);
CHAR_DATA *get_char_room(CHAR_DATA *ch, const char *argument);
CHAR_DATA *get_char_world(CHAR_DATA *ch, const char *argument);
CHAR_DATA *get_char_world_ooc(CHAR_DATA *ch, const char *argument);
CHAR_DATA *get_char_from_comfreq(CHAR_DATA *ch, const char *argument);
OBJ_DATA *get_obj_type(OBJ_INDEX_DATA *pObjIndexData);
OBJ_DATA *get_obj_list(CHAR_DATA *ch, const char *argument, OBJ_DATA *list);
OBJ_DATA *get_obj_list_rev(CHAR_DATA *ch, const char *argument, OBJ_DATA *list);
OBJ_DATA *get_obj_carry(CHAR_DATA *ch, const char *argument);
OBJ_DATA *get_obj_wear(CHAR_DATA *ch, const char *argument);
OBJ_DATA *get_obj_here(CHAR_DATA *ch, const char *argument);
OBJ_DATA *get_obj_world(CHAR_DATA *ch, const char *argument);
int get_obj_number(OBJ_DATA *obj);
int get_obj_weight(OBJ_DATA *obj);
bool room_is_dark(ROOM_INDEX_DATA *pRoomIndex);
bool room_is_private(CHAR_DATA *ch, ROOM_INDEX_DATA *pRoomIndex);
bool can_see(CHAR_DATA *ch, CHAR_DATA *victim);
bool can_see_obj(CHAR_DATA *ch, OBJ_DATA *obj);
bool can_drop_obj(CHAR_DATA *ch, OBJ_DATA *obj);
const char *item_type_name(OBJ_DATA *obj);
const char *affect_loc_name(int location);
const char *affect_bit_name(int vector);
const char *extra_bit_name(int extra_flags);
const char *magic_bit_name(int magic_flags);
ch_ret check_for_trap(CHAR_DATA *ch, OBJ_DATA *obj, int flag);
ch_ret check_room_for_traps(CHAR_DATA *ch, int flag);
bool is_trapped(OBJ_DATA *obj);
OBJ_DATA *get_trap(OBJ_DATA *obj);
ch_ret spring_trap(CHAR_DATA *ch, OBJ_DATA *obj);
void name_stamp_stats(CHAR_DATA *ch);
void fix_char(CHAR_DATA *ch);
void showaffect(CHAR_DATA *ch, AFFECT_DATA *paf);
void set_cur_obj(OBJ_DATA *obj);
bool obj_extracted(OBJ_DATA *obj);
void queue_extracted_obj(OBJ_DATA *obj);
void clean_obj_queue(void);
void set_cur_char(CHAR_DATA *ch);
bool char_died(CHAR_DATA *ch);
void queue_extracted_char(CHAR_DATA *ch, bool extract);
void clean_char_queue(void);
void add_timer(CHAR_DATA *ch, short type, short count, DO_FUN *fun, int value);
TIMER *get_timerptr(CHAR_DATA *ch, short type);
short get_timer(CHAR_DATA *ch, short type);
void extract_timer(CHAR_DATA *ch, TIMER *timer);
void remove_timer(CHAR_DATA *ch, short type);
bool in_soft_range(CHAR_DATA *ch, AREA_DATA *tarea);
bool in_hard_range(CHAR_DATA *ch, AREA_DATA *tarea);
bool chance(CHAR_DATA *ch, short percent);
OBJ_DATA *clone_object(OBJ_DATA *obj);
void split_obj(OBJ_DATA *obj, int num);
void separate_obj(OBJ_DATA *obj);
bool empty_obj(OBJ_DATA *obj, OBJ_DATA *destobj, ROOM_INDEX_DATA *destroom);
OBJ_DATA *find_obj(CHAR_DATA *ch, const char *argument, bool carryonly);
bool ms_find_obj(CHAR_DATA *ch);
void worsen_mental_state(CHAR_DATA *ch, int mod);
void better_mental_state(CHAR_DATA *ch, int mod);
void boost_economy(AREA_DATA *tarea, int gold);
void lower_economy(AREA_DATA *tarea, int gold);
void economize_mobgold(CHAR_DATA *mob);
bool economy_has(AREA_DATA *tarea, int gold);
void add_kill(CHAR_DATA *ch, CHAR_DATA *mob);
int times_killed(CHAR_DATA *ch, CHAR_DATA *mob);
void check_switches(bool possess);
void check_switch(CHAR_DATA *ch, bool possess);

/* interp.c */
bool check_pos(CHAR_DATA *ch, short position);
void interpret(CHAR_DATA *ch, const char *argument);
bool is_number(const char *arg);
int number_argument(const char *argument, char *arg);
char *one_argument(char *argument, char *arg_first);
const char *one_argument(const char *argument, char *arg_first);
const char *one_argument2(const char *argument, char *arg_first);
SOCIALTYPE *find_social(const char *command, bool exact);
CMDTYPE *find_command(char *command, bool exact);
void hash_commands(void);
void start_timer(struct timeval *sttime);
time_t end_timer(struct timeval *sttime);
void send_timer(struct timerset *vtime, CHAR_DATA *ch);
void update_userec(struct timeval *time_used, struct timerset *userec);

/* magic.c */
bool process_spell_components(CHAR_DATA *ch, int sn);
int ch_slookup(CHAR_DATA *ch, const char *name);
int find_spell(CHAR_DATA *ch, const char *name, bool know);
int find_skill(CHAR_DATA *ch, const char *name, bool know);
int find_weapon(CHAR_DATA *ch, const char *name, bool know);
int find_tongue(CHAR_DATA *ch, const char *name, bool know);
int skill_lookup(const char *name);
int herb_lookup(const char *name);
int personal_lookup(CHAR_DATA *ch, const char *name);
int slot_lookup(int slot);
int bsearch_skill(const char *name, int first, int top);
int bsearch_skill_exact(const char *name, int first, int top);
bool saves_poison_death(int level, CHAR_DATA *victim);
bool saves_wand(int level, CHAR_DATA *victim);
bool saves_para_petri(int level, CHAR_DATA *victim);
bool saves_breath(int level, CHAR_DATA *victim);
bool saves_spell_staff(int level, CHAR_DATA *victim);
ch_ret obj_cast_spell(int sn, int level, CHAR_DATA *ch, CHAR_DATA *victim, OBJ_DATA *obj);
int dice_parse(CHAR_DATA *ch, int level, char *xexp);
SKILLTYPE *get_skilltype(int sn);

/* request.c */
void init_request_pipe(void);
void check_requests(void);

/* save.c */
/* object saving defines for fread/write_obj. -- Altrag */
void write_corpses(CHAR_DATA *ch, char *name);
void save_char_obj(CHAR_DATA *ch);
void save_clone(CHAR_DATA *ch);
void save_profile(CHAR_DATA *ch);
bool load_char_obj(DESCRIPTOR_DATA *d, char *name, bool preload, bool hotboot);
void set_alarm(long seconds);
void requip_char(CHAR_DATA *ch);
void fwrite_obj(CHAR_DATA *ch, OBJ_DATA *obj, FILE *fp, int iNest, short os_type, bool hotboot);
void fread_obj(CHAR_DATA *ch, FILE *fp, short os_type);
void de_equip_char(CHAR_DATA *ch);
void re_equip_char(CHAR_DATA *ch);
void save_home(CHAR_DATA *ch);

/* shops.c */

/* special.c */
SPEC_FUN *spec_lookup(const char *name);

/* tables.c */
int get_skill(const char *skilltype);
char *spell_name(SPELL_FUN *spell);
char *skill_name(DO_FUN *skill);
void load_skill_table(void);
void save_skill_table(int delnum);
void sort_skill_table(void);
void load_socials(void);
void save_socials(void);
void load_commands(void);
void save_commands(void);
SPELL_FUN *spell_function(const char *name);
DO_FUN *skill_function(const char *name);
void load_herb_table(void);
void save_herb_table(void);

/* track.c */
void found_prey(CHAR_DATA *ch, CHAR_DATA *victim);
void hunt_victim(CHAR_DATA *ch);

/* update.c */
void advance_level(CHAR_DATA *ch, int ability);
void gain_exp(CHAR_DATA *ch, int gain, int ability);
void gain_exp2(CHAR_DATA *ch, int gain, int ability);
void gain_condition(CHAR_DATA *ch, int iCond, int value);
void update_handler(void);
void reboot_check(time_t reset);
void auction_update(void);
void remove_portal(OBJ_DATA *portal);
int max_level(CHAR_DATA *ch, int ability);

/* hashstr.c */
char *str_alloc(const char *str);
char *quick_link(const char *str);
int str_free(const char *str);
void show_hash(int count);
char *hash_stats(void);
char *check_hash(const char *str);
void hash_dump(int hash);
void show_high_hash(int top);
bool in_hash_table(const char *str);

/* ships.c */
void load_ship_prototypes(void);
int load_prototype(const char *prototypefile, int prototype);
bool load_prototype_rooms(FILE *fp, int prototype);
bool fread_prototype_room(FILE *fp, int prototype);
bool load_prototype_header(FILE *fp, int prototype);
void write_all_prototypes(void);
void write_prototype_list(void);
void save_prototype(int prototype);
int find_vnum_block(int num_needed);
int make_prototype_rooms(int ship_type, int vnum, AREA_DATA *tarea, char *Sname);
int get_sp_rflag(char *flag);
SHIP_DATA *make_prototype_ship(int ship_type, int vnum, CHAR_DATA *ch, char *ship_name);
void write_ship_list(void);
void resetship(SHIP_DATA *ship);
char *parse_prog_string(char *inp, int ship_type, int vnum);
void make_rprogs(int ship_type, int vnum);

/* functions.c */
char *strrep(const char *src, const char *sch, const char *rep);
char *strlinwrp(const char *src, int length);
char *remand(const char *arg);
char *rembg(const char *arg);
const char *htmlcolor(const char *arg);

/* newscore.c */
const char *get_race(CHAR_DATA *ch);
void oprog_speech_trigger(const char *txt, CHAR_DATA *ch);
void oprog_random_trigger(OBJ_DATA *obj);
void oprog_wear_trigger(CHAR_DATA *ch, OBJ_DATA *obj);
bool oprog_use_trigger(CHAR_DATA *ch, OBJ_DATA *obj, CHAR_DATA *vict, OBJ_DATA *targ, void *vo);
void oprog_remove_trigger(CHAR_DATA *ch, OBJ_DATA *obj);
void oprog_sac_trigger(CHAR_DATA *ch, OBJ_DATA *obj);
void oprog_damage_trigger(CHAR_DATA *ch, OBJ_DATA *obj);
void oprog_repair_trigger(CHAR_DATA *ch, OBJ_DATA *obj);
void oprog_drop_trigger(CHAR_DATA *ch, OBJ_DATA *obj);
// void oprog_zap_trigger( CHAR_DATA *ch, OBJ_DATA *obj );
char *oprog_type_to_name(int type);
int rprog_custom_trigger(const char *command, const char *argument, CHAR_DATA *ch);
int mprog_custom_trigger(const char *command, const char *argument, CHAR_DATA *ch);
int oprog_custom_trigger(const char *command, const char *argument, CHAR_DATA *ch);
void oprog_greet_trigger(CHAR_DATA *ch);
void oprog_get_trigger(CHAR_DATA *ch, OBJ_DATA *obj);
void oprog_examine_trigger(CHAR_DATA *ch, OBJ_DATA *obj);
void oprog_pull_trigger(CHAR_DATA *ch, OBJ_DATA *obj);
void oprog_push_trigger(CHAR_DATA *ch, OBJ_DATA *obj);
void rprog_leave_trigger(CHAR_DATA *ch);
void rprog_enter_trigger(CHAR_DATA *ch);
void rprog_sleep_trigger(CHAR_DATA *ch);
void rprog_rest_trigger(CHAR_DATA *ch);
void rprog_rfight_trigger(CHAR_DATA *ch);
void rprog_death_trigger(CHAR_DATA *killer, CHAR_DATA *ch);
void rprog_speech_trigger(const char *txt, CHAR_DATA *ch);
void rprog_random_trigger(CHAR_DATA *ch);
void rprog_time_trigger(CHAR_DATA *ch);
void rprog_hour_trigger(CHAR_DATA *ch);
char *rprog_type_to_name(int type);
void oprog_act_trigger(char *buf, OBJ_DATA *mobj, CHAR_DATA *ch, OBJ_DATA *obj, void *vo);
void rprog_act_trigger(char *buf, ROOM_INDEX_DATA *room, CHAR_DATA *ch, OBJ_DATA *obj, void *vo);
bool is_valid_vnum(int vnum, short type);

/* ships.c */
void load_market_list(void);
void save_market_list(void);
void add_market_ship(SHIP_DATA *ship);
void remove_market_ship(BMARKET_DATA *marketship);
void make_random_marketlist(void);
BMARKET_DATA *get_market_ship(const char *name);
void show_market(CHAR_DATA *ch);
void buy_ship(CHAR_DATA *ch, const char *argument);
void sell_ship(CHAR_DATA *ch, const char *argument);
void value_ship(CHAR_DATA *ch, const char *argument);
bool ship_in_list(SHIP_DATA *ship);
void clear_market_list(void);
void update_market(void);
void free_marketlist(void);