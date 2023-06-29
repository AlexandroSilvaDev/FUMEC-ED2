/*
 * funcoes.c
 *
 *  Created on: 16 de mai. de 2023
 *      Author: xande
 */

#include "biblioteca.h"

NO* criar(ITEM item)
{
    NO* no = (NO*)malloc(sizeof(NO));
    no->item = item;
    no->esq = no->dir = NULL;
    no->cor = 0; // O novo nó é sempre vermelho

    return no;
}

int isRed(NO* no)
{
    if (no == NULL)
    {
    	return 0;
    }
    return (no->cor == 0);
}

NO* rotateLeft(NO* no)
{
    NO* rightChild = no->dir;
    no->dir = rightChild->esq;
    rightChild->esq = no;
    rightChild->cor = no->cor;
    no->cor = 0;

    return rightChild;
}

NO* rotateRight(NO* no)
{
	NO* leftChild = no->esq;
    no->esq = leftChild->dir;
    leftChild->dir = no;
    leftChild->cor = no->cor;
    no->cor = 0;

    return leftChild;
}

void flipColors(NO* no)
{
    no->cor = 0;
    no->esq->cor = 1;
    no->dir->cor = 1;
}

NO* inserir(NO* raiz, ITEM item)
{
    if (raiz == NULL)
    {
    	return criar(item);
    }

    if (strcmp(item.nome, raiz->item.nome) < 0)
    {
    	raiz->esq = inserir(raiz->esq, item);
    }
    else if (strcmp(item.nome, raiz->item.nome) > 0)
    {
    	raiz->dir = inserir(raiz->dir, item);
    }
    else // A chave já existe no dicionário, atualiza o valor
    {
    	raiz->item.preco = item.preco;
    }

    if (isRed(raiz->dir) && !isRed(raiz->esq))
    {
    	raiz = rotateLeft(raiz);
    }
    if (isRed(raiz->esq) && isRed(raiz->esq->esq))
    {
    	raiz = rotateRight(raiz);
    }
    if (isRed(raiz->esq) && isRed(raiz->dir))
    {
    	flipColors(raiz);
    }

    return raiz;
}

NO* pesquisa(NO* raiz, CHAVE nome)
{
    if (raiz == NULL || strcmp(nome, raiz->item.nome) == 0)
    {
    	return raiz;
    }

    if (strcmp(nome, raiz->item.nome) < 0)
    {
    	return pesquisa(raiz->esq, nome);
    }
    else
    {
    	return pesquisa(raiz->dir, nome);
    }
}

void percorreIn(NO* raiz)
{
    if (raiz != NULL)
    {
    	percorreIn(raiz->esq);
        printf("%s: %.2f\n", raiz->item.nome, raiz->item.preco);
        percorreIn(raiz->dir);
    }
}

