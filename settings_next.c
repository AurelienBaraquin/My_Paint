/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** settings_next
*/

#include "settings.h"

void update_button_settings(global_t *global, set_t *set)
{
    set_list_t *tmp = set->list_first;
    int i = 0;
    while (tmp->next != NULL) {
        sfFloatRect rect = sfRectangleShape_getGlobalBounds(tmp->button->rect);
        if (sfFloatRect_contains(&rect,
        sfMouse_getPositionRenderWindow(set->window).x,
        sfMouse_getPositionRenderWindow(set->window).y)) {
            if_mousebutton_pressed(tmp);
        } else {
            sfRectangleShape_setFillColor(tmp->button->rect, sfBlack);
            sfText_setColor(tmp->button->text, sfWhite);
        }
        tmp = tmp->next;
        i++;
    }
}

set_t* init_settings(global_t *global)
{
    set_t *set = malloc(sizeof(set_t));
    set->window = sfRenderWindow_create((sfVideoMode){480, 480, 32},
    "Settings", (sfUint32)(sfNone), NULL);
    sfRenderWindow_setFramerateLimit(set->window, 60);
    sfRenderWindow_setPosition(set->window, (sfVector2i){290, 184});
    set->list_first = NULL;
    init_settings_list(set);
    return set;
}

void display_settings(global_t *global, set_t *set)
{
    sfRenderWindow_clear(set->window, sfBlack);
    set_list_t *tmp = set->list_first;
    int i = 0;
    while (tmp->next != NULL) {
        sfRectangleShape_setPosition(tmp->button->rect,
        (sfVector2f){10, 10 + (i * 100)});
        sfText_setPosition(tmp->button->text, (sfVector2f){10 + 100 -
        (sfText_getLocalBounds(tmp->button->text).width / 2),
        10 + (i * 100) + 10});
        sfRenderWindow_drawRectangleShape(set->window,
        tmp->button->rect, NULL);
        sfRenderWindow_drawText(set->window, tmp->button->text, NULL);
        tmp = tmp->next;
        i++;
    }
    sfRenderWindow_display(set->window);
}

void if_mousebutton_pressed(set_list_t *tmp)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        tmp->button->is_clicked = sfTrue;
    else
        tmp->button->is_clicked = sfFalse;
    sfRectangleShape_setFillColor(tmp->button->rect, sfWhite);
    sfText_setColor(tmp->button->text, sfBlack);
}
