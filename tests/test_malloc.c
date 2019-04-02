/*
** EPITECH PROJECT, 2019
** libfox_memory
** File description:
** Flexible malloc testing wrapper
*/

#include "test_include.h"

typedef enum {
    MW_RESET,
    MW_SET,
    MW_STEP,
} mw_action_t;

static bool counter(mw_action_t a, ssize_t n)
{
    static ssize_t cpt = 0;
    static ssize_t break_at = -1;

    if (a == MW_STEP)
        cpt += (break_at != -1) && (cpt + 1 > cpt);
    if (a == MW_SET)
        break_at = n;
    if (a == MW_RESET) {
        cpt = 0;
        return counter(MW_SET, -1);
    }
    return break_at == -1 ||  cpt < break_at;
}

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

tsuite_t test_suite(mwrap, .fini = reset_malloc_cpt);

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

Test(mwrap, break_at_1)
{
    char *str = NULL;

    break_malloc_at(1);
    str = malloc(3 * sizeof(*str));
    cr_assert_null(str);
    free(str);
    str = NULL;
}

Test(mwrap, break_at_4)
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