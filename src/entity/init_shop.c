/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to initialize the shop
*/

#include <stdlib.h>
#include "entity.h"
#include "item.h"
#include "time.h"

void shift_items(item_t **items, int index)
{
    int i = 0;

    while (items[i] != NULL) {
        if (i >= index)
            items[i] = items[i + 1];
        i += 1;
    }
}

void pick_items(npc_t *shopkeeper, item_t **level_items)
{
    int i = 0;
    int index;

    srand(time(NULL));
    while (level_items[i] != NULL)
        i += 1;
    for (int j = 0; j < 3; j++) {
        index = rand() % i;
        i -= 1;
        shopkeeper->shop[j] = level_items[index];
        shift_items(level_items, index);
    }
}
