/*
** EPITECH PROJECT, 2022
** npc_talk.c
** File description:
** npc_talk
*/

#include <stdio.h>
#include <stdlib.h>
#include "useful_csfml.h"
#include "m_rpg.h"
#include "entity.h"
#include "game.h"

void write_npc_dialogue(npc_t *npc, sfRenderWindow *window)
{
    sfText *txt = sfText_create();
    sfFont *arial = sfFont_createFromFile("assets/font/arial.ttf");

    sfText_setString(txt, npc->text);
    sfText_setFont(txt, arial);
    sfText_setColor(txt, sfBlack);
    sfText_setPosition(txt, create_sfvector(225, 810));
    sfRenderWindow_drawText(window, txt, NULL);
    sfText_destroy(txt);
    sfFont_destroy(arial);
}

void npc_talk(npc_t *npc, sfRenderWindow *window)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, create_sfvector(200, 800));
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(120, 120, 120, 175));
    sfRectangleShape_setSize(rect, create_sfvector(800, 200));
    sfRenderWindow_drawSprite(window, npc->avatar, NULL);
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    write_npc_dialogue(npc, window);
    sfRectangleShape_destroy(rect);
}
