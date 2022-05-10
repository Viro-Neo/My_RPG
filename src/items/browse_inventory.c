/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to browse inventory
*/

#include <stdio.h>
#include "game.h"
#include "item.h"

int item_select_event(game_t *game, int *index, int limit, int step)
{
    sfEvent *event = game->event;
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == game->options->keys[KEY_MENU_LEFT])
            adjust_index(index, -1, limit);
        if (event->key.code == game->options->keys[KEY_MENU_RIGHT])
            adjust_index(index, 1, limit);
        if (event->key.code == game->options->keys[KEY_MENU_UP])
            adjust_index(index, step * -1, limit);
        if (event->key.code == game->options->keys[KEY_MENU_DOWN])
            adjust_index(index, step, limit);
        if (event->key.code == game->options->keys[KEY_CONFIRM])
            return 1;
        if (event->key.code == game->options->keys[KEY_BACK])
            return -1;
    }
    return 0;
}

void item_selected(game_t *game, player_t *player, int index)
{
    if (index < MAX_SLOTS && player->inventory[index] == NULL)
        return;
    if ((index >= MAX_SLOTS || player->inventory[index]->type != CONSUMABLE) &&
        game->map[game->current_room]->type == ENEMY_ROOM)
        return;
    if (index >= MAX_SLOTS)
        unequip_item(player, index - MAX_SLOTS);
    else
        use_item(player, index);
}

void select_item(game_t *game, player_t *player)
{
    int index = 0;
    int selected = 0;

    while (selected == 0) {
        if (sfRenderWindow_pollEvent(game->window, game->event)) {
            check_window_closed(game);
            selected = item_select_event(game, &index,
                                         MAX_SLOTS + 4, ROW_COUNT);
        }
        display_inventory(game, index);
    }
    if (selected == -1)
        return;
    item_selected(game, player, index);
    select_item(game, player);
}