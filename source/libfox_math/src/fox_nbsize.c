/*
** EPITECH PROJECT, 2018
** libfox_io
** File description:
** Get a number's digit count
*/

#include <sys/types.h>
#include "fox_define.h"

extern inline __a((const))
size_t fox_ullongsize(ullong_t nb)
{
    size_t size = 0;

    do {
        nb /= 10;
        size += 1;
    } while (nb);
    return size;
}

extern inline __a((const))
size_t fox_llongsize(llong_t nb)
{
    size_t size = 0;

    do {
        nb /= 10;
        size += 1;
    } while (nb);
    return size;
}

extern inline __a((const))
size_t fox_uintsize(uint nb)
{
    return fox_ullongsize(nb);
}

extern inline __a((const))
size_t fox_intsize(int nb)
{
    return fox_llongsize(nb);
}
