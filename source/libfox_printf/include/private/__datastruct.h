/*
** EPITECH PROJECT, 2018
** libfox
** File description:
** No description
*/

#ifndef LIBFOX_DATASTRUCT_H
#define LIBFOX_DATASTRUCT_H

#include <sys/types.h>

#ifndef FOX_MACRO
    #ifndef __A
        #define __A(x) __attribute__(x)
    #endif // __A

    #ifndef CCSTR_TYPE
        #define CCSTR_TYPE
        typedef char const * const * const  str4c_t;
        typedef char const * const          str3c_t;
        typedef char const *                str2c_t;
        typedef char *                      str_t;
        #endif //CCSTR_TYPE
    #endif // FOX_MACRO

typedef enum {
    FC_PLUS     = 1u << 0u,
    FC_SPACE    = 1u << 1u,
    FC_HASH     = 1u << 2u,
    FC_ZERO     = 1u << 3u,
} flagc_t;

typedef enum {
    LM_NONE     ,   // default
    LM_CHAR     ,   // hh
    LM_SHORT    ,   // h
    LM_LONG     ,   // l
    LM_LLONG    ,   // ll, L, q
    LM_ULONG    ,   // z
} lnmod_t;

typedef enum {
    CS_NONE     ,   // default

    CS_INT      ,   // d, i
    CS_UINT     ,   // u
    CS_BIN      ,   // b
    CS_OCT      ,   // o
    CS_HEXL     ,   // x
    CS_HEXU     ,   // X
    CS_LEN      ,   // n
    CS_PERC     ,   // %
    CS_CHAR     ,   // c
    CS_STR      ,   // s
    CS_STR2     ,   // S

    CS_SENTINEL ,   // To mark the end of the arg array
} cspec_t;

typedef          long long llong_t;
typedef unsigned long long ullong_t;
typedef union {
    char        c   ;
    u_char      uc  ;
    short       h   ;
    ushort      uh  ;
    int         i   ;
    uint        ui  ;
    long        l   ;
    ulong       ul  ;
    llong_t     ll  ;
    ullong_t    ull ;
    char   *    str ;
} fargv_t;

typedef struct {
    ssize_t flength;    // call flag length (including '%')
    uint    flagmask;   // bit mask for flags
    lnmod_t lenmodif;   // length modifier
    cspec_t convspec;   // conversion specifier
    fargv_t argvalue;   // argument value
} farg_t;

#endif //LIBFOX_DATASTRUCT_H
