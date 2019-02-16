/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Choose the adequate printer depending on arg info
*/

#include "private/__foxprintf.h"

static __attribute__ ((nonnull))
void print_integer_small(farg_t const * const arg)
{
    switch (arg->lenmodif) {
    case LM_CHAR :
        fox_putint(arg->argvalue.c);
        break;
    case LM_SHORT :
        fox_putint(arg->argvalue.h);
        break;
    default :
        fox_putint(arg->argvalue.i);
        break;
    }
}

inline __attribute__ ((nonnull))
void print_integer(farg_t const * const arg)
{
    if (arg->lenmodif <= LM_SHORT)
        print_integer_small(arg);
    else if (arg->lenmodif <= LM_LLONG)
        if (arg->lenmodif == LM_LONG)
            fox_putllong(arg->argvalue.l);
        else
            fox_putllong(arg->argvalue.ll);
    else
        fox_putullong(arg->argvalue.ull);
}