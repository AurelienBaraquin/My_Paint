/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** layer_window
*/

#include "layer.h"

void display_layer_windew_2(layer_t *layer, layer_elem_t *tmp, int i)
{
    sfRectangleShape_setPosition(tmp->rect_layer,
    (sfVector2f){10, 70 + i * 60});
    sfText_setPosition(tmp->layer_name, (sfVector2f){20, 80 + i * 60});
    sfRectangleShape_setPosition(tmp->rect_arrow,
    (sfVector2f){360, 70 + i * 60});
    sfText_setPosition(tmp->arrow_text, (sfVector2f){368, 74 + i * 60});
    sfRectangleShape_setPosition(tmp->rect_case,
    (sfVector2f){420, 70 + i * 60});
    sfText_setPosition(tmp->case_text, (sfVector2f){428, 74 + i * 60});
    sfRenderWindow_drawRectangleShape(layer->window, tmp->rect_layer, NULL);
    sfRenderWindow_drawText(layer->window, tmp->layer_name, NULL);
    sfRenderWindow_drawRectangleShape(layer->window, tmp->rect_arrow, NULL);
    sfRenderWindow_drawText(layer->window, tmp->arrow_text, NULL);
    sfRenderWindow_drawRectangleShape(layer->window, tmp->rect_case, NULL);
    sfRenderWindow_drawText(layer->window, tmp->case_text, NULL);
}

void display_layer_window(layer_t *layer)
{
    sfRenderWindow_clear(layer->window, sfBlack);
    sfRenderWindow_drawRectangleShape(layer->window,
    layer->layer_list->create_layer, NULL);
    sfRenderWindow_drawText(layer->window,
    layer->layer_list->create_layer_text, NULL);
    layer_elem_t *tmp = layer->layer_list->first;
    int i = 0;
    while (tmp != NULL) {
        display_layer_windew_2(layer, tmp, i);
        tmp = tmp->next;
        i++;
    }
    sfRenderWindow_display(layer->window);
}

void update_layer_window_2(layer_t *layer, int view_deplacement)
{
    layer->layer_list->is_hovered = sfTrue;
    sfRectangleShape_setOutlineColor(layer->layer_list->create_layer, sfRed);
    sfText_setColor(layer->layer_list->create_layer_text, sfRed);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (layer->layer_list->is_clicked == sfTrue)
            return;
        layer->layer_list->is_clicked = sfTrue;
        sfRectangleShape_setFillColor(layer->layer_list->create_layer, sfRed);
        add_layer_to_list(layer->layer_list, get_text_input(layer->window,
        sfRectangleShape_getPosition(layer->layer_list->create_layer),
        "Enter layer name :"));
        layer->nb_layers++;
    } else {
        layer->layer_list->is_clicked = sfFalse;
        sfRectangleShape_setFillColor(layer->layer_list->create_layer, sfBlack);
    }
}

void update_layer_window(layer_t *layer, int view_deplacement)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(layer->window);
    sfVector2f mouse_pos_f = (sfVector2f){mouse_pos.x,
    mouse_pos.y + view_deplacement};
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(
    layer->layer_list->create_layer);
    if (sfFloatRect_contains(&rect, mouse_pos_f.x, mouse_pos_f.y)) {
        update_layer_window_2(layer, view_deplacement);
    } else {
        layer->layer_list->is_hovered = sfFalse;
        sfRectangleShape_setOutlineColor(
        layer->layer_list->create_layer, sfWhite);
        sfText_setColor(layer->layer_list->create_layer_text, sfWhite);
    }
}
