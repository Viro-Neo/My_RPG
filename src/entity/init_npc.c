/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** functions used to initialize npcs
*/

#include <stdlib.h>
#include "my.h"
#include "item.h"
#include "entity.h"
#include "useful_csfml.h"

npc_t *init_quest_npc(char *name, sfVector2f vect, int quest, char *path)
{
    npc_t *npc = malloc(sizeof(npc_t));

    npc->x = vect.x;
    npc->y = vect.y;
    npc->name = name;
    npc->type = QUEST_NPC;
    npc->quest_id = quest;
    npc->text = "this is a new quest, try an complet it\n";
    create_sprite_npc(npc, path);
    return npc;
}

npc_t *init_idle_npc(char *path)
{
    npc_t *npc = malloc(sizeof(npc_t));
    char *txt = get_item_stats(path);
    char **array = str_to_array(txt, '\n');
    sfTexture *texture =
            sfTexture_createFromFile(get_stat_value(array[7]), NULL);

    npc->x = my_atoi(get_stat_value(array[1]));
    npc->y = my_atoi(get_stat_value(array[2]));
    npc->name = get_stat_value(array[0]);
    npc->type = my_atoi(get_stat_value(array[3]));
    npc->text = my_strdup(get_stat_value(array[4]));
    npc->quest_id = my_atoi(get_stat_value(array[5]));
    create_sprite_npc(npc, get_stat_value(array[6]));
    npc->avatar = sfSprite_create();
    sfSprite_setTexture(npc->avatar, texture, sfTrue);
    sfSprite_setPosition(npc->avatar, create_sfvector(50, 800));
    free(txt);
    free_layout(array);
    return npc;
}

npc_t *init_shop_npc(char *path, item_t** level_items)
{
    npc_t *npc = malloc(sizeof(npc_t));
    char *txt = get_item_stats(path);
    char **array = str_to_array(txt, '\n');
    sfTexture *texture =
            sfTexture_createFromFile(get_stat_value(array[7]), NULL);

    npc->x = my_atoi(get_stat_value(array[1]));
    npc->y = my_atoi(get_stat_value(array[2]));
    npc->name = get_stat_value(array[0]);
    npc->type = my_atoi(get_stat_value(array[3]));
    npc->text = my_strdup(get_stat_value(array[4]));
    npc->quest_id = my_atoi(get_stat_value(array[5]));
    create_sprite_npc(npc, get_stat_value(array[6]));
    npc->avatar = sfSprite_create();
    sfSprite_setTexture(npc->avatar, texture, sfTrue);
    sfSprite_setPosition(npc->avatar, create_sfvector(50, 800));
    free(txt);
    free_layout(array);
    pick_items(npc, level_items);
    return npc;
}
