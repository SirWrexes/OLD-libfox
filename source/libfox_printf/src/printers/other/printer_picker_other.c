/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Choose the adequate printer depending on arg info
*/

#include "private/p_foxprintf.h"

inline __attribute__ ((nonnull))
void print_other(farg_t const * const arg)
{
    switch (arg->convspec) {
    default : break;
    case CS_CHAR :
        fox_putc(arg->argvalue.c);
        break;
    case CS_STR :
        fox_puts(arg->argvalue.str);
        break;
    case CS_STR2 :
        fox_puts2(arg->argvalue.str);
        break;
    case CS_LEN :
        fox_putullong(N_GET);
        break;
    }
}