/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** No description
*/

#ifndef LIBFOX_PRINTF_IL_PRINTERPICKER_UNSIGNED_H
#define LIBFOX_PRINTF_IL_PRINTERPICKER_UNSIGNED_H

#include "p_datastruct.h"

__a((const))
static inline str2c_t _hex_base_(cspec_t cs)
{
    static str3c_t uppercase = "0123456789ABCDEF";
    static str3c_t lowercase = "0123456789abcdef";

    if (cs == CS_HEXU)
        return uppercase;
    else
        return lowercase;
}

#endif //LIBFOX_PRINTF_IL_PRINTERPICKER_UNSIGNED_H