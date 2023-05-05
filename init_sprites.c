/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquinsfWhite
** File description:
** init_sprites
*/
#include "paint.h"

void init_slider(global_t *global)
{
    init_otherslider(global);
    color_rect(global);
    black_slider(global);
    sfSprite_setPosition(global->folder_sprite, global->folder_pos);
    sfSprite_setScale(global->folder_sprite, (sfVector2f){0.4, 0.4});
    global->download_sprite = sfSprite_create();
    global->download_texture =
    sfTexture_createFromFile("assets/download.png", NULL);
    sfSprite_setTexture(global->download_sprite, global->download_texture,
    sfTrue);
    global->download_pos = (sfVector2f){0, 0};
    sfSprite_setPosition(global->download_sprite, global->download_pos);
    sfSprite_setScale(global->download_sprite, (sfVector2f){0.4, 0.4});
}

void init_sprites_second(global_t *global)
{
    sfSprite_setPosition(global->eraser_sprite, global->eraser_pos);
    global->pencil_texture =
    sfTexture_createFromFile("assets/pencil.png", NULL);
    global->pencil_sprite = sfSprite_create();
    sfSprite_setTexture(global->pencil_sprite, global->pencil_texture, sfTrue);
    global->pencil_pos = (sfVector2f){0, 320};
    sfSprite_setPosition(global->pencil_sprite, global->pencil_pos);
    sfSprite_setScale(global->pencil_sprite, (sfVector2f){0.3, 0.3});
    global->trash_sprite = sfSprite_create();
    global->trash_texture = sfTexture_createFromFile("assets/trash.png", NULL);
    sfSprite_setTexture(global->trash_sprite, global->trash_texture, sfTrue);
    global->trash_pos = (sfVector2f){80, -20};
    sfSprite_setPosition(global->trash_sprite, global->trash_pos);
    sfSprite_setScale(global->trash_sprite, (sfVector2f){0.28, 0.28});
}

void init_sprites_first(global_t *global)
{
    global->bucket_texture = sfTexture_createFromFile("assets/bucket.png",
    NULL);
    global->bucket_sprite = sfSprite_create();
    sfSprite_setTexture(global->bucket_sprite, global->bucket_texture, sfTrue);
    global->bucket_pos = (sfVector2f){0, 121};
    sfSprite_setPosition(global->bucket_sprite, global->bucket_pos);
    sfSprite_scale(global->bucket_sprite, (sfVector2f){0.18, 0.18});
    global->eraser_texture = sfTexture_createFromFile("assets/eraser.png",
    NULL);
    global->eraser_sprite = sfSprite_create();
    sfSprite_setTexture(global->eraser_sprite, global->eraser_texture, sfTrue);
    global->eraser_pos = (sfVector2f){0, 221};
    sfSprite_setScale(global->eraser_sprite, (sfVector2f){0.2, 0.2});
}

void init_sprits(global_t *global)
{
    init_sprites_first(global);
    init_sprites_second(global);
    init_slider(global);
    global->arrow_left_sprite = sfSprite_create();
    global->arrow_left_texture =
    sfTexture_createFromFile("assets/arrow_left.png", NULL);
    sfSprite_setTexture(global->arrow_left_sprite, global->arrow_left_texture,
    sfTrue);
    global->arrow_left_pos = (sfVector2f){0, 0};
    sfSprite_setPosition(global->arrow_left_sprite, global->arrow_left_pos);
    sfSprite_setScale(global->arrow_left_sprite, (sfVector2f){0.2, 0.2});
    global->arrow_right_sprite = sfSprite_create();
    global->arrow_right_texture =
    sfTexture_createFromFile("assets/arrow_right.png", NULL);
    sfSprite_setTexture(global->arrow_right_sprite, global->arrow_right_texture,
    sfTrue);
    global->arrow_right_pos = (sfVector2f){0, 0};
    sfSprite_setPosition(global->arrow_right_sprite, global->arrow_right_pos);
    sfSprite_setScale(global->arrow_right_sprite, (sfVector2f){0.2, 0.2});
}
