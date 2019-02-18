/*
** EPITECH PROJECT, 2018
** libfox_memory
** File description:
** Get the number of allocated bytes for a pointer
*/

#include "private/__foxmemory.h"

__attribute__ ((pure))
inline size_t fox_allocbytes(void *ptr)
{
    return allocbytes_ptr(ptr);
}