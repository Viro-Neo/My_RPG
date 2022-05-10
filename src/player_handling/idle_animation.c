/*
** EPITECH PROJECT, 2022
** idle_animation
** File description:
** idle_animation
*/

#include "player_handling.h"
#include "useful_csfml.h"

void idle_animation(player_t *player)
{
    sfVector2f vect = create_sfvector(player->x * 64 - 32, player->y * 64 - 32);
    float seconds = get_seconds(player->clock);

    player->vect.x = 0;
    if (seconds > 0.2) {
        player->vect.y++;
        if (player->vect.y >= 4)
            player->vect.y = 0;
        sfClock_restart(player->clock);
    }
    sfSprite_setPosition(player->sprites[0][player->vect.y], vect);
}
