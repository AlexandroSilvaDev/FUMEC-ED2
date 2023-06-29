/*
 ============================================================================
 Name        : 6.c
 Author      : Alexandro Silva
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void imprime(int *v, int tam)
{
	printf("\n");

	for (int i = 0; i < tam; i++)
	{
		printf("%03d ", i);
	}
	printf("\n");

	for (int i = 0; i < tam; i++)
	{
		printf("%03d ", v[i]);
	}
	printf("\n");
}

void heapfy(int *v, int tam, int raiz)
{
	int esq = 2 * raiz + 1;
	int dir = 2 * raiz + 2;
	int max = raiz;

	if (esq < tam && v[max] < v[esq])
	{
		max = esq;
	}
	if (dir < tam && v[max] < v[dir])
	{
		max = dir;
	}
	if (max != raiz)
	{
		int temp = v[max];
		v[max] = v[raiz];
		v[raiz] = temp;
		heapfy(v, tam, max);
	}
}

void heapsort(int *v, int tam)
{
	for (int i = tam/2 - 1; i >= 0; i--)
	{
		heapfy(v, tam, i);
	}
	for (int i = tam-1; i > 0; i--)
	{
		int temp = v[0];
		v[0] = v[i];
		v[i] = temp;
		heapfy(v, i, 0);
	}
}

int main(void)
{
	int vet[] = {7,42,76,8,-1,995,72,3,44,0,1,15,28,77,100,98,105,44,36};
	int tam = sizeof(vet) / sizeof(int);

	imprime(vet, tam);

	heapsort(vet, tam);

	imprime(vet, tam);

	return EXIT_SUCCESS;
}
