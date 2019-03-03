/*
** EPITECH PROJECT, 2018
** libfox_string
** File description:
** Convert a string to an int
*/

#include "private/__foxstring.h"

__attribute__((pure))
int getnb(str_t str)
{
    if ('\0' == str[0] || !IS_NUM(str[0]))
        return 0;
    return CTOI(str[0]) + 10 * (getnb(str + 1));
}
__attribute__((nonnull, pure))
int fox_atoi(str_t str)
{
    int  ret = 0;
    bool isneg = false;

    if (!IS_NUM(str[0])
    &&  ('\0' != str[1] && !IS_NUM(str[1]) && !IS_SIGN(str[0])))
        return 0;
    if (str[0] == '-')
        isneg = true;
    str = fox_revstr(str + IS_SIGN(str[0]));
    ret = getnb(str);
    fox_revstr(str + IS_SIGN(str[0]));
    return isneg ? -ret : ret;
}