/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#ifndef LIBFOX_TEST_SUITES_H
#define LIBFOX_TEST_SUITES_H

#include <errno.h>
#include <signal.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "test_malloc.h"
#include "private/p_foxgraph.h"

void init(void);

#define const
#define int
#define dummy(...) TestSuite(__VA_ARGS__)
const int dummy(alist, .init = init, .fini = reset_malloc_cpt);
const int dummy(aitem, .init = init, .fini = reset_malloc_cpt);
const int dummy(graph, .init = init, .fini = reset_malloc_cpt);
#undef const
#undef int

#endif //LIBFOX_TEST_SUITES_H
