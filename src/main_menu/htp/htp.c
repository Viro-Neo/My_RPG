/*
** EPITECH PROJECT, 2022
** m_rpg
** File description:
** How to play menu
*/

#include "stdlib.h"
#include "game.h"
#include "useful_csfml.h"
#include "main_menu.h"
#include "main_menu_fct.h"

static void reset_btn_states(htp_menu_t *htp_menu)
{
    htp_menu->back_btn->is_clicked = false;
    htp_menu->back_btn->is_hover = false;
    htp_menu->translate_btn->is_clicked = false;
    htp_menu->translate_btn->is_hover = false;
}

static void reset_modifications(htp_menu_t *htp_menu)
{
    if (!htp_menu->back_btn->is_hover)
        sfRectangleShape_setSize(htp_menu->back_btn->rectangle,
                                    htp_menu->back_btn->size);
    if (!htp_menu->translate_btn->is_hover)
        sfRectangleShape_setSize(htp_menu->translate_btn->rectangle,
                                    htp_menu->translate_btn->size);
}

static void draw_buttons_split(htp_menu_t *htp_menu, sfRenderWindow *window)
{
    if (htp_menu->translate_btn->is_clicked && !htp_menu->is_text_translated) {
        htp_menu->is_text_translated = true;
        htp_menu->translate_btn->t_btn = sfTexture_createFromFile(
            "assets/menu/htp/btns/englishbtn.png", NULL);
        sfRectangleShape_setTexture(htp_menu->translate_btn->rectangle,
                                    htp_menu->translate_btn->t_btn, sfTrue);
    }
    else if (htp_menu->translate_btn->is_clicked &&
            htp_menu->is_text_translated) {
        htp_menu->is_text_translated = false;
        htp_menu->translate_btn->t_btn = sfTexture_createFromFile(
            "assets/menu/htp/btns/frenchbtn.png", NULL);
        sfRectangleShape_setTexture(htp_menu->translate_btn->rectangle,
                                    htp_menu->translate_btn->t_btn, sfTrue);
    }
}

static void draw_buttons(htp_menu_t *htp_menu, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    verify_mouse_pos_btn(mouse_pos, htp_menu->back_btn);
    sfRenderWindow_drawRectangleShape(window, htp_menu->back_btn->rectangle,
                                        NULL);
    verify_mouse_pos_btn(mouse_pos, htp_menu->translate_btn);
    sfRenderWindow_drawRectangleShape(window,
                                    htp_menu->translate_btn->rectangle,
                                    NULL);
    draw_buttons_split(htp_menu, window);
    reset_modifications(htp_menu);
}

static void free_n_exit(htp_menu_t *htp_menu)
{
    sfText_destroy(htp_menu->txt_en);
    sfText_destroy(htp_menu->txt_fr);
    sfSprite_destroy(htp_menu->bg_sprite);
    sfSprite_destroy(htp_menu->title_sprite);
    sfRectangleShape_destroy(htp_menu->back_btn->rectangle);
    sfRectangleShape_destroy(htp_menu->translate_btn->rectangle);
    free(htp_menu->back_btn);
    free(htp_menu->translate_btn);
    free(htp_menu);
}

static void htp_text_handling(htp_menu_t *htp_menu, sfRenderWindow *window)
{
    if (htp_menu->is_text_translated)
        sfRenderWindow_drawText(window, htp_menu->txt_fr, NULL);
    else
        sfRenderWindow_drawText(window, htp_menu->txt_en, NULL);
}

void htp_menu(game_t *game, htp_menu_t *htp_menu)
{
    htp_menu = init_htp_menu();

    game->event = malloc(sizeof(sfEvent));
    while (sfRenderWindow_isOpen(game->window))
    {
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, htp_menu->bg_sprite, NULL);
        sfRenderWindow_drawSprite(game->window, htp_menu->title_sprite, NULL);
        htp_text_handling(htp_menu, game->window);
        draw_buttons(htp_menu, game->window);
        if (htp_menu->back_btn->is_clicked)
            break;
        if (sfRenderWindow_pollEvent(game->window, game->event) &&
                game->event->type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        reset_btn_states(htp_menu);
        sfRenderWindow_display(game->window);
    }
    free_n_exit(htp_menu);
}
