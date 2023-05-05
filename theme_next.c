/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** theme_next
*/

#include "theme.h"

void draw_theme(theme_space_t *theme_win)
{
    sfRenderWindow_clear(theme_win->window, sfBlack);
    theme_elem_t *tmp = theme_win->theme_first;
    int i = 0;
    while (tmp->theme != NULL) {
        sfRectangleShape_setPosition(tmp->rect, (sfVector2f){10,
        (i * 50) + (i * 10) + 10});
        sfText_setPosition(tmp->text, (sfVector2f){20,
        (i * 50) + (i * 10) + 20});
        sfRenderWindow_drawRectangleShape(theme_win->window, tmp->rect, NULL);
        sfRenderWindow_drawText(theme_win->window, tmp->text, NULL);
        tmp = tmp->next;
        i++;
    }
    sfRenderWindow_display(theme_win->window);
}

void verif_mouse_button_pressed(global_t *global, theme_space_t *theme_win,
theme_elem_t *tmp)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        global->theme = tmp->theme;
        sfRenderWindow_close(theme_win->window);
    }
}

void update_theme(global_t *global, theme_space_t *theme_win,
int view_deplacement)
{
    theme_elem_t *tmp = theme_win->theme_first;
    int i = 0;
    while (tmp->theme != NULL) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(theme_win->window);
        sfFloatRect rect = sfRectangleShape_getGlobalBounds(tmp->rect);
        if (sfFloatRect_contains
        (&rect, mouse.x, mouse.y + view_deplacement)) {
            sfRectangleShape_setFillColor(tmp->rect, sfWhite);
            sfText_setColor(tmp->text, sfBlack);
            verif_mouse_button_pressed(global, theme_win, tmp);
        } else {
            sfRectangleShape_setFillColor(tmp->rect, sfBlack);
            sfText_setColor(tmp->text, sfWhite);
        }
        tmp = tmp->next;
        i++;
    }
}

int basic_event_verif(sfEvent event, theme_space_t *theme_win,
int view_deplacement)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(theme_win->window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(theme_win->window);
    if (event.type == sfEvtLostFocus)
        sfRenderWindow_close(theme_win->window);
    if (event.type == sfEvtMouseWheelScrolled) {
        if (event.mouseWheelScroll.delta > 0 && view_deplacement > 0) {
            view_deplacement -= 10;
        }
        if (event.mouseWheelScroll.delta < 0 &&
        view_deplacement < 60 * 13 - 470){
            view_deplacement += 10;
        }
        sfRenderWindow_setView(theme_win->window,
        sfView_createFromRect((sfFloatRect){0, view_deplacement, 480, 480}));
    }
    return view_deplacement;
}

void theme_window(global_t *global)
{
    theme_space_t *theme_win = init_theme(global);
    sfEvent event;
    int view_deplacement = 0;
    while (sfRenderWindow_isOpen(theme_win->window)) {
        while (sfRenderWindow_pollEvent(theme_win->window, &event)) {
            view_deplacement = basic_event_verif(event, theme_win,
            view_deplacement);
        }
        update_theme(global, theme_win, view_deplacement);
        draw_theme(theme_win);
    }
}
