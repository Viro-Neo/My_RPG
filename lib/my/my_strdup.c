/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** memory alloc
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *copy;
    int size = 0;
    int i = 0;

    while (src[size] != '\0') {
        size += 1;
    }
    copy = malloc((size) + 1);
    while (i < size) {
        copy[i] = src[i];
        i += 1;
    }
    copy[i] = '\0';
    return (copy);
}
