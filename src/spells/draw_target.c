/*
** EPITECH PROJECT, 2021
** my_rpg
** functions used to draw rectangle target
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Graphics/Rect.h>
#include "useful_csfml.h"


sfRectangleShape *init_rectangle(sfVector2f pos, int size)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rectangle, sfTransparent);
    sfRectangleShape_setPosition(rectangle, pos);
    sfRectangleShape_setOutlineColor(rectangle, sfRed);
    sfRectangleShape_setOutlineThickness(rectangle, 1);
    sfRectangleShape_setSize(rectangle, create_sfvector(size, size));
    return rectangle;
}

void draw_target(sfRectangleShape *rectangle, game_t *game)
{
    sfRenderWindow *window = game->window;
    sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
}
