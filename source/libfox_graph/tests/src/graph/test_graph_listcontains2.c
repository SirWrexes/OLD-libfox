/*
** EPITECH PROJECT, 2019
** libfox_graph
** File description:
** AList Virtual Table tests
*/

#include "test_include.h"

Test(graph, vt_list_contains_alist_iptr)
{
    alist_t list;
    aitem_t i;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = list->vt->fetch(list,
    MORPH(ID, list->vt->add_item(list, list)));
    cr_expect(test->vt->list_contains(test,
    MORPH(PT, list), MORPH(PT, i->iptr)));
}

Test(graph, vt_list_contains_aitem_id)
{
    ssize_t i = -1;
    alist_t list;
    FGVAR(graph_t, test, 3, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    i = test->vt->add_list(test, &test);
    list = test->vt->fetch(test, MORPH(ID, i));
    cr_assert_not_null(list, "list = %p", list);
    i = test->vt->add_item(test, MORPH(ID, i), &list);
    cr_assert_not_null(list->head, ".head = %p", list->head);
    cr_expect(
    test->vt->list_contains(test, MORPH(PT, list->head), MORPH(ID, i)));
}

Test(graph, vt_list_contains_aitem_aitem)
{
    ssize_t i = -1;
    alist_t list;
    FGVAR(graph_t, test, 3, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    i = test->vt->add_list(test, &test);
    list = test->vt->fetch(test, MORPH(ID, i));
    cr_assert_not_null(list, "list = %p", list);
    i = test->vt->add_item(test, MORPH(ID, i), &list);
    cr_assert_not_null(list->head, ".head = %p", list->head);
    cr_expect(
    test->vt->list_contains(
    test, MORPH(PT, list->head), MORPH(PT, list->last)));
}

Test(graph, vt_list_contains_aitem_iptr)
{
    ssize_t i = -1;
    alist_t list;
    FGVAR(graph_t, test, 3, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    i = test->vt->add_list(test, &test);
    list = test->vt->fetch(test, MORPH(ID, i));
    cr_assert_not_null(list, "list = %p", list);
    i = test->vt->add_item(test, MORPH(ID, i), &list);
    cr_assert_not_null(list->head, ".head = %p", list->head);
    cr_expect(
    test->vt->list_contains(
    test, MORPH(PT, list->head), MORPH(PT, list->last->iptr)));
}

Test(graph, vt_list_contains_iptr_id)
{
    alist_t list;
    aitem_t i;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = list->vt->fetch(list, MORPH(ID, list->vt->add_item(list, list)));
    cr_expect(test->vt->list_contains(test, MORPH(PT, i->iptr),
    MORPH(ID, i->i)));
}