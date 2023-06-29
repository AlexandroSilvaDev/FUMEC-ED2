/*
 * pilha.h
 *
 *  Created on: 28 de fev. de 2023
 *      Author: 13A226889818
 */

#ifndef PILHA_H_
#define PILHA_H_

// Biblioteca

#include <stdio.h>
#include <stdlib.h>

// typedef

typedef struct CELULA_TAG *PONT;

// Estrutura

// Item que armazena o dados relevantes.
typedef struct
{
	int chave; // valor do conteudo que será guardado no ITEM da celula.
} ITEM;

// Celula (uma posicao da lista) que contem os itens e o ponteiro do proximo.
typedef struct CELULA_TAG
{
	ITEM item; // conteudo da celula a ser guardado.

	PONT prox; // aponta para o endereco de memoria da proxima celula.
} CELULA;

// Pilha que contem o topo da pilha, o fundo da pilha e o tamanho da pilha.
typedef struct
{
	int tamanho; // tamanho da pilha (numero de elementos existentes)

	PONT topo;  // ponteiro proximo.
	PONT fundo; // ponteiro ultimo.
} PILHA;

// Prototipo

// Cria a pilha vazia (inclui a celula cabecalho).
void cria( PILHA * );

// Verifica se a pilha esta vazia.
int vazia( PILHA );

// Empilha um item.
int push( ITEM, PILHA * );

// Desempilha um item.
int pop( PILHA *, ITEM * );

// Recupera (sem desempilhar) um item no topo da pilha.
int look( PILHA *, ITEM * );

// Retorna a quantidade de itens na pilha.
int tamanho( PILHA );

#endif /* PILHA_H_ */
