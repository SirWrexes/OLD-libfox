/*
** EPITECH PROJECT, 2018
** libfox_tests
** File description:
** fox_putc
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libfox_display.h"

Test(putc, regular_usage)
{
    cr_expect_eq(fox_putc('x'), 1);
    cr_expect_stdout_eq_str("x");
}

Test(eputc, regular_usage)
{
    cr_expect_eq(fox_eputc('x'), 1);
    cr_expect_stderr_eq_str("x");
}

Test(fputc, regular_usage)
{
    cr_expect_eq(fox_fputc(2, 'x'), 1);
    cr_expect_stderr_eq_str("x");
}