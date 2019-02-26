/*
** EPITECH PROJECT, 2018
** libfox_io
** File description:
** Master header
*/

#ifndef LIBFOX_FOXDISPLAY_H
#define LIBFOX_FOXDISPLAY_H

#include <unistd.h>
#include <stdbool.h>

#ifndef LIBFOX_FOX_MACRO_H
#ifndef LIBFOX_IO_MACRO
#   undef ITOC
#   undef ABS

//  Numeric value to ascii char value
#   define ITOC(i) ((char) ((i) + '0'))

//  Get the absolute value of a number
#   define ABS(x) ((x) >= 0 ? (x) : -(x))

#   define LIBFOX_IO_MACRO
#   endif //LIBFOX_IO_MACRO
#endif // LIBFOX_FOX_MACRO_H

#ifdef LIBFOX_IO_UT
#   define inline
#endif //LIBFOX_IO_UT

size_t fox_strlen(char const *str)  __attribute__ ((pure));
size_t fox_nbsize(int nb)           __attribute__ ((const));

#endif //LIBFOX_FOXDISPLAY_H
