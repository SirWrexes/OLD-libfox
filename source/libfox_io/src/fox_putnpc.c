/*
** EPITECH PROJECT, 2019
** libfox_IO
** File description:
** Print non printable chars in octal
*/

#include "fox_io.h"

extern inline ssize_t fox_fputnpc(int fd, char c)
{
    return fox_fputuint_base(fd, (uint) c, "01234567");
}

extern inline ssize_t fox_eputnpc(char c)
{
    return fox_fputnpc(2, c);
}

extern inline ssize_t fox_putnpc(char c)
{
    return fox_fputnpc(1, c);
}