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
    size_t acmax,
    farg_t fargs[acmax],
    str2c_t fstr,
    va_list ap
) __A((cold, leaf));
void get_argvalue_int(farg_t *farg, va_list ap)         __A((nonnull));
void get_argvalue_unsigned(farg_t *farg, va_list ap)    __A((nonnull));
void get_argvalue_other(farg_t *farg, va_list ap)       __A((nonnull));

size_t n_printed_bytes(ssize_t nplus)   __A((hot, leaf));

void print_integer(farg_t const *arg)   __A((nonnull));
void print_unsigned(farg_t const *arg)  __A((nonnull));
void print_other(farg_t const *arg)     __A((nonnull));

size_t fox_strlen(str2c_t str)  __A((pure));
void fox_putc(char c);
void fox_putnpc(char c);
void fox_puts(str2c_t str);
void fox_puts2(str2c_t str);

size_t fox_nbsize(llong_t nb)   __A((const));
size_t fox_unbsize(ullong_t nb) __A((const));

void fox_putint(int nbr);
void fox_putuint(uint nbr);
void fox_putllong(llong_t nbr);
void fox_putullong(ullong_t nbr);

void fox_putuint_base(uint nbr, str2c_t base)       __A((nonnull));
void fox_putullong_base(ullong_t nbr, str2c_t base) __A((nonnull));

#endif //LIBFOX_PRIV_FOXPRINTF_H
