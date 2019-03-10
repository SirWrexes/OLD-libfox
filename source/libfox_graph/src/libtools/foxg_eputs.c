/*
** EPITECH PROJECT, 2018
** libfox_io
** File description:
** Write a string
*/

#include <unistd.h>
#include "private/__foxgraph.h"

extern inline ssize_t fox_eputs(str3c_t str)
{
    if (str == NULL)
        return write(2, "(null)", 6);
    return write(2, str, fox_strlen(str));
}