/*
** EPITECH PROJECT, 2019
** libfox_memory UT
** File description:
** fox_memcpy
*/

#include "fox_memory.h"
#include <criterion/criterion.h>

Test(memcpy, regular_usage)
{
    char *src = "This is a test.";
    size_t srclen = strlen(src);
    char *dstend = NULL;
    char dst[srclen];

    for (size_t i = 0 ; i < srclen; i += 1)
        dst[i] = '\0';
    dstend = fox_memcpy(dst, src, '\0', srclen);
    cr_expect_str_eq(src, dst);
    cr_expect_null(dstend);
}

Test(memcpy, found_c)
{
    char *src = "This is a test.";
    size_t srclen = strlen(src);
    size_t i = 0;
    char *dstend = NULL;
    char dst[srclen];

    for (i = 0 ; i < srclen; i += 1)
        dst[i] = '\0';
    dstend = fox_memcpy(dst, src, 'a', srclen);
    for (i = 0 ; src[i] != 'a' ; i += 1)
        cr_expect_eq(src[i], dst[i]);
    cr_assert_not_null(dstend);
    cr_expect_eq(dstend, dst + i + 1);
}