/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to select options in combat
*/

#include <stdio.h>
#include <stdlib.h>
#include "useful_csfml.h"
#include "game.h"
#include "item.h"

void write_option(char *option, sfRenderWindow *win, int select, sfVector2f pos)
{
    sfText *txt = sfText_create();
    sfFont *arial = sfFont_createFromFile("assets/font/Amatic-Bold.ttf");

    sfText_setString(txt, option);
    sfText_setFont(txt, arial);
    if (select == 1)
        sfText_setColor(txt, sfWhite);
    else
        sfText_setColor(txt, sfBlack);
    sfText_setPosition(txt, pos);
    sfRenderWindow_drawText(win, txt, NULL);
    sfText_destroy(txt);
    sfFont_destroy(arial);
}

void option_menu(char *options[3], sfRenderWindow *window, int index)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, create_sfvector(200, 800));
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(120, 120, 120, 175));
    sfRectangleShape_setSize(rect, create_sfvector(330, 100));
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    for (int i = 0; i < 3; i++) {
        write_option(options[i], window, i == index,
                     create_sfvector(225 + i * 100, 830));
    }
    sfRectangleShape_destroy(rect);
}

void draw_options(game_t *game, int index)
{
    char *options[3] = {"spells", "items", "attack"};

    sfRenderWindow_clear(game->window, sfBlack);
    draw(game);
    option_menu(options, game->window, index);
    sfRenderWindow_display(game->window);
}

int option_select_event(game_t *game, int *index, int limit)
{
    sfEvent *event = game->event;
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == game->options->keys[KEY_MENU_LEFT])
            adjust_index(index, -1, limit);
        if (event->key.code == game->options->keys[KEY_MENU_RIGHT])
            adjust_index(index, 1, limit);
        if (event->key.code == game->options->keys[KEY_CONFIRM])
            return 1;
        if (event->key.code == game->options->keys[KEY_BACK])
            return -1;
    }
    return 0;
}

void select_combat_option(game_t *game, player_t *player)
{
    int index = 0;
    int selected = 0;

    void (*options[3])(game_t *, player_t *) = {select_spell,
        select_item, attack};
    while (selected == 0) {
        if (sfRenderWindow_pollEvent(game->window, game->event)) {
            check_window_closed(game);
            selected = option_select_event(game, &index, 3);
        }
        draw_options(game, index);
    }
    if (selected == -1)
        return;
    options[index](game, player);
}
