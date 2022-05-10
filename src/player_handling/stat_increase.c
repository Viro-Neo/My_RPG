/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to handle player level
*/

#include <stdio.h>
#include <stdlib.h>
#include "useful_csfml.h"
#include "game.h"
#include "my.h"

char **make_stat_array(stat_t *stats, int points)
{
    char **stats_text = malloc(sizeof(char *) * (7 + 1));

    stats_text[0] = my_strcat("Points left : ", my_itoa(points));
    stats_text[1] = my_strcat("Max_hp : ", my_itoa(stats->max_hp));
    stats_text[2] = my_strcat("Max_mana : ", my_itoa(stats->max_mana));
    stats_text[3] = my_strcat("Str : ", my_itoa(stats->str));
    stats_text[4] = my_strcat("Wis : ", my_itoa(stats->wis));
    stats_text[5] = my_strcat("Dex : ", my_itoa(stats->dex));
    stats_text[6] = my_strcat("Armor : ", my_itoa(stats->ac));
    stats_text[7] = NULL;
    return stats_text;
}

void write_stat_s(char *stat, sfRenderWindow *window,
                  sfVector2f pos, int selected)
{
    sfText *txt = sfText_create();
    sfFont *arial = sfFont_createFromFile("assets/font/Amatic-Bold.ttf");

    sfText_setString(txt, stat);
    sfText_setFont(txt, arial);
    if (selected == 1)
        sfText_setColor(txt, sfWhite);
    else
        sfText_setColor(txt, sfBlack);
    sfText_setPosition(txt, pos);
    sfRenderWindow_drawText(window, txt, NULL);
    sfText_destroy(txt);
    sfFont_destroy(arial);
}

void write_stats_s(char **stat_arr, sfRenderWindow *window,
                   int index, game_t *game)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, create_sfvector(820, 10));
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(120, 120, 120, 175));
    sfRectangleShape_setSize(rect, create_sfvector(350, 375));
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    for (int i = 0; i < 7; i++) {
        write_stat_s(stat_arr[i], window,
                     create_sfvector(835, 25 + i * 50), i == (index + 1));
    }
    sfRectangleShape_destroy(rect);
    sfRenderWindow_display(game->window);
}

int stat_select_event(game_t *game, int *index, int limit)
{
    sfEvent *event = game->event;

    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyUp)
            adjust_index(index, -1, limit);
        if (event->key.code == sfKeyDown)
            adjust_index(index, 1, limit);
        if (event->key.code == sfKeyReturn)
            return 1;
    }
    return 0;
}

void select_stat_increase(game_t *game, player_t *player, int points)
{
    int index = 0;
    int selected = 0;
    char **stat_arr = make_stat_array(player->stat, points);

    while (selected == 0) {
        sfRenderWindow_clear(game->window, sfBlack);
        if (sfRenderWindow_pollEvent(game->window, game->event))
            selected = stat_select_event(game, &index, 6);
        draw(game);
        write_stats_s(stat_arr, game->window, index, game);
    }
    if (selected == -1)
        return;
    update_stats(player, index + 1);
    for (int i = 0; i < 7; i++)
        free(stat_arr[i]);
    free(stat_arr);
    if (points > 1)
        select_stat_increase(game, player, points - 1);
}
