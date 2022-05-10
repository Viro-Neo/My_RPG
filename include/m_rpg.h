/*
** EPITECH PROJECT, 2021
** m_rpg.h
** File description:
** m_rpg
*/

#ifndef M_RPG_H_
    #define M_RPG_H_

typedef struct quest_s {
    int id;
    int status;
} quest_t;

int error_handling(int ac, char **av);
int m_rpg(int ac, char **av);

#endif/*M_RPG_H_*/
