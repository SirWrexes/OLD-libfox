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

#include "private/p_foxgraph.h"

#undef ME
#define ME alist_t me

#undef UNALLOWED_THING
#define UNALLOWED_THING(thing)                  \
(                                               \
    ((thing).type != PT && (thing).type != ID)  \
    ||                                          \
    ((thing).type == PT && (thing)._pt == NULL) \
)

#undef MATCH
#define MATCH(thing, x)                                 \
(                                                       \
    (thing).type == ID                                  \
    ? (thing)._id == (x)->i                             \
    : (thing)._pt == (x) || (thing)._pt == (x)->iptr    \
)

static inline ssize_t alist_additem(ME, void *iptr)
{
    aitem_t tmp = me->vt->fetch(me, MORPH(PT, iptr));

    if (tmp != NULL)
        return tmp->i;
    tmp = NEW(aitem_t, iptr);
    if (tmp == NULL)
        return MFAIL;
    me->size += 1;
    tmp->i = (me->head == NULL) ? 0 : me->last->i + 1;
    me->head = me->head ? : tmp;
    tmp->next = NULL;
    if (me->last != NULL)
        me->last->next = tmp;
    me->last = tmp;
    return me->last->i;
}

static inline bool alist_contains(ME, pmorph_t thing)
{
    if (UNALLOWED_THING(thing))
        return false;
    for (aitem_t i = me->head; i != NULL; i = i->next)
        if (MATCH(thing, i))
            return true;
    return false;
}

static inline aitem_t alist_fetch(ME, pmorph_t thing)
{
    if (UNALLOWED_THING(thing))
        return  NULL;
    for (aitem_t i = me->head; i != NULL; i = i->next)
        if (MATCH(thing, i))
            return i;
    return NULL;
}

static inline void alist_remove(ME, pmorph_t thing)
{
    aitem_t tmp = me->head;
    aitem_t i = tmp != NULL ? tmp->next : NULL;

    if (UNALLOWED_THING(thing))
        return;
    if (MATCH(thing, me->head))
        DESTROY(alist_t, me);
    for (; i != NULL; i = i->next) {
        if (MATCH(thing, i))
            break;
        tmp = tmp->next;
    }
    if (i == NULL)
        return;
    if (i == me->last)
        me->last = me->vt->fetch(me, MORPH(ID, i->i - 1));
    tmp->next = i->next;
    me->size -= 1;
    DESTROY(aitem_t, i);
}

static inline void alist_flush(ME)
{
    while (me->last != me->head)
        me->vt->remove(me, MORPH(ID, me->last->i));
}

const struct vtalist_s vt = {
    alist_additem   ,
    alist_contains  ,
    alist_fetch     ,
    alist_remove    ,
    alist_flush     ,
};

#undef ME
#endif //LIBFOX_VTALIST_H
