/*
** EPITECH PROJECT, 2019
** libfox_memory
** File description:
** fox_autoclose
*/

#include "fox_memory.h"
#include "test_include.h"

__attribute__ ((noinline))
static FILE *proc_autoclose_fp(void)
{
    CLEANUP_FP FILE *ptr = fopen("Makefile", "r");

    return ptr;
}

__attribute__ ((noinline))
static int proc_autoclose_fd(void)
{
    CLEANUP_FD int fd = open("Makefile", O_RDONLY);

    cr_expect_neq(fd, -1);
    return fd;
}

Test(autoclose_fp, regular_usage, .signal = SIGABRT)
{
    FILE *test = proc_autoclose_fp();

    fclose(test);
}

Test(autoclose_fd, regular_usage)
{
    int test = proc_autoclose_fd();

    cr_expect_eq(close(test), -1);
}

Test(autoclose_fp, manual_call)
{
    FILE *test = fopen("Makefile", "r");

    cr_expect_not_null(test);
    fox_autoclose_fp(&test);
    cr_expect_null(test);
}

Test(autoclose_fd, manual_call)
{
    int test = open("Makefile", O_RDONLY);

    cr_expect_neq(test, -1);
    fox_autoclose_fd(&test);
    cr_expect_eq(test, -1);
    cr_expect_eq(close(test), -1);
}

Test(autoclose_fp, manual_call_null_fp)
{
    FILE *test = NULL;

    fox_autoclose_fp(&test);
    cr_expect_null(test);
}

Test(autoclose_fd, manual_call_bad_fd)
{
    int test = -1;

    fox_autoclose_fd(&test);
}