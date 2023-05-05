/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** get_text_input
*/

#include "paint.h"

int get_text_if(int i, sfEvent event, char *str)
{
    if (event.text.unicode == 8) {
        if (i > 0)
            i--;
        str[i] = '\0';
    }
    if (event.text.unicode == 13)
        return -1;
    else {
        str[i] = event.text.unicode;
        i++;
    }
    return i;
}

void get_text_input_loop_2(sfEvent event, sfText *input,
sfText *text, char *str)
{
    static int i = 0;
    if (str[0] == '\0')
        i = 0;
    if (event.type == sfEvtTextEntered) {
        i = get_text_if(i, event, str);
        if (i == -1)
            return;
    }
}

char* get_text_input_loop(sfRenderWindow *window, sfEvent event,
sfText *input, sfText *text)
{
    char *str = malloc(sizeof(char) * 100);
    for (int i = 0; i < 100; i++)
        str[i] = '\0';
    while (event.type != sfEvtKeyPressed && event.key.code != sfKeyEnter) {
        sfRenderWindow_clear(window, sfBlack);
        sfText_setString(input, str);
        sfRenderWindow_drawText(window, input, NULL);
        sfRenderWindow_drawText(window, text, NULL);
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            get_text_input_loop_2(event, input, text, str);
        }
    }
    return str;
}

char *get_text_input(sfRenderWindow *window, sfVector2f pos, char *str2)
{
    sfEvent event;
    event.type = 0;
    sfText *text = sfText_create();
    sfText_setFont(text, sfFont_createFromFile("./assets/font.ttf"));
    sfText_setCharacterSize(text, 20);
    sfText_setPosition(text, pos);
    sfText_setString(text, str2);
    sfText *input = sfText_create();
    sfText_setFont(input, sfFont_createFromFile("./assets/font.ttf"));
    sfText_setCharacterSize(input, 20);
    sfText_setPosition(input, (sfVector2f){pos.x, pos.y + 30});
    sfText_setString(input, "");
    return get_text_input_loop(window, event, input, text);
}
