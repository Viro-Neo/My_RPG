/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** contains functions used to generate map
*/

#include <stdlib.h>
#include "game.h"
#include "my.h"
#include "map.h"
#include "dirent.h"

room_t *generate_room(char *path, int x, int y, int type)
{
    char *file = read_file(path);
    room_t *room;
    char **layout;

    if (file == NULL)
        return NULL;
    if ((room = malloc(sizeof(room_t) * 1)) == NULL)
        return NULL;
    if ((layout = str_to_array(file, '\n')) == NULL)
        return NULL;
    room->layout = layout;
    room->x = x;
    room->y = y;
    room->type = type;
    room->npc = NULL;
    room->enemy = NULL;
    free(file);
    return room;
}

char *random_room(int indice)
{
    DIR *dir = opendir("assets/rooms");
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

static int init_map(int i, room_t **map, int l, int c)
{
    char *rooms;
    int random_id = (rand() % 2) + 1;

    if (l == 0 && c == 0) {
        rooms = my_strcat("assets/rooms/", random_room(0));
        map[i] = generate_room(rooms, l, c, START_ROOM);
    }
    else {
        rooms = my_strcat("assets/rooms/", random_room(random_id));
        map[i] = generate_room(rooms, l, c, ENEMY_ROOM);
    }
    if (map[i] == NULL)
        return -1;
    free(rooms);
    return 0;
}

/*generate the map with random indice. the indice is the first number of the
name of room's file example: "1:test_room". The size is the size of map
size * size*/
room_t **generate_map(int size, item_t **level_items, game_t *game)
{
    room_t **map = malloc(sizeof(room_t *) * (size * size + 1));
    int l = 0;
    int c = 0;

    if (map == NULL)
        return NULL;
    for (int i = 0; i < size * size; i++) {
        init_map(i, map, l, c);
        c++;
        if (c == size) {
            l++;
            c = 0;
        }
    }
    map[size * size] = NULL;
    create_special_room(map, size, level_items);
    create_exit(map);
    fill_map(map, game);
    return map;
}
