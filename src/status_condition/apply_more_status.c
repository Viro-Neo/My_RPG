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

void shift_status(status_t **status, int index)
{
    int i = 0;
    while (i < MAX_STATUS && status[i] != NULL) {
        if (i >= index)
            status[i] = status[i + 1];
        i += 1;
    }
}

void apply_blind_p(game_t *game, player_t *player, int index)
{
    player->status[index]->timer -= 1;
    if (player->status[index]->timer == 0) {
        player->status[index]->timer = player->status[index]->max_timer;
        shift_status(player->status, index);
        display_popup(game, "Lost blind effect");
    }
}

void apply_blind_e(game_t *game, spell_t *spell,
                   int index, int damage)
{
    enemy_t *enemy = game->map[game->current_room]->enemy[index];
    if (enemy->status[1] == NULL) {
        display_popup(game, "Enemy was afflicted with blind");
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
