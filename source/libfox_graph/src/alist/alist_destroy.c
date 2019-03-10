/*
** EPITECH PROJECT, 2019
** libfox_graph
** File description:
** AList: Adjacency list destructor
*/

#include <malloc.h>
#include "fox_graph.h"

extern void alist_t_destroy(alist_t *alistptr)
{
    if (*alistptr == NULL)
        return;
    for (aitem_t i = (*alistptr)->head; i != NULL; i = i->next)
        DESTROY(aitem_t, i);
    *alistptr = NULL;
}