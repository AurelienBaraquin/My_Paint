/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** help_text
*/

#include "help.h"

void add_text_to_list(help_t *help, char *str, int size)
{
    text_help_t *new_elem = malloc(sizeof(text_help_t));
    text_help_t *tmp = help->text_first;
    new_elem->text = sfText_create();
    sfText_setString(new_elem->text, str);
    sfText_setFont(new_elem->text, sfFont_createFromFile("assets/font.ttf"));
    sfText_setCharacterSize(new_elem->text, size);
    sfText_setPosition(new_elem->text, (sfVector2f){0, 0});
    help->nb_text++;
    new_elem->next = NULL;
    if (help->text_first == NULL) {
        help->text_first = new_elem;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new_elem;
}

void text_of_help_2(help_t *help)
{
    add_text_to_list(help,
    "You can clear the drawing with the clear button", 20);
    add_text_to_list(help,
    "You can change the settings with the settings button", 20);
    add_text_to_list(help,
    "You can quit the program with the quit button", 20);
    add_text_to_list(help,
    "You can go back to the main menu with the [ESCAPE] key", 20);
    add_text_to_list(help,
    "You can undo your last action with the [<-] key", 20);
    add_text_to_list(help,
    "You can redo your last action with the [->] key", 20);
    add_text_to_list(help,
    "You can change the layer with the [1] to [9] keys", 20);
    add_text_to_list(help,
    "You can access to the layer interface with the layer button",
    20);
    add_text_to_list(help,
    "You can use [UP] key to place the last layer to the first", 20);
}

void text_of_help(help_t *help)
{
    add_text_to_list(help,
    "Welcome to MyPaint", 30);
    add_text_to_list(help,
    "This is a simple paint program", 20);
    add_text_to_list(help,
    "You can draw with the mouse", 20);
    add_text_to_list(help,
    "You can change the color with the color picker", 20);
    add_text_to_list(help,
    "You can change the size of the brush with the slider", 20);
    add_text_to_list(help,
    "You can change the shape of the brush with the buttons", 20);
    add_text_to_list(help,
    "You can save your drawing with the save button", 20);
    add_text_to_list(help,
    "You can load a drawing with the load button", 20);
    text_of_help_2(help);
}
