/*
** EPITECH PROJECT, 2022
** m_rpg
** File description:
** functions used to handle key binding
*/

#include <stdlib.h>
#include "my.h"
#include "options.h"
#include "game.h"
#include "useful_csfml.h"

void write_key_change(char *key, sfRenderWindow *window)
{
    sfText *txt = sfText_create();
    sfFont *arial = sfFont_createFromFile("assets/font/Amatic-Bold.ttf");
    char *text = my_strcat("Select  new  key  for  ", key);

    sfText_setString(txt, text);
    sfText_setFont(txt, arial);
    sfText_setColor(txt, sfWhite);
    sfText_setPosition(txt, create_sfvector(125, 950));
    sfRenderWindow_drawText(window, txt, NULL);
    sfText_destroy(txt);
    sfFont_destroy(arial);
    sfRenderWindow_display(window);
}

static int key_bind_event(game_t *game)
{
    sfEvent *event = game->event;

    if (event->type == sfEvtKeyPressed) {
        return event->key.code;
    }
    return 0;
}

static void get_key_bind(game_t *game, int index)
{
    int selected = 0;
    char *key_type[KEY_COUNT] =
            {"  Confirm", "  Act", "  Pause", "  Move left",
            "  Move up", "  Move right", "  Move down", "  Interact",
            "  Menu left", "  Menu up", "  Menu right",
            "  Menu down", "  Back"};

    write_key_change(key_type[index], game->window);
    while (selected == 0)
        if (sfRenderWindow_pollEvent(game->window, game->event))
            selected = key_bind_event(game);
    if (selected == -1)
        return;
    game->options->keys[index] = selected;
}

int key_select_event(game_t *game, int *index, int limit)
{
    sfEvent *event = game->event;

    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == game->options->keys[KEY_MENU_LEFT])
            adjust_index(index, -5, limit);
        if (event->key.code == game->options->keys[KEY_MENU_RIGHT])
            adjust_index(index, 5, limit);
        if (event->key.code == game->options->keys[KEY_MENU_UP])
            adjust_index(index, -1, limit);
        if (event->key.code == game->options->keys[KEY_MENU_DOWN])
            adjust_index(index, 1, limit);
        if (event->key.code == game->options->keys[KEY_CONFIRM])
            return 1;
        if (event->key.code == game->options->keys[KEY_BACK])
            return -1;
    }
    return 0;
}

void select_key(game_t *game)
{
    int index = 0;
    int selected = 0;

    if (game->event == NULL)
        game->event = malloc(sizeof(sfEvent));
    while (selected == 0) {
        if (sfRenderWindow_pollEvent(game->window, game->event)) {
            check_window_closed(game);
            selected = key_select_event(game, &index, KEY_COUNT);
        }
        draw_key_select(game, index);
    }
    if (selected == -1)
        return;
    get_key_bind(game, index);
    select_key(game);
}
