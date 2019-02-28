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

#ifndef FOX_MACRO
    #undef ITOC
    #undef ABS
    #define ITOC(i) ((char) ((i) + '0'))
    #define ABS(x) ((x) >= 0 ? (x) : -(x))
    #ifndef __A
        #define __A(x) __attribute__(x)
    #endif
#endif // FOX_MACRO

#ifdef LIBFOX_UT
    #define inline
#endif //LIBFOX_UT

size_t fox_strlen(char const *str) __A((pure));
size_t fox_nbsize(int nb)          __A((const));

#endif //LIBFOX_FOXDISPLAY_H
