/*******************************************
 * REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA *
 *******************************************/

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

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

/* A função NEWnode() recebe um vértice w e o endereço first de um nó e devolve
 * o endereço p de um novo nó tal que p->w == w e p-> next == first.
 */
link NEWnode(Vertex w, link first) {
    link p;
    p = malloc(sizeof(struct node));
    p->w = w;
    p->next = first;
    return p;
}

/* A função GRAPHinit() constrói um grafo com vértices 0..V -1 e nenhum arco
 * em θ(V).
 */
Graph GRAPHinit(int V) {
    Vertex v;
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = malloc(V*sizeof(link));
    for(v = 0; v < V; v++)
        G->adj[v] = NULL;
    return G;
}

int GRAPHvertex(Graph G) {
    return G->V;
}

int GRAPHedges(Graph G) {
    return G->A;
}

/* A função GRAPHinsertArc() insere um arco v-w no grafo G em O(V). */
void GRAPHinsertArc(Graph G, Vertex v, Vertex w) {
    link p;
    if(v != w) {
        for(p = G->adj[v]; p != NULL; p = p->next)
            if(p->w == w) return;
        G->adj[v] = NEWnode(w, G->adj[v]);
        G->A++;
    }
}

/* A função GRAPHremoveArc() remove um arco v-w do grafo G em O(V). */
void GRAPHremoveArc(Graph G, Vertex v, Vertex w) {
    link ant, p;
    for(ant = NULL, p = G->adj[v]; p != NULL && p->w != w; ant = p, p = p->next);
    if(p != NULL) {
        if(ant == NULL)
            G->adj[v] = p->next;
        else
            ant->next = p->next;
    G->A--;
    free(p);
    }
}

/* A função GRAPHshow() imprime, para cada vértice v do grafo G, em uma linha,
 * todos os vértices adjacentes a v em em θ(V+A).
 */
void GRAPHshow(Graph G) {
    Vertex v;
    link p;
    for(v = 0; v < G->V; v++) {
        printf("%d: ", v);
        for(p = G->adj[v]; p != NULL; p = p->next)
            printf("%d ", p->w);
        printf("\n");
    }   
}

int main() {
    Graph G = GRAPHinit(7);
    GRAPHinsertArc(G, 0, 1);
    GRAPHinsertArc(G, 1, 3);
    GRAPHinsertArc(G, 2, 1);
    GRAPHinsertArc(G, 2, 3);
    GRAPHinsertArc(G, 2, 5);
    GRAPHinsertArc(G, 4, 0);
    GRAPHinsertArc(G, 4, 3);
    GRAPHinsertArc(G, 4, 5);
    GRAPHinsertArc(G, 5 ,6);
    GRAPHinsertArc(G, 6, 2);
    printf("Todos os arcos foram inseridos.\n");

    GRAPHremoveArc(G, 4, 3);
    printf("Removendo arco 4-3.\n");

    GRAPHshow(G);
}