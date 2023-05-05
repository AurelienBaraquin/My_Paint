/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** settings_verif_event
*/

#include "paint.h"

void settings_verif_event(global_t *global)
{
    if (((global->event.type == sfEvtKeyPressed &&
    global->event.key.code == sfKeyH) || (
    global->gui_button->first_buttons[3]->is_clicked == sfTrue &&
    global->event.type == sfEvtMouseButtonPressed &&
    global->mouse_pos.x >= global->gui_button->first_buttons[3]->pos.x &&
    global->mouse_pos.x <= global->gui_button->first_buttons[3]->pos.x +
    global->gui_button->first_buttons[3]->size.x &&
    global->mouse_pos.y >= global->gui_button->first_buttons[3]->pos.y &&
    global->mouse_pos.y <= global->gui_button->first_buttons[3]->pos.y +
    global->gui_button->first_buttons[3]->size.y))){
        settings_main(global);
        global->mouse_pos = sfMouse_getPositionRenderWindow(global->window);
        global->gui_button->first_buttons[3]->is_clicked = sfFalse;
        global->gui[2]->is_clicked = sfFalse;
    }
}
