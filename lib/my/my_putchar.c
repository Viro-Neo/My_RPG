/*
** EPITECH PROJECT, 2022
** putchar
** File description:
** puchar
*/

#include "my.h"
#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
