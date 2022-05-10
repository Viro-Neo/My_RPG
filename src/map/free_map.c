/*
** EPITECH PROJECT, 2022
** free_map.c
** File description:
** free_map
*/

#include "map.h"
#include "stdlib.h"
#include "entity.h"

void free_layout(char **layout)
{
    for (int r = 0; layout[r] != NULL; r++) {
        free(layout[r]);
    }
}

void free_map(room_t **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        free_layout(map[i]->layout);
        free(map[i]);
    }
    free(map);
}
