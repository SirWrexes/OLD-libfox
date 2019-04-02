/*
** EPITECH PROJECT, 2019
** libfox_graph
** File description:
** Graph destructor
*/

#include <malloc.h>
#include "fox_graph.h"

extern void graph_t_destroy(graph_t *graphptr)
{
    if (*graphptr == NULL)
        return;
    if ((*graphptr)->name != NULL)
        free((*graphptr)->name);
    if ((*graphptr)->graph != NULL) {
        for (size_t i = 0; i < (*graphptr)->size; i += 1)
            FGDESTROY(alist_t, (*graphptr)->graph[i]);
        free((*graphptr)->graph);
    }
    free(*graphptr);
    *graphptr = NULL;
}