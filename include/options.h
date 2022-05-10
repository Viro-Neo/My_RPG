/*
** EPITECH PROJECT, 2022
** game.h
** File description:
** game.h
*/

#ifndef OPTIONS_H_
    #define OPTIONS_H_
    #define KEY_COUNT 13
    #define KEY_CONFIRM 0
    #define KEY_ACT 1
    #define KEY_PAUSE 2
    #define KEY_LEFT 3
    #define KEY_UP 4
    #define KEY_RIGHT 5
    #define KEY_DOWN 6
    #define KEY_INTERACT 7
    #define KEY_MENU_LEFT 8
    #define KEY_MENU_UP 9
    #define KEY_MENU_RIGHT 10
    #define KEY_MENU_DOWN 11
    #define KEY_BACK 12

typedef struct option_s {
    int keys[KEY_COUNT];
} option_t;

#endif /* OPTIONS_H_ */
