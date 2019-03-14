/*
** EPITECH PROJECT, 2018
** libfox_io
** File description:
** Write a single char
*/

#include "private/p_foxio.h"

extern inline ssize_t fox_fputc(int fd, char c)
{
    return write(fd, &c, 1);
}

extern inline ssize_t fox_eputc(char c)
{
    return fox_fputc(2, c);
}

extern inline ssize_t fox_putc(char c)
{
    return fox_fputc(1, c);
}

