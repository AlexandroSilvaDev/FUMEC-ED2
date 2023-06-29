/*
 * biblioteca.h
 *
 *  Created on: 25 de abr. de 2023
 *      Author: 13A226889818
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Biblioteca

#include <stdio.h>
#include <stdlib.h>

// Typedef

typedef struct item ITEM;
typedef struct no NO;
typedef NO ARVORE;

// Estrutura

struct item
{
	int chave;
};

struct no
{
	ITEM item;
	NO *esq;
	NO *dir;
};

// Prototipo

void cria         (ARVORE **a);
int pesquisa      (ARVORE **a, ITEM *i);
int insere        (ARVORE **a, ITEM i);
int retira        (ARVORE **a, ITEM i);
void percorreIn   (ARVORE *a);
void percorrePre  (ARVORE *a);
void percorrePos  (ARVORE *a);

#endif /* BIBLIOTECA_H_ */
