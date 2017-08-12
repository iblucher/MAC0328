#include <stdio.h>
#include <stdlib.h>
#include "graph_matrix.h"
#include "graph_lists.h"

/* A função GRAPHbuildComplete() constrói um grafo completo (cada par de 
 * vértices distintos é conectado por um par único de arcos, um em cada 
 * direção). Tempo: θ(V^2) para a matriz e em O(V^3) para listas.
 */
Graph GRAPHbuildComplete(int V) {
	Vertex v, w;
	Graph G = GRAPHinit(V);
	for(v = 0; v < G->V; v++)
		for(w = 0; w < G->V; w++)
			GRAPHinsertArc(G, v, w);
	return G;
}

/* A função GRAPHbuildPath() constrói um caminho (passeio: sequência de 
 * vértices v1, v2, ..., vk tal que vi - vi+1 é um arco do grafo para 
 * i = 1..k-1. Um caminho é um passeio que não repete vértices). 
 * Tempo: θ(V) para a matriz e em θ(V^2) para listas.
 */
Graph GRAPHbuildPath(int V) {
	Vertex v;
	Graph G = GRAPHinit(V);
	for(v = 0; v < V - 1; v++)
		GRAPHinsertArc(G, v, v + 1);
	return G;
}


Graph GRAPHbuildChessKing(int n) {
	int l, c, i, j;
	Vertex v;
	Graph G = GRAPHinit(n*n);
	for(v = 0; v < G->V; v++) {
		l = v/n;
		c = v % n;
		for(i = l - 1; i <= l + 1; i++)
			for(j = c - 1; j <= c + 1; j++)
				if(i >= 0 && i < n && j >= 0 && j< n)
					GRAPHinsertArc(G, v, i*n + j);
	}
	return G;
}

Vertex randV(Graph G) {
	double r;
	r = rand()/(RAND_MAX + 1.0);
	return (r*G->V);
}

Graph GRAPHrand1(int V, int A) {
	Vertex v, w;
	Graph G = GRAPHinit(V);
	while(G->A != A) {
		v = randV(G);
		w = randV(G);
		GRAPHinsertArc(G, v, w);
	}
	return G;
}

Graph GRAPHrand2(int V, int A) {
	double p = (double)A/(V*(V - 1));
	Vertex v, w;
	Graph G = GRAPHinit(V);
	for(v = 0; v < V; v++)
		for(w = 0; w < V; w++)
			if(rand() < p * (RAND_MAX + 1.0))
				GRAPHinsertArc(G, v, w);
	return G;
}

int main() {
	Graph G = GRAPHbuildComplete(6);
	GRAPHshow(G);
}