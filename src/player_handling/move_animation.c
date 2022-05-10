/*
** EPITECH PROJECT, 2022
** idle
** File description:
** idle
*/

#include "player_handling.h"
#include "useful_csfml.h"

void reset_sprites(player_t *player, sfVector2f former, int i, game_t *game)
{
    player->vect.y++;
    if (player->vect.y >= 8)
        player->vect.y = 0;
    sfSprite_setPosition(player->sprites[i][player->vect.y], former);
    draw(game);
    sfRenderWindow_display(game->window);
}

void right_animation(player_t *player, game_t *game)
{
    sfVector2f vect = create_sfvector(player->x * 64 - 32, player->y * 64 - 32);
    sfVector2f former = create_sfvector((player->x - 1) * 64 - 32, vect.y);
    float seconds = 0;

    player->vect.x = 1;
    sfClock_restart(player->clock);
    while (former.x < vect.x) {
        seconds = get_seconds(player->clock);
        if (seconds > 0.2 / 8) {
            former.x += 8;
            reset_sprites(player, former, 1, game);
            sfClock_restart(player->clock);
        }
    }
}

void top_animation(player_t *player, game_t *game)
{
    sfVector2f vect = create_sfvector(player->x * 64 - 32, player->y * 64 - 32);
    sfVector2f former = create_sfvector(vect.x, (player->y + 1) * 64 - 32);
    float seconds = 0;

    player->vect.x = 2;
    sfClock_restart(player->clock);
    while (former.y > vect.y) {
        seconds = get_seconds(player->clock);
        if (seconds > 0.2 / 8) {
            former.y -= 8;
            reset_sprites(player, former, 2, game);
            sfClock_restart(player->clock);
        }
    }
}

void left_animation(player_t *player, game_t *game)
{
    sfVector2f vect = create_sfvector(player->x * 64 - 32, player->y * 64 - 32);
    sfVector2f former = create_sfvector((player->x + 1) * 64 - 32, vect.y);
    float seconds = 0;

    player->vect.x = 3;
    sfClock_restart(player->clock);
    while (former.x > vect.x) {
        seconds = get_seconds(player->clock);
        if (seconds > 0.2 / 8) {
            former.x -= 8;
            reset_sprites(player, former, 3, game);
            sfClock_restart(player->clock);
        }
    }
}

void bottom_animation(player_t *player, game_t *game)
{
    sfVector2f vect = create_sfvector(player->x * 64 - 32, player->y * 64 - 32);
    sfVector2f former = create_sfvector(vect.x, (player->y - 1) * 64 - 32);
    float seconds = 0;

    player->vect.x = 4;
    sfClock_restart(player->clock);
    while (former.y < vect.y) {
        seconds = get_seconds(player->clock);
        if (seconds > 0.2 / 8) {
            former.y += 8;
            reset_sprites(player, former, 4, game);
            sfClock_restart(player->clock);
        }
    }
}
