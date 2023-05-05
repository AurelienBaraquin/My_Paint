/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** settings_selection
*/

#include "settings.h"

void fps_settings(global_t *global, set_t *set)
{
    sfSleep(sfSeconds(0.2));
    int fps = 0;
    for (int i = 0; fps <= 0; i++) {
        if (i > 0)
            fps = get_nbr(get_text_input(set->window
            ,(sfVector2f){0, 0} , "Enter a valid FPS: "));
        else
            fps = get_nbr(get_text_input(set->window
            ,(sfVector2f){0, 0} , "Enter the FPS you want: "));
    }
    global->fps = fps;
    sfRenderWindow_close(set->window);
}

int apply_diff_settings(global_t *global, set_t *set, int i)
{
    if (i == 0) {
        sfRenderWindow_close(set->window);
        sfSleep(sfSeconds(0.2));
        theme_window(global);
        return 1;
    }
    if (i == 1) {
        fps_settings(global, set);
        return 1;
    }
    if (i == 2) {
        sfRenderWindow_close(set->window);
        sfSleep(sfSeconds(0.2));
        help_window(global);
        return 1;
    }
}
