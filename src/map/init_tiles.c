/*
** EPITECH PROJECT, 2022
** init_tiles.c
** File description:
** init_tiles
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include "map.h"
#include "game.h"

tiles_t *add_tiles(char *path, char c)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    tiles_t *new = malloc(sizeof(tiles_t) * 1);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, 0);
    new->sprite = sprite;
    new->c = c;
    return new;
}

static int number_of_line(char *str)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            result++;
    }
    return result;
}

static void reset_path(char *str)
{
    for (int i = 0; i != 79; i++)
        str[i] = '\0';
}

void loop_tiles(char *file, tiles_t **tiles_array)
{
    int link = 0;
    int indice = 0;
    char path[80];

    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == '=') {
            path[link] = '\0';
            tiles_array[indice] = add_tiles(path, file[i + 1]);
            link = 0;
            i += 3;
            indice++;
            reset_path(path);
        }
        path[link] = file[i];
        link++;
    }
}

tiles_t **init_tiles(game_t *game)
{
    char *path = get_level_path(game->level,
                                "assets/tiles/level", "/all_tiles.txt");
    int fd = open(path, O_RDONLY);
    char file[1000];
    for (int i = 0; i < 1000; i++)
        file[i] = '\0';
    int test = read(fd, file, 1000);
    int nb_line = number_of_line(file);
    tiles_t **tiles_array = malloc(sizeof(tiles_t *) * (nb_line + 1));

    if (fd == -1 || test == -1)
        return NULL;
    loop_tiles(file, tiles_array);
    tiles_array[number_of_line(file)] = NULL;
    close(fd);
    return tiles_array;
}
