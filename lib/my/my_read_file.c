/*
** EPITECH PROJECT, 2022
** my_read_file.c
** File description:
** read a file
*/

#include "unistd.h"
#include "stdlib.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"

char *read_file(char *path)
{
    struct stat *buf = malloc(sizeof(struct stat));
    char *result;
    int fd = 0;

    if (stat(path, buf) == -1)
        return NULL;
    fd = open(path, O_RDONLY);
    if (fd == -1)
        return NULL;
    result = malloc(sizeof(char) * buf->st_size + 1);
    if (result == NULL)
        return NULL;
    if (read(fd, result, buf->st_size) == -1)
        return NULL;
    result[buf->st_size] = '\0';
    close(fd);
    free(buf);
    return result;
}
