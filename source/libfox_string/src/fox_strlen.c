/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** Returns the number of characters in a string
*/

#include "private/p_foxstring.h"

static __a((pure))
size_t get_len(str3c_t str)
{
    size_t len;

    for (len = 0;; len += 7) {
        if (str[len] == '\0')
            return len;
        if (str[len + 1] == '\0')
            return len + 1;
        if (str[len + 2] == '\0')
            return len + 2;
        if (str[len + 3] == '\0')
            return len + 3;
        if (str[len + 4] == '\0')
            return len + 4;
        if (str[len + 5] == '\0')
            return len + 5;
        if (str[len + 6] == '\0')
            return len + 6;
        if (str[len + 7] == '\0')
            return len + 7;
    }
}

__a((pure))
size_t fox_strlen(str3c_t str)
{
    if (str == NULL)
        return 0;
    else
        return get_len(str);
}