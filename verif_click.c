/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** verif_click
*/

#include "paint.h"

int verif_button_clicked(ptrect_t **button, int nb_button)
{
    for (int i = 0; i < nb_button; i++) {
        if (button[i]->is_clicked == sfTrue)
            return (i);
    }
    return (-1);
}

void verif_click_realised_2(global_t *global)
{
    if (global->nb_layers > 1)
        display_f(global, 2);
    add_element_to_texture_list(global,
    screen_window_to_texture(global));
    display_f(global, 1);
}

void verif_click_realised(global_t *global)
{
    if (global->click_release == 1) {
        global->click_release = 0;
        if (global->pencil->mode != 2) {
            verif_click_realised_2(global);
        }
        clear_array_vertex(global);
    }
}
