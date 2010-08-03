#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0

typedef int bool;

typedef struct Point{
	int x;
	int y;
}Point;

bool Left(Point, Point, Point);

int main(int argc, char **argv){
	Point a, b, c;
	bool retorno;

	printf("Entre com dois pontos do segmento:\n");
	scanf("%i %i", &(a.x), &(a.y));	
	scanf("%i %i", &(b.x), &(b.y));		
	scanf("%i %i", &(c.x), &(c.y));	

/*	printf("Pontos:\n A=(%i,%i), B=(%i,%i), C=(%i, %i)\n", a.x, a.y, b.x, b.y, c.x, c.y);*/

	retorno = Left(a, b, c);

	if ( retorno == true)
		printf("Ta na esquerda\n");
	else
		printf("Ta na direita\n");
}

bool Left(Point a, Point b, Point c){
	/*caso em que o segmento nao e horizontal*/
	if (a.y != b.y)
		return (c.x <= a.x && c.x <= b.x) ? true : false;
	else
		return (c.y <= a.y && c.y <= b.y) ? true : false;	
}
