/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** layer_case
*/

#include "layer.h"

void update_layer_case_2(layer_t *layer, int view_deplacement,
layer_elem_t *tmp, int i)
{
    tmp->is_hovered_case = sfTrue;
    sfRectangleShape_setOutlineColor(tmp->rect_case, sfRed);
    sfText_setColor(tmp->case_text, sfRed);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (tmp->is_clicked_case == sfTrue)
            return;
        tmp->is_clicked_case = sfTrue;
        sfRectangleShape_setFillColor(tmp->rect_case, sfRed);
        if (layer->nb_layers > 1) {
            remove_layer_from_list(layer->layer_list, i);
            sfSleep(sfSeconds(0.2));
            layer->nb_layers--;
        }
    } else {
        tmp->is_clicked_case = sfFalse;
        sfRectangleShape_setFillColor(tmp->rect_case, sfBlack);
    }
}

void update_layer_case(layer_t *layer, int view_deplacement)
{
    layer_elem_t *tmp = layer->layer_list->first;
    int i = 0;
    while (tmp != NULL) {
        sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(layer->window);
        sfVector2f mouse_pos_f = (sfVector2f){mouse_pos.x, mouse_pos.y +
        view_deplacement};
        sfFloatRect rect = sfRectangleShape_getGlobalBounds(tmp->rect_case);
        if (sfFloatRect_contains(&rect, mouse_pos_f.x, mouse_pos_f.y)) {
            update_layer_case_2(layer, view_deplacement, tmp, i);
        } else {
            tmp->is_hovered_case = sfFalse;
            sfRectangleShape_setOutlineColor(tmp->rect_case, sfWhite);
            sfText_setColor(tmp->case_text, sfWhite);
        }
        tmp = tmp->next;
        i++;
    }
}
