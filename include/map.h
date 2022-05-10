/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** header file for map handling
*/

#ifndef MAP_H_
    #define MAP_H_
    #include "entity.h"
    #include "player_handling.h"
    #include <SFML/Graphics/Types.h>
    #define START_ROOM    4
    #define CLEARED_ROOM  3
    #define ENEMY_ROOM    0
    #define NPC_ROOM      1
    #define BOSS_ROOM     2

typedef struct tiles_s
{
    sfSprite *sprite;
    char c;
} tiles_t;

    typedef struct room_s
    {
        char **layout;
        int x;
        int y;
        int type;
        struct npc_s *npc;
        struct enemy_s **enemy;
    } room_t;

tiles_t *choose_tile(char c, tiles_t **array_tiles);
int draw_room(sfRenderWindow *window, tiles_t **array_tiles, room_t *room);
void create_exit(room_t **map);
sfRenderWindow *create_window(unsigned int width, unsigned int height);
void free_map(room_t **map);
void free_tiles(tiles_t **);
room_t *generate_room(char *path, int x, int y, int type);
void free_layout(char **layout);
void create_special_room(room_t **map, int size, item_t **level_items);
char *random_room(int indice);
char *get_level_path(int level, char *pre, char *post);

#endif/* MAP_H_ */
