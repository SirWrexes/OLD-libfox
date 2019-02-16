/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Because we need a prototype
*/

#ifndef LIBFOX_PRINTF_FOX_PRINTF_H
#define LIBFOX_PRINTF_FOX_PRINTF_H

#include <sys/types.h>

__attribute__ ((nonnull, format(printf, 1,2)))
ssize_t fox_printf(char const *fstr, ...);

#endif //LIBFOX_PRINTF_FOX_PRINTF_H
