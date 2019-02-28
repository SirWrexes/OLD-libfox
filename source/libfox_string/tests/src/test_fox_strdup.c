/*
** EPITECH PROJECT, 2019
** libfox UT
** File description:
** fox_strdup
*/

#include <criterion/criterion.h>
#include "fox_string.h"

Test(strdup, null_string)
{
    cr_expect_null(fox_strdup(NULL));
}

Test(strdup, empty_array)
{
    char *arr = {0};

    cr_expect_null(fox_strdup(arr));
}

Test(strdup, empty_string)
{
    char *dest = fox_strdup("");

    cr_expect_str_eq(dest, "");
}

Test(strdup, normal_string)
{
    char *str = fox_strdup("Never argue with the data.");

    cr_expect_str_eq(str, "Never argue with the data.");
}
