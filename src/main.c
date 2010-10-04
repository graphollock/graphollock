#include <stdlib.h>
#include <stdio.h>
#include "Data/graphlib.h"
/*#include "adjacent_matrix.h"
#include "drawing_core.h"*/


/*ordem dos parametros:
	1 - arquivo que contem a matriz de adjacencia
	2 - nome do arquivo que ira conter o arquivo graphviz
*/

int main (int argc, char **argv){
	printf("lendo o arquivo...\n");
	Graph *g = ReadFile(argv[1], MTR_READ, 0);

	printf("Tamanho de V(G): %d\n", g->sizev);
	printf("Tamanho de E(G): %d\n", g->sizee);

	int i;
	for ( i = 0; i < 3; i++)
		printf("(%d,{%d;%d})\n", g->e[i].id, g->e[i].endpoint1, g->e[i].endpoint2);

	for ( i = 0; i < 3; i++)
		printf("%d\n", g->v[i].id);


	/*int t = order_of_matrix(argv);*/



	/*UINT **m = allocate_matrix(t, t);

	if (!m)
		return EXIT_FAILURE;

	complete_matrix(argv, m, t, t);

	Vertice *v = CriaVetor(m, t);

	InitialLayout(v, t, m);

	ApplyForces(v, t, m);

	GerarArquivo(v, argv[2], t, m);*/


	return EXIT_SUCCESS;
}
