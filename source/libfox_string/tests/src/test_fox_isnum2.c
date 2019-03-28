/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include <criterion/criterion.h>
#include "fox_string.h"
#include "private/p_foxstring.h"

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
