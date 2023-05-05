/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** settings
*/

#include "settings.h"

set_button_t *buttons[] = {
    &(set_button_t){NULL, NULL, "Theme", sfFalse},
    &(set_button_t){NULL, NULL, "FPS", sfFalse},
    &(set_button_t){NULL, NULL, "Help", sfFalse},
    NULL
};

set_button_t* init_settings_button(set_button_t *button)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(button->rect, (sfVector2f){460, 50});
    sfRectangleShape_setFillColor(button->rect, sfBlack);
    sfRectangleShape_setOutlineColor(button->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(button->rect, 2);
    button->text = sfText_create();
    sfText_setString(button->text, button->name);
    sfText_setFont(button->text, sfFont_createFromFile("assets/font.ttf"));
    sfText_setCharacterSize(button->text, 30);
    return button;
}

void init_settings_list(set_t *set)
{
    set_list_t *list = malloc(sizeof(set_list_t));
    set_list_t *tmp = list;
    int i = 0;
    while (buttons[i] != NULL) {
        tmp->button = buttons[i];
        tmp->button = init_settings_button(tmp->button);
        tmp->next = malloc(sizeof(set_list_t));
        tmp = tmp->next;
        i++;
    }
    tmp->next = NULL;
    set->list_first = list;
}

int apply_settings(global_t *global, set_t *set)
{
    set_list_t *tmp = set->list_first;
    int i = 0;
    while (tmp->next != NULL) {
        if (tmp->button->is_clicked == sfTrue) {
            apply_diff_settings(global, set, i);
        }
        tmp = tmp->next;
        i++;
    }
    return 0;
}

void destroy_settings(set_t *set)
{
    set_list_t *tmp = set->list_first;
    while (tmp->next != NULL) {
        sfRectangleShape_destroy(tmp->button->rect);
        sfText_destroy(tmp->button->text);
        tmp->button->is_clicked = sfFalse;
        tmp = tmp->next;
    }
    sfRenderWindow_destroy(set->window);
    free(set);
}

void settings_main(global_t *global)
{
    set_t *set = init_settings(global);
    sfEvent event;
    while (sfRenderWindow_isOpen(set->window)) {
        while (sfRenderWindow_pollEvent(set->window, &event)) {
            verif_event_basic(event, set, global);
        }
        apply_settings(global, set);
        update_button_settings(global, set);
        display_settings(global, set);
    }
    destroy_settings(set);
}
