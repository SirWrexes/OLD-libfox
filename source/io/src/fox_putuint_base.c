/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Write a number in its hexadecimal value
*/

#include "private/fox_printf/p_foxprintf.h"

__a((nonnull))
size_t fox_fputuint_base(int fd, uint nbr, str3c_t base)
{
    size_t conv[64];
    size_t baselen = fox_strlen(base);
    size_t nbrlen = 0;
    ssize_t i = 0;
    ssize_t n;

    do {
        conv[nbrlen++] = nbr % baselen;
        nbr /= baselen;
    } while (nbr);
    i = nbrlen - 1;
    nbrlen = 0;
    do {
        n = write(fd, &base[conv[i--]], 1);
        nbrlen += n > 0 ? n : 0;
    } while (i >= 0);
    return nbrlen;
}

__a((nonnull))
size_t fox_eputuint_base(uint nbr, str3c_t base)
{
    return fox_fputuint_base(2, nbr, base);
}

__a((nonnull))
size_t fox_putuint_base(uint nbr, str3c_t base)
{
    return fox_fputuint_base(1, nbr, base);
}
