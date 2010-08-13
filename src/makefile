all: arquivo.o adjacent_matrix.o drawing_core.o main.o Data/queue.o
	gcc -o graphollock arquivo.c main.c adjacent_matrix.c drawing_core.c -lm

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

clean:
	rm graphollock main.o drawing_core.o adjacent_matrix.o arquivo.o

DQ:
	gcc -o Data/queue Data/queue.c -DDEBUGQUEUE

