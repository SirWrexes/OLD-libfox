/*
** EPITECH PROJECT, 2018
** libfox_string
** File description:
** Convert a string to an int
*/

#include "private/p_foxstring.h"

__a((pure))
int getnb(str_t str)
{
    if ('\0' == str[0] || !IS_NUM(str[0]))
        return 0;
    return CTOI(str[0]) + 10 * (getnb(str + 1));
}

__a((nonnull, pure))
int fox_atoi(str3c_t str)
{
    int ret = 0;
    bool isneg = false;

    if (str[0] == '-')
        isneg = true;
    for (size_t i = isneg; str[i] && IS_NUM(str[i]); i += 1) {
        ret *= 10u;
        ret += CTOI(str[i]);
    }
    return isneg ? -ret : ret;
}
