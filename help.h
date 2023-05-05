/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** help
*/

#ifndef HELP_H_
    #define HELP_H_

    #include "paint.h"

typedef struct text_help_s {
    sfText *text;
    struct text_help_s *next;
} text_help_t;

typedef struct help_s {
    sfRenderWindow *window;
    text_help_t *text_first;
    int nb_text;
} help_t;

void text_of_help(help_t *help);

#endif /* !HELP_H_ */
