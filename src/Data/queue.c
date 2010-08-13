#include "queue.h"

queue *CreateQueue(int v){
	queue *q = (queue*)malloc(sizeof(Queue));
	q->head = q->last = (node*)malloc(sizeof(node));

	q->head->v = v;
	q->head->next = NULL;

	q->size = 1;

	return q;
}

void Queue(queue *q, int v){
	printf("Enfilando: %i\n", v);
	node *n = (node*)malloc(sizeof(node));

	n->v = v;
	n->next = NULL;
	q->last->next = n;

	q->last = n;

	q->size++;
}

int Dequeue(queue *q){
	int v = q->head->v;
	node *n = q->head;

	q->head = q->head->next;

	free(n);

	q->size--;

	return v;
}

void DestroyQueue(queue *q){
	free(q->head);
	free(q);
}

#ifdef DEBUGQUEUE
void print(queue *q){
	node *n;
	n = q->head;

	for (n = q->head; n != q->last; n = n->next){
		printf("%i\n", n->v);
	}
	
	printf("last value: %i\n", q->last->v);
}

int main(){
	queue *q = CreateQueue(1);
	int i;
	
	for (i = 2; i <= 10; i++)
		Queue(q, i);

	print(q);

	printf("Dequeing...\n--------------------------------------\n");

	while(q->size != 0){
		int n = Dequeue(q);
		printf("Value: %i\n", n);
	}
}
#endif
