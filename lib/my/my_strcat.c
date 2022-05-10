/*
** EPITECH PROJECT, 2021
** my_strcar
** File description:
** cat
*/

#include <stdlib.h>

int my_strlen(char const *);

void m_strcat(char *dest, char const *src)
{
    int len1 = my_strlen(dest);
    int len2 = my_strlen(src);
    int i = len1;

    for (int j = 0; j < len2; j++) {
        dest[i] = src[j];
        i += 1;
    }
    dest[i] = '\0';
}

char *my_strcat(char *dest, char const *src)
{
    int len2 = my_strlen(dest);
    int len1 = my_strlen(src);
    char *result = malloc(sizeof(char) * (len2 + len1 + 1));

    for (int i = 0; dest[i] != '\0'; i++) {
        result[i] = dest[i];
    }
    for (int i = 0; src[i] != '\0'; i++) {
        result[len2 + i] = src[i];
    }
    result[len2 + len1] = '\0';
    return result;
}
