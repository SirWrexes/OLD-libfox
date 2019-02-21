/*
** EPITECH PROJECT, 2018
** libfox_io
** File description:
** Get a number's digit count
*/

#include <sys/types.h>

__attribute__ ((const))
size_t fox_nbsize(int nb)
{
    size_t size = 0;

    do {
        nb /= 10;
        size += 1;
    } while (nb);
    return size;
}