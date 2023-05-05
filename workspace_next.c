/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** workspace_next
*/
#include "workspace.h"

file_elem_t* create_file_elem(char *name)
{
    file_elem_t *file = malloc(sizeof(file_elem_t));
    file->button = malloc(sizeof(text_button_t));
    file->button->text = sfText_create();
    file->button->rect = sfRectangleShape_create();
    file->button->is_clicked = sfFalse;
    sfText_setString(file->button->text, name);
    sfText_setFont(file->button->text,
    sfFont_createFromFile("./assets/font.ttf"));
    sfText_setCharacterSize(file->button->text, 20);
    sfRectangleShape_setSize(file->button->rect, (sfVector2f){460, 50});
    sfRectangleShape_setFillColor(file->button->rect, sfBlack);
    sfRectangleShape_setOutlineColor(file->button->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(file->button->rect, 2);
    file->name = name;
    return file;
}

int get_file_list(work_t *work)
{
    int nb_file = 0;
    DIR *dir;
    struct dirent *file;
    if (opendir("./outputs/") == NULL) {
        my_putstr("Error: ./outputs/ doesn't exist\n");
        return -1;
    }
    dir = opendir("./outputs/");
    while ((file = readdir(dir)) != NULL) {
        if (file->d_name[0] != '.') {
            file_elem_t *new_file = create_file_elem(file->d_name);
            new_file->next = work->file_first;
            work->file_first = new_file;
            nb_file++;
        }
    }
    closedir(dir);
    return nb_file;
}

work_t* init_workspace(void)
{
    work_t *work = malloc(sizeof(work_t));
    work->window = sfRenderWindow_create((sfVideoMode){480, 480, 32},
    "MyPaint", sfNone, NULL);
    sfRenderWindow_setPosition(work->window, (sfVector2i){290, 184});
    sfRenderWindow_setFramerateLimit(work->window, 60);
    work->file_first = NULL;
    work->nb_file = get_file_list(work);
    return work;
}

void display_save_workspace(work_t *work)
{
    sfRenderWindow_setView(work->window, sfRenderWindow_getView(work->window));
    sfRenderWindow_clear(work->window, sfBlack);
    file_elem_t *file = work->file_first;
    int i = 0;
    while (file != NULL) {
        sfRectangleShape_setPosition(file->button->rect,
        (sfVector2f){10, 10 + i * 60});
        sfText_setPosition(file->button->text, (sfVector2f){20, 10 + i * 60 +
        25 - sfText_getLocalBounds(file->button->text).height / 2});
        sfRenderWindow_drawRectangleShape(work->window, file->button->rect,
        NULL);
        sfRenderWindow_drawText(work->window, file->button->text, NULL);
        file = file->next;
        i++;
    }
    sfRenderWindow_display(work->window);
}

void verif_files(work_t *work, int view_deplacement,
file_elem_t *file, sfFloatRect rect)
{
    if (sfFloatRect_contains(&rect,
    sfMouse_getPositionRenderWindow(work->window).x,
    sfMouse_getPositionRenderWindow(work->window).y +
    view_deplacement)) {
        sfRectangleShape_setFillColor(file->button->rect, sfWhite);
        sfText_setColor(file->button->text, sfBlack);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            file->button->is_clicked = sfTrue;
        }
    } else {
        sfRectangleShape_setFillColor(file->button->rect, sfBlack);
        sfText_setColor(file->button->text, sfWhite);
    }
}
