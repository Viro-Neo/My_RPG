/*
** EPITECH PROJECT, 2022
** init_enemy.c
** File description:
** init the enemy of a room
*/

#include <stdlib.h>
#include "my.h"
#include "stat.h"
#include "item.h"
#include "entity.h"
#include "useful_csfml.h"

static void init_enemt_status(enemy_t *enemy, char **array)
{
    enemy->status[0] = malloc(sizeof(status_t));
    enemy->status[0]->type = my_atoi(get_stat_value(array[19]));
    enemy->status[0]->timer = my_atoi(get_stat_value(array[20]));
    enemy->status[0]->damage = my_atoi(get_stat_value(array[21]));
    enemy->status[0]->chance = my_atoi(get_stat_value(array[22]));
    enemy->status[0]->max_timer = enemy->status[0]->timer;
    enemy->status[1] = NULL;
}

static void init_enemy_stat(enemy_t *enemy, char **array)
{
    enemy->stats = malloc(sizeof(stat_t));
    enemy->range = my_atoi(get_stat_value(array[17]));
    enemy->stats->level = my_atoi(get_stat_value(array[3]));
    enemy->stats->str = my_atoi(get_stat_value(array[4]));
    enemy->stats->dex = my_atoi(get_stat_value(array[5]));
    enemy->stats->wis = my_atoi(get_stat_value(array[6]));
    enemy->stats->hp = my_atoi(get_stat_value(array[7]));
    enemy->stats->mana = my_atoi(get_stat_value(array[8]));
    enemy->stats->ac = my_atoi(get_stat_value(array[9]));
    enemy->stats->max_hp = my_atoi(get_stat_value(array[10]));
    enemy->stats->max_mana = my_atoi(get_stat_value(array[11]));
    enemy->stats->money = my_atoi(get_stat_value(array[12]));
    enemy->stats->actions = my_atoi(get_stat_value(array[18]));
    enemy->stats->max_actions = enemy->stats->actions;
    init_enemt_status(enemy, array);
    enemy->vect.x = 0;
    enemy->vect.y = 0;
    enemy->dir = -1;
}

void init_enemy_sprites(enemy_t *enemy)
{
    sfVector2f vect = create_sfvector(enemy->x * 64, enemy->y * 64);

    for (int i = 0; enemy->sprites[i] != NULL; i++) {
        for (int j = 0; enemy->sprites[j] != NULL; j++) {
            sfSprite_move(enemy->sprites[i][j], vect);
        }
    }
}

enemy_t *init_enemy(char *path)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    char *txt = get_item_stats(path);
    char **array = str_to_array(txt, '\n');

    enemy->clock = sfClock_create();
    enemy->name = my_strdup(get_stat_value(array[0]));
    enemy->xp_given = my_atoi(get_stat_value(array[1]));
    enemy->size_sp = my_atoi(get_stat_value(array[16]));
    enemy->sprite_x = my_atoi(get_stat_value(array[13]));
    enemy->sprite_y = my_atoi(get_stat_value(array[14]));
    enemy->scale = my_atoi(get_stat_value(array[15]));
    create_sprite_enemy(enemy, get_stat_value(array[2]),
                        enemy->sprite_x, enemy->sprite_y);
    for (int i = 0; enemy->sprites[i] != NULL; i++)
        scale_sprite_npc(enemy->sprites[i],
                         enemy->scale);
    init_enemy_stat(enemy, array);
    free(txt);
    free_layout(array);
    return enemy;
}
