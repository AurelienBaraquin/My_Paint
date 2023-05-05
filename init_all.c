/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** init_all
*/

#include "paint.h"

void init_gui_specific(ptrect_t *gui, sfVector2f pos,
sfVector2f size, sfColor color)
{
    gui->pos = pos;
    gui->size = size;
    gui->color = color;
    gui->rect = sfRectangleShape_create();
    gui->is_clicked = sfFalse;
    gui->is_hovered = sfFalse;
}

ptrect_t** init_gui(int nb, global_t *global)
{
    ptrect_t **gui = malloc(sizeof(ptrect_t *) * nb);
    for (int i = 0; i < nb; i++) {
        gui[i] = malloc(sizeof(ptrect_t));
        gui[i]->pos = (sfVector2f){0, 0};
        gui[i]->size = (sfVector2f){0, 0};
        gui[i]->color = global->theme->color_button;
        gui[i]->rect = sfRectangleShape_create();
        gui[i]->is_clicked = sfFalse;
        gui[i]->is_hovered = sfFalse;
    }
    return gui;
}

void init_gui_button_specific(gui_button_t *gui_button, global_t *global)
{
    for (int i = 0; i < gui_button->nb_first_buttons; i++) {
        for (int j = 0; j < gui_button->nb_seg_buttons[i]; j++) {
            init_gui_specific(gui_button->seg_buttons[i][j],
            (sfVector2f){100 * i + 221 + 10 * i, 100 * j + 100},
            (sfVector2f){100, 100}, (sfColor){30 + 20 * j, 0, 30 * j, 255});
        }
        init_gui_specific(gui_button->first_buttons[i],
        (sfVector2f){100 * i + 221  + 10 * i, 0}, (sfVector2f){100, 100},
        global->theme->color_button);
    }
    global->is_launched2 = sfFalse;
    global->thread2 = sfThread_create((void *)&verif_which_gui, global);
    global->settings = 0;
    global->clock = sfClock_create();
}

gui_button_t* init_gui_button(int nb_first_button,
int *nb_seg_button, global_t *global)
{
    gui_button_t *gui_button = malloc(sizeof(gui_button_t));
    gui_button->nb_first_buttons = nb_first_button;
    gui_button->seg_buttons = malloc(sizeof(ptrect_t **) *
    gui_button->nb_first_buttons);
    gui_button->first_buttons = init_gui(gui_button->nb_first_buttons, global);
    gui_button->nb_seg_buttons = malloc(sizeof(int) *
    gui_button->nb_first_buttons);
    for (int i = 0; i < gui_button->nb_first_buttons; i++)
        gui_button->nb_seg_buttons[i] = nb_seg_button[i];
    for (int i = 0; i < gui_button->nb_first_buttons; i++) {
        gui_button->seg_buttons[i] =
        init_gui(gui_button->nb_seg_buttons[i], global);
    }
    return gui_button;
}

global_t* init_all(void)
{
    global_t *global = malloc(sizeof(global_t));
    global->theme = get_theme_from_file("save/theme_save");
    global->layer_first = create_layer_elem("default");
    global->layer_first->next = NULL;
    init_gui_all(global);
    init_window_and_mouse(global);
    init_pencil(global);
    init_sprits(global);
    global->size = 30;
    init_vertex(global);
    global->settings_sprite = sfSprite_create();
    global->settings_texture = sfTexture_createFromFile("assets/settings.png",
    NULL);
    sfSprite_setTexture(global->settings_sprite, global->settings_texture,
    sfTrue);
    sfSprite_setPosition(global->settings_sprite, (sfVector2f){0, 0});
    sfSprite_setScale(global->settings_sprite, (sfVector2f){0.25, 0.25});
    return global;
}
