/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Unsigned decimal number printer
*/

#include "private/fox_printf/p_foxprintf.h"

ssize_t fox_fputullong(int fd, ullong_t nbr)
{
    char conv[fox_ullongsize(nbr)];
    size_t len = 0;
    ssize_t i  = 0;
    ssize_t n;

    do {
        conv[len++] = ITOC(nbr % 10);
        nbr /= 10;
    } while (nbr);
    i = len - 1;
    len = 0;
    do {
        n = write(fd, &conv[i--], 1);
        len += n > 0 ? n : 0;
    } while (i >= 0);
    return len;
}

ssize_t fox_eputullong(ullong_t nbr)
{
    return fox_fputullong(2, nbr);
}

ssize_t fox_putullong(ullong_t nbr)
{
    return fox_fputullong(1, nbr);
}

