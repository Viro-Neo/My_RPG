/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to browse inventory
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "useful_csfml.h"
#include "entity.h"
#include "game.h"
#include "item.h"

void item_stat_display(item_t *item, sfRenderWindow *window, int x)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, create_sfvector(x, 100));
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(120, 120, 120, 175));
    sfRectangleShape_setSize(rect, create_sfvector(350, 514));
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    write_item_stats(item->name, item->stats, window, x);
    sfRectangleShape_destroy(rect);
}

sfVector2f get_item_pos_shop(int index, int limit)
{
    int x;
    int y;

    x = 862 + ((index % limit) * 78);
    y = 641;
    return create_sfvector(x, y);
}

void item_buy_menu(item_t **items, sfRenderWindow *window, int index)
{
    sfTexture *texture;
    sfSprite *sprite = sfSprite_create();
    char *sprite_path = "assets/inventory/shop_overlay-1.png.png";
    char *cost;

    texture = sfTexture_createFromFile(sprite_path, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, create_sfvector(854, 634));
    sfRenderWindow_drawSprite(window, sprite, NULL);
    for (int i = 0; i < SHOP_SLOTS; i++) {
        if (items[i] != NULL) {
            draw_item(items[i], window, get_item_pos_shop(i, 3));
            cost = my_itoa(items[i]->stats->money);
            write_cost(cost, window, create_sfvector(880 + i * 78, 739));
        }
    }
    draw_selector(window, get_item_pos_shop(index, 3));
    sfSprite_destroy(sprite);
}

void display_shop(game_t *game, npc_t *shopkeep, int index)
{
    item_t **items = shopkeep->shop;

    sfRenderWindow_clear(game->window, sfBlack);
    draw(game);
    item_buy_menu(items, game->window, index);
    if (items[index] != NULL)
        item_stat_display(items[index], game->window, 785);
    sfRenderWindow_display(game->window);
}

void select_shop_item(game_t *game, npc_t *shopkeep)
{
    int index = 0;
    int selected = 0;

    while (selected == 0) {
        if (sfRenderWindow_pollEvent(game->window, game->event)) {
            check_window_closed(game);
            selected = item_select_event(game, &index, SHOP_SLOTS, 1);
        }
        display_shop(game, shopkeep, index);
    }
    if (selected == -1)
        return;
    buy_item(game, shopkeep, index);
    select_shop_item(game, shopkeep);
}
