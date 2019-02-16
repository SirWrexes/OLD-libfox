/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Get a number's digit count
*/

#include "private/__foxprintf.h"

__attribute__ ((const))
size_t fox_nbsize(llong_t nb)
{
    size_t size = 0;

    do {
        nb /= 10;
        size += 1;
    } while (nb);
    return size;
}

__attribute__ ((const))
size_t fox_unbsize(ullong_t nb)
{
    size_t size = 0;

    do {
        nb /= 10;
        size += 1;
    } while (nb);
    return size;
}