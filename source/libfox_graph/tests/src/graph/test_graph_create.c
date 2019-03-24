/*
** EPITECH PROJECT, 2019
** libfox_graph UT
** File description:
** Graph
*/

#include "test_suites.h"

Test(graph, create_unnamed)
{
    str3c_t name = NULL;
    FGVAR(graph_t, test, 1, name);

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
    FGVAR(graph_t, test, 3, name);

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
    FGVAR(graph_t, test, 0, NULL);

    cr_assert_null(test, "test = %p", test);
    cr_expect_stderr_eq_str("Graph: Invalid size.\n");
}