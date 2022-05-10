/*
** EPITECH PROJECT, 2022
** m_rpg
** File description:
** Init pause menu struct
*/

#include <stdlib.h>
#include "main_menu.h"
#include "main_menu_fct.h"
#include "pause_menu.h"

static sprite_t *init_sprite(sprite_t *sprite)
{
    int width = 800 / 2;
    int height = 967 / 2;

    sprite->pos.x = 1920 / 2 - width;
    sprite->pos.y = 1080 / 2 - height;
    sprite->texture = sfTexture_createFromFile("assets/pause/pause_bg.png", NULL);
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    return sprite;
}

static btns_t *init_btns(btns_t *btns)
{
    btns->btn_resume = init_button("assets/pause/btns/resume.png",
                                                    1920 / 2, 360);
    btns->btn_options = init_button("assets/pause/btns/options.png",
                                                    1920 / 2, 550);
    btns->btn_htp = init_button("assets/pause/btns/htp.png",
                                            1920 / 2, 740);
    btns->btn_exit = init_button("assets/pause/btns/exit.png",
                                            1920 / 2, 930);
    return btns;
}

pause_menu_t *init_pause_menu(void)
{
    pause_menu_t *pause_menu = malloc(sizeof(pause_menu_t));
    pause_menu->sprite = malloc(sizeof(sprite_t));
    pause_menu->btns = malloc(sizeof(btns_t));

    pause_menu->sprite = init_sprite(pause_menu->sprite);
    pause_menu->btns = init_btns(pause_menu->btns);
    return pause_menu;
}