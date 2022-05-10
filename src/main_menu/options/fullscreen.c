/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** fullscreen handling
*/

#include <SFML/Graphics.h>
#include "game.h"

void set_fullscreen(game_t *game, int status)
{
    sfRenderWindow_destroy(game->window);
    if (status == 1)
        game->window = sfRenderWindow_create(sfVideoMode_getDesktopMode(),
                                    "my_rpg", sfFullscreen, NULL);
    else if (status == 0)
        game->window = sfRenderWindow_create(sfVideoMode_getDesktopMode(),
                                    "my_rpg", sfDefaultStyle, NULL);
}
