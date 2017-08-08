/*******************************************
 * REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA *
 *******************************************/

#include <stdio.h>
#include <stdlib.h>

/* Vértices de grafos são representados por objetos do tipo Vertex. */
#define Vertex int

struct node {
    Vertex w;
    struct node * next;
};
typedef struct node * link;

/* A estrutura graph representa um grafo. O campo adj é um ponteiro para o vetor
 * de listas de adjacência, o campo V contém o número de vértices e o campo A
 * contém o número de arcos do grafo. */
struct graph {
    int V;
    int A;
    link *adj;
};
typedef struct graph * Graph;

link NEWnode(Vertex w, link first) {
    link p;
    p = malloc(sizeof(struct node));
    p->w = w;
    p->next = first;
    first = p;
    return first;
}

Graph GRAPHinit(int V) {
    
}