/*
** EPITECH PROJECT, 2022
** status condition
** File description:
** spell effect
*/

#include <stdlib.h>
#include "my.h"
#include "player_handling.h"
#include "status_condition.h"
#include "item.h"
#include "game.h"

void apply_poison_e(game_t *game, spell_t *spell, int index, int damage)
{
    enemy_t *enemy = game->map[game->current_room]->enemy[index];

    if (enemy->status[1] == NULL) {
        display_popup(game, "Enemy was afflicted with poison");
        enemy->status[1] = spell->status;
        return;
    }
    enemy->status[1]->timer -= 1;
    enemy_take_damage(game, enemy->status[1]->damage, index);
    if (enemy->status[1]->timer == 0) {
        enemy->status[1]->timer = enemy->status[1]->max_timer;
        enemy->status[1] = NULL;
    }
}

void apply_freeze_e(game_t *game, spell_t *spell, int index, int damage)
{
    enemy_t *enemy = game->map[game->current_room]->enemy[index];

    if (enemy->status[1] == NULL) {
        display_popup(game, "Enemy was afflicted with freeze");
        enemy->status[1] = spell->status;
        return;
    }
    enemy->status[1]->timer -= 1;
    if (enemy->status[1]->timer == 0) {
        enemy->status[1]->timer = enemy->status[1]->max_timer;
        enemy->status[1] = NULL;
        return;
    }
}

void apply_lifesteal_e(game_t *game, spell_t *spell, int index, int damage)
{
    enemy_t *enemy = game->map[game->current_room]->enemy[index];

    player_heal_damage(game->player, damage / 2);
    display_popup(game, "Regained life due to life steal");
}

void apply_stoneskin_e(game_t *game, spell_t *spell, int index, int damage)
{
    return;
}

void apply_berserk_e(game_t *game, spell_t *spell, int index, int damage)
{
    enemy_t *enemy = game->map[game->current_room]->enemy[index];

    if (damage > enemy->stats->hp) {
        game->player->stat->actions = 5 + spell->stats->actions;
        game->player->stat->mana += spell->stats->mana;
        display_popup(game, "Dealing the killing blow reinvigorates you");
    } else {
        game->player->stat->actions = 0;
        player_take_damage(game->player, spell->status->damage, game);
        display_popup(game, "Letting the enemy live drains your power");
    }
}
