#ifndef LISTS_H_
#define LISTS_H_

Graph GRAPHinit(int V);

int GRAPHvertex(Graph G);

int GRAPHedges(Graph G);

int GRAPHindegree(Graph G, Vertex v);

int GRAPHoutdegree(Graph G, Vertex v);

void GRAPHinsertArc(Graph G, Vertex v, Vertex w);

void GRAPHremoveArc(Graph G, Vertex v, Vertex w);

void GRAPHshow(Graph G);

#endif