/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** strcpy
*/

#include "paint.h"

char *my_strncpy(char *dest, char *src, size_t n)
{
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for ( ; i < n; i++)
        dest[i] = '\0';
    return dest;
}

char *my_strchr(char *str, int c)
{
    while (*str != (char)c) {
        if (!*str++)
            return NULL;
    }
    return (char *)str;
}

void *my_memcpy(void *dest, void *src, size_t n)
{
    unsigned char *d = dest;
    const unsigned char *s = src;
    while (n--)
        *d++ = *s++;
    return dest;
}

char *my_strcpy(char *src)
{
    size_t len = my_strlen(src) + 1;
    char *dest = (char *)malloc(len * sizeof(char));
    if (dest == NULL) {
        return NULL;
    }
    return (char *)my_memcpy(dest, src, len);
}
