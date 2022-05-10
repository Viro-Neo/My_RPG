/*
** EPITECH PROJECT, 2022
** free_player.c
** File description:
** free player
*/

#include <stdlib.h>
#include "player_handling.h"

void free_sprites(sfSprite ***sprites)
{
    for (int i = 0; sprites[i] != NULL; i++) {
        for (int r = 0; sprites[i][r] != NULL; r++) {
            sfSprite_destroy(sprites[i][r]);
        }
        free(sprites[i]);
    }
}

void free_player(player_t *player)
{
    free(player->stat);
    free_sprites(player->sprites);
    sfClock_destroy(player->clock);
}
