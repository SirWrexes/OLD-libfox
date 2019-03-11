/*
** EPITECH PROJECT, 2018
** libfox_io
** File description:
** Write an int
*/

#include "private/p_foxio.h"

ssize_t fox_putint(int nb)
{
    char conv[fox_nbsize(nb)];
    bool neg = nb < 0;
    size_t len = 0;
    ssize_t i  = 0;

    do {
        conv[len++] = ITOC(ABS(nb) % 10);
        nb /= 10;
    } while (nb);
    if (neg && len)
        if (write(1, "-", 1) == -1)
            return -1;
    i = len - 1;
    do
        if (write(1, &conv[i--], 1) == -1)
            return -1;
    while (i >= 0);
    return len + (neg && len);
}

ssize_t fox_eputint(int nb)
{
    char conv[fox_nbsize(nb)];
    bool neg = nb < 0;
    size_t len = 0;
    ssize_t i  = 0;

    do {
        conv[len++] = ITOC(ABS(nb) % 10);
        nb /= 10;
    } while (nb);
    if (neg && len)
        if (write(2, "-", 1) == -1)
            return -1;
    i = len - 1;
    do
        if (write(2, &conv[i--], 1) == -1)
            return -1;
    while (i >= 0);
    return len + (neg && len);
}

ssize_t fox_fputint(int fd, int nb)
{
    char conv[fox_nbsize(nb)];
    bool neg = nb < 0;
    size_t len = 0;
    ssize_t i  = 0;

    do {
        conv[len++] = ITOC(ABS(nb) % 10);
        nb /= 10;
    } while (nb);
    if (neg && len)
        if (write(fd, "-", 1) == -1)
            return -1;
    i = len - 1;
    do
        if (write(fd, &conv[i--], 1) == -1)
            return -1;
    while (i >= 0);
    return len + (neg && len);
}