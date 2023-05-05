/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** layer_init
*/

#include "layer.h"

void init_layer_global_2(layer_t *layer)
{
    sfRectangleShape_setSize(layer->layer_list->create_layer,
    (sfVector2f){50, 50});
    sfRectangleShape_setPosition(layer->layer_list->create_layer,
    (sfVector2f){10, 10});
    sfRectangleShape_setFillColor(layer->layer_list->create_layer, sfBlack);
    sfRectangleShape_setOutlineColor(layer->layer_list->create_layer, sfWhite);
    sfRectangleShape_setOutlineThickness(layer->layer_list->create_layer, 2);
    layer->layer_list->create_layer_text = sfText_create();
    sfText_setString(layer->layer_list->create_layer_text, "+");
    sfText_setFont(layer->layer_list->create_layer_text,
    sfFont_createFromFile("./assets/font.ttf"));
    sfText_setCharacterSize(layer->layer_list->create_layer_text, 40);
    sfText_setPosition(layer->layer_list->create_layer_text,
    (sfVector2f){18, 13});
}

layer_t* init_layer_global(global_t *global)
{
    layer_t *layer = malloc(sizeof(layer_t));
    layer->window = sfRenderWindow_create((sfVideoMode){480, 480, 32},
    "MyPaint", sfNone, NULL);
    sfRenderWindow_setFramerateLimit(layer->window, 60);
    sfRenderWindow_setPosition(layer->window, (sfVector2i){280, 180});
    layer->layer_list = malloc(sizeof(layer_list_t));
    layer->layer_list->first = global->layer_first;
    layer->layer_list->create_layer = sfRectangleShape_create();
    layer->layer_list->is_clicked = sfFalse;
    layer->layer_list->is_hovered = sfFalse;
    init_layer_global_2(layer);
    layer->nb_layers = 1;
    return layer;
}
