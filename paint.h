/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** paint
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Export.h>
#include <time.h>
#include <stdio.h>
#include <SFML/System/Vector2.h>

#ifndef PAINT_H_
    #define PAINT_H_

    #define MAX_VERTEX_SIZE 30

typedef struct ptrect_s {
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
    sfRectangleShape *rect;
    sfBool is_clicked;
    sfBool is_hovered;
} ptrect_t;

typedef struct gui_button_s {
    ptrect_t ***seg_buttons;
    ptrect_t **first_buttons;
    int *nb_seg_buttons;
    int nb_first_buttons;
} gui_button_t;

typedef struct pencil_s {
    int size;
    sfColor color;
    int mode;
} pencil_t;

typedef struct texture_elem_s {
    sfTexture *texture;
    struct texture_elem_s *next;
} texture_elem_t;

typedef struct theme_s {
    char *name;
    sfColor color_header;
    sfColor color_body;
    sfColor color_button;
} theme_t;

typedef struct texture_list_s {
    texture_elem_t *first;
    sfVector2f pos;
    sfSprite *sprite;
    sfVector2f size;
    int index;
} texture_list_t;

typedef struct layer_elem_s {
    sfRectangleShape *rect_layer;
    sfBool is_clicked_layer;
    sfBool is_hovered_layer;

    sfText *layer_name;

    sfRectangleShape *rect_case;
    sfBool is_clicked_case;
    sfBool is_hovered_case;

    sfText *case_text;

    sfRectangleShape *rect_arrow;
    sfBool is_clicked_arrow;
    sfBool is_hovered_arrow;

    sfText *arrow_text;

    texture_list_t *texture_list;
    int is_visible;
    struct layer_elem_s *next;
} layer_elem_t;

typedef struct layer_list_s {
    layer_elem_t *first;
    sfRectangleShape *create_layer;
    sfText *create_layer_text;
    sfBool is_clicked;
    sfBool is_hovered;
} layer_list_t;

typedef struct global_s {
    ptrect_t **gui;
    gui_button_t *gui_button;
    sfRenderWindow *window;
    sfEvent event;
    sfVector2i mouse_pos;
    sfVector2f mouse_posf;
    sfTexture *win_texture;
    sfSprite *win_sprite;
    pencil_t *pencil;

    layer_elem_t *layer_first;
    texture_list_t *texture_list;

    theme_t *theme;

    int click_release;

    sfImage *win_image;
    sfUint8 *win_pixels;

    sfThread *thread2;
    sfBool is_launched2;

    sfSprite *eraser_sprite;
    sfTexture *eraser_texture;
    sfVector2f eraser_pos;
    sfSprite *pencil_sprite;
    sfTexture *pencil_texture;
    sfVector2f pencil_pos;
    sfSprite *bucket_sprite;
    sfTexture *bucket_texture;
    sfVector2f bucket_pos;
    sfVector2i chosen_button;
    sfSprite *trash_sprite;
    sfTexture *trash_texture;
    sfVector2f trash_pos;
    sfSprite *color_palette_sprite;
    sfTexture *color_palette_texture;
    sfVector2f color_palette_pos;
    sfVector2f color_palette_size;
    sfRectangleShape *color_palette_rect;
    sfVector2f color_palette_pos_rect;
    sfVector2f color_palette_size_rect;
    sfSprite *black_pallette_sprite;
    sfTexture *black_pallette_texture;
    sfVector2f black_pallette_pos;
    sfVector2f black_pallette_size;
    sfRectangleShape *black_pallette_rect;
    sfVector2f black_pallette_pos_rect;
    sfVector2f black_pallette_size_rect;
    int glutting;
    sfSprite *diskette_sprite;
    sfTexture *diskette_texture;
    sfVector2f diskette_pos;
    sfVector2f diskette_size;
    sfSprite *folder_sprite;
    sfTexture *folder_texture;
    sfVector2f folder_pos;
    sfVector2f folder_size;
    sfSprite *download_sprite;
    sfTexture *download_texture;
    sfVector2f download_pos;
    sfVector2f download_size;
    sfRectangleShape *colors_rect;
    sfVector2f colors_pos_rect;
    sfVector2f colors_size_rect;
    int pipette;
    sfSprite *pipette_sprite;
    sfTexture *pipette_texture;
    sfVector2f pipette_pos;
    sfVector2f pipette_size;
    sfSprite *arrow_left_sprite;
    sfTexture *arrow_left_texture;
    sfVector2f arrow_left_pos;
    sfVector2f arrow_left_size;
    sfSprite *arrow_right_sprite;
    sfTexture *arrow_right_texture;
    sfVector2f arrow_right_pos;
    sfVector2f arrow_right_size;
    sfSprite *settings_sprite;
    sfTexture *settings_texture;
    sfVector2f settings_pos;
    sfVector2f settings_size;
    int settings;
    sfClock *clock;
    sfTime time;
    sfRectangleShape *rect;
    sfVector2f rect_pos;
    sfVector2f rect_size;
    sfSprite *rect_sprite;
    sfTexture *rect_texture;
    sfVector2f rect_pos_sprite;
    sfVector2f rect_size_sprite;

    sfVertexArray* vertices[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE];
    sfVertex point[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE];
    sfRectangleShape *back_slider;
    sfVector2f back_slider_pos;
    sfVector2f back_slider_size;

    sfCircleShape *slider;
    sfVector2f slider_pos;
    int slider_size;

    int occurence;
    int size;

    int fps;
    int nb_layers;

} global_t;

    #define mpf global->mouse_posf

