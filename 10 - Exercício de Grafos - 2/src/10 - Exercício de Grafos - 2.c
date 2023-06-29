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
	setbuf(stdout, NULL);

	TipoGrafo Grafo;
	TipoValorVertice V1, V2;
	TipoPeso Peso;

	FGVazio(&Grafo);
	Grafo.NumVertices = 7;
	Grafo.NumArestas = 8;

	V1 = 0;
	V2 = 1;
	Peso = 0;
	InsereAresta(&V1, &V2, &Peso, &Grafo);

	V1 = 0;
	V2 = 2;
	Peso = 0;
	InsereAresta(&V1, &V2, &Peso, &Grafo);

	V1 = 1;
	V2 = 3;
	Peso = 0;
	InsereAresta(&V1, &V2, &Peso, &Grafo);

	V1 = 1;
	V2 = 4;
	Peso = 0;
	InsereAresta(&V1, &V2, &Peso, &Grafo);

	V1 = 2;
	V2 = 3;
	Peso = 0;
	InsereAresta(&V1, &V2, &Peso, &Grafo);

	V1 = 2;
	V2 = 5;
	Peso = 0;
	InsereAresta(&V1, &V2, &Peso, &Grafo);

	V1 = 3;
	V2 = 6;
	Peso = 0;
	InsereAresta(&V1, &V2, &Peso, &Grafo);

	V1 = 4;
	V2 = 6;
	Peso = 0;
	InsereAresta(&V1, &V2, &Peso, &Grafo);

	printf("Busca em Profundidade: ");
	BuscaEmProfundidade(&Grafo);
	printf("\n");

	printf("Busca em Largura: ");
	BuscaEmLargura(&Grafo);
	printf("\n");

	OrdenacaoTopologica(&Grafo);

	if (ExisteCiclo(&Grafo)) {
		printf("O grafo contém ciclos\n");
	} else {
		printf("O grafo não contém ciclos\n");
	}

	return 0;
}
