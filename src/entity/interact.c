/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to initialize npcs
*/

#include <stdio.h>
#include <stdlib.h>
#include "useful_csfml.h"
#include "m_rpg.h"
#include "entity.h"
#include "game.h"

static void npc_interaction(npc_t *npc, game_t *game)
{
    sfEvent *event = malloc(sizeof(sfEvent));

    while (event->key.code != sfKeyReturn || event->type != sfEvtKeyPressed) {
        sfRenderWindow_pollEvent(game->window, event);
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
            return;
        }
        sfRenderWindow_clear(game->window, sfBlack);
        draw(game);
        npc_talk(npc, game->window);
        sfRenderWindow_display(game->window);
    }
    free(event);
}

void start_quest(npc_t *npc, game_t *game)
{
    int id = npc->quest_id;

    if (game->quests[id]->status == 0)
        game->quests[id]->status = 1;
}

int verif_interaction(npc_t *npc, player_t *player)
{
    if (player->x == npc->x + 1 && player->y == npc->y)
        return 1;
    if (player->x == npc->x - 1 && player->y == npc->y)
        return 1;
    if (player->x == npc->x && player->y == npc->y + 1)
        return 1;
    if (player->x == npc->x && player->y == npc->y - 1)
        return 1;
    return 0;
}

void interact(npc_t *npc, game_t *game)
{
    if (verif_interaction(npc, game->player) != 1)
        return;
    if (npc->type == IDLE_NPC)
        npc_interaction(npc, game);
    if (npc->type == SHOPKEEPER)
        select_shop_item(game, npc);
    if (npc->type == QUEST_NPC) {
        npc_interaction(npc, game);
//        start_quest(npc, game);
    }
}
