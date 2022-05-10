/*
** EPITECH PROJECT, 2022
** putnbr
** File description:
** putnbr
*/

#include "my.h"

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb > 9) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    } else
        my_putchar(nb + 48);
}
