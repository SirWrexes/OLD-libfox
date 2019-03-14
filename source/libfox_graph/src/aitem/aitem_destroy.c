/*
** EPITECH PROJECT, 2019
** libfox_graph
** File description:
** AItem Adjacency list item destructor
*/

#include <malloc.h>
#include "private/p_foxgraph.h"

extern void aitem_t_destroy(aitem_t *this)
{
    if (*this == NULL)
        return;
    for (aitem_t i = (*this)->next; i != NULL; i = i->next)
        i->i -= 1;
    free(*this);
    *this = NULL;
}