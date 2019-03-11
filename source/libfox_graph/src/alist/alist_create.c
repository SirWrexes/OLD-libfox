/*
** EPITECH PROJECT, 2019
** libfox_graph
** File description:
** AList: Adjacency list constructor
*/

#define FOXALIST_CONSTRUCTOR

#include <malloc.h>
#include "private/p_foxgraph.h"
#include "private/p_vtalist.h"

static void *l_abort(alist_t this, str3c_t errstr)
{
    fox_eputs("AList: ");
    fox_eputs(errstr);
    fox_eputs("\n");
    if (this == NULL)
        return NULL;
    for (aitem_t i = this->head; i != NULL; i = i->next)
        DESTROY(aitem_t, &i);
    return NULL;
}

extern alist_t alist_t_create(void *item)
{
    alist_t this = malloc(sizeof(*this));

    if (this == NULL)
        return l_abort(this, "Creation failed.");
    if (item != NULL) {
        this->head = NEW(aitem_t, item);
        if (this->head == NULL)
            return l_abort(this, "Item creation failed.");
        this->size = 1;
    } else {
        this->head = NULL;
        this->size = 0;
    }
    this->last = this->head;
    this->i = 0;
    this->type = MT_LIST;
    return this;
}

#undef FOXALIST_CONSTRUCTOR