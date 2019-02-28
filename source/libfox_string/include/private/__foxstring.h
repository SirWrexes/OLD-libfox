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

#if !(defined FOX_MACRO) && !(defined FOX_STRING_MACRO)
    #define FOX_STRING_MACRO
    #ifndef __A
        # define __A(x) __attribute__(x)
    #endif
    #define IS_ALPHALO(c) ((c) >= 'a' && (c) <= 'z')
    #define IS_ALPHAUP(c) ((c) >= 'A' && (c) <= 'Z')
    #define IS_ALPHA(c) (IS_ALPHALO(c) || IS_ALPHAUP(c))
    #define IS_NUM(c) ((c) >= '0' && (c) <= '9')
    #define IS_ALPHANUM(c) (IS_ALPHA(c) || IS_NUM(c))
    #define IS_EOL(c) ((c) == '\n' || (c) == '\0')
    #define IS_SIGN(c) ((c) == '+' || (c) == '-')
    #define CHAR_TOUPPER(c)  ((c) >= 'a' && (c) <= 'z' ? (c) - 32 : (c))
#endif

#ifndef CCSTR_TYPE
    #define CCSTR_TYPE
    typedef char const * const * const  str4c_t;
    typedef char const * const          str3c_t;
    typedef char const *                str2c_t;
    typedef char *                      str_t;
#endif //CCSTR_TYPE

long fox_pow(long nb, size_t power) __A((const));

#endif //LIBFOX_FOXSTRING_H
