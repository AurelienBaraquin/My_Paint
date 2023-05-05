/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** get_nbr
*/

#include "paint.h"

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int get_nbr(char *str)
{
    int num = 0;
    int sign = 1;
    char *p = str;
    if (*p == '-') {
        sign = -1;
        p++;
    }
    while (*p != '\0') {
        if (!is_digit(*p)) {
            return -84;
        }
        num = num * 10 + (*p - '0');
        p++;
    }
    return num * sign;
}
