/*
** EPITECH PROJECT, 2019
** libfox_MATH
** File description:
** nbsize UT
*/

#include "fox_math.h"
#include <criterion/criterion.h>

Test(nbsize, intsize_1)
{
    cr_expect_eq(fox_intsize(0), 1);
}

Test(nbsize, intsize_2)
{
    cr_expect_eq(fox_intsize(123456), 6);
}

Test(nbsize, intsize_3)
{
    cr_expect_eq(fox_intsize(-56), 2);
}

Test(nbsize, intsize_4)
{
    cr_expect_eq(fox_intsize(9999), 4);
}

Test(nbsize, intsize_5)
{
    cr_expect_eq(fox_intsize(1234567890), 10);
}