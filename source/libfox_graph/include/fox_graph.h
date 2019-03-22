/*
** EPITECH PROJECT, 2019
** libfox_graph
** File description:
** Graph: Public header
*/

#ifndef LIBFOX_FOX_GRAPH_H
#define LIBFOX_FOX_GRAPH_H

#include <sys/types.h>
#include <stdbool.h>
#include "fox_define.h"

#if defined(MORPH)          \
    || defined(ME)          \
    || defined(FGNEW)       \
    || defined(FGVAR)       \
    || defined(FGDESTROY)   \
    || defined(FGITEM)      \
    || defined(MFAIL)
    #undef MORPH
    #undef ME
    #undef FGNEW
    #undef FGVAR
    #undef FGDESTROY
    #undef FGITEM
    #undef MFAIL
#endif

/*
****************************************************************
****************************************************************
*/

// Remember : These are pointers. To access members, use `->`, not `.` !
typedef struct aitem_s *aitem_t;
typedef struct alist_s *alist_t;
typedef struct graph_s *graph_t;

typedef struct pseudo_polymorph_s pmorph_t;
typedef enum pseudo_polymorph_type_e morph_t;

/*
****************************************************************
****************************************************************
*/

/* The following functions return NULL in case of failure. */

// Creates a new graph and retruns its pointer.
// ├ Size : number of rows it graph_t->graph[]
// │ └ Has to be at least 1
// └ Name : Self explanatory.
//   └ Can be NULL
extern graph_t graph_t_create(size_t size, str3c_t name);

// Creates a new adjacency list and retruns its pointer.
// └ Item : iptr for list's head item
//   └ Can be NULL. If so, first added item will be its head.
extern alist_t alist_t_create(void *item);

// Creates a new graph and retruns its pointer.
// └ Item : iptr for the item.
extern aitem_t aitem_t_create(void *item);

extern void graph_t_destroy(graph_t *graphptr);
extern void alist_t_destroy(alist_t *alistptr);
extern void aitem_t_destroy(aitem_t *aitemptr);

/*
****************************************************************
****************************************************************
*/

// OOP style macro for creating graph elements.
#define FGNEW(type, ...)      type##_create(__VA_ARGS__)

// We got a constructor so why not a destructor ?
#define FGDESTROY(type, thing)  type##_destroy(&(thing))

