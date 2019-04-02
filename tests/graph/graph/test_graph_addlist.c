/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "fox_graph.h"
#include "test_include.h"
#include "graph/test_graph_extra.h"

Test(graph, vt_add_list_to_empty)
{
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_assert_neq(test->vt->add_list(test, test), MFAIL,
    "%s", strerror(errno));
    cr_expect_eq(test->graph[0]->head->iptr, test,
    ".graph[0]-->iptr = %p, test = %p", test->graph[0]->head->iptr, test);
}

Test(graph, vt_add_list_to_non_empty)
{
    FGVAR(graph_t, test, 3, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_assert_neq(test->vt->add_list(test, test),
    MFAIL, "%s", strerror(errno));
    cr_assert_neq(test->vt->add_list(test, &test),
    MFAIL, "%s", strerror(errno));
    cr_expect_eq(test->graph[0]->head->iptr, test,
    ".graph[0]-->iptr = %p, test = %p", test->graph[0]->head->iptr, test);
    cr_expect_eq(test->graph[1]->head->iptr, &test,
    ".graph[1]-->iptr = %p, test = %p", test->graph[1]->head->iptr, test);
}

Test(graph, vt_add_list_to_full)
{
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_assert_neq(test->vt->add_list(test, test), MFAIL, "%s", strerror(errno));
    cr_expect_eq(test->graph[0]->head->iptr, test,
    ".graph[0]-->iptr = %p, test = %p", test->graph[0]->head->iptr, test);
    cr_expect_eq(test->vt->add_list(test, &test), MFAIL);
}

Test(graph, vt_add_list_duplicate)
{
    ssize_t id = 0;
    FGVAR(graph_t, test, 2, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    id = test->vt->add_list(test, test);
    cr_expect_eq(test->vt->add_list(test, test), id);
    cr_expect_null(test->graph[1], ".graph[1] = %p", test->graph[1]);
}