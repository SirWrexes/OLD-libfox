/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "test_suites.h"

Test(graph, vt_list_contains_iptr_aitem)
{
    alist_t l;
    aitem_t i;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(PT, i->iptr),
    MORPH(PT, i)));
}

Test(graph, vt_list_contains_iptr_iptr)
{
    alist_t l;
    aitem_t i;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(PT, i->iptr),
    MORPH(PT, i->iptr)));
}

Test(graph, vt_list_contains_mfail)
{
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_not(
    test->vt->list_contains(test, MORPH(XX, 23), MORPH(XX, 23)));
    cr_expect_not(
    test->vt->list_contains(test, MORPH(PT, NULL), MORPH(XX, 23)));
    cr_expect_not(
    test->vt->list_contains(test, MORPH(ID, 987), MORPH(XX, 23)));
    test->vt->add_list(test, test);
    cr_expect_not(
    test->vt->list_contains(test, MORPH(ID, 0), MORPH(XX, 23)));
    cr_expect_not(
    test->vt->list_contains(test, MORPH(ID, 0), MORPH(PT, NULL)));
    cr_expect_not(
    test->vt->list_contains(test, MORPH(ID, 0), MORPH(ID, 999)));
}