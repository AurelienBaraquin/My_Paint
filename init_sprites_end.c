/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** init_sprites_end
*/
#include "paint.h"

void init_otherslider(global_t *global)
{
    global->back_slider = sfRectangleShape_create();
    global->back_slider_size = (sfVector2f){170, 5};
    sfRectangleShape_setSize(global->back_slider, global->back_slider_size);
    sfRectangleShape_setFillColor(global->back_slider, sfBlack);
    global->back_slider_pos = (sfVector2f){10, 200};
    sfRectangleShape_setPosition(global->back_slider, global->back_slider_pos);
    global->slider = sfCircleShape_create();
    sfCircleShape_setRadius(global->slider, 10);
    sfCircleShape_setFillColor(global->slider, sfWhite);
    global->slider_pos = (sfVector2f){160, 192};
    sfCircleShape_setPosition(global->slider, global->slider_pos);
    global->slider_size = 10;
    global->color_palette_sprite = sfSprite_create();
    global->color_palette_texture =
    sfTexture_createFromFile("assets/color_palette.png", NULL);
    sfSprite_setTexture(global->color_palette_sprite,
    global->color_palette_texture, sfTrue);
    global->color_palette_pos = (sfVector2f){30, 300};
    sfSprite_setPosition(global->color_palette_sprite,
    global->color_palette_pos);
}

void color_rect_next(global_t *global)
{
    sfSprite_setTexture(global->black_pallette_sprite,
    global->black_pallette_texture, sfTrue);
    global->black_pallette_pos = (sfVector2f){90, 300};
    sfSprite_setPosition(global->black_pallette_sprite,
    global->black_pallette_pos);
    global->black_pallette_size = (sfVector2f){
        sfSprite_getGlobalBounds(global->black_pallette_sprite).width,
        sfSprite_getGlobalBounds(global->black_pallette_sprite).height};
    global->colors_rect = sfRectangleShape_create();
    global->colors_size_rect = (sfVector2f){40, 40};
    sfRectangleShape_setSize(global->colors_rect, global->colors_size_rect);
    sfRectangleShape_setFillColor(global->colors_rect, sfBlack);
    global->colors_pos_rect = (sfVector2f){53, 240};
    sfRectangleShape_setPosition(global->colors_rect,
    global->colors_pos_rect);
    sfRectangleShape_setOutlineColor(global->colors_rect,
    sfBlack);
    sfRectangleShape_setOutlineThickness(global->colors_rect, 2);
}

void color_rect(global_t *global)
{
    global->color_palette_size = (sfVector2f){
        sfSprite_getGlobalBounds(global->color_palette_sprite).width,
        sfSprite_getGlobalBounds(global->color_palette_sprite).height};
    global->color_palette_rect = sfRectangleShape_create();
    global->color_palette_size_rect = (sfVector2f){40, 10};
    sfRectangleShape_setSize(global->color_palette_rect,
    global->color_palette_size_rect);
    sfRectangleShape_setFillColor(global->color_palette_rect, sfBlack);
    global->color_palette_pos_rect = (sfVector2f){20,
    global->color_palette_pos.y + 242};
    sfRectangleShape_setPosition(global->color_palette_rect,
    global->color_palette_pos_rect);
    sfRectangleShape_setFillColor(global->color_palette_rect, sfRed);
    global->black_pallette_sprite = sfSprite_create();
    global->black_pallette_texture =
    sfTexture_createFromFile("assets/black_palette.png", NULL);
    color_rect_next(global);
}

void black_slider_next(global_t *global)
{
    sfSprite_setTexture(global->diskette_sprite,
    global->diskette_texture, sfTrue);
    global->diskette_pos = (sfVector2f){0, 0};
    sfSprite_setPosition(global->diskette_sprite, global->diskette_pos);
    sfSprite_setScale(global->diskette_sprite, (sfVector2f){0.2, 0.2});
    global->folder_sprite = sfSprite_create();
    global->folder_texture =
    sfTexture_createFromFile("assets/folder.png", NULL);
    sfSprite_setTexture(global->folder_sprite,
    global->folder_texture, sfTrue);
    global->folder_pos = (sfVector2f){0, 0};
}

void black_slider(global_t *global)
{
    global->black_pallette_rect = sfRectangleShape_create();
    global->black_pallette_size_rect = (sfVector2f){40, 10};
    sfRectangleShape_setSize(global->black_pallette_rect,
    global->black_pallette_size_rect);
    sfRectangleShape_setFillColor(global->black_pallette_rect, sfBlack);
    global->black_pallette_pos_rect = (sfVector2f){80,
    global->black_pallette_size.y + 290};
    sfRectangleShape_setFillColor(global->black_pallette_rect, sfBlack);
    sfRectangleShape_setPosition(global->black_pallette_rect,
    global->black_pallette_pos_rect);
    global->glutting = 0;
    global->diskette_sprite = sfSprite_create();
    global->diskette_texture =
    sfTexture_createFromFile("assets/diskette.png", NULL);
    black_slider_next(global);
}
