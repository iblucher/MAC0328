/*******************************************
 * REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS *
 *******************************************/

#include <stdio.h>
#include <stdlib.h>

/* Vértices de grafos são representados por objetos do tipo Vertex. */
#define Vertex int

/* A estrutura graph representa um grafo. O campo adj é um ponteiro para a
 * matriz de adjacências do grafo. O campo V contém o número de vértices e o
 * campo A contém o número de arcos do grafo. Um Graph é um ponteiro para um
 * graph, ou seja, um Graph contém o endereço de um graph.
 */
struct graph {
    int V;
    int A;
    int **adj;
};
typedef struct graph *Graph;

/* A função MATRIXinit aloca uma matriz com l linhas e c colunas e cada
 * elemento recebe o valor val.
 */
static int **MATRIXinit(int l, int c, int val) {
    int **M = malloc(l*sizeof(int*));
    int i, j;
    for(i = 0; i < l; i++) {
        M[i] = malloc(c*sizeof(int));
        for(j = 0; j < c; j++) {
            M[i][j] = val;
        }
    }
    return M;
}

/* A função GRAPHinit() constrói um grafo com vértices 0..V -1 e nenhum arco. */
Graph GRAPHinit(int V) {
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = MATRIXinit(V, V, 0);
    return G;
}

/* A função GRAPHinsertArc() insere um arco v-w no grafo G. */
void GRAPHinsertArc(Graph G, Vertex v, Vertex w) {
    if(v != w && G->adj[v][w] == 0) {
        G->adj[v][w] = 1;
        G->A++;
    }
}

/* A função GRAPHremoveArc() remove um arco v-w do grafo G. */
void GRAPHremoveArc(Graph G, Vertex v, Vertex w) {
    if(G->adj[v][w] == 1) {
        G->adj[v][w] = 0;
        G->A--;
    }
}

/* A função GRAPHshow() imprime, para cada vértice v do grafo G, em uma linha,
 * todos os vértices adjacentes a v.
 */
void GRAPHshow(Graph G) {
    Vertex v, w;
    for(v = 0; v < G->V; v++) {
        printf("%d: ", v);
        for(w = 0; w < G->V; w++) {
            if(G->adj[v][w] == 1)
                printf("%d ", w);
        }
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
