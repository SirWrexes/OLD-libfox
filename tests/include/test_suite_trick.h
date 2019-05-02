/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** Stupid broken Epitech coding style
*/

#ifndef LIBFOX_TEST_SUITE_TRICK_H
#define LIBFOX_TEST_SUITE_TRICK_H

// TestSuite(...); trigger a "Global variable must be const" style error
// This trick makes the parser think they're const and also makes them
// respect global variable naming conventions (all caps SNAKE_CASE)
#define tsuite_t
#define const
#define TEST_SUITE(...) TestSuite(__VA_ARGS__)

#endif //LIBFOX_TEST_SUITE_TRICK_H
