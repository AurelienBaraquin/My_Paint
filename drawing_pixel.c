/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** drawing_pixel
*/

#include "paint.h"

int get_pixel_index(int x, int y, int width)
{
    return 4 * (x + y * width);
}

int place_pixel(sfUint8 *pixels, int index , sfColor color)
{
    pixels[index] = color.r;
    pixels[index + 1] = color.g;
    pixels[index + 2] = color.b;
    pixels[index + 3] = color.a;
    return (0);
}

sfColor get_pixel_color(sfUint8 *pixels, int x, int y, int width)
{
    int index = get_pixel_index(x, y, width);
    sfColor color = {pixels[index], pixels[index + 1],
    pixels[index + 2], pixels[index + 3]};
    return (color);
}

void append_on_vertrex(global_t *global, int mouse_x, int mouse_y, int i)
{
    for (int j = 0; j < global->size; j++) {
        global->point[i][j].position = (sfVector2f){
            i + mouse_x - global->size / 2, j + mouse_y - global->size / 2};
        sfVertexArray_append(global->vertices[i][j], global->point[i][j]);
        global->point[i][j].color = global->pencil->color;
    }
}

void draw_with_pencil(global_t *global)
{
    int mouse_x = global->mouse_pos.x;
    int mouse_y = global->mouse_pos.y;
    if (global->occurence == 20) {
        for (int i = 0; i < global->size; i++) {
            append_on_vertrex(global, mouse_x, mouse_y, i);
        }
        global->occurence = 0;
    }
    global->occurence++;
}
