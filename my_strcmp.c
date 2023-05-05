/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** my_strcmp
*/

#include "paint.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
        return 0;
    if (s1[i] == '\0')
        return -1;
    return 1;
}
