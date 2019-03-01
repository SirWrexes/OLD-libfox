/*
** EPITECH PROJECT, 2018
** libfox UT
** File description:
** Tests for my_isnum
*/

#include <criterion/criterion.h>
#include "fox_string.h"
#include "private/__foxstring.h"

Test(isnum, empty_string)
{
    cr_expect_not(fox_isnum(""));
}

Test(isnum, signed_alphabetic_string)
{
    cr_expect_not(fox_isnum("++-AaBbCc"));
}

Test(isnum, alphabetic_string)
{
    cr_expect_not(fox_isnum("AaBbCc"));
}

Test(isnum, letters_then_numbers)
{
    cr_expect_not(fox_isnum("afklsd4586"));
}

Test(isnum, numbers_then_letters)
{
    cr_expect_not(fox_isnum("8975afzf"));
}

Test(isnum, numeric_string)
{
    cr_expect(fox_isnum("123"));
}

Test(isnum, numeric_starting_string_with_plus)
{
    cr_expect(fox_isnum("+45678"));
}

Test(isnum, numeric_string_starting_with_less)
{
    cr_expect(fox_isnum("-15638"));
}

Test(isnum, numeric_containing_plus)
{
    cr_expect_not(fox_isnum("4456+5678"));
}

Test(isnum, numeric_containing_less)
{
    cr_expect_not(fox_isnum("44565678-"));
}

Test(isnum, numeric_containing_only_less)
{
    cr_expect_not(fox_isnum("-"));
}

Test(isnum, numeric_containing_only_plus)
{
    cr_expect_not(fox_isnum("+"));
}

Test(isnum, numeric_containing_only_several_less)
{
    cr_expect_not(fox_isnum("-----"));
}

Test(isnum, numeric_containing_only_several_plus)
{
    cr_expect_not(fox_isnum("++++++"));
}

Test(isnum, numeric_containing_only_several_signs)
{
    cr_expect_not(fox_isnum("+--+-+-+"));
}

Test(isnum, numeric_with_several_signs)
{
    cr_expect(fox_isnum("+--+-+-+568741"));
}
