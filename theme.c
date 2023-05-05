/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** theme
*/

#include "theme.h"

theme_t theme[] = {
    {"poop", (sfColor){19, 14, 10, 255},
    (sfColor){63, 34, 4, 255}, (sfColor){63, 34, 4, 255}},
    {"louis", (sfColor){160, 121, 121, 255},
    (sfColor){128, 128, 0, 255}, (sfColor){173, 79, 9, 255}},
    {"default", (sfColor){160, 40, 200, 255},
    (sfColor){178, 190, 181, 255}, (sfColor){178, 190, 181, 255}},
    {"dark", (sfColor){40, 40, 40, 255},
    (sfColor){60, 60, 60, 255}, (sfColor){80, 80, 80, 255}},
    {"light", (sfColor){200, 200, 200, 255},
    (sfColor){255, 255, 255, 255}, (sfColor){221, 221, 221, 255}},
    {"amethyste", (sfColor){136, 77, 167, 255},
    (sfColor){223, 115, 255, 255}, (sfColor){182, 102, 210, 255}},
    {"red", (sfColor){0, 0, 0, 255},
    (sfColor){255, 0, 0, 255}, (sfColor){255, 0, 0, 255}},
    {"green", (sfColor){0, 0, 0, 255},
    (sfColor){0, 255, 0, 255}, (sfColor){0, 255, 0, 255}},
    {"cherry", (sfColor){222, 49, 99, 255},
    (sfColor){254, 231, 240, 255}, (sfColor){255, 228, 196, 255}},
    {"blue", (sfColor){0, 0, 0, 255},
    (sfColor){0, 0, 255, 255}, (sfColor){0, 0, 255, 255}},
    {"blood", (sfColor){191, 48, 48, 255},
    (sfColor){115, 8, 0, 255}, (sfColor){133, 6, 6, 255}},
    {"wheat", (sfColor){24, 57, 30, 255},
    (sfColor){223, 255, 0, 255}, (sfColor){158, 253, 56, 255}},
    {"carrot", (sfColor){221, 152, 92, 255},
    (sfColor){223, 109, 20, 255}, (sfColor){20, 148, 20, 255}},
    NULL
};

theme_t* get_theme(char *name)
{
    for (int i = 0; i < 13; i++) {
        if (my_strcmp(name, theme[i].name) == 0)
            return &theme[i];
    }
    return &theme[0];
}

theme_t* get_theme_from_file(char *path)
{
    int fd = open(path, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 100);
    read(fd, buffer, 100);
    close(fd);
    return get_theme(buffer);
}

theme_elem_t* add_theme(theme_elem_t *theme_first, theme_t *theme)
{
    theme_elem_t *new = malloc(sizeof(theme_elem_t));
    new->theme = theme;
    new->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(new->rect, (sfVector2f){460, 50});
    sfRectangleShape_setFillColor(new->rect, sfBlack);
    sfRectangleShape_setOutlineColor(new->rect, theme->color_body);
    sfRectangleShape_setOutlineThickness(new->rect, 2);
    new->text = sfText_create();
    sfText_setString(new->text, theme->name);
    sfText_setFont(new->text, sfFont_createFromFile("assets/font.ttf"));
    sfText_setCharacterSize(new->text, 30);
    sfText_setColor(new->text, sfWhite);
    new->next = theme_first;
    return new;
}

void init_theme_list(global_t *global, theme_space_t *theme_win)
{
    theme_win->theme_first = malloc(sizeof(theme_elem_t));
    theme_win->theme_first->theme = NULL;
    for (int i = 0; i < 13; i++) {
        theme_win->theme_first =
        add_theme(theme_win->theme_first, get_theme(theme[i].name));
    }
}

theme_space_t* init_theme(global_t *global)
{
    theme_space_t *theme_win = malloc(sizeof(theme_space_t));
    theme_win->window = sfRenderWindow_create((sfVideoMode){480, 480, 32},
    "Theme", sfNone, NULL);
    sfRenderWindow_setFramerateLimit(theme_win->window, 60);
    sfRenderWindow_setPosition(theme_win->window, (sfVector2i){290, 184});
    theme_win->theme_actual = global->theme;
    init_theme_list(global, theme_win);
    return theme_win;
}
