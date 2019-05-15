/*
** EPITECH PROJECT, 2018
** libfox UT
** File description:
** Tests for my_isnum
*/

#include <criterion/criterion.h>
#include "fox_string.h"
#include "private/p_foxstring.h"

Test(isnum, expect_false)
{
    cr_expect_not(fox_isnum(""));
    cr_expect_not(fox_isnum("-"));
    cr_expect_not(fox_isnum("+"));
    cr_expect_not(fox_isnum("-----"));
    cr_expect_not(fox_isnum("++++++"));
    cr_expect_not(fox_isnum("+--+-+-+"));
    cr_expect_not(fox_isnum("++-AaBbCc"));
    cr_expect_not(fox_isnum("AaBbCc"));
    cr_expect_not(fox_isnum("afklsd4586"));
    cr_expect_not(fox_isnum("8975afzf"));
    cr_expect_not(fox_isnum("4456+5678"));
    cr_expect_not(fox_isnum("44565678-"));
}

Test(isnum, expect_true)
{
    cr_expect(fox_isnum("123"));
    cr_expect(fox_isnum("+45678"));
    cr_expect(fox_isnum("-15638"));
    cr_expect(fox_isnum("+--+-+-+568741"));
}