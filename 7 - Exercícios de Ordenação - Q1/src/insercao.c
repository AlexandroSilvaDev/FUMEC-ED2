/*
 * insercao.c
 *
 *  Created on: 23 de mar. de 2023
 *      Author: 13A226889818
 */

#include "insercao.h"

void insercao(ITEM *v, int tam)
{
	for (int i = 0; i < tam - 1; i++)
	{
		ordena(v, i+1);
	}
}

void ordena(ITEM *v, int index)
{
	CHAVE temp;

	for (int i = index; i >= 0; i--)
	{
		if (v[i-1].chave > v[i].chave)
		{
			temp = v[i-1].chave;
			v[i-1].chave = v[i].chave;
			v[i].chave = temp;
		}
		else
		{
			return;
		}
	}
}

void imprime(ITEM *v, int tam)
{
	for (int i = 0; i < tam-1; i++)
	{
		printf("%ld ", v[i].chave);
	}
	printf("\n");
}
