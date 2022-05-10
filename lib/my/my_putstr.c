/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** putstr
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    int nb = 0;

    nb = my_strlen(str);
    write(1, str, nb);
    return nb;
}

int my_puterr(char const *str)
{
    int nb = 0;

    nb = my_strlen(str);
    write(2, str, nb);
    return nb;
}
