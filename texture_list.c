/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** texture_list
*/

#include "paint.h"

void colors_texture_next(sfColor color, sfTexture *texture,
sfImage *image, int x)
{
    sfVector2u size = sfImage_getSize(image);
    for (unsigned int y = 0; y < size.y; y++) {
        sfColor pixel_color = sfImage_getPixel(image, x, y);
        if (pixel_color.r == color.r && pixel_color.g == color.g &&
        pixel_color.b == color.b) {
            pixel_color.a = 0;
            sfImage_setPixel(image, x, y, pixel_color);
        }
    }
}

void remove_color_from_texture(sfTexture *texture, sfColor color)
{
    sfImage *image = sfTexture_copyToImage(texture);
    sfVector2u size = sfImage_getSize(image);
    for (unsigned int x = 0; x < size.x; x++) {
        colors_texture_next(color, texture, image, x);
    }
    sfTexture_updateFromImage(texture, image, 0, 0);
    sfImage_destroy(image);
}

void redo_texture_list(global_t *global)
{
    layer_elem_t *tmp_layer = global->layer_first;
    int i = 0;
    while (tmp_layer != NULL) {
        if (tmp_layer->texture_list->first == NULL ||
        tmp_layer->is_visible != 1) {
            tmp_layer = tmp_layer->next;
            continue;
        }
        texture_elem_t *tmp = tmp_layer->texture_list->first;
        i = 0;
        while (i < tmp_layer->texture_list->index && tmp != NULL) {
            tmp = tmp->next;
            i++;
        }
        if (tmp != NULL)
            tmp_layer->texture_list->index++;
        tmp_layer = tmp_layer->next;
    }
}

void remove_last_element_from_texture_list(global_t *global)
{
    layer_elem_t *tmp_layer = global->layer_first;
    while (tmp_layer != NULL) {
        if (tmp_layer->texture_list->first == NULL ||
        tmp_layer->texture_list->index <= 0 ||
        tmp_layer->is_visible != 1) {
            tmp_layer = tmp_layer->next;
            continue;
        }
        tmp_layer->texture_list->index--;
        tmp_layer = tmp_layer->next;
    }
}

void add_elem_next_texture(texture_elem_t *new_elem, texture_elem_t *tmp
,layer_elem_t *tmp_layer)
{
    int i = 0;
    if (tmp_layer->texture_list->first == NULL ||
    tmp_layer->texture_list->index == 0) {
        tmp_layer->texture_list->first = new_elem;
        tmp_layer->texture_list->index++;
        tmp_layer = tmp_layer->next;
        return;
    }
    while (tmp->next != NULL && i < tmp_layer->texture_list->index - 1) {
        tmp = tmp->next;
        i++;
    }
    tmp->next = new_elem;
    tmp_layer->texture_list->index++;
    tmp_layer = tmp_layer->next;
}
