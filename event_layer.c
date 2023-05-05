/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** layer_event
*/

#include "paint.h"

void move_the_last_to_the_first_layer(global_t *global)
{
    layer_elem_t *tmp = global->layer_first;
    layer_elem_t *last = global->layer_first;
    layer_elem_t *before_last = global->layer_first;
    if (tmp->next == NULL)
        return;
    while (tmp->next != NULL) {
        before_last = tmp;
        tmp = tmp->next;
    }
    last = tmp;
    before_last->next = NULL;
    last->next = global->layer_first;
    global->layer_first = last;
}

void move_the_first_to_the_last_layer(global_t *global)
{
    layer_elem_t *tmp = global->layer_first;
    layer_elem_t *last = global->layer_first;
    if (tmp->next == NULL)
        return;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    last = global->layer_first;
    global->layer_first = global->layer_first->next;
    last->next = NULL;
    tmp->next = last;
}

void switch_layer_state(global_t *global, sfEvent event)
{
    layer_elem_t *tmp = global->layer_first;
    for (int i = 0; i < event.key.code - sfKeyNum1; i++) {
        if (tmp->next != NULL)
            tmp = tmp->next;
        else
            return;
    }
    tmp->is_visible = !tmp->is_visible;
    return;
}

void layer_event_main(global_t *global, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code >= sfKeyNum1
    && event.key.code <= sfKeyNum9) {
        switch_layer_state(global, event);
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
        move_the_last_to_the_first_layer(global);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
        move_the_first_to_the_last_layer(global);
}
