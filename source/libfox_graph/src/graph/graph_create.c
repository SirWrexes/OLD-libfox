/*
** EPITECH PROJECT, 2019
** libfox_graph
** File description:
** Graph constructor
*/

#define FOXGRAPH_CONSTRUCTOR

#include <malloc.h>
#include "private/p_foxgraph.h"
#include "private/p_vtgraph.h"

static void *g_abort(graph_t this, str3c_t errstr)
{
    fox_eputs("Graph: ");
    fox_eputs(errstr);
    fox_eputs("\n");
    if (this == NULL)
        return NULL;
    if (this->name != NULL)
        free(this->name);
    if (this->graph != NULL)
        free(this->graph);
    return NULL;
}

extern graph_t graph_t_create(size_t size, str3c_t name)
{
    graph_t this = malloc(sizeof(*this));

    if (this == NULL)
        return g_abort(this, "Creation failed.");
    this->graph = malloc(size * sizeof(*this->graph));
    if (this->graph == NULL)
        return g_abort(this, "Array allocation failed.");
    for (size_t i = 0; i < size; i += 1)
        this->graph[i] = NULL;
    this->size = size;
    if (name != NULL)
        this->name = fox_strdup(name);
    if (this->name == NULL)
        return g_abort(this, "Name assignation failed.");
    this->vt = &vt;
    this->type = MT_GRAPH;
    return this;
}

#undef FOXGRAPH_CONSTRUCTOR