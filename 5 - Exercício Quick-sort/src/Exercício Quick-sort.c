/*
 ============================================================================
 Name        : Exerc�cio.c
 Author      : Alexandro Silva
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
/*
void imprime(int *v, int tam)
{
	for( int i = 0 ; i < tam ; i++ )
	{
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, j, pivo, temp;

	int vet [] = {0,0,1,0,1,1,1,0,0,1,0,0,0,1,1,0,1,0,1,1,0,0,1,1,1,0};

	int tam = sizeof(vet) / sizeof(int);

	imprime(vet, tam);

	i = 0;
	j = tam - 1;
	pivo = 1;
	do
	{
		while( pivo > vet[i] )
		{
			i++;
		}
		while ( pivo <= vet[j] )
		{
			j--;
		}
		if ( i <= j )
		{
			temp = vet[i];
			vet[i] = vet[j];
			vet[j] = temp;
			i++;
			j--;
		}
	} while ( i <= j );

	imprime(vet, tam);

	printf("i = %d, j = %d\n", i, j);

	j = tam - 1;
	pivo = 2;

	do
	{
		while( pivo > vet[i] )
		{
			i++;
		}
		while ( pivo <= vet[j] )
		{
			j--;
		}
		if ( i <= j )
		{
			temp = vet[i];
			vet[i] = vet[j];
			vet[j] = temp;
			i++;
			j--;
		}
	} while ( i <= j );

	imprime(vet, tam);

	printf("i = %d, j = %d\n", i, j);

	return 0;
}
*/
