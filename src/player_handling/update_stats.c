/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to handle player level
*/

#include <stdlib.h>
#include "game.h"

void update_stats(player_t *player, int index)
{
    if (index == 1)
        player->stat->max_hp += 5;
    if (index == 2)
        player->stat->max_mana += 5;
    if (index == 3)
        player->stat->str += 2;
    if (index == 4)
        player->stat->wis += 2;
    if (index == 5)
        player->stat->dex += 2;
    if (index == 6)
        player->stat->ac += 2;
}