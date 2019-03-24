/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "test_include.h"

Test(graph, vt_add_item_alist_duplicate)
{
    FGVAR(graph_t, test, 1, NULL);
    alist_t list;

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(test->vt->add_item(test, MORPH(PT, list), test), 0);
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(list->head, list->last,
    ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, test);
}

Test(graph, vt_add_item_aitem)
{
    FGVAR(graph_t, test, 1, NULL);
    alist_t list;

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(test->vt->add_item(test, MORPH(PT, list->head), &test), 1);
    cr_expect_eq(list->size, 2, ".size = %zu", list->size);
    cr_expect_neq(list->head, list->last,
    ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, test);
    cr_expect_eq(list->last->iptr, &test);
}

Test(graph, vt_add_item_aitem_duplicate)
{
    FGVAR(graph_t, test, 1, NULL);
    alist_t list;

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(test->vt->add_item(test, MORPH(PT, list->head), test), 0);
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(list->head, list->last,
    ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, test);
}

Test(graph, vt_add_item_iptr)
{
    FGVAR(graph_t, t, 1, NULL);
    alist_t list;

    cr_assert_not_null(t, "%s", strerror(errno));
    list = t->vt->fetch(t, MORPH(ID, t->vt->add_list(t, t)));
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(t->vt->add_item(t, MORPH(PT, list->head->iptr), &t), 1);
    cr_expect_eq(list->size, 2, ".size = %zu", list->size);
    cr_expect_neq(list->head, list->last,
    ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, t);
    cr_expect_eq(list->last->iptr, &t);
}

Test(graph, vt_add_item_iptr_duplicate)
{
    FGVAR(graph_t, t, 1, NULL);
    alist_t list;

    cr_assert_not_null(t, "%s", strerror(errno));
    list = t->vt->fetch(t, MORPH(ID, t->vt->add_list(t, t)));
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(t->vt->add_item(t, MORPH(PT, list->head->iptr), t), 0);
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(list->head, list->last,
    ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, t);
}