/*
 * funcoes.c
 *
 *  Created on: 5 de mai. de 2023
 *      Author: xande
 */

#include "biblioteca.h"

void criar(DICIONARIO *d)
{
	*d = NULL;
}

int pesquisar(DICIONARIO *d, ITEM i)
{
	if (*d == NULL)
	{
		return -1;
	}

	if(strncmp(i.nome, (*d)->item.nome, N + 1) == 0)
	{
		i.preco = (*d)->item.preco;
		return 0;
	}
	if (strncmp(i.nome, (*d)->item.nome, N + 1) == -1)
	{
		return pesquisar(&(*d)->esq, i);
	}
	if (strncmp(i.nome, (*d)->item.nome, N + 1) == 1)
	{
		return pesquisar(&(*d)->dir, i);
	}

	return 0;
}

int inserir(DICIONARIO *d, ITEM i)
{
	if (*d == NULL)
	{
		*d = (PONT) malloc(sizeof(NO));
		(*d)->item = i;
		(*d)->dir = NULL;
		(*d)->esq = NULL;
		return 0;
	}

	if(strncmp(i.nome, (*d)->item.nome, N + 1) == 0)
	{
		return -1;
	}
	if (strncmp(i.nome, (*d)->item.nome, N + 1) == -1)
	{
		return inserir(&(*d)->esq, i);
	}
	if (strncmp(i.nome, (*d)->item.nome, N + 1) == 1)
	{
		return inserir(&(*d)->dir, i);
	}

	return -1;
}

void antecessor(PONT q, PONT *r)
{
	if ((*r)->dir != NULL)
	{
		antecessor(q, &(*r)->dir);
		return;
	}
}

int retirar(DICIONARIO *d, ITEM i)
{
	PONT aux;

	if (*d == NULL)
	{
		return -1;
	}

	if(strncmp(i.nome, (*d)->item.nome, N + 1) == 0)
	{
		if ((*d)->dir == NULL)
		{
			aux = *d;
			*d = (*d)->esq;
			free(aux);
			return 0;
		}
		if ((*d)->esq == NULL)
		{
			aux = *d;
			*d = (*d)->dir;
			free(aux);
			return 0;
		}
	}
	if (strncmp(i.nome, (*d)->item.nome, N + 1) == -1)
	{
		return retirar(&(*d)->esq, i);
	}
	if (strncmp(i.nome, (*d)->item.nome, N + 1) == 1)
	{
		return retirar(&(*d)->dir, i);
	}

	antecessor(*d, &(*d)->esq);
	return 0;
}

void percorreIn(DICIONARIO d)
{
	if (d != NULL)
	{
		percorreIn(d->esq);
		printf("%s\n", d->item.nome);
		percorreIn(d->dir);
	}
}

void percorrePre(DICIONARIO d)
{
	if (d != NULL)
	{
		printf("%s\n", d->item.nome);
		percorrePre(d->esq);
		percorrePre(d->dir);
	}
}

void percorrePos(DICIONARIO d)
{
	if(d != NULL)
	{
		percorrePos(d->esq);
		percorrePos(d->dir);
		printf("%s\n", d->item.nome);
	}
}

int altura(DICIONARIO d)
{
	int esq, dir;

	if (d == NULL)
	{
		return -1;
	}
	else
	{
		esq = altura(d->esq);
		dir = altura(d->dir);

		if (esq > dir)
		{
			return esq + 1;
		}
		else
		{
			return dir + 1;
		}
	}
}
