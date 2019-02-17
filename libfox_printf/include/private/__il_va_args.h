/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** No description
*/

#ifndef LIBFOX_PRINTF_IL_VA_ARGS_H
#define LIBFOX_PRINTF_IL_VA_ARGS_H

#include "private/__datastruct.h"

__attribute__ ((const))
static inline cspec_t _convspec_(char cs)
{
    switch (cs) {
    case 'i' : return CS_INT;
    case 'd' : return CS_INT;
    case 'u' : return CS_UINT;
    case 'b' : return CS_BIN;
    case 'o' : return CS_OCT;
    case 'p' :
    case 'x' : return CS_HEXL;
    case 'P' :
    case 'X' : return CS_HEXU;
    case 'n' : return CS_LEN;
    case '%' : return CS_PERC;
    case 'c' : return CS_CHAR;
    case 's' : return CS_STR;
    case 'S' : return CS_STR2;
    default : return CS_NONE;
    }
}

__attribute__ ((const))
static inline lnmod_t __lenmodif_(char lm1, char lm2)
{
    if (lm1 == lm2) {
        if (lm1 == 'h')
            return LM_CHAR;
        if (lm1 == 'l')
            return LM_LLONG;
    }
    switch (lm1) {
    case 'h' : return LM_SHORT;
    case 'l' : return LM_LONG;
    case 'L' :
    case 'q' : return LM_LONG;
    case 'z' :
    case 'Z' : return LM_ULONG;
    default : return LM_NONE;
    }
}

#endif //LIBFOX_PRINTF_IL_VA_ARGS_H
