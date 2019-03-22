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

void break_malloc_at(size_t n);
void reset_malloc_cpt(void);

#endif //LIBFOX_MALLOC_WRAPPER_H
