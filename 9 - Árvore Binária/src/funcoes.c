/*
 * funcoes.c
 *
 *  Created on: 25 de abr. de 2023
 *      Author: 13A226889818
 */

#include "biblioteca.h"

void cria(ARVORE **a)
{
	*a = NULL;
}

int pesquisa(ARVORE **a, ITEM *i)
{
	if (*a == NULL)
	{
		return -1;
	}

	if (i->chave < (*a)->item.chave)
	{
		return pesquisa(&(*a)->esq, i);
	}
	if (i->chave < (*a)->item.chave)
	{
		return pesquisa(&(*a)->dir, i);
	}

	*i = (*a)->item;

	return 0;
}

int insere(ARVORE **a, ITEM i)
{
	if (*a == NULL)
	{
		*a = (NO*) malloc(sizeof(NO));
		(*a)->item = i;
		(*a)->dir = NULL;
		(*a)->esq = NULL;
		return 0;
	}
	if (i.chave < (*a)->item.chave)
	{
		return insere(&(*a)->esq, i);
	}
	if (i.chave > (*a)->item.chave)
	{
		return insere(&(*a)->dir, i);
	}
	return -1;
}

void antecessor(NO *q, NO **r)
{
	if ((*r)->dir != NULL)
	{
		antecessor(q, &(*r)->dir);
		return;
	}
}

int retira(ARVORE **a, ITEM i)
{
	ARVORE *aux;

	if(*a == NULL)
	{
		return -1;
	}

	if (i.chave < (*a)->item.chave)
	{
		return retira(&(*a)->esq, i);
	}
	if (i.chave > (*a)->item.chave)
	{
		return retira(&(*a)->dir, i);
	}

	if ((*a)->dir == NULL)
	{
		aux = *a;
		*a = (*a)->esq;
		free(aux);
		return 0;
	}
	if ((*a)->esq == NULL)
	{
		aux = *a;
		*a = (*a)->dir;
		free(aux);
		return 0;
	}

	antecessor(*a, &(*a)->esq);
	return 0;
}

void percorreIn(ARVORE *a)
{
	if (a != NULL)
	{
		percorreIn(a->esq);
		printf("%d\n", a->item.chave);
		percorreIn(a->dir);
	}
}

void percorrePre(ARVORE *a)
{
	if (a != NULL)
	{
		printf("%d\n", a->item.chave);
		percorrePre(a->esq);
		percorrePre(a->dir);
	}
}

void percorrePos(ARVORE *a)
{
	if(a != NULL)
	{
		percorrePos(a->esq);
		percorrePos(a->dir);
		printf("%d\n", a->item.chave);
	}
}
