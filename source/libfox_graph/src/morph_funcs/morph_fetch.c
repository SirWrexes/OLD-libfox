/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** Polymorphic graph fetch
*/

#include "private/p_foxgraph.h"

extern void *fox_graphfetch(pmorph_t thing, void *in)
{
    switch (((graph_t) in)->type) {
    default :
        fox_eputs("graphfetch(): invalid container type");
        return NULL;
    case MT_GRAPH : return ((graph_t) in)->vt->fetch(in, thing);
    case MT_LIST : return ((alist_t) in)->vt->fetch(in, thing);
    }
}