/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#ifndef LIBFOX_FOX_MATH_H
#define LIBFOX_FOX_MATH_H

#include <sys/types.h>
#include "fox_define.h"

size_t fox_ullongsize(ullong_t nb)  __a((const));
size_t fox_llongsize(llong_t nb)    __a((const));
size_t fox_uintsize(uint nb)        __a((const));
size_t fox_intsize(int nb)          __a((const));

#endif //LIBFOX_FOX_MATH_H
