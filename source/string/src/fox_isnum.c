/*
** EPITECH PROJECT, 2018
** infin_add
** File description:
** my_isnum
*/

#include "private/p_foxstring.h"

__a((nonnull, pure))
bool fox_isnum(str3c_t str)
{
    size_t i;

    for (i = 0; str[i] && IS_SIGN(str[i]); i += 1);
    if (str[i] == '\0')
        return false;
    while (str[i])
        if (!IS_NUM(str[i++]))
            return false;
    return true;
}
