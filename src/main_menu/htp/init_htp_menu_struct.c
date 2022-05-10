/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init how to play menu struct
*/

#include <stdlib.h>
#include "main_menu.h"
#include "game.h"
#include "useful_csfml.h"
#include "main_menu_fct.h"

static sfText *init_htp_text(char *text)
{
    sfText *txt = sfText_create();
    sfFont *arial = sfFont_createFromFile("assets/font/arial.ttf");

    sfText_setFont(txt, arial);
    sfText_setString(txt, text);
    sfText_setColor(txt, sfWhite);
    sfText_setPosition(txt, create_sfvector(10, 10));
    sfText_setScale(txt, create_sfvector(0.8, 0.8));
    return txt;
}

static sfSprite *init_htp_bg(void)
{
    sfTexture *texture;
    sfSprite *sprite = sfSprite_create();

    texture = sfTexture_createFromFile(
            "assets/menu/htp/blank_bg.jpg", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setColor(sprite, sfColor_fromRGBA(255, 255, 255, 75));
    return sprite;
}

static sfSprite *init_htp_title(void)
{
    sfTexture *texture;
    sfSprite *sprite = sfSprite_create();
    int title_width = 1331 * 0.4;
    int title_height = 470 * 0.4;
    float pos_x = 1920 / 2 - title_width / 2;
    float pos_y = 1080 - title_height;

    texture = sfTexture_createFromFile(
            "assets/menu/htp/htp_title.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, create_sfvector(0.4, 0.4));
    sfSprite_setPosition(sprite, create_sfvector(pos_x, pos_y));
    return sprite;
}

htp_menu_t *init_htp_menu(void)
{
    char *text_en = get_item_stats("assets/menu/htp/htp_en.txt");
    char *text_fr = get_item_stats("assets/menu/htp/htp_fr.txt");
    htp_menu_t *htp_menu = malloc(sizeof(htp_menu_t));

    htp_menu->back_btn = init_button("assets/menu/htp/btns/exitbtn.png",
                                                350, 1050);
    htp_menu->translate_btn = init_button("assets/menu/htp/btns/frenchbtn.png",
                                                1570, 1050);
    htp_menu->is_text_translated = false;
    htp_menu->txt_en = init_htp_text(text_en);
    htp_menu->txt_fr = init_htp_text(text_fr);
    htp_menu->bg_sprite = init_htp_bg();
    htp_menu->title_sprite = init_htp_title();
    return htp_menu;
}
