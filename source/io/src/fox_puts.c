/*
** EPITECH PROJECT, 2018
** libfox_io
** File description:
** Write a string
*/

#include "private/p_foxio.h"

extern inline ssize_t fox_fputs(int fd, str3c_t str)
{
    if (str == NULL)
        return write(fd, "(null)", 6);
    return write(fd, str, fox_strlen(str));
}

extern inline ssize_t fox_eputs(str3c_t str)
{
    return fox_fputs(2, str);
}

extern inline ssize_t fox_puts(str3c_t str)
{
    return fox_fputs(1, str);
}