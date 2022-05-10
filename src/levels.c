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
#include "main_menu.h"
#include "main_menu_fct.h"

char *get_level_path(int level, char *pre, char *post)
{
    char *post_path;
    char *full_path;

    post_path = my_strcat(my_itoa(level), post);
    full_path = my_strcat(pre, post_path);
    free(post_path);
    return full_path;
}

void remove_key(player_t *player)
{
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (player->inventory[i] == NULL)
            continue;
        if (my_strcmp(player->inventory[i]->name, "Boss Key") == 0) {
            player->inventory[i] = NULL;
            return;
        }
    }
}

void init_levels(game_t *game, int size)
{
    char *items_path = get_level_path(game->level, "assets/items/level", "/");
    game->level_items = make_item_arr(items_path);

    free(items_path);
    game->map = generate_map(size, game->level_items, game);
    game->tiles_array = init_tiles(game);
    game->current_room = 0;
    game->size = size;
}

void free_level(game_t *game)
{
    if (game->map != NULL)
        free_map(game->map);
    if (game->level_items != NULL)
        free_items(game->level_items, game);
    if (game->tiles_array != NULL)
        free_tiles(game->tiles_array);
    if (game->quests != NULL)
        return;
}

void change_levels(game_t *game)
{
    if (game->level == 2)
        main_menu(game);
    free_level(game);
    game->level += 1;
    game->player->x = 14;
    game->player->y = 7;
    init_levels(game, game->size);
    remove_key(game->player);
    stop_music(game->music);
    game->music = play_music("assets/musics/in_game/leve_2_music.ogg",
                             game->volume);
}
