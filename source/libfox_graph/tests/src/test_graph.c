/*
** EPITECH PROJECT, 2019
** libfox_graph UT
** File description:
** Graph
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

TestSuite(graph, .init = reset_errno);

Test(graph, create_unnamed)
{
    str3c_t name = NULL;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, name);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->type, MT_GRAPH, ".type = %d", test->type);
    cr_assert_null(test->name, ".name (ptr) = %p", test->name);
    cr_expect_eq(test->size, 1, ".size = %zu", test->size);
    cr_assert_not_null(test->graph, ".graph = %p", test->graph);
    for (size_t i = 0; i < test->size; i += 1)
        cr_expect_null(test->graph[i], ".graph[%zu] = %p", i, test->graph[i]);
}

Test(graph, create_named)
{
    str3c_t name = "t ki dan le sport";
    FOXGRAPH(graph_t) test = NEW(graph_t, 3, name);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_eq(test->type, MT_GRAPH, ".type = %d", test->type);
    cr_assert_not_null(test->name, ".name (ptr) = %p", test->name);
    cr_expect_str_eq(test->name, name, ".name = %s", test->name);
    cr_expect_eq(test->size, 3, ".size = %zu", test->size);
    cr_assert_not_null(test->graph, ".graph = %p", test->graph);
    for (size_t i = 0; i < test->size; i += 1)
        cr_expect_null(test->graph[i], ".graph[%zu] = %p", i, test->graph[i]);
}

Test(graph, create_invalid_size)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 0, NULL);

    cr_assert_null(test, "test = %p", test);
}

Test(graph, destroy)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 2, "sauce");

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, destroy_null_graph_t)
{
    graph_t test = NULL;

    DESTROY(graph_t, test);
}

Test(graph, destroy_null_grapharray)
{
    graph_t test = calloc(1, sizeof(*test));

    cr_assert_not_null(test, "%s", strerror(errno));
    DESTROY(graph_t, test);
}

Test(graph, vt_add_list_to_empty)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_assert_neq(test->vt->add_list(test, test), MFAIL,
        "%s", strerror(errno));
    cr_expect_eq(test->graph[0]->head->iptr, test,
        ".graph[0]-->iptr = %p, test = %p", test->graph[0]->head->iptr, test);
}

Test(graph, vt_add_list_to_non_empty)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 3, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_assert_neq(test->vt->add_list(test, test),
        MFAIL, "%s", strerror(errno));
    cr_assert_neq(test->vt->add_list(test, &test),
        MFAIL, "%s", strerror(errno));
    cr_expect_eq(test->graph[0]->head->iptr, test,
        ".graph[0]-->iptr = %p, test = %p", test->graph[0]->head->iptr, test);
    cr_expect_eq(test->graph[1]->head->iptr, &test,
        ".graph[1]-->iptr = %p, test = %p", test->graph[1]->head->iptr, test);
}

Test(graph, vt_add_list_to_full)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_assert_neq(test->vt->add_list(test, test), MFAIL, "%s", strerror(errno));
    cr_expect_eq(test->graph[0]->head->iptr, test,
        ".graph[0]-->iptr = %p, test = %p", test->graph[0]->head->iptr, test);
    cr_expect_eq(test->vt->add_list(test, &test), MFAIL);
}

Test(graph, vt_add_list_duplicate)
{
    ssize_t id = 0;
    FOXGRAPH(graph_t) test = NEW(graph_t, 2, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    id = test->vt->add_list(test, test);
    cr_expect_eq(test->vt->add_list(test, test), id);
    cr_expect_null(test->graph[1], ".graph[1] = %p", test->graph[1]);
}

Test(graph, vt_add_item_empty_id)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);
    alist_t list;

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, NULL)));
    cr_expect_not(list->size, ".size = %zu", list->size);
    cr_expect_not(test->vt->add_item(test, MORPH(ID, list->i), test));
    cr_expect(list->size, ".size = %zu", list->size);
    cr_expect_eq(list->head, list->last,
        ".head = %p, .last = %p", list->head, list->last);
}

Test(graph, vt_add_item_empty_alist)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);
    alist_t list;

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, NULL)));
    cr_expect_not(list->size, ".size = %zu", list->size);
    cr_expect_not(test->vt->add_item(test, MORPH(PT, list), test));
    cr_expect(list->size, ".size = %zu", list->size);
    cr_expect_eq(list->head, list->last,
        ".head = %p, .last = %p", list->head, list->last);
}

Test(graph, vt_add_item_id)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);
    alist_t list;

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(test->vt->add_item(test, MORPH(ID, list->i), &test), 1);
    cr_expect_eq(list->size, 2, ".size = %zu", list->size);
    cr_expect_neq(list->head, list->last,
        ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, test);
    cr_expect_eq(list->last->iptr, &test);
}

Test(graph, vt_add_item_id_duplicate)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);
    alist_t list;

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(test->vt->add_item(test, MORPH(ID, list->i), test), 0);
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(list->head, list->last,
        ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, test);
}

Test(graph, vt_add_item_alist)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);
    alist_t list;

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(test->vt->add_item(test, MORPH(PT, list), &test), 1);
    cr_expect_eq(list->size, 2, ".size = %zu", list->size);
    cr_expect_neq(list->head, list->last,
        ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, test);
    cr_expect_eq(list->last->iptr, &test);
}

Test(graph, vt_add_item_alist_duplicate)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);
    alist_t list;

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(test->vt->add_item(test, MORPH(PT, list), test), 0);
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(list->head, list->last,
        ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, test);
}

Test(graph, vt_add_item_aitem)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);
    alist_t list;

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(test->vt->add_item(test, MORPH(PT, list->head), &test), 1);
    cr_expect_eq(list->size, 2, ".size = %zu", list->size);
    cr_expect_neq(list->head, list->last,
        ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, test);
    cr_expect_eq(list->last->iptr, &test);
}

Test(graph, vt_add_item_aitem_duplicate)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);
    alist_t list;

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(test->vt->add_item(test, MORPH(PT, list->head), test), 0);
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(list->head, list->last,
        ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, test);
}

Test(graph, vt_add_item_iptr)
{
    FOXGRAPH(graph_t) t = NEW(graph_t, 1, NULL);
    alist_t list;

    cr_assert_not_null(t, "%s", strerror(errno));
    list = t->vt->fetch(t, MORPH(ID, t->vt->add_list(t, t)));
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(t->vt->add_item(t, MORPH(PT, list->head->iptr), &t), 1);
    cr_expect_eq(list->size, 2, ".size = %zu", list->size);
    cr_expect_neq(list->head, list->last,
        ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, t);
    cr_expect_eq(list->last->iptr, &t);
}

Test(graph, vt_add_item_iptr_duplicate)
{
    FOXGRAPH(graph_t) t = NEW(graph_t, 1, NULL);
    alist_t list;

    cr_assert_not_null(t, "%s", strerror(errno));
    list = t->vt->fetch(t, MORPH(ID, t->vt->add_list(t, t)));
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(t->vt->add_item(t, MORPH(PT, list->head->iptr), t), 0);
    cr_expect_eq(list->size, 1, ".size = %zu", list->size);
    cr_expect_eq(list->head, list->last,
        ".head = %p, .last = %p", list->head, list->last);
    cr_expect_eq(list->head->iptr, t);
}

Test(graph, vt_contains_id)
{
    ssize_t id;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    id = test->vt->add_list(test, test);
    cr_expect_neq(id, MFAIL, "id = %ld", id);
    cr_expect(test->vt->contains(test, MORPH(ID, id)));
}

Test(graph, vt_contains_alist)
{
    alist_t list = NULL;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect(test->vt->contains(test, MORPH(PT, list)));
}

Test(graph, vt_contains_aitem)
{
    alist_t list = NULL;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect(test->vt->contains(test, MORPH(PT, list->head)));
}

Test(graph, vt_contains_iptr)
{
    alist_t list = NULL;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    list = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    cr_expect(test->vt->contains(test, MORPH(PT, list->head->iptr)));
}

Test(graph, vt_contains_mfail)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    cr_expect_not(test->vt->contains(test, MORPH(PT, NULL)));
    cr_expect_not(test->vt->contains(test, MORPH(XX, 0)));
    cr_expect_not(test->vt->contains(test, MORPH(-2, 0)));
}

Test(graph, vt_list_contains_id_id)
{
    alist_t l;
    aitem_t i;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(ID, l->i), MORPH(ID, i->i)));
}

Test(graph, vt_list_contains_id_aitem)
{
    alist_t l;
    aitem_t i;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(ID, l->i), MORPH(PT, i)));
}

Test(graph, vt_list_contains_id_iptr)
{
    alist_t l;
    aitem_t i;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(ID, l->i),
        MORPH(PT, i->iptr)));
}

Test(graph, vt_list_contains_alist_id)
{
    alist_t l;
    aitem_t i;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(PT, l), MORPH(ID, i->i)));
}

Test(graph, vt_list_contains_alist_aitem)
{
    alist_t l;
    aitem_t i;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(PT, l), MORPH(PT, i)));
}

Test(graph, vt_list_contains_alist_iptr)
{
    alist_t l;
    aitem_t i;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(PT, l), MORPH(PT, i->iptr)));
}

Test(graph, vt_list_contains_aitem_id)
{
    alist_t l;
    aitem_t i;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(PT, i), MORPH(ID, i->i)));
}

Test(graph, vt_list_contains_aitem_aitem)
{
    alist_t l;
    aitem_t i;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(PT, i), MORPH(PT, i)));
}

Test(graph, vt_list_contains_aitem_iptr)
{
    alist_t l;
    aitem_t i;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(PT, i), MORPH(PT, i->iptr)));
}

Test(graph, vt_list_contains_iptr_id)
{
    alist_t l;
    aitem_t i;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(PT, i->iptr),
        MORPH(ID, i->i)));
}

Test(graph, vt_list_contains_iptr_aitem)
{
    alist_t l;
    aitem_t i;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(PT, i->iptr),
        MORPH(PT, i)));
}

Test(graph, vt_list_contains_iptr_iptr)
{
    alist_t l;
    aitem_t i;
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
    l = test->vt->fetch(test, MORPH(ID, test->vt->add_list(test, test)));
    i = l->vt->fetch(l, MORPH(ID, l->vt->add_item(l, l)));
    cr_expect(test->vt->list_contains(test, MORPH(PT, i->iptr),
        MORPH(PT, i->iptr)));
}

Test(graph, vt_list_contains_mfail)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, vt_fetch)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, vt_remove)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}

Test(graph, vt_flush)
{
    FOXGRAPH(graph_t) test = NEW(graph_t, 1, NULL);

    cr_assert_not_null(test, "%s", strerror(errno));
}