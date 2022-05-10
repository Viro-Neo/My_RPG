/*
** EPITECH PROJECT, 2022
** status condition
** File description:
** status condition
*/

#include <stdlib.h>
#include "my.h"
#include "status_condition.h"
#include "player_handling.h"
#include "item.h"
#include "game.h"

void display_status_popup(status_t *status, game_t *game)
{
    switch (status->type)
    {
        case POISON:
            display_popup(game, "You are now poisonned");
            break;
        case FREEZE:
            display_popup(game, "You are now frozen");
            break;
        case LIFESTEAL:
            display_popup(game, "You have gained effect Lifesteal");
            break;
        case STONESKIN:
            display_popup(game, "You have gained effet Stoneskin");
        default:
            break;
    }
}

int is_aflicted(player_t *player, int type)
{
    int i = 0;

    while (i < MAX_STATUS) {
        if (player->status[i] != NULL && player->status[i]->type == type)
            return i;
        i += 1;
    }
    return -1;
}

void clear_status(player_t *player)
{
    for (int i = 0; i < MAX_STATUS; i++)
        player->status[i] = NULL;
}

void apply_status_condition(game_t *game, status_t *status, player_t *player)
{
    int chance;
    int success;
    int i = 0;

    if (status->type == 0)
        return;
    chance = 100 / status->chance;
    success = rand() % chance;
    if (status == NULL || status->type == 0 || success != 0 ||
            is_aflicted(player, status->type) >= 0)
        return;
    while (i < MAX_STATUS && player->status[i] != NULL)
        i += 1;
    if (i == MAX_STATUS)
        return;
    player->status[i] = status;
    display_status_popup(status, game);
}

void apply_status_effect(game_t *game, player_t *player)
{
    void (*apply_status[6])(game_t *, player_t *, int) =
            {apply_poison_p, apply_freeze_p,
             apply_lifesteal_p, apply_stoneskin_p,
             apply_berserk_p, apply_blind_p};

    for (int i = 0; i < MAX_STATUS; i++) {
        if (player->status[i] != NULL)
            apply_status[player->status[i]->type - 1](game, player, i);
    }
}
