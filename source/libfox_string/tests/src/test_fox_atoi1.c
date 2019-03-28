/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** UT for atoi
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "fox_string.h"

Test(atoi, multi_digit_pos)
{
    char *str = strdup("123");

    cr_expect_eq(fox_atoi(str), atoi(str));
}

Test(atoi, uni_digit_pos)
{
    char *str = strdup("1");

    cr_expect_eq(fox_atoi(str), atoi(str));
}

Test(atoi, multi_digit_neg)
{
    char *str = strdup("-958");

    cr_expect_eq(fox_atoi(str), atoi(str));
}

Test(atoi, uni_digit_neg)
{
    char *str = strdup("-3");

    cr_expect_eq(fox_atoi(str), atoi(str));
}