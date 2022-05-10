/*
** EPITECH PROJECT, 2022
** str_to_array.c
** File description:
** str to array
*/

#include "stdlib.h"
#include "stdio.h"

static int initialize_array_line(char *str, char **array, char delim)
{
    int c = 0;
    int l = 0;
    int indice = 0;

    while (str[indice] != '\0') {
        if (str[indice] == delim) {
            array[l] = malloc(sizeof(char) * (c + 1));
            array[l][c] = '\0';
            c = 0;
            l++;
            indice++;
        } else {
            indice++;
            c++;
        }
    }
    return 0;
}

static char **initialize_array(char *str, char delim)
{
    char **array;
    int l = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim)
            l++;
    }
    array = malloc(sizeof(char *) * (l + 1));
    if (array == NULL)
        return NULL;
    array[l] = NULL;
    return array;
}

char **str_to_array(char *str, char delim)
{
    char **array = initialize_array(str, delim);
    int l = 0;
    int c = 0;
    int indice = 0;

    initialize_array_line(str, array, delim);
    while (str[indice] != '\0') {
        if (str[indice] == delim) {
            c = 0;
            l++;
            indice++;
        } else {
            array[l][c] = str[indice];
            indice++;
            c++;
        }
    }
    return array;
}
