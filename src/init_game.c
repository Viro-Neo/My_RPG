/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** init game
*/

#include "my.h"
#include "m_rpg.h"
#include "map.h"
#include "stdlib.h"
#include "player_handling.h"
#include "game.h"
#include "item.h"
#include "useful_csfml.h"

void player_start(player_t *player, item_t **items)
{
    int i = 0;
    int index;

    while (items[i] != NULL)
        i += 1;
    index = rand() % i;
    while (items[index] != NULL && items[index]->type < 2)
        index = rand() % i;
    if (items[index] != NULL) {
        items[index]->stats->level = 1;
        acquire_item(items[index], player);
        shift_items(items, index);
    }
}

void set_default_options(game_t *game)
{
    option_t *options = game->options;

    options->keys[KEY_ACT] = sfKeyS;
    options->keys[KEY_CONFIRM] = sfKeyReturn;
    options->keys[KEY_UP] = sfKeyUp;
    options->keys[KEY_RIGHT] = sfKeyRight;
    options->keys[KEY_DOWN] = sfKeyDown;
    options->keys[KEY_LEFT] = sfKeyLeft;
    options->keys[KEY_INTERACT] = sfKeyReturn;
    options->keys[KEY_MENU_LEFT] = sfKeyLeft;
    options->keys[KEY_MENU_RIGHT] = sfKeyRight;
    options->keys[KEY_MENU_UP] = sfKeyUp;
    options->keys[KEY_MENU_DOWN] = sfKeyDown;
    options->keys[KEY_BACK] = sfKeyBack;
    options->keys[KEY_PAUSE] = sfKeyEscape;
    game->volume = 50;
}

game_t *init_game(int size)
{
    game_t *game = malloc(sizeof(game_t) * 1);

    game->options = malloc(sizeof(option_t));
    set_default_options(game);
    game->level_items = make_item_arr("assets/items/level1/");
    game->spells = make_spell_arr();
    game->level = 1;
    game->map = generate_map(size, game->level_items, game);
    game->tiles_array = init_tiles(game);
    game->window = create_window(1920, 1080);
    game->player = init_player();
    player_start(game->player, game->level_items);
    game->current_room = 0;
    game->size = size;
    return game;
}

void free_game(game_t *game)
{
    if (game->map != NULL)
        free_map(game->map);
    if (game->level_items != NULL)
        free_items(game->level_items, game);
    if (game->player != NULL)
        free_player(game->player);
    if (game->tiles_array != NULL)
        free_tiles(game->tiles_array);
    if (game->window != NULL)
        sfRenderWindow_destroy(game->window);
    if (game->quests != NULL)
        return;
}
