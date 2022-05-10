/*
** EPITECH PROJECT, 2021
** my_rpg
** functions used for targeting
*/

#include <stdlib.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include "my.h"
#include "game.h"
#include "player_handling.h"
#include "item.h"

int is_valid_target(game_t *game, int pos[2], spell_t *spell)
{
    int i = 0;
    int range = spell->range;
    enemy_t **enemies = game->map[game->current_room]->enemy;
    int x = game->player->x + pos[0];
    int y = game->player->y + pos[1];

    if (pos[0] > range || pos[0] < range * (-1)
    || pos[1] > range || pos[1] < range * (-1)) {
        display_popup(game, "your target is out of spell range\n");
        return 0;
    }
    while (enemies[i] != NULL) {
        if (enemies[i]->x == x && enemies[i]->y == y)
            return i;
        i += 1;
    }
    display_popup(game, "your target is not an enemy\n");
    return 0;
}

int targeting_event(game_t *game, int pos[2], spell_t *spell)
{
    sfEvent *event = game->event;
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == game->options->keys[KEY_LEFT])
            pos[0] -= 1;
        if (event->key.code == game->options->keys[KEY_UP])
            pos[1] -= 1;
        if (event->key.code == game->options->keys[KEY_RIGHT])
            pos[0] += 1;
        if (event->key.code == game->options->keys[KEY_DOWN])
            pos[1] += 1;
        if (event->key.code == game->options->keys[KEY_BACK])
            return -1;
        if (event->key.code == game->options->keys[KEY_CONFIRM])
            return is_valid_target(game, pos, spell);
    }
    return 0;
}
