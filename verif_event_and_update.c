/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** verif_event_and_update
*/

#include "paint.h"

void change_color(global_t *global)
{
    global->color_palette_pos_rect.y = global->mouse_pos.y -
    global->color_palette_size_rect.y / 2;
    sfRectangleShape_setPosition(global->color_palette_rect,
    global->color_palette_pos_rect);
    sfImage* image = sfTexture_copyToImage(global->color_palette_texture);
    sfColor pixel_color = sfImage_getPixel(image, global->mouse_pos.x -
    global->color_palette_pos.x, global->mouse_pos.y -
    global->color_palette_pos.y);
    sfRectangleShape_setFillColor(global->color_palette_rect, pixel_color);
    global->pencil->color = pixel_color;
    sfImage_destroy(image);
    display_f(global, 0);
    global->mouse_pos = sfMouse_getPositionRenderWindow(global->window);
}

void pieptte_next(global_t *global)
{
    for (int i = 0; i < global->gui_button->nb_first_buttons; i++) {
        if (global->gui_button->first_buttons[i]->is_clicked == sfTrue) {
            global->gui_button->first_buttons[i]->is_clicked = sfFalse;
        }
    }
    global->mouse_pos = sfMouse_getPositionRenderWindow(global->window);
    sfImage *image1 = screen_window_to_image(global);
    global->pencil->color = sfImage_getPixel(image1,
    global->mouse_pos.x, global->mouse_pos.y);
    sfRectangleShape_setFillColor(global->colors_rect,
    global->pencil->color);
    sfImage_destroy(image1);
}

int pipette(global_t *global)
{
    pieptte_next(global);
    if (global->event.type == sfEvtMouseButtonPressed){
        global->pipette = 0;
        sfImage *image = screen_window_to_image(global);
        global->pencil->color = sfImage_getPixel(image,
        global->mouse_pos.x, global->mouse_pos.y);
        if (global->pencil->color.r == 255 &&
        global->pencil->color.g == 255 && global->pencil->color.b == 255){
            global->pencil->color.r = 254;
            global->pencil->color.g = 254;
            global->pencil->color.b = 254;
        }
        sfRectangleShape_setFillColor(global->colors_rect,
        global->pencil->color);
        sfImage_destroy(image);
        return 1;
    }
    display_f(global, 1);
    return 0;
}

void verif_click_next(global_t *global)
{
    for (int i = 0; i < global->gui_button->nb_first_buttons; i++) {
        if (global->gui_button->first_buttons[i]->is_clicked == sfTrue) {
            verif_event_under_window(global, i);
            global->event.type = sfEvtMouseButtonReleased;
        }
    }
    for (int i = 0; i < global->gui_button->nb_first_buttons; i++) {
        if (verif_coord(global, i) == sfTrue) {
            global->gui_button->first_buttons[i]->is_clicked = sfTrue;
        } else {
            global->gui_button->first_buttons[i]->is_clicked = sfFalse;
        }
    }
    verif_slider(global);
    verif_color_pallette(global);
    verif_black_pallette(global);
}

void verif_is_clicked_button(global_t *global)
{
    if (global->mouse_pos.x >= global->colors_pos_rect.x &&
    global->mouse_pos.x <= global->colors_pos_rect.x + 40 &&
    global->mouse_pos.y >= global->colors_pos_rect.y &&
    global->mouse_pos.y <= global->colors_pos_rect.y + 40) {
        global->pipette = 1;
        return;
    }
    while (global->pipette == 1) {
        if (pipette(global) == 1)
            return;
    }
    verif_click_next(global);
}
