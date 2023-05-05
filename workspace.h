/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** workspace
*/

#include "paint.h"

#ifndef WORKSPACE_H_
    #define WORKSPACE_H_

typedef struct text_button_s {
    sfText *text;
    sfRectangleShape *rect;
    sfBool is_clicked;
} text_button_t;

typedef struct file_elem_s {
    text_button_t *button;
    char *name;
    struct file_elem_s *next;
} file_elem_t;

typedef struct work_s {
    sfRenderWindow *window;
    file_elem_t *file_first;
    int nb_file;
} work_t;

typedef struct save_s {
    sfRenderWindow *window;
    sfText *input;
    sfText *text;
    sfRectangleShape *rect;
    sfBool is_clicked;
    text_button_t **format;
    char *input_key;
    int *scroll;
    int format_type;
} save_t;

file_elem_t* create_file_elem(char *name);
int get_file_list(work_t *work);
work_t* init_workspace(void);
void verif_files(work_t *work, int view_deplacement,
file_elem_t *file, sfFloatRect rect);
void display_save_workspace(work_t *work);
void init_next(save_t *save, sfFont *font, sfText *text,
sfRectangleShape *rect);
save_t* init_save(void);
char *add_char_to_str(const char *str, char c);
void basic_event(sfEvent event, save_t *save);
void event_key_pressed(sfEvent event, save_t *save, global_t *global);
void draw_format_button(save_t *save);
void update_format_button(save_t *save);
void init_format(save_t *save, sfFont *font);

#endif /* !WORKSPACE_H_ */
