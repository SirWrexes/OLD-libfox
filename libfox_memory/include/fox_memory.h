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

// Get the number of allocated bytes for a pointer
__attribute__ ((pure))
size_t fox_allocbytes(void *ptr);

// Set pointed memory to given data
__attribute__ ((nonnull, returns_nonnull))
void *fox_memset(void *ptr, size_t n, char data);

// Allocate a pointer to n memebers of size and memset it to 0
__attribute__ ((malloc, alloc_size(1, 2)))
void *fox_calloc(size_t n, size_t size);

// Change size of allocated memory
//  -- Reallocating to 0 is like calling free.
//  -- Reallocating a null pointer is like calling malloc
// This function may cause conditional jump errors
__attribute__ ((alloc_size(2)))
void *fox_realloc(void *ptr, size_t newsize);

#endif //LIBFOX_FOX_MEMORY_H
