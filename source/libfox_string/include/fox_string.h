/*
** EPITECH PROJECT, 2019
** libfox_string
** File description:
** Public header
*/

#ifndef LIBFOX_FOX_STRING_H
#define LIBFOX_FOX_STRING_H

#include <stddef.h>

#if !(defined FOX_MACRO) && !(defined __A)
    #define __A(x) __attribute__(x)
#endif

#ifndef CCSTR_TYPE
    #define CCSTR_TYPE
    typedef char const * const * const  str4c_t;
    typedef char const * const          str3c_t;
    typedef char const *                str2c_t;
    typedef char *                      str_t;
#endif //CCSTR_TYPE

// Check if s1 is the same as s2 [up to n character]
int fox_strcmp(str3c_t s1, str3c_t s2)             __A((nonnull, pure));
char fox_strncmp(str3c_t s1, str3c_t s2, size_t n) __A((nonnull, pure));

#endif //LIBFOX_FOX_STRING_H
