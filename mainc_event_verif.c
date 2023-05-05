/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** mainc_event_verif
*/

#include "paint.h"

void other_choosen_button(global_t *global)
{
    if ((global->chosen_button.x == 0 && global->chosen_button.y == 1)
    || (global->event.type == sfEvtKeyPressed && global->event.key.code ==
    sfKeyL && global->event.key.control)){
        global->chosen_button.x = -1;
        global->chosen_button.y = -1;
        global->event.type = sfEvtLostFocus;
        global->gui_button->first_buttons[0]->is_clicked = sfFalse;
        display_f(global, 1);
        sfSleep(sfSeconds(0.1));
        load_workspace(global);
    }
    if ((global->chosen_button.x == 0 && global->chosen_button.y == 0) ||
    (global->event.type == sfEvtKeyPressed && global->event.key.control
    && global->event.key.code == sfKeyS)){
        one_choosen_button(global);
    }
}

void key_e_and_b(global_t *global)
{
    if ((global->event.type == sfEvtKeyPressed &&
    global->event.key.code == sfKeyE)
    || (global->chosen_button.x == 1 && global->chosen_button.y == 0)){
        global->pencil->mode = 1;
        global->chosen_button.x = 1;
        global->chosen_button.y = 0;
    }
    if ((global->event.type == sfEvtKeyPressed &&
    global->event.key.code == sfKeyB) ||
    (global->chosen_button.x == 1 && global->chosen_button.y == 1)){
        global->pencil->mode = 2;
        global->chosen_button.x = 1;
        global->chosen_button.y = 1;
    }
}

void chosen_key_elem(global_t *global)
{
    if ((global->event.type == sfEvtKeyPressed &&
    global->event.key.code == sfKeyP) || (global->chosen_button.x == 1
    && global->chosen_button.y == 2)){
        global->pencil->mode = 0;
        global->chosen_button.x = 1;
        global->chosen_button.y = 2;
    }
    key_e_and_b(global);
    other_choosen_button(global);
    verif_event(global);
    layer_event_main(global, global->event);
}

void verif_event(global_t *global)
{
    if (global->event.type == sfEvtResized)
        sfRenderWindow_setView(global->window,
        sfView_createFromRect((sfFloatRect){0, 0,
        global->event.size.width, global->event.size.height}));
    if (global->event.type == sfEvtKeyPressed &&
    global->event.key.code == sfKeyD)
        global->theme = get_theme("dark");
    if (global->event.type == sfEvtKeyPressed &&
    global->event.key.code == sfKeyF)
        global->theme = get_theme("light");
    if (global->event.type == sfEvtKeyPressed &&
    global->event.key.code == sfKeyRight)
        redo_texture_list(global);
    settings_verif_event(global);
}

void event_verif(global_t *global)
{
    verif_key_layers(global);
    if (global->event.type == sfEvtClosed)
        close_windows(global);
    if (global->event.type == sfEvtKeyPressed &&
    global->event.key.code == sfKeyEscape)
        close_windows(global);
    if (global->event.type == sfEvtMouseButtonPressed &&
    global->event.mouseButton.button == sfMouseLeft){
        verif_is_clicked_button(global);
    }
    if (global->event.type == sfEvtKeyPressed &&
    global->event.key.code == sfKeySpace){
        remove_layer(global);
    }
    if (global->event.type == sfEvtKeyPressed &&
    global->event.key.code == sfKeyLeft)
        remove_last_element_from_texture_list(global);
    chosen_key_elem(global);
}
