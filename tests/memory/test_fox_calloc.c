/*
** EPITECH PROJECT, 2019
** libfox_memory UT
** File description:
** fox_calloc
*/

#include "fox_memory.h"
#include "test_include.h"

Test(calloc, regular_usage)
{
    char *str = fox_calloc(42, sizeof(*str));

    for (size_t i = 0 ; i < 42 ; i += 1)
        cr_expect_eq(str[i], 0);
}

Test(calloc, null_size)
{
    char *str = fox_calloc(0, sizeof(*str));

    cr_expect_null(str);
}

Test(calloc, null_size2)
{
    char *str = fox_calloc(42, 0);

    cr_expect_null(str);
}

Test(calloc, broken_malloc)
{
    break_malloc_at(0);
    cr_expect_null(fox_calloc(42, sizeof(char*)));
}