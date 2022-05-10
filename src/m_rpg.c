/*
** EPITECH PROJECT, 2021
** m_rpg.c
** File description:
** m_rpg
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "m_rpg.h"
#include "game.h"
#include "player_handling.h"
#include "main_menu.h"
#include "main_menu_fct.h"
#include "map.h"
#include "useful_csfml.h"
#include "pause_menu.h"

int event_handling_menu(sfRenderWindow *window)
{
    sfEvent *event = malloc(sizeof(sfEvent));

    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    free(event);
    return 0;
}

void check_window_closed(game_t *game)
{
    if (game->event->type == sfEvtClosed)
        sfRenderWindow_close(game->window);
}

int event_handling_game(sfRenderWindow *window, game_t *game)
{
    game->event = malloc(sizeof(sfEvent));
    int i = 0;

    if (sfRenderWindow_pollEvent(window, game->event) && i <= 2) {
        check_window_closed(game);
        player_event(game, game->event);
        game->player->stat->actions = 5;
        change_room(game);
        i++;
    } else
        idle_animation(game->player);
    while (sfRenderWindow_pollEvent(window, game->event)) {}
    if (game->player->stat->hp == 0)
        sfRenderWindow_close(game->window);
    free(game->event);
    return 0;
}

int m_rpg(int ac, char **av)
{
    srand(time(NULL));
    game_t *game = init_game(3);
    int exit = 1;

    if (error_handling(ac, av) == exit)
        return 84;
    sfRenderWindow_setFramerateLimit(game->window, 60);
    if (main_menu(game) == exit)
        return 0;
    game->music = play_music("assets/musics/in_game/in_game_music.ogg",
                             game->volume);
    while (sfRenderWindow_isOpen(game->window) != 0) {
        sfRenderWindow_clear(game->window, sfBlack);
        event_handling_game(game->window, game);
        draw(game);
        sfRenderWindow_display(game->window);
        if (game->exit_pause) {
            stop_music(game->music);
            free_game(game);
            m_rpg(ac, av);
        }
    }
    stop_music(game->music);
    return 1;
}
