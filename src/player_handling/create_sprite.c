/*
** EPITECH PROJECT, 2022
** create_sprite
** File description:
** create_sprite
*/

#include "player_handling.h"
#include "useful_csfml.h"
#include <stdlib.h>

void scale_sprite_player(sfSprite ***sprite)
{
    for (int i = 0; sprite[i] != NULL; i++) {
        for (int j = 0; sprite[i][j] != NULL; j++) {
            sfSprite_scale(sprite[i][j], create_sfvector(4, 4));
            sfSprite_move(sprite[i][j], create_sfvector(-32, -32));
        }
    }
}

void create_sprite_attack(sfSprite ***sprites, sfIntRect sheet, int index)
{
    sfTexture *texture = NULL;

    sheet.top += 32 * 10;
    while (index < 9) {
        sprites[index] = malloc(sizeof(sfSprite *) * (8 + 1));
        if (sprites[index] == NULL)
            return;
        for (int i = 0; i < 8; i++) {
            sprites[index][i] = sfSprite_create();
            texture = sfTexture_createFromFile("assets/player/player", &sheet);
            sfSprite_setTexture(sprites[index][i], texture, sfTrue);
            sheet.left += 32;
        }
        sprites[index][8] = NULL;
        sheet.left = 0;
        sheet.top += 32;
        index++;
    }
    sprites[index] = NULL;
}

void create_sprite_player(player_t *player)
{
    sfIntRect sheet = sfintrect_create(0, 0, 32, 32);
    sfTexture *texture = NULL;
    sfSprite ***sprites = malloc(sizeof(sfSprite **) * (9 + 1));
    int i = 0;

    for (i = 0; i < 5; i++) {
        sprites[i] = malloc(sizeof(sfSprite *) * (8 + 1));
        for (int j = 0; j < 8; j++) {
            sprites[i][j] = sfSprite_create();
            texture = sfTexture_createFromFile("assets/player/player", &sheet);
            sfSprite_setTexture(sprites[i][j], texture, sfTrue);
            sheet.left += 32;
        }
        sprites[i][8] = NULL;
        sheet.left = 0;
        sheet.top += 32;
    }
    create_sprite_attack(sprites, sheet, i);
    player->sprites = sprites;
    //free_sprites(sprites);
}
