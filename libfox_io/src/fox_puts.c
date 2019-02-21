/*
** EPITECH PROJECT, 2018
** libfox_io
** File description:
** Write a string
*/

#include "private/__foxio.h"

inline ssize_t fox_puts(char const * const str)
{
    return write(1, str, fox_strlen(str));
}

inline ssize_t fox_eputs(char const * const str)
{
    return write(2, str, fox_strlen(str));
}

inline ssize_t fox_fputs(int fd, char const * const str)
{
    return write(fd, str, fox_strlen(str));
}
