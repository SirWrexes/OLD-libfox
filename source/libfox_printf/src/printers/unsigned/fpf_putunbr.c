/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Unsigned decimal number printer
*/

#include "private/p_foxprintf.h"

void fox_putuint(uint nbr)
{
    char conv[fox_unbsize(nbr)];
    size_t len = 0;
    ssize_t i  = 0;

    do {
        conv[len++] = ITOC(nbr % 10);
        nbr /= 10;
    } while (nbr);
    i = len - 1;
    do
        write(1, &conv[i--], 1);
    while (i >= 0);
    N_ADD(len);
}

void fox_putullong(ullong_t nbr)
{
    char conv[fox_unbsize(nbr)];
    size_t len = 0;
    ssize_t i  = 0;

    do {
        conv[len++] = ITOC(nbr % 10);
        nbr /= 10;
    } while (nbr);
    i = len - 1;
    do
        write(1, &conv[i--], 1);
    while (i >= 0);
    N_ADD(len);
}