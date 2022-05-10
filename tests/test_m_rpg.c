/*
** EPITECH PROJECT, 2021
** test_m_rpg.c
** File description:
** test_m_rpg
*/

#include <criterion/criterion.h>
#include "m_rpg.h"

Test(m_rpg_test, simple_test)
{
    int ac = 1;
    char *av[1] = {"./m_rpg"};

    cr_assert_eq(m_rpg(ac, av), 0);
}
