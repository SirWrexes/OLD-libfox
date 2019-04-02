/*
** EPITECH PROJECT, 2018
** libfox_tests
** File description:
** fox_putc
*/

#include "fox_io.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(xputc, regular_usage, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_putc('x'), 1);
    cr_expect_stdout_eq_str("x");
}

Test(eputc, regular_usage, .init = cr_redirect_stderr)
{
    cr_expect_eq(fox_eputc('x'), 1);
    cr_expect_stderr_eq_str("x");
}

Test(fputc, regular_usage, .init = cr_redirect_stderr)
{
    cr_expect_eq(fox_fputc(2, 'x'), 1);
    cr_expect_stderr_eq_str("x");
}