/*
 * biblioteca.h
 *
 *  Created on: 5 de mai. de 2023
 *      Author: xande
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Biblioteca

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macros

#define M 113
#define N 20
#define VAZIO    "                    "
#define RETIRADO "********************"
#define RANDOM rand() % 300

// Estrutura e Typedef

typedef char CHAVE [N + 1];
typedef struct NO_TAG *PONT;

typedef struct
{
	CHAVE nome;
	double preco;
} ITEM;

typedef struct NO_TAG
{
	ITEM item;

	PONT dir;
	PONT esq;
} NO;

typedef PONT DICIONARIO;

// Prototipo

void criar        (DICIONARIO *d);
int pesquisar     (DICIONARIO *d, ITEM i);
int inserir       (DICIONARIO *d, ITEM i);
int retirar       (DICIONARIO *d, ITEM i);
void percorreIn   (DICIONARIO d);
void percorrePre  (DICIONARIO d);
void percorrePos  (DICIONARIO d);
int altura        (DICIONARIO d);

#endif /* BIBLIOTECA_H_ */
