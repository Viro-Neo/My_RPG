/*
** EPITECH PROJECT, 2021
** my_rpg
** functions used for attack spells
*/

#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include "game.h"
#include "player_handling.h"
#include "item.h"
#include "useful_csfml.h"
#include <stdio.h>

void update_target(game_t *game, sfRectangleShape *rect, int *pos)
{
    player_t *player = game->player;

    sfRectangleShape_setPosition(rect,
                                 create_sfvector((player->x + pos[0]) * 64,
                                                 (player->y + pos[1]) * 64));
    sfRenderWindow_clear(game->window, sfBlack);
    draw(game);
    draw_target(rect, game);
    sfRenderWindow_display(game->window);
}

int get_spell_target(player_t *player, game_t *game, spell_t *spell)
{
    int pos[2];
    int target = 0;

    pos[0] = 0;
    pos[1] = 0;
    if (is_aflicted(player, BLIND) >= 0) {
        display_popup(game, "Cannot use spell due to blind effect");
        return -1;
    }
    sfRectangleShape *rect = init_rectangle
            (create_sfvector(player->x, player->y), 64);
    while (target == 0) {
        if (sfRenderWindow_pollEvent(game->window, game->event)) {
            check_window_closed(game);
            target = targeting_event(game, pos, spell);
        }
        update_target(game, rect, pos);
    }
    sfRectangleShape_destroy(rect);
    return target;
}

void player_use_atk_spell(player_t *player, game_t *game, int index)
{
    spell_t *spell = player->spells[index];
    int en_index = get_spell_target(player, game, spell);
    enemy_t *target;
    int damage = get_spell_bonus(player, spell);

    if (en_index == -1)
        return;
    target = game->map[game->current_room]->enemy[en_index];
    damage -= target->stats->ac;
    apply_spell_effect(game, spell, en_index, damage);
    enemy_take_damage(game, damage, en_index);
}