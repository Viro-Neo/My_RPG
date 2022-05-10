/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "main_menu.h"
#include "main_menu_fct.h"
#include "useful_csfml.h"
#include "m_rpg.h"

static void reset_btn_states(main_menu_t *main_menu)
{
    main_menu->play_btn->is_clicked = false;
    main_menu->opt_btn->is_clicked = false;
    main_menu->htp_btn->is_clicked = false;
    main_menu->exit_btn->is_clicked = false;
    main_menu->play_btn->is_hover = false;
    main_menu->opt_btn->is_hover = false;
    main_menu->htp_btn->is_hover = false;
    main_menu->exit_btn->is_hover = false;
}

static int gameloop(game_t *game, main_menu_t *main_menu)
{
    while ((!main_menu->play_btn->is_clicked && \
            !main_menu->exit_btn->is_clicked) && \
            sfRenderWindow_isOpen(game->window)) {
        event_handling_menu(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
        reset_btn_states(main_menu);
        sfRenderWindow_drawSprite(game->window, main_menu->s_bg, NULL);
        display_btn(game->window, main_menu);
        if (main_menu->opt_btn->is_clicked)
            options_menu(main_menu->opt_menu, game);
        if (main_menu->htp_btn->is_clicked)
            htp_menu(game, main_menu->htp_menu);
        sfRenderWindow_display(game->window);
    }
    return main_menu->exit_btn->is_clicked;
}

static void free_btn(btn_t *btn)
{
    sfRectangleShape_destroy(btn->rectangle);
    sfTexture_destroy(btn->t_btn);
    free(btn);
}

void free_main_menu(main_menu_t *main_menu)
{
    free_btn(main_menu->play_btn);
    free_btn(main_menu->opt_btn);
    free_btn(main_menu->htp_btn);
    free_btn(main_menu->exit_btn);
    sfSprite_destroy(main_menu->s_bg);
    sfTexture_destroy(main_menu->t_bg);
    free(main_menu);
}

int main_menu(game_t *game)
{
    int exit = 1;
    main_menu_t *main_menu = init_main_menu();
    game->music = play_music("assets/musics/in_game/menu_music.ogg",
                             game->volume);

    if (gameloop(game, main_menu) == exit) {
        free_main_menu(main_menu);
        sfRenderWindow_close(game->window);
        sfRenderWindow_destroy(game->window);
        stop_music(game->music);
        return exit;
    }
    stop_music(game->music);
    return 0;
}
