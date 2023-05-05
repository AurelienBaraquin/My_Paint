/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** save_format
*/

#include "workspace.h"

static const char *format[] = {".png", ".jpg", ".tga"};

void init_format(save_t *save, sfFont *font)
{
    save->format_type = 0;
    save->format = malloc(sizeof(text_button_t *) * 3);
    for (int i = 0; i < 3; i++) {
        save->format[i] = malloc(sizeof(text_button_t));
        save->format[i]->text = sfText_create();
        save->format[i]->rect = sfRectangleShape_create();
        sfText_setFont(save->format[i]->text, font);
        sfText_setCharacterSize(save->format[i]->text, 20);
        sfText_setPosition(save->format[i]->text, (sfVector2f){0, 0});
        sfRectangleShape_setSize(save->format[i]->rect,
        (sfVector2f){100, 50});
        sfRectangleShape_setFillColor(save->format[i]->rect, sfBlack);
        sfRectangleShape_setOutlineColor(save->format[i]->rect, sfWhite);
        sfRectangleShape_setOutlineThickness(save->format[i]->rect, 2);
    }
    sfText_setString(save->format[0]->text, format[0]);
    sfText_setString(save->format[1]->text, format[1]);
    sfText_setString(save->format[2]->text, format[2]);
}

void update_format_button_2(save_t *save, sfVector2f pos,
sfVector2f size, int i)
{
    if (sfFloatRect_contains(&((sfFloatRect) {pos.x, pos.y, size.x, size.y}),
    sfMouse_getPositionRenderWindow(save->window).x,
    sfMouse_getPositionRenderWindow(save->window).y)) {
        sfRectangleShape_setFillColor(save->format[i]->rect, sfWhite);
        sfText_setColor(save->format[i]->text, sfBlack);
        sfRectangleShape_setOutlineColor(save->format[i]->rect, sfBlack);
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
        (save->format[i]->is_clicked == sfFalse)) {
            save->format[i]->is_clicked = sfTrue;
            save->format_type = i;
        }
    } else {
        sfRectangleShape_setFillColor(save->format[i]->rect,
        sfBlack);
        sfText_setColor(save->format[i]->text, sfWhite);
        sfRectangleShape_setOutlineColor(save->format[i]->rect, sfWhite);
        save->format[i]->is_clicked = sfFalse;
    }
}

void update_format_button(save_t *save)
{
    sfVector2f pos = {0, 0};
    sfVector2f size = {0, 0};
    for (int i = 0; i < 3; i++) {
        pos = sfRectangleShape_getPosition(save->format[i]->rect);
        size = sfRectangleShape_getSize(save->format[i]->rect);
        update_format_button_2(save, pos, size, i);
        if (save->format_type == i)
            sfRectangleShape_setFillColor(save->format[i]->rect,
            (sfColor){30, 255, 30, 255});
    }
}

void draw_format_button(save_t *save)
{
    sfVector2f pos = {0, 0};
    sfVector2f size = {0, 0};
    for (int i = 0; i < 3; i++) {
        pos = sfRectangleShape_getPosition(save->format[i]->rect);
        size = sfRectangleShape_getSize(save->format[i]->rect);
        sfRectangleShape_setPosition(save->format[i]->rect,
        (sfVector2f){10 + (i * 100) + i * 20, 400});
        sfText_setPosition(save->format[i]->text, (sfVector2f){10 + (i * 100) +
        50 - (sfText_getLocalBounds(save->format[i]->text).width / 2)
        + i * 20, 10 + 400});
        sfRenderWindow_drawRectangleShape(save->window,
        save->format[i]->rect, NULL);
        sfRenderWindow_drawText(save->window, save->format[i]->text, NULL);
    }
}

void event_key_pressed(sfEvent event, save_t *save, global_t *global)
{
    if (event.type == sfEvtKeyPressed && event.key.code ==
    sfKeyReturn) {
        sfText_setString(save->input, add_char_to_str
        (sfText_getString(save->input), '.'));
        sfText_setString(save->input, add_char_to_str
        (sfText_getString(save->input), format[save->format_type][1]));
        sfText_setString(save->input, add_char_to_str
        (sfText_getString(save->input), format[save->format_type][2]));
        sfText_setString(save->input, add_char_to_str
        (sfText_getString(save->input), format[save->format_type][3]));
        if (my_strlen(sfText_getString(save->input)) > 20){
            sfText_setString(save->input, "Name too long");
            return;
        }
        save_texture_to_file(strcat_malloc("outputs/",
        sfText_getString(save->input)), global);
        sfRenderWindow_close(save->window);
    }
}
