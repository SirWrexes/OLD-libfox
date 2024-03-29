/*
** EPITECH PROJECT, 2019
** libfox_graph
** File description:
** Graph: Graph virtual table
*/

#ifndef LIBFOX_VTABLES_H
#define LIBFOX_VTABLES_H

#include "private/p_foxgraph.h"
#define ME graph_t me

#undef UNALLOWED_THING
#define UNALLOWED_THING(thing)                  \
(                                               \
    ((thing).type != PT && (thing).type != ID)  \
    ||                                          \
    ((thing).type == PT && (thing)._pt == NULL) \
)

static inline ssize_t graph_addlist(ME, void *item)
{
    size_t i;
    alist_t list = me->vt->fetch(me, MORPH(PT, item));

    if (list != NULL && list->head != NULL && list->head->iptr == item)
        return list->i;
    for (i = 0; me->graph[i] != NULL && i < me->size; i += 1);
    if (i == me->size)
        RETURN(MFAIL, fox_eputs("add_list(): Graph is full\n"));
    list = FGNEW(alist_t, item);
    if (list == NULL)
        RETURN(MFAIL, fox_eputs("add_list(): Abort\n"));
    list->i = i;
    me->graph[i] = list;
    return i;
}

static inline ssize_t graph_additem(ME, pmorph_t list, void *item)
{
    alist_t tmp = NULL;

    if (UNALLOWED_THING(list))
        return MFAIL;
    tmp = me->vt->fetch(me, list);
    if (tmp == NULL)
        return MFAIL;
    return tmp->vt->add_item(tmp, item);
}

#undef MATCH
#define MATCH(thing, x, j)                                      \
(                                                               \
    (thing).type == ID                                          \
    ?  (x)->graph[(thing)._id] != NULL                          \
    :  (thing)._pt == (x)->graph[j]                             \
    || ((x)->graph[j] != NULL &&                                \
        (x)->graph[j]->vt->contains((x)->graph[j], (thing)))    \
)

static inline bool graph_contains(ME, pmorph_t thing)
{
    if (UNALLOWED_THING(thing))
        return false;
    for (size_t i = 0; i < me->size; i += 1)
        if (MATCH(thing, me, i))
            return true;
    return false;
}

static inline bool graph_listcontains(ME, pmorph_t list, pmorph_t item)
{
    alist_t tmp = NULL;

    if (UNALLOWED_THING(list))
        return false;
    tmp = me->vt->fetch(me, list);
    if (tmp == NULL)
        return false;
    return tmp->vt->contains(tmp, item);
}

static inline alist_t graph_fetch(ME, pmorph_t thing)
{
    if (UNALLOWED_THING(thing))
        return NULL;
    if (thing.type == ID
    &&  me->size > thing._id
    &&  me->graph[thing._id] != NULL)
        return me->graph[thing._id];
    for (size_t i = 0; i < me->size; i += 1) {
        if (me->graph[i] == NULL)
            continue;
        if (MATCH(thing, me, i))
            return me->graph[i];
    }
        return NULL;
}

static inline void graph_remove(ME, pmorph_t thing)
{
    alist_t tmp = NULL;

    if (UNALLOWED_THING(thing))
        return;
    while (true) {
        tmp = me->vt->fetch(me, thing);
        if (tmp == NULL)
            break;
        if (thing.type == ID
        ?   thing._id == tmp->i
        :   thing._pt == me->graph[tmp->i]
        ||  thing._pt == tmp->head
        ||  (tmp->head != NULL && thing._pt == tmp->head->iptr))
            FGDESTROY(alist_t, me->graph[tmp->i]);
        else
            tmp->vt->remove(tmp, thing);
    }
}

static inline void graph_flush(ME, pmorph_t list)
{
    alist_t tmp = NULL;

    if (UNALLOWED_THING(list) || (list.type == ID && list._id > me->size))
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
