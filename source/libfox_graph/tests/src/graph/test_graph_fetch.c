/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "test_suites.h"

Test(graph, vt_fetch)
{
    alist_t list = NULL;
    FGVAR(graph_t, test, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, &test)));
    cr_expect_not_null(list);
    cr_expect_eq(list->i, 0, ".i = %zu", list->i);
    cr_expect_eq(list, test->graph[0],
    "list = %p, .graph[0] = %p", list, test->graph[0]);
    cr_expect_eq(list->head, list->last,
    ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, &test,
    ".head.iptr = %p, &test = %p", list->head->iptr, &test);
    cr_expect_eq(list, test->vt->fetch(test, MORPH(PT, &test)));
    cr_expect_eq(list, test->vt->fetch(test, MORPH(PT, list)));
}