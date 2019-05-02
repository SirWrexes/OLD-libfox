/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** Test suite for malloc testing tools
*/

#include "test_include.h"
#include "test_suite_trick.h"

const tsuite_t TEST_SUITE(mwrap, .fini = reset_malloc_cpt);
const tsuite_t TEST_SUITE(autoclose_fp, .init = cr_redirect_stderr);
const tsuite_t TEST_SUITE(autofree, .init = cr_redirect_stderr);
const tsuite_t TEST_SUITE(calloc, .fini = reset_malloc_cpt);