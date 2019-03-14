/*
** EPITECH PROJECT, 2019
** libfox_string
** File description:
** Private header
*/

#ifndef LIBFOX_FOXSTRING_H
#define LIBFOX_FOXSTRING_H

#include <stddef.h>
#include <stdbool.h>
#include <limits.h>
#include <malloc.h>
#include "fox_define.h"

size_t fox_strlen(str3c_t str)      __a((pure));
str_t fox_revstr(str_t str)         __a((nonnull));
long fox_pow(long nb, size_t power) __a((const));

#endif //LIBFOX_FOXSTRING_H
