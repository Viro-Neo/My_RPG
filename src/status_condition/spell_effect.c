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

int apply_to_enemy(game_t *game, spell_t *spell, int index, int damage)
{
    int chance;
    int success;
    int type;
    enemy_t *enemy = game->map[game->current_room]->enemy[index];

    if (enemy->status[1] == NULL) {
        chance = 100 / spell->status->chance;
        success = rand() % chance;
        type = spell->status->type;
    } else {
        chance = 100 / enemy->status[1]->chance;
        success = rand() % chance;
        type = enemy->status[1]->type;
    }
    if (success == 0)
        return type;
    return -1;
}

void apply_spell_effect(game_t *game, spell_t *spell, int index, int damage)
{
    enemy_t *enemy = game->map[game->current_room]->enemy[index];
    int type;
    void (*apply_status[6])(game_t *, spell_t *, int, int) =
            {apply_poison_e, apply_freeze_e, apply_lifesteal_e,
             apply_stoneskin_e, apply_berserk_e, apply_blind_e};

    if ((spell != NULL && spell->status->type == 0) ||
    (enemy->status[1] == NULL && damage < 0))
        return;
    type = apply_to_enemy(game, spell, index, damage);
    if (type != -1)
        apply_status[type - 1](game, spell, index, damage);
}
