/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "test_include.h"

Test(graph, vt_add_item_empty_id)
{
    FGVAR(graph_t, test, 1, NULL);
    alist_t list;

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, NULL)));
    cr_expect_not(list->size, ".size = %zu", list->size);
    cr_expect_not(test->vt->add_item(test, MORPH(ID, list->i), test));
    cr_expect(list->size, ".size = %zu", list->size);
    cr_expect_eq(list->head, list->last,
    ".head = %p, .last = %p", list->head, list->last);
}

Test(graph, vt_add_item_empty_alist)
{
    FGVAR(graph_t, test, 1, NULL);
    alist_t list;

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, NULL)));
    cr_expect_not(list->size, ".size = %zu", list->size);
    cr_expect_not(test->vt->add_item(test, MORPH(PT, list), test));
    cr_expect(list->size, ".size = %zu", list->size);
    cr_expect_eq(list->head, list->last,
    ".head = %p, .last = %p", list->head, list->last);
}

Test(graph, vt_add_item_id)
{
    FGVAR(graph_t, test, 1, NULL);
    alist_t list;

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(test->vt->add_item(test, MORPH(ID, list->i), &test), 1);
    cr_expect_eq(list->size, 2, ".size = %zu", list->size);
    cr_expect_neq(list->head, list->last,
    ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, test);
    cr_expect_eq(list->last->iptr, &test);
}

Test(graph, vt_add_item_id_duplicate)
{
    FGVAR(graph_t, test, 1, NULL);
    alist_t list;

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(test->vt->add_item(test, MORPH(ID, list->i), test), 0);
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(list->head, list->last,
    ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, test);
}

Test(graph, vt_add_item_alist)
{
    FGVAR(graph_t, test, 1, NULL);
    alist_t list;

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(test->vt->add_item(test, MORPH(PT, list), &test), 1);
    cr_expect_eq(list->size, 2, ".size = %zu", list->size);
    cr_expect_neq(list->head, list->last,
    ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, test);
    cr_expect_eq(list->last->iptr, &test);
}