/*
 * funcoes.c
 *
 *  Created on: 15 de abr. de 2023
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
	// d = (DICIONARIO *) malloc( sizeof(DICIONARIO) * M );

	for (int i = 0; i < M; i++)
	{
		strncpy(d[i].nome, VAZIO, N);
		d[i].preco = 0;
	}
}

int inserir(DICIONARIO d, ITEM x)
{
	int i, inicial;

	inicial = converter(x.nome);
	i = 0;

	while( ( strncmp(d[(inicial + i) % M].nome, VAZIO, N)) &&
		   ( strncmp(d[(inicial + i) % M].nome, RETIRADO, N)) &&
		   ( i < M ) )
	{
		i++;
	}
	if (i < M)
	{
		d[(inicial + i) % M] = x;
		return ((inicial + i) % M);
	}
	else
	{
		return -1;
	}
}

int remover(DICIONARIO d, CHAVE chave)
{
	int i;

	i = pesquisa(d, chave);

	if (i != -1)
	{
		memcpy(d[i].nome, RETIRADO, sizeof(CHAVE));
		return d[i].preco;
	}
	else
	{
		return -1;
	}
}

int pesquisa(DICIONARIO d, CHAVE chave)
{
	int i, inicial;

	inicial = converter(chave);
	i = 0;

	while( (strncmp(d[(inicial + i) % M].nome, VAZIO, N)) &&
		   (strncmp(d[(inicial + i) % M].nome, chave, N)) &&
		   (i < M) )
	{
		i++;
	}
	if (! strncmp(d[(inicial + i) % M].nome, chave, N))
	{
		return ((inicial + i) % M);
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
		d[i].preco = preco;
		return 0;
	}
	else
	{
		return -1;
	}
}

