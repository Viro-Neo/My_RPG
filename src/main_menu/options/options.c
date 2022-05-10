/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** options menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "useful_csfml.h"
#include "m_rpg.h"
#include "main_menu.h"
#include "main_menu_fct.h"

static void reset_btn_states(options_menu_t *opt_menu)
{
    opt_menu->back_btn->is_clicked = false;
    opt_menu->back_btn->is_hover = false;
    opt_menu->fullscreen_btn->is_clicked = false;
    opt_menu->fullscreen_btn->is_hover = false;
    opt_menu->sound_btn->is_clicked = false;
    opt_menu->sound_btn->is_hover = false;
    opt_menu->keybinding_btn->is_clicked = false;
    opt_menu->keybinding_btn->is_hover = false;
}

static void reset_modifications(options_menu_t *opt_menu)
{
    if (!opt_menu->back_btn->is_hover)
        sfRectangleShape_setSize(opt_menu->back_btn->rectangle,
            opt_menu->back_btn->size);
    if (!opt_menu->fullscreen_btn->is_hover)
        sfRectangleShape_setSize(opt_menu->fullscreen_btn->rectangle,
            opt_menu->fullscreen_btn->size);
    if (!opt_menu->sound_btn->is_hover)
        sfRectangleShape_setSize(opt_menu->sound_btn->rectangle,
            opt_menu->sound_btn->size);
    if (!opt_menu->keybinding_btn->is_hover)
        sfRectangleShape_setSize(opt_menu->keybinding_btn->rectangle,
                                    opt_menu->keybinding_btn->size);
}

static void check_options(options_menu_t *opt_menu, game_t *game)
{
    if (opt_menu->is_fullscreen) {
        if (opt_menu->fullscreen_btn->is_clicked) {
            set_fullscreen(game, sfFalse);
            opt_menu->is_fullscreen = false;
        }
    } else
        if (opt_menu->fullscreen_btn->is_clicked) {
            set_fullscreen(game, sfTrue);
            opt_menu->is_fullscreen = true;
        }
    check_music(game->music, opt_menu);
    if (opt_menu->keybinding_btn->is_clicked)
        select_key(game);
    if (opt_menu->sound_btn->is_clicked)
        select_volume(game);
}

static void update_status(btn_t *btn, int status, char which)
{
    sfTexture *new_text;

    if (which == 'f') {
        if (status) {
            new_text = sfTexture_createFromFile("assets/menu/options/btns/fs_onbtn.png", NULL);
            sfRectangleShape_setTexture(btn->rectangle, new_text, sfTrue);
        } else {
            new_text = sfTexture_createFromFile("assets/menu/options/btns/fs_offbtn.png", NULL);
            sfRectangleShape_setTexture(btn->rectangle, new_text, sfTrue);
        }
    } else if (which == 'm') {
        if (status == sfPlaying) {
            new_text = sfTexture_createFromFile("assets/menu/options/btns/msc_onbtn.png", NULL);
            sfRectangleShape_setTexture(btn->rectangle, new_text, sfTrue);
        } else {
            new_text = sfTexture_createFromFile("assets/menu/options/btns/msc_offbtn.png", NULL);
            sfRectangleShape_setTexture(btn->rectangle, new_text, sfTrue);
        }
    }
}

static void display_opt_btns(options_menu_t *opt_menu, game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    verify_mouse_pos_btn(mouse_pos, opt_menu->back_btn);
    sfRenderWindow_drawRectangleShape(game->window,
        opt_menu->back_btn->rectangle, NULL);
    verify_mouse_pos_btn(mouse_pos, opt_menu->fullscreen_btn);
    update_status(opt_menu->fullscreen_btn, opt_menu->is_fullscreen, 'f');
    sfRenderWindow_drawRectangleShape(game->window,
        opt_menu->fullscreen_btn->rectangle, NULL);
    verify_mouse_pos_btn(mouse_pos, opt_menu->sound_btn);
    update_status(opt_menu->sound_btn, sfMusic_getStatus(game->music), 'm');
    sfRenderWindow_drawRectangleShape(game->window,
        opt_menu->sound_btn->rectangle, NULL);
    verify_mouse_pos_btn(mouse_pos, opt_menu->keybinding_btn);
    sfRenderWindow_drawRectangleShape(game->window,
        opt_menu->keybinding_btn->rectangle, NULL);
    check_options(opt_menu, game);
    reset_modifications(opt_menu);
}

void options_menu(options_menu_t *opt_menu, game_t *game)
{
    opt_menu = init_options_menu();

    while (!opt_menu->back_btn->is_clicked &&
           sfRenderWindow_isOpen(game->window)) {
        event_handling_menu(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
        reset_btn_states(opt_menu);
        sfRenderWindow_drawSprite(game->window, opt_menu->s_bg, NULL);
        display_opt_btns(opt_menu, game);
        sfRenderWindow_display(game->window);
    }
}
