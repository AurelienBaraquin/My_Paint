/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** bucket_draw
*/

#include "paint.h"

int compare_color(sfColor color1, sfColor color2)
{
    if (color1.a <= color2.a + 25 && color1.a >= color2.a - 25 &&
    color1.r <= color2.r + 25 && color1.r >= color2.r - 25 &&
    color1.g <= color2.g + 25 && color1.g >= color2.g - 25 &&
    color1.b <= color2.b + 25 && color1.b >= color2.b - 25)
        return 1;
    return 0;
}

void append_on_vertex_erased(global_t *global, int mouse_x, int mouse_y, int i)
{
    int size = global->size;
    for (int j = 0; j < size; j++) {
        global->point[i][j].position = (sfVector2f) {i + mouse_x, j + mouse_y};
        sfVertexArray_append(global->vertices[i][j], global->point[i][j]);
        global->point[i][j].color = sfColor_fromRGBA(254, 254, 254, 255);
    }
}

void draw_with_eraser(global_t *global)
{
    int size = global->size;
    int mouse_x = global->mouse_pos.x;
    int mouse_y = global->mouse_pos.y;
    if (global->occurence == 20) {
        for (int i = 0; i < size; i++) {
            append_on_vertex_erased(global, mouse_x, mouse_y, i);
        }
        global->occurence = 0;
    }
    global->occurence++;
}

int **verif_stack(int *stack, int *parms_two, int top, int *params)
{
    int **stack_two = malloc(sizeof(int *) * 2);
    if (parms_two[0] > 221) {
        stack[top++] = parms_two[0] - 1;
        stack[top++] = parms_two[1];
    }
    if (parms_two[0] < params[2] - 1) {
        stack[top++] = parms_two[0] + 1;
        stack[top++] = parms_two[1];
    }
    if (parms_two[1] > 121) {
        stack[top++] = parms_two[0];
        stack[top++] = parms_two[1] - 1;
    }
    if (parms_two[1] < params[3] - 1) {
        stack[top++] = parms_two[0];
        stack[top++] = parms_two[1] + 1;
    }
    stack_two[0] = stack;
    stack_two[1] = &top;
    return stack_two;
}

void bucket_fill(sfUint8 *pixels, int *params,
sfColor old_color, sfColor new_color)
{
    int size = params[2] * params[3], top = 0;
    int *stack = malloc(sizeof(int) * size * 2);
    stack[top++] = params[0], stack[top++] = params[1];
    while (top > 0) {
        int py = stack[--top];
        int px = stack[--top];
        int idx = py * params[2] + px;
        if (compare_color(get_pixel_color(pixels, px, py, params[2]),
        old_color) == 0) {
            continue;
        }
        int index = get_pixel_index(px, py, params[2]);
        place_pixel(pixels, index, new_color);
        int *parms_two = malloc(sizeof(int) * 2);
        parms_two[0] = px;
        parms_two[1] = py;
        int **stack_two = verif_stack(stack, parms_two, top, params);
        stack = stack_two[0];
        top = *stack_two[1];
    }
}
