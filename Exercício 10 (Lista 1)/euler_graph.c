#include <stdio.h>
#include <stdlib.h>

#define Vertex int
#define TAM 1000

struct graph {
    int V;
    int A;
    int **adj;
};
typedef struct graph * Graph;

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

Graph GRAPHinit(int V) {
    Graph G = malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = MATRIXinit(V, V, 0);
    return G;
}

void GRAPHinsertArc(Graph G, Vertex v, Vertex w) {
    if(v != w && G->adj[v][w] == 0) {
        G->adj[v][w] = 1;
        G->A++;
    }
}

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

int GRAPHcheckComplete(Graph G) {
    if(G->A == G->V*(G->V - 1))
        return 1;
    return 0;
}

int main(int argc, char **argv) {
    FILE *file = fopen("euler.txt", "r");
    int i, stop = 0;
    int X = atoi(argv[1]);
    int e[TAM];
    Graph G = GRAPHinit(X);

    for(i = 0; i < TAM; i++)
        fscanf(file, "%1d", &e[i]);

    for(i = 0; i < TAM - 1; i++) {
        stop++;
        if(e[i] < X && e[i+1] < X) {
            GRAPHinsertArc(G, e[i], e[i+1]);
            if(GRAPHcheckComplete(G) == 1)
                break;
        }
    }

    if(X == 0)
        printf("Grafo nulo\n");
    else if(X == 1)
        printf("Grafo com 1 vértice é completo\n");
    else {
        printf("Completo em %d dígitos do número de Euler\n", i+1);
        GRAPHshow(G);
    }
}
