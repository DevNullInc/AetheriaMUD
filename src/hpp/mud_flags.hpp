#pragma once
#include <ctime>
// All function prototypes from mud.hpp

/* act_comm.cpp */
bool check_parse_name( const char *name );
void sound_to_room( ROOM_INDEX_DATA * room, const char *argument );
bool circle_follow( CHAR_DATA * ch, CHAR_DATA * victim );
void add_follower( CHAR_DATA * ch, CHAR_DATA * master );
void stop_follower( CHAR_DATA * ch );
void die_follower( CHAR_DATA * ch );
bool is_same_group( CHAR_DATA * ach, CHAR_DATA * bch );
void send_rip_screen( CHAR_DATA * ch );
void send_rip_title( CHAR_DATA * ch );
void send_ansi_title( CHAR_DATA * ch );
void send_ascii_title( CHAR_DATA * ch );
void to_channel( const char *argument, int channel, const char *verb, short level );
void talk_auction( char *argument );
bool knows_language( CHAR_DATA * ch, int language, CHAR_DATA * cch );
bool can_learn_lang( CHAR_DATA * ch, int language );
int countlangs( int languages );
char *obj_short( OBJ_DATA * obj );
/* act_info.cpp */
int get_door( const char *arg );
char *format_obj_to_char( OBJ_DATA * obj, CHAR_DATA * ch, bool fShort );
void show_list_to_char( OBJ_DATA * list, CHAR_DATA * ch, bool fShort, bool fShowNothing );
/* act_move.cpp */
void clear_vrooms( void );
ED *find_door( CHAR_DATA * ch, const char *arg, bool quiet );
ED *get_exit( ROOM_INDEX_DATA * room, short dir );
ED *get_exit_to( ROOM_INDEX_DATA * room, short dir, int vnum );
ED *get_exit_num( ROOM_INDEX_DATA * room, short count );
ch_ret move_char( CHAR_DATA * ch, EXIT_DATA * pexit, int fall );
void teleport( CHAR_DATA * ch, int room, int flags );
short encumbrance( CHAR_DATA * ch, short move );
bool will_fall( CHAR_DATA * ch, int fall );
int wherehome( CHAR_DATA * ch );
/* act_obj.cpp */
obj_ret damage_obj( OBJ_DATA * obj );
short get_obj_resistance( OBJ_DATA * obj );
bool remove_obj( CHAR_DATA * ch, int iWear, bool fReplace );
void save_clan_storeroom( CHAR_DATA * ch, CLAN_DATA * clan );
void obj_fall( OBJ_DATA * obj, bool through );
/* act_wiz.cpp */
void close_area( AREA_DATA * pArea );
AREA_DATA *get_area( const char *argument );
RID *find_location( CHAR_DATA * ch, char *arg );
void echo_to_room( short AT_COLOR, ROOM_INDEX_DATA * room, const char *argument );
void echo_to_all( short AT_COLOR, const char *argument, short tar );
void get_reboot_string( void );
struct tm *update_time( struct tm * old_time );
void free_social( SOCIALTYPE * social );
void add_social( SOCIALTYPE * social );
void free_command( CMDTYPE * command );
void unlink_command( CMDTYPE * command );
void add_command( CMDTYPE * command );
/* boards.cpp */
void load_boards( void );
BD *get_board( OBJ_DATA * obj );
void free_note( NOTE_DATA * pnote );
/* bounty.cpp */
BOUNTY_DATA *get_disintegration( const char *target );
void load_bounties( void );
void save_bounties( void );
void save_disintegrations( void );
void remove_disintegration( BOUNTY_DATA * bounty );
void claim_disintegration( CHAR_DATA * ch, CHAR_DATA * victim );
bool is_disintegration( CHAR_DATA * victim );
/* build.cpp */
const char *flag_string( int bitvector, const char *const flagarray[] );
char *strip_cr( const char *str );
int get_vip_flag( const char *flag );
int get_wanted_flag( const char *flag );
int get_flag( const char *, const char *const flagarray[], int );
int get_otype( const char *type );
int get_atype( const char *type );
int get_aflag( const char *flag );
int get_oflag( const char *flag );
int get_wflag( const char *flag );
int get_risflag( const char *flag );
int get_attackflag( const char *flag );
int get_defenseflag( const char *flag );
int get_langnum( const char *flag );
int get_langnum_save( const char *flag );
int get_langflag( const char *flag );
int get_exflag( const char *flag );
int get_rflag( const char *flag );
int get_rflag2( const char *flag );
int get_secflag( const char *flag );
int get_actflag( const char *flag );
int get_cmdflag( const char *flag );
int get_npc_race( const char *type );
int get_pc_race( const char *type );
int get_npc_sex( const char *sex );
int get_areaflag( const char *flag );
int get_mpflag( const char *flag );
int get_trigflag( const char *flag );
int get_dir( const char *txt );
int get_partflag( const char *flag );
int get_npc_position( const char *position );
/* build.cpp */
const char *flag_string( int bitvector, const char *const flagarray[] );
char *strip_cr( const char *str );
int get_vip_flag( const char *flag );
int get_wanted_flag( const char *flag );
int get_flag( const char *, const char *const flagarray[], int );
int get_otype( const char *type );
int get_atype( const char *type );
int get_aflag( const char *flag );
int get_oflag( const char *flag );
int get_wflag( const char *flag );
int get_risflag( const char *flag );
int get_attackflag( const char *flag );
int get_defenseflag( const char *flag );
int get_langnum( const char *flag );
int get_langnum_save( const char *flag );
int get_langflag( const char *flag );
int get_exflag( const char *flag );
int get_rflag( const char *flag );
int get_rflag2( const char *flag );
int get_secflag( const char *flag );
int get_actflag( const char *flag );
int get_cmdflag( const char *flag );
int get_npc_race( const char *type );
int get_pc_race( const char *type );
int get_npc_sex( const char *sex );
int get_areaflag( const char *flag );
int get_mpflag( const char *flag );
int get_trigflag( const char *flag );
int get_dir( const char *txt );
int get_partflag( const char *flag );
int get_npc_position( const char *position );
/* clans.cpp */
CL *get_clan( const char *name );
void load_clans( void );
void save_clan( CLAN_DATA * clan );
void load_senate( void );
void save_senate( void );
PLANET_DATA *get_planet( const char *name );
void load_planets( void );
void save_planet( PLANET_DATA * planet );
long get_taxes( PLANET_DATA * planet );
/* comm.cpp */
const char *PERS( CHAR_DATA * ch, CHAR_DATA * looker );
FELLOW_DATA *knowsof( CHAR_DATA * ch, CHAR_DATA * victim );
void close_socket( DESCRIPTOR_DATA * dclose, bool force );
bool write_to_descriptor( DESCRIPTOR_DATA * d, const char *txt, int length );
void write_to_buffer( DESCRIPTOR_DATA * d, const char *txt, size_t length );
void write_to_pager( DESCRIPTOR_DATA * d, const char *txt, size_t length );
void send_to_char( const char *txt, CHAR_DATA * ch );
void send_to_char_color( const char *txt, CHAR_DATA * ch );
void send_to_char_noand( const char *txt, CHAR_DATA * ch );
void send_to_pager( const char *txt, CHAR_DATA * ch );
void send_to_pager_color( const char *txt, CHAR_DATA * ch );
void ch_printf( CHAR_DATA * ch, const char *fmt, ... ) __attribute__ ( ( format( printf, 2, 3 ) ) );
char *chrmax( char *src, int length );
int strlen_color( char *argument );
char *format_str( char *str, int len );
void pager_printf( CHAR_DATA * ch, const char *fmt, ... ) __attribute__ ( ( format( printf, 2, 3 ) ) );
void log_string_plus( const char *str, short log_type, short level );
void log_printf_plus( short log_type, short level, const char *fmt, ... ) __attribute__ ( ( format( printf, 3, 4 ) ) );
void log_printf( const char *fmt, ... ) __attribute__ ( ( format( printf, 1, 2 ) ) );
void descriptor_printf( DESCRIPTOR_DATA * d, const char *fmt, ... ) __attribute__ ( ( format( printf, 2, 3 ) ) );
void buffer_printf( DESCRIPTOR_DATA * d, const char *fmt, ... ) __attribute__ ( ( format( printf, 2, 3 ) ) );
void act( short AType, const char *format, CHAR_DATA * ch, const void *arg1, const void *arg2, int type );
/* db.cpp */
char *fread_flagstring( FILE * fp );
void show_file( CHAR_DATA * ch, const char *filename );
bool is_valid_filename( CHAR_DATA * ch, const char *direct, const char *filename );
char *str_dup( char const *str );
const char *centertext( const char *text, size_t size );
void boot_db( bool fCopyOver );
void area_update( void );
void add_char( CHAR_DATA * ch );
CD *create_mobile( MOB_INDEX_DATA * pMobIndex );
OD *create_object( OBJ_INDEX_DATA * pObjIndex, int level );
void clear_char( CHAR_DATA * ch );
void free_char( CHAR_DATA * ch );
char *get_extra_descr( const char *name, EXTRA_DESCR_DATA * ed );
MID *get_mob_index( int vnum );
OID *get_obj_index( int vnum );
RID *get_room_index( int vnum );
char fread_letter( FILE * fp );
int fread_number( FILE * fp );
float fread_float( FILE * fp );
char *fread_string( FILE * fp );
char *fread_string_nohash( FILE * fp );
void fread_to_eol( FILE * fp );
char *fread_word( FILE * fp );
char *fread_line( FILE * fp );
int number_fuzzy( int number );
int number_range( int from, int to );
int number_percent( void );
int number_door( void );
int number_bits( int width );
int number_mm( void );
int dice( int number, int size );
int interpolate( int level, int value_00, int value_32 );
void smash_tilde( char *str );
const char *smash_tilde( const char *str );
char *smash_tilde_copy( const char *str );
void hide_tilde( char *str );
char *show_tilde( const char *str );
bool str_cmp( const char *astr, const char *bstr );
bool str_prefix( const char *astr, const char *bstr );
bool str_infix( const char *astr, const char *bstr );
bool str_suffix( const char *astr, const char *bstr );
char *capitalize( const char *str );
char *strlower( const char *str );
char *strupper( const char *str );
const char *aoran( const char *str );
void append_file( CHAR_DATA * ch, const char *file, const char *str );
void append_to_file( const char *file, const char *str );
void prepend_to_file( const char *file, const char *str );
void bug( const char *str, ... );
RID *make_room( int vnum, AREA_DATA * area );
RID *make_ship_room( SHIP_DATA * ship, int vnum );
OID *make_object( int vnum, int cvnum, const char *name );
MID *make_mobile( int vnum, int cvnum, const char *name );
ED *make_exit( ROOM_INDEX_DATA * pRoomIndex, ROOM_INDEX_DATA * to_room, short door );
void add_help( HELP_DATA * pHelp );
void fix_area_exits( AREA_DATA * tarea );
void load_area_file( AREA_DATA * tarea, const char *filename );
void randomize_exits( ROOM_INDEX_DATA * room, short maxdir );
void make_wizlist( void );
void tail_chain( void );
void delete_room( ROOM_INDEX_DATA * room );
void delete_obj( OBJ_INDEX_DATA * obj );
void delete_mob( MOB_INDEX_DATA * mob );
void sort_area( AREA_DATA * pArea, bool proto );
void sort_area_by_name( AREA_DATA * pArea ); /* Fireblade */
size_t mudstrlcat( char * __restrict dst, const char * __restrict src, size_t dsize );
size_t mudstrlcpy( char * __restrict dst, const char * __restrict src, size_t dsize );
/* editor.cpp cronel new editor */
#define start_editing( ch, data ) \
	start_editing_nolimit( ch, data, MAX_STRING_LENGTH )
