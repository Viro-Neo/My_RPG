/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to handle equipment
*/

#include "player_handling.h"
#include "item.h"

void gain_equip_stats(player_t *player, item_t *item)
{
    player->stat->max_hp += item->stats->max_hp;
    player->stat->max_mana += item->stats->max_mana;
    player->stat->str += item->stats->str;
    player->stat->wis += item->stats->wis;
    player->stat->dex += item->stats->dex;
    player->stat->ac += item->stats->ac;
}

void lose_equip_stats(player_t *player, item_t *item)
{
    player->stat->max_hp -= item->stats->max_hp;
    if (player->stat->hp > player->stat->max_hp)
        player->stat->hp = player->stat->max_hp;
    player->stat->max_mana -= item->stats->max_mana;
    player->stat->str -= item->stats->str;
    player->stat->wis -= item->stats->wis;
    player->stat->dex -= item->stats->dex;
    player->stat->ac -= item->stats->ac;
}

void unequip_item(player_t *player, int index)
{
    if (player->equipment[index] == NULL)
        return;
    lose_equip_stats(player, player->equipment[index]);
    acquire_item(player->equipment[index], player);
    player->equipment[index] = NULL;
}

int item_is_equipable(item_t *item, player_t *player)
{
    if (player->stat->level < item->stats->level)
        return 0;
    return 1;
}

int equip_item(player_t *player, int index)
{
    int type = player->inventory[index]->type;

    if (player->equipment[type - 2] == NULL) {
        if (item_is_equipable(player->inventory[index], player)) {
            player->equipment[type - 2] = player->inventory[index];
            gain_equip_stats(player, player->inventory[index]);
            player->inventory[index] = NULL;
            return 1;
        }
        return 0;
    } else {
        // maybe a popup here
        return 0;
    }
}
