/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to display popups
*/

#include <stdio.h>
#include <stdlib.h>
#include "useful_csfml.h"
#include "game.h"
#include "item.h"

void write_popup(char* text, sfRenderWindow *window, sfVector2f pos)
{
    sfText *txt = sfText_create();
    sfFont *arial = sfFont_createFromFile("assets/font/Amatic-Bold.ttf");

    sfText_setString(txt, text);
    sfText_setFont(txt, arial);
    sfText_setColor(txt, sfBlack);
    sfText_setPosition(txt, pos);
    sfRenderWindow_drawText(window, txt, NULL);
    sfText_destroy(txt);
    sfFont_destroy(arial);
}

void popup_box(char *text, sfRenderWindow *window)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, create_sfvector(610, 700));
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(120, 120, 120, 175));
    sfRectangleShape_setSize(rect, create_sfvector(700, 100));
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    write_popup(text, window, create_sfvector(625, 730));
    sfRectangleShape_destroy(rect);
}

void display_popup(game_t *game, char *text)
{
    int popup = 0;
    sfEvent *event = game->event;

    while (popup == 0) {
        if (sfRenderWindow_pollEvent(game->window, event))
            popup = (event->type == sfEvtKeyPressed &&
                    event->key.code == sfKeyReturn);
        sfRenderWindow_clear(game->window, sfBlack);
        draw(game);
        popup_box(text, game->window);
        sfRenderWindow_display(game->window);
    }
}