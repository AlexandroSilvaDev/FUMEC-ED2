/*
 * funcoes.c
 *
 *  Created on: 16 de mai. de 2023
 *      Author: xande
 */

#include "biblioteca.h"

// Função auxiliar para criar um novo nó com a chave especificada
NO* criar(int chave)
{
    NO* no = (NO*)malloc(sizeof(NO));
    no->chave = chave;
    no->esq = no->dir = NULL;
    no->cor = 0; // O novo nó é sempre vermelho
    no->deletado = 0; // O novo nó não está deletado

    return no;
}

// Função auxiliar para realizar a rotação para a esquerda
NO* rotateLeft(NO* no)
{
    NO* rightChild = no->dir;
    no->dir = rightChild->esq;
    rightChild->esq = no;
    rightChild->cor = no->cor;
    no->cor = 0;

    return rightChild;
}

// Função auxiliar para realizar a rotação para a direita
NO* rotateRight(NO* no)
{
    NO* leftChild = no->esq;
    no->esq = leftChild->dir;
    leftChild->dir = no;
    leftChild->cor = no->cor;
    no->cor = 0;

    return leftChild;
}

// Função auxiliar para inverter as cores dos nós
void flipColors(NO* no)
{
    no->cor = 0;
    no->esq->cor = 1;
    no->dir->cor = 1;
}

// Função auxiliar para verificar se o nó é vermelho
int isRed(NO* no)
{
    if (no == NULL)
    {
        return 0;
    }
    return (no->cor == 0);
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

// Função auxiliar para buscar o nó com a chave mínima
NO* findMin(NO* no)
{
    if (no == NULL)
    {
    	return NULL;
    }
    if (no->esq != NULL)
    {
    	return findMin(no->esq);
    }
    return no;
}

// Função auxiliar para deletar a marcação de um nó
void undeleteNode(NO* node)
{
	if (node != NULL)
	{
		node->deletado = 0;
	}
}

// Função para marcar um nó como deletado
void deleteNode(NO* node)
{
	if (node != NULL)
	{
		node->deletado = 1;
	}
}

// Função auxiliar para remover um nó com a chave especificada
NO* remover(NO* raiz, int chave)
{
	if (raiz == NULL)
	{
		return NULL;
	}

	// Busca pela chave na árvore
	if (chave < raiz->chave)
	{
		raiz->esq = remover(raiz->esq, chave);
	}
	else if (chave > raiz->chave)
	{
		raiz->dir = remover(raiz->dir, chave);
	}
	else
	{
	    // Encontrou o nó a ser removido
	    if (raiz->esq == NULL)
	    {
	        // Nó com apenas um filho à direita ou sem filhos
	        NO* temp = raiz->dir;
	        free(raiz);
	        return temp;
	    }
	    else if (raiz->dir == NULL)
	    {
	        // Nó com apenas um filho à esquerda
	        NO* temp = raiz->esq;
	        free(raiz);
	        return temp;
	    }
	    else
	    {
	        // Nó com dois filhos
	        NO* minNode = findMin(raiz->dir);
	        raiz->chave = minNode->chave;
	        raiz->dir = remover(raiz->dir, minNode->chave);
	    }
	}
	return raiz;
}

// Função para pesquisar um valor na árvore
NO* pesquisa(NO* raiz, int chave)
{
	// Caso base: chegou ao fim da árvore ou encontrou o valor
	if (raiz == NULL || (raiz->chave == chave && !raiz->deletado))
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

		if (!raiz->deletado)
		{
			printf("%d ", raiz->chave);
		}
		percorreIn(raiz->dir);
	}
}
