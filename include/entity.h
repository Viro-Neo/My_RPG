/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** file containing struct for entities such as enemies or npcs
*/

#ifndef ENTITY_H_
    #define ENTITY_H_
    #define SHOPKEEPER  3
    #define ROBOT_NPC   2
    #define QUEST_NPC   1
    #define IDLE_NPC    0
    #define SHOP_SLOTS  3
    #include "item.h"
    #include "stat.h"
    #include "status_condition.h"
    #include <SFML/Graphics.h>
    #include <SFML/System/Types.h>

    typedef struct enemy_s {
        struct stat_s *stats;
        sfClock *clock;
        int x;
        int y;
        int dir;
        int sprite_x;
        int sprite_y;
        int scale;
        char *name;
        int size_sp;
        int range;
        sfSprite ***sprites;
        sfVector2i vect;
        int xp_given;
        status_t *status[2];
    } enemy_t;

    typedef struct npc_s {
        int x;
        int y;
        int type;
        char *text;
        char *name;
        int quest_id;
        sfSprite *avatar;
        sfSprite **sprites;
        struct item_s *shop[3];
    } npc_t;

void create_sprite_npc(npc_t *npc, char *path);
npc_t *init_idle_npc(char *path);
npc_t *init_quest_npc(char *name, sfVector2f vect, int quest, char *path);
npc_t *init_shop_npc(char *path, item_t **level_items);
void pick_items(npc_t *, item_t **);
enemy_t *init_enemy(char *);
char *get_npc_path(int indice, char *path);
void create_sprite_enemy(enemy_t *enemy, char *path, int l, int c);
void npc_talk(npc_t *npc, sfRenderWindow *window);
void display_en_stats(enemy_t *);
void init_enemy_sprites(enemy_t *enemy);

#endif/* ENTITY_H_ */
