/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to create spell array
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "useful_csfml.h"
#include "item.h"

char *make_spell_path(char *filename)
{
    char *dir_path = "assets/spells/";
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

void get_spell_status(spell_t *spell, char **array)
{
    spell->status = malloc(sizeof(status_t));
    spell->status->type = my_atoi(get_stat_value(array[12]));
    spell->status->timer = my_atoi(get_stat_value(array[13]));
    spell->status->damage = my_atoi(get_stat_value(array[14]));
    spell->status->chance = my_atoi(get_stat_value(array[15]));
    spell->status->max_timer = spell->status->timer;
    spell->status->active = 0;
}

spell_t *parse_spell(spell_t *spell)
{
    char *path = make_spell_path(spell->description);
    char *txt = get_item_stats(path);
    char **array = str_to_array(txt, '\n');

    spell->name = my_strdup(get_stat_value(array[0]));
    spell->type = my_atoi(get_stat_value(array[1]));
    spell->stats->level = my_atoi(get_stat_value(array[2]));
    spell->stats->str = my_atoi(get_stat_value(array[3]));
    spell->stats->dex = my_atoi(get_stat_value(array[4]));
    spell->stats->wis = my_atoi(get_stat_value(array[5]));
    spell->stats->hp = my_atoi(get_stat_value(array[6]));
    spell->stats->mana = my_atoi(get_stat_value(array[7]));
    spell->damage = my_atoi(get_stat_value(array[8]));
    spell->range = my_atoi(get_stat_value(array[9]));
    spell->stats->actions = my_atoi(get_stat_value(array[11]));
    get_spell_status(spell, array);
    free(txt);
    free_layout(array);
    return spell;
}

int count_spells(spell_list_t *spells)
{
    int count = 0;

    while (spells) {
        count += 1;
        spells = spells->next;
    }
    return count;
}

spell_t **make_spell_arr(void)
{
    spell_list_t *spells = init_spells("assets/spells/");
    int count = count_spells(spells);
    spell_t **spell_arr = malloc(sizeof(spell_t *) * (count + 1));
    int i = 0;

    if (spell_arr == NULL) {
        my_printf("failed to allocate memory for item array\n");
        return NULL;
    }
    while (spells != NULL) {
        parse_spell(spells->spell);
        spell_arr[i] = malloc(sizeof(spell_t));
        spell_arr[i] = spells->spell;
        spells = spells->next;
        i += 1;
    }
    spell_arr[i] = NULL;
    return spell_arr;
}
