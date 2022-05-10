/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** sound_handling
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "main_menu.h"
#include "main_menu_fct.h"

void check_music(sfMusic *music, options_menu_t *opt_menu)
{
    sfSoundStatus status = sfMusic_getStatus(music);

    if (status == sfPlaying) {
        if (opt_menu->sound_btn->is_clicked)
            sfMusic_pause(music);
    } else
        if (opt_menu->sound_btn->is_clicked)
            sfMusic_play(music);
}
