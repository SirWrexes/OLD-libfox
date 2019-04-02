/*
** EPITECH PROJECT, 2018
** libfox_memory
** File description:
** Get the number of allocated bytes for a pointer
*/

#include "private/p_foxmemory.h"

__attribute__ ((
    deprecated(
    "This functions needs a rework. "
    "Currently gives undefined results"
    )
))
__attribute__ ((pure))
inline size_t fox_allocbytes(void *ptr)
{
    return allocbytes_ptr(ptr);
}