/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to handle player level
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "player_handling.h"
#include "game.h"

void shift_spells(spell_t **spells, int index)
{
    int i = 0;

    while (spells[i] != NULL) {
        if (i >= index)
            spells[i] = spells[i + 1];
        i += 1;
    }
}

void player_learn_spell(player_t *player, spell_t *spell, game_t *game)
{
    int i = 0;
    char *text;

    while (player->spells[i] != NULL && i < SPELL_COUNT) {
        i += 1;
    }
    if (i == SPELL_COUNT) {
        return;
    }
    text = my_strcat("Learned spell ", spell->name);
    display_popup(game, text);
    free(text);
    player->spells[i] = spell;
}

void player_level_up(player_t *player, spell_t **spells, game_t *game)
{
    int i = 0;

    player->stat->level += 1;
    player->xp = 0;
    display_popup(game, "leveled up, please select stats to increase\n");
    select_stat_increase(game, player, 5);
    while (spells[i] != NULL) {
        if (player->stat->level == spells[i]->stats->level) {
            player_learn_spell(player, spells[i], game);
            shift_spells(spells, i);
            continue;
        }
        i += 1;
    }
}

void player_gain_xp(player_t *player, int xp, game_t *game)
{
    int xp_needed = 0;

    xp_needed =  48 + 8 * (player->stat->level - 1);
    if (xp >= xp_needed) {
        player_level_up(player, game->spells, game);
        player_gain_xp(player, xp - xp_needed, game);
    }
    else
        player->xp += xp;
}
