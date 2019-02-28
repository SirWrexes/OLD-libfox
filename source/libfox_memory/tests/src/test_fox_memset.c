/*
** EPITECH PROJECT, 2019
** libfox_memory UT
** File description:
** fox_memset
*/

#include "fox_memory.h"
#include <criterion/criterion.h>

Test(fox_memset, set_to_char_0)
{
    char *test = calloc(5, sizeof(char));
    char *real = calloc(5, sizeof(char));

    test = fox_memset(test, 4 * sizeof(char), '0');
    real = memset(test, '0', 4 * sizeof(char));
    cr_expect_str_eq(test, real);
}

Test(fox_memset, set_to_zero)
{
    char *test = calloc(5, sizeof(char));

    test = fox_memset(test, 4 * sizeof(char), 0);
    cr_expect_str_empty(test);
}

Test(fox_memset, set_to_null_char)
{
    char *test = calloc(5, sizeof(char));

    test = fox_memset(test, 4 * sizeof(char), '\0');
    cr_expect_str_empty(test);
}