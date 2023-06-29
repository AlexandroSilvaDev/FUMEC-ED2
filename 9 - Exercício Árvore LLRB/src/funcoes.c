/*
 * funcoes.c
 *
 *  Created on: 11 de mai. de 2023
 *      Author: 13A226889818
 */

#include "biblioteca.h"

// Função auxiliar para criar um novo nó com a chave especificada
NO* criar(int chave)
{
    NO* no = (NO*) malloc(sizeof(NO));
    no->chave = chave;
    no->esq = no->dir = NULL;
    no->color = 0; // O novo nó é sempre vermelho

    return no;
}

// Função auxiliar para realizar a rotação para a esquerda
NO* rotateLeft(NO* no)
{
    NO* rightChild = no->dir;
    no->dir = rightChild->esq;
    rightChild->esq = no;
    rightChild->color = no->color;
    no->color = 0;

    return rightChild;
}

// Função auxiliar para realizar a rotação para a direita
NO* rotateRight(NO* no)
{
    NO* leftChild = no->esq;
    no->esq = leftChild->dir;
    leftChild->dir = no;
    leftChild->color = no->color;
    no->color = 0;

    return leftChild;
}

// Função auxiliar para inverter as cores dos nós
void flipColors(NO* no)
{
    no->color = 0;
    no->esq->color = 1;
    no->dir->color = 1;
}

// Função auxiliar para verificar se o nó é vermelho
int isRed(NO* no)
{
    if (no == NULL)
    {
        return 0;
    }
    return (no->color == 0);
}

// Função para inserir um novo nó com a chave especificada na árvore
NO* inserir(NO* raiz, int chave)
{
    // Caso base: encontrou uma posição de inserção
    if (raiz == NULL)
    {
        return criar(chave);
    }

    // Inserção recursiva
    if (chave < raiz->chave)
    {
    	raiz->esq = inserir(raiz->esq, chave);
    }
    else if (chave > raiz->chave)
    {
    	raiz->dir = inserir(raiz->dir, chave);
    }
    else // A chave já existe na árvore, não faz nada
    {
        return raiz;
    }

    // Realiza as operações de balanceamento
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

// Função para pesquisar um valor na árvore
NO* pesquisa(NO* raiz, int chave)
{
    // Caso base: chegou ao fim da árvore ou encontrou o valor
    if (raiz == NULL || raiz->chave == chave)
    {
        return raiz;
    }

    // Valor é menor que a chave atual, busca na subárvore esquerda
    if (chave < raiz->chave)
    {
        return pesquisa(raiz->esq, chave);
    }

    // Valor é maior que a chave atual, busca na subárvore direita
    return pesquisa(raiz->dir, chave);
}

// Função para realizar o percorrimento inorder da árvore
void percorreIn(NO* raiz)
{
	if (raiz != NULL)
	{
		percorreIn(raiz->esq);
		printf("%d ", raiz->chave);
		percorreIn(raiz->dir);
	}
}

