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
#include "p_datastruct.h"
#include "p_preprocessor.h"
#include "private/p_foxio.h"

bool fpf_getargs(
    size_t acmax,
    farg_t fargs[acmax],
    str2c_t fstr,
    va_list ap
) __a((cold, leaf));

void get_argvalue_int(farg_t *farg, va_list ap)         __a((nonnull));
void get_argvalue_unsigned(farg_t *farg, va_list ap)    __a((nonnull));
void get_argvalue_other(farg_t *farg, va_list ap)       __a((nonnull));

size_t n_printed_bytes(ssize_t nplus)   __a((hot, leaf));

ssize_t print_integer(int fd, farg_t const *arg)   __a((nonnull));
ssize_t print_unsigned(int fd, farg_t const *arg)  __a((nonnull));
ssize_t print_other(int fd, farg_t const *arg)     __a((nonnull));

#endif //LIBFOX_PRIV_FOXPRINTF_H
