/*
** EPITECH PROJECT, 2021
** my_itoa.c
** File description:
** integer to ASCII
*/

#include <stdlib.h>
#include "my.h"

int my_intlen(int nb)
{
    int i = 0;

    while (nb != 0) {
        i++;
        nb = nb / 10;
    }
    return i;
}

char *my_itoa(int nb)
{
    int len = my_intlen(nb);
    char *res = malloc(len + 1);
    int j = len - 1;
    int div = 1;
    int mod = 10;

    if (nb == 0)
        return "0";
    for (; j >= 0; j--) {
        res[j] = ((nb % mod) / div) + '0';
        mod = mod * 10;
        div = div * 10;
    }
    res[len] = '\0';
    return res;
}