// Use this to create elements that'll auto-destroy
// when leaving the function's scope.
#define FGVAR(type, name, ...)                               \
__cleanup(type##_destroy) type name = FGNEW(type, __VA_ARGS__)

// When you're sure the aitem you're looking for is in the list you're
// using this macro with, this'll greatly simplify the task fetching it
// then casting its iptr into the desired type to access its contents.
//
// Say my list list0 has an n-th item with a struct foo_s (foo_t) in its iptr
// container and foo_t type contains a char* named bar.
// ((foo_t*) list0->vt->fetch(list0, MORPH(ID, n))->iptr)->bar = "baz"
// becomes
// FGITEM(list0, ID, n, foo_t*)->bar = "baz"
#define FGITEM(list, morphtype, morphvalue, type)                        \
((type) (list)->vt->fetch((list), MORPH((morphtype), (morphvalue)))->iptr)

// Error value for (ssize_t) function failures
#define MFAIL (-1)

/*
****************************************************************
****************************************************************
*/

/*
** Pseudo-polymorphism
** Allows for reducing the number of functions used to manipulate the graph
** and its lists. Functions using pseudo-polymorphic items as arguments can
** be called in two ways, always using MORPH marco :
**
** void func(pmorph_t thing, ...):
**   - func(MORPH(ID, <thing's index>), ...)
**   - func(MORPH(PT, <thing's pointer>), ...)
*/

#define MORPH(type, item) (pmorph_t) {(type), {(size_t) (item)}}

enum pseudo_polymorph_type_e {
    ID  , // aitem_t->i
    PT  , // aitem_t->item
    XX  , // For specific functions

    // --- //

    MT_GRAPH = 'g'  ,
    MT_LIST  = 'l'  ,
    MT_ITEM  = 'i'  ,
};

struct pseudo_polymorph_s {
    morph_t type;
    union {
        size_t _id;
        void  *_pt;
    } __transparent;
};

/*
****************************************************************
****************************************************************
*/

struct aitem_s {
    morph_t type;
    void   *iptr;
    /*
    *  As the index (i) may have different values for a single item (iptr)
    *  depending on its presence in multiple adjacency lists, I would
    *  recommend making your item a structure containing a unique ID that
    *  could help differentiate it from other iptr. It may also not be
    *  necessary. It's up to you and the needs of your project.
    *  Happy graphing !
    */
    size_t  i;
    aitem_t next;
};

/*
****************************************************************
****************************************************************
*/

// For the following add_* methods, adding an item that's already
// in the graph/list you're using it from counts as a success,
// while not duplicating the thing's presence.

// contains() and fetch() act exactly the same way except
//   - contains returns a boolean value
//   - fetch returns the item you're looking for
// The algorithm still is 100% identical

struct alist_s {
    morph_t type;
    size_t i;
    ssize_t size;
    aitem_t head;
    aitem_t last;

    const struct vtalist_s {
        #define ME alist_t me
        // Adds an item containing iptr to the list
        // Returns its index or -1 in case of failure
        ssize_t (*add_item)(ME, void *iptr);

        // Returns true if item is in the list
        // Possible thing values
        //   - aitem index
        //   - aitem pointer
        //   - aitem->iptr
        bool (*contains)(ME, pmorph_t thing);

        // If its in the list, returns a pointer to the corresponding aitem
        // Else, returns NULL
        // Possible thing values
        //   - aitem index
        //   - aitem pointer
        //   - aitem->iptr
        aitem_t (*fetch)(ME, pmorph_t thing);

        // If it's in the list, removes thing.
        // Possible thing values :
        //   - aitem index
        //   - aitem pointer
        //   - aitem->iptr
        void (*remove)(ME, pmorph_t thing);

        // Empties the whole list except for its head.
        void (*flush)(ME);
        #undef  ME
    } *vt;
};

/*
****************************************************************
****************************************************************
*/

// For the following add_* methods, adding an item or list that's already
// in the graph/list you're using it from counts as a success,
// while not duplicating the thing's presence.

// contains() and fetch() act exactly the same way except
//   - contains returns a boolean value
//   - fetch returns the list you're looking for
// The algorithm still is 100% identical.
// Same goes for list_contains

struct graph_s {
    morph_t type;
    char    *name;  // Can be NULL
    size_t   size;
    alist_t *graph;

    const struct vtgraph_s {
        #define ME graph_t me
        // Creates a list with item as head and adds it to the graph.
        // Returns new list's index or MFAIL in case of failure.
        ssize_t (*add_list)(ME, void *item);

        // Adds an item to a list.
        // Returns its index in the list on success, returns MFAIL otherwise.
        // Possible thing values
        //   - alist index
        //   - alist pointer
        //   - aitem pointer (adds to first list containing aitem)
        //   - aitem->iptr (adds to first list containing iptr)
        ssize_t (*add_item)(ME, pmorph_t thing, void *item);

        // Returns true if the graph contains given thing.
        // If thing.type isn't ID or PT, returns false.
        // Possible thing values:
        //   - alist index
        //   - alist pointer
        //   - aitem pointer
        //   - aitem->iptr
        bool (*contains)(ME, pmorph_t thing);

        // Gives the return value of alist->contains(item).
        // If list isn't in the graph, returns false.
        // Possible list | item values:
        //   - alist index   | aitem index
        //   - alist pointer | aitem pointer
        //   - aitem pointer | aitem->iptr
        //   - aitem->iptr   |
        // Using an aitem pointer/aitem->iptr for list will search
        // in the first list containing those (see fetch/contains)
        bool (*list_contains)(ME, pmorph_t list, pmorph_t item);

        // If its in the graph, returns a pointer to the corresponding list.
        // Else, returns NULL
        // Possible thing values:
        //   - alist index
        //   - alist pointer
        //   - aitem pointer (fetches first list conatining thing)
        //   - aitem->iptr (fetches first list conatining thing)
        alist_t (*fetch)(ME, pmorph_t list);

        // If thing is a list, remove it from the graph.
        // If it's an aitem, removes it from its container list.
        // └If that aitem is a list's head, removes list from the graph
        // If it's an iptr, removes every corresponding aitem in every list
        // Possible thing values:
        //   - alist index
        //   - alist pointer
        //   - aitem pointer
        //   - aitem->iptr
        void (*remove)(ME, pmorph_t thing);

        // Calls list->flush() function if list is in the graph.
        // If list is any of the follow combinations, flushes every list:
        //   - MOPRH(PT, NULL)
        //   - MOPRH(XX, <anything>)
        //   - MORPH(ID, <something bigger than graph size>)
        void (*flush)(ME, pmorph_t list);
        #undef ME
    } *vt;
};

#endif //LIBFOX_FOX_GRAPH_H
