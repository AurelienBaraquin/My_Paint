/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-aurelien.baraquin
** File description:
** strcat_malloc
*/

#include "paint.h"

char* ma_strcpy(char* dest, const char* src)
{
    size_t i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char* ma_strcat(char* dest, const char* src)
{
    size_t i = 0;
    size_t dest_len = my_strlen(dest);
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}

char* strcat_malloc(char* str1, const char* str2)
{
    if (str1 == NULL || str2 == NULL)
        return NULL;
    size_t len1 = my_strlen(str1);
    size_t len2 = my_strlen(str2);
    size_t total_len = len1 + len2 + 1;
    char* result = malloc(total_len * sizeof(char));
    if (result == NULL)
        return NULL;
    ma_strcpy(result, str1);
    ma_strcat(result, str2);
    return result;
}
