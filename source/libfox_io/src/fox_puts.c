/*
** EPITECH PROJECT, 2018
** libfox_io
** File description:
** Write a string
*/

#include "private/p_foxio.h"

extern inline ssize_t fox_puts(char const * const str)
{
    if (str == NULL)
        return write(1, "(null)", 6);
    return write(1, str, fox_strlen(str));
}

extern inline ssize_t fox_eputs(char const * const str)
{
    if (str == NULL)
        return write(2, "(null)", 6);
    return write(2, str, fox_strlen(str));
}

extern inline ssize_t fox_fputs(int fd, char const * const str)
{
    if (str == NULL)
        return write(fd, "(null)", 6);
    return write(fd, str, fox_strlen(str));
}
