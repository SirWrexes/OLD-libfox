/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include <criterion/criterion.h>
#include "fox_string.h"

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