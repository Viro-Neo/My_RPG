/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init main menu struct
*/

#include <stdlib.h>
#include "main_menu.h"
#include "main_menu_fct.h"

btn_t *init_button(char *path, int pos_x, int pos_y)
{
    btn_t *button = malloc(sizeof(btn_t));

    button->t_btn = sfTexture_createFromFile(path, NULL);
    button->rect.width = 723;
    button->rect.height = 182;
    button->size.x = button->rect.width;
    button->size.y = button->rect.height;
    button->pos.x = pos_x - button->size.x / 2;
    button->pos.y = pos_y - button->size.y;
    button->rectangle = sfRectangleShape_create();
    sfRectangleShape_setTexture(button->rectangle, button->t_btn, sfTrue);
    sfRectangleShape_setPosition(button->rectangle, button->pos);
    sfRectangleShape_setSize(button->rectangle, button->size);
    button->is_hover = false;
    button->is_handled = false;
    button->is_clicked = false;
    return button;
}

static main_menu_t *init_buttons(main_menu_t *main_menu)
{
    main_menu->play_btn = init_button("assets/menu/btns/playbtn.png", 1500,
                                                                        360);
    main_menu->opt_btn = init_button("assets/menu/btns/optbtn.png", 1500, 550);
    main_menu->htp_btn = init_button("assets/menu/btns/htpbtn.png", 1500, 740);
    main_menu->exit_btn = init_button("assets/menu/btns/exitbtn.png", 1550,
                                                                        1050);
    return main_menu;
}

main_menu_t *init_main_menu(void)
{
    main_menu_t *main_menu = malloc(sizeof(main_menu_t));

    main_menu->t_bg = sfTexture_createFromFile("assets/menu/bg.jpg", NULL);
    main_menu->s_bg = sfSprite_create();
    sfSprite_setTexture(main_menu->s_bg, main_menu->t_bg, sfTrue);
    main_menu = init_buttons(main_menu);
    return (main_menu);
}
