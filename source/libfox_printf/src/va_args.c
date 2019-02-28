/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** libfox_printf : args
*/

#include "private/__foxprintf.h"
#include "private/__il_va_args.h"

static __attribute__ ((nonnull))
void get_argvalue(farg_t *farg, va_list ap)
{
    if (farg->convspec == CS_INT)
        get_argvalue_int(farg, ap);
    else if (farg->convspec >= CS_UINT && farg->convspec <= CS_HEXU)
        get_argvalue_unsigned(farg, ap);
    else
        get_argvalue_other(farg, ap);
}

static __attribute__ ((nonnull))
ssize_t get_arginfo(farg_t *farg, char const * const fstr)
{
    ssize_t i = 1;


    if (__lenmodif_(fstr[i], fstr[i + 1])) {
        farg->lenmodif = __lenmodif_(fstr[i], fstr[i + 1]);
        i += (
            EQ3('l', fstr[i], fstr[i + 1]) ||
            EQ3('h', fstr[i], fstr[i + 1])
        ) + 1;
    }
    if (__lenmodif_(fstr[i], fstr[i]))
        return 0;
    if (_convspec_(fstr[i]))
        farg->convspec = _convspec_(fstr[i]);
    farg->flength += ++i;
    return farg->flength;
}

__attribute__ ((nonnull, cold, leaf))
bool fpf_getargs(
    size_t acmax, farg_t fargs[acmax], char const * const fstr, va_list ap)
{
    ssize_t i = 0;
    size_t argi = 0;

    while (fstr[i] != '\0') {
        for ( ; fstr[i] && fstr[i] != '%' ; i += 1);
        if (fstr[i] == '\0' || fstr[i + 1] == '\0')
            break;
        i += get_arginfo(&fargs[argi], fstr + i) ?: -(i + 1);
        if (i <= 0)
            return true;
        get_argvalue(&fargs[argi++], ap);
    }
    fargs[argi].convspec = CS_SENTINEL;
    return false;
}