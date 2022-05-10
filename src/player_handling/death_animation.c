/*
** EPITECH PROJECT, 2022
** death_animation
** File description:
** death_animation
*/

#include "player_handling.h"
#include "useful_csfml.h"

void death_animation(player_t *player, game_t *game)
{
    sfRenderWindow *window = game->window;
    sfSprite ***sprites = player->sprites;
    sfVector2f vect = create_sfvector(player->x * 64 - 32, player->y * 64 - 32);
    float seconds = 0;

    sfClock_restart(player->clock);
    while (player->vect.y < 7) {
        seconds = get_seconds(player->clock);
        sfRenderWindow_clear(window, sfBlack);
        if (seconds > 2. / 8.) {
            player->vect.y++;
            sfSprite_setPosition(player->sprites[5][player->vect.y], vect);
            sfRenderWindow_drawSprite(window, sprites[5][player->vect.y], NULL);
            sfRenderWindow_display(window);
            sfClock_restart(player->clock);
        }
    }
}
