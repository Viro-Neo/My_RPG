/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "player_handling.h"
#include "item.h"
#include "entity.h"
#include "m_rpg.h"
#include "my.h"

int main(int ac, char **av)
{
    if (m_rpg(ac, av) == -1)
        return 84;
    return 0;
}
