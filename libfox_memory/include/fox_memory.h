/*
** EPITECH PROJECT, 2018
** libfox_memory
** File description:
** fox_memory prototypes
*/

#ifndef LIBFOX_FOX_MEMORY_H
#define LIBFOX_FOX_MEMORY_H

#include <stdio.h>

#ifndef LIBFOX_CLEANUP
#   define LIBFOX_CLEANUP
#   undef CLEANUP_PT
#   undef CLEANUP_FD
#   undef CLEANUP_FP
#   define CLEANUP_PT __attribute__ ((cleanup(fox_autofree)))
#   define CLEANUP_FD __attribute__ ((cleanup(fox_autoclose_fd)))
#   define CLEANUP_FP __attribute__ ((cleanup(fox_autoclose_fp)))
// For more information about these macros, see
// GNU C documentation about variable attributes
void fox_autofree(void *ptr);
void fox_autoclose_fd(int *fd)  __attribute__ ((nonnull));
void fox_autoclose_fp(FILE **fp);
#endif

// Set pointed memory to given data
__attribute__ ((nonnull, returns_nonnull))
void *fox_memset(void *ptr, size_t n, char data);



#endif //LIBFOX_FOX_MEMORY_H
