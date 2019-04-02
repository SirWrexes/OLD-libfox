/*
** EPITECH PROJECT, 2019
** libfox_graph UT
** File description:
** Adjacency list
*/

#include "fox_graph.h"
#include "test_include.h"
#include "graph/test_graph_extra.h"

Test(alist, destroy, .signal = SIGABRT)
{
    aitem_t item = NULL;
    alist_t test = FGNEW(alist_t, "oui");

    cr_assert_not_null(test, "%s", strerror(errno));
    item = test->head;
    FGDESTROY(alist_t, test);
    cr_expect_null(test);
    free(item);
}