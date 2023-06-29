/*
 * funcoes.c
 *
 *  Created on: 17 de abr. de 2023
 *      Author: xande
 */

#include "biblioteca.h"

int converter(CHAVE chave)
{
	int i, soma;

	for (i = 0; i < 20; i++)
	{
		soma += chave[i];
	}
	return (soma % M);
}

void criar(DICIONARIO d)
{
	CELULA *cabecalho = (CELULA*) malloc(sizeof(CELULA));

	for (int i = 0; i < M; i++)
	{
		d[i].inicio = cabecalho;
		d[i].fim = cabecalho;

		strncpy(d[i].inicio->item.nome, VAZIO, N);
		strncpy(d[i].fim->item.nome, VAZIO, N);
		d[i].inicio->item.preco = 0;
		d[i].fim->item.preco = 0;
	}
}

int inserir(DICIONARIO d, ITEM x)
{
	int i = converter(x.nome);

	CELULA *nova = (CELULA*) malloc(sizeof(CELULA));

	strncpy(nova->item.nome, x.nome, N);
	nova->item.preco = RANDOM;

	d[i].fim->proximo = nova;
	d[i].fim = nova;
	nova->proximo = NULL;

	return 0;
}

int remover(DICIONARIO d, CHAVE chave)
{
	CELULA *aux;
	int i = pesquisa(d, chave);

	aux = d[i].inicio;

	while (strncmp(aux->item.nome, chave, N) && aux->proximo)
	{
		if (strncmp(aux->item.nome, chave, N))
		{
			if (i != -1)
			{
				memcpy(d[i].inicio->item.nome, RETIRADO, sizeof(CHAVE));
				return d[i].inicio->item.preco;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			aux = aux->proximo;
		}
	}
	if (! d[i].inicio)
	{
		return -1;
	}
	else
	{
		return d[i].inicio->item.preco;
	}
}

int pesquisa(DICIONARIO d, CHAVE chave)
{
	CELULA *aux;
	int i = converter(chave);

	aux = d[i].inicio;

	while( aux && strncmp(aux->item.nome, chave, N))
	{
		aux = aux->proximo;
	}
	if (d)
	{
		return (i % M);
	}
	else
	{
		return -1;
	}
}

int alterarPreco(DICIONARIO d, CHAVE chave, double preco)
{
	int i;

	i = pesquisa(d, chave);

	if (i != -1)
	{
		d[i].inicio->item.preco = RANDOM;
		return 0;
	}
	else
	{
		return -1;
	}
}
