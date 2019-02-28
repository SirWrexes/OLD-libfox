/*
** EPITECH PROJECT, 2019
** libfox_memory UT
** File description:
** fox_realloc
*/

#include "fox_memory.h"
#include <criterion/criterion.h>

Test(fox_realloc, size_null)
{
    char *test = malloc(sizeof(char) * 10);

    test = fox_realloc(test, 0);
    cr_expect_null(test);
}

Test(fox_realloc, pointer_null)
{
    char *test = NULL;

    test = fox_realloc(test, sizeof test * 12);
    cr_expect_not_null(test);
}

Test(fox_realloc, bigger)
{
    char *test = malloc(sizeof(char) * 5);

    for (int i = 0 ; i < 5 ; ++i)
        test[i] = (char) (i + 48);
    test = fox_realloc(test, 10);
    cr_expect_str_eq(test, "01234");
    for (int j = 0 ; j < 10 ; ++j)
        test[j] = (char) (j + 48);
    cr_expect_str_eq(test, "0123456789");
}

Test(fox_realloc, smaller)
{
    char *test = malloc(sizeof(char) * 10);

    for (int i = 0 ; i < 10 ; ++i)
        test[i] = (char) (i + 48);
    test = fox_realloc(test, 5);
    cr_expect_str_eq(test, "01234");
}

Test(fox_realloc, not_a_string)
{
    int *test = malloc(sizeof(int) * 5);
    int expected[2] = {0, 1};

    for (int i = 0 ; i < 5 ; ++i)
        test[i] = i;
    test = fox_realloc(test, 2);
    cr_expect_arr_eq(test, expected, 3);
}

Test(fox_realloc, char_would_overflow)
{
    int *test = malloc(sizeof(int) * 5);
    int expected[2] = {650, 651};

    for (int i = 0 ; i < 5 ; ++i)
        test[i] = 650 + i;
    test = fox_realloc(test, 2);
    cr_expect_arr_eq(test, expected, 3);
}