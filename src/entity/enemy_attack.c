/*
** EPITECH PROJECT, 2022
** enemy_attack.c
** File description:
** enemy_attack
*/

#include "game.h"
#include "stdlib.h"
#include "useful_csfml.h"
#include "my.h"

int enemy_attack(enemy_t *enemy, player_t *player, game_t *game)
{
    //animation_attack(enemy, player);
    sfClock_restart(enemy->clock);
    enemy->vect.x = 1;
    char *damage;
    //en_attack_animation(enemy, game);
    if (((rand() % player->stat->dex) - (rand() % enemy->stats->dex)) <= 0) {
        player_take_damage(player, enemy->stats->str - player->stat->ac, game);
        damage = my_strcat("Damage suffered was ",
                           my_itoa(enemy->stats->str - player->stat->ac));
        display_popup(game, damage);
        apply_status_condition(game, enemy->status[0], player);
    } else
        display_popup(game, "dodged enemy attack");
    //pop_up?
    return 0;
}
