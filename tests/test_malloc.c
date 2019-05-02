/*
** EPITECH PROJECT, 2019
** libfox_memory
** File description:
** Flexible malloc testing wrapper
*/

#include "test_include.h"
#include "p_mallocwrap_redef.h"

void reset_malloc_cpt(void)
{
    counter(MW_RESET, 0);
}

void break_malloc_at(size_t n)
{
    counter(MW_SET, n);
}

void *real_malloc(size_t size);
void *wrap_malloc(size_t size)
{
    if (counter(MW_STEP, 1))
        return real_malloc(size);
    errno = ENOMEM;
    return NULL;
}

Test(mwrap, no_break_then_break_at_1)
{
    char *str = malloc(3 * sizeof(*str));

    cr_assert_not_null(str);
    free(str);
    break_malloc_at(1);
    reset_malloc_cpt();
    str = malloc(3 * sizeof(*str));
    cr_assert_not_null(str);
    free(str);
    break_malloc_at(1);
    str = malloc(3 * sizeof(*str));
    cr_assert_null(str);
    free(str);
}

Test(mwrap, break_at_4)
{
    char *str = NULL;

    break_malloc_at(4);
    str = malloc(3 * sizeof(*str));
    cr_assert_not_null(str);
    free(str);
    str = malloc(3 * sizeof(*str));
    cr_assert_not_null(str);
    free(str);
    str = malloc(3 * sizeof(*str));
    cr_assert_not_null(str);
    free(str);
    str = malloc(3 * sizeof(*str));
    cr_assert_null(str);
}