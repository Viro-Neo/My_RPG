/*
** EPITECH PROJECT, 2021
** my_rpg
** functions used to display spell selection
*/

#include <stdio.h>
#include <stdlib.h>
#include "useful_csfml.h"
#include "game.h"
#include "item.h"

sfVector2f get_menu_pos(int index, int limit)
{
    int x = 125 + ((index % limit) * 150);
    int y = 125 + ((index / limit) * 100);
    return create_sfvector(x, y);
}

void write_spell(spell_t *spell, sfRenderWindow *window,
                  int selected, sfVector2f pos)
{
    sfText *txt = sfText_create();
    sfFont *arial = sfFont_createFromFile("assets/font/Amatic-Bold.ttf");

    sfText_setString(txt, spell->name);
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

void spell_menu(spell_t **spells, sfRenderWindow *window,
                int index, int spell_count)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, create_sfvector(100, 100));
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(120, 120, 120, 175));
    sfRectangleShape_setSize(rect, create_sfvector(350, 800));
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    for (int i = 0; i < spell_count; i++)
        write_spell(spells[i], window,
                    i == index, get_menu_pos(i, 2));
    sfRectangleShape_destroy(rect);
}

void draw_spell_select(game_t *game, int index, int spell_count)
{
    spell_t **spells = game->player->spells;

    sfRenderWindow_clear(game->window, sfBlack);
    draw(game);
    spell_menu(spells, game->window, index, spell_count);
    spell_description(spells[index], game->window);
    sfRenderWindow_display(game->window);
}
