/*
** EPITECH PROJECT, 2021
** my_rpg
** functions used to display status effects
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "useful_csfml.h"
#include "game.h"
#include "item.h"

void write_effect_timer(status_t *status,
                        sfRenderWindow *window, sfVector2f pos)
{
    sfText *txt = sfText_create();
    sfFont *arial = sfFont_createFromFile("assets/font/Amatic-Bold.ttf");

    sfText_setString(txt, my_itoa(status->timer));
    sfText_setFont(txt, arial);
    sfText_setColor(txt, sfWhite);
    sfText_setPosition(txt, pos);
    sfRenderWindow_drawText(window, txt, NULL);
    sfText_destroy(txt);
    sfFont_destroy(arial);
}

char *get_sprite(int id)
{
    char *paths[6] = {"assets/effects/poison_status-1.png.png",
                      "assets/effects/freeze_status-1.png.png",
                      "assets/effects/Lifesteal_status-1.png.png",
                      "assets/effects/status_stoneskin-1.png.png",
                      "assets/effects/berserk_effect-1.png.png",
                      "assets/effects/blind_effect-1.png.png"};
    return paths[id];
}

void draw_status_effect(char *path, sfRenderWindow *window, sfVector2f pos)
{
    sfTexture *texture;
    sfSprite *sprite = sfSprite_create();

    texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    return;
}

void display_status(player_t *player, sfRenderWindow *window)
{
    char *path;

    for (int i = 0; i < MAX_STATUS; i++) {
        if (player->status[i] == NULL)
            continue;
        path = get_sprite(player->status[i]->type - 1);
        draw_status_effect(path, window, create_sfvector(75 + (i * 50), 970));
        write_effect_timer(player->status[i], window,
                           create_sfvector(100 + (i * 50), 967));
    }
}