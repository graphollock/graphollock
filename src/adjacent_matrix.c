#include "adjacent_matrix.h"

unsigned int **allocate_matrix(int l, int c)
{
	int i;

	unsigned int **m = (unsigned int **)malloc(l * sizeof(unsigned int *));
	if (!**m) exit(EXIT_FAILURE);

	for (i = 0; i < l; i++)
	{
		*(m + i) = (unsigned int *)malloc(c * sizeof(unsigned int));
		if (!*(m + i)) exit(EXIT_FAILURE);
	}

	return m;
}

void destroy_matrix(unsigned int **m, int l, int c)
{
	int i;
	for (i = 0; i < l; i++)
		free(*(m + i));
	free(m);
}

void complete_matrix(char *path, unsigned int **m, int l, int c)
{
	int i = 0;
	size_t len = 0;
	char *line = NULL;
	/* tamanho da linha do arquivo */
	int size = l;

	line = (char*)malloc((size + 1) * sizeof(char));

	FILE *in = fopen(path, "r");
	if (!in) exit(EXIT_FAILURE);

	while (getline(&line, &len, in) != -1 && !feof(in) && !ferror(in)){
		handle_line(m, line, l, i++);
	}


}


/* o xunxo tah aqui nesse aux2, depois piro em fazer alguma coisa mais
 * decente, por enquanto esta funcionando */
void handle_line(unsigned int **m, char *line, int l, int actual_line)
{
	int i;
   	char aux;
	short aux2;

	for (i = 0; i < l; i++)
	{	
		aux = *(line + i);
		aux2 = atoi(&aux);
		*(*(m + actual_line) + i) = aux2;
	}
}


int order_of_matrix(char *path)
{	
	char *line = NULL;
	size_t len = 0;

	FILE *in = fopen(path, "r");
	if (!in)exit(EXIT_FAILURE);

	getline(&line, &len, in);

	fclose(in);
	if (line) free(line);

	return (strlen(line) - 1);
}

void print_matrix(unsigned int **m, int l, int c)
{
	int i, j;
	for (i = 0; i < l; i++)
	{
		for(j = 0; j < c; j++){
			fprintf(stdout, "%d ", *(*(m + i) + j));
		}

		fprintf(stdout, "\n");
	}
}
