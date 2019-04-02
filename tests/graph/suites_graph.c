/*
** EPITECH PROJECT, 2018
** libfox_graph
** File description:
** Test suites
*/

#include "test_include.h"

tsuite_t test_suite(alist, .init = init, .fini = reset_malloc_cpt);
tsuite_t test_suite(aitem, .init = init, .fini = reset_malloc_cpt);
tsuite_t test_suite(graph, .init = init, .fini = reset_malloc_cpt);
