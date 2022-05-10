/*
** EPITECH PROJECT, 2022
** main_menu_fct.h
** File description:
** main_menu_fct
*/

#ifndef MAIN_MENU_FCT_H_
    #define MAIN_MENU_FCT_H_
    #include "game.h"
    #include "main_menu.h"

int main_menu(game_t *game);
main_menu_t *init_main_menu(void);
options_menu_t *init_options_menu(void);
btn_t *init_button(char *path, int pos_x, int pos_y);
void verify_mouse_pos_btn(sfVector2i mouse_pos, btn_t *btn);
void display_btn(sfRenderWindow *window, main_menu_t *main_menu);
void options_menu(options_menu_t *opt_menu, game_t *game);
void set_fullscreen(game_t *game, int status);
void check_music(sfMusic *music, options_menu_t *opt_menu);
void htp_menu(game_t *game, htp_menu_t *htp_menu);
htp_menu_t *init_htp_menu(void);
void free_main_menu(main_menu_t *main_menu);

#endif/*MAIN_MENU_FCT_H_*/