void start_editing_nolimit( CHAR_DATA * ch, char *data, short max_size );
void stop_editing( CHAR_DATA * ch );
void edit_buffer( CHAR_DATA * ch, char *argument );
char *copy_buffer( CHAR_DATA * ch );
void set_editor_desc( CHAR_DATA * ch, char *desc );
void editor_desc_printf( CHAR_DATA * ch, const char *desc_fmt, ... );
/* fight.cpp */
int max_fight( CHAR_DATA * ch );
void violence_update( void );
ch_ret multi_hit( CHAR_DATA * ch, CHAR_DATA * victim, int dt );
short ris_damage( CHAR_DATA * ch, short dam, int ris );
ch_ret damage( CHAR_DATA * ch, CHAR_DATA * victim, int dam, int dt );
void update_pos( CHAR_DATA * victim );
void set_fighting( CHAR_DATA * ch, CHAR_DATA * victim );
void stop_fighting( CHAR_DATA * ch, bool fBoth );
void free_fight( CHAR_DATA * ch );
CD *who_fighting( CHAR_DATA * ch );
void check_killer( CHAR_DATA * ch, CHAR_DATA * victim );
void check_attacker( CHAR_DATA * ch, CHAR_DATA * victim );
void death_cry( CHAR_DATA * ch );
void stop_hunting( CHAR_DATA * ch );
void stop_hating( CHAR_DATA * ch );
void stop_fearing( CHAR_DATA * ch );
void start_hunting( CHAR_DATA * ch, CHAR_DATA * victim );
void start_hating( CHAR_DATA * ch, CHAR_DATA * victim );
void start_fearing( CHAR_DATA * ch, CHAR_DATA * victim );
bool is_hunting( CHAR_DATA * ch, CHAR_DATA * victim );
bool is_hating( CHAR_DATA * ch, CHAR_DATA * victim );
bool is_fearing( CHAR_DATA * ch, CHAR_DATA * victim );
bool is_safe( CHAR_DATA * ch, CHAR_DATA * victim );
bool is_safe_nm( CHAR_DATA * ch, CHAR_DATA * victim );
bool legal_loot( CHAR_DATA * ch, CHAR_DATA * victim );
bool check_illegal_pk( CHAR_DATA * ch, CHAR_DATA * victim );
OBJ_DATA *raw_kill( CHAR_DATA * ch, CHAR_DATA * victim );
bool in_arena( CHAR_DATA * ch );
/* force.cpp */
bool check_reflect( CHAR_DATA * ch, CHAR_DATA * victim, int dam );
void write_all_forceskills( void );
void save_forceskill( FORCE_SKILL * fskill );
void write_forceskill_list( void );
bool load_forceskill( const char *forceskillfile );
void fread_forceskill( FORCE_SKILL * fskill, FILE * fp );
void write_all_forcehelps( void );
void save_forcehelp( FORCE_HELP * fhelp );
void write_forcehelp_list( void );
bool load_forcehelp( const char *forcehelpfile );
void fread_forcehelp( FORCE_HELP * fhelp, FILE * fp );
int check_force_skill( CHAR_DATA * ch, const char *command, const char *argument );
void load_force_skills( void );
void load_force_help( void );
DO_FUN *get_force_skill_function( const char *name );
FORCE_SKILL *get_force_skill( const char *argument );
FORCE_HELP *get_force_help( const char *fname, const char *type );
void force_send_to_room( CHAR_DATA * ch, CHAR_DATA * victim, const char *msg );
CHAR_DATA *force_get_victim( CHAR_DATA * ch, const char *argument, int loc );
const char *force_get_possessive( CHAR_DATA * ch );
const char *force_get_objective( CHAR_DATA * ch );
const char *force_get_pronoun( CHAR_DATA * ch );
char *force_parse_string( CHAR_DATA * ch, CHAR_DATA * victim, const char *msg );
void force_learn_from_failure( CHAR_DATA * ch, FORCE_SKILL * fskill );
void force_learn_from_success( CHAR_DATA * ch, FORCE_SKILL * fskill );
FORCE_SKILL *force_test_skill_use( const char *skill_name, CHAR_DATA * ch, int skill_type );
const char *force_get_level( CHAR_DATA * ch );
int force_promote_ready( CHAR_DATA * ch );
void draw_force_line( CHAR_DATA * ch, int length );
void draw_force_line_rev( CHAR_DATA * ch, int length );
void update_force( void );
/* functions.cpp */
char *strrep( const char *src, const char *sch, const char *rep );
char *strlinwrp( const char *src, int length );
char *remand( const char *arg );
char *rembg( const char *arg );
const char *htmlcolor( const char *arg );
/* handler.cpp */
void free_obj( OBJ_DATA * obj );
void explode( OBJ_DATA * obj );
int get_exp( CHAR_DATA * ch, int ability );
int get_exp_worth( CHAR_DATA * ch );
int exp_level( short level );
short get_trust( CHAR_DATA * ch );
short get_age( CHAR_DATA * ch );
short get_curr_str( CHAR_DATA * ch );
short get_curr_int( CHAR_DATA * ch );
short get_curr_wis( CHAR_DATA * ch );
short get_curr_dex( CHAR_DATA * ch );
short get_curr_con( CHAR_DATA * ch );
short get_curr_cha( CHAR_DATA * ch );
short get_curr_lck( CHAR_DATA * ch );
short get_curr_frc( CHAR_DATA * ch );
bool can_take_proto( CHAR_DATA * ch );
int can_carry_n( CHAR_DATA * ch );
int can_carry_w( CHAR_DATA * ch );
bool is_name( const char *str, const char *namelist );
bool is_name_prefix( const char *str, const char *namelist );
bool nifty_is_name( const char *str, const char *namelist );
bool nifty_is_name_prefix( const char *str, const char *namelist );
void affect_modify( CHAR_DATA * ch, AFFECT_DATA * paf, bool fAdd );
void affect_to_char( CHAR_DATA * ch, AFFECT_DATA * paf );
void affect_remove( CHAR_DATA * ch, AFFECT_DATA * paf );
void affect_strip( CHAR_DATA * ch, int sn );
bool is_affected( CHAR_DATA * ch, int sn );
void affect_join( CHAR_DATA * ch, AFFECT_DATA * paf );
void char_from_room( CHAR_DATA * ch );
void char_to_room( CHAR_DATA * ch, ROOM_INDEX_DATA * pRoomIndex );
OD *obj_to_char( OBJ_DATA * obj, CHAR_DATA * ch );
void obj_from_char( OBJ_DATA * obj );
int apply_ac( OBJ_DATA * obj, int iWear );
OD *get_eq_char( CHAR_DATA * ch, int iWear );
void equip_char( CHAR_DATA * ch, OBJ_DATA * obj, int iWear );
void unequip_char( CHAR_DATA * ch, OBJ_DATA * obj );
int count_obj_list( OBJ_INDEX_DATA * pObjIndex, OBJ_DATA * list );
int count_mob_in_room( MOB_INDEX_DATA * mob, ROOM_INDEX_DATA * list );
void obj_from_room( OBJ_DATA * obj );
OD *obj_to_room( OBJ_DATA * obj, ROOM_INDEX_DATA * pRoomIndex );
OD *obj_to_obj( OBJ_DATA * obj, OBJ_DATA * obj_to );
void obj_from_obj( OBJ_DATA * obj );
void extract_obj( OBJ_DATA * obj );
void extract_exit( ROOM_INDEX_DATA * room, EXIT_DATA * pexit );
void extract_room( ROOM_INDEX_DATA * room );
void clean_room( ROOM_INDEX_DATA * room );
void clean_obj( OBJ_INDEX_DATA * obj );
void clean_mob( MOB_INDEX_DATA * mob );
void clean_resets( ROOM_INDEX_DATA * room );
void extract_char( CHAR_DATA * ch, bool fPull );
CD *get_char_room( CHAR_DATA * ch, const char *argument );
CD *get_char_world( CHAR_DATA * ch, const char *argument );
CD *get_char_world_ooc( CHAR_DATA * ch, const char *argument );
CD *get_char_from_comfreq( CHAR_DATA * ch, const char *argument );
OD *get_obj_type( OBJ_INDEX_DATA * pObjIndexData );
OD *get_obj_list( CHAR_DATA * ch, const char *argument, OBJ_DATA * list );
OD *get_obj_list_rev( CHAR_DATA * ch, const char *argument, OBJ_DATA * list );
OD *get_obj_carry( CHAR_DATA * ch, const char *argument );
OD *get_obj_wear( CHAR_DATA * ch, const char *argument );
OD *get_obj_here( CHAR_DATA * ch, const char *argument );
OD *get_obj_world( CHAR_DATA * ch, const char *argument );
int get_obj_number( OBJ_DATA * obj );
int get_obj_weight( OBJ_DATA * obj );
bool room_is_dark( ROOM_INDEX_DATA * pRoomIndex );
bool room_is_private( CHAR_DATA * ch, ROOM_INDEX_DATA * pRoomIndex );
bool can_see( CHAR_DATA * ch, CHAR_DATA * victim );
bool can_see_obj( CHAR_DATA * ch, OBJ_DATA * obj );
bool can_drop_obj( CHAR_DATA * ch, OBJ_DATA * obj );
const char *item_type_name( OBJ_DATA * obj );
const char *affect_loc_name( int location );
const char *affect_bit_name( int vector );
const char *extra_bit_name( int extra_flags );
const char *magic_bit_name( int magic_flags );
ch_ret check_for_trap( CHAR_DATA * ch, OBJ_DATA * obj, int flag );
ch_ret check_room_for_traps( CHAR_DATA * ch, int flag );
bool is_trapped( OBJ_DATA * obj );
OD *get_trap( OBJ_DATA * obj );
ch_ret spring_trap( CHAR_DATA * ch, OBJ_DATA * obj );
void name_stamp_stats( CHAR_DATA * ch );
void fix_char( CHAR_DATA * ch );
void showaffect( CHAR_DATA * ch, AFFECT_DATA * paf );
void set_cur_obj( OBJ_DATA * obj );
bool obj_extracted( OBJ_DATA * obj );
void queue_extracted_obj( OBJ_DATA * obj );
void clean_obj_queue( void );
void set_cur_char( CHAR_DATA * ch );
bool char_died( CHAR_DATA * ch );
void queue_extracted_char( CHAR_DATA * ch, bool extract );
void clean_char_queue( void );
void add_timer( CHAR_DATA * ch, short type, short count, DO_FUN * fun, int value );
TIMER *get_timerptr( CHAR_DATA * ch, short type );
short get_timer( CHAR_DATA * ch, short type );
void extract_timer( CHAR_DATA * ch, TIMER * timer );
void remove_timer( CHAR_DATA * ch, short type );
bool in_soft_range( CHAR_DATA * ch, AREA_DATA * tarea );
bool in_hard_range( CHAR_DATA * ch, AREA_DATA * tarea );
bool chance( CHAR_DATA * ch, short percent );
OD *clone_object( OBJ_DATA * obj );
void split_obj( OBJ_DATA * obj, int num );
void separate_obj( OBJ_DATA * obj );
bool empty_obj( OBJ_DATA * obj, OBJ_DATA * destobj, ROOM_INDEX_DATA * destroom );
OD *find_obj( CHAR_DATA * ch, const char *argument, bool carryonly );
bool ms_find_obj( CHAR_DATA * ch );
void worsen_mental_state( CHAR_DATA * ch, int mod );
void better_mental_state( CHAR_DATA * ch, int mod );
void boost_economy( AREA_DATA * tarea, int gold );
void lower_economy( AREA_DATA * tarea, int gold );
void economize_mobgold( CHAR_DATA * mob );
bool economy_has( AREA_DATA * tarea, int gold );
void add_kill( CHAR_DATA * ch, CHAR_DATA * mob );
int times_killed( CHAR_DATA * ch, CHAR_DATA * mob );
void check_switches( bool possess );
void check_switch( CHAR_DATA * ch, bool possess );
/* hashstr.cpp */
char *str_alloc( const char *str );
char *quick_link( const char *str );
int str_free( const char *str );
void show_hash( int count );
char *hash_stats( void );
char *check_hash( const char *str );
void hash_dump( int hash );
void show_high_hash( int top );
bool in_hash_table( const char *str );
/* interp.cpp */
bool check_pos( CHAR_DATA * ch, short position );
void interpret( CHAR_DATA * ch, const char *argument );
bool is_number( const char *arg );
int number_argument( const char *argument, char *arg );
char *one_argument( char *argument, char *arg_first );
const char *one_argument( const char *argument, char *arg_first );
const char *one_argument2( const char *argument, char *arg_first );
ST *find_social( const char *command, bool exact );
CMDTYPE *find_command( char *command, bool exact );
void hash_commands( void );
void start_timer( struct timeval * sttime );
time_t end_timer( struct timeval * sttime );
void send_timer( struct timerset * vtime, CHAR_DATA * ch );
void update_userec( struct timeval * time_used, struct timerset * userec );
/* magic.cpp */
bool process_spell_components( CHAR_DATA * ch, int sn );
int ch_slookup( CHAR_DATA * ch, const char *name );
int find_spell( CHAR_DATA * ch, const char *name, bool know );
int find_skill( CHAR_DATA * ch, const char *name, bool know );
int find_weapon( CHAR_DATA * ch, const char *name, bool know );
int find_tongue( CHAR_DATA * ch, const char *name, bool know );
int skill_lookup( const char *name );
int herb_lookup( const char *name );
int personal_lookup( CHAR_DATA * ch, const char *name );
int slot_lookup( int slot );
int bsearch_skill( const char *name, int first, int top );
int bsearch_skill_exact( const char *name, int first, int top );
bool saves_poison_death( int level, CHAR_DATA * victim );
bool saves_wand( int level, CHAR_DATA * victim );
bool saves_para_petri( int level, CHAR_DATA * victim );
bool saves_breath( int level, CHAR_DATA * victim );
bool saves_spell_staff( int level, CHAR_DATA * victim );
ch_ret obj_cast_spell( int sn, int level, CHAR_DATA * ch, CHAR_DATA * victim, OBJ_DATA * obj );
int dice_parse( CHAR_DATA * ch, int level, char *xexp );
SK *get_skilltype( int sn );
/* makeobjs.cpp */
OBJ_DATA *make_corpse( CHAR_DATA * ch, char *killer );
void make_blood( CHAR_DATA * ch );
void make_bloodstain( CHAR_DATA * ch );
void make_scraps( OBJ_DATA * obj );
void make_fire( ROOM_INDEX_DATA * in_room, short timer );
OD *make_trap( int v0, int v1, int v2, int v3 );
OD *create_money( int amount );
/* misc.cpp */
void actiondesc( CHAR_DATA * ch, OBJ_DATA * obj, void *vo );
void jedi_checks( CHAR_DATA * ch );
void jedi_bonus( CHAR_DATA * ch );
void sith_penalty( CHAR_DATA * ch );
/* mud_comm.cpp */
const char *mprog_type_to_name( int type );
/* mud_prog.cpp */
void mprog_wordlist_check( const char *arg, CHAR_DATA * mob, CHAR_DATA * actor, OBJ_DATA * object, void *vo, int type );
void mprog_percent_check( CHAR_DATA * mob, CHAR_DATA * actor, OBJ_DATA * object, void *vo, int type );
void mprog_act_trigger( char *buf, CHAR_DATA * mob, CHAR_DATA * ch, OBJ_DATA * obj, void *vo );
void mprog_bribe_trigger( CHAR_DATA * mob, CHAR_DATA * ch, int amount );
void mprog_entry_trigger( CHAR_DATA * mob );
void mprog_give_trigger( CHAR_DATA * mob, CHAR_DATA * ch, OBJ_DATA * obj );
void mprog_greet_trigger( CHAR_DATA * mob );
void mprog_fight_trigger( CHAR_DATA * mob, CHAR_DATA * ch );
void mprog_hitprcnt_trigger( CHAR_DATA * mob, CHAR_DATA * ch );
void mprog_death_trigger( CHAR_DATA * killer, CHAR_DATA * mob );
void mprog_random_trigger( CHAR_DATA * mob );
void mprog_speech_trigger( const char *txt, CHAR_DATA * mob );
void mprog_script_trigger( CHAR_DATA * mob );
void mprog_hour_trigger( CHAR_DATA * mob );
void mprog_time_trigger( CHAR_DATA * mob );
void progbug( const char *str, CHAR_DATA * mob );
void rset_supermob( ROOM_INDEX_DATA * room );
void release_supermob( void );
void mpsleep_update( void );
/* newarena.cpp */
void show_jack_pot( void );
void do_game( void );
int num_in_arena( void );
void find_game_winner( void );
void do_end_game( void );
void start_game( void );
void silent_end( void );
void write_fame_list( void );
void load_hall_of_fame( void );
/* pfiles.cpp */
void remove_member( char *name, char *shortname );
void add_member( char *name, char *shortname );
/* player.cpp */
void set_title( CHAR_DATA * ch, const char *title );
/* request.cpp */
void init_request_pipe( void );
void check_requests( void );
/* reset.cpp */
RD *make_reset( char letter, int extra, int arg1, int arg2, int arg3 );
RD *add_reset( ROOM_INDEX_DATA * room, char letter, int extra, int arg1, int arg2, int arg3 );
void reset_area( AREA_DATA * pArea );
/* save.cpp */
#define OS_CARRY	0
#define OS_CORPSE	1
void write_corpses( CHAR_DATA * ch, char *name );
void save_char_obj( CHAR_DATA * ch );
void save_clone( CHAR_DATA * ch );
void save_profile( CHAR_DATA * ch );
bool load_char_obj( DESCRIPTOR_DATA * d, char *name, bool preload, bool hotboot );
void set_alarm( long seconds );
void requip_char( CHAR_DATA * ch );
void fwrite_obj( CHAR_DATA * ch, OBJ_DATA * obj, FILE * fp, int iNest, short os_type, bool hotboot );
void fread_obj( CHAR_DATA * ch, FILE * fp, short os_type );
void de_equip_char( CHAR_DATA * ch );
void re_equip_char( CHAR_DATA * ch );
void save_home( CHAR_DATA * ch );
/* ships.cpp */
void load_ship_prototypes( void );
int load_prototype( const char *prototypefile, int prototype );
bool load_prototype_rooms( FILE * fp, int prototype );
bool fread_prototype_room( FILE * fp, int prototype );
bool load_prototype_header( FILE * fp, int prototype );
void write_all_prototypes( void );
void write_prototype_list( void );
void save_prototype( int prototype );
int find_vnum_block( int num_needed );
int make_prototype_rooms( int ship_type, int vnum, AREA_DATA * tarea, char *Sname );
int get_sp_rflag( char *flag );
SHIP_DATA *make_prototype_ship( int ship_type, int vnum, CHAR_DATA * ch, char *ship_name );
void write_ship_list( void );
void resetship( SHIP_DATA * ship );
char *parse_prog_string( char *inp, int ship_type, int vnum );
void make_rprogs( int ship_type, int vnum );
/* shops.cpp (Nothing here...yet) */
/* skills.cpp */
bool check_skill( CHAR_DATA * ch, const char *command, const char *argument );
void learn_from_success( CHAR_DATA * ch, int sn );
void learn_from_failure( CHAR_DATA * ch, int sn );
bool check_parry( CHAR_DATA * ch, CHAR_DATA * victim );
bool check_dodge( CHAR_DATA * ch, CHAR_DATA * victim );
bool check_grip( CHAR_DATA * ch, CHAR_DATA * victim );
void disarm( CHAR_DATA * ch, CHAR_DATA * victim );
void trip( CHAR_DATA * ch, CHAR_DATA * victim );
/* space.cpp */
SH *get_ship( const char *name );
void load_ships( void );
void placeships( void );
void save_ship( SHIP_DATA * ship );
void load_space( void );
void save_starsystem( SPACE_DATA * starsystem );
SPACE_DATA *starsystem_from_name( const char *name );
SPACE_DATA *starsystem_from_room( ROOM_INDEX_DATA * room );
SHIP_DATA *ship_from_entrance( int vnum );
SHIP_DATA *ship_from_room( int vnum );
SHIP_DATA *ship_from_hanger( int vnum );
SHIP_DATA *ship_from_pilotseat( int vnum );
SHIP_DATA *ship_from_cockpit( int vnum );
SHIP_DATA *ship_from_turret( int vnum );
SHIP_DATA *ship_from_engine( int vnum );
SHIP_DATA *ship_from_pilot( const char *name );
SHIP_DATA *get_ship_here( const char *name, SPACE_DATA * starsystem );
void showstarsystem( CHAR_DATA * ch, SPACE_DATA * starsystem );
void update_space( void );
void recharge_ships( void );
void move_ships( void );
void update_bus( void );
void update_traffic( void );
bool check_pilot( CHAR_DATA * ch, SHIP_DATA * ship );
bool is_rental( CHAR_DATA * ch, SHIP_DATA * ship );
void echo_to_ship( int color, SHIP_DATA * ship, const char *argument );
void echo_to_cockpit( int color, SHIP_DATA * ship, const char *argument );
void echo_to_system( int color, SHIP_DATA * ship, const char *argument, SHIP_DATA * ignore );
bool extract_ship( SHIP_DATA * ship );
bool ship_to_room( SHIP_DATA * ship, int vnum );
bool ship_to_room2( SHIP_DATA * ship, ROOM_INDEX_DATA * shipto );
long get_ship_value( SHIP_DATA * ship );
bool rent_ship( CHAR_DATA * ch, SHIP_DATA * ship );
void damage_ship( SHIP_DATA * ship, int min, int max );
void damage_ship_ch( SHIP_DATA * ship, int min, int max, CHAR_DATA * ch );
void destroy_ship( SHIP_DATA * ship, CHAR_DATA * ch, const char *reason );
void ship_to_starsystem( SHIP_DATA * ship, SPACE_DATA * starsystem );
void ship_from_starsystem( SHIP_DATA * ship, SPACE_DATA * starsystem );
void new_missile( SHIP_DATA * ship, SHIP_DATA * target, CHAR_DATA * ch, int missiletype );
void extract_missile( MISSILE_DATA * missile );
SHIP_DATA *ship_in_room( ROOM_INDEX_DATA * room, const char *name );
/* morespace.cpp */
SHIP_PROTOTYPE *get_ship_prototype( char *name );
void load_prototypes( void );
void save_ship_protoype( SHIP_PROTOTYPE * prototype );
long int get_prototype_value( SHIP_PROTOTYPE * prototype );
void create_ship_rooms( SHIP_DATA * ship );
/* special.cpp */
SF *spec_lookup( const char *name );
/* tables.cpp */
int get_skill( const char *skilltype );
char *spell_name( SPELL_FUN * spell );
char *skill_name( DO_FUN * skill );
void load_skill_table( void );
void save_skill_table( int delnum );
void sort_skill_table( void );
void load_socials( void );
void save_socials( void );
void load_commands( void );
void save_commands( void );
SPELL_FUN *spell_function( const char *name );
DO_FUN *skill_function( const char *name );
void load_herb_table( void );
void save_herb_table( void );
/* track.cpp */
void found_prey( CHAR_DATA * ch, CHAR_DATA * victim );
void hunt_victim( CHAR_DATA * ch );
/* update.cpp */
void advance_level( CHAR_DATA * ch, int ability );
void gain_exp( CHAR_DATA * ch, int gain, int ability );
void gain_exp2( CHAR_DATA * ch, int gain, int ability );
void gain_condition( CHAR_DATA * ch, int iCond, int value );
void update_handler( void );
void reboot_check( time_t reset );
void auction_update( void );
void remove_portal( OBJ_DATA * portal );
int max_level( CHAR_DATA * ch, int ability );
/* newscore.cpp */
const char *get_race( CHAR_DATA * ch );

// ACT bits for mobs (used in #MOBILES)
#define ACT_IS_NPC		 BV00 /* Auto set for mobs */
#define ACT_SENTINEL		 BV01 /* Stays in one room */
#define ACT_SCAVENGER		 BV02 /* Picks up objects  */
#define ACT_NOFLEE		 BV03 /* Mobs don't flee. -T  */
#define ACT_AGGRESSIVE		 BV05 /* Attacks PC's      */
#define ACT_STAY_AREA		 BV06 /* Won't leave area  */
#define ACT_WIMPY		 BV07 /* Flees when hurt   */
#define ACT_PET		 BV08 /* Auto set for pets */
#define ACT_TRAIN		 BV09 /* Can train PC's */
#define ACT_PRACTICE		 BV10 /* Can practice PC's */
#define ACT_IMMORTAL		 BV11 /* Cannot be killed  */
#define ACT_DEADLY		 BV12 /* Has a deadly poison  */
#define ACT_POLYSELF		 BV13
#define ACT_META_AGGR		 BV14 /* Extremely aggressive */
#define ACT_GUARDIAN		 BV15 /* Protects master   */
#define ACT_RUNNING		 BV16 /* Hunts quickly  */
#define ACT_NOWANDER		 BV17 /* Doesn't wander */
#define ACT_MOUNTABLE		 BV18 /* Can be mounted */
#define ACT_MOUNTED		 BV19 /* Is mounted     */
#define ACT_SCHOLAR              BV20  /* Can teach languages  */
#define ACT_SECRETIVE		 BV21 /* actions aren't seen  */
#define ACT_POLYMORPHED		 BV22 /* Mob is a ch    */
#define ACT_MOBINVIS		 BV23 /* Like wizinvis  */
#define ACT_NOASSIST		 BV24 /* Doesn't assist mobs  */
#define ACT_NOKILL               BV25  /* Mob can't die */
#define ACT_DROID                BV26  /* mob is a droid */
#define ACT_NOCORPSE             BV27
#define ACT_PUEBLO		 BV28 /* This is the pueblo flag */
#define ACT_PROTOTYPE		 BV30 /* A prototype mob   */

