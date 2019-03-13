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

static void reset_errno(void)
{
    errno = 0;
}

TestSuite(aitem, .init = reset_errno);

Test(aitem_create, create_string)
{
    char *str = "sauce";
    FOXGRAPH(aitem_t) test = NEW(aitem_t, str);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->type, MT_ITEM, ".type = %d", test->type);
    cr_expect_str_eq(test->iptr, str, ".iptr = %s", test->iptr);
    cr_expect_null(test->next, ".next = %p", test->next);
    cr_expect_not(test->i, ".i = %zu", test->i);
}

struct dummy {
    char *str;
    int n;
};

Test(aitem, create_structure)
{
    struct dummy dumdum = {.str = "durp", .n = 12};
    struct dummy *mudmud = NULL;
    FOXGRAPH(aitem_t) test = NEW(aitem_t, &dumdum);

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
    aitem_t test = NEW(aitem_t, "hurp");

    cr_assert_not_null(test, "%s", strerror(errno));
    DESTROY(aitem_t, test);
    cr_expect_null(test);
    test->i += 1;
}

Test(aitem, destroy_in_list, .signal = SIGSEGV)
{
    aitem_t test = NEW(aitem_t, "hurp");
    FOXGRAPH(aitem_t) test2 = NEW(aitem_t, "durp");
    FOXGRAPH(aitem_t) test3 = NEW(aitem_t, "burp");

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_assert_not_null(test2, "&test2 = %p", test2);
    cr_assert_not_null(test3, "&test3 = %p", test3);
    test2->i = 2;
    test3->i = 3;
    test2->next = test3;
    test->next = test2;
    DESTROY(aitem_t, test);
    cr_expect_null(test);
    cr_expect_eq(test2->i, 1, "test2->i = %zu", test2->i);
    cr_expect_eq(test3->i, 2, "test3->i = %zu", test3->i);
    test->i += 1;
}