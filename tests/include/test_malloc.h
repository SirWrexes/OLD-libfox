/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** Flexible malloc testing wrapper header
*/

#ifndef LIBFOX_MALLOC_WRAPPER_H
#define LIBFOX_MALLOC_WRAPPER_H

#include <sys/types.h>
#include <stdbool.h>

#define real_malloc __real_malloc
void *real_malloc(size_t size);

#define wrap_malloc __wrap_malloc
void *wrap_malloc(size_t size);

void break_malloc_at(size_t n);
void reset_malloc_cpt(void);

#endif //LIBFOX_MALLOC_WRAPPER_H