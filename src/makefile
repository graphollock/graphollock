all: arquivo.o adjacent_matrix.o drawing_core.o main.o Data/queue.o Datagstructs.o
	gcc -o graphollock arquivo.o main.o adjacent_matrix.o drawing_core.o Data/queue.o Data/gstructs.o -lm -ggdb

arquivo.o: arquivo.h
	gcc -c arquivo.c 

adjacent_matrix.o: adjacent_matrix.h
	gcc -c adjacent_matrix.c

drawing_core.o: drawing_core.h arquivo.h adjacent_matrix.h
	gcc -c drawing_core.c

main.o: arquivo.h drawing_core.h adjacent_matrix.h
	gcc -c main.c

queue.o: Data/queue.h
	gcc -c Data/queue.c

gstructs.o: Data/gstructs.h
	gcc -c Data/gstructs.c

clean:
	rm graphollock main.o drawing_core.o adjacent_matrix.o arquivo.o Data/queue.o

DQ:
	gcc -o Data/queue Data/queue.c -DDEBUGQUEUE

