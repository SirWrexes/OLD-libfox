/*
** EPITECH PROJECT, 2019
** libfox_tests
** File description:
** Testing fox_puts
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "fox_io.h"

static char const *str = "This is a test.";

Test(fox_puts, regular_usage, .init = cr_redirect_stdout)
{

    cr_expect_eq(fox_puts(str), strlen(str));
    cr_expect_stdout_eq_str(str);
}

Test(fox_puts, empty_string, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_puts(""), 0);
}

Test(fox_puts, null_string, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_puts(NULL), strlen("(null)"));
    cr_expect_stdout_eq_str("(null)\n");
}

Test(fox_eputs, regular_usage, .init = cr_redirect_stderr)
{

    cr_expect_eq(fox_eputs(str), strlen(str));
    cr_expect_stderr_eq_str(str);
}

Test(fox_eputs, empty_string, .init = cr_redirect_stderr)
{
    cr_expect_eq(fox_eputs(""), 0);
}

Test(fox_eputs, null_string, .init = cr_redirect_stderr)
{
    cr_expect_eq(fox_eputs(NULL), strlen("(null)"));
    cr_expect_stderr_eq_str("(null)\n");
}

Test(fox_fputs, regular_usage, .init = cr_redirect_stdout)
{

    cr_expect_eq(fox_fputs(1, str), strlen(str));
    cr_expect_stdout_eq_str(str);
}

Test(fox_fputs, empty_string, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_fputs(1, ""), 0);
}

Test(fox_fputs, null_string, .init = cr_redirect_stdout)
{
    cr_expect_eq(fox_fputs(1, NULL), strlen("(null)"));
    cr_expect_stdout_eq_str("(null)\n");
}

