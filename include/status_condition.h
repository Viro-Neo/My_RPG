/*
** EPITECH PROJECT, 2022
** stat
** File description:
** stat
*/

#ifndef STATUS_CONDITION_H
    #define STATUS_CONDITION_H
    #define MAX_STATUS 5
    #define CLEAR 0
    #define POISON 1
    #define FREEZE 2
    #define LIFESTEAL 3
    #define STONESKIN 4
    #define BERSERK 5
    #define BLIND 6

typedef struct status_s {
    int type;
    int timer;
    int max_timer;
    int damage;
    int chance;
    int active;
} status_t;

#endif /* STATUS_CONDITION_H */
