/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** load_image
*/

#include "paint.h"

sfTexture *load_texture_from_file(const char *filename)
{
    sfTexture *texture = sfTexture_create(1920, 1080);
    sfImage *image = sfImage_createFromFile(filename);
    if (image == NULL)
        return NULL;
    if (sfImage_getSize(image).x > 1920 - 220 ||
    sfImage_getSize(image).y > 1080 - 120){
        sfImage *croppedImage = sfImage_create(1920 - 220, 1080 - 120);
        sfImage_copyImage(croppedImage, image, 0, 0, (sfIntRect){0, 0,
        1700, 960}, sfTrue);
        sfTexture_updateFromImage(texture, croppedImage, 220, 120);
        sfImage_destroy(image);
        sfImage_destroy(croppedImage);
        return texture;
    }
    sfTexture_updateFromImage(texture, image, 220, 120);
    sfImage_destroy(image);
    return texture;
}

void save_texture_to_file(const char *filename, global_t *global)
{
    sfTexture *texture = sfTexture_create(
        sfRenderWindow_getSize(global->window).x,
    sfRenderWindow_getSize(global->window).y);
    sfTexture_updateFromRenderWindow(texture, global->window, 0, 0);
    sfImage *image = sfTexture_copyToImage(texture);
    sfImage* croppedImage = sfImage_create(
        sfRenderWindow_getSize(global->window).x - 221,
        sfRenderWindow_getSize(global->window).y - 121);
    sfIntRect rect = {221, 121, sfRenderWindow_getSize(global->window).x - 221,
    sfRenderWindow_getSize(global->window).y - 121};
    sfImage_copyImage(croppedImage, image, 0, 0, rect, sfTrue);
    sfImage_saveToFile(croppedImage, filename);
    sfImage_destroy(image);
    sfImage_destroy(croppedImage);
}
