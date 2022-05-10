/*
** EPITECH PROJECT, 2022
** decision_tree.c
** File description:
** decision_tree
*/

#include "game.h"

int in_range(enemy_t *enemy, player_t *player)
{
    if (enemy->x > player->x
        && enemy->x - enemy->range <= player->x
        && enemy->y == player->y)
        return 1;
    if (enemy->x < player->x
        && enemy->x + enemy->range >= player->x
        && enemy->y == player->y)
        return 1;
    if (enemy->y > player->y
        && enemy->y - enemy->range <= player->y
        && enemy->x == player->x)
        return 1;
    if (enemy->y < player->y
        && enemy->y + enemy->range >= player->y
        && enemy->x == player->x)
        return 1;
    return 0;
}

int enemy_decision_tree(enemy_t *enemy, room_t *room, player_t *player, game_t *game)
{
    if (in_range(enemy, player))
        enemy_attack(enemy, player, game);
    else {
        enemy_move(enemy, player, room);
    }
    return 0;
}
