/*
** EPITECH PROJECT, 2022
** count_file.c
** File description:
** count_file
*/

#include "stdlib.h"
#include "dirent.h"

int count_file(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *current;
    int i = 0;

    if (dir == NULL)
        return 0;
    while ((current = readdir(dir)) != NULL)
        if (current->d_type == DT_REG)
            i++;
    closedir(dir);
    return i;
}
