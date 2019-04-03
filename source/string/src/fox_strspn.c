/*
** EPITECH PROJECT, 2018
** libfox
** File description:
** No description
*/

#include "private/p_foxstring.h"

static __a((pure, nonnull))
bool is_delim(char c, str3c_t delims)
{
    for (size_t i = 0; delims[i]; i += 1)
        if (c == delims[i])
            return true;
    return false;
}

__a((pure, nonnull))
size_t fox_strspn(str3c_t str, str3c_t delims)
{
    size_t i = 0;

    while (str[i] && is_delim(str[i], delims))
        i += 1;
    return i;
}

__a((pure, nonnull))
size_t fox_strcspn(str3c_t str, str3c_t delims)
{
    size_t i = 0;

    while (str[i] && !is_delim(str[i], delims))
        i += 1;
    return i;
}