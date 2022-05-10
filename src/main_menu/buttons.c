/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** buttons handling and display
*/

#include "main_menu.h"
#include "main_menu_fct.h"

static void reset_modifications(main_menu_t *main_menu)
{
    if (!main_menu->play_btn->is_hover)
        sfRectangleShape_setSize(main_menu->play_btn->rectangle,
                                main_menu->play_btn->size);
    if (!main_menu->opt_btn->is_hover)
        sfRectangleShape_setSize(main_menu->opt_btn->rectangle,
                                main_menu->opt_btn->size);
    if (!main_menu->htp_btn->is_hover)
        sfRectangleShape_setSize(main_menu->htp_btn->rectangle,
                                main_menu->htp_btn->size);
    if (!main_menu->exit_btn->is_hover)
        sfRectangleShape_setSize(main_menu->exit_btn->rectangle,
                                main_menu->exit_btn->size);
}

static void verify_states(btn_t *btn)
{
    if (btn->is_hover)
        sfRectangleShape_setSize(btn->rectangle,
            (sfVector2f){btn->size.x * 1.05, btn->size.y * 1.05});
    if (btn->is_handled)
        sfRectangleShape_setSize(btn->rectangle,
            (sfVector2f){btn->size.x * 0.9, btn->size.y * 0.9});
    if (btn->is_clicked)
        sfRectangleShape_setSize(btn->rectangle, btn->size);
}

void verify_mouse_pos_btn(sfVector2i mouse_pos, btn_t *btn)
{
    if (mouse_pos.x >= btn->pos.x && mouse_pos.x <= btn->pos.x + btn->size.x
    && mouse_pos.y >= btn->pos.y && mouse_pos.y <= btn->pos.y + btn->size.y) {
        btn->is_hover = true;
        if (sfMouse_isButtonPressed(sfMouseLeft))
            btn->is_handled = true;
        if (btn->is_handled && !sfMouse_isButtonPressed(sfMouseLeft)) {
            btn->is_handled = false;
            btn->is_clicked = true;
        }
    }
    verify_states(btn);
}

static void verify_mouse_pos(sfRenderWindow *window, main_menu_t *main_menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    verify_mouse_pos_btn(mouse_pos, main_menu->play_btn);
    verify_mouse_pos_btn(mouse_pos, main_menu->opt_btn);
    verify_mouse_pos_btn(mouse_pos, main_menu->htp_btn);
    verify_mouse_pos_btn(mouse_pos, main_menu->exit_btn);
}

void display_btn(sfRenderWindow *window, main_menu_t *main_menu)
{
    verify_mouse_pos(window, main_menu);
    sfRenderWindow_drawRectangleShape(window, main_menu->play_btn->rectangle,
                                                                    NULL);
    sfRenderWindow_drawRectangleShape(window, main_menu->opt_btn->rectangle,
                                                                    NULL);
    sfRenderWindow_drawRectangleShape(window, main_menu->htp_btn->rectangle,
                                                                    NULL);
    sfRenderWindow_drawRectangleShape(window, main_menu->exit_btn->rectangle,
                                                                    NULL);
    reset_modifications(main_menu);
}
