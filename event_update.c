/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** event_update
*/

#include "paint.h"

void clear_array_vertex(global_t *global)
{
    for (int i = 0; i < global->size; i++){
        for (int j = 0; j < global->size; j++){
            sfVertexArray_clear(global->vertices[i][j]);
        }
    }
}

void remove_layer(global_t *global)
{
    layer_elem_t *tmp = global->layer_first;
    while (tmp != NULL) {
        if (tmp->is_visible == 1) {
            tmp->texture_list->first = NULL;
        }
        tmp = tmp->next;
    }
}

void update_differents_var(global_t *global)
{
    for (int i = 0; i < global->gui_button->nb_first_buttons; i++) {
        if (global->gui_button->first_buttons[i]->is_clicked == sfTrue){
            global->gui[0]->is_clicked = sfTrue;
        }
    }
    if (global->gui_button->first_buttons[2]->is_clicked == sfTrue) {
        remove_layer(global);
    }
    if (global->gui_button->first_buttons[4]->is_clicked == sfTrue){
        remove_last_element_from_texture_list(global);
        global->event.type = sfEvtMouseButtonReleased;
        global->gui_button->first_buttons[4]->is_clicked = sfFalse;
    }
    if (global->gui_button->first_buttons[5]->is_clicked == sfTrue){
        redo_texture_list(global);
        global->event.type = sfEvtMouseButtonReleased;
        global->gui_button->first_buttons[5]->is_clicked = sfFalse;
    }
}

void verif_event_under_window(global_t *global, int i)
{
    for (int j = 0; j < global->gui_button->nb_seg_buttons[i]; j++) {
        if (verif_coord_two(global, i, j) == sfTrue) {
            global->gui_button->seg_buttons[i][j]->is_clicked = sfTrue;
            global->chosen_button = (sfVector2i){i, j};
            global->event.type = sfEvtMouseButtonReleased;
        } else {
            global->gui_button->seg_buttons[i][j]->is_clicked = sfFalse;
        }
    }
}

void change_size(global_t *global)
{
    global->slider_pos.x = global->mouse_pos.x - global->slider_size;
    global->size = (global->slider_pos.x - global->back_slider_pos.x) / 5;
    if (global->size < 1)
        global->size = 1;
    if (global->size > MAX_VERTEX_SIZE)
        global->size = MAX_VERTEX_SIZE;
    sfCircleShape_setPosition(global->slider, global->slider_pos);
    display_f(global, 0);
}
