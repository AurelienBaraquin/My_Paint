/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** verif_mouse_pos
*/

#include "paint.h"

void update_mouse_pos(global_t *global)
{
    global->mouse_pos = sfMouse_getPositionRenderWindow(global->window);
    global->mouse_posf = (sfVector2f){global->mouse_pos.x, global->mouse_pos.y};
}

void dont_count_line(global_t *global)
{
    for (int i = 0; i < global->size; i++) {
        for (int j = 0; j < global->size; j++) {
            global->point[i][j].color = sfTransparent;
            sfVertexArray_append(global->vertices[i][j], global->point[i][j]);
        }
    }
}

void mouse_button_on_gui(global_t *global, int *i, int *a)
{
    if (global->event.type == sfEvtMouseButtonPressed &&
    global->event.mouseButton.button == sfMouseLeft){
        global->gui[*i]->is_clicked = sfTrue;
    }
    if (global->event.type == sfEvtMouseButtonReleased &&
    global->event.mouseButton.button == sfMouseLeft){
        global->gui[*i]->is_clicked = sfFalse;
        global->occurence = 0;
        *a = 0;
    }
}

void mouse_on_gui(global_t *global, int *a)
{
    for (int i = 0; i < 3; i++) {
        if (global->mouse_posf.x >= global->gui[i]->pos.x &&
        global->mouse_posf.x <= global->gui[i]->pos.x +
        global->gui[i]->size.x && global->mouse_posf.y >= global->gui[i]->pos.y
        &&
        global->mouse_posf.y <=
        global->gui[i]->pos.y + global->gui[i]->size.y) {
            global->gui[i]->is_hovered = sfTrue;
            mouse_button_on_gui(global, &i, a);
        } else {
            global->gui[i]->is_hovered = sfFalse;
            global->gui[i]->is_clicked = sfFalse;
        }
    }
}

int change_i_value(global_t *global, int i)
{
    while (sfRenderWindow_pollEvent(global->window, &global->event)){
        if (global->event.type == sfEvtMouseButtonReleased){
            i = 1;
            break;
        }
    }
    return (i);
}
