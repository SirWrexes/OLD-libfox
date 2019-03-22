/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "test_malloc.h"
#include <criterion/criterion.h>

TestSuite(mwrap, .fini = reset_malloc_cpt);

Test(mwrap, no_break)
{
    char *str = malloc(3 * sizeof(*str));

    cr_assert_not_null(str);
    free(str);
    str = NULL;
    reset_malloc_cpt();
    str = malloc(3 * sizeof(*str));
    cr_assert_not_null(str);
    free(str);
}

Test(mwrap, break_at_n)
{
    char *str = NULL;

    break_malloc_at(4);
    str = malloc(3 * sizeof(*str));
    cr_assert_not_null(str);
    free(str);
    str = NULL;
    str = malloc(3 * sizeof(*str));
    cr_assert_not_null(str);
    free(str);
    str = NULL;
    str = malloc(3 * sizeof(*str));
    cr_assert_not_null(str);
    free(str);
    str = NULL;
    str = malloc(3 * sizeof(*str));
    cr_assert_null(str);
}