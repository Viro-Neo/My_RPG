/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** contains functions used to display combat overlay
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "useful_csfml.h"
#include "game.h"
#include "item.h"

int determine_max_value(stat_t *stats, int stat)
{
    if (stat == 0)
        return stats->max_hp;
    if (stat == 1)
        return stats->max_mana;
    if (stat == 2)
        return 9999;
    if (stat == 3)
        return 5;
    return -1;
}

int determine_value(stat_t *stats, int stat)
{
    if (stat == 0)
        return stats->hp;
    if (stat == 1)
        return stats->mana;
    if (stat == 2)
        return stats->money;
    if (stat == 3)
        return stats->actions;
    return -1;
}

void write_ol_stat(stat_t *stats, sfRenderWindow *win, int stat, sfVector2f pos)
{
    int value = determine_value(stats, stat);
    int max_value = determine_max_value(stats, stat);
    int text_siz = 1 + my_strlen(my_itoa(value)) + my_strlen(my_itoa(max_value));
    char *text = malloc(sizeof(char) * (text_siz + 1));

    text[0] = '\0';
    m_strcat(text, my_itoa(value));
    m_strcat(text, "/");
    m_strcat(text, my_itoa(max_value));
    write_stat(text, win, pos);
    free(text);
}

void write_ol_stats(game_t *game)
{
    sfRenderWindow *window = game->window;
    player_t *player = game->player;
    room_t *curr_room = game->map[game->current_room];

    write_ol_stat(player->stat, window, 0, create_sfvector(1616, 69));
    write_ol_stat(player->stat, window, 1, create_sfvector(1616, 104));
    if (curr_room->type == ENEMY_ROOM)
        write_ol_stat(player->stat, window, 3,
                      create_sfvector(1616, 139));
    else
        write_ol_stat(player->stat, window, 2, create_sfvector(1616, 139));
}

void combat_overlay(game_t *game, sfRenderWindow *window)
{
    sfTexture *texture;
    sfSprite *sprite = sfSprite_create();
    char *sprite_path;

    if (game->map[game->current_room]->type == ENEMY_ROOM ||
            game->map[game->current_room]->type == BOSS_ROOM)
        sprite_path = "assets/inventory/status_overlay2-1.png.png";
    else
        sprite_path = "assets/inventory/status_overlay1-1.png.png";
    texture = sfTexture_createFromFile(sprite_path, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, create_sfvector(1556, 64));
    sfRenderWindow_drawSprite(window, sprite, NULL);
    write_ol_stats(game);
    sfSprite_destroy(sprite);
}
