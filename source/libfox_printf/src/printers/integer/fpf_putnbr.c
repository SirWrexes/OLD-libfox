/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Signed decimal number printer
*/

#include "private/p_foxprintf.h"

void fox_putint(int nbr)
{
    char conv[fox_nbsize(nbr)];
    bool neg = nbr < 0;
    size_t len = 0;
    ssize_t i  = 0;

    do {
        conv[len++] = ITOC(ABS(nbr) % 10);
        nbr /= 10;
    } while (nbr);
    if (neg && len)
        write(1, "-", 1);
    i = len - 1;
    do
        write(1, &conv[i--], 1);
    while (i >= 0);
    N_ADD(len + neg);
}

void fox_putllong(llong_t nbr)
{
    char conv[fox_nbsize(nbr)];
    bool   neg = nbr < 0;
    size_t len = 0;
    ssize_t i  = 0;

    do {
        conv[len++] = ITOC(ABS(nbr) % 10);
        nbr /= 10;
    } while (nbr);
    if (neg && len)
        write(1, "-", 1);
    i = len - 1;
    do
        write(1, &conv[i--], 1);
    while (i >= 0);
    N_ADD(len + neg);
}