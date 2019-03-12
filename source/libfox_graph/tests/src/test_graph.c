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

Test(graph, create_unnamed)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->type, MT_GRAPH, ".type = %d", test->type);
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);

}

Test(graph, create_unnamed)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, create_unnamed)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, create_unnamed)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, create_unnamed)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, create_unnamed)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, create_unnamed)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, create_unnamed)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, create_unnamed)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, create_unnamed)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, create_unnamed)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, create_unnamed)
{
    GRAPH_AD(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

