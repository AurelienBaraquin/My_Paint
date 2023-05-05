/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** save_workspace
*/

#include "workspace.h"

void other_event(sfEvent event, save_t *save, global_t *global, int len)
{
    if (event.type == sfEvtKeyPressed && event.key.code ==
    sfKeyBack && my_strlen(sfText_getString(save->input)) > 0) {
        char *str = (char *) sfText_getString(save->input);
        char *new_str = malloc(sizeof(char) * (len + 1));
        int len = my_strlen(str);
        for (int i = 0; i < len - 1; i++)
            new_str[i] = str[i];
        new_str[len - 1] = '\0';
        sfText_setString(save->input, new_str);
    }
    event_key_pressed(event, save, global);
}

void save_workspace(global_t *global)
{
    save_t *save = init_save();
    while (sfRenderWindow_isOpen(save->window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(save->window, &event)) {
            basic_event(event, save);
            other_event(event, save, global, my_strlen
            (sfText_getString(save->input)));
        }
        update_format_button(save);
        sfRenderWindow_clear(save->window, sfBlack);
        sfRenderWindow_drawText(save->window, save->text, NULL);
        sfRenderWindow_drawText(save->window, save->input, NULL);
        sfRenderWindow_drawRectangleShape(save->window, save->rect, NULL);
        draw_format_button(save);
        sfRenderWindow_display(save->window);
    }
}
