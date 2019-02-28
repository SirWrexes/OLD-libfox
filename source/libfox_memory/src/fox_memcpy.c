/*
** EPITECH PROJECT, 2018
** libfox_memory
** File description:
** Copy up to n bytes from src to dst, stop when c is found
*/

#include <stdbool.h>
#include "private/__foxmemory.h"
#include "fox_memory.h"

__attribute__ ((nonnull))
void *fox_memcpy(void *dst, void *src, int c, size_t n)
{
    char *tmpdst = (char *) dst;
    char *tmpsrc = (char *) src;
    size_t dstsz = fox_allocbytes(dst);
    size_t srcsz = fox_allocbytes(src);
    bool foundc = false;
    size_t i;

    for (i = 0 ; i < dstsz && i < srcsz && i < n && !foundc ; i += 1) {
        tmpdst[i] = tmpsrc[i];
        foundc = (tmpsrc[i] == c);
    }
    return foundc ? (void *) tmpdst + i : NULL;
}