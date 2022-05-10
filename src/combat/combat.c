/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** contains functions used for combat
*/

#include <stdlib.h>
#include "useful_csfml.h"
#include "status_condition.h"
#include "game.h"
#include "player_handling.h"
#include "entity.h"
#include "map.h"
#include "my.h"
#include "main_menu.h"

int are_enemies(enemy_t **enemies)
{
    int i = 0;

    if (enemies == NULL)
        return 0;
    while (enemies[i] != NULL)
        i += 1;
    return i;
}

void player_turn(game_t *game)
{
    sfRenderWindow *window = game->window;
    int i = 0;

    if (sfRenderWindow_pollEvent(window, game->event) && i <= 2) {
        if (game->event->type == sfEvtClosed)
            sfRenderWindow_close(window);
        player_event(game, game->event);
        change_room(game);
        i++;
    } else {
        animate_enemies(game);
        idle_animation(game->player);
    }
    while (sfRenderWindow_pollEvent(window, game->event)) {}
}

void enemy_turn(game_t *game)
{
    int i = 0;
    player_t *player = game->player;
    room_t *room = game->map[game->current_room];
    enemy_t **enemies = room->enemy;

    display_popup(game, "enemy turn\n");
    while (enemies[i] != NULL) {
        while (enemies[i]->stats->actions > 0) {
            enemy_decision_tree(enemies[i], room, player, game);
            enemies[i]->stats->actions -= 1;
            sfRenderWindow_clear(game->window, sfBlack);
            draw(game);
            sfRenderWindow_display(game->window);
        }
        enemies[i]->stats->actions = enemies[i]->stats->max_actions;
        i += 1;
    }
}

void combat(game_t *game)
{
    player_t *player = game->player;
    room_t *room = game->map[game->current_room];
    enemy_t **enemies = room->enemy;

    while (player->stat->actions > 0 && are_enemies(enemies) &&
            sfRenderWindow_isOpen(game->window) != 0 &&
            player->stat->hp > 0) {
        sfRenderWindow_clear(game->window, sfBlack);
        draw(game);
        sfRenderWindow_display(game->window);
        player_turn(game);
    }
    enemy_turn(game);
    end_of_turn(game);
}

void enage_combat(game_t *game)
{
    room_t *room = game->map[game->current_room];

    game->player->stat->actions = 5;
    while (are_enemies(room->enemy) &&
    sfRenderWindow_isOpen(game->window) != 0
    && game->player->stat->hp > 0)
        combat(game);
    if (game->player->stat->hp == 0)
        return;
    if (room->type == ENEMY_ROOM) {
        clear_status(game->player);
        game->map[game->current_room]->type = CLEARED_ROOM;
        get_reward(game);
    }
    if (room->type == BOSS_ROOM) {
        clear_status(game->player);
        spawn_exit(game);
        game->map[game->current_room]->type = CLEARED_ROOM;
    }
}
