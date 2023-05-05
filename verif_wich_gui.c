/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** verif_wich_gui
*/

#include "paint.h"

void update_gui(global_t *global)
{
    if (global->is_launched2 == sfFalse){
        sfThread_launch(global->thread2);
        global->is_launched2 = sfTrue;
    }
    if (global->gui[2]->is_hovered == sfTrue &&
    global->gui[2]->is_clicked == sfTrue &&
    global->gui[0]->is_clicked == sfFalse) {
        drawing(global);
    } else {
        verif_click_realised(global);
    }
}

sfBool verif_coord(global_t *global, int i)
{
    if (global->mouse_posf.x >= global->gui_button->first_buttons[i]->pos.x &&
    global->mouse_posf.x <= global->gui_button->first_buttons[i]->pos.x
    + global->gui_button->first_buttons[i]->size.x &&
    global->mouse_posf.y >= global->gui_button->first_buttons[i]->pos.y &&
    global->mouse_posf.y <= global->gui_button->first_buttons[i]->pos.y +
    global->gui_button->first_buttons[i]->size.y) {
        return (sfTrue);
    }
    return (sfFalse);
}

sfBool verif_coord_two(global_t *global, int i, int j)
{
    if (global->mouse_posf.x >= global->gui_button->seg_buttons[i][j]->pos.x &&
    global->mouse_posf.x <= global->gui_button->seg_buttons[i][j]->pos.x +
    global->gui_button->seg_buttons[i][j]->size.x &&
    global->mouse_posf.y >= global->gui_button->seg_buttons[i][j]->pos.y &&
    global->mouse_posf.y <= global->gui_button->seg_buttons[i][j]->pos.y +
    global->gui_button->seg_buttons[i][j]->size.y) {
        return (sfTrue);
    }
    return (sfFalse);
}

void verif_key_layers(global_t *global)
{
    if ((global->event.type == sfEvtKeyPressed && global->event.key.code ==
    sfKeyN) || (global->gui[1]->is_clicked == sfTrue &&
    global->event.type == sfEvtMouseButtonPressed &&
    global->mouse_pos.x >= global->rect_pos_sprite.x &&
    global->mouse_pos.x <= global->rect_pos_sprite.x +
    150 && global->mouse_pos.y >= global->rect_pos_sprite.y &&
    global->mouse_pos.y <= global->rect_pos_sprite.y +
    150))
        layer_window(global);
}
