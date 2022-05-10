/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to display player stats
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "useful_csfml.h"
#include "game.h"
#include "item.h"

void write_stat(char *stat, sfRenderWindow *window, sfVector2f pos)
{
    sfText *txt = sfText_create();
    sfFont *arial = sfFont_createFromFile("assets/font/Amatic-Bold.ttf");

    sfText_setString(txt, stat);
    sfText_setFont(txt, arial);
    sfText_setColor(txt, sfBlack);
    sfText_setPosition(txt, pos);
    sfRenderWindow_drawText(window, txt, NULL);
    sfText_destroy(txt);
    sfFont_destroy(arial);
}

void write_stats(stat_t *stats, sfRenderWindow *window)
{
    write_stat("Level :", window, create_sfvector(835, 25));
    write_stat(my_itoa(stats->level), window, create_sfvector(1035, 25));
    write_stat("Max hp :", window, create_sfvector(835, 75));
    write_stat(my_itoa(stats->max_hp), window, create_sfvector(1035, 75));
    write_stat("Hp :", window, create_sfvector(835, 125));
    write_stat(my_itoa(stats->hp), window, create_sfvector(1035, 125));
    write_stat("Max mana :", window, create_sfvector(835, 175));
    write_stat(my_itoa(stats->max_mana), window, create_sfvector(1035, 175));
    write_stat("Mana :", window, create_sfvector(835, 225));
    write_stat(my_itoa(stats->mana), window, create_sfvector(1035, 225));
    write_stat("Str :", window, create_sfvector(835, 275));
    write_stat(my_itoa(stats->str), window, create_sfvector(1035, 275));
    write_stat("Wis :", window, create_sfvector(835, 325));
    write_stat(my_itoa(stats->wis), window, create_sfvector(1035, 325));
    write_stat("Dex :", window, create_sfvector(835, 375));
    write_stat(my_itoa(stats->dex), window, create_sfvector(1035, 375));
    write_stat("Armor :", window, create_sfvector(835, 425));
    write_stat(my_itoa(stats->ac), window, create_sfvector(1035, 425));
}

void player_stat_display(player_t *player, sfRenderWindow *window)
{
    write_stats(player->stat, window);
}
