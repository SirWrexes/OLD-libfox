/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "fox_graph.h"
#include "test_include.h"
#include "graph/test_graph_extra.h"

Test(graph, destroy)
{
    FGVAR(graph_t, test, 2, "sauce");

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, destroy_null_graph_t)
{
    graph_t test = NULL;

    FGDESTROY(graph_t, test);
}

Test(graph, destroy_null_grapharray)
{
    graph_t test = calloc(1, sizeof(*test));

    cr_assert_not_null(test, "%s", strerror(errno));
    FGDESTROY(graph_t, test);
}