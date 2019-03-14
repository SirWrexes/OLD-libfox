/*
** EPITECH PROJECT, 2019
** libfox_IO
** File description:
** Write an unsigned int
*/

#include "private/p_foxio.h"

ssize_t fox_fputuint(int fd, uint nbr)
{
    char conv[fox_unbsize(nbr)];
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

extern inline ssize_t fox_eputuint(uint nbr)
{
    return fox_fputuint(2, nbr);
}

extern inline ssize_t fox_putuint(uint nbr)
{
    return fox_fputuint(1, nbr);
}