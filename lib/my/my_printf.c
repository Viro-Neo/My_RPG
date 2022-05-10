/*
** EPITECH PROJECT, 2022
** printf
** File description:
** printf
*/

#include "my.h"
#include <stdarg.h>

int search_flag(va_list list, const char *format, int i)
{
    switch (format[i]) {
    case '%':
        my_putchar('%');
        break;
    case 'c':
        my_putchar(va_arg(list, int));
        break;
    case 'i':case 'd':
        my_putnbr(va_arg(list, int));
        break;
    case 's':
        my_putstr(va_arg(list, char *));
        break;
    }
    return 1;
}

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;

    va_start(list, format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%')
            my_putchar(format[i]);
        else
            i += search_flag(list, format, i + 1);
    }
    va_end(list);
    return i;
}
