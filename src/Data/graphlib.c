#include <stdlib.h>
#include <stdio.h>
#include "graphlib.h"

Graph *ReadFile(char *path, ReadFlag rtype, int n){
	Graph *g = (Graph*)malloc(sizeof(Graph));
	
	//switch (rtype){
		/*Numero de vertices do grafo*/
	    int size = order_of_matrix(path);
		/*Aloca matriz de adjacencia*/
		g->am = (AdjMatrix*)malloc(sizeof(AdjMatrix));
		/*Ajeita os valores iniciais de i e j*/
		g->am->last_i = 0; /*Linha*/
		g->am->last_j = 1; /*Coluna*/
		
		/*le a matriz do arquivo pra dentro da matriz de adjacencia*/
		complete_matrix(path, g->am->m, size, size);
		

	//}
	return g;
}

Edge *FirstEdge(Graph *g){
	int i, j;

	for (i = g->last_i; i < g->sizev - 1; i++){
		for (j = g->last_j; i < g<sizev - 1; j++){
			if (g->ma->m[i][j] == 1){
				Edge *e = (Edge*)malloc(sizeof(Edge));
				e->endpoint1 = i;
				e->endpoint2 = j;
				e->id = 1;

				return e;
			}
		}
	}

	return NULL;
}

void FindAllEdges(Graph *g){
	
}
