/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to initialize spells
*/

#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "item.h"
#include "player_handling.h"

spell_t *init_spell(void)
{
    spell_t *spell = malloc(sizeof(spell_t));
    spell->stats = malloc(sizeof(stat_t));
    return spell;
}

spell_list_t *init_spells(char *path)
{
    DIR *dir = opendir(path);
    spell_list_t *spell_list;
    spell_list_t *spell;

    struct dirent *next;
    next = readdir(dir);
    spell_list = NULL;
    while (next) {
        if (next->d_name[0] != '.') {
            spell = malloc(sizeof(spell_list_t));
            spell->spell = init_spell();
            spell->spell->description = next->d_name;
            spell->next = spell_list;
            spell_list = spell;
        }
        next = readdir(dir);
    }
    return spell_list;
}