/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Choose the adequate printer depending on arg info
*/

#include "private/fox_printf/p_foxprintf.h"

static __a((nonnull))
ssize_t print_integer_small(int fd, farg_t const * const arg)
{
    switch (arg->lenmodif) {
    case LM_CHAR :
        return fox_fputint(fd, arg->value.c);
    case LM_SHORT :
        return fox_fputint(fd, arg->value.h);
    default :
        return fox_fputint(fd, arg->value.i);
    }
}

inline __a((nonnull))
ssize_t print_integer(int fd, farg_t const * const arg)
{
    if (arg->lenmodif <= LM_SHORT)
        return print_integer_small(fd, arg);
    else if (arg->lenmodif <= LM_LLONG)
        if (arg->lenmodif == LM_LONG)
            return fox_fputllong(fd, arg->value.ld);
        else
            return fox_fputllong(fd, arg->value.lld);
    else
        return fox_fputullong(fd, arg->value.ull);
}