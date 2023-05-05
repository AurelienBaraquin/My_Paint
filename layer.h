/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** layer
*/

#ifndef LAYER_H_
    #define LAYER_H_

    #include "paint.h"

typedef struct layer_s {
    sfRenderWindow *window;
    layer_list_t *layer_list;
    int nb_layers;
} layer_t;

void update_layer_window(layer_t *layer, int view_deplacement);
void remove_layer_from_list(layer_list_t *layer_list, int index);
void update_layer_case(layer_t *layer, int view_deplacement);
void update_layer(layer_t *layer, int view_deplacement);
void display_layer_window(layer_t *layer);
layer_t* init_layer_global(global_t *global);
void update_arrow(layer_t *layer, int view_deplacement);
void update_layer(layer_t *layer, int view_deplacement);
void update_layer_case(layer_t *layer, int view_deplacement);
void update_layer_window(layer_t *layer, int view_deplacement);
void move_layer_prev_in_list(layer_list_t *layer_list, int index);
void remove_layer_from_list(layer_list_t *layer_list, int index);
void add_layer_to_list(layer_list_t *list, char *name);

#endif /* !LAYER_H_ */
