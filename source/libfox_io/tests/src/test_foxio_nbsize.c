/*
** EPITECH PROJECT, 2019
** libfox_tests
** File description:
** fox_nbsize
*/

#include "private/p_foxio.h"
#include <criterion/criterion.h>

Test(nbsize, regular_usage)
{
    cr_expect_eq(fox_nbsize(123456), 6);
}

Test(nbsize, zero)
{
    cr_expect_eq(fox_nbsize(0), 1);
}

Test(nbsize, negative_zero)
{
    cr_expect_eq(fox_nbsize(-0), 1);
}

Test(nbsize, negative_regular)
{
    cr_expect_eq(fox_nbsize(-654321), 6);
}