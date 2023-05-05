/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** display_next
*/
#include "paint.h"

void draw_gui(global_t *global)
{
    global->gui[0]->color = global->theme->color_header;
    global->gui[1]->color = global->theme->color_body;
    for (int i = 0; i < 3; i++) {
        sfRectangleShape_setPosition(global->gui[i]->rect,
        global->gui[i]->pos);
        sfRectangleShape_setSize(global->gui[i]->rect,
        global->gui[i]->size);
        sfRectangleShape_setFillColor(global->gui[i]->rect,
        global->gui[i]->color);
        sfRenderWindow_drawRectangleShape(global->window,
        global->gui[i]->rect, NULL);
    }
}

void verif_which_button_third(global_t *global, gui_button_t *button, int i)
{
    if (i == 1){
        sfSprite_setPosition(global->eraser_sprite, (sfVector2f)
        {button->seg_buttons[i][0]->pos.x,
        button->seg_buttons[i][0]->pos.y + 20});
        sfRenderWindow_drawSprite(global->window,
        global->eraser_sprite, NULL);
        sfSprite_setPosition(global->bucket_sprite, (sfVector2f)
        {button->seg_buttons[i][1]->pos.x,
        button->seg_buttons[i][1]->pos.y - 5});
        sfRenderWindow_drawSprite(global->window,
        global->bucket_sprite, NULL);
        sfSprite_setPosition(global->pencil_sprite, (sfVector2f)
        {button->seg_buttons[i][2]->pos.x,
        button->seg_buttons[i][2]->pos.y});
        sfRenderWindow_drawSprite(global->window,
        global->pencil_sprite, NULL);
    }
}

void verif_which_button_two(global_t *global, gui_button_t *button, int i)
{
    if (i == 0){
        sfSprite_setPosition(global->diskette_sprite, (sfVector2f)
        {button->seg_buttons[i][0]->pos.x + 7,
        button->seg_buttons[i][0]->pos.y + 10});
        sfRenderWindow_drawSprite(global->window,
        global->diskette_sprite, NULL);
        sfSprite_setPosition(global->folder_sprite, (sfVector2f)
        {button->seg_buttons[i][1]->pos.x,
        button->seg_buttons[i][1]->pos.y});
        sfRenderWindow_drawSprite(global->window,
        global->folder_sprite, NULL);
    }
}

void verif_wich_button(gui_button_t *button, global_t *global, int i)
{
    if (button->first_buttons[i]->is_clicked == sfTrue){
        for (int j = 0; j < button->nb_seg_buttons[i]; j++) {
            sfRectangleShape_setPosition(button->seg_buttons[i][j]->rect,
            button->seg_buttons[i][j]->pos);
            sfRectangleShape_setSize(button->seg_buttons[i][j]->rect,
            button->seg_buttons[i][j]->size);
            sfRectangleShape_setFillColor(button->seg_buttons[i][j]->rect,
            button->seg_buttons[i][j]->color);
            sfRenderWindow_drawRectangleShape(global->window,
            button->seg_buttons[i][j]->rect, NULL);
        }
        verif_which_button_two(global, button, i);
        verif_which_button_third(global, button, i);
    }
}

void wich_gui_mode(gui_button_t *button, global_t *global)
{
    if (global->pencil->mode == 0){
        sfSprite_setPosition(global->pencil_sprite, (sfVector2f)
        {button->first_buttons[1]->pos.x, button->first_buttons[1]->pos.y});
        sfRenderWindow_drawSprite(global->window, global->pencil_sprite, NULL);
    }
    if (global->pencil->mode == 1){
        sfSprite_setPosition(global->eraser_sprite, (sfVector2f)
        {button->first_buttons[1]->pos.x,
        button->first_buttons[1]->pos.y + 20});
        sfRenderWindow_drawSprite(global->window, global->eraser_sprite, NULL);
    }
    if (global->pencil->mode == 2){
        sfSprite_setPosition(global->bucket_sprite, (sfVector2f)
        {button->first_buttons[1]->pos.x, button->first_buttons[1]->pos.y});
        sfRenderWindow_drawSprite(global->window, global->bucket_sprite, NULL);
    }
}
