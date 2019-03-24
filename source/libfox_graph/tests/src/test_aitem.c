/*
** EPITECH PROJECT, 2019
** libfox_graph UT
** File description:
** Adjacency list item
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include "private/p_foxgraph.h"
#include "test_malloc.h"

struct dummy {
    char *str;
    int n;
};

static void init(void)
{
    errno = 0;
    cr_redirect_stderr();
}

TestSuite(aitem, .init = init, .fini = reset_malloc_cpt);

Test(aitem_create, create_string)
{
    char *str = "sauce";
    FGVAR(aitem_t, test, str);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->type, MT_ITEM, ".type = %d", test->type);
    cr_expect_str_eq(test->iptr, str, ".iptr = %s", test->iptr);
    cr_expect_null(test->next, ".next = %p", test->next);
    cr_expect_not(test->i, ".i = %zu", test->i);
}

Test(aitem, create_structure)
{
    struct dummy dumdum = {.str = "durp", .n = 12};
    struct dummy *mudmud = NULL;
    FGVAR(aitem_t, test, &dumdum);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->type, MT_ITEM, ".type = %d", test->type);
    cr_expect_eq(test->iptr, &dumdum,
        ".iptr = %p, &dumdum = %p", test->iptr, &dumdum);
    mudmud = test->iptr;
    cr_expect_eq(mudmud->n, dumdum.n,
        "mudmud->n = %d, dumdum.n = %d", mudmud->n, dumdum.n);
    cr_expect_str_eq(mudmud->str, dumdum.str,
        "mudmud->str = %s, dumdum.str = %s", mudmud->str, dumdum.str);
    cr_expect_null(test->next, ".next = %p", test->next);
    cr_expect_not(test->i, ".i = %zu", test->i);
}

Test(aitem, destroy, .signal = SIGSEGV)
{
    aitem_t test = FGNEW(aitem_t, "hurp");

    cr_assert_not_null(test, "%s", strerror(errno));
    FGDESTROY(aitem_t, test);
    cr_expect_null(test);
    test->i += 1;
}

Test(aitem, destroy_in_list, .signal = SIGSEGV)
{
    aitem_t test = FGNEW(aitem_t, "hurp");
    FGVAR(aitem_t, test2, "durp");
    FGVAR(aitem_t, test3, "burp");

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_assert_not_null(test2, "&test2 = %p", test2);
    cr_assert_not_null(test3, "&test3 = %p", test3);
    test2->i = 2;
    test3->i = 3;
    test2->next = test3;
    test->next = test2;
    FGDESTROY(aitem_t, test);
    cr_expect_null(test);
    cr_expect_eq(test2->i, 1, "test2->i = %zu", test2->i);
    cr_expect_eq(test3->i, 2, "test3->i = %zu", test3->i);
    test->i += 1;
}

Test(aitem, broken_malloc)
{
    break_malloc_at(1);
    cr_assert_null(FGNEW(aitem_t, (void*)0x01));
    cr_expect_stderr_eq_str("AItem: Creation failed.\n");
}