/*
** EPITECH PROJECT, 2018
** libfox UT
** File description:
** Tests for my_isnum
*/

#include <criterion/criterion.h>
#include "fox_string.h"
#include "private/p_foxstring.h"

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