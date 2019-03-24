/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "test_suites.h"

Test(alist, broken_malloc_creation)
{
    break_malloc_at(1);
    cr_assert_null(FGNEW(alist_t, (void*)0x01));
    cr_expect_stderr_eq_str("AList: Creation failed.\n");
}

Test(alist, broken_malloc_item_creation)
{
    break_malloc_at(2);
    cr_assert_null(FGNEW(alist_t, (void*)0x01));
    cr_expect_stderr_eq_str(
    "AItem: Creation failed.\n"
    "AList: Item creation failed.\n");
}

Test(alist, broken_malloc_additem)
{
    FGVAR(alist_t, test, NULL);

    break_malloc_at(1);
    cr_assert_eq(test->vt->add_item(test, &test), MFAIL);
    cr_expect_stderr_eq_str("AItem: Creation failed.\n");
}