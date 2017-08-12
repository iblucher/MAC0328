CC=gcc
CFLAGS=-Wall

matrix:
	$(CC) graph_matrix.c graph_matrix.h -o graph_matrix

lists: 
	$(CC) graph_lists.c graph_lists.h -o graph_lists

clean: 
	rm -f graph_matrix graph_lists graph_matrix.o