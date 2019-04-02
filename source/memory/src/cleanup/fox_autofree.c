/*
** EPITECH PROJECT, 2018
** libfox_memor -- cleanup
** File description:
** Automaticaly free any pointer
*/

#include "private/p_foxmemory.h"

extern inline __a((nonnull))
void fox_autofree(void *ptr)
{
    if (*(void **)ptr == NULL)
        return;
    free(*(void **)ptr);
    *(void **)ptr = NULL;
}