// Player wanted bits for vip planets
#define WANTED_CORUSCANT   	VIP_CORUSCANT
#define WANTED_YAVIN_IV	VIP_YAVIN_IV
#define WANTED_TATOOINE   	VIP_TATOOINE
#define WANTED_KASHYYYK   	VIP_KASHYYYK
#define WANTED_MON_CALAMARI   	VIP_MON_CALAMARI
#define WANTED_ENDOR	VIP_ENDOR
#define WANTED_ORD_MANTELL   	VIP_ORD_MANTELL
#define WANTED_NAL_HUTTA   	VIP_NAL_HUTTA
#define WANTED_CORELLIA   	VIP_CORELLIA
#define WANTED_BAKURA   	VIP_BAKURA

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
#define VIP_CORUSCANT           BV00
#define VIP_YAVIN_IV		BV01
#define VIP_TATOOINE            BV02
#define VIP_KASHYYYK           	BV03
#define VIP_MON_CALAMARI        	BV04
#define VIP_ENDOR		BV05
#define VIP_ORD_MANTELL         BV06
#define VIP_NAL_HUTTA           BV07
#define VIP_CORELLIA            BV08
#define VIP_BAKURA	        BV09

// Player flags (PLR_*)
#define PLR_IS_NPC BV00  /* Don't EVER set.   */
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

