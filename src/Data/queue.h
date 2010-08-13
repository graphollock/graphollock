#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int v;
	struct node *next;
}node;

typedef struct queue{
	node *head;
	node *last;
	int size;
}queue;

queue *CreateQueue(int);
void Queue(queue*, int);
int Dequeue(queue*);
void DestroyQueue(queue *);
