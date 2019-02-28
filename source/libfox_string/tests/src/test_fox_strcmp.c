/*
** EPITECH PROJECT, 2019
** libfox UT
** File description:
** strcmp
*/

#include "fox_string.h"
#include <criterion/criterion.h>

Test(strcmp, equal_strings)
{
    int test1 = fox_strcmp("salope", "salope");
    int test2 = strcmp("salope", "salope");

    cr_expect_eq(test1, test2, "test1 = %d, test2 = %d\n", test1, test2);
}

Test(strcmp, different_strings_same_len1)
{
    int test1 = fox_strcmp("suce", "pute");
    int test2 = strcmp("suce", "pute");

    cr_expect_eq(test1, test2, "test1 = %d, test2 = %d\n", test1, test2);
}

Test(strcmp, different_strings_same_len2)
{
    int test1 = fox_strcmp("Je suis noir", "Je suis laid");
    int test2 = strcmp("Je suis noir", "Je suis laid");

    cr_expect_eq(test1, test2, "test1 = %d, test2 = %d\n", test1, test2);
}

Test(strcmp, diff_str_diff_len)
{
    int test1 = fox_strcmp("C'est pas du tout raciste", "Si en fait");
    int test2 = strcmp("C'est pas du tout raciste", "Si en fait");

    cr_expect_eq(test1, test2, "test1 = %d, test2 = %d\n", test1, test2);
}

Test(strncmp, equal_strings)
{
    int test1 = fox_strncmp("salope", "salope", 3);
    int test2 = strncmp("salope", "salope", 3);

    cr_expect_eq(test1, test2, "test1 = %d, test2 = %d\n", test1, test2);
}

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