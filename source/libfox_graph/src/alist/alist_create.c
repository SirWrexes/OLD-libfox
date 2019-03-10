/*
** EPITECH PROJECT, 2019
** libfox_graph
** File description:
** AList: Adjacency list constructor
*/

#define FOXALIST_CONSTRUCTOR

#include <malloc.h>
#include "private/__foxgraph.h"
#include "private/__vtalist.h"

static void *l_abort(alist_t this, str3c_t errstr)
{
    fox_eputs("AList:");
    fox_eputs(errstr);
    fox_eputs("\n");
    if (this == NULL)
        return NULL;
    for (aitem_t i = this->head; i != NULL; i = i->next)
        DESTROY(aitem_t, &i);
    return NULL;
}

extern alist_t alist_t_create(void *item, size_t i)
{
    alist_t this = malloc(sizeof(*this));

    if (this == NULL)
        return l_abort(this, "Creation failed.");
    this->head = NEW(aitem_t, item);
    if (this->head == NULL)
        return l_abort(this, "Item creation failed.");
    this->last = this->head;
    this->size = 1;
    this->i = 1;
    return this;
}

#undef FOXALIST_CONSTRUCTOR