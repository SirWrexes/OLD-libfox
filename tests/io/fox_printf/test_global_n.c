/*
** EPITECH PROJECT, 2019
** libfox_IO
** File description:
** Printf: N tests
*/

#include "private/fox_printf/p_foxprintf.h"
#include <criterion/criterion.h>

Test(global_n, global_n)
{
    cr_expect_not(N_RST);
    cr_expect_not(N_GET);
    cr_expect_eq(N_ADD(2), 2);
    cr_expect_eq(N_ADD(3), 5);
    cr_expect_eq(N_GET, 5);
    cr_expect_eq(N_ADD(52), N_GET);
    cr_expect_not(N_RST);
    cr_expect_not(N_GET);
    cr_expect_eq(N_ADD(20), 20);
    cr_expect_eq(N_ADD(-3), 17);
}