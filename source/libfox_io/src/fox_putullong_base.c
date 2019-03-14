/*
** EPITECH PROJECT, 2019
** libfox_IO
** File description:
** Write an unsigned long long in given base
*/

#include "private/p_foxio.h"

__a((nonnull))
size_t fox_fputullong_base(int fd, ullong_t nbr, str3c_t base)
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
    do {
        n = write(fd, &base[conv[i--]], 1);
        nbrlen += n > 0 ? n : 0;
    } while (i >= 0);
    return nbrlen;
}

__a((nonnull))
size_t fox_eputullong_base(ullong_t nbr, str3c_t base)
{
    return fox_fputullong_base(2, nbr, base);
}

__a((nonnull))
size_t fox_putullong_base(ullong_t nbr, str3c_t base)
{
    return fox_fputullong_base(1, nbr, base);
}
