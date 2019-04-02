/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#ifndef LIBFOX_TEST_SUITES_H
#define LIBFOX_TEST_SUITES_H

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "test_malloc.h"

// TestSuite(...); trigger a "Global variable must be const" style error
// This trick makes the parser think they're prototypes
#define tsuite_t
#define test_suite(...) TestSuite(__VA_ARGS__)

void init(void);

#endif //LIBFOX_TEST_SUITES_H
