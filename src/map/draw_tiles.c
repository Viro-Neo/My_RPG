/*
** EPITECH PROJECT, 2022
** draw_tiles.c
** File description:
** draw tiles from map
*/

#include "map.h"
#include "stdlib.h"
#include "useful_csfml.h"

tiles_t *choose_tile(char c, tiles_t **array_tiles)
{
    int i = 0;

    while (array_tiles[i] != NULL) {
        if (array_tiles[i]->c == c)
            return array_tiles[i];
        i++;
    }
    return NULL;
}

int draw_room(sfRenderWindow *window, tiles_t **array_tiles, room_t *room)
{
    int l = 0;
    int x = 0;
    tiles_t *tiles;

    for (int i = 0; room->layout[l] != NULL; i++) {
        tiles = choose_tile(room->layout[l][x], array_tiles);
        sfSprite_setPosition(tiles->sprite, create_sfvector(x * 64, l * 64));
        sfRenderWindow_drawSprite(window, tiles->sprite, NULL);
        x++;
        if (room->layout[l][x] == '\0') {
            l++;
            x = 0;
        }
    }
    if (room->type == NPC_ROOM)
        sfRenderWindow_drawSprite(window, room->npc->sprites[0], NULL);
    return 1;
}
