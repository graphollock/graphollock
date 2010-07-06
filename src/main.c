#include <stdlib.h>
#include <stdio.h>
#include "adjacent_matrix.h"
#include "drawing_core.h"

/*ordem dos parametros:
	1 - arquivo que contem a matriz de adjacencia
	2 - nome do arquivo que ira conter o arquivo graphviz
*/

int main (int argc, char **argv){


	int t = order_of_matrix(argv);



	unsigned int **m = allocate_matrix(t, t);

	if (!m)
		return EXIT_FAILURE;

	printf("%i\n", t);

	complete_matrix(argv, m, t, t);

	Vertice *v = CriaVetor(m, t);

	InitialLayout(v, t);

	ApplyForces(v, t, m);

	GerarArquivo(v, argv[2], t, m);
	print_matrix(m, t, t);

	return EXIT_SUCCESS;
}
