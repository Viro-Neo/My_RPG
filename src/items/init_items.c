/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to parse item files
*/

#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include "item.h"
#include "player_handling.h"

item_t *init_item(void)
{
    item_t *item = malloc(sizeof(item_t));
    item->stats = malloc(sizeof(stat_t));
    return item;
}

item_list_t *init_items(char *path)
{
    DIR *dir = opendir(path);
    item_list_t *item_list;
    item_list_t *item;

    struct dirent *next;
    next = readdir(dir);
    item_list = NULL;
    while (next) {
        if (next->d_name[0] != '.') {
            item = malloc(sizeof(item_list_t));
            item->item = init_item();
            item->item->description = next->d_name;
            item->next = item_list;
            item_list = item;
        }
        next = readdir(dir);
    }
    return item_list;
}
