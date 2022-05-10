/*
** EPITECH PROJECT, 2022
** count_file.c
** File description:
** count_file
*/

#include <stdlib.h>
#include "game.h"
#include "useful_csfml.h"
#include "my.h"

void write_sound(char *key, sfRenderWindow *window, sfVector2f pos)
{
    sfText *txt = sfText_create();
    sfFont *arial = sfFont_createFromFile("assets/font/Amatic-Bold.ttf");

    sfText_setString(txt, key);
    sfText_setFont(txt, arial);
    sfText_setColor(txt, sfWhite);
    sfText_setPosition(txt, pos);
    sfText_setScale(txt, create_sfvector(5, 5));
    sfRenderWindow_drawText(window, txt, NULL);
    sfText_destroy(txt);
    sfFont_destroy(arial);
}

void set_volume_menu(game_t *game, int index)
{
    sfRenderWindow *window = game->window;
    char *pre;
    char *post;

    char *volume = my_itoa((int)sfMusic_getVolume(game->music));
    pre = my_strcat("<  ", volume);
    post = my_strcat(pre, "  >");
    write_sound(post, game->window, create_sfvector(850, 540));
}

void draw_volume_select(game_t *game, int index)
{
    sfRenderWindow_clear(game->window, sfBlack);
    set_volume_menu(game, index);
    sfRenderWindow_display(game->window);
}

int volume_select_event(game_t *game, int *index, int limit)
{
    sfEvent *event = game->event;

    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == game->options->keys[KEY_MENU_LEFT])
            adjust_index(index, -5, limit);
        if (event->key.code == game->options->keys[KEY_MENU_RIGHT])
            adjust_index(index, 5, limit);
        if (event->key.code == game->options->keys[KEY_CONFIRM])
            return -1;
        if (event->key.code == game->options->keys[KEY_BACK])
            return -1;
    }
    return 0;
}

void select_volume(game_t *game)
{
    int index = (int)sfMusic_getVolume(game->music);
    int selected = 0;

    if (game->event == NULL)
        game->event = malloc(sizeof(sfEvent));
    sfMusic_play(game->music);
    while (selected == 0) {
        if (sfRenderWindow_pollEvent(game->window, game->event)) {
            check_window_closed(game);
            selected = volume_select_event(game, &index, 100);
            sfMusic_setVolume(game->music, index);
            game->volume = index;
            sfMusic_play(game->music);
        }
        draw_volume_select(game, index);
    }
}
