/*
** EPITECH PROJECT, 2018
** libfox_memory
** File description:
** Allocate a pointer to n memebers of size and memset it to 0
*/

#include "private/p_foxmemory.h"
#include "fox_memory.h"

__attribute__ ((malloc, alloc_size(1, 2)))
void *fox_calloc(size_t n, size_t size)
{
    void *ptr = n && size ? malloc(n * size) : NULL;

    if (ptr == NULL)
        return NULL;
    fox_memset(ptr, n * size, 0);
    return ptr;
}