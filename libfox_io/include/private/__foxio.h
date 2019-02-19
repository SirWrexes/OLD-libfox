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
#include "fox_macro.h"

size_t fox_strlen(char const *str)  __attribute__ ((pure));
size_t fox_nbsize(int nb)           __attribute__ ((const));

#endif //LIBFOX_FOXDISPLAY_H
