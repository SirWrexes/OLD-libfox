/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#include "fox_graph.h"
#include "test_include.h"
#include "graph/test_graph_extra.h"

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