/*
** EPITECH PROJECT, 2022
** pause_menu.h
** File description:
** pause_menu
*/

#ifndef PAUSE_MENU_H_
    #define PAUSE_MENU_H_
    #include "main_menu.h"

typedef struct btns_t {
    btn_t *btn_resume;
    btn_t *btn_options;
    btn_t *btn_htp;
    btn_t *btn_exit;
} btns_t;

typedef struct sprite_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} sprite_t;

typedef struct pause_menu_s {
    btns_t *btns;
    sprite_t *sprite;
} pause_menu_t;

pause_menu_t *init_pause_menu(void);
void pause_menu(game_t *game);

#endif/*PAUSE_MENU_H_*/
