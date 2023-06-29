/*
 * biblioteca.h
 *
 *  Created on: 11 de mar. de 2023
 *      Author: xande
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Biblioteca

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef

typedef struct CELULA_TAG *PONT;

// Estrutura

// Item que armazena os dados relevantes.
/*
typedef struct
{
	int chave; // valor do conteudo que será guardado no ITEM da celula.
} ITEM;
*/
// Celula (uma posicao da lista) que contem os itens e o ponteiro do proximo.
typedef struct CELULA_TAG
{
	float valor; // conteudo da celula a ser guardado.

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
int push( float, PILHA * );

// Desempilha um item.
int pop( PILHA * );

// Recupera (sem desempilhar) um item no topo da pilha.
int look( PILHA *, float * );

// Retorna a quantidade de itens na pilha.
int tamanho( PILHA );

float operacao( float a, float b, char x );

float resolverExpressao( char vet[] );

#endif /* BIBLIOTECA_H_ */
