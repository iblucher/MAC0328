#ifndef UTIL_H_
#define UTIL_H_

#define TRUE 1
#define FALSE 0

/* Vértices de grafos são representados por objetos do tipo Vertex. */
#define Vertex int

struct graph;
typedef struct graph * Graph;

Graph GRAPHinit(int V);

int GRAPHvertex(Graph G);

int GRAPHedges(Graph G);

int GRAPHindegree(Graph G, Vertex v);

int GRAPHoutdegree(Graph G, Vertex v);

void GRAPHinsertArc(Graph G, Vertex v, Vertex w);

void GRAPHremoveArc(Graph G, Vertex v, Vertex w);

int GRAPHsource(Graph G, Vertex v);

void GRAPHshow(Graph G);

#endif