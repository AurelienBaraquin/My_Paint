/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** texture_next
*/

#include "paint.h"

texture_list_t* init_texture_list(void)
{
    texture_list_t *texture_list = malloc(sizeof(texture_list_t));
    texture_list->index = 0;
    texture_list->first = NULL;
    texture_list->sprite = sfSprite_create();
    texture_list->size = (sfVector2f){1920 - 221, 1080 - 121};
    texture_list->pos = (sfVector2f){221, 121};
    sfSprite_setPosition(texture_list->sprite, texture_list->pos);
    return texture_list;
}

void add_element_to_texture_list_2(global_t *global,
sfTexture *texture, layer_elem_t *tmp_layer)
{
    texture_elem_t *new_elem = malloc(sizeof(texture_elem_t));
    texture_elem_t *tmp = tmp_layer->texture_list->first;
    new_elem->texture = texture;
    new_elem->next = NULL;
    if (tmp_layer->texture_list->first == NULL ||
    tmp_layer->texture_list->index <= 0) {
        tmp_layer->texture_list->first = new_elem;
        tmp_layer->texture_list->index++;
        tmp_layer = tmp_layer->next;
        return;
    }
    int i = 0;
    while (tmp->next != NULL && i < tmp_layer->texture_list->index - 1) {
        tmp = tmp->next;
        i++;
    }
    tmp->next = new_elem;
    tmp_layer->texture_list->index++;
}

void add_element_to_texture_list(global_t *global, sfTexture *texture)
{
    layer_elem_t *tmp_layer = global->layer_first;
    if (texture == NULL)
        return;
    while (tmp_layer != NULL) {
        if (texture == NULL || tmp_layer->is_visible != 1) {
            tmp_layer = tmp_layer->next;
            continue;
        }
        remove_color_from_texture(texture, sfWhite);
        add_element_to_texture_list_2(global, texture, tmp_layer);
        tmp_layer = tmp_layer->next;
    }
}

void display_texture_list(global_t *global)
{
    layer_elem_t *tmp_layer = global->layer_first;
    while (tmp_layer != NULL) {
        if (tmp_layer->texture_list->first == NULL ||
        tmp_layer->texture_list->index <= 0 || tmp_layer->is_visible != 1) {
            tmp_layer = tmp_layer->next;
            continue;
        }
        texture_elem_t *tmp = tmp_layer->texture_list->first;
        for (int i = 0; tmp != NULL &&
        i < tmp_layer->texture_list->index; i++) {
            sfSprite_setTexture(tmp_layer->texture_list->sprite,
            tmp->texture, sfTrue);
            sfSprite_setTextureRect(tmp_layer->texture_list->sprite,
            (sfIntRect){221, 121, 1920 - 221, 1080 - 121});
            sfRenderWindow_drawSprite(global->window,
            tmp_layer->texture_list->sprite, NULL);
            tmp = tmp->next;
        }
        tmp_layer = tmp_layer->next;
    }
}
