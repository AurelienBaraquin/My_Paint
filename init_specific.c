/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** init_specific
*/

#include "paint.h"

void init_pencil(global_t *global)
{
    global->win_texture = sfTexture_create(1920, 1080);
    global->win_sprite = sfSprite_create();
    sfSprite_setTexture(global->win_sprite, global->win_texture, sfTrue);
    global->pencil = malloc(sizeof(pencil_t));
    global->pencil->size = 4;
    global->pencil->color = (sfColor){0, 0, 0, 255};
    global->pencil->mode = 0;
}

void init_gui_all(global_t *global)
{
    global->gui = init_gui(3, global);
    init_gui_specific(global->gui[0], (sfVector2f){0, 0},
    (sfVector2f){1920, 100}, global->theme->color_header);
    init_gui_specific(global->gui[1], (sfVector2f){0, 121},
    (sfVector2f){200, 980}, global->theme->color_body);
    init_gui_specific(global->gui[2], (sfVector2f){221, 121},
    (sfVector2f){1920 - 121, 1080 - 121}, (sfColor){255, 255, 255, 255});
    global->gui_button = init_gui_button(6, (int[6]){2, 3, 0, 0, 0, 0}, global);
    init_gui_button_specific(global->gui_button, global);
    global->click_release = 0;
    global->fps = 60;
    global->pipette = 0;
    global->chosen_button = (sfVector2i){-1, -1};
    global->rect_pos_sprite = (sfVector2f){20, 600};
    global->rect_sprite = sfSprite_create();
    global->rect_texture = sfTexture_createFromFile("assets/layers.png", NULL);
    sfSprite_setTexture(global->rect_sprite, global->rect_texture, sfTrue);
    sfSprite_setPosition(global->rect_sprite, global->rect_pos_sprite);
    sfSprite_setScale(global->rect_sprite, (sfVector2f){0.5, 0.5});
}

void init_window_and_mouse(global_t *global)
{
    global->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 60},
    "My Paint", sfResize | sfClose , NULL);
    sfRenderWindow_setPosition(global->window, (sfVector2i){0, 0});
    global->event = (sfEvent){0};
    global->mouse_pos = (sfVector2i){0, 0};
    global->mouse_posf = (sfVector2f){0, 0};
}

void init_vertex(global_t *global)
{
    if (global->size > MAX_VERTEX_SIZE)
        global->size = MAX_VERTEX_SIZE;
    for (int i = 0; i < global->size && i < MAX_VERTEX_SIZE; i++) {
        for (int j = 0; j < global->size && i < MAX_VERTEX_SIZE; j++) {
            global->vertices[i][j] = sfVertexArray_create();
            sfVertexArray_setPrimitiveType(global->vertices[i][j],
            sfLinesStrip);
        }
    }
    global->occurence = 0;
    for (int i = 0; i < global->size && i < MAX_VERTEX_SIZE; i++) {
        for (int j = 0; j < global->size && i < MAX_VERTEX_SIZE; j++) {
            global->point[i][j].position = (sfVector2f) {0.f, 0.f};
            global->point[i][j].color = sfBlack;
        }
    }
}
