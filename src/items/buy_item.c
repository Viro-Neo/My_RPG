/*
** EPITECH PROJECT, 2022
** create_sprite
** File description:
** functions used to buy items
*/

#include <stdlib.h>
#include "my.h"
#include "player_handling.h"
#include "item.h"
#include "entity.h"
#include "game.h"

void buy_item(game_t *game, npc_t *shopkeep, int index)
{
    item_t **items = shopkeep->shop;
    player_t *player = game->player;

    if (items[index] == NULL)
        return;
    int cost = items[index]->stats->money;
    if (player->stat->money >= cost) {
        if (acquire_item(items[index], player) == 0)
            return;
        player_spend_money(player, cost);
        shopkeep->shop[index] = NULL;
    } else
        display_popup(game, "You do not have enough money for this item");
}