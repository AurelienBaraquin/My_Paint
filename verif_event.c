/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** verif_event
*/

#include "paint.h"

void verif_color_pallette(global_t *global)
{
    while (((global->mouse_pos.x >= global->color_palette_pos.x - 10 &&
    global->mouse_pos.x <= global->color_palette_pos.x
    + global->color_palette_size.x + 10 &&
    global->mouse_pos.y >= global->color_palette_pos.y &&
    global->mouse_pos.y <= global->color_palette_pos.y +
    global->color_palette_size.y)
    && (global->pencil->mode == 0 || global->pencil->mode == 2))){
        int i = 0;
        change_color(global);
        i = change_i_value(global, i);
        if (i == 1)
            break;
    }
}

void change_black_color(global_t *global)
{
    global->black_pallette_pos_rect.y = global->mouse_pos.y -
    global->black_pallette_size_rect.y / 2;
    sfRectangleShape_setPosition(global->black_pallette_rect,
    global->black_pallette_pos_rect);
    sfImage* image = sfTexture_copyToImage(global->black_pallette_texture);
    sfColor pixel_color = sfImage_getPixel(image, global->mouse_pos.x -
    global->black_pallette_pos.x, global->mouse_pos.y -
    global->black_pallette_pos.y);
    sfRectangleShape_setFillColor(global->black_pallette_rect, pixel_color);
    sfImage_destroy(image);
    global->pencil->color = pixel_color;
    if (pixel_color.r == 255 && pixel_color.g == 255 && pixel_color.b == 255){
        global->pencil->color.r = 254;
        global->pencil->color.g = 254;
        global->pencil->color.b = 254;
    }
    display_f(global, 0);
    global->mouse_pos = sfMouse_getPositionRenderWindow(global->window);
}

void verif_black_pallette(global_t *global)
{
    while (((global->mouse_pos.x >= global->black_pallette_pos.x - 10 &&
    global->mouse_pos.x <= global->black_pallette_pos.x +
    global->color_palette_size.x + 10 &&
    global->mouse_pos.y >= global->black_pallette_pos.y &&
    global->mouse_pos.y <= global->black_pallette_pos.y +
    global->color_palette_size.y)
    && (global->pencil->mode == 0 || global->pencil->mode == 2))){
        int i = 0;
        change_black_color(global);
        i = change_i_value(global, i);
        if (i == 1)
            break;
    }
}

void verif_slider(global_t *global)
{
    while ((global->mouse_pos.x >= global->back_slider_pos.x &&
    global->mouse_pos.x <=
    global->back_slider_pos.x + global->back_slider_size.x &&
    global->mouse_pos.y >= global->back_slider_pos.y - 20 &&
    global->mouse_pos.y <= global->back_slider_pos.y +
    global->back_slider_size.y + 20) && (global->pencil->mode == 0 ||
    global->pencil->mode == 1)){
        int i = 0;
        change_size(global);
        global->mouse_pos = sfMouse_getPositionRenderWindow(global->window);
        i = change_i_value(global, i);
        if (i == 1)
            break;
    }
}

void verif_which_gui(global_t *global)
{
    int a = 0;
    while (1){
        mouse_on_gui(global, &a);
        update_differents_var(global);
    }
}
