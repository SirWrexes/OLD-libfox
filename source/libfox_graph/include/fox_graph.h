/*
** EPITECH PROJECT, 2019
** libfox_graph
** File description:
** Graph: Public header
*/

#ifndef LIBFOX_FOX_GRAPH_H
#define LIBFOX_FOX_GRAPH_H

#include <stdbool.h>

#if (defined MORPH) || (define ME)
    #undef MORPH
    #undef ME
#endif

/*
** Pseudo-polymorphism
** Allows for reducing the number of functions used to manipulate the graph
** and its lists. Functions using pseudo-polymorphic items as arguments can
** be called in two ways :
**
** Consider this function : void func(pitem_t pi);
** You can either do
** func(MORPH(ID, 12) implying desired item's i equals 12
** -- OR
** func(MORPH(PT, iptr) where iptr would be the pointer stored in void* item
**
** Providing an iptr when ID is given or vice versa gives undefined behaviour.
*/

typedef enum pseudo_polymorph_type_e {
    ID  , // aitem_t->i
    PT  , // aitem_t->item
    XX  , // For specific functions
} ptype_t;

typedef struct pseudo_polymorph_s {
    ptype_t type;
    union {
        size_t _id;
        void  *_pt;
    } __a((__transparent_union__));
} pmorph_t;

#define MORPH(type, item) ((pmorph_t) {type, {item}})

typedef struct aitem_s *aitem_t;
typedef struct alist_s *alist_t;
typedef struct graph_s *graph_t;

struct aitem_s {
    ssize_t i;
    void   *iptr;
    /* As the index (i) may have different values for a single item (iptr)
    *  depending on its presence in multiple adjacency lists, I would
    *  recommend making your item a structure containing a unique ID that
    *  could help differentiate it from other iptr. It may also not be
    *  necessary. It's up to you and the needs and your project.
    *  Happy coding !
    **/

    aitem_t next;
};

/*
****************************************************************
****************************************************************
*/

// For the following add_* methods, item to add being already
// in the container you want to add it to counts as a success
// while not actually adding it again

struct alist_s {
    #define ME alist_t me
    ssize_t size;
    aitem_t head;
    aitem_t last;

    // Adds an item containing iptr to the list
    // Returns its index or -1 in case of failure
    ssize_t (*add_item)(ME, void *iptr);

    // Returns true if item is in the list
    bool (*contains)(ME, pmorph_t item);

    // If its in the list, returns a pointer to the corresponding aitem
    // Else, returns NULL
    aitem_t (*fetch)(ME, pmorph_t item);

    // Removes an item using its index or iptr
    // Does nothing if item isn't in the list
    void (*rm_item)(ME, pmorph_t item);

    // Empty the whole list except for its head;
    void (*flush)(ME);
};

struct graph_s {
    #define ME graph_s me
    char    *name;  // Can be NULL
    size_t   size;
    alist_t *graph;

    // Creates a list and adds it to the graph.
    // Returns new list's index or -1 in case of failure
    ssize_t (*add_list)(ME, void *item);

    // Adds an item to chosen list
    // Returns its index on success -1 otherwise.
    ssize_t (*add_item)(ME, pmorph_t list, void *item)

    // Returns true if the graph contains given thing.
    // Possible thing values:
    //   - index of an alist
    //   - alist pointer
    //   - aitem pointer
    //   - aitem->iptr
    bool (*contains)(ME, pmorph_t thing)

    // Gives the return value of list->contains(item)
    // If list isn't in the graph, returns -1.
    bool (list_contains)(ME, pmorph_t list, pmorph_t item);

    // If its in the graph, returns a pointer to the corresponding alist
    // Else, returns NULL
    alist_t (*fetch)(ME, pmorph_t list);

    // If thing is a list, remove it from the graph.
    // If it's an aitem, removes it from its container list.
    // If it's an iptr, removes every aitem corresponding to it in every list
    void (*remove)(ME, pmorph_t thing);

    // Calls list->flush() function if list is in the graph.
    // If any list is any of the follow combinations, flushes every list:
    //   - MOPRH(PT, NULL)
    //   - MOPRH(XX, <anything>)
    //   - MOPRH(ID, <negative index>)
    void (*flush)(ME, pmorph_t list);
};

#undef ME
#endif //LIBFOX_FOX_GRAPH_H
