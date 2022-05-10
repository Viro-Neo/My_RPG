/*
** EPITECH PROJECT, 2022
** status condition
** File description:
** status condition
*/

#include <stdlib.h>
#include "my.h"
#include "player_handling.h"
#include "status_condition.h"
#include "item.h"
#include "game.h"

void apply_poison_p(game_t *game, player_t *player, int index)
{
    player_take_damage(player, player->status[index]->damage, game);
    player->status[index]->timer -= 1;
    if (player->status[index]->timer == 0) {
        player->status[index]->timer = player->status[index]->max_timer;
        shift_status(player->status, index);
        display_popup(game, "No longer poisonned");
    }
}

void apply_freeze_p(game_t *game, player_t *player, int index)
{
    player->status[index]->timer -= 1;
    if (player->status[index]->timer == 0) {
        player->status[index]->timer = player->status[index]->max_timer;
        shift_status(player->status, index);
        display_popup(game, "No longer frozen");
    }
}

void apply_lifesteal_p(game_t *game, player_t *player, int index)
{
    player->status[index]->timer -= 1;
    if (player->status[index]->timer == 0) {
        player->status[index]->timer = player->status[index]->max_timer;
        shift_status(player->status, index);
        display_popup(game, "Lost lifesteal effect");
    }
}

void apply_stoneskin_p(game_t *game, player_t *player, int index)
{
    if (player->status[index]->active == 0) {
        player->stat->ac += player->status[index]->damage;
        player->status[index]->active = 1;
        return;
    }
    player->status[index]->timer -= 1;
    if (player->status[index]->timer == 0) {
        player->stat->ac -= player->status[index]->damage;
        player->status[index]->timer = player->status[index]->max_timer;
        shift_status(player->status, index);
        display_popup(game, "Lost stoneskin effect");
    }
}

void apply_berserk_p(game_t *game, player_t *player, int index)
{
    if (player->status[index]->active == 0) {
        player->stat->str += player->status[index]->damage;
        player->status[index]->active = 1;
    }
    player->status[index]->timer -= 1;
    if (player->status[index]->timer == 0) {
        player->stat->str -= player->status[index]->damage;
        player_take_damage(player, player->status[index]->damage, game);
        player->status[index]->timer = player->status[index]->max_timer;
        shift_status(player->status, index);
        display_popup(game, "Lost Berserk effect and paid it's cost");
    }
}
