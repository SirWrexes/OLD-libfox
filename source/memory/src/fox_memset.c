/*
** EPITECH PROJECT, 2018
** libfox_memory
** File description:
** Set pointed memory to given data
*/

#include "private/p_foxmemory.h"

__attribute__ ((nonnull, returns_nonnull))
void *fox_memset(void *ptr, size_t n, char data)
{
    char *tmp = (char *) ptr;

    for (size_t i = 0 ; i < n ; i += 1)
        tmp[i] = data;
    return ptr;
}