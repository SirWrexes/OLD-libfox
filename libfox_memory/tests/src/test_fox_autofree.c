/*
** EPITECH PROJECT, 2019
** libfox_memory UT
** File description:
** fox_autofree
*/

#include "fox_memory.h"
#include <stddef.h>
#include <signal.h>
#include <criterion/criterion.h>

void *proc_autofree(size_t n)
{
    CLEANUP_PT void *ptr = malloc(n);
    return ptr;
}

Test(autofree, regular_usage, .signal = SIGABRT)
{
    char *test = proc_autofree(12 * sizeof(*test));

    free(test);
}

Test(autofree, manual_call)
{
    char *test = malloc(23);

    fox_autofree(&test);
    cr_expect_null(test);
}

Test(autofree, manual_call_null_ptr)
{
    char *test = NULL;

    fox_autofree(&test);
}