/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** fox_putint
*/

#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_io.h"

Test(putint, regular_usage, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_putint(123), strlen("123"));
    cr_expect_stdout_eq_str("123");
}

Test(putint, negative_nb, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_putint(-123), strlen("-123"));
    cr_expect_stdout_eq_str("-123");
}

Test(putint, zero, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_putint(0), strlen("0"));
    cr_expect_stdout_eq_str("0");
}

Test(putint, negative_zero, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_putint(-0), strlen("0"));
    cr_expect_stdout_eq_str("0");
}

Test(eputint, regular_usage, .init = cr_redirect_stderr)
{
    cr_expect_eq(fox_eputint(123), strlen("123"));
    cr_expect_stderr_eq_str("123");
}

Test(eputint, negative_nb, .init = cr_redirect_stderr)
{
    cr_expect_eq(fox_eputint(-123), strlen("-123"));
    cr_expect_stderr_eq_str("-123");
}

Test(eputint, zero, .init = cr_redirect_stderr)
{
    cr_expect_eq(fox_eputint(0), strlen("0"));
    cr_expect_stderr_eq_str("0");
}

Test(eputint, negative_zero, .init = cr_redirect_stderr)
{
    cr_expect_eq(fox_eputint(-0), strlen("0"));
    cr_expect_stderr_eq_str("0");
}

Test(fputint, regular_usage, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_fputint(1, 123), strlen("123"));
    cr_expect_stdout_eq_str("123");
}

Test(fputint, negative_nb, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_fputint(1, -123), strlen("-123"));
    cr_expect_stdout_eq_str("-123");
}

Test(fputint, zero, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_fputint(1, 0), strlen("0"));
    cr_expect_stdout_eq_str("0");
}

Test(fputint, negative_zero, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_fputint(1, -0), strlen("0"));
    cr_expect_stdout_eq_str("0");
}
