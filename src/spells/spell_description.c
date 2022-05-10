/*
** EPITECH PROJECT, 2021
** my_rpg
** functions used to display spell description
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "useful_csfml.h"
#include "game.h"
#include "item.h"

void write_spell_text(char *text, sfRenderWindow *window, sfVector2f pos)
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

char *get_effect(int id)
{
    char *effect[7] = {"None", "Poison", "Freeze",
                       "Lifesteal", "Stoneskin", "Berserk", "Blind"};
    return effect[id];
}

void write_spell_stat(char *stat, int value, sfRenderWindow *window, int i)
{
    char *text;
    char *effect;

    if (my_strcmp(stat, "Effect :") == 0) {
        effect = get_effect(value);
        text = my_strcat(stat, effect);
        write_spell_text(text, window, create_sfvector(515, 115 + (i * 45)));
        free(text);
        return;
    }
    if (value == -1) {
        write_spell_text(stat, window, create_sfvector(515, 115 + (i * 45)));
        return;
    }
    text = my_strcat(stat, my_itoa(value));
    write_spell_text(text, window, create_sfvector(515, 115 + (i * 45)));
    free(text);
}

void write_spell_stats(spell_t *spell, sfRenderWindow *window)
{
    write_spell_stat(spell->name, -1, window, 0);
    write_spell_stat("Str required :", spell->stats->str, window, 1);
    write_spell_stat("Wis required :", spell->stats->wis, window, 2);
    write_spell_stat("Dex required :", spell->stats->dex, window, 3);
    write_spell_stat("Mana cost :", spell->stats->mana, window, 4);
    write_spell_stat("Actions cost :", spell->stats->actions, window, 5);
    write_spell_stat("Hp recovered :", spell->stats->hp, window, 6);
    write_spell_stat("Damage dealt :", spell->damage, window, 7);
    write_spell_stat("Effect :", spell->status->type, window, 8);
}

void spell_description(spell_t *spell, sfRenderWindow *window)
{
    if (spell == NULL)
        return;
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, create_sfvector(500, 100));
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(120, 120, 120, 175));
    sfRectangleShape_setSize(rect, create_sfvector(500, 500));
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    write_spell_stats(spell, window);
    sfRectangleShape_destroy(rect);
}