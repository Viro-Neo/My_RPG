/*
** EPITECH PROJECT, 2022
** idle_animation
** File description:
** idle_animation
*/

#include <stdio.h>
#include "game.h"
#include "useful_csfml.h"
#include "entity.h"

void enemy_idle(enemy_t *enemy)
{
    sfVector2f vect = create_sfvector(enemy->x * 64 - 32, enemy->y * 64 - 32);
    float seconds = get_seconds(enemy->clock);

    if (seconds > 0.8 / enemy->sprite_y) {
        enemy->vect.y++;
        if (enemy->vect.y >= enemy->sprite_y) {
            enemy->vect.y = 0;
            enemy->vect.x = 0;
            sfClock_restart(enemy->clock);
        }
        sfClock_restart(enemy->clock);
    }
    sfSprite_setPosition(enemy->sprites[enemy->vect.x][enemy->vect.y], vect);
}

void animate_enemies(game_t *game)
{
    int i = 0;
    room_t *room = game->map[game->current_room];

    if (room->type != ENEMY_ROOM)
        return;
    while (room->enemy[i] != NULL) {
        enemy_idle(room->enemy[i]);
        i += 1;
    }
    return;
}

void reset_sprites_en(enemy_t *enemy)
{
    if (enemy->vect.y >= enemy->sprite_y)
        enemy->vect.y = 0;
}

void en_death_animation(enemy_t *enemy, game_t *game)
{
    sfVector2f vect = create_sfvector(enemy->x * 64 - 32, enemy->y * 64 - 32);
    sfVector2f former = create_sfvector((enemy->x - 1) * 64 - 32, vect.y);
    float seconds = 0;

    sfClock_restart(enemy->clock);
    enemy->vect.y = 0;
    enemy->vect.x = 2;
    while (enemy->vect.y < enemy->sprite_y - 1) {
        seconds = get_seconds(enemy->clock);
        if (seconds > 0.8 / enemy->sprite_y) {
            former.x += 8;
            enemy->vect.y++;
            sfSprite_setPosition(enemy->sprites[1][enemy->vect.y], former);
            draw(game);
            sfRenderWindow_display(game->window);
            sfClock_restart(enemy->clock);
        }
    }
}
