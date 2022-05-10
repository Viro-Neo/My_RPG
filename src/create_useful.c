/*
** EPITECH PROJECT, 2021
** create useful
** File description:
** create useful
*/

#include "map.h"
#include <SFML/Graphics.h>

sfColor create_color(sfUint8 r, sfUint8 g, sfUint8 b, sfUint8 a)
{
    sfColor color;

    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return color;
}

sfVector2f create_sfvector(float x, float y)
{
    sfVector2f vf;

    vf.x = x;
    vf.y = y;
    return vf;
}

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "my_rpg",
                                    sfDefaultStyle, NULL);
    return window;
}

sfVertex sfvertex_create(sfVector2f pos, sfColor color)
{
    sfVertex vertex;

    vertex.position = pos;
    vertex.color = color;
    return vertex;
}

sfIntRect sfintrect_create(int left, int top, int width, int height)
{
    sfIntRect rect;

    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = height;
    return rect;
}
