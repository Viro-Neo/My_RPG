/*
** EPITECH PROJECT, 2022
** create_special_room.c
** File description:
** create_special_room
*/

#include "map.h"
#include "useful_csfml.h"
#include "stdlib.h"
#include "dirent.h"
#include "my.h"
#include "stdio.h"

static void find_right_coord(int *coord, room_t **map, int size)
{
    int x = 0;
    int y = 0;

    while (x == 0 && y == 0) {
        x = (rand() % size);
        y = (rand() % size);
    }
    for (int i = 0; map[i] != NULL; i++) {
        if (map[i]->x == x && map[i]->y == y && map[i]->type != 0) {
            return find_right_coord(coord, map, size);
        }
    }
    coord[0] = x;
    coord[1] = y;
    return;
}

char *get_npc_path(int indice, char *path)
{
    DIR *dir = opendir(path);
    char *room_name;
    char *room_id = my_itoa(indice);
    struct dirent *current;
    int i = 0;

    while ((current = readdir(dir)) != NULL) {
        while (room_id[i] == current->d_name[i])
            i++;
        if (room_id[i] == '\0' && current->d_name[i] == ':') {
            room_name = my_strdup(current->d_name);
        }
        i = 0;
    }
    if (room_id[0] != '0')
        free(room_id);
    closedir(dir);
    return room_name;
}

static void create_npc_room(room_t **map, int *coord, item_t **level_items)
{
    int x = coord[0];
    int y = coord[1];
    int random = rand() % count_file("assets/npc") + 101;
    char *npc_room = get_npc_path(random, "assets/rooms");
    char *path = my_strcat("assets/rooms/", npc_room);

    for (int i = 0; map[i] != NULL; i++) {
        if (map[i]->x == x && map[i]->y == y) {
            free_layout(map[i]->layout);
            map[i] = generate_room(path, x, y, NPC_ROOM);
            free(path);
            free(npc_room);
            npc_room = get_npc_path(random, "assets/npc");
            path = my_strcat("assets/npc/", npc_room);
            map[i]->npc = init_shop_npc(path, level_items);
            map[i]->enemy = NULL;
        }
    }
    free(npc_room);
    free(path);
}

static void create_boss_room(room_t **map, int *coord)
{
    int x = coord[0];
    int y = coord[1];
    char *path = "assets/rooms/boss.room";

    for (int i = 0; map[i] != NULL; i++) {
        if (map[i]->x == x && map[i]->y == y) {
            free_layout(map[i]->layout);
            map[i] = generate_room(path, x, y, BOSS_ROOM);
        }
    }
}

void create_special_room(room_t **map, int size, item_t **level_items)
{
    int coord[2] = {0, 0};

    for (int i = 0; i < size / 2; i++) {
        find_right_coord(coord, map, size);
        create_npc_room(map, coord, level_items);
    }
    find_right_coord(coord, map, size);
    create_boss_room(map, coord);
}
