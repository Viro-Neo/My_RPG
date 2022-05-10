/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to initialize player
*/

#include <stdlib.h>
#include "status_condition.h"
#include "player_handling.h"
#include "useful_csfml.h"

void init_player_stats(player_t *player)
{
    player->stat = malloc(sizeof(stat_t));
    player->stat->level = 1;
    player->stat->str = 50;
    player->stat->dex = 50;
    player->stat->wis = 50;
    player->stat->hp = 100;
    player->stat->max_hp = 100;
    player->stat->mana = 100;
    player->stat->max_mana = 100;
    player->stat->ac = 50;
    player->stat->money = 10;
    player->stat->actions = 5;
    player->pos = create_sfvector(0, 0);
}

void init_inventory(player_t *player)
{
    player->inventory = malloc(sizeof(item_t *) * (MAX_SLOTS + 1));
    player->equipment = malloc(sizeof(item_t *) * 4);
    player->spells = malloc(sizeof(spell_t *) * (SPELL_COUNT + 1));
    player->status = malloc(sizeof(status_t *) * (MAX_STATUS + 2));
    for (int i = 0; i < MAX_SLOTS; i++)
        player->inventory[i] = NULL;
    for (int i = 0; i < 4; i++)
        player->equipment[i] = NULL;
    for (int i = 0; i < SPELL_COUNT; i++)
        player->spells[i] = NULL;
    for (int i = 0; i <= MAX_STATUS; i++)
        player->status[i] = NULL;
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    sfVector2f vect;

    player->x = 14;
    player->y = 7;
    player->xp = 0;
    player->clock = sfClock_create();
    init_inventory(player);
    init_player_stats(player);
    create_sprite_player(player);
    vect = create_sfvector(player->x * 64, player->y * 64);
    player->vect.x = 0;
    player->vect.y = 0;
    for (int i = 0; player->sprites[i] != NULL; i++) {
        for (int j = 0; player->sprites[i][j] != NULL; j++)
            sfSprite_move(player->sprites[i][j], vect);
    }
    scale_sprite_player(player->sprites);
    return player;
}
