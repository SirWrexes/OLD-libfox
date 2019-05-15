/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** Check if a string contains given characters
*/

#include "fox_string.h"

extern inline __a((nonnull, pure))
bool fox_strcont_c(str2c_t str, char accept)
{
    for (; *str ; str += 1)
        if (*str == accept)
            return true;
    return false;
}

extern inline __a((nonnull, pure))
bool fox_strcont(str2c_t str, str3c_t accept)
{
    for (; *str; str += 1)
        if (fox_strcont_c(accept, *str))
            return true;
    return false;
}

extern inline __a((nonnull, pure))
bool fox_strcont_r(str2c_t str, str3c_t accept)
{
    bool b = true;

    for (; b && *str; str += 1)
        b = fox_strcont_c(accept, *str);
    return b;
}