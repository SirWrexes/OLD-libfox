/*
** EPITECH PROJECT, 2019
** libfox_IO
** File description:
** putllong UT
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_io.h"

Test(putllong, regular_usage, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_putllong(123), strlen("123"));
    cr_expect_stdout_eq_str("123");
}

Test(putllong, negative_nb, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_putllong(-123), strlen("-123"));
    cr_expect_stdout_eq_str("-123");
}

Test(putllong, zero, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_putllong(0), strlen("0"));
    cr_expect_stdout_eq_str("0");
}

Test(putllong, negative_zero, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_putllong(-0), strlen("0"));
    cr_expect_stdout_eq_str("0");
}

Test(eputllong, regular_usage, .init = cr_redirect_stderr)
{
    cr_expect_eq(fox_eputllong(123), strlen("123"));
    cr_expect_stderr_eq_str("123");
}

Test(eputllong, negative_nb, .init = cr_redirect_stderr)
{
    cr_expect_eq(fox_eputllong(-123), strlen("-123"));
    cr_expect_stderr_eq_str("-123");
}

Test(eputllong, zero, .init = cr_redirect_stderr)
{
    cr_expect_eq(fox_eputllong(0), strlen("0"));
    cr_expect_stderr_eq_str("0");
}

Test(eputllong, negative_zero, .init = cr_redirect_stderr)
{
    cr_expect_eq(fox_eputllong(-0), strlen("0"));
    cr_expect_stderr_eq_str("0");
}

Test(fputllong, regular_usage, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_fputllong(1, 123), strlen("123"));
    cr_expect_stdout_eq_str("123");
}

Test(fputllong, negative_nb, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_fputllong(1, -123), strlen("-123"));
    cr_expect_stdout_eq_str("-123");
}

Test(fputllong, zero, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_fputllong(1, 0), strlen("0"));
    cr_expect_stdout_eq_str("0");
}

Test(fputllong, negative_zero, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_fputllong(1, -0), strlen("0"));
    cr_expect_stdout_eq_str("0");
}