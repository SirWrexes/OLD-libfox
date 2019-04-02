/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "fox_graph.h"
#include "test_include.h"
#include "graph/test_graph_extra.h"

Test(graph, vt_flush)
{
    FGVAR(graph_t, test, 3, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    test->vt->add_list(test, test);
    test->vt->add_list(test, &test);
    test->vt->add_list(test, test->graph);
    test->vt->add_item(test, MORPH(ID, 0), test->graph);
    test->vt->add_item(test, MORPH(ID, 0), &test->vt);
    test->vt->add_item(test, MORPH(ID, 0), &test->size);
    test->vt->add_item(test, MORPH(ID, 1), test->graph);
    test->vt->add_item(test, MORPH(ID, 2), &test->graph);
    test->vt->add_item(test, MORPH(ID, 2), &test->vt);
    cr_expect_eq(test->graph[0]->size, 4, "0sz = %zu", test->graph[0]->size);
    test->vt->flush(test, MORPH(ID, 0));
    cr_expect_eq(test->graph[0]->size, 1, "0sz = %zu", test->graph[0]->size);
    test->vt->flush(test, MORPH(ID, 999));
    cr_expect_eq(test->graph[0]->size, 1, "0sz = %zu", test->graph[0]->size);
    cr_expect_eq(test->graph[1]->size, 1, "1sz = %zu", test->graph[1]->size);
    cr_expect_eq(test->graph[2]->size, 1, "2sz = %zu", test->graph[2]->size);
}