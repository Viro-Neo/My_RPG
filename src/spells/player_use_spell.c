/*
** EPITECH PROJECT, 2021
** my_rpg
** functions used to use spells
*/

#include <stdio.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include "player_handling.h"
#include "game.h"
#include "item.h"
#include "entity.h"
#include "my.h"

int spell_is_usable(game_t *game, player_t *player, spell_t *spell)
{
    int type = spell->type;
    int cost = spell->stats->mana;

    if ((type == SELF_SPELL || type == ATK_SPELL)
        && player->equipment[0] == NULL) {
            display_popup(game, "You do not have a wand or staff equipped\n");
            return 0;
    }
    if (player->stat->wis < spell->stats->wis ||
    player->stat->str < spell->stats->str ||
    player->stat->dex < spell->stats->dex) {
        display_popup(game, "You need higher stats to use this spell\n");
        return 0;
    }
    if (player->stat->mana < cost) {
        display_popup(game, "Need more mana\n");
        return 0;
    }
    return 1;
}

int get_spell_bonus(player_t *player, spell_t *spell)
{
    int type = spell->type;
    int bonus = 0;

    if (spell->stats->hp == 0 && type == SELF_SPELL)
        return 0;
    if (spell->damage == 0 && type == ATK_SPELL)
        return 0;
    bonus += (player->stat->wis - spell->stats->wis) / 2;
    if (type == SELF_SPELL)
        return spell->stats->hp + bonus;
    if (type == ATK_SPELL)
        return spell->damage + bonus;
    return 0;
}

void player_use_self_spell(player_t *player, int index, game_t *game)
{
    spell_t *spell = player->spells[index];
    int heal = get_spell_bonus(player, spell);
    status_t *status = player->spells[index]->status;

    heal += spell->stats->hp;
    player_heal_damage(player, heal);
    if (is_aflicted(player, status->type) == 1)
        return;
    apply_status_condition(game, status, player);
}

void player_use_spell(player_t *player, game_t *game, int index)
{
    int type;

    if (player->spells[index] == NULL)
        return;
    type = player->spells[index]->type;
    if (spell_is_usable(game, player, player->spells[index]) == 0)
        return;
    if (player->spells[index]->stats->actions > player->stat->actions) {
        display_popup(game, "This spell requires more actions");
        return;
    }
    if (type == SELF_SPELL)
        player_use_self_spell(player, index, game);
    if (type == ATK_SPELL) {
        player_use_atk_spell(player, game, index);
    }
    player_use_mana(player, player->spells[index]->stats->mana);
    player->stat->actions -= player->spells[index]->stats->actions;
}
