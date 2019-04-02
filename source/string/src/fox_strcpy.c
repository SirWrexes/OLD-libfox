/*
** EPITECH PROJECT, 2019
** libfox_string
** File description:
** Copy a string into another [up to n characters]
*/

#include "private/p_foxstring.h"

__a((nonnull))
str_t fox_strcpy(str_t dst, str3c_t src)
{
    size_t i;
    size_t len1 = fox_strlen(dst);
    size_t len2 = fox_strlen(src);

    for (i = 0; i < len1 && i < len2; i += 1)
        dst[i] = src[i];
    for (i -= 1; i < len1; i += 1)
        dst[i] = '\0';
    return dst;
}

__a((nonnull))
str_t fox_strncpy(str_t dst, str3c_t src, size_t n)
{
    size_t i;
    size_t len1 = fox_strlen(dst);
    size_t len2 = fox_strlen(src);

    for (i = 0; i < n && i < len1 && i < len2; i += 1)
        dst[i] = src[i];
    for (i -= 1; i < len1; i += 1)
        dst[i] = '\0';
    return dst;
}
