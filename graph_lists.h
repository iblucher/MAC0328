#ifndef LISTS_H_
#define LISTS_H_

/* Vértices de grafos são representados por objetos do tipo Vertex. */
#define Vertex int

typedef struct graph * Graph;

Graph GRAPHinit(int V);

int GRAPHvertex(Graph G);

int GRAPHedges(Graph G);

int GRAPHindegree(Graph G, Vertex v);

int GRAPHoutdegree(Graph G, Vertex v);

void GRAPHinsertArc(Graph G, Vertex v, Vertex w);

void GRAPHremoveArc(Graph G, Vertex v, Vertex w);

void GRAPHshow(Graph G);

#endif