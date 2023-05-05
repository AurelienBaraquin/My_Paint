/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** destroy
*/

#include "paint.h"

void destroy_f(global_t *global)
{
    for (int i = 0; i < 3; i++) {
        sfRectangleShape_destroy(global->gui[i]->rect);
        free(global->gui[i]);
    }
    free(global->gui);
    sfRenderWindow_destroy(global->window);
    free(global);
}
