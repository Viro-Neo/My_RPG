/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to handle equipment
*/

#include <stdio.h>
#include <stdlib.h>
#include "useful_csfml.h"
#include "game.h"
#include "item.h"

void draw_selector(sfRenderWindow *window, sfVector2f pos)
{
    sfTexture *texture;
    sfSprite *sprite = sfSprite_create();
    char *sprite_path = "assets/inventory/selector-1.png.png";

    texture = sfTexture_createFromFile(sprite_path, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void equipment_menu(item_t **items, sfRenderWindow *window, int index)
{
    for (int i = 0; i < 4; i++)
        draw_item(items[i], window, get_item_pos(i + MAX_SLOTS, ROW_COUNT));
    draw_selector(window, get_item_pos(index, ROW_COUNT));
}