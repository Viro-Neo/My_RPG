/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** my_strlen
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;
    int counts = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        counts += 1;
        i += 1;
    }
    return (counts);
}
