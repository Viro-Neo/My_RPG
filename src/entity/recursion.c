/*
** EPITECH PROJECT, 2022
** recursion.c
** File description:
** rec
*/

#include "stdlib.h"
#include "game.h"

static int is_colision_enemy(enemy_t **enemy, int x, int y)
{
    if (enemy == NULL)
        return 1;
    for (int i = 0; enemy[i] != NULL; i++) {
        if (enemy[i]->x == x && enemy[i]->y == y) {
            return -1;
        }
    }
    return 1;
}

static int go_right(int **path, room_t *room, int *c, int step)
{
    char **array = room->layout;

    if (array[c[0]][c[1] + 1] != 'o' && array[c[0]][c[1] + 1] != 'x'
        && array[c[0]][c[1] + 1] != 'e' && array[c[0]][c[1] + 1] != 'd'
        && is_colision_enemy(room->enemy, c[1] + 1, c[0]) == 1
        && (path[c[0]][c[1] + 1] > step || path[c[0]][c[1] + 1] == -1)) {
        c[1]++;
        recursion(path, room, c, step + 1);
    }
    return 0;
}

static int go_left(int **path, room_t *room, int *c, int step)
{
    char **array = room->layout;

    if (array[c[0]][c[1] - 1] != 'o' && array[c[0]][c[1] - 1] != 'x'
        && array[c[0]][c[1] - 1] != 'e' && array[c[0]][c[1] - 1] != 'd'
        && is_colision_enemy(room->enemy, c[1] - 1, c[0]) == 1
        && (path[c[0]][c[1] - 1] > step || path[c[0]][c[1] - 1] == -1)) {
        c[1]--;
        recursion(path, room, c, step + 1);
    }
    return 0;
}

static int go_up(int **path, room_t *room, int *c, int step)
{
    char **array = room->layout;

    if (array[c[0] - 1][c[1]] != 'o' && array[c[0] - 1][c[1]] != 'x'
        && array[c[0] - 1][c[1]] != 'e' && array[c[0] - 1][c[1]] != 'd'
        && is_colision_enemy(room->enemy, c[1], c[0] - 1) == 1
        && (path[c[0] - 1][c[1]] > step || path[c[0] - 1][c[1]] == -1)) {
        c[0]--;
        recursion(path, room, c, step + 1);
    }
    return 0;
}

int recursion(int **path, room_t *room, int *c, int step)
{
    char **array = room->layout;
    int old[2] = {c[0], c[1]};

    if (step > 17)
        return 0;
    path[c[0]][c[1]] = step;
    go_left(path, room, c, step);
    c[1] = old[1];
    go_right(path, room, c, step);
    c[1] = old[1];
    go_up(path, room, c, step);
    c[0] = old[0];
    if (array[c[0] + 1][c[1]] != 'o' && array[c[0] + 1][c[1]] != 'x'
        && array[c[0] + 1][c[1]] != 'e' && array[c[0] + 1][c[1]] != 'd'
        && is_colision_enemy(room->enemy, c[1], c[0] + 1) == 1
        && (path[c[0] + 1][c[1]] > step || path[c[0] + 1][c[1]] == -1)) {
        c[0]++;
        recursion(path, room, c, step + 1);
    }
    c[0] = old[0];
    return 0;
}