// PC_DATA flags -- for PC_DATA->flags
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

// Player wanted bits for vip planets
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

// ACT bits for mobs (used in #MOBILES)
#define	ACT_BOUND		 BV00 /* This is the bind flag */
#define ACT_JEDI		 BV01 /* This is a light jedi */
#define	ACT_SITH		 BV02 /* This is a dark jedi */
#define	ACT_GAGGED		 BV03 /* This is a gagged flag */

// Affect bits (AFF_*)
#define AFF_NONE                  0
#define AFF_BLIND	  BV00
#define AFF_INVISIBLE	  BV01
#define AFF_DETECT_EVIL	  BV02
#define AFF_DETECT_INVIS	  BV03
#define AFF_DETECT_MAGIC	  BV04
#define AFF_DETECT_HIDDEN	  BV05
#define AFF_WEAKEN	  BV06
#define AFF_SANCTUARY	  BV07
#define AFF_FAERIE_FIRE	  BV08
#define AFF_INFRARED	  BV09
#define AFF_CURSE	  BV10
#define AFF_COVER_TRAIL	  BV11
#define AFF_POISON	  BV12
#define AFF_PROTECT	  BV13
#define AFF_PARALYSIS	  BV14
#define AFF_SNEAK	  BV15
#define AFF_HIDE	  BV16
#define AFF_SLEEP	  BV17
#define AFF_CHARM	  BV18
#define AFF_FLYING	  BV19
#define AFF_PASS_DOOR	  BV20
#define AFF_FLOATING	  BV21
#define AFF_TRUESIGHT	  BV22
#define AFF_DETECTTRAPS	  BV23
#define AFF_SCRYING	  BV24
#define AFF_FIRESHIELD	  BV25
#define AFF_SHOCKSHIELD	  BV26
#define AFF_FASTHEAL      BV27
#define AFF_ICESHIELD   	  BV28
#define AFF_POSSESS	  BV29
#define AFF_BERSERK	  BV30
#define AFF_AQUA_BREATH	  BV31