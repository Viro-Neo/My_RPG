/*
** EPITECH PROJECT, 2022
** player_event.c
** File description:
** player event
*/

#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include "game.h"
#include "pause_menu.h"

int player_event(game_t *game, sfEvent *event)
{
    option_t *options = game->options;

    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == options->keys[KEY_LEFT])
            move_player(game, -1, 0);
        if (event->key.code == options->keys[KEY_UP])
            move_player(game, 0, -1);
        if (event->key.code == options->keys[KEY_RIGHT])
            move_player(game, 1, 0);
        if (event->key.code == options->keys[KEY_DOWN])
            move_player(game, 0, 1);
        if (event->key.code == options->keys[KEY_ACT])
            select_combat_option(game, game->player);
        if (event->key.code == options->keys[KEY_PAUSE])
            pause_menu(game);
        if (event->key.code == sfKeyK)
            select_key(game);
        if (event->key.code == options->keys[KEY_CONFIRM] &&
            game->map[game->current_room]->type == NPC_ROOM)
            interact(game->map[game->current_room]->npc, game);
    }
    return 0;
}
