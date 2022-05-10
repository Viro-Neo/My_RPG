/*x
** EPITECH PROJECT, 2022
** attack.c
** File description:
** attack to enemies
*/

#include <stdlib.h>
#include "my.h"
#include "game.h"
#include "player_handling.h"
#include "entity.h"

int enemy_adjacent(player_t *player, enemy_t *enemy)
{
    if (player->x == enemy->x + 1 && player->y == enemy->y)
        return 1;
    if (player->x == enemy->x - 1 && player->y == enemy->y)
        return 1;
    if (player->x == enemy->x && player->y == enemy->y + 1)
        return 1;
    if (player->x == enemy->x && player->y == enemy->y - 1)
        return 1;
    return 0;
}

int is_attack_valid(game_t *game, enemy_t *enemy)
{
    player_t *player = game->player;
    int type = game->map[game->current_room]->type;

    if ((((rand() % player->stat->dex) - (rand() % enemy->stats->dex)) >= 0)) {
        game->player->stat->actions -= 1;
        display_popup(game, "Enemy dodged attack");
        return 0;
    }
    if ((type == ENEMY_ROOM || type == BOSS_ROOM)
        && player->stat->actions >= 1)
        return 1;
    return 0;
}

int get_target_enemy(game_t *game, player_t *player)
{
    enemy_t **enemies = game->map[game->current_room]->enemy;
    int i = 0;

    while (enemies[i] != NULL) {
        if (enemy_adjacent(player, enemies[i]) == 1)
            return i;
        i += 1;
    }
    return -1;
}

void check_combat_effect(game_t *game, player_t *player, int index, int damage)
{
    enemy_t *enemy = game->map[game->current_room]->enemy[index];
    int status_i = 0;

    if (enemy == NULL)
        return;
    if ((status_i = is_aflicted(player, BERSERK)) != -1) {
        if (damage >= enemy->stats->hp) {
            player->stat->actions = 5;
            player->status[status_i]->timer =
                    player->status[status_i]->max_timer + 1;
        }
        if (damage < enemy->stats->hp)
            player->stat->actions = 0;
    }
    if (is_aflicted(player, LIFESTEAL) == 1)
        player_heal_damage(player, damage / 2);
}

void attack(game_t *game, player_t *player)
{
    int index = 0;
    int damage = 0;

    if (game->map[game->current_room]->type != ENEMY_ROOM &&
            game->map[game->current_room]->type != BOSS_ROOM) {
        display_popup(game, "can only use this in enemy room\n");
        return;
    }
    index = get_target_enemy(game, player);
    if (index == -1)
        return;
    if (is_attack_valid(game, game->map[game->current_room]->enemy[index]) == 0)
        return;
    player->stat->actions -= 1;
    damage = player->stat->str -
            game->map[game->current_room]->enemy[index]->stats->ac;
    check_combat_effect(game, player, index, damage);
    enemy_take_damage(game, damage, index);
}
