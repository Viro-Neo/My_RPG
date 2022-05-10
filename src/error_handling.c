/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** error_handling
*/

#include "my.h"

int error_handling(int ac, char **av)
{
    int exit = 1;

    if (ac != 1)
        return exit;
    if (my_strcmp(av[0], "./my_rpg") != 0)
        return exit;
    return 0;
}
