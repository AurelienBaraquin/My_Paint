/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** save_workspace_next
*/

#include "workspace.h"

void init_next(save_t *save, sfFont *font, sfText *text,
sfRectangleShape *rect)
{
    save->window = sfRenderWindow_create((sfVideoMode){480, 480, 32},
    "Save", sfNone, NULL);
    sfRenderWindow_setPosition(save->window, (sfVector2i){290, 184});
    save->input = sfText_create();
    sfText_setFont(save->input, font);
    sfText_setCharacterSize(save->input, 30);
    sfText_setPosition(save->input, (sfVector2f){0, 40});
    sfText_setString(save->input, "");
    save->text = text;
    save->rect = rect;
    save->is_clicked = sfFalse;
    init_format(save, font);
}

save_t* init_save(void)
{
    save_t *save = malloc(sizeof(save_t));
    sfVector2f pos = {0, 0};
    sfVector2f size = {0, 0};
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    sfText *text = sfText_create();
    sfRectangleShape *rect = sfRectangleShape_create();
    sfText_setFont(text, font);
    sfText_setString(text, "Write the name of the file:");
    sfText_setCharacterSize(text, 20);
    sfText_setPosition(text, pos);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfBlack);
    init_next(save, font, text, rect);
    return (save);
}

char *add_char_to_str(const char *str, char c)
{
    int len = my_strlen(str);
    char *new_str = malloc(sizeof(char) * (len + 2));
    for (int i = 0; i < len; i++)
        new_str[i] = str[i];
    new_str[len] = c;
    new_str[len + 1] = '\0';
    return new_str;
}

void basic_event(sfEvent event, save_t *save)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(save->window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(save->window);
    if (event.type == sfEvtLostFocus)
        sfRenderWindow_close(save->window);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code >= sfKeyA && event.key.code <= sfKeyZ) {
            sfText_setString(save->input,
            add_char_to_str(sfText_getString(save->input),
            event.key.code + 97));
        }
    }
}
