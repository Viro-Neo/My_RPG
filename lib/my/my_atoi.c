/*
** EPITECH PROJECT, 2021
** my_atoi.c
** File description:
** ASCII to integer
*/

int my_atoi(char *str)
{
    int i = 0;
    int value = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        value *= 10;
        value += str[i] - 48;
        i += 1;
    }
    return value;
}