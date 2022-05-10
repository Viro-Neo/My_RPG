/*
** EPITECH PROJECT, 2022
** m_rpg
** File description:
** Pause menu
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "main_menu.h"
#include "main_menu_fct.h"
#include "pause_menu.h"

static void reset_btn_states(btns_t *btns)
{
    btns->btn_resume->is_clicked = false;
    btns->btn_resume->is_hover = false;
    btns->btn_options->is_clicked = false;
    btns->btn_options->is_hover = false;
    btns->btn_htp->is_clicked = false;
    btns->btn_htp->is_hover = false;
    btns->btn_exit->is_clicked = false;
    btns->btn_exit->is_hover = false;
}

static void reset_modifications(btns_t *btns)
{
    if (!btns->btn_resume->is_hover)
        sfRectangleShape_setSize(btns->btn_resume->rectangle,
                                    btns->btn_resume->size);
    if (!btns->btn_options->is_hover)
        sfRectangleShape_setSize(btns->btn_options->rectangle,
                                    btns->btn_options->size);
    if (!btns->btn_htp->is_hover)
        sfRectangleShape_setSize(btns->btn_htp->rectangle,
                                    btns->btn_htp->size);
    if (!btns->btn_exit->is_hover)
        sfRectangleShape_setSize(btns->btn_exit->rectangle,
                                    btns->btn_exit->size);
    reset_btn_states(btns);
}

static int handle_btns(btns_t *btns, game_t *game)
{
    int resume = 1;

    if (btns->btn_resume->is_clicked)
        return resume;
    if (btns->btn_options->is_clicked)
        options_menu(game->main_menu->opt_menu, game);
    if (btns->btn_htp->is_clicked)
        htp_menu(game, game->main_menu->htp_menu);
    if (btns->btn_exit->is_clicked)
        game->exit_pause = true;
    return 0;
}

static int display_btns(btns_t *btns, game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    int resume = 1;

    verify_mouse_pos_btn(mouse_pos, btns->btn_resume);
    sfRenderWindow_drawRectangleShape(game->window, btns->btn_resume->rectangle,
                                        NULL);
    verify_mouse_pos_btn(mouse_pos, btns->btn_options);
    sfRenderWindow_drawRectangleShape(game->window, btns->btn_options->rectangle,
                                        NULL);
    verify_mouse_pos_btn(mouse_pos, btns->btn_htp);
    sfRenderWindow_drawRectangleShape(game->window, btns->btn_htp->rectangle,
                                        NULL);
    verify_mouse_pos_btn(mouse_pos, btns->btn_exit);
    sfRenderWindow_drawRectangleShape(game->window, btns->btn_exit->rectangle,
                                        NULL);
    if (handle_btns(btns, game) == resume)
        return resume;
    reset_modifications(btns);
    return 0;
}

static int events_pause_menu(game_t *game, sfEvent *event, btns_t *btns)
{
    int resume = 1;

    if (display_btns(btns, game) == resume)
        return resume;
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event->type == sfEvtKeyPressed && event->key.code == game->options->keys[KEY_PAUSE])
            return resume;
    }
    return 0;
}

static void free_pause_menu_struct(pause_menu_t *pause_menu)
{
    sfRectangleShape_destroy(pause_menu->btns->btn_resume->rectangle);
    sfRectangleShape_destroy(pause_menu->btns->btn_options->rectangle);
    sfRectangleShape_destroy(pause_menu->btns->btn_htp->rectangle);
    sfRectangleShape_destroy(pause_menu->btns->btn_exit->rectangle);
    sfSprite_destroy(pause_menu->sprite->sprite);
    sfTexture_destroy(pause_menu->sprite->texture);
    free(pause_menu->btns->btn_resume);
    free(pause_menu->btns->btn_options);
    free(pause_menu->btns->btn_htp);
    free(pause_menu->btns->btn_exit);
    free(pause_menu->sprite);
    free(pause_menu);
}

void pause_menu(game_t *game)
{
    sfEvent event;
    int resume = 1;
    pause_menu_t *pause_menu = init_pause_menu();
    game->main_menu = init_main_menu();

    while (sfRenderWindow_isOpen(game->window) && !game->exit_pause) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, pause_menu->sprite->sprite, NULL);
        if (events_pause_menu(game, &event, pause_menu->btns) == resume)
            return;
        sfRenderWindow_display(game->window);
    }
    free_pause_menu_struct(pause_menu);
    free_main_menu(game->main_menu);
}
