/*
** EPITECH PROJECT, 2022
** useful_csfml
** File description:
** useful_csfml
*/

#ifndef USEFUL_H_
    #define USEFUL_H_
    #include "game.h"
    #include <SFML/System/Time.h>
    #include <SFML/Graphics/Types.h>

sfIntRect sfintrect_create(int left, int top, int width, int height);
sfVector2f create_sfvector(float x, float y);
int event_handling_menu(sfRenderWindow *window);
int event_handling_game(sfRenderWindow *window, game_t *game);
float get_seconds(sfClock *clock);
float get_deciseconds(sfClock *clock);
char *get_stat_value(char *stat);
void scale_sprite_npc(sfSprite **sprite, int scale);
int count_file(char *);

#endif
