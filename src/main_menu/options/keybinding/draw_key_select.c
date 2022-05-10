/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw everything each loop
*/

#include <stdio.h>
#include <stdlib.h>
#include "useful_csfml.h"
#include "game.h"
#include "item.h"
#include "my.h"

sfVector2f get_key_bind_pos(int index, int limit)
{
    int x = 125 + ((index / limit) * 250);
    int y = 125 + ((index % limit) * 150);
    return create_sfvector(x, y);
}

char *get_key(int index)
{
    char *keys[sfKeyCount - 16] =
        {"a", "b", "c", "d", "e", "f", "g", "h",
        "i", "j", "k", "l", "m", "n", "o", "p",
        "q", "r", "s", "t", "u", "v", "w", "x",
        "y", "z", "0", "1", "2", "3", "4",
        "5", "6", "7", "8", "9", "Escape",
        "Lctrl", "Lshift", "Lalt", "Lsystem",
        "Rctrl", "Rshift", "Ralt", "Rsystem",
        "Menu", "[", "]", ";", ",", ".", "'", "/",
        "\\", "~", "=", "-", " ", "Return",
        "Backspace", "Tab", "PgUp", "PgDown",
        "End", "Home", "Insert", "Del", "+", "-",
        "*", "/", "Left", "Right", "Up", "Down",
        "n0", "n1", "n2", "n3", "n4", "n5", "n6",
        "n7", "n8", "n9"};

    return keys[index];
}

void write_key(char *key, sfRenderWindow *window, int selected, sfVector2f pos)
{
    sfText *txt = sfText_create();
    sfFont *arial = sfFont_createFromFile("assets/font/Amatic-Bold.ttf");

    sfText_setString(txt, key);
    sfText_setFont(txt, arial);
    if (selected == 1)
        sfText_setColor(txt, sfYellow);
    else
        sfText_setColor(txt, sfWhite);
    sfText_setPosition(txt, pos);
    sfRenderWindow_drawText(window, txt, NULL);
    sfText_destroy(txt);
    sfFont_destroy(arial);
}

void key_bind_menu(game_t *game, int index)
{
    sfRenderWindow *window = game->window;
    char **keys = malloc(sizeof(char *) * (KEY_COUNT + 1));
    char *tmp_key_value;
    char *key_type[KEY_COUNT] =
        {"Confirm   ", "Act   ", "Pause   ", "Move left   ",
        "Move up   ", "Move right   ", "Move down   ", "Interact   ",
        "Menu left   ", "Menu up   ", "Menu right   ",
        "Menu down   ", "Back   "};

    for (int i = 0; i < KEY_COUNT; i++) {
        tmp_key_value = get_key(game->options->keys[i]);
        keys[i] = my_strcat(key_type[i], tmp_key_value);
        write_key(keys[i], window, i == index, get_key_bind_pos(i, 5));
    }
    for (int i = 0; i < KEY_COUNT; i++)
        free(keys[i]);
    free(keys);
}

void draw_key_select(game_t *game, int index)
{
    sfRenderWindow_clear(game->window, sfBlack);
    key_bind_menu(game, index);
    sfRenderWindow_display(game->window);
}
