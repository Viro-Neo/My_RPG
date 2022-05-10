/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to parse item files
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "item.h"

char *get_stat_value(char *stat)
{
    int i = 0;

    while (stat[i] != '\0' && stat[i] != '=')
        i += 1;
    i += 1;
    return &stat[i];
}

void fill_item_stats(item_t *item, char **stats)
{
    item->name = my_strdup(get_stat_value(stats[0]));
    item->name[my_strlen(item->name) - 1] = '\0';
    item->type = my_atoi(get_stat_value(stats[1]));
    item->stats->level = my_atoi(get_stat_value(stats[2]));
    item->stats->str = my_atoi(get_stat_value(stats[3]));
    item->stats->dex = my_atoi(get_stat_value(stats[4]));
    item->stats->wis = my_atoi(get_stat_value(stats[5]));
    item->stats->hp = my_atoi(get_stat_value(stats[6]));
    item->stats->mana = my_atoi(get_stat_value(stats[7]));
    item->stats->ac = my_atoi(get_stat_value(stats[8]));
    item->stats->max_hp = my_atoi(get_stat_value(stats[9]));
    item->stats->max_mana = my_atoi(get_stat_value(stats[10]));
    item->stats->money = my_atoi(get_stat_value(stats[11]));
    item->sprite = my_strdup(get_stat_value(stats[12]));
}

char *make_item_path(char *filename, char *filepath)
{
    char *dir_path = filepath;
    int size1 = my_strlen(dir_path);
    int size2 = my_strlen(filename);
    char *fullpath = malloc(sizeof(char) * (size1 + size2 + 1));
    int k = 0;

    for (int i = 0; i < size1; i++) {
        fullpath[k] = dir_path[i];
        k += 1;
    }
    for (int i = 0; i < size2; i++) {
        fullpath[k] = filename[i];
        k += 1;
    }
    fullpath[k] = '\0';
    return fullpath;
}

void parse_item(item_t *item, char *filepath)
{
    char *path = make_item_path(item->description, filepath);
    char *text = get_item_stats(path);
    int line_count = get_line_count(text);
    char **stats = malloc(sizeof(char *) * (line_count + 2));

    get_file_lines(text, stats);
    fill_item_stats(item, stats);
    free(path);
}
