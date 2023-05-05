/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** main
*/

#include "paint.h"

void close_windows(global_t *global)
{
    sfThread_terminate(global->thread2);
    sfSleep(sfSeconds(0.1));
    sfRenderWindow_close(global->window);
}

void one_choosen_button(global_t *global)
{
    global->chosen_button.x = -1;
    global->chosen_button.y = -1;
    global->event.type = sfEvtLostFocus;
    global->gui_button->first_buttons[0]->is_clicked = sfFalse;
    display_f(global, 1);
    save_workspace(global);
    sfSleep(sfSeconds(0.1));
}

int main(int ac, char **av)
{
    global_t *global = init_all();
    if (ac != 1 && my_strcmp(av[1], "-h") == 0) {
        sfRenderWindow_close(global->window);
        return help_window(global);
    }
    while (sfRenderWindow_isOpen(global->window)) {
        update_mouse_pos(global);
        while (sfRenderWindow_pollEvent(global->window, &global->event)) {
            event_verif(global);
        }
        display_f(global, 0);
        update_gui(global);
        global->mouse_pos = sfMouse_getPositionRenderWindow(global->window);
    }
    save_in_file(global);
    destroy_f(global);
    sfThread_terminate(global->thread2);
    return 0;
}
