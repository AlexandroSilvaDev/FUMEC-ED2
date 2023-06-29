/*
 * funcoes.c
 *
 *  Created on: 28 de mar. de 2023
 *      Author: xande
 */

#include "biblioteca.h"

void quicksort(int *v, int tam)
{
	if (tam > 20)
	{
		printf("\nOrdenação utilizando Quick sort!\n");
		ordenaQuick(v, 0, tam-1);
	}
	else
	{
		printf("\nOrdenação utilizando Insertion sort!\n");
		insercao(v, tam);
	}

}

void ordenaQuick(int *v, int esq, int dir)
{
	int i, j;

	particaoQuick(v, esq, dir, &i, &j);

	if(esq < j)
	{
		ordenaQuick(v, esq, j);
	}
	if(i < dir)
	{
		ordenaQuick(v, i, dir);
	}
}

void particaoQuick(int *v, int esq, int dir, int *i, int *j)
{

	int pivo, temp;
	*i = esq;
	*j = dir;
	pivo = v[(*i + *j) / 2] ;

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

void insercao(int *v, int tam)
{
	for (int i = 0; i < tam - 1; i++)
	{
		ordenaInsercao(v, i+1);
	}
}

void ordenaInsercao(int *v, int index)
{
	int temp;

	for (int i = index; i > 0; i--)
	{
		if (v[i-1] > v[i])
		{
			temp = v[i-1];
			v[i-1] = v[i];
			v[i] = temp;
		}
		else
		{
			return;
		}
	}
}

void imprime(int *v, int tam)
{
	for(int i = 0; i < tam; i++)
	{
		printf("%d ", v[i]);
	}
	printf("\n");
}
