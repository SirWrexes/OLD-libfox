/*
** EPITECH PROJECT, 2019
** libfox UT
** File description:
** fox_strdup
*/

#include "fox_string.h"
#include "test_malloc.h"
#include <criterion/criterion.h>

TestSuite(strdup, .fini = reset_malloc_cpt);

Test(strdup, null_string)
{
    cr_expect_null(fox_strdup(NULL));
}

Test(strdup, empty_array)
{
    str_t arr = {0};

    cr_expect_null(fox_strdup(arr));
}

Test(strdup, empty_string)
{
    str_t str = fox_strdup("");

    cr_assert_not_null(str);
    cr_expect_str_eq(str, "");
}

Test(strdup, normal_string)
{
    str_t str = fox_strdup("Never argue with the data.");

    cr_assert_not_null(str);
    cr_expect_str_eq(str, "Never argue with the data.");
}

Test(strdup, broken_malloc)
{
    break_malloc_at(1);
    cr_expect_null(fox_strdup("c kassé :("));
}