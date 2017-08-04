/*******************************************
 * REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS *
 *******************************************/

#include <stdlib.h>

/* Vértices de grafos são representados por objetos do tipo Vertex */
#define Vertex int;

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
 * elemento recebe o valor val
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
/* A função GRAPHinit() constrói um grafo com vértices 0...V -1 e nenhum arco */
Graph GRAPHinit(int V) {
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = MATRIXinit(V, V, 0);
    return G;
}
