/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Signed decimal number printer
*/

#include "private/fox_printf/p_foxprintf.h"

ssize_t fox_fputllong(int fd, llong_t nbr)
{
    char conv[fox_intsize(nbr)];
    bool neg = nbr < 0;
    size_t len = 0;
    ssize_t i = 0;

    do {
        conv[len++] = ITOC(ABS(nbr) % 10);
        nbr /= 10;
    } while (nbr);
    if (neg && len)
        write(fd, "-", 1);
    i = len - 1;
    do
        write(fd, &conv[i--], 1);
    while (i >= 0);
    return len + (neg && len);
}

ssize_t fox_eputllong(llong_t nbr)
{
    return fox_fputllong(2, nbr);
}

ssize_t fox_putllong(llong_t nbr)
{
    return fox_fputllong(1, nbr);
}