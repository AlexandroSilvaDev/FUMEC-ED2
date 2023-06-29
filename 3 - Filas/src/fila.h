/*
 * fila.h
 *
 *  Created on: 7 de mar. de 2023
 *      Author: 13A226889818
 */

#ifndef FILA_H_
#define FILA_H_

// Biblioteca

#include <stdio.h>
#include <stdlib.h>

// Typedef

typedef struct CELULA_TAG *PONT;

// Estrutura

typedef struct
{
	int chave;
} ITEM;

typedef struct CELULA_TAG
{
	ITEM item;

	PONT prox;
} CELULA;

typedef struct
{
	int tamanho;

	PONT inicio;
	PONT fim;
} FILA;

// Prototipo

void cria( FILA * );
int vazia( FILA );
int enfileira( ITEM , FILA * );
int desenfileira( FILA * , ITEM * );

#endif /* FILA_H_ */
