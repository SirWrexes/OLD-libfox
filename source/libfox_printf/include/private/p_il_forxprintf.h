/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Simple 1 or 2 statement functions should be inlined
*/

#ifndef LIBFOX_PRINTF_INLINES_H
#define LIBFOX_PRINTF_INLINES_H

#include "private/p_datastruct.h"

__A((cold))
static inline size_t _get_acmax_(char const * const fstr)
{
    size_t acmax = 0;

    for (size_t i = 0 ; fstr[i] ; i += 1)
        acmax += (fstr[i] == '%');
    return acmax;
}

#endif //LIBFOX_PRINTF_INLINES_H
