/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init options menu struct
*/

#include <stdlib.h>
#include "main_menu.h"
#include "main_menu_fct.h"

options_menu_t *init_options_menu(void)
{
    options_menu_t *opt_menu = malloc(sizeof(options_menu_t));

    opt_menu->t_bg = sfTexture_createFromFile("assets/menu/options/bg.jpg",
                                                                    NULL);
    opt_menu->s_bg = sfSprite_create();
    sfSprite_setTexture(opt_menu->s_bg, opt_menu->t_bg, sfTrue);
    opt_menu->back_btn = init_button("assets/menu/options/btns/backbtn.png",
                                                                    400, 200);
    opt_menu->fullscreen_btn = init_button("assets/menu/options/btns/fs_offbtn.png",
                                                            1920 / 2, 1080 / 2);
    opt_menu->is_fullscreen = false;
    opt_menu->sound_btn = init_button("assets/menu/options/btns/msc_onbtn.png",
                                                1920 / 2, 1080 / 2 + 200);
    opt_menu->keybinding_btn = init_button("assets/menu/options/btns/kbbtn.png",
                                                    1920 / 2, 1080 / 2 + 400);
    return opt_menu;
}
