/*
** EPITECH PROJECT, 2019
** libfox_tests
** File description:
** fox_strlen
*/

#include "private/__foxio.h"
#include <criterion/criterion.h>

Test(strlen, 1_char)
{
    cr_expect_eq(fox_strlen("a"), strlen("a"));
}

Test(strlen, 2_char)
{
    cr_expect_eq(fox_strlen("aa"), strlen("aa"));
}

Test(strlen, 3_char)
{
    cr_expect_eq(fox_strlen("aaa"), strlen("aaa"));
}

Test(strlen, 4_char)
{
    cr_expect_eq(fox_strlen("aaaa"), strlen("aaaa"));
}

Test(strlen, 5_char)
{
    cr_expect_eq(fox_strlen("aaaaa"), strlen("aaaaa"));
}

Test(strlen, 6_char)
{
    cr_expect_eq(fox_strlen("aaaaaa"), strlen("aaaaaa"));
}

Test(strlen, 7_char)
{
    cr_expect_eq(fox_strlen("aaaaaaa"), strlen("aaaaaaa"));
}

Test(strlen, empty_string)
{
    cr_expect_eq(fox_strlen(""), strlen(""));
}

Test(strlen, null_string)
{
    cr_expect_eq(fox_strlen(NULL), 0);
}