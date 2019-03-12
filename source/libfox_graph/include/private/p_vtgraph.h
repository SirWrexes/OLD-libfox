/*
** EPITECH PROJECT, 2019
** libfox_graph
** File description:
** Graph: Graph virtual table
*/

#ifndef FOXGRAPH_CONSTRUCTOR
#error "vtables should be included only in their corresponding constructors"
#endif

#ifndef LIBFOX_VTABLES_H
#define LIBFOX_VTABLES_H

#include "private/p_foxgraph.h"
#define ME graph_t me

static inline ssize_t graph_addlist(ME, void *item)
{
    size_t i;
    alist_t list = me->vt->fetch(me, MORPH(PT, item));

    if (list != NULL)
        return list->i;
    for (i = 0; me->graph[i] != NULL && i < me->size; i += 1);
    if (i == me->size)
        RETURN(MFAIL, fox_eputs("add_list(): Graph is full\n"));
    list = NEW(alist_t, item);
    if (list == NULL)
        RETURN(MFAIL, fox_eputs("add_list(): Abort\n"));
    list->i = i;
    me->graph[i] = list;
    return i;
}

static inline ssize_t graph_additem(ME, pmorph_t list, void *item)
{
    alist_t tmp = NULL;

    if (list.type != ID && list.type != PT)
        return MFAIL;
    tmp = me->vt->fetch(me, list);
    if (tmp == NULL)
        return MFAIL;
    return tmp->vt->add_item(tmp, item);
}

static inline bool graph_contains(ME, pmorph_t thing)
{
    if (thing.type != ID && thing.type != PT)
        return MFAIL;
    for (size_t i = 0; i < me->size; i += 1)
        if (thing.type == ID
        ?   thing._id == me->graph[i]->i
        :   thing._pt == me->graph[i])
            return true;
    if (thing.type != PT)
        return false;
    for (size_t i = 0; i < me->size; i += 1)
        if (thing._pt == me->graph[i]->head
        ||  thing._pt == me->graph[i]->head->iptr)
            return true;
    return false;
}

static inline bool graph_listcontains(ME, pmorph_t list, pmorph_t item)
{
    alist_t tmp = NULL;

    if (list.type != ID && list.type != PT)
        return false;
    tmp = me->vt->fetch(me, list);
    if (tmp == NULL)
        return MFAIL;
    return tmp->vt->contains(tmp, item);
}

static inline alist_t graph_fetch(ME, pmorph_t thing)
{
    if (thing.type != ID && thing.type != PT)
        return NULL;
    for (size_t i = 0; i < me->size; i += 1)
        if (thing.type == ID
        ? thing._id == me->graph[i]->i
        : thing._pt == me->graph[i])
            return me->graph[i];
    if (thing.type != PT)
        return NULL;
    for (size_t i = 0; i < me->size; i += 1)
        if (thing._pt == me->graph[i]->head
        ||  me->graph[i]->vt->contains(me->graph[i], thing))
            return me->graph[i];
    return NULL;
}

static inline void graph_remove(ME, pmorph_t thing)
{
    alist_t tmp = NULL;

    if (thing.type != ID && thing.type != PT)
        return;
    while (true) {
        tmp = me->vt->fetch(me, thing);
        if (tmp == NULL)
            break;
        if (thing.type == ID
        ?   thing._id == tmp->i
        :   thing._pt == tmp || thing._pt == tmp->head)
            DESTROY(alist_t, me->graph[tmp->i]);
        else
            tmp->vt->remove(tmp, thing);
    }
}

static inline void graph_flush(ME, pmorph_t list)
{
    alist_t tmp = NULL;

    if (list.type == XX
    || (list.type == PT && list._pt == NULL)
    || (list.type == ID && list._id > me->size))
        for (size_t i = 0; i < me->size; i += 1)
            me->graph[i]->vt->flush(me->graph[i]);
    tmp = me->vt->fetch(me, list);
    if (tmp != NULL)
        tmp->vt->flush(tmp);
}

static const struct vtgraph_s vt = {
    graph_addlist       ,
    graph_additem       ,
    graph_contains      ,
    graph_listcontains  ,
    graph_fetch         ,
    graph_remove        ,
    graph_flush         ,
};

#undef ME
#endif //LIBFOX_VTABLES_H
