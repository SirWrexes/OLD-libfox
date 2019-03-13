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

#ifndef FOX_MACRO
    #ifndef FOX_GRAPH_MACRO
        #define FOX_GRAPH_MACRO
        #undef __a
        #undef __transparent
        #undef RETURN

        #define __a(__) __attribute__ (__)
        #define __transparent __a((__transparent_union__))
        #define RETURN(value, funcs...) return (0 ? : ((funcs), (value)))
    #endif // FOX_GRAPH_MACRO

    #ifndef CCSTR_TYPE
        #define CCSTR_TYPE
        typedef char const * const * const  str4c_t;
        typedef char const * const          str3c_t;
        typedef char const *                str2c_t;
        typedef char *                      str_t;
    #endif //CCSTR_TYPE
#endif // FOX_MACRO

#if defined(MORPH)      \
    || defined(ME)      \
    || defined(NEW)     \
    || defined(DESTROY) \
    || defined(MFAIL)   \
    || defined(FOXGRAPH)
    #undef MORPH
    #undef ME
    #undef NEW
    #undef MFAIL
    #undef DESTROY
    #undef FOXGRAPH
#endif

/*
****************************************************************
****************************************************************
*/

// OOP style macro for creating graph elements.
#define NEW(type, ...)      type##_create(__VA_ARGS__)

// We got a constructor so why not a destructor ?
#define DESTROY(type, ptr)  type##_destroy(&(ptr))

// Use this to create elements that'll auto-destroy
// when leaving the function's scope.
#define FOXGRAPH(type)      __attribute__((cleanup(type##_destroy))) type

// Error value for boolean Methods
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

typedef enum pseudo_polymorph_type_e {
    ID  , // aitem_t->i
    PT  , // aitem_t->item
    XX  , // For specific functions

    // --- //

    MT_GRAPH = 'g'  ,
    MT_LIST  = 'l'  ,
    MT_ITEM  = 'i'  ,
} morph_t;

typedef struct pseudo_polymorph_s {
    morph_t type;
    union {
        size_t _id;
        void *_pt;
    } __transparent;
} pmorph_t;

/*
****************************************************************
****************************************************************
*/

// Remember : These are pointers. To access members, use `->`, not `.` !
typedef struct aitem_s *aitem_t;
typedef struct alist_s *alist_t;
typedef struct graph_s *graph_t;

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
        //   - aitem pointer (adds to list cntaining aitem)
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

        // Gives the return value of list->contains(item).
        // If list isn't in the graph, returns false.
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

#endif //LIBFOX_FOX_GRAPH_H
