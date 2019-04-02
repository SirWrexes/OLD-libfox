/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include <criterion/criterion.h>
#include "fox_string.h"
#include "private/p_foxstring.h"

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