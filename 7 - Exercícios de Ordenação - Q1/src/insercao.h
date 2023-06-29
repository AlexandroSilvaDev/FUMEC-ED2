/*
 * insercao.h
 *
 *  Created on: 23 de mar. de 2023
 *      Author: 13A226889818
 */

#ifndef INSERCAO_H_
#define INSERCAO_H_

// Biblioteca

#include <stdio.h>
#include <stdlib.h>

// Macro

#define MAXTAM 20
#define RANDOM rand() % 100

// Typedef

typedef long CHAVE;

// Estrutura

typedef struct ITEM_TAG
{
	CHAVE chave;
} ITEM;

typedef ITEM VETOR[MAXTAM];
// Prototipo

void insercao(ITEM *vetor, int tamanho);
void ordena(ITEM *v, int index);
void imprime(ITEM *v, int tam);

#endif /* INSERCAO_H_ */
