/*
** EPITECH PROJECT, 2022
** player_handling.h
** File description:
** player_handling
*/

#ifndef PLAYER_HANDLING_H_
    #define PLAYER_HANDLING_H_
    #define ANIMATION 8
    #include "stat.h"
    #include "item.h"
    #include "entity.h"
    #include "status_condition.h"
    #include <SFML/Graphics.h>
    #include <SFML/System/Types.h>

typedef struct player_s
{
    int x;
    int y;
    sfVector2i vect;
    int xp;
    struct stat_s *stat;
    sfSprite ***sprites;
    sfClock *clock;
    item_t **inventory;
    item_t **equipment;
    spell_t **spells;
    status_t **status;
    sfVector2f pos;
}player_t;

player_t *init_player(void);
void free_player(player_t *);
void free_sprites(sfSprite ***);
void create_sprite_player(player_t *);
void create_sprite_player(player_t *);
void player_heal_damage(player_t *, int);
void scale_sprite_player(sfSprite ***);
void idle_animation(player_t *);
int acquire_item(item_t *, player_t *);
int use_item(player_t *, int);
int equip_item(player_t *, int);
void unequip_item(player_t *, int);
void player_recover_mana(player_t *, int);
void player_use_mana(player_t *, int);
void display_equipment(item_t **);
void display_stats(player_t *);
void display_items(item_t **);
void display_learned_spells(player_t *);
void player_gain_money(player_t *, int);
void player_spend_money(player_t *, int);
int is_item_in_inventory(player_t *, char *);
void update_stats(player_t *, int);
int is_aflicted(player_t *, int);

#endif/*PLAYER_HANDLING_H_*/
