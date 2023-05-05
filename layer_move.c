/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** layer_move
*/

#include "layer.h"

void move_layer_prev_in_list(layer_list_t *layer_list, int index)
{
    if (index == 0)
        return;
    layer_elem_t *tmp = layer_list->first;
    layer_elem_t *prev = NULL;
    layer_elem_t *prev_prev = NULL;
    int i = 0;
    for (; i < index; i++) {
        prev_prev = prev;
        prev = tmp;
        tmp = tmp->next;
    }
    if (prev_prev == NULL) {
        layer_list->first = tmp;
        prev->next = tmp->next;
        tmp->next = prev;
        return;
    }
    prev_prev->next = tmp;
    prev->next = tmp->next;
    tmp->next = prev;
}

void remove_layer_from_list(layer_list_t *layer_list, int index)
{
    layer_elem_t *tmp = layer_list->first;
    layer_elem_t *prev = NULL;
    int i = 0;
    while (tmp != NULL) {
        if (i == index && prev == NULL) {
            layer_list->first = tmp->next;
            free(tmp);
            return;
        }
        if (i == index) {
            prev->next = tmp->next;
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
        i++;
    }
}

void add_layer_to_list(layer_list_t *list, char *name)
{
    layer_elem_t *elem = list->first;
    while (elem->next != NULL)
        elem = elem->next;
    elem->next = create_layer_elem(name);
}
