/*
** EPITECH PROJECT, 2022
** strcmp
** File description:
** strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int nbs1 = 0;
    int nbs2 = 0;

    for (int i = 0; s1[i] != '\0'; i++)
        nbs1 = nbs1 + s1[i];
    for (int i = 0; s2[i] != '\0'; i++)
        nbs2 = nbs2 + s2[i];
    if (nbs1 - nbs2 == 0)
        return 0;
    else if (nbs1 - nbs2 < 0)
        return -1;
    else
        return 1;
}
