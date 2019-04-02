/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "fox_graph.h"
#include "test_include.h"
#include "graph/test_graph_extra.h"

Test(alist, vt_remove_id)
{
    FGVAR(alist_t, test, "Can't touch this");

    cr_assert_not_null(test);
    test->vt->add_item(test, &test);
    cr_expect_eq(test->size, 2, ".size = %zu", test->size);
    test->vt->remove(test, MORPH(ID, test->last->i));
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    cr_expect_eq(test->head, test->last,
    ".head = %p, .last = %p", test->head, test->last);
}

Test(alist, vt_remove_pt)
{
    FGVAR(alist_t, test, "Cant touch this");

    cr_assert_not_null(test);
    test->vt->add_item(test, test);
    cr_expect_eq(test->size, 2, ".size = %zu", test->size);
    test->vt->remove(test, MORPH(PT, test->vt->fetch(test, MORPH(PT, test))));
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    cr_expect_eq(test->head, test->last,
    ".head = %p, .last = %p", test->head, test->last);
}

Test(alist, vt_remove_iptr)
{
    FGVAR(alist_t, test, "Cant touch this");

    cr_assert_not_null(test);
    test->vt->add_item(test, test);
    cr_expect_eq(test->size, 2, ".size = %zu", test->size);
    test->vt->remove(test, MORPH(PT, test));
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    cr_expect_eq(test->head, test->last,
    ".head = %p, .last = %p", test->head, test->last);
}

Test(alist, vt_remove_mfail)
{
    FGVAR(alist_t, test, "Cant touch this");

    cr_assert_not_null(test);
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    test->vt->add_item(test, &test);
    cr_expect_eq(test->size, 2, ".size = %zu", test->size);
    test->vt->remove(test, MORPH(PT, NULL));
    test->vt->remove(test, MORPH(ID, 23));
    test->vt->remove(test, MORPH(XX, 42));
    cr_expect_eq(test->size, 2, ".size = %zu", test->size);
}