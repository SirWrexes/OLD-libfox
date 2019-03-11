/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** No description
*/

#ifndef LIBFOX_PRINTF_IL_PRINTERPICKER_UNSIGNED_H
#define LIBFOX_PRINTF_IL_PRINTERPICKER_UNSIGNED_H

#include "p_datastruct.h"

__A((const))
static inline char const *_hex_base_(cspec_t cs)
{
    static char const * const uppercase = "0123456789ABCDEF";
    static char const * const lowercase = "0123456789abcdef";

    if (cs == CS_HEXU)
        return uppercase;
    else
        return lowercase;
}

#endif //LIBFOX_PRINTF_IL_PRINTERPICKER_UNSIGNED_H
