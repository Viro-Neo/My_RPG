/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to acquire use and equip items
*/

#include "my.h"
#include "player_handling.h"
#include "useful_csfml.h"
#include "item.h"

int acquire_item(item_t *item, player_t *player)
{
    int i = 0;

    if (item == NULL)
        return 0;
    while (i < MAX_SLOTS && player->inventory[i] != NULL)
        i += 1;
    if (i == MAX_SLOTS)
        return 0;
    player->inventory[i] = item;
    return 1;
}

void consume_item(player_t *player, int index)
{
    player_heal_damage(player, player->inventory[index]->stats->hp);
    player_recover_mana(player, player->inventory[index]->stats->mana);
    player->inventory[index] = NULL;
}

int can_use_item(player_t *player, int index)
{
    if (player->inventory[index]->type == KEY_ITEM) {
        return 0;
    }
    if (player->stat->actions < 2) {
        return 0;
    }
    return 1;
}

int use_item(player_t *player, int index)
{
    if (player->inventory[index] == NULL)
        return 0;
    if (can_use_item(player, index) == 0)
        return 0;
    if (player->inventory[index]->type == LEFT_EQUIP ||
            player->inventory[index]->type == RIGHT_EQUIP ||
            player->inventory[index]->type == ARMOR_EQUIP ||
            player->inventory[index]->type == TRINKET_EQUIP) {
        equip_item(player, index);
        return 1;
    }
    if (player->inventory[index]->type == CONSUMABLE) {
        consume_item(player, index);
        player->stat->actions -= 2;
        return 1;
    }
    return 0;
}

int is_item_in_inventory(player_t *player, char *name)
{
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (player->inventory[i] == NULL)
            continue;
        if (my_strcmp(player->inventory[i]->name, name) == 0)
            return 1;
    }
    return 0;
}
