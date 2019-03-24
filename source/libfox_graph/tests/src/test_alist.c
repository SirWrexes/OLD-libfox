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
#include "test_malloc.h"

static void init(void)
{
    errno = 0;
    cr_redirect_stderr();
}

TestSuite(alist, .init = init, .fini = reset_malloc_cpt);

Test(alist, create_empty)
{
    FGVAR(alist_t, test, NULL);

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
    FGVAR(alist_t, test, "euuuuuuuuuuh");

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
    alist_t test = FGNEW(alist_t, "oui");

    cr_assert_not_null(test, "%s", strerror(errno));
    item = test->head;
    FGDESTROY(alist_t, test);
    cr_expect_null(test);
    free(item);
}

Test(alist, vt_add_one_to_empty)
{
    FGVAR(alist_t, test, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->size, 0, ".size = %zu", test->size);
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
    FGVAR(alist_t, test, "peut-etre");

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
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

Test(alist, add_duplicate)
{
    FGVAR(alist_t, test, &test);

    cr_assert_not_null(test);
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    cr_expect_eq(test->vt->add_item(test, &test), test->head->i);
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
}

Test(alist, vt_contains_id)
{
    FGVAR(alist_t, test, "peux-tu répéter la question ?");

    cr_assert_not_null(test);
    test->vt->add_item(test, "Tu n'es pas le patron de moi maintenant !");
    test->vt->add_item(test, "Tu n'es pas le patron de moi maintenant !");
    test->vt->add_item(test, "Tu n'es pas le patron de moi maintenant !");
    test->vt->add_item(test, "Et tu n'es pas si gros.");
    cr_expect_not(test->vt->contains(test, MORPH(ID, 12)));
    cr_expect(test->vt->contains(test, MORPH(ID, 2)));
}

Test(alist, vt_contains_pt)
{
    FGVAR(alist_t, test, "peux-tu répéter la question ?");
    FGVAR(aitem_t, item, test);

    cr_assert_not_null(test, "%s", strerror(errno));
    test->vt->add_item(test, "Tu n'es pas le patron de moi maintenant !");
    test->vt->add_item(test, "Tu n'es pas le patron de moi maintenant !");
    test->vt->add_item(test, "Tu n'es pas le patron de moi maintenant !");
    test->vt->add_item(test, "Et tu n'es pas si gros.");
    cr_expect_not(test->vt->contains(test, MORPH(PT, NULL)));
    cr_expect_not(test->vt->contains(test, MORPH(PT, item)));
    cr_expect(test->vt->contains(test, MORPH(PT, test->head->next)));
}

Test(alist, vt_contains_mfail)
{
    FGVAR(alist_t, test, "Je sens quelque-chose...");

    cr_assert_not_null(test);
    cr_expect_not(test->vt->contains(test, MORPH(PT, NULL)));
    cr_expect_not(test->vt->contains(test, MORPH(XX, 0)));
    cr_expect_not(test->vt->contains(test, MORPH(23, 1)));
}

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

Test(alist, vt_remove_id)
{
    FGVAR(alist_t, test, "Can't touch this");

    cr_assert_not_null(test);
    test->vt->add_item(test, &test);
    cr_expect_eq(test->size, 2, ".size = %zu", test->size);
    test->vt->remove(test, MORPH(ID, test->last->i));
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    cr_expect_eq(test->head, test->last,
        ".head = %p, .last = %p", test->head, test->last);
}

Test(alist, vt_remove_pt)
{
    FGVAR(alist_t, test, "Cant touch this");

    cr_assert_not_null(test);
    test->vt->add_item(test, test);
    cr_expect_eq(test->size, 2, ".size = %zu", test->size);
    test->vt->remove(test, MORPH(PT, test->vt->fetch(test, MORPH(PT, test))));
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    cr_expect_eq(test->head, test->last,
        ".head = %p, .last = %p", test->head, test->last);
}

Test(alist, vt_remove_iptr)
{
    FGVAR(alist_t, test, "Cant touch this");

    cr_assert_not_null(test);
    test->vt->add_item(test, test);
    cr_expect_eq(test->size, 2, ".size = %zu", test->size);
    test->vt->remove(test, MORPH(PT, test));
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    cr_expect_eq(test->head, test->last,
        ".head = %p, .last = %p", test->head, test->last);
}

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

Test(alist, vt_remove_mfail)
{
    FGVAR(alist_t, test, "Cant touch this");

    cr_assert_not_null(test);
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    test->vt->add_item(test, &test);
    cr_expect_eq(test->size, 2, ".size = %zu", test->size);
    test->vt->remove(test, MORPH(PT, NULL));
    test->vt->remove(test, MORPH(ID, 23));
    test->vt->remove(test, MORPH(XX, 42));
    cr_expect_eq(test->size, 2, ".size = %zu", test->size);
}

Test(alist, vt_flush)
{
    FGVAR(alist_t, test, "STOP !");

    cr_assert_not_null(test);
    test->vt->add_item(test, "Hammer time !");
    test->vt->add_item(test, "dududdididoduydu");
    test->vt->add_item(test, "dududoiddidudud");
    test->vt->add_item(test, "didudududidiududu");
    test->vt->add_item(test, "dudidudodududu");
    cr_expect_eq(test->size, 6, ".size = %zu", test->size);
    test->vt->flush(test);
    cr_expect_eq(test->size, 1);

}

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