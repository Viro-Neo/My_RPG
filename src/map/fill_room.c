/*
** EPITECH PROJECT, 2022
** fill_room.c
** File description:
** fill room with enemies
*/

#include <stdlib.h>
#include "game.h"
#include "my.h"
#include "map.h"
#include "dirent.h"

void add_coord_enemy(enemy_t *enemy, room_t *room)
{
    int x = rand() % 12 + 2;
    int y = rand() % 27 + 2;

    if (room->layout[x][y] != 'o' && room->layout[x][y] != 'x') {
        enemy->x = y;
        enemy->y = x;
    } else {
        add_coord_enemy(enemy, room);
    }
}

void add_enemy_coord(enemy_t **enemy, room_t *room)
{
    for (int i = 0; enemy[i] != NULL; i++) {
        add_coord_enemy(enemy[i], room);
    }
}

void add_enemy_to_room(room_t *room, int level, game_t *game)
{
    int rand_num = (rand() % (level + 3)) + 2;
    char *r_enemy;
    char *en_path = get_level_path(game->level, "assets/enemy/level", "/");
    char *path;
    int r;

    room->enemy = malloc(sizeof(enemy_t *) * (rand_num + 1));
    room->enemy[rand_num] = NULL;
    for (int i = 0; i != rand_num; i++) {
        if (room->type == (BOSS_ROOM))
            r = 3;
        else
            r = rand() % 2 + 1;
        r_enemy = get_npc_path(r, en_path);
        path = my_strcat(en_path, r_enemy);
        room->enemy[i] = init_enemy(path);
        free(r_enemy);
        free(path);
    }
}

void add_enemies_sprites(enemy_t **enemies)
{
    int i = 0;

    while (enemies[i] != NULL) {
        init_enemy_sprites(enemies[i]);
        i += 1;
    }
}

void fill_map(room_t **map, game_t *game)
{
    for (int i = 0; map[i] != NULL; i++)
        if (map[i]->type == ENEMY_ROOM || map[i]->type == BOSS_ROOM) {
            add_enemy_to_room(map[i], 1, game);
            add_enemy_coord(map[i]->enemy, map[i]);
        }
}
