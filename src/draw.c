/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw everything each loop
*/

#include "game.h"
#include "m_rpg.h"
#include "player_handling.h"
#include "main_menu.h"
#include "map.h"
#include "useful_csfml.h"

void flip_sprites(enemy_t *enemy)
{
    for (int i = 0; i < enemy->sprite_x; i++)
        for (int j = 0; j < enemy->sprite_y; j++) {
            sfSprite_scale(enemy->sprites[i][j], create_sfvector(-1, 1));
        }
}

void set_enemy_sprite_pos(enemy_t *enemy)
{
    sfSprite *sprite = enemy->sprites[enemy->vect.x][enemy->vect.y];
    sfVector2f pos =
            create_sfvector(enemy->x * 64 + 64 * (enemy->dir != -1),
                         enemy->y * 64);

    sfSprite_setPosition(sprite, pos);
}

void draw_enemy(sfRenderWindow *window, room_t *room, game_t *game)
{
    enemy_t **enemies = room->enemy;
    for (int i = 0; enemies[i] != NULL; i++) {
        set_enemy_sprite_pos(enemies[i]);
        sfRenderWindow_drawSprite(window,
            enemies[i]->sprites[enemies[i]->vect.x][enemies[i]->vect.y],
            NULL);
        if (enemies[i]->x < game->player->x && enemies[i]->dir == -1) {
            flip_sprites(enemies[i]);
            enemies[i]->dir = 1;
        }
        if (enemies[i]->x >= game->player->x && enemies[i]->dir == 1) {
            flip_sprites(enemies[i]);
            enemies[i]->dir = -1;
        }
    }
}

void draw(game_t *game)
{
    player_t *player = game->player;
    sfSprite ***sprites = game->player->sprites;

    draw_room(game->window, game->tiles_array, game->map[game->current_room]);
    sfRenderWindow_drawSprite(game->window,
                              sprites[player->vect.x][player->vect.y], NULL);
    if (game->map[game->current_room]->type == ENEMY_ROOM ||
        game->map[game->current_room]->type == BOSS_ROOM) {
        draw_enemy(game->window, game->map[game->current_room], game);
    }
    combat_overlay(game, game->window);
    display_status(game->player, game->window);
}
