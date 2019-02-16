/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Global variables are cool
*/

#include <sys/types.h>

extern inline __attribute__ ((hot, leaf))
size_t n_printed_bytes(ssize_t nplus)
{
    static size_t n = 0;

    n += nplus;
    return n;
}