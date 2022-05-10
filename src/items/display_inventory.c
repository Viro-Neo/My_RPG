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

sfVector2f get_item_pos(int index, int limit)
{
    int x;
    int y;
    if (index < MAX_SLOTS) {
        x = 728 + ((index % limit) * 100);
        y = 520 + ((index / limit) * 100);
    } else {
        x = 728 + (((index - MAX_SLOTS) % 2) * 400);
        y = 295 + (((index - MAX_SLOTS) / 2) * 105);
    }
    return create_sfvector(x, y);
}

void draw_item(item_t *item, sfRenderWindow *window, sfVector2f pos)
{
    if (item == NULL)
        return;
    sfTexture *texture;
    sfSprite *sprite = sfSprite_create();

    texture = sfTexture_createFromFile(item->sprite, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    return;
}

void inventory_menu(item_t **items, sfRenderWindow *window)
{
    sfTexture *texture;
    sfSprite *sprite = sfSprite_create();
    char *sprite_path = "assets/inventory/inventory_overlay-1.png.png";

    texture = sfTexture_createFromFile(sprite_path, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, create_sfvector(707, 10));
    sfRenderWindow_drawSprite(window, sprite, NULL);
    for (int i = 0; i < MAX_SLOTS; i++)
        draw_item(items[i], window, get_item_pos(i, ROW_COUNT));
}

void display_inventory(game_t *game, int index)
{
    item_t **items = game->player->inventory;
    item_t **equips = game->player->equipment;

    sfRenderWindow_clear(game->window, sfBlack);
    draw(game);
    inventory_menu(items, game->window);
    equipment_menu(equips, game->window, index);
    player_stat_display(game->player, game->window);
    if (index >= MAX_SLOTS && equips[index - MAX_SLOTS] != NULL)
        item_stat_display(equips[index - MAX_SLOTS], game->window, 1250);
    if (index < MAX_SLOTS && items[index] != NULL)
        item_stat_display(items[index], game->window, 1250);
    sfRenderWindow_display(game->window);
}
