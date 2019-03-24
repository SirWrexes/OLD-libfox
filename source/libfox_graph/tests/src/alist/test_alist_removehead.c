/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "test_include.h"

Test(alist, vt_remove_head_id)
{
    FGVAR(alist_t, test, "Can't touch this");

    cr_assert_not_null(test);
    test->vt->remove(test, MORPH(ID, test->head->i));
}

Test(alist, vt_remove_head_pt)
{
    FGVAR(alist_t, test, "Cant touch this");

    cr_assert_not_null(test);
    test->vt->add_item(test, &test);
    cr_expect_eq(test->size, 2, ".size = %zu", test->size);
    test->vt->remove(test, MORPH(PT, test->head));
    cr_expect_null(test);
}

Test(alist, vt_remove_head_iptr)
{
    FGVAR(alist_t, test, "Cant touch this");

    cr_assert_not_null(test);
    test->vt->add_item(test, &test);
    cr_expect_eq(test->size, 2, ".size = %zu", test->size);
    test->vt->remove(test, MORPH(PT, test->head->iptr));
    cr_expect_null(test);
}