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
    aitem_t stock;

    if (*alistptr == NULL)
        return;
    while ((*alistptr)->head != NULL) {
        stock = (*alistptr)->head;
        (*alistptr)->head = (*alistptr)->head->next;
        FGDESTROY(aitem_t, stock);
    }
    (*alistptr)->last = NULL;
    free(*alistptr);
    *alistptr = NULL;
}