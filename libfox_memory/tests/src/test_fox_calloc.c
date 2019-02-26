/*
** EPITECH PROJECT, 2019
** libfox_memory UT
** File description:
** fox_calloc
*/

#include "fox_memory.h"
#include <criterion/criterion.h>

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