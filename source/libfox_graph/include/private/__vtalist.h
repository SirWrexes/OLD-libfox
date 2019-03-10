/*
** EPITECH PROJECT, 2019
** libfox
** File description:
** No description
*/

#ifndef FOXALIST_CONSTRUCTOR
#error "vtables should be included only in their corresponding constructors"
#endif

#ifndef LIBFOX_VTALIST_H
#define LIBFOX_VTALIST_H

#include "private/__foxgraph.h"
#define ME alist_t me

static inline ssize_t alist_additem(ME, void *iptr)
{
    aitem_t tmp = me->vt->fetch(me, MORPH(PT, iptr));

    if (tmp != NULL)
        return tmp->i;
    tmp = NEW(aitem_t, iptr);
    if (tmp == NULL)
        return MFAIL;
    me->i += 1;
    tmp->i = me->last->i + 1;
    tmp->next = NULL;
    me->last->next = tmp;
    me->last = tmp;
    return me->last->i;
}

static inline bool alist_contains(ME, pmorph_t thing)
{
    if (thing.type != PT && thing.type != ID)
        return MFAIL;
    for (aitem_t i = me->head; i != NULL; i = i->next)
        if (thing.type == ID
        ?   thing._id == i->i
        :   thing._pt == i || thing._pt == i->iptr)
            return true;
    return false;
}

static inline aitem_t alist_fetch(ME, pmorph_t thing)
{
    if (thing.type != PT && thing.type != ID)
        return NULL;
    for (aitem_t i = me->head; i != NULL; i = i->next)
        if (thing.type == ID
        ?   thing._id == i->i
        :   thing._pt == i || thing._pt == i->iptr)
            return i;
    return NULL;
}

static inline void alist_remove(ME, pmorph_t thing)
{
    aitem_t i = me->head->next;
    aitem_t tmp = me->head;

    if (thing.type != PT && thing.type != ID)
        return;
    if (thing.type == ID
    ?   thing._id == me->head->i
    :   thing._pt == me->head || thing._pt == me->head->iptr)
        DESTROY(alist_t, &me);
    for (; i != NULL; i = i->next) {
        if (thing.type == PT
        ?   thing._pt == i || thing._pt == i->iptr
        :   thing._id == i->i)
            break;
        tmp = tmp->next;
    }
    if (i == NULL)
        return;
    tmp->next = i->next;
    me->size -= 1;
    DESTROY(aitem_t, &i);
}

static inline void alist_flush(ME)
{
    aitem_t i = me->head->next;
    aitem_t tmp;

    while (i != NULL) {
        tmp = i->next;
        DESTROY(aitem_t, &i);
        i = tmp;
    }
}

const struct vtalist_s alist_vt = {
    alist_additem   ,
    alist_contains  ,
    alist_fetch     ,
    alist_remove    ,
    alist_flush     ,
};

#undef ME
#endif //LIBFOX_VTALIST_H
