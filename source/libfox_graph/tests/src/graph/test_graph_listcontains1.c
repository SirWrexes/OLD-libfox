/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "test_include.h"

Test(graph, vt_list_contains_id_id)
{
    alist_t l;
    aitem_t i;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(ID, l->i), MORPH(ID, i->i)));
}

Test(graph, vt_list_contains_id_aitem)
{
    alist_t l;
    aitem_t i;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(ID, l->i), MORPH(PT, i)));
}

Test(graph, vt_list_contains_id_iptr)
{
    alist_t l;
    aitem_t i;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(ID, l->i),
    MORPH(PT, i->iptr)));
}

Test(graph, vt_list_contains_alist_id)
{
    alist_t l;
    aitem_t i;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(PT, l), MORPH(ID, i->i)));
}

Test(graph, vt_list_contains_alist_aitem)
{
    alist_t l;
    aitem_t i;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(PT, l), MORPH(PT, i)));
}