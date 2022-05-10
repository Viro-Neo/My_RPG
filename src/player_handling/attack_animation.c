/*
** EPITECH PROJECT, 2022
** attack_animation
** File description:
** attack_animation
*/

#include "game.h"
#include "useful_csfml.h"

void right_attack(player_t *player, game_t *game)
{
    sfRenderWindow *window = game->window;
    sfSprite ***sprites = player->sprites;
    sfVector2f vect = create_sfvector(player->x * 64 - 32, player->y * 64 - 32);
    float seconds = 0;

    sfClock_restart(player->clock);
    while (player->vect.y < 5) {
        seconds = get_seconds(player->clock);
        if (seconds > 0.2 / 8) {
            player->vect.y++;
            sfSprite_setPosition(player->sprites[6][player->vect.y], vect);
            sfRenderWindow_drawSprite(window, sprites[6][player->vect.y], NULL);
            sfRenderWindow_display(window);
            sfClock_restart(player->clock);
        }
    }
}

void top_attack(player_t *player, game_t *game)
{
    sfRenderWindow *window = game->window;
    sfSprite ***sprites = player->sprites;
    sfVector2f vect = create_sfvector(player->x * 64 - 32, player->y * 64 - 32);
    float seconds = 0;

    sfClock_restart(player->clock);
    while (player->vect.y < 5) {
        seconds = get_seconds(player->clock);
        if (seconds > 0.2 / 8) {
            player->vect.y++;
            sfSprite_setPosition(player->sprites[7][player->vect.y], vect);
            sfRenderWindow_drawSprite(window, sprites[7][player->vect.y], NULL);
            sfRenderWindow_display(window);
            sfClock_restart(player->clock);
        }
    }
}

void left_attack(player_t *player, game_t *game)
{
    sfRenderWindow *window = game->window;
    sfSprite ***sprites = player->sprites;
    sfVector2f vect = create_sfvector(player->x * 64 - 32, player->y * 64 - 32);
    float seconds = 0;

    sfClock_restart(player->clock);
    while (player->vect.y < 5) {
        seconds = get_seconds(player->clock);
        if (seconds > 0.2 / 8) {
            player->vect.y++;
            sfSprite_setPosition(player->sprites[8][player->vect.y], vect);
            sfRenderWindow_drawSprite(window, sprites[8][player->vect.y], NULL);
            sfRenderWindow_display(window);
            sfClock_restart(player->clock);
        }
    }
}

void bottom_attack(player_t *player, game_t *game)
{
    sfRenderWindow *window = game->window;
    sfSprite ***sprites = player->sprites;
    sfVector2f vect = create_sfvector(player->x * 64 - 32, player->y * 64 - 32);
    float seconds = 0;

    sfClock_restart(player->clock);
    while (player->vect.y < 5) {
        seconds = get_seconds(player->clock);
        if (seconds > 0.2 / 8) {
            player->vect.y++;
            sfSprite_setPosition(player->sprites[9][player->vect.y], vect);
            sfRenderWindow_drawSprite(window, sprites[9][player->vect.y], NULL);
            sfRenderWindow_display(window);
            sfClock_restart(player->clock);
        }
    }
}

void animation_attack(player_t *player, game_t *game, int index)
{
    enemy_t *enemy = game->map[game->current_room]->enemy[index];

    if (enemy == NULL)
        return;
    if (player->y - enemy->y == 1 && enemy->x == player->x)
        top_attack(player, game);
    if (player->y - enemy->y == -1 && enemy->x == player->x)
        bottom_attack(player, game);
    if (player->x - enemy->x == 1 && enemy->y == player->y)
        right_attack(player, game);
    if (player->x - enemy->x == -1 && enemy->y == player->y)
        left_attack(player, game);
}
