/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Main source
*/

#include "private/__il_forxprintf.h"
#include "private/__foxprintf.h"

static __attribute__ ((nonnull, hot))
ssize_t print_arg(farg_t const * const arg)
{
    if (arg->convspec == CS_INT)
        print_integer(arg);
    else if (arg->convspec >= CS_UINT && arg->convspec <= CS_HEXU)
        print_unsigned(arg);
    else
        print_other(arg);
    return arg->flength;
}

static __attribute__ ((nonnull, hot))
size_t print_segment(char const * const fstr)
{
    size_t seglen;

    for (seglen = 0 ; fstr[seglen] && fstr[seglen] != '%' ; seglen += 1);
    N_ADD(write(1, fstr, seglen));
    return seglen;
}

static __attribute__ ((cold))
void fpf_init(size_t acmax, farg_t formatargs[acmax])
{
    N_RST;
    for (size_t i = 0 ; i < acmax ; i += 1) {
        formatargs[i].flength = 0;
        formatargs[i].convspec = 0;
        formatargs[i].flagmask = 0;
        formatargs[i].lenmodif = 0;
        formatargs[i].argvalue.ll = 0;
    }
    formatargs[acmax - 1].convspec = CS_SENTINEL;
}

__attribute__ ((nonnull, format(printf, 1,2)))
ssize_t fox_printf(char const * const fstr, ...)
{
    va_list ap;
    size_t i = 0;
    size_t j = 0;
    size_t acmax = _get_acmax_(fstr) + 1;
    farg_t formatargs[acmax];

    va_start(ap, fstr);
    fpf_init(acmax, formatargs);
    if (fpf_getargs(acmax, formatargs, fstr, ap)) {
        write(2, "Arg list creation failure.\n", 28);
        return -1;
    }
    while (fstr[i] != '\0') {
        i += print_segment(fstr + i);
        if (fstr[i] == '\0')
            break;
        i += print_arg(&formatargs[j++]);
    }
    return N_GET;
}