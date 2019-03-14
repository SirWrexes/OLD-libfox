/*
** EPITECH PROJECT, 2018
** libfox_memory
** File description:
** Master header
*/

#ifndef LIBFOX_FOXMEMORY_H
#define LIBFOX_FOXMEMORY_H

#include <malloc.h>
#include <unistd.h>
#include "fox_memory.h"

#ifndef LIBFOX_CHUNKSIZE
    #define LIBFOX_CHUNKSIZE

    //These macros are taken straight from malloc.c
    //https://code.woboq.org/userspace/glibc/malloc/malloc.c.html#_M/chunksize
    #undef PREV_INUSE
    #undef IS_MMAPPED
    #undef NON_MAIN_ARENA
    #undef SIZE_BITS
    #undef mem2chunk
    #undef chunksize_nomask
    #undef chunksize
    #undef SIZE_SZ

    #define PREV_INUSE 0x1u
    #define IS_MMAPPED 0x2u
    #define NON_MAIN_ARENA 0x4u
    #define SIZE_BITS (PREV_INUSE | IS_MMAPPED | NON_MAIN_ARENA)
    #define SIZE_SZ (sizeof (size_t))

    typedef struct mchunkptr* mchunkptr_t;
    struct mchunkptr {
        size_t mchunk_prev_size;  // Size of previous chunk (if free).
        size_t mchunk_size;       // Size in bytes, including overhead.
        struct malloc_chunk* fd;       // double links -- used only if free.
        struct malloc_chunk* bk;
        /* Only used for large blocks: pointer to next larger size.  */
        struct malloc_chunk* fd_nextsize; // double links -- used only if free.
        struct malloc_chunk* bk_nextsize;
    };

    //Convert a pointer to a memory chunk structure
    #define mem2chunk(mem) ((mchunkptr_t)((char*)(mem) - 2 * SIZE_SZ))

    //Like chunksize, but do not mask SIZE_BITS.
    #define chunksize_nomask(p) ((p)->mchunk_size)

    //Get size, ignoring use bits
    #define chunksize(p) (chunksize_nomask(p) & ~(SIZE_BITS))

    //Get the number of allocated bytes (without metadata) for a chunk
    #define allocbytes_chunk(p) (chunksize(p) - 2 * SIZE_SZ)

    //Get the number of allocated bytes (without metadata) for a pointer
    #define allocbytes_ptr(p) (allocbytes_chunk(mem2chunk(p)))
#endif // LIBFOX_CHUNKSIZE

#ifdef LIBFOX_UT
    #define inline
#endif //LIBFOX_UT

#endif //LIBFOX_FOXMEMORY_H
