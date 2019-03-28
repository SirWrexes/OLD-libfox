/*
** EPITECH PROJECT, 2019
** libfox_graph
** File description:
** AList Virtual Table tests
*/

#include "test_include.h"

Test(graph, vt_list_contains_id_id)
{
    alist_t li;
    aitem_t i;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    li = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = li->vt->fetch(li, MORPH(ID, li->vt->add_item(li, li)));
    cr_expect(
        test->vt->list_contains(test, MORPH(ID, li->i), MORPH(ID, i->i)));
}

Test(graph, vt_list_contains_id_aitem)
{
    alist_t li;
    aitem_t i;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    li = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = li->vt->fetch(li, MORPH(ID, li->vt->add_item(li, li)));
    cr_expect(test->vt->list_contains(test, MORPH(ID, li->i), MORPH(PT, i)));
}

Test(graph, vt_list_contains_id_iptr)
{
    alist_t li;
    aitem_t i;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    li = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = li->vt->fetch(li, MORPH(ID, li->vt->add_item(li, li)));
    cr_expect(test->vt->list_contains(test, MORPH(ID, li->i),
    MORPH(PT, i->iptr)));
}

Test(graph, vt_list_contains_alist_id)
{
    alist_t li;
    aitem_t i;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    li = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = li->vt->fetch(li, MORPH(ID, li->vt->add_item(li, li)));
    cr_expect(test->vt->list_contains(test, MORPH(PT, li), MORPH(ID, i->i)));
}

Test(graph, vt_list_contains_alist_aitem)
{
    alist_t li;
    aitem_t i;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    li = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = li->vt->fetch(li, MORPH(ID, li->vt->add_item(li, li)));
    cr_expect(test->vt->list_contains(test, MORPH(PT, li), MORPH(PT, i)));
}