/*
 ============================================================================
 Name        : 10.c
 Author      : Alexandro Silva
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "biblioteca.h"

int main(void)
{
	int num_vertices = 6;
	struct Graph* graph = createGraph(num_vertices);

	addEdge(graph, 5, 2);
	addEdge(graph, 5, 0);
	addEdge(graph, 4, 0);
	addEdge(graph, 4, 1);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 1);

	topologicalSort(graph);

	printf("\nBusca em largura: ");
	BFS(graph, 0);

	return EXIT_SUCCESS;
}
