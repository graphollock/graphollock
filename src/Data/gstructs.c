#include <stdlib.h>
#include <stdio.h>
#include "gstructs.h"

/*Cria um novo jornal*/
Newspapper *CreateNP(Edge e, EventType et){
	EventList *el = (EventList*)malloc(sizeof(EventList));

	el->head = (Node*)malloc(sizeof(Node));

	el->head->next = el->head->prev = NULL;

	el->head->e = e;
	el->head->event = et;

	el->tail = el->head;

	return (Newspapper*)el;
}

/*Insere no jornal*/
void InsertEvent(Newspapper *np, Edge e, EventType et){
	Node *n = (Node*)malloc(sizeof(Node));

	n->e = e;
	n->event = et;

	n->prev = np->tail;
	n->next = NULL;

	np->tail->next = n;

	np->tail = n;
}

Node *GetNodeAt(Newspapper *np, int index){
	Node *n;
	int i = 0;

	return np->head + index;	
}
