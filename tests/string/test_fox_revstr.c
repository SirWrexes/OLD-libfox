/*
** EPITECH PROJECT, 2018
** libfox UT
** File description:
** revstr
*/

#include <criterion/criterion.h>
#include "fox_string.h"

Test(revstr, empty_string)
{
    char *str = "";

    cr_expect_str_eq(fox_revstr(str), "");
}

Test(revstr, string_with_only_one_char)
{
    char *str = "a";

    cr_expect_str_eq(fox_revstr(str), "a");
}

Test(revstr, normal_string)
{
    char *str = strdup("aeiou");

    cr_expect_str_eq(fox_revstr(str), "uoiea");
}
