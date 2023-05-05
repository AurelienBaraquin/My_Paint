/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** help
*/

#include "help.h"

help_t* init_help_window(void)
{
    help_t *help = malloc(sizeof(help_t));
    help->window = sfRenderWindow_create((sfVideoMode){960, 720, 32},
    "Help", sfNone, NULL);
    sfRenderWindow_setFramerateLimit(help->window, 60);
    sfRenderWindow_setPosition(help->window, (sfVector2i){280, 180});
    help->text_first = NULL;
    help->nb_text = 0;
    text_of_help(help);
    return help;
}

void display_help_window(help_t *help)
{
    sfRenderWindow_clear(help->window, sfBlack);
    text_help_t *tmp = help->text_first;
    int i = 0;
    while (tmp != NULL) {
        sfText_setPosition(tmp->text, (sfVector2f){10, 10 + i * 50});
        sfRenderWindow_drawText(help->window, tmp->text, NULL);
        tmp = tmp->next;
        i++;
    }
    sfRenderWindow_display(help->window);
}

int help_window_event(help_t *help, sfEvent event, int view_deplacement)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(help->window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(help->window);
    if (event.type == sfEvtLostFocus)
        sfRenderWindow_close(help->window);
    if (event.type == sfEvtMouseWheelScrolled) {
        if (event.mouseWheelScroll.delta > 0 && view_deplacement > 0) {
            view_deplacement -= 10;
        }
        if (event.mouseWheelScroll.delta < 0 &&
        view_deplacement < help->nb_text * 50 - 720){
            view_deplacement += 10;
        }
        sfRenderWindow_setView(help->window,
        sfView_createFromRect((sfFloatRect){0, view_deplacement, 960, 720}));
    }
    return view_deplacement;
}

int help_window(global_t *global)
{
    help_t *help = init_help_window();
    sfEvent event;
    int view_deplacement = 0;
    while (sfRenderWindow_isOpen(help->window)) {
        while (sfRenderWindow_pollEvent(help->window, &event)) {
            view_deplacement = help_window_event(help,
            event, view_deplacement);
        }
        display_help_window(help);
    }
}
