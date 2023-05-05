/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** settings
*/

#ifndef SETTINGS_H_
    #define SETTINGS_H_

    #include "paint.h"

typedef struct set_button_s {
    sfRectangleShape *rect;
    sfText *text;
    char *name;
    sfBool is_clicked;
} set_button_t;

typedef struct set_list_s {
    set_button_t *button;
    struct set_list_s *next;
} set_list_t;

typedef struct set_s {
    sfRenderWindow *window;
    set_list_t *list_first;
} set_t;

set_button_t* init_settings_button(set_button_t *button);
void init_settings_list(set_t *set);
set_t* init_settings(global_t *global);
void display_settings(global_t *global, set_t *set);
void if_mousebutton_pressed(set_list_t *tmp);
void update_button_settings(global_t *global, set_t *set);
int apply_diff_settings(global_t *global, set_t *set, int i);
int verif_event_basic(sfEvent event, set_t *set, global_t *global);

#endif /* !SETTINGS_H_ */
