/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** contains functions used for combat
*/

#include <stdlib.h>
#include "useful_csfml.h"
#include "status_condition.h"
#include "game.h"
#include "player_handling.h"
#include "entity.h"
#include "map.h"
#include "my.h"

void end_of_turn(game_t *game)
{
    player_t *player = game->player;
    room_t *room = game->map[game->current_room];
    enemy_t **enemies = room->enemy;
    int i = 0;

    apply_status_effect(game, player);
    i = 0;
    while (enemies[i] != NULL) {
        apply_spell_effect(game, NULL, i, -1);
        i += 1;
    }
    player->stat->actions = 5;        
    return;
}

void get_reward(game_t *g)
{
    int i = 0;
    int index = 0;
    char *text = NULL;

    while (g->level_items[i] != NULL)
        i += 1;
    if (i != 0)
        index = rand() % i;
    if (g->level_items[index] != NULL) {
        text = my_strcat("Room cleared, obtained ", g->level_items[index]->name);
        acquire_item(g->level_items[index], g->player);
        shift_items(g->level_items, index);
        display_popup(g, text);
        free(text);
    }
}
