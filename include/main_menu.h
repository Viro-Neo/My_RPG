/*
** EPITECH PROJECT, 2022
** main_menu.h
** File description:
** main_menu
*/

#ifndef MAIN_MENU_H_
    #define MAIN_MENU_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <stdbool.h>

typedef struct btn_s {
    sfTexture *t_btn;
    sfVector2f pos;
    sfVector2f size;
    sfIntRect rect;
    sfRectangleShape *rectangle;
    bool is_hover;
    bool is_handled;
    bool is_clicked;
} btn_t;

typedef struct music_s {
    sfMusic *music;
    int volume;
    bool is_playing;
} music_t;

typedef struct options_menu_s {
    sfSprite *s_bg;
    sfTexture *t_bg;
    btn_t *back_btn;
    btn_t *fullscreen_btn;
    btn_t *keybinding_btn;
    btn_t *sound_btn;
    bool is_fullscreen;
} options_menu_t;

typedef struct htp_menu_s {
    btn_t *back_btn;
    btn_t *translate_btn;
    bool is_text_translated;
    sfText *txt_fr;
    sfText *txt_en;
    sfSprite *bg_sprite;
    sfSprite *title_sprite;
} htp_menu_t;

typedef struct main_menu_s {
    sfSprite *s_bg;
    sfTexture *t_bg;
    options_menu_t *opt_menu;
    htp_menu_t *htp_menu;
    music_t *music;
    btn_t *play_btn;
    btn_t *opt_btn;
    btn_t *htp_btn;
    btn_t *exit_btn;
} main_menu_t;

#endif /*MAIN_MENU_H_*/
