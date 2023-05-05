/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** settings_verif
*/

#include "settings.h"

int verif_event_basic(sfEvent event, set_t *set, global_t *global)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(set->window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(set->window);
    if (event.type == sfEvtLostFocus){
        sfRenderWindow_close(set->window);
    }
    return 0;
}
