//
// Created by PENG on 18/10/2017.
//

#ifndef ASS2_GRAPH_H
#define ASS2_GRAPH_H

#endif //ASS2_GRAPH_H
// Graph ADT interface ... COMP9024 17s2
#include <stdbool.h>

typedef struct GraphRep *Graph;

// vertices are ints
typedef int Vertex;

// edges are pairs of vertices (end-points)
typedef struct Edge {
    Vertex v;
    Vertex w;
} Edge;

Graph newGraph(int);
void  insertEdge(Graph, Edge);
void  removeEdge(Graph, Edge);
bool  adjacent(Graph, Vertex, Vertex);
void  showGraph(Graph);
void  freeGraph(Graph);
