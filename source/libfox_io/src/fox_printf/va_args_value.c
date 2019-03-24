/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** A whole lot of switches and stuff.
*/

#include "private/fox_printf/p_foxprintf.h"

inline __attribute__ ((nonnull))
void get_argvalue_int(farg_t *farg, va_list ap)
{
    switch (farg->lenmodif) {
    default :
        farg->argvalue.i = va_arg(ap, int);
        break;
    case LM_CHAR :
        farg->argvalue.c = (char) va_arg(ap, int);
        break;
    case LM_SHORT :
        farg->argvalue.h = (short) va_arg(ap, int);
        break;
    case LM_LONG :
        farg->argvalue.ld = va_arg(ap, long);
        break;
    case LM_LLONG :
        farg->argvalue.lld = va_arg(ap, long long);
        break;
    case LM_ULONG :
        farg->argvalue.ul = va_arg(ap, ulong);
        break;
    }
}

inline __attribute__ ((nonnull))
void get_argvalue_unsigned(farg_t *farg, va_list ap)
{
    switch (farg->lenmodif) {
    default :
        farg->argvalue.ui = va_arg(ap, uint);
        break;
    case LM_CHAR :
        farg->argvalue.uc = (u_char) va_arg(ap, int);
        break;
    case LM_SHORT :
        farg->argvalue.uh = (ushort) va_arg(ap, int);
        break;
    case LM_LONG :
        farg->argvalue.ul = va_arg(ap, ulong);
        break;
    case LM_LLONG :
        farg->argvalue.ull = va_arg(ap, ullong_t);
        break;
    case LM_ULONG :
        farg->argvalue.ul = va_arg(ap, ulong);
        break;
    }
}

inline __attribute__ ((nonnull))
void get_argvalue_other(farg_t *farg, va_list ap)
{
    switch (farg->convspec) {
    default : break;
    case CS_LEN :
        farg->lenmodif = LM_ULONG;
        break;
    case CS_PERC :
        farg->argvalue.c = '%';
        farg->convspec = CS_CHAR;
        break;
    case CS_STR :
    case CS_STR2 :
        farg->argvalue.str = va_arg(ap, char *);
        break;
    }
}