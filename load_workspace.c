/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** save_workspace
*/

#include "workspace.h"

void update_file_list(work_t *work, global_t *global, int view_deplacement)
{
    file_elem_t *file = work->file_first;
    while (file != NULL) {
        sfFloatRect rect = sfRectangleShape_getGlobalBounds
        (file->button->rect);
        verif_files(work, view_deplacement, file, rect);
        if (file->button->is_clicked == sfTrue) {
            char *path = strcat_malloc("outputs/",
            sfText_getString(file->button->text));
            add_element_to_texture_list(global,
            load_texture_from_file(path));
            sfRenderWindow_close(work->window);
        }
        file = file->next;
    }
}

int load_right_file(work_t *work, global_t *global, sfEvent event,
int view_deplacement)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(work->window);
    if (event.type == sfEvtLostFocus)
        sfRenderWindow_close(work->window);
    if (event.type == sfEvtMouseWheelScrolled) {
        if (event.mouseWheelScroll.delta > 0 && view_deplacement > 0) {
            sfView_move((sfView *)sfRenderWindow_getView(work->window),
            (sfVector2f){0, -10});
            view_deplacement -= 10;
        }
        if (event.mouseWheelScroll.delta < 0 && view_deplacement < 60 *
        work->nb_file - 470){
            sfView_move((sfView *)sfRenderWindow_getView(work->window),
            (sfVector2f){0, 10});
            view_deplacement += 10;
        }
    }
    return view_deplacement;
}

void load_workspace(global_t *global)
{
    work_t *work = init_workspace();
    int view_deplacement = 0;
    if (work->nb_file <= 0)
        sfRenderWindow_close(work->window);
    while (sfRenderWindow_isOpen(work->window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(work->window, &event)) {
            view_deplacement = load_right_file(work, global, event,
            view_deplacement);
        }
        update_file_list(work, global, view_deplacement);
        display_save_workspace(work);
    }
}
