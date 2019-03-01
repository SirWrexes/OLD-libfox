/*
** EPITECH PROJECT, 2019
** libfox UT
** File description:
** str[n]cpy
*/

#include <criterion/criterion.h>
#include "private/__foxstring.h"
#include "fox_string.h"

Test(strcpy, copy_string_in_epty_array)
{
    char dest[6] = {0};

    fox_strcpy(dest, "Sauce");
    cr_expect_str_eq(dest, "Sauce");
}

Test(strcpy, copy_string_in_longer_string)
{
    char dest[8] = "Blanche";

    fox_strcpy(dest, "Sauce");
    cr_expect_str_eq(dest, "Sauce");
}

Test(strcpy, strcpy_return_value)
{
    char dest[7] = "Biggie";
    char *ret = fox_strcpy(dest, "Poivre");

    cr_expect_str_eq(ret, "Poivre");
}

Test(strcpy, copy_large_string_in_smaller_array)
{
    char dest[15] = "Chatte étroite";

    fox_strcpy(dest, "Grosse bite de noir");
    cr_expect_str_eq(dest, "Grosse bite de noir");
}