/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** test_fox_strcont
*/

#include "test_include.h"
#include "fox_string.h"

Test(strcont, expect_false)
{
    cr_expect_not(fox_strcont_c("", 'O'));
    cr_expect_not(fox_strcont_c("Suce bien fort", 'O'));
    cr_expect_not(fox_strcont("Hahah that's gay", "0123"));
    cr_expect_not(fox_strcont_r("stfu bitch", "stfubitch"));
}

Test(strcont, expect_true)
{
    cr_expect(fox_strcont_c("O", 'O'));
    cr_expect(fox_strcont_c("Suce bien fort", 'o'));
    cr_expect(fox_strcont("Hahah that's gay", "yo!"));
    cr_expect(fox_strcont_r("stfu bitch", "stfu bitch"));
}