/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to modify player money
*/

#include <stdio.h>
#include "player_handling.h"

void player_spend_money(player_t *player, int cost)
{
    player->stat->money -= cost;
}

void player_gain_money(player_t *player, int amount)
{
    player->stat->money += amount;
}
