/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** layer_update
*/

#include "layer.h"

void update_layer_2(layer_elem_t *tmp, layer_t *layer)
{
    tmp->is_hovered_layer = sfTrue;
    sfRectangleShape_setOutlineColor(tmp->rect_layer, sfBlue);
    sfText_setColor(tmp->layer_name, sfBlue);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (tmp->is_clicked_layer == sfTrue)
            return;
        tmp->is_clicked_layer = sfTrue;
        sfRectangleShape_setFillColor(tmp->rect_layer, sfBlue);
        tmp->is_visible *= -1;
    } else {
        tmp->is_clicked_layer = sfFalse;
        sfRectangleShape_setFillColor(tmp->rect_layer, sfBlack);
    }
}

void update_layer_3(layer_elem_t *tmp, layer_t *layer)
{
    tmp->is_hovered_layer = sfFalse;
    if (tmp->is_visible == 1) {
        sfRectangleShape_setOutlineColor(tmp->rect_layer, sfGreen);
        sfText_setColor(tmp->layer_name, sfGreen);
    } else {
        sfRectangleShape_setOutlineColor(tmp->rect_layer, sfWhite);
        sfText_setColor(tmp->layer_name, sfWhite);
    }
}

void update_layer(layer_t *layer, int view_deplacement)
{
    layer_elem_t *tmp = layer->layer_list->first;
    while (tmp != NULL) {
        sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(layer->window);
        sfVector2f mouse_pos_f = (sfVector2f){mouse_pos.x,
        mouse_pos.y + view_deplacement};
        sfFloatRect rect = sfRectangleShape_getGlobalBounds(tmp->rect_layer);
        if (sfFloatRect_contains(&rect, mouse_pos_f.x, mouse_pos_f.y)) {
            update_layer_2(tmp, layer);
        } else {
            update_layer_3(tmp, layer);
        }
        tmp = tmp->next;
    }
}
