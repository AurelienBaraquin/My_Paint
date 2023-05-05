/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** save_in_file
*/

#include "paint.h"

void save_theme(global_t *global)
{
    int fd = open("save/theme_save", O_CREAT | O_WRONLY | O_TRUNC, 0666);
    write(fd, global->theme->name, my_strlen(global->theme->name));
    close(fd);
}

void save_in_file(global_t *global)
{
    save_theme(global);
}
