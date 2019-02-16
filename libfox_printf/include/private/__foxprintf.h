/*
** EPITECH PROJECT, 2018
** libfox-printf
** File description:
** Printf : private header
*/

#ifndef LIBFOX_PRIV_FOXPRINTF_H
#define LIBFOX_PRIV_FOXPRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>
#include <sys/types.h>
#include "__datastruct.h"
#include "__preprocessor.h"

bool fpf_getargs(
    size_t      acmax       ,
    farg_t      fargs[acmax],
    char const *fstr        ,
    va_list     ap          ) __attribute__ ((cold, leaf));
void get_argvalue_int(
    farg_t *farg     ,
    va_list ap       ) __attribute__ ((nonnull));
void get_argvalue_unsigned(
    farg_t *farg          ,
    va_list ap            ) __attribute__ ((nonnull));
void get_argvalue_other(
    farg_t *farg       ,
    va_list ap         ) __attribute__ ((nonnull));

size_t n_printed_bytes(ssize_t nplus)   __attribute__ ((hot, leaf));

void print_integer(farg_t const *arg)   __attribute__ ((nonnull));
void print_unsigned(farg_t const *arg)  __attribute__ ((nonnull));
void print_other(farg_t const *arg)     __attribute__ ((nonnull));

size_t fox_strlen(char const *str)  __attribute__ ((pure));
void fox_putc(char c);
void fox_putnpc(char c);
void fox_puts(char const *str);
void fox_puts2(char const *str);

size_t fox_nbsize(llong_t nb)   __attribute__ ((const));
size_t fox_unbsize(ullong_t nb) __attribute__ ((const));

void fox_putint(int nbr);
void fox_putuint(uint nbr);
void fox_putllong(llong_t nbr);
void fox_putullong(ullong_t nbr);

void fox_putuint_base(
    uint nbr         ,
    char const *base ) __attribute__ ((nonnull));

void fox_putullong_base(
    ullong_t nbr       ,
    char const *base   ) __attribute__ ((nonnull));

#endif //LIBFOX_PRIV_FOXPRINTF_H
