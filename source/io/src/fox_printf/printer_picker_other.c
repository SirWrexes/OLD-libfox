/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Choose the adequate printer depending on arg info
*/

#include "private/fox_printf/p_foxprintf.h"

inline __attribute__ ((nonnull))
ssize_t print_other(int fd, farg_t const * const arg)
{
    switch (arg->convspec) {
    default : return 0;
    case CS_CHAR :
        return fox_fputc(fd, arg->value.c);
    case CS_STR :
        return fox_fputs(fd, arg->value.str);
    case CS_STR2 :
        return fox_fputnps(fd, arg->value.str);
    case CS_LEN :
        return fox_putullong(N_GET);
    }
}