/*
** EPITECH PROJECT, 2022
** count_file.c
** File description:
** count_file
*/

#include "my.h"
#include "game.h"

sfMusic *play_music(char *path, int volume)
{
    sfMusic *music = sfMusic_createFromFile(path);

    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, volume);
    sfMusic_play(music);
    return music;
}

void stop_music(sfMusic *music)
{
    sfMusic_stop(music);
    sfMusic_destroy(music);
}
