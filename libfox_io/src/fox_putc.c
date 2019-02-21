/*
** EPITECH PROJECT, 2018
** libfox_io
** File description:
** Write a single char
*/

#include "private/__foxdisplay.h"

inline ssize_t fox_putc(char c)
{
    return write(1, &c, 1);
}

inline ssize_t fox_eputc(char c)
{
    return write(2, &c, 1);
}

inline ssize_t fox_fputc(int fd, char c)
{
    return write(fd, &c, 1);
}