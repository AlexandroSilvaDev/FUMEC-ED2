/*
 * biblioteca.h
 *
 *  Created on: 11 de mai. de 2023
 *      Author: 13A226889818
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Biblioteca

#include <stdio.h>
#include <stdlib.h>

// Estrutura

typedef struct NO_TAG *PONT;

typedef struct NO_TAG
{
	int chave;
	int color; // 0 para vermelho, 1 para preto

	PONT dir;
	PONT esq;
} NO;

typedef PONT DICIONARIO;

// Prototipo

NO* criar(int chave);
NO* rotateLeft(NO* no);
NO* rotateRight(NO* no);
void flipColors(NO* no);
int isRed(NO* no);
NO* inserir(NO* raiz, int chave);
NO* pesquisa(NO* raiz, int chave);
void percorreIn(NO* raiz);

#endif /* BIBLIOTECA_H_ */
