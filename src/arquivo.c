#include "arquivo.h"

/*contador de tabs*/
int tabcount;


/*Gera o arquivo formato graphviz conforme as coordenadas geradas pelo algoritmo*/
void GerarArquivo(Vertice *v, char *n, int vcount, UINT **m){
	/*Inicializa o contador de tabs*/
	tabcount = 0;
	FILE *f = fopen(n, "w+");

	InsereComentarioInicial(f);

	/*Declaracao do grafo*/
	fprintf(f, "Graph G{\n");
	tabcount++;

	DeclaraVertices(f, v, vcount);

	DeclaraArestas(f, m, vcount);

	tabcount--;
	InsereTabs(f);
	fprintf(f, "};\n");
}

void InsereTabs(FILE *f){
	int i;

	for (i = 0; i < tabcount; i++)
		fprintf(f, "\t");
}

void DeclaraVertices(FILE *f, Vertice *v, int vcount){
	int i;

	for (i = 0; i < vcount; i++){
		InsereTabs(f);
		fprintf(f, "%i [pos=\"%i,%i\", width=\"0.30\", height=\"0.30\"]\n", v[i].id, v[i].x, v[i].y);
	}
}

void InsereComentarioInicial(FILE *f){
	fprintf(f, "/*Arquivo gerado usando o graphollock*/\n");
	fprintf(f,"\n");
}

void DeclaraArestas (FILE *f, UINT **m, UINT l){
	int i, j;

	for (i = 0; i < l; i++)
		for (j = 0; j < l; j++)
			if (m[i][j] == 1){
				InsereTabs(f);
				fprintf(f, "%i -- %i\n", i + 1, j + 1);
				m[j][i] = 0;
			}
}

Vertice *CriaVetor(UINT **m, UINT l){
	Vertice *v = (Vertice*) malloc (l * sizeof(Vertice));
	int i;

	for (i = 0; i < l; i++){
		v[i].id = i + 1;
	}

	return v;	
}
