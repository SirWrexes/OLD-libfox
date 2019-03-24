/*
** EPITECH PROJECT, 2019
** libfox_graph UT
** File description:
** Adjacency list
*/

#include "test_include.h"

Test(alist, vt_add_one_to_empty)
{
    FGVAR(alist_t, test, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->size, 0, ".size = %zu", test->size);
    cr_expect_eq(test->vt->add_item(test, "non"), 0);
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    cr_expect_not_null(test->head, ".head = %p", test->head);
    cr_expect_not_null(test->last, ".last = %p", test->last);
    cr_expect_eq(test->head, test->last,
    ".head = %p, .last = %p", test->head, test->last);
    cr_expect_not(test->head->i, ".head.i = %zu", test->head->i);
    cr_expect_not_null(test->head->iptr, ".head.iptr = %p", test->head->iptr);
    cr_expect_str_eq(test->head->iptr, "non",
    ".head.iptr = %s", test->head->iptr);
}

Test(alist, vt_add_one_to_non_empty)
{
    FGVAR(alist_t, test, "peut-etre");

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    cr_expect_eq(test->vt->add_item(test, "je ne sais pas"), 1);
    cr_expect_eq(test->size, 2, ".size = %zu", test->size);
    cr_expect_not_null(test->head, ".head = %p", test->head);
    cr_expect_not_null(test->last, ".last = %p", test->last);
    cr_expect_neq(test->head, test->last,
    ".head = %p, .last = %p", test->head, test->last);
    cr_expect_eq(test->head->i, 0, ".head.i = %zu", test->head->i);
    cr_expect_eq(test->last->i, 1, ".last.i = %zu", test->last->i);
    cr_expect_not_null(test->head->iptr, ".head.iptr = %p", test->head->iptr);
    cr_expect_not_null(test->last->iptr, ".last.iptr = %p", test->last->iptr);
    cr_expect_str_eq(test->head->iptr, "peut-etre",
    ".head.iptr = %s", test->head->iptr);
    cr_expect_str_eq(test->last->iptr, "je ne sais pas",
    ".last.iptr = %s", test->last->iptr);
}

Test(alist, add_duplicate)
{
    FGVAR(alist_t, test, &test);

    cr_assert_not_null(test);
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    cr_expect_eq(test->vt->add_item(test, &test), test->head->i);
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
}