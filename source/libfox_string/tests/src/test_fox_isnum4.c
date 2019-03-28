/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include <criterion/criterion.h>
#include "fox_string.h"
#include "private/p_foxstring.h"

Test(isnum, numeric_with_several_signs)
{
    cr_expect(fox_isnum("+--+-+-+568741"));
}