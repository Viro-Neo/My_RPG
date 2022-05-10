/*
** EPITECH PROJECT, 2022
** free_tiles.c
** File description:
** free tiles
*/

#include "stdlib.h"
#include "map.h"

void free_tiles(tiles_t **tiles)
{
    for (int i = 0; tiles[i] != NULL; i++) {
        sfSprite_destroy(tiles[i]->sprite);
    }
    free(tiles);
}
