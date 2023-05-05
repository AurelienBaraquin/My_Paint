/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** display
*/

#include "paint.h"

void verif_mods_and_draw(gui_button_t *button, global_t *global)
{
    wich_gui_mode(button, global);
    sfSprite_setPosition(global->trash_sprite, (sfVector2f)
    {button->first_buttons[2]->pos.x - 20,
    button->first_buttons[2]->pos.y - 20});
    sfRenderWindow_drawSprite(global->window, global->trash_sprite, NULL);
    sfSprite_setPosition(global->download_sprite, (sfVector2f)
    {button->first_buttons[0]->pos.x - 50,
    button->first_buttons[0]->pos.y - 50});
    sfRenderWindow_drawSprite(global->window, global->download_sprite, NULL);
    sfSprite_setPosition(global->arrow_left_sprite, (sfVector2f)
    {button->first_buttons[4]->pos.x, button->first_buttons[4]->pos.y});
    sfRenderWindow_drawSprite(global->window, global->arrow_left_sprite, NULL);
    sfSprite_setPosition(global->arrow_right_sprite, (sfVector2f)
    {button->first_buttons[5]->pos.x, button->first_buttons[5]->pos.y});
    sfRenderWindow_drawSprite(global->window, global->arrow_right_sprite, NULL);
    sfSprite_setPosition(global->settings_sprite, (sfVector2f)
    {button->first_buttons[3]->pos.x - 10,
    button->first_buttons[3]->pos.y - 10});
    sfRenderWindow_drawSprite(global->window, global->settings_sprite, NULL);
}

void draw_button_on_gui(gui_button_t *button, global_t *global)
{
    for (int i = 0; i < button->nb_first_buttons; i++) {
        button->first_buttons[i]->color = global->theme->color_button;
        sfRectangleShape_setPosition(button->first_buttons[i]->rect,
        button->first_buttons[i]->pos);
        sfRectangleShape_setSize(button->first_buttons[i]->rect,
        button->first_buttons[i]->size);
        sfRectangleShape_setFillColor(button->first_buttons[i]->rect,
        button->first_buttons[i]->color);
        sfRenderWindow_drawRectangleShape(global->window,
        button->first_buttons[i]->rect, NULL);
        verif_wich_button(button, global, i);
    }
    verif_mods_and_draw(button, global);
}

void draw_on_which_mode(global_t *global)
{
    if (global->pencil->mode == 0 || global->pencil->mode == 1){
        sfRenderWindow_drawRectangleShape
        (global->window, global->back_slider, NULL);
        sfRenderWindow_drawCircleShape
        (global->window, global->slider, NULL);
    }
    if (global->pencil->mode == 0 || global->pencil->mode == 2){
        sfRenderWindow_drawSprite
        (global->window, global->color_palette_sprite, NULL);
        sfRenderWindow_drawSprite
        (global->window, global->black_pallette_sprite, NULL);
        sfRenderWindow_drawRectangleShape(
            global->window, global->color_palette_rect, NULL);
        sfRenderWindow_drawRectangleShape
        (global->window, global->black_pallette_rect, NULL);
        sfRectangleShape_setFillColor(global->colors_rect,
        global->pencil->color);
        sfRenderWindow_drawRectangleShape
        (global->window, global->colors_rect, NULL);
    }
}

void display_vertex(global_t *global, int i)
{
    for (int j = 0; j < global->size; j++){
        sfRenderWindow_drawVertexArray(global->window,
        global->vertices[i][j], NULL);
    }
}

void display_f(global_t *global, int priority)
{
    static int i = 0;
    if (i == 100 || priority >= 1) {
        sfRenderWindow_setFramerateLimit(global->window, global->fps);
        sfRenderWindow_clear(global->window, sfBlack);
        draw_gui(global);
        if (priority != 2)
            display_texture_list(global);
        for (int i = 0; i < global->size; i++){
            display_vertex(global, i);
        }
        draw_button_on_gui(global->gui_button, global);
        draw_on_which_mode(global);
        sfRenderWindow_drawSprite(global->window, global->rect_sprite, NULL);
        sfRenderWindow_display(global->window);
        i = 0;
    }
    i++;
}
