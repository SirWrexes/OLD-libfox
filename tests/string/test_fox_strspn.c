/*
** EPITECH PROJECT, 2018
** libfox_string
** File description:
** strspn unit tests
*/

#include "fox_string.h"
#include "test_include.h"

Test(strspn, strspn)
{
    cr_expect_eq(fox_strspn("", "-="), strspn("", "-="));
    cr_expect_eq(fox_strspn("-=-aaee--=", ""), strspn("-=-aaee--=", ""));
    cr_expect_eq(fox_strspn("-=-aaee--=", "-="), strspn("-=-aaee--=", "-="));
    cr_expect_eq(fox_strspn("uuuuuuu", "-="), strspn("uuuuuuu", "-="));
    cr_expect_eq(fox_strspn("aaee--=", "-="), strspn("aaee--=", "-="));
    cr_expect_eq(fox_strspn("-=-", "-="), strspn("-=-", "-="));
    cr_expect_eq(fox_strcspn("", "-="), strcspn("", "-="));
    cr_expect_eq(fox_strcspn("-=-aaee--=", ""), strcspn("-=-aaee--=", ""));
    cr_expect_eq(fox_strcspn("-=-aaee--=", "-="), strcspn("-=-aaee--=", "-="));
    cr_expect_eq(fox_strcspn("uuuuuuu", "-="), strcspn("uuuuuuu", "-="));
    cr_expect_eq(fox_strcspn("aaee--=", "-="), strcspn("aaee--=", "-="));
    cr_expect_eq(fox_strcspn("-=-", "-="), strcspn("-=-", "-="));
}