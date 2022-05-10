/*
** EPITECH PROJECT, 2022
** enemy_move.c
** File description:
** enemy_move
*/

#include "stdlib.h"
#include "game.h"

void free_int_array(int **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

int **create_path_array(char **array)
{
    int **result;
    int size_h = 0;
    int size_w = 0;

    for (size_h = 0; array[size_h] != NULL; size_h++);
    result = malloc(sizeof(int *) * (size_h + 1));
    result[size_h] = NULL;
    for (size_w = 0; array[0][size_w] != '\0'; size_w++);
    for (int i = 0; i < size_h; i++) {
        result[i] = malloc(sizeof(int) * size_w);
        for (int r = 0; r < size_w; r++)
            result[i][r] = -1;
    }
    return result;
}

int actual_move(int *c, int **path)
{
    int curr[2] = {c[0] + 1, c[1]};

    if (path[curr[0]][curr[1]] == -1 ||
        (path[curr[0]][curr[1]] > path[c[0] - 1][c[1]]
         && path[c[0] - 1][c[1]] != -1)) {
        curr[0] = c[0] - 1;
        curr[1] = c[1];
    }
    if (path[curr[0]][curr[1]] == -1 ||
        (path[curr[0]][curr[1]] > path[c[0]][c[1] - 1]
         && path[c[0]][c[1] - 1] != -1)) {
        curr[0] = c[0];
        curr[1] = c[1] - 1;
    }
    if (path[curr[0]][curr[1]] == -1 ||
        (path[curr[0]][curr[1]] > path[c[0]][c[1] + 1]
         && path[c[0]][c[1] + 1] != -1)) {
        curr[0] = c[0];
        curr[1] = c[1] + 1;
    }
    c[0] = curr[0];
    c[1] = curr[1];
    return 0;
}

void enemy_move(enemy_t *enemy, player_t *player, room_t *room)
{
    char **array = room->layout;
    int c[2] = {enemy->y, enemy->x};
    int **path = create_path_array(array);
    int end[2] = {player->y, player->x};

    recursion(path, room, end, 0);
    actual_move(c, path);
    if (path[c[0]][c[1]] != -1) {
        enemy->y = c[0];
        enemy->x = c[1];
    }
    free_int_array(path);
}
