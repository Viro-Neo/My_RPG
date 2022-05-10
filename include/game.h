/*
** EPITECH PROJECT, 2022
** game.h
** File description:
** game.h
*/

#ifndef GAME_H_
    #define GAME_H_
    #include <SFML/Window/Window.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/System/InputStream.h>
    #include <stdbool.h>
    #include "entity.h"
    #include "player_handling.h"
    #include "map.h"
    #include "m_rpg.h"
    #include "item.h"
    #include "options.h"
    #include "main_menu.h"

typedef struct game_s
{
    room_t **map;
    int volume;
    sfMusic *music;
    option_t *options;
    player_t *player;
    tiles_t **tiles_array;
    main_menu_t *main_menu;
    int current_room;
    int size;
    sfRenderWindow *window;
    quest_t **quests;
    sfEvent *event;
    item_t **level_items;
    spell_t **spells;
    int level;
    bool exit_pause;
} game_t;

void draw(game_t *);
void change_room(game_t *);
game_t *init_game(int );
void free_game(game_t *);
int player_event(game_t *, sfEvent *);
void change_room(game_t *);
void interact(npc_t *, game_t *);
void move_player(game_t *, int , int );
void bottom_animation(player_t *, game_t *);
void right_animation(player_t *, game_t *);
void top_animation(player_t *, game_t *);
void left_animation(player_t *, game_t *);
void animate_player(player_t *, game_t *);
void test_spells(game_t *);
void enemy_take_damage(game_t *, int, int);
void player_use_spell(player_t *, game_t *, int);
int get_spell_bonus(player_t *, spell_t *);
void player_use_atk_spell(player_t *, game_t *, int);
int targeting_event(game_t *, int [2], spell_t *);
sfRectangleShape *init_rectangle(sfVector2f, int);
void draw_target(sfRectangleShape *, game_t *);
void select_spell(game_t *, player_t *);
void adjust_index(int * ,int , int);
void display_inventory(game_t *, int);
void select_combat_option(game_t *, player_t *);
void draw_spell_select(game_t *, int , int);
void select_item(game_t *, player_t *);
void test_display_inventory(player_t *);
void equipment_menu(item_t **, sfRenderWindow *, int);
void draw_item(item_t *, sfRenderWindow *, sfVector2f);
sfVector2f get_item_pos(int, int);
void player_stat_display(player_t *, sfRenderWindow *);
int item_select_event(game_t *, int *, int, int);
void draw_selector(sfRenderWindow *, sfVector2f);
void select_shop_item(game_t *, npc_t *);
void write_stat(char *, sfRenderWindow *, sfVector2f);
void item_stat_display(item_t *, sfRenderWindow *, int);
void combat_overlay(game_t *, sfRenderWindow *);
void enemy_move(enemy_t *, player_t *, room_t *);
int enemy_attack(enemy_t *, player_t *, game_t *);
int enemy_decision_tree(enemy_t *, room_t *, player_t *, game_t *);
int recursion(int **, room_t *, int *, int);
void enage_combat(game_t *);
void attack(game_t *, player_t *);
void display_popup(game_t *, char *);
void write_item_stats(char *, stat_t *, sfRenderWindow *, int);
void write_cost(char *, sfRenderWindow *, sfVector2f);
void player_gain_xp(player_t *, int, game_t *);
void select_stat_increase(game_t *, player_t *, int);
void free_items(item_t **, game_t *);
char *get_items_path(int);
void init_levels(game_t *, int);
void change_levels(game_t *);
void spawn_exit(game_t *);
void apply_poison_p(game_t *, player_t *, int);
void apply_freeze_p(game_t *, player_t *, int);
void apply_lifesteal_p(game_t *, player_t *, int);
void apply_stoneskin_p(game_t *, player_t *, int);
void apply_berserk_p(game_t *, player_t *, int);
void apply_blind_p(game_t *, player_t *, int);
void apply_status_condition(game_t *, status_t *, player_t *);
void apply_status_effect(game_t *, player_t *);
void clear_status(player_t *);
void apply_poison_e(game_t *, spell_t *, int, int);
void apply_freeze_e(game_t *, spell_t *, int, int);
void apply_lifesteal_e(game_t *, spell_t *, int, int);
void apply_stoneskin_e(game_t *, spell_t *, int, int);
void apply_berserk_e(game_t *, spell_t *, int, int);
void apply_blind_e(game_t *, spell_t *, int, int);
void apply_spell_effect(game_t *, spell_t *, int, int);
void spell_description(spell_t *, sfRenderWindow *);
void display_status(player_t *, sfRenderWindow *);
void shift_status(status_t **, int);
void check_window_closed(game_t *);
void end_of_turn(game_t *);
void get_reward(game_t *);
tiles_t **init_tiles(game_t *);
room_t **generate_map(int, item_t **, game_t *);
void fill_map(room_t **, game_t *);
void animate_enemies(game_t *);
void en_attack_animation(enemy_t *, game_t *);
void death_animation(player_t *, game_t *);
void select_key(game_t *);
void draw_key_select(game_t *, int);
sfVector2f get_menu_pos(int, int);
char *get_item_stats(char *);
void en_death_animation(enemy_t *, game_t *);
void player_take_damage(player_t *, int, game_t *);
void animation_attack(player_t *, game_t *, int);
sfMusic *play_music(char *path, int volume);
void stop_music(sfMusic *music);
void select_volume(game_t *game);
void buy_item(game_t *, npc_t *, int);

#endif /*GAME_H*/
