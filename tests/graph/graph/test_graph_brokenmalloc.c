/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "fox_graph.h"
#include "test_include.h"
#include "graph/test_graph_extra.h"

Test(graph, broken_malloc_creation)
{
    break_malloc_at(1);
    cr_assert_null(FGNEW(graph_t, 1, NULL));
    cr_expect_stderr_eq_str("Graph: Creation failed.\n");
}

Test(graph, broken_malloc_array)
{
    break_malloc_at(2);
    cr_assert_null(FGNEW(graph_t, 1, NULL));
    cr_expect_stderr_eq_str("Graph: Array allocation failed.\n");
}

Test(graph, broken_malloc_name)
{
    break_malloc_at(3);
    cr_assert_null(FGNEW(graph_t, 1, "I'M GONNA WRECK IT"));
    cr_expect_stderr_eq_str("Graph: Name assignation failed.\n");
}