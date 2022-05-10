/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions get text from item files
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char *get_item_stats(char *path)
{
    int fd = open(path, O_RDONLY);
    ssize_t size = 0;
    char buf[30000];
    char *text;

    if (fd == -1)
        return NULL;
    if ((size = read(fd, buf, 30000)) == -1)
        return NULL;
    text = malloc(sizeof(char) * (size + 2));
    for (int i = 0; i < size; i++) {
        text[i] = buf[i];
    }
    text[size] = 0;
    text[size + 1] = 0;
    return text;
}

int get_line_count(char *text)
{
    int i = 0;
    int line_count = 0;

    while (text[i]) {
        if (text[i] == '\n')
            line_count += 1;
        i += 1;
    }
    return line_count + 1;
}

int get_line_size(char *text)
{
    int i = 0;

    while (text[i] && text[i] != '\n')
        i += 1;
    return i;
}

int my_getline(char *text, char *line, int i)
{
    int j = 0;
    while (text[i] != '\0' && text[i] != '\n') {
        line[j] = text[i];
        i += 1;
        j += 1;
    }
    line[j] = text[i];
    line[j + 1] = '\0';
    return i + 1;
}

void get_file_lines(char *text, char **lines)
{
    int i = 0;
    int j = 0;
    int line_size = 0;

    while (text[i] != '\0') {
        line_size = get_line_size(&text[i]);
        lines[j] = malloc(sizeof(char) * (line_size + 2));
        if (lines[j] == NULL)
            return;
        i = my_getline(text, lines[j], i);
        j += 1;
    }
    lines[j] = NULL;
    free(text);
}