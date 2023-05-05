/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** theme
*/

#ifndef THEME_H_
    #define THEME_H_

    #include "paint.h"

typedef struct theme_elem_s {
    theme_t *theme;
    sfRectangleShape *rect;
    sfText *text;
    sfBool is_clicked;
    struct theme_elem_s *next;
} theme_elem_t;

typedef struct theme_space_s {
    sfRenderWindow *window;
    theme_t *theme_actual;
    theme_elem_t *theme_first;
} theme_space_t;

void draw_theme(theme_space_t *theme_win);
void verif_mouse_button_pressed(global_t *global, theme_space_t *theme_win,
theme_elem_t *tmp);
void update_theme(global_t *global, theme_space_t *theme_win,
int view_deplacement);
void theme_window(global_t *global);
int basic_event_verif(sfEvent event, theme_space_t *theme_win,
int view_deplacement);
theme_space_t* init_theme(global_t *global);
#endif /* !THEME_H_ */
