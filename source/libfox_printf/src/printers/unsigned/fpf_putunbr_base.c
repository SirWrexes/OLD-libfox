/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Write a number in its hexadecimal value
*/

#include "private/p_foxprintf.h"

__attribute__ ((nonnull))
void fox_putuint_base(uint nbr, char const * const base)
{
    size_t conv[64];
    size_t baselen = fox_strlen(base);
    size_t nbrlen = 0;
    ssize_t i = 0;

    do {
        conv[nbrlen++] = nbr % baselen;
        nbr /= baselen;
    } while (nbr);
    i = nbrlen - 1;
    do
        write(1, &base[conv[i--]], 1);
    while (i >= 0);
    N_ADD(nbrlen);
}

__attribute__ ((nonnull))
void fox_putullong_base(ullong_t nbr, char const * const base)
{
    size_t conv[64];
    size_t baselen = fox_strlen(base);
    size_t nbrlen = 0;
    ssize_t i = 0;

    do {
        conv[nbrlen++] = nbr % baselen;
        nbr /= baselen;
    } while (nbr);
    i = nbrlen - 1;
    do
        write(1, &base[conv[i--]], 1);
    while (i >= 0);
    N_ADD(nbrlen);
}
