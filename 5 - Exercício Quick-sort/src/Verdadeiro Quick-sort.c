/*
 * Verdadeiro Quick-sort.c
 *
 *  Created on: 14 de mar. de 2023
 *      Author: 13A226889818
 */

#include <stdio.h>
/*
void imprime(int *v, int tam)
{
	for( int i = 0 ; i < tam ; i++ )
	{
		printf("%d ", v[i]);
	}
	printf("\n");
}

void particao( int *vet, int esq, int dir, int *i, int *j )
{
	int pivo, temp;

	*i = esq;
	*j = dir;
	pivo = vet[( *i + *j ) / 2];

	do
	{
		while( pivo > vet[*i] )
		{
			(*i)++;
		}
		while ( pivo <= vet[*j] )
		{
			(*j)--;
		}
		if ( *i <= *j )
		{
			temp = vet[*i];
			vet[*i] = vet[*j];
			vet[*j] = temp;
			(*i)++;
			(*j)--;
		}
	} while ( *i <= *j );
}

void ordena( int *v, int esq, int dir )
{
	int i, j;

	particao(v, esq, dir, &i, &j);

	if ( esq < j )
	{
		ordena(v, esq, j);
	}
	if ( i < dir )
	{
		ordena(v, i, dir);
	}
}

void quicksort( int *v, int tam )
{
	ordena(v, 0, tam-1);
}

int main(void)
{
	int vet[] = {7,42,76,8,-1,995,72,3,44,0,1,15,28,77,100,98,105,44,36};

	int tam = sizeof(vet) / sizeof(int);

	imprime(vet, tam);

	quicksort(vet, tam);

	imprime(vet, tam);

	return 0;
}
*/

void imprime(int *v, int tam)
{
	for(int i = 0; i < tam; i++)
	{
		printf("%d ", v[i]);
	}
	printf("\n");
}

void particao(int *v, int esq, int dir, int *i, int *j)
{

	int pivo, temp;
	*i = esq;
	*j = dir;
	pivo = v[(*i + *j) / 2];

	do {
		while(pivo > v[*i])
		{
			(*i)++;
		}
		while(pivo < v[*j])
		{
			(*j)--;
		}

		if(*i <= *j)
		{
			temp = v[*i];
			v[*i] = v[*j];
			v[*j] = temp;
			(*i)++;
			(*j)--;
		}
	} while(*i <= *j);
}

void ordena(int *v, int esq, int dir)
{
	int i, j;

	particao(v, esq, dir, &i, &j);

	if(esq < j)
	{
		ordena(v, esq, j);
	}
	if(i < dir)
	{
		ordena(v, i, dir);
	}
}

void quicksort(int *v, int tam)
{
	ordena(v, 0, tam-1);
}

int main(void)
{

	int vet[] = {7,42,76,8,-1,995,72,3,44,0,1,15,28,77,100,98,105,44,36};
	int tam = sizeof(vet) / sizeof(int);

	imprime(vet,tam);

	quicksort(vet, tam);

	imprime(vet,tam);

	return 0;
}
