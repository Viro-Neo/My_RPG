/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to modify player_health
*/

#include <stdio.h>
#include "player_handling.h"
#include "m_rpg.h"
#include "game.h"

void player_take_damage(player_t *player, int damage, game_t *game)
{
    if (damage > 0)
        player->stat->hp -= damage;
    if (player->stat->hp <= 0) {
        player->stat->hp = 0;
        death_animation(player, game);
        game->exit_pause = true;
    }
}

void player_heal_damage(player_t *player, int heal)
{
    player->stat->hp += heal;
    if (player->stat->hp > player->stat->max_hp)
        player->stat->hp = player->stat->max_hp;
}
