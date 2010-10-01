#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
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
		
		/*Zera */
		g->last_epos = 0;		

		/*Aloca E*/
		g->e = (Edge*)malloc(n * n * sizeof(Edge));

		/*le a matriz do arquivo pra dentro da matriz de adjacencia*/
		complete_matrix(path, g->am->m, size, size);
	
		/*Preenche todas as arestas*/
		FindAllEdges(g);

	//}
	return g;
}

Edge *FirstEdge(Graph *g){
	int i, j;

	for (i = g->am->last_i; i < g->sizev - 1; i++){
		for (j = g->am->last_j; i < g->sizev - 1; j++){
			if (g->am->m[i][j] == 1){
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
	/*Procura a primeira aresta*/
	Edge *e = FirstEdge(g);
	
	/*Insere a primeira aresta na lista*/
	g->e[g->last_epos] = *e;

	g->last_epos++;

	/*Enquanto tiver proximas arestas*/
	while ((e = NextEdge(g))){
		g->e[g->last_epos] = *e;
		g->last_epos++;
	}
}

Edge *NextEdge(Graph *g){
	int i,j;
	UINT eid = 2;

	for (i = 0; i < g->sizev - 1; i++){
		for (j = g->am->last_j; j < g->sizev - 1; j++){
			if (g->am->m[i][j] == 1){
				Edge *e = (Edge*)malloc(sizeof(Edge));
				e->id = eid;
				e->endpoint1 = i;
				e->endpoint2 = j;
			}
		}

		g->am->last_j = i + 1;
	}
}


/*TODO: Transferir para Lista de adjacencia*/
/*void InsertEdge(Graph *g, Edge *e){
	AdjNode *n = (AdjNode*)malloc(sizeof(AdjNode));

	Alocacao falhou
	if (!n){
		fprintf(stdout, "Memory allocate error, aborting...\n");
		Erro de memória
		exit(ENOMEM);
	}
	
	atribui o ID da aresta do valor do no
	n->id = e->id;

	O anterior do novo no sera o ultimo no da lista
	n->prev = g->AdjList->end;

	Aterra ponteiro de proximo do novo no
	n->next = NULL;
	
	Referencia novo no no ultimo existente na lista
	g->AdjList->end->next = e;

	Aponta o final da lista para o novo no
	g->AdjList->end = n;
}*/
