/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "fox_graph.h"
#include "test_include.h"
#include "graph/test_graph_extra.h"

Test(graph, vt_remove_mfail)
{
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    test->vt->remove(test, MORPH(XX, 0));
    test->vt->remove(test, MORPH(PT, NULL));
    test->vt->remove(test, MORPH(ID, 150));
}

Test(graph, vt_remove_list_head)
{
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    test->vt->add_list(test, &test);
    cr_assert_not_null(test->graph[0], "%s", strerror(errno));
    test->vt->remove(test, MORPH(PT, &test));
    cr_expect_not(test->vt->contains(test, MORPH(PT, &test)));
    cr_expect_null(test->graph[0]);
    test->vt->add_list(test, &test);
    cr_assert_not_null(test->graph[0], "%s", strerror(errno));
    test->vt->remove(test, MORPH(PT, test->graph[0]));
    cr_expect_not(test->vt->contains(test, MORPH(PT, &test)));
    cr_expect_null(test->graph[0]);
    test->vt->add_list(test, &test);
    cr_assert_not_null(test->graph[0], "%s", strerror(errno));
    test->vt->remove(test, MORPH(PT, test->graph[0]));
    cr_expect_not(test->vt->contains(test, MORPH(PT, &test)));
    cr_expect_null(test->graph[0]);
}

Test(graph, vt_remove_id)
{
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    test->vt->add_list(test, &test);
    cr_assert_not_null(test->graph[0], "%s", strerror(errno));
    test->vt->remove(test,
    MORPH(ID, test->vt->fetch(test, MORPH(PT, &test))->i));
    cr_expect_not(test->vt->contains(test, MORPH(PT, &test)));
    cr_expect_null(test->graph[0]);
}

Test(graph, vt_remove)
{
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    test->vt->add_list(test, test);
    cr_assert_not_null(test->graph[0], "%s", strerror(errno));
    test->vt->add_item(test, MORPH(ID, 0), &test);
    cr_assert_not_null(test->graph[0]->head->next, "%s", strerror(errno));
    test->vt->remove(test, MORPH(PT, &test));
    cr_expect_null(test->graph[0]->head->next,
    ".head.next = %p", test->graph[0]->head->next);
    cr_expect_not(test->vt->contains(test, MORPH(PT, &test)));
}