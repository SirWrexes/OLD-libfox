/*
** EPITECH PROJECT, 2019
** libfox UT
** File description:
** fox_strlen
*/

#include <criterion/criterion.h>
#include "fox_string.h"

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