/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Main source
*/

#include "private/fox_printf/p_foxprintf.h"
#include "private/fox_printf/p_get_acmax.h"

static __a((nonnull, hot))
ssize_t print_arg(int fd, farg_t const * const arg)
{
    if (arg->convspec == CS_INT)
        N_ADD(print_integer(fd, arg));
    else if (arg->convspec >= CS_UINT && arg->convspec <= CS_HEXU)
        N_ADD(print_unsigned(fd, arg));
    else
        N_ADD(print_other(fd, arg));
    return arg->flength;
}

static __a((nonnull, hot))
ssize_t print_segment(int fd, str3c_t fstr)
{
    size_t seglen;
    ssize_t n;

    for (seglen = 0 ; fstr[seglen] && fstr[seglen] != '%' ; seglen += 1);
    n = write(fd, fstr, seglen);
    return N_ADD(n > 0 ? n : 0);
}

static __a((cold))
void fpf_init(size_t acmax, farg_t formatargs[acmax])
{
    N_RST;
    for (size_t i = 0 ; i < acmax ; i += 1) {
        formatargs[i].flength = 0;
        formatargs[i].convspec = 0;
        formatargs[i].flagmask = 0;
        formatargs[i].lenmodif = 0;
        formatargs[i].argvalue.lld = 0;
    }
    formatargs[acmax - 1].convspec = CS_SENTINEL;
}

extern __a((nonnull, format(printf, 2, 3)))
ssize_t fox_dprintf(int fd, str3c_t fstr, ...)
{
    va_list ap;
    size_t i = 0;
    size_t j = 0;
    size_t acmax = _get_acmax_(fstr) + 1;
    farg_t formatargs[acmax];

    va_start(ap, fstr);
    fpf_init(acmax, formatargs);
    if (fpf_getargs(acmax, formatargs, fstr, ap))
        RETURN(-1, fox_eputs("Arg list creation failure.\n"));
    while (fstr[i] != '\0') {
        i += print_segment(fd, fstr + i);
        if (fstr[i] == '\0')
            break;
        i += print_arg(fd, &formatargs[j++]);
    }
    return N_GET;
}
