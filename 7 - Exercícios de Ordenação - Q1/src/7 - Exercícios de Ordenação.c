/*
 ============================================================================
 Name        : 7.c
 Author      : Alexandro Silva
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "insercao.h"

int main(void)
{
	ITEM vet[MAXTAM];
	int tam = sizeof(vet) / sizeof(ITEM);

	for (int i = 0; i < tam - 1; i++)
	{
		vet[i].chave = RANDOM;
	}
	printf("Vetor original!\n");
	imprime(vet, tam);

	insercao(vet, tam);

	printf("\nVetor ordenado pelo insertion sort!\n");
	imprime(vet, tam);

	return EXIT_SUCCESS;
}
