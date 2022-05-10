/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** file containing struct for items
*/

#ifndef ITEM_H_
    #define ITEM_H_
    #include "stat.h"
    #include "status_condition.h"
    #define MAX_SLOTS 20
    #define CONSUMABLE 1
    #define KEY_ITEM 0
    #define LEFT_EQUIP 2
    #define RIGHT_EQUIP 3
    #define ARMOR_EQUIP 4
    #define TRINKET_EQUIP 5
    #define SPELL_COUNT 9
    #define SELF_SPELL 1
    #define ATK_SPELL 2
    #define ROW_COUNT 5

    typedef struct item_s {
        int type;
        char *name;
        char *description;
        char *sprite;
        struct stat_s *stats;
    } item_t;

    typedef struct item_list_s {
        struct item_s *item;
        struct item_list_s *next;
    } item_list_t;

    typedef struct spell_s {
        char *name;
        char *description;
        struct stat_s *stats;
        status_t *status;
        int type;
        int damage;
        int range;
    } spell_t;

    typedef struct spell_list_s {
        struct spell_s *spell;
        struct spell_list_s *next;
    } spell_list_t;

item_list_t *init_items(char *);

char *get_item_stats(char *);

int get_line_count(char *);

void get_file_lines(char *, char **);

void parse_item(item_t *item, char *filepath);

item_t **make_item_arr(char *path);

void shift_items(item_t **, int);

item_t **get_level_items(item_t **, int);

spell_list_t *init_spells(char *);

spell_t **make_spell_arr(void);

#endif/* ITEM_H_ */
