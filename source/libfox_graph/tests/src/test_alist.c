/*
** EPITECH PROJECT, 2019
** libfox_graph UT
** File description:
** Adjacency list
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include "private/p_foxgraph.h"

Test(alist, create_empty)
{
    GRAPH_AD(alist_t) test = NEW(alist_t, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->type, MT_LIST, ".type = %d", test->type);
    cr_expect_not(test->i, ".i = %zu", test->i);
    cr_expect_not(test->size, ".size = %zu", test->size);
    cr_expect_null(test->head, ".head = %p", test->head);
    cr_expect_null(test->last, ".last = %p", test->last);
    cr_expect_not_null(test->vt, ".vt = %p", test->vt);
}

Test(alist, create_non_empty)
{
    GRAPH_AD(alist_t) test = NEW(alist_t, "euuuuuuuuuuh");

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->type, MT_LIST, ".type = %d", test->type);
    cr_expect_not(test->i, ".i = %zu", test->i);
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    cr_expect_not_null(test->head, ".head = %p", test->head);
    cr_expect_not_null(test->last, ".last = %p", test->last);
    cr_expect_eq(test->head, test->last,
        ".head = %p, .last = %p", test->head, test->last);
    cr_expect_str_eq(test->head->iptr, "euuuuuuuuuuh",
        "..iptr = %s", test->head->iptr);
    cr_expect_str_eq(test->last->iptr, "euuuuuuuuuuh",
        "..iptr = %s", test->last->iptr);
    cr_expect_not_null(test->vt, ".vt = %p", test->vt);
}

Test(alist, destroy, .signal = SIGABRT)
{
    aitem_t item = NULL;
    alist_t test = NEW(alist_t, "oui");

    cr_assert_not_null(test, "%s", strerror(errno));
    item = test->head;
    DESTROY(alist_t, test);
    cr_expect_null(test);
    free(item);
}

Test(alist, vt_add_one_to_empty)
{
    GRAPH_AD(alist_t) test = NEW(alist_t, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->vt->add_item(test, "non"), 0);
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    cr_expect_not_null(test->head, ".head = %p", test->head);
    cr_expect_not_null(test->last, ".last = %p", test->last);
    cr_expect_eq(test->head, test->last,
        ".head = %p, .last = %p", test->head, test->last);
    cr_expect_not(test->head->i, ".head.i = %zu", test->head->i);
    cr_expect_not_null(test->head->iptr, ".head.iptr = %p", test->head->iptr);
    cr_expect_str_eq(test->head->iptr, "non",
        ".head.iptr = %s", test->head->iptr);
}

Test(alist, vt_add_one_to_non_empty)
{
    GRAPH_AD(alist_t) test = NEW(alist_t, "peut-etre");

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->vt->add_item(test, "je ne sais pas"), 1);
    cr_expect_eq(test->size, 2, ".size = %zu", test->size);
    cr_expect_not_null(test->head, ".head = %p", test->head);
    cr_expect_not_null(test->last, ".last = %p", test->last);
    cr_expect_neq(test->head, test->last,
        ".head = %p, .last = %p", test->head, test->last);
    cr_expect_eq(test->head->i, 0, ".head.i = %zu", test->head->i);
    cr_expect_eq(test->last->i, 1, ".last.i = %zu", test->last->i);
    cr_expect_not_null(test->head->iptr, ".head.iptr = %p", test->head->iptr);
    cr_expect_not_null(test->last->iptr, ".last.iptr = %p", test->last->iptr);
    cr_expect_str_eq(test->head->iptr, "peut-etre",
        ".head.iptr = %s", test->head->iptr);
    cr_expect_str_eq(test->last->iptr, "je ne sais pas",
        ".last.iptr = %s", test->last->iptr);
}

Test(alist, vt_contains_id)
{
    GRAPH_AD(alist_t) test = NEW(alist_t, "peux-tu répéter la question ?");

    cr_assert_not_null(test, "%s", strerror(errno));
    test->vt->add_item(test, "Tu n'es pas le patron de moi maintenant !");
    test->vt->add_item(test, "Tu n'es pas le patron de moi maintenant !");
    test->vt->add_item(test, "Tu n'es pas le patron de moi maintenant !");
    test->vt->add_item(test, "Et tu n'es pas si gros.");
    cr_expect_not(test->vt->contains(test, MORPH(XX, 0)));
    cr_expect_not(test->vt->contains(test, MORPH(23, 1)));
    cr_expect_not(test->vt->contains(test, MORPH(ID, 12)));
    cr_expect(test->vt->contains(test, MORPH(ID, 2)));
}

Test(alist, vt_contains_pt)
{
    GRAPH_AD(alist_t) test = NEW(alist_t, "peux-tu répéter la question ?");
    GRAPH_AD(aitem_t) item = NEW(aitem_t, test);

    cr_assert_not_null(test, "%s", strerror(errno));
    test->vt->add_item(test, "Tu n'es pas le patron de moi maintenant !");
    test->vt->add_item(test, "Tu n'es pas le patron de moi maintenant !");
    test->vt->add_item(test, "Tu n'es pas le patron de moi maintenant !");
    test->vt->add_item(test, "Et tu n'es pas si gros.");
    cr_expect_not(test->vt->contains(test, MORPH(PT, NULL)));
    cr_expect_not(test->vt->contains(test, MORPH(PT, item)));
    cr_expect(test->vt->contains(test, MORPH(PT, test->head->next)));
}