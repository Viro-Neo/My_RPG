/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to modify enemy's health
*/

#include "my.h"
#include "game.h"
#include "player_handling.h"
#include "item.h"
#include "stat.h"
#include "entity.h"

void shift_enemies(enemy_t **enemies, int index)
{
    int i = 0;

    while (enemies[i] != NULL) {
        if (i >= index)
            enemies[i] = enemies[i + 1];
        i += 1;
    }
}

void drop_loot(int xp, int gold, game_t *game)
{
    player_t *player = game->player;

    player->stat->money += gold;
    player_gain_xp(player, xp, game);
}

void enemy_die(enemy_t *enemy, game_t *game, int index)
{
    int xp = enemy->xp_given;
    int gold = enemy->stats->money;

    en_death_animation(enemy, game);
    shift_enemies(game->map[game->current_room]->enemy, index);
    drop_loot(xp, gold, game);
    return;
}

void enemy_take_damage(game_t *game, int damage, int index)
{
    enemy_t *enemy = game->map[game->current_room]->enemy[index];
    my_printf("enemy %s will take %d damage\n", enemy->name, damage);
    enemy->stats->hp -= damage;
    if (enemy->stats->hp <= 0)
        enemy_die(enemy, game, index);
}

void enemy_heal_damage(enemy_t *enemy, int heal)
{
    enemy->stats->hp += heal;
    if (enemy->stats->hp > enemy->stats->max_hp)
        enemy->stats->hp = enemy->stats->max_hp;
}