/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "fox_string.h"

Test(atoi, zero_pos)
{
    char *str = strdup("0");

    cr_expect_eq(fox_atoi(str), atoi(str));
}

Test(atoi, zero_neg)
{
    char *str = strdup("-0");

    cr_expect_eq(fox_atoi(str), atoi(str));
}

Test(atoi, garbage_then_number_pos)
{
    char *str = strdup("garbage42");

    cr_expect_eq(fox_atoi(str), atoi(str));
}

Test(atoi, garbage_then_number_neg)
{
    char *str = strdup("junk then -5");

    cr_expect_eq(fox_atoi(str), atoi(str));
}