/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** drawing
*/

#include "paint.h"

void full_fill_2(sfVector2f width_and_i, sfColor color,
sfUint8 *pixels, sfColor new_color)
{
    int width = width_and_i.x;
    int i = width_and_i.y;
    for (int j = 0; j < width; j++) {
        if (compare_color(color, sfColor_fromRGBA(pixels[(i * width + j) * 4],
        pixels[(i * width + j) * 4 + 1], pixels[(i * width + j) * 4 + 2],
        pixels[(i * width + j) * 4 + 3])) == 1) {
            pixels[(i * width + j) * 4] = new_color.r;
            pixels[(i * width + j) * 4 + 1] = new_color.g;
            pixels[(i * width + j) * 4 + 2] = new_color.b;
            pixels[(i * width + j) * 4 + 3] = new_color.a;
        }
    }
}

void full_fill(sfUint8 *pixels, int *params, sfColor color, sfColor new_color)
{
    int x = params[0];
    int y = params[1];
    int width = params[2];
    int height = params[3];
    int i = 0;
    int j = 0;
    for (; i < height; i++) {
        full_fill_2((sfVector2f){width, i}, color, pixels, new_color);
    }
}

void draw_with_bucket(global_t *global)
{
    sfImage *image = screen_window_to_image(global);
    sfUint8 *pixels = (sfUint8 *)sfImage_getPixelsPtr(image);
    int *params = malloc(sizeof(int) * 4);
    params[0] = global->mouse_pos.x;
    params[1] = global->mouse_pos.y;
    params[2] = sfImage_getSize(image).x;
    params[3] = sfImage_getSize(image).y;
    sfColor color = sfImage_getPixel(image, params[0], params[1]);
    sfColor new_color = global->pencil->color;
    if (compare_color(color, new_color) == 1)
        return;
    if (global->layer_first->is_visible == 1 &&
    global->layer_first->texture_list->index == 0)
        full_fill(pixels, params, color, new_color);
    else
        bucket_fill(pixels, params, color, new_color);
    sfTexture *texture = sfTexture_create(params[2], params[3]);
    sfTexture_updateFromPixels(texture, pixels, params[2], params[3], 0, 0);
    add_element_to_texture_list(global, texture);
    sfImage_destroy(image);
}

void drawing(global_t *global)
{
    int nb_layers = 0;
    for (layer_elem_t *tmp_layer = global->layer_first;
    tmp_layer != NULL; tmp_layer = tmp_layer->next) {
        if (tmp_layer->is_visible == 1)
            nb_layers++;
    }
    global->nb_layers = nb_layers;
    if (global->nb_layers == 0)
        return;
    if (global->pencil->mode == 0)
        draw_with_pencil(global);
    if (global->pencil->mode == 1)
        draw_with_eraser(global);
    if (global->pencil->mode == 2 && global->click_release == 0) {
        if (global->nb_layers != 1)
            return;
        draw_with_bucket(global);
        display_texture_list(global);
    }
    global->click_release = 1;
}
