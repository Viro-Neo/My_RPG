/*
** EPITECH PROJECT, 2022
** change_room.c
** File description:
** change_room
*/

#include "game.h"
#include "useful_csfml.h"
#include "my.h"

static void change_room_position(game_t *game)
{
    player_t *player = game->player;

    if (player->x == 0) {
        game->current_room -= 1;
        player->x = 28;
    }
    if (player->y == 0) {
        game->current_room -= game->size;
        player->y = 13;
    }
    if (player->x == 29) {
        game->current_room += 1;
        player->x = 1;
    }
    if (player->y == 14) {
        game->current_room += game->size;
        player->y = 1;
    }
}

void through_door(room_t *current, game_t *game, player_t *player)
{
    if (current->layout[player->y][player->x] == 'e') {
        if (player->x == 0) {
            game->current_room -= 1;
            player->x = 28;
        }
        if (player->y == 0) {
            game->current_room -= game->size;
            player->y = 13;
        }
        if (player->x == 29) {
            game->current_room += 1;
            player->x = 1;
        }
        if (player->y == 14) {
            game->current_room += game->size;
            player->y = 1;
        }
    }
}

void spawn_exit(game_t *game)
{
    room_t *room = game->map[game->current_room];

    room->layout[7][14] = 'w';
}

void change_room(game_t *game)
{
    player_t *player = game->player;
    room_t *current = game->map[game->current_room];
    sfVector2f vect =
            create_sfvector(player->x * 64 - 32, player->y * 64 - 32);

    if (current->layout[player->y][player->x] == 'e') {
        change_room_position(game);
        if (game->map[game->current_room]->type == ENEMY_ROOM)
            enage_combat(game);
        if (game->map[game->current_room]->type == BOSS_ROOM)
            enage_combat(game);
    }
    if (game->player->stat->hp == 0)
        return;
    if (current->layout[player->y][player->x] == 'w') {
        change_levels(game);
        return;
    }
    through_door(current, game, player);
    sfSprite_setPosition(player->sprites[player->vect.x][player->vect.y],
                         vect);
}
