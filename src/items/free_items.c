/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to free items
*/

#include <stdlib.h>
#include "item.h"
#include "game.h"

void free_items(item_t **items, game_t *game)
{
    int size = 9 + (game->level == 1);

    for (int i = 0; i < size; i++)
        free(items[i]);
    free(items);
}
