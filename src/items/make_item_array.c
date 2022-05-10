/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to create item array
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "item.h"

int count_items(item_list_t *items)
{
    int count = 0;

    while (items != NULL) {
        count += 1;
        items = items->next;
    }
    return count;
}

item_t **make_item_arr(char *path)
{
    item_list_t *items = init_items(path);
    int count = count_items(items);
    item_t **item_arr = malloc(sizeof(item_t *) * (count + 1));

    if (item_arr == NULL) {
        my_printf("failed to allocate memory for item array\n");
        return NULL;
    }
    int i = 0;
    while (items != NULL) {
        parse_item(items->item, path);
        item_arr[i] = malloc(sizeof(item_t));
        item_arr[i] = items->item;
        items = items->next;
        i += 1;
    }
    item_arr[i] = NULL;
    return item_arr;
}
