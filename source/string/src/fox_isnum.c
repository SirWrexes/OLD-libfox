/*
** EPITECH PROJECT, 2018
** infin_add
** File description:
** my_isnum
*/

#include "private/p_foxstring.h"

__attribute__((nonnull, pure))
bool fox_isnum(str3c_t str)
{
    size_t i;

    for (i = 0;
    str[i] != '\0'
    && !IS_NUM(str[i])
    && IS_SIGN(str[i])
    && !IS_EOL(str[i]);
    i += 1);
    if (!IS_SIGN(str[i]) && !IS_NUM(str[i]))
        return false;
    for (; !IS_EOL(str[i]) && IS_NUM(str[i]); i += 1);
    if (!IS_NUM(str[i]) && !IS_EOL(str[i]))
        return false;
    return true;
}
