/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "fox_graph.h"
#include "test_include.h"
#include "graph/test_graph_extra.h"

Test(alist, vt_flush)
{
    FGVAR(alist_t, test, "STOP !");

    cr_assert_not_null(test);
    test->vt->add_item(test, "Hammer time !");
    test->vt->add_item(test, "dududdididoduydu");
    test->vt->add_item(test, "dududoiddidudud");
    test->vt->add_item(test, "didudududidiududu");
    test->vt->add_item(test, "dudidudodududu");
    cr_expect_eq(test->size, 6, ".size = %zu", test->size);
    test->vt->flush(test);
    cr_expect_eq(test->size, 1);
}