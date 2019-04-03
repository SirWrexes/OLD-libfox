/*
** EPITECH PROJECT, 2018
** libfox
** File description:
** No description
*/

#include "fox_string.h"
#include "test_include.h"

Test(strtok, null_and_empty)
{
    char str[] = "Sauce";
    str_t tok1 = NULL;

    cr_expect_null(fox_strtok(NULL, ""));
    tok1 = fox_strtok(str, "");
    cr_expect_eq(tok1, str);
    cr_expect_null(fox_strtok(NULL, ""));
}

Test(strtok, cmp_with_libc_strtok)
{
    char str1[] = "La saucisse du jardin";
    char str2[] = "La saucisse du jardin";
    str_t tok1 = NULL;
    str_t tok2 = NULL;

    tok1 = fox_strtok(str1, "e");
    tok2 = strtok(str2, "e");
    cr_expect_str_eq(tok1, tok2);
    tok1 = fox_strtok(NULL, "ui");
    tok2 = strtok(NULL, "ui");
    cr_expect_str_eq(tok1, tok2);
    tok1 = fox_strtok(NULL, "n");
    tok2 = strtok(NULL, "n");
    cr_expect_str_eq(tok1, tok2);
    tok1 = fox_strtok(NULL, "");
    tok2 = strtok(NULL, "");
    cr_expect_null(tok1);
    cr_expect_null(tok2);
}