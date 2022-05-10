/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to retrieve items for certain levels
*/

#include <stdlib.h>
#include <stdio.h>
#include "item.h"

int count_level_items(item_t **items, int level)
{
    int count = 0;
    int i = 0;

    while (items[i] != NULL) {
        if (items[i]->stats->level > (level - 1) * 5 &&
        items[i]->stats->level <= (level) * 5) {
            count += 1;
        }
        i += 1;
    }
    return count;
}

item_t **get_level_items(item_t **items, int level)
{
    item_t **level_items;
    int size = count_level_items(items, level);
    int i = 0;
    int j = 0;

    level_items = malloc(sizeof(item_t *) * (size + 1));
    if (level_items == NULL)
        return NULL;
    while (items[i] != NULL) {
        if (items[i]->stats->level > (level - 1) * 5 &&
            items[i]->stats->level <= (level) * 5 /*&&
            items[i]->stats->level != 0*/) {
            level_items[j] = items[i];
            j += 1;
        }
        i += 1;
    }
    level_items[size] = NULL;
    return level_items;
}