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
#include "fox_io.h"

#ifdef LIBFOX_UT
    #define inline
#endif //LIBFOX_UT

size_t fox_strlen(char const *str) __a((pure));
size_t fox_intsize(int nb)          __a((const));
size_t fox_uintsize(uint nb)        __a((const));

#endif //LIBFOX_FOXDISPLAY_H
