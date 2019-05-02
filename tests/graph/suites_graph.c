/*
** EPITECH PROJECT, 2018
** libfox_graph
** File description:
** Test suites
*/

#include "test_include.h"
#include "test_suite_trick.h"

const tsuite_t TEST_SUITE(alist, .init = init, .fini = reset_malloc_cpt);
const tsuite_t TEST_SUITE(aitem, .init = init, .fini = reset_malloc_cpt);
const tsuite_t TEST_SUITE(graph, .init = init, .fini = reset_malloc_cpt);