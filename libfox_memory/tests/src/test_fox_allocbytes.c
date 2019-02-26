/*
** EPITECH PROJECT, 2019
** libfox_memory UT
** File description:
** fox_allocbytes
*/

#include "fox_memory.h"
#include <criterion/criterion.h>

Test(allocbytes, regular_usage_char, .disabled = true)
{
    size_t n = 25;
    char *ptr = malloc(n * sizeof(*ptr));
    size_t alloc = fox_allocbytes(ptr);

    cr_expect_eq(alloc, n * sizeof(*ptr), "char alloc = %zu\n", alloc);
    free(ptr);
}

Test(allocbytes, regular_usage_uchar, .disabled = true)
{
    size_t n = 25;
    u_char *ptr = malloc(n * sizeof(*ptr));
    size_t alloc = fox_allocbytes(ptr);

    cr_expect_eq(alloc, n * sizeof(*ptr), "uchar alloc = %zu\n", alloc);
    free(ptr);
}

Test(allocbytes, regular_usage_short, .disabled = true)
{
    size_t n = 25;
    short *ptr = malloc(n * sizeof(*ptr));
    size_t alloc = fox_allocbytes(ptr);

    cr_expect_eq(alloc, n * sizeof(*ptr), "short alloc = %zu\n", alloc);
    free(ptr);
}

Test(allocbytes, regular_usage_ushort, .disabled = true)
{
    size_t n = 25;
    ushort *ptr = malloc(n * sizeof(*ptr));
    size_t alloc = fox_allocbytes(ptr);

    cr_expect_eq(alloc, n * sizeof(*ptr), "ushort alloc = %zu\n", alloc);
    free(ptr);
}

Test(allocbytes, regular_usage_int, .disabled = true)
{
    size_t n = 25;
    int *ptr = malloc(n * sizeof(*ptr));
    size_t alloc = fox_allocbytes(ptr);

    cr_expect_eq(alloc, n * sizeof(*ptr), "int alloc = %zu\n", alloc);
    free(ptr);
}

Test(allocbytes, regular_usage_uint, .disabled = true)
{
    size_t n = 25;
    uint *ptr = malloc(n * sizeof(*ptr));
    size_t alloc = fox_allocbytes(ptr);

    cr_expect_eq(alloc, n * sizeof(*ptr), "uint alloc = %zu\n", alloc);
    free(ptr);
}

Test(allocbytes, regular_usage_long, .disabled = true)
{
    size_t n = 25;
    long *ptr = malloc(n * sizeof(*ptr));
    size_t alloc = fox_allocbytes(ptr);

    cr_expect_eq(alloc, n * sizeof(*ptr), "long alloc = %zu\n", alloc);
    free(ptr);
}

Test(allocbytes, regular_usage_ulong, .disabled = true)
{
    size_t n = 25;
    ulong *ptr = malloc(n * sizeof(*ptr));
    size_t alloc = fox_allocbytes(ptr);

    cr_expect_eq(alloc, n * sizeof(*ptr), "ulong alloc = %zu\n", alloc);
    free(ptr);
}

Test(allocbytes, regular_usage_llong, .disabled = true)
{
    size_t n = 25;
    long long *ptr = malloc(n * sizeof(*ptr));
    size_t alloc = fox_allocbytes(ptr);

    cr_expect_eq(alloc, n * sizeof(*ptr), "llong alloc = %zu\n", alloc);
    free(ptr);
}

Test(allocbytes, regular_usage_ullong, .disabled = true)
{
    size_t n = 25;
    unsigned long long int *ptr = malloc(n * sizeof(*ptr));
    size_t alloc = fox_allocbytes(ptr);

    cr_expect_eq(alloc, n * sizeof(*ptr), "ullong alloc = %zu\n", alloc);
    free(ptr);
}