void destroy_f(global_t *global);
global_t* init_all(void);
void drawing(global_t *global);
void display_f(global_t *global, int a);
void init_pencil(global_t *global);
void init_gui_all(global_t *global);
void init_window_and_mouse(global_t *global);
void init_vertex(global_t *global);
void init_sprites_second(global_t *global);
void init_sprites_first(global_t *global);
void init_sprits(global_t *global);
ptrect_t** init_gui(int nb, global_t *global);
void init_gui_specific(ptrect_t *gui, sfVector2f pos,
sfVector2f size, sfColor color);
void init_gui_button_specific(gui_button_t *gui_button,
global_t *global);
gui_button_t* init_gui_button(int nb_first_button,
int *nb_seg_button, global_t *global);
void update_mouse_pos(global_t *global);
void dont_count_line(global_t *global);
void mouse_button_on_gui(global_t *global, int *i, int *a);
void mouse_on_gui(global_t *global, int *a);
void verif_which_gui(global_t *global);
int verif_button_clicked(ptrect_t **button, int nb_button);
void update_gui(global_t *global);
sfBool verif_coord(global_t *global, int i);
sfBool verif_coord_two(global_t *global, int i, int j);
void update_differents_var(global_t *global);
void verif_event_under_window(global_t *global, int i);
void verif_is_clicked_button(global_t *global);
sfTexture* screen_window_to_texture(global_t *global);
void clear_array_vertex(global_t *global);
sfTexture *load_texture_from_file(const char *filename);
void save_texture_to_file(const char *filename, global_t *global);
void load_workspace(global_t *global);
char* strcat_malloc(char* str1, const char* str2);
void save_workspace(global_t *global);
int my_strcmp(char *s1, char *s2);
theme_t* get_theme(char *name);
void theme_window(global_t *global);
void my_putstr(char *str);
int my_strlen(char const *str);
void settings_main(global_t *global);
theme_t* get_theme_from_file(char *path);
void redo_texture_list(global_t *global);
void save_in_file(global_t *global);
void draw_gui(global_t *global);
void verif_which_button_third(global_t *global,
gui_button_t *button, int i);
void verif_which_button_two(global_t *global,
gui_button_t *button, int i);
void verif_wich_button(gui_button_t *button,
global_t *global, int i);
void wich_gui_mode(gui_button_t *button,
global_t *global);
void init_otherslider(global_t *global);
void color_rect_next(global_t *global);
void color_rect(global_t *global);
void black_slider_next(global_t *global);
void black_slider(global_t *global);
int place_pixel(sfUint8 *pixels, int index , sfColor color);
int get_pixel_index(int x, int y, int width);
sfColor get_pixel_color(sfUint8 *pixels, int x,
int y, int width);
void append_on_vertrex(global_t *global,
int mouse_x, int mouse_y, int i);
void draw_with_pencil(global_t *global);
int compare_color(sfColor color1, sfColor color2);
void append_on_vertex_erased(global_t *global,
int mouse_x, int mouse_y, int i);
void draw_with_eraser(global_t *global);
int **verif_stack(int *stack, int *parms_two,
int top, int *params);
void bucket_fill(sfUint8 *pixels, int *params,
sfColor old_color, sfColor new_color);
void one_choosen_button(global_t *global);
void other_choosen_button(global_t *global);
void key_e_and_b(global_t *global);
void chosen_key_elem(global_t *global);
void verif_event(global_t *global);
void event_verif(global_t *global);
void close_windows(global_t *global);
texture_list_t* init_texture_list(void);
void add_element_to_texture_list(global_t *list,
sfTexture *texture);
void display_texture_list(global_t *global);
sfTexture* screen_window_to_texture(global_t *global);
void clear_array_vertex(global_t *global);
void update_differents_var(global_t *global);
void verif_event_under_window(global_t *global, int i);
void change_size(global_t *global);
int change_i_value(global_t *global, int i);
void verif_slider(global_t *global);
void verif_which_gui(global_t *global);
layer_elem_t* create_layer_elem(char *name);
void add_layer_to_list(layer_list_t *list, char *name);
char *get_text_input(sfRenderWindow *window, sfVector2f pos, char *str2);
void layer_window(global_t *global);
void remove_color_from_texture(sfTexture *texture, sfColor color);
void remove_last_element_from_texture_list(global_t *global);
void remove_layer(global_t *global);
sfImage *screen_window_to_image(global_t *global);
int get_nbr(char *str);
void verif_color_pallette(global_t *global);
void change_black_color(global_t *global);
void verif_black_pallette(global_t *global);
int change_i_value(global_t *global, int i);
int help_window(global_t *global);
void layer_event_main(global_t *global, sfEvent event);
void change_color(global_t *global);
void add_elem_next_texture(texture_elem_t *new_elem, texture_elem_t *tmp,
layer_elem_t *tmp_layer);
void settings_verif_event(global_t *global);
void verif_click_realised(global_t *global);
char * restrcat(char *dest, char *str);
char *my_strcat(char *dest, const char *src);
void *my_memset(void *s, int c, size_t n);
int my_strncmp(char *str1, char *str2, int n);
char *my_strcpy(char *src);
void *my_memcpy(void *dest, void *src, size_t n);
char *my_strchr(char *str, int c);
char *my_strncpy(char *dest, char *src, size_t n);
void full_fill(sfUint8 *pixels, int *params, sfColor color,
sfColor new_color);
void verif_key_layers(global_t *global);

#endif /* !PAINT_H_ */
