/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to modify player_mana
*/

#include <stdio.h>
#include "player_handling.h"

void player_use_mana(player_t *player, int cost)
{
    player->stat->mana -= cost;
    if (player->stat->mana < 0)
        player->stat->mana = 0;
}

void player_recover_mana(player_t *player, int amount)
{
    player->stat->mana += amount;
    if (player->stat->mana > player->stat->max_mana)
        player->stat->mana = player->stat->max_mana;
}