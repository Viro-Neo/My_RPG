/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** contains functions used to move player
*/

#include "player_handling.h"
#include "map.h"
#include "useful_csfml.h"
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/BlendMode.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

static int is_colision_enemy(enemy_t **enemy, int x, int y)
{
    if (enemy == NULL)
        return 1;
    for (int i = 0; enemy[i] != NULL; i++)
        if (enemy[i]->x == x && enemy[i]->y == y)
            return 0;
    return 1;
}

static int is_colision(room_t *room, int x, int y)
{
    if (room->npc != NULL)
        if (room->npc->x == x && room->npc->y == y)
            return 0;
    if (room->enemy != NULL)
        if (is_colision_enemy(room->enemy, x, y) == 0)
            return 0;
    return 1;
}

static int is_valid_pos(room_t *room, int x, int y, player_t *player)
{
    char **layout = room->layout;

    if (layout[y][x]) {
        if (layout[y][x] == 'd' && is_item_in_inventory(player, "Boss Key")) {
            layout[y][x] = 'e';
            return 0;
        }
        if (layout[y][x] == 'e' && room->type == ENEMY_ROOM)
            return 0;
        if (layout[y][x] != 'x' && layout[y][x] != 'o' && layout[y][x] != 'd')
            return 1;
    }
    return 0;
}

static void animation_player_move(int x, int y, player_t *player, game_t *game)
{
    if (x == 1)
        right_animation(player, game);
    if (y == -1)
        top_animation(player, game);
    if (x == -1)
        left_animation(player, game);
    if (y == 1)
        bottom_animation(player, game);
}

void move_player(game_t *game, int x, int y)
{
    player_t *player = game->player;
    room_t *room = game->map[game->current_room];
    int pos_x = player->x;
    int pos_y = player->y;

    if (is_aflicted(player, FREEZE) >= 0) {
        player->stat->actions -= 1;
        return;
    }
    if (is_valid_pos(room, pos_x + x, pos_y + y, player) &&
        is_colision(room, pos_x + x, pos_y + y)) {
        player->x += x;
        player->y += y;
        animation_player_move(x, y, player, game);
    }
    player->stat->actions -= 1;
}
