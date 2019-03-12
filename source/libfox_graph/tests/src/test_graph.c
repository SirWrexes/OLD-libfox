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

Test(graph, destrooy_unnamed)
{
    str3c_t name = NULL;
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, name);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->type, MT_GRAPH, ".type = %d", test->type);
    cr_assert_null(test->name, ".name (ptr) = %p", test->name);
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    cr_assert_not_null(test->graph, ".graph = %p", test->graph);
    for (size_t i = 0; i < test->size; i += 1)
        cr_expect_null(test->graph[i], ".graph[%zu] = %p", i, test->graph[i]);
}

Test(graph, destroy_named)
{
    str3c_t name = "t ki dan le sport";
    GRAPH_AD(graph_t) test = NEW(graph_t, 3, name);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->type, MT_GRAPH, ".type = %d", test->type);
    cr_assert_not_null(test->name, ".name (ptr) = %p", test->name);
    cr_expect_str_eq(test->name, name, ".name = %s", test->name);
    cr_expect_eq(test->size, 3, ".size = %zu", test->size);
    cr_assert_not_null(test->graph, ".graph = %p", test->graph);
    for (size_t i = 0; i < test->size; i += 1)
        cr_expect_null(test->graph[i], ".graph[%zu] = %p", i, test->graph[i]);
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

Test(graph, vt_add_list)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, vt_add_item)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, vt_contains)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, vt_graph_contains)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, vt_list_contains)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, vt_fetch)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, vt_remove)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, vt_flush)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}