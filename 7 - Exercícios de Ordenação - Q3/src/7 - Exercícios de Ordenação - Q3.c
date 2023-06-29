/*
 ============================================================================
 Name        : 7.c
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
	for(int i = 0; i < tam; i++)
	{
		printf("%d ", v[i]);
	}
	printf("\n");
}

void particao(int *v, int inicio, int fim)
{
	int meio, i, j, k, aux[fim + 1];

	if (inicio < fim)
	{
		meio = (inicio + fim) / 2;

		particao(v, inicio, meio);
		particao(v, meio + 1, fim);

		i = inicio;
		j = meio + 1;
		k = inicio;

		while (i <= meio && j <= fim)
		{
			if ( v[i] < v[j] )
			{
				aux[k] = v[i];
				i++;
			}
			else
			{
				aux[k] = v[j];
				j++;
			}
			k++;
		}
		while (i <= meio)
		{
			aux[k] = v[i];
			i++;
			k++;
		}
		while (j <= fim)
		{
			aux[k] = v[j];
			j++;
			k++;
		}

		for (i = inicio; i <= fim; i++)
		{
			v[i] = aux[i];
		}
	}
}

void mergeSort(int *v, int tam)
{
	particao(v, 0, tam - 1);
}

int main(void)
{
	int vet[] = {7,42,76,8,-1,995,72,3,44,0,1,15,28,77,100,98,105,44,36};
	int tam = sizeof(vet) / sizeof(int);

	printf("\nVetor nao ordenado: \n");
	imprime(vet,tam);

	mergeSort(vet, tam);

	printf("\nVetor ordenado pelo Merge Sort: \n");
	imprime(vet,tam);

	return EXIT_SUCCESS;
}
