/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to browse inventory
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "useful_csfml.h"
#include "entity.h"
#include "game.h"
#include "item.h"

void write_item_stats(char *name, stat_t *stats, sfRenderWindow *window, int x)
{
    int off1 = x + 50;
    int off2 = x + 250;

    write_stat(name, window, create_sfvector(off1, 125));
    write_stat("Level :", window, create_sfvector(off1, 175));
    write_stat(my_itoa(stats->level), window, create_sfvector(off2, 175));
    write_stat("Max hp :", window, create_sfvector(off1, 225));
    write_stat(my_itoa(stats->max_hp), window, create_sfvector(off2, 225));
    write_stat("Max mana :", window, create_sfvector(off1, 275));
    write_stat(my_itoa(stats->max_mana), window, create_sfvector(off2, 275));
    write_stat("Str :", window, create_sfvector(off1, 325));
    write_stat(my_itoa(stats->str), window, create_sfvector(off2, 325));
    write_stat("Wis :", window, create_sfvector(off1, 375));
    write_stat(my_itoa(stats->wis), window, create_sfvector(off2, 375));
    write_stat("Dex :", window, create_sfvector(off1, 425));
    write_stat(my_itoa(stats->dex), window, create_sfvector(off2, 425));
    write_stat("Armor :", window, create_sfvector(off1, 475));
    write_stat(my_itoa(stats->ac), window, create_sfvector(off2, 475));
}

void write_cost(char *stat, sfRenderWindow *window, sfVector2f pos)
{
    sfText *txt = sfText_create();
    sfFont *arial = sfFont_createFromFile("assets/font/Amatic-Bold.ttf");

    sfText_setString(txt, stat);
    sfText_setFont(txt, arial);
    sfText_setColor(txt, sfBlack);
    sfText_setPosition(txt, pos);
    sfText_setScale(txt, create_sfvector(0.7, 0.7));
    sfRenderWindow_drawText(window, txt, NULL);
    sfText_destroy(txt);
    sfFont_destroy(arial);
}