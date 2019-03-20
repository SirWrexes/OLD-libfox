/*
** EPITECH PROJECT, 2019
** libfox_graph
** File description:
** AItem Adjacency list item constructor
*/

#include <malloc.h>
#include "private/p_foxgraph.h"

static void *i_abort(aitem_t this, str3c_t errstr)
{
    fox_eputs("AItem:");
    fox_eputs(errstr);
    fox_eputs("\n");
    FGDESTROY(aitem_t, this);
    return NULL;
}

__a((nonnull))
extern aitem_t aitem_t_create(void *iptr)
{
    aitem_t this = malloc(sizeof(*this));

    if (this == NULL)
        return i_abort(this, "Creation failed.");
    this->i = 0;
    this->iptr = iptr;
    this->next = NULL;
    this->type = MT_ITEM;
    return this;
}