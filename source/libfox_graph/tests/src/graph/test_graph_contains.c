/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "test_suites.h"

Test(graph, vt_contains_id)
{
    ssize_t id;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    id = test->vt->add_list(test, test);
    cr_expect_neq(id, MFAIL, "id = %ld", id);
    cr_expect(test->vt->contains(test, MORPH(ID, id)));
}

Test(graph, vt_contains_alist)
{
    alist_t list = NULL;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect(test->vt->contains(test, MORPH(PT, list)));
}

Test(graph, vt_contains_aitem)
{
    alist_t list = NULL;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect(test->vt->contains(test, MORPH(PT, list->head)));
}

Test(graph, vt_contains_iptr)
{
    alist_t list = NULL;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect(test->vt->contains(test, MORPH(PT, list->head->iptr)));
}

Test(graph, vt_contains_mfail)
{
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_not(test->vt->contains(test, MORPH(PT, NULL)));
    cr_expect_not(test->vt->contains(test, MORPH(XX, 0)));
    cr_expect_not(test->vt->contains(test, MORPH(-2, 0)));
}