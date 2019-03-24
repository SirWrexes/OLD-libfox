/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "test_suites.h"

Test(alist, vt_fetch_id)
{
    ssize_t id = 0;
    aitem_t fetch = NULL;
    FGVAR(alist_t, test, "Ooh");

    cr_assert_not_null(test);
    id = test->vt->add_item(test, "Eeh");
    fetch = test->vt->fetch(test, MORPH(ID, id));
    cr_expect_eq(fetch->i, id, "fetch.i = %zu, i = %ld", fetch->i, id);
    cr_expect_eq(test->last, fetch,
    ".last = %p, fetch = %p", test->last, fetch);
    cr_expect_eq(test->last->i, id,
    ".last.i = %zu, id = %ld", test->last->i, id);

}

Test(alist, vt_fetch_pt)
{
    ssize_t id = 0;
    aitem_t fetch1 = NULL;
    aitem_t fetch2 = NULL;
    FGVAR(alist_t, test, "Ooh");

    cr_assert_not_null(test);
    id = test->vt->add_item(test, "Ah-ah");
    fetch1 = test->vt->fetch(test, MORPH(ID, id));
    fetch2 = test->vt->fetch(test, MORPH(PT, fetch1));
    cr_expect_eq(test->last, fetch2,
    ".last = %p, fetch2 = %p", test->last, fetch2);
}

Test(alist, vt_fetch_iptr)
{
    ssize_t item = 0;
    aitem_t fetch = NULL;
    FGVAR(alist_t, test, "Ting tang");

    cr_assert_not_null(test);
    test->vt->add_item(test, &item);
    fetch = test->vt->fetch(test, MORPH(PT, &item));
    cr_expect_eq(fetch->iptr, &item,
    ".last.iptr = %p, &item = %p", test->last, &item);
}

Test(alist, vt_fetch_mfail)
{
    FGVAR(alist_t, test, "Walla walla bang bang");

    cr_assert_not_null(test);
    cr_expect_null(test->vt->fetch(test, MORPH(PT, NULL)));
    cr_expect_null(test->vt->fetch(test, MORPH(XX, 0)));
    cr_expect_null(test->vt->fetch(test, MORPH(23, 0)));
}