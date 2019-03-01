/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** Unit tests for my strrev
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_revstr, empty_string)
{
    char *str = "";

    cr_expect_str_eq(my_revstr(str), "");
}

Test(my_revstr, string_with_only_one_char)
{
    char *str = "a";

    cr_expect_str_eq(my_revstr(str), "a");
}

Test(my_revstr, normal_string)
{
    char *str = strdup("aeiou");

    cr_expect_str_eq(my_revstr(str), "uoiea");
}
