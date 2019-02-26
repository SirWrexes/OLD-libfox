/*
** EPITECH PROJECT, 2018
** libfox
** File description:
** No description
*/

#include "private/__foxmemory.h"
#include "fox_memory.h"

__attribute__ ((alloc_size(2)))
void *fox_realloc(void *ptr, size_t newsize)
{
    void *newptr = NULL;
    char *tmpdst = NULL;
    char *tmpsrc = (char *) ptr;

    if (ptr == NULL)
        return malloc(newsize);
    else if (newsize == 0) {
        free(ptr);
        return NULL;
    } else {
        newptr = malloc(newsize);
        tmpdst = (char *) newptr;
        for (size_t i = 0 ; i < newsize ; i += 1)
            tmpdst[i] = tmpsrc[i];
        return newptr;
    }
}

//__attribute__ ((alloc_size(2)))
//void *fox_realloc(void *ptr, size_t newsize)
//{
//    void *newptr = NULL;
//    char *tmpdst = NULL;
//    char *tmpsrc = (char *) ptr;
//    size_t oldmemsz = 0;
//
//    if (ptr == NULL)
//        return malloc(newsize);
//    else if (newsize == 0) {
//        free(ptr);
//        return NULL;
//    } else {
//        oldmemsz = fox_allocbytes(ptr);
//        newptr = malloc(newsize);
//        tmpdst = (char *) newptr;
//        for (size_t i = 0 ; i < oldmemsz && i < newsize ; i += 1)
//            tmpdst[i] = tmpsrc[i];
//        return newptr;
//    }
//}