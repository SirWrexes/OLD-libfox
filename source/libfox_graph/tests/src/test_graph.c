/*
** EPITECH PROJECT, 2019
** libfox_graph UT
** File description:
** Graph
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include "private/p_foxgraph.h"

static void reset_errno(void)
{
    errno = 0;
}

TestSuite(graph, .init = reset_errno);

Test(graph, create_unnamed)
{
    str3c_t name = NULL;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, name);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->type, MT_GRAPH, ".type = %d", test->type);
    cr_assert_null(test->name, ".name (ptr) = %p", test->name);
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    cr_assert_not_null(test->graph, ".graph = %p", test->graph);
    for (size_t i = 0; i < test->size; i += 1)
        cr_expect_null(test->graph[i], ".graph[%zu] = %p", i, test->graph[i]);
}

Test(graph, create_named)
{
    str3c_t name = "t ki dan le sport";
    FOXGRAPH(graph_t) test = NEW(graph_t, 3, name);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->type, MT_GRAPH, ".type = %d", test->type);
    cr_assert_not_null(test->name, ".name (ptr) = %p", test->name);
    cr_expect_str_eq(test->name, name, ".name = %s", test->name);
    cr_expect_eq(test->size, 3, ".size = %zu", test->size);
    cr_assert_not_null(test->graph, ".graph = %p", test->graph);
    for (size_t i = 0; i < test->size; i += 1)
        cr_expect_null(test->graph[i], ".graph[%zu] = %p", i, test->graph[i]);
}

Test(graph, create_invalid_size)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 0, NULL);

    cr_assert_null(test, "test = %p", test);
}

Test(graph, destroy)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 2, "sauce");

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, destroy_null_graph_t)
{
    graph_t test = NULL;

    DESTROY(graph_t, test);
}

Test(graph, destroy_null_grapharray)
{
    graph_t test = calloc(1, sizeof(*test));

    cr_assert_not_null(test, "%s", strerror(errno));
    DESTROY(graph_t, test);
}

Test(graph, vt_add_list_to_empty)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_assert_neq(test->vt->add_list(test, test), MFAIL, "%s", strerror(errno));
    cr_expect_eq(test->graph[0]->head->iptr, test,
        ".graph[0]-->iptr = %p, test = %p", test->graph[0]->head->iptr, test);
}

Test(graph, vt_add_list_to_non_empty)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 3, NULL);

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
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_assert_neq(test->vt->add_list(test, test), MFAIL, "%s", strerror(errno));
    cr_expect_eq(test->graph[0]->head->iptr, test,
        ".graph[0]-->iptr = %p, test = %p", test->graph[0]->head->iptr, test);
    cr_expect_eq(test->vt->add_list(test, &test), MFAIL);
}

Test(graph, vt_add_item_duplicate)
{
    ssize_t id = 0;
    FOXGRAPH(graph_t) test = NEW(graph_t, 2, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    id = test->vt->add_list(test, test);
    cr_expect_eq(test->vt->add_list(test, test), id);
}

Test(graph, vt_contains)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, vt_graph_contains)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, vt_list_contains)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, vt_fetch)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, vt_remove)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, vt_flush)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}