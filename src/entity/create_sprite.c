/*
** EPITECH PROJECT, 2022
** create_sprite.c
** File description:
** create npc sprite
*/

#include "stdlib.h"
#include "useful_csfml.h"
#include "SFML/Graphics.h"
#include "SFML/System/Types.h"

void scale_sprite_npc(sfSprite **sprite, int scale)
{
    for (int j = 0; sprite[j] != NULL; j++) {
        sfSprite_scale(sprite[j], create_sfvector(scale, scale));
        sfSprite_move(sprite[j], create_sfvector(-scale * 16, -scale * 16));
    }
}

void create_sprite_npc(npc_t *npc, char *path)
{
    sfIntRect sheet = sfintrect_create(0, 0, 64, 64);
    sfTexture *texture;
    sfSprite **sprites = malloc(sizeof(sfSprite *) * (6 + 1));

    for (int j = 0; j < 6; j++) {
        sprites[j] = sfSprite_create();
        texture = sfTexture_createFromFile(path, &sheet);
        sfSprite_setTexture(sprites[j], texture, sfTrue);
        sfSprite_setPosition(sprites[j],
                             create_sfvector(64 * npc->x, 64 * npc->y));
        sheet.left += 64;
    }
    sprites[6] = NULL;
    npc->sprites = sprites;
    scale_sprite_npc(npc->sprites, 2);
}

void create_sprite_enemy(enemy_t *enemy, char *path, int l, int c)
{
    sfIntRect sheet = sfintrect_create(0, 0, enemy->size_sp, enemy->size_sp);
    sfTexture *texture;
    sfSprite ***sprites = malloc(sizeof(sfSprite **) * (l + 1));
    int i = 0;

    while (i < l) {
        sprites[i] = malloc(sizeof(sfSprite *) * (c + 1));
        for (int j = 0; j < c; j++) {
            sprites[i][j] = sfSprite_create();
            texture = sfTexture_createFromFile(path, &sheet);
            sfSprite_setTexture(sprites[i][j], texture, sfTrue);
            sheet.left += enemy->size_sp;
        }
        sprites[i][c] = NULL;
        sheet.left = 0;
        sheet.top += enemy->size_sp;
        i++;
    }
    sprites[i] = NULL;
    enemy->sprites = sprites;
}
