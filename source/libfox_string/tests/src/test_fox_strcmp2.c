/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "fox_string.h"
#include <criterion/criterion.h>

Test(strncmp, diff_str_cmp_eq_zero)
{
    int test1 = fox_strncmp("putride", "pute", 3);
    int test2 = strncmp("putride", "pute", 3);


    cr_expect_eq(test1, test2, "test1 = %d, test2 = %d\n", test1, test2);
}

Test(strncmp, diff_str_cmp_neq_zero)
{
    int test1 = fox_strncmp("Je suis noir", "Je suis laid", 9);
    int test2 = strncmp("Je suis noir", "Je suis laid", 9);

    cr_expect_eq(test1, test2, "test1 = %d, test2 = %d\n", test1, test2);
}

Test(strncmp, diff_str_cmp_neq_zero2)
{
    int test1 = fox_strncmp("C'est pas du tout raciste", "Si en fait", 12);
    int test2 = strncmp("C'est pas du tout raciste", "Si en fait", 12);

    cr_expect_eq(test1, test2, "test1 = %d, test2 = %d\n", test1, test2);
}