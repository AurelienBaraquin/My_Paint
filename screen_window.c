/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** screen_window
*/

#include "paint.h"

sfImage *screen_window_to_image(global_t *global)
{
    return sfRenderWindow_capture(global->window);
}

sfTexture* screen_window_to_texture(global_t *global)
{
    sfImage *image = screen_window_to_image(global);
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    sfImage_destroy(image);
    return texture;
}
