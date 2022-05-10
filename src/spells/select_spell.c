/*
** EPITECH PROJECT, 2021
** my_rpg
** functions used to select spells
*/

#include "my.h"
#include "game.h"
#include "item.h"

int spell_select_event(game_t *game, int *index, int limit)
{
    sfEvent *event = game->event;

    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == game->options->keys[KEY_MENU_LEFT])
            adjust_index(index, -1, limit);
        if (event->key.code == game->options->keys[KEY_MENU_RIGHT])
            adjust_index(index, 1, limit);
        if (event->key.code == game->options->keys[KEY_MENU_UP])
            adjust_index(index, -2, limit);
        if (event->key.code == game->options->keys[KEY_MENU_DOWN])
            adjust_index(index, 2, limit);
        if (event->key.code == game->options->keys[KEY_CONFIRM])
            return 1;
        if (event->key.code == game->options->keys[KEY_BACK])
            return -1;
    }
    return 0;
}

void adjust_index(int *index, int offset, int limit)
{
    *index += offset;
    if (*index >= limit)
        *index = 0;
    if (*index < 0)
        *index = limit - 1;
}

int get_spell_count(player_t *player)
{
    int i = 0;

    while (player->spells[i] != NULL)
        i += 1;
    return i;
}

int can_cast_spell(game_t *game)
{
    if (game->map[game->current_room]->type != ENEMY_ROOM
        && game->map[game->current_room]->type != BOSS_ROOM) {
        display_popup(game, "cannot cast spell outside of enemy room\n");
        return 0;
    }
    return 1;
}

void select_spell(game_t *game, player_t *player)
{
    int index = 0;
    int selected = 0;
    int spell_count =  get_spell_count(player);

    while (selected == 0) {
        if (sfRenderWindow_pollEvent(game->window, game->event)) {
            check_window_closed(game);
            selected = spell_select_event(game, &index, spell_count);
        }
        draw_spell_select(game, index, spell_count);
    }
    if (selected == -1)
        return;
    if (can_cast_spell(game) == 0)
        return;
    player_use_spell(player, game, index);
}
