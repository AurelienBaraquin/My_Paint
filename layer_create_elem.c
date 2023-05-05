/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** layer_create_elem
*/

#include "layer.h"

void create_layer_elem_2(layer_elem_t *elem, char *name)
{
    elem->rect_layer = sfRectangleShape_create();
    sfRectangleShape_setSize(elem->rect_layer, (sfVector2f){340, 50});
    sfRectangleShape_setFillColor(elem->rect_layer, sfBlack);
    sfRectangleShape_setOutlineColor(elem->rect_layer, sfWhite);
    sfRectangleShape_setOutlineThickness(elem->rect_layer, 2);
    elem->layer_name = sfText_create();
    sfText_setString(elem->layer_name, name);
    sfText_setFont(elem->layer_name,
    sfFont_createFromFile("./assets/font.ttf"));
    sfText_setCharacterSize(elem->layer_name, 20);
    elem->is_clicked_layer = sfFalse;
    elem->is_hovered_layer = sfFalse;
    elem->rect_case = sfRectangleShape_create();
    sfRectangleShape_setSize(elem->rect_case, (sfVector2f){50, 50});
    sfRectangleShape_setFillColor(elem->rect_case, sfBlack);
    sfRectangleShape_setOutlineColor(elem->rect_case, sfWhite);
    sfRectangleShape_setOutlineThickness(elem->rect_case, 2);
}

void create_layer_elem_3(layer_elem_t *elem)
{
    elem->case_text = sfText_create();
    sfText_setString(elem->case_text, "X");
    sfText_setFont(elem->case_text, sfFont_createFromFile("./assets/font.ttf"));
    sfText_setCharacterSize(elem->case_text, 40);
    elem->is_clicked_case = sfFalse;
    elem->is_hovered_case = sfFalse;
    elem->rect_arrow = sfRectangleShape_create();
    sfRectangleShape_setSize(elem->rect_arrow, (sfVector2f){50, 50});
    sfRectangleShape_setFillColor(elem->rect_arrow, sfBlack);
    sfRectangleShape_setOutlineColor(elem->rect_arrow, sfWhite);
    sfRectangleShape_setOutlineThickness(elem->rect_arrow, 2);
    elem->arrow_text = sfText_create();
    sfText_setString(elem->arrow_text, "/");
    sfText_setFont(elem->arrow_text,
    sfFont_createFromFile("./assets/font.ttf"));
    sfText_setCharacterSize(elem->arrow_text, 40);
}

layer_elem_t* create_layer_elem(char *name)
{
    layer_elem_t *elem = malloc(sizeof(layer_elem_t));
    create_layer_elem_2(elem, name);
    create_layer_elem_3(elem);
    elem->is_clicked_arrow = sfFalse;
    elem->is_hovered_arrow = sfFalse;
    elem->is_visible = 1;
    elem->texture_list = init_texture_list();
    elem->next = NULL;
    return elem;
}
