/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** layer_arrow
*/

#include "layer.h"

void update_arrow_2(layer_t *layer, int view_deplacement,
layer_elem_t *tmp, int i)
{
    tmp->is_hovered_arrow = sfTrue;
    sfRectangleShape_setOutlineColor(tmp->rect_arrow, sfBlue);
    sfText_setColor(tmp->arrow_text, sfBlue);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (tmp->is_clicked_arrow == sfTrue)
            return;
        tmp->is_clicked_arrow = sfTrue;
        sfRectangleShape_setFillColor(tmp->rect_arrow, sfBlue);
        move_layer_prev_in_list(layer->layer_list, i);
        sfSleep(sfSeconds(0.2));
    } else {
        tmp->is_clicked_arrow = sfFalse;
        sfRectangleShape_setFillColor(tmp->rect_arrow, sfBlack);
    }
}

void update_arrow(layer_t *layer, int view_deplacement)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(layer->window);
    sfVector2f mouse_pos_f = (sfVector2f){mouse_pos.x, mouse_pos.y +
    view_deplacement};
    layer_elem_t *tmp = layer->layer_list->first;
    int i = 0;
    while (tmp != NULL) {
        sfFloatRect rect = sfRectangleShape_getGlobalBounds(tmp->rect_arrow);
        if (sfFloatRect_contains(&rect, mouse_pos_f.x, mouse_pos_f.y)) {
            update_arrow_2(layer, view_deplacement, tmp, i);
        } else {
            tmp->is_hovered_arrow = sfFalse;
            sfRectangleShape_setOutlineColor(tmp->rect_arrow, sfWhite);
            sfText_setColor(tmp->arrow_text, sfWhite);
        }
        tmp = tmp->next;
        i++;
    }
}
