/*
** EPITECH PROJECT, 2022
** cleanup_room.c
** File description:
** cleannup the map
*/

#include "my.h"
#include "map.h"
#include "stdlib.h"

static int get_map_width(room_t **map)
{
    int i = 0;

    while (map[i] != NULL)
        i++;
    return map[i - 1]->x + 1;
}

static int get_map_height(room_t **map)
{
    int i = 0;

    while (map[i] != NULL)
        i++;
    return map[i - 1]->y + 1;
}

static void verif_exit(room_t **map, int l, int c, int *max)
{
    int random;

    if (l != max[0] - 1) {
        random = (rand() % 27) + 1;
        map[max[2]]->layout[14][random] = 'e';
        map[max[2] + max[0]]->layout[0][random] = 'e';
    }
    if (c != max[1] - 1) {
        random = (rand() % 13) + 1;
        map[max[2]]->layout[random][29] = 'e';
        map[max[2] + 1]->layout[random][0] = 'e';
    }
}

static void create_door(int *max, room_t **map, int l, int c)
{
    room_t *boss = map[max[2]];

    if (boss->layout[l][c] == 'e') {
        boss->layout[l][c] = 'd';
        if (l == 0)
            map[max[2] - max[0]]->layout[14][c] = 'd';
        if (c == 0)
            map[max[2] - 1]->layout[l][29] = 'd';
        if (l == 14)
            map[max[2] + max[0]]->layout[0][c] = 'd';
        if (c == 29)
            map[max[2] + 1]->layout[l][0] = 'd';
    }
}

void create_exit(room_t **map)
{
    int max[3] = {get_map_height(map), get_map_width(map), 0};

    for (int l = 0; map[max[2]] != NULL; l++) {
        for (int c = 0; c < max[1] && map[max[2]] != NULL; c++) {
            verif_exit(map, l, c, max);
            max[2] = max[2] + 1;
        }
    }
    for (int i = 0; map[i] != NULL; i++)
        if (map[i]->type == BOSS_ROOM)
            max[2] = i;
    for (int l = 0; map[max[2]]->layout[l] != NULL; l++) {
        for (int c = 0; map[max[2]]->layout[l][c] != '\0'; c++) {
            create_door(max, map, l, c);
        }
    }
}
//create_exit crée les exit de chaques rooms.
