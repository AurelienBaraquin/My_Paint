/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** layer
*/

#include "paint.h"
#include "layer.h"

int layer_event_2(sfEvent event, layer_t *glo, int view_deplacement)
{
    if (event.mouseWheelScroll.delta > 0 && view_deplacement > 0)
        view_deplacement -= 10;
    else if (event.mouseWheelScroll.delta < 0 && view_deplacement < 60
    * glo->nb_layers - 410)
        view_deplacement += 10;
    sfRenderWindow_setView(glo->window, sfView_createFromRect((sfFloatRect)
    {0, view_deplacement, 480, 480}));
    return view_deplacement;
}

int layer_event(layer_t *glo, sfEvent event, int view_deplacement)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(glo->window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(glo->window);
    if (event.type == sfEvtLostFocus)
        sfRenderWindow_close(glo->window);
    if (event.type == sfEvtMouseWheelScrolled) {
        view_deplacement = layer_event_2(event, glo, view_deplacement);
    }
    return view_deplacement;
}

void layer_window(global_t *global)
{
    layer_t* glo = init_layer_global(global);
    global->mouse_pos = sfMouse_getPositionRenderWindow(glo->window);
    for (layer_elem_t *tmp = glo->layer_list->first; tmp->next != NULL;
    tmp = tmp->next)
        glo->nb_layers++;
    sfEvent event;
    int view_deplacement = 0;
    while (sfRenderWindow_isOpen(glo->window)) {
        while (sfRenderWindow_pollEvent(glo->window, &event)) {
            view_deplacement = layer_event(glo, event, view_deplacement);
        }
        update_layer_window(glo, view_deplacement);
        update_layer_case(glo, view_deplacement);
        update_layer(glo, view_deplacement);
        update_arrow(glo, view_deplacement);
        display_layer_window(glo);
    }
    global->layer_first = glo->layer_list->first;
}
