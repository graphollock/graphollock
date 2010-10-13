/*Modulo responsavel por gerar o arquivo no formato do graphviz
Contem a estrutura de representacao de um vertice no plano*/

#include <stdlib.h>
#include <stdio.h>

#define TAM 20

typedef unsigned int UINT;

typedef struct Vertice{
	float x;
	float y;

	UINT tam;
	UINT id;

	UINT xdisp;
	UINT ydisp;

	UINT depth;

	UINT visited;
}Vertice;

void GerarArquivo(Vertice*, char*, int, UINT**);

void InsereTabs(FILE *f);

void DeclaraVertices(FILE *f, Vertice *v, int vcount);

void InsereComentarioInicial(FILE *f);

void DeclaraArestas(FILE*,UINT**, UINT);

Vertice *CriaVetor(UINT **, UINT);
