/*
 * biblioteca.h
 *
 *  Created on: 17 de abr. de 2023
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

// Typedef

typedef char CHAVE[N + 1];
typedef struct CELULA CELULA;

// Estrutura

typedef struct
{
	CHAVE nome;
	double preco;
} ITEM;

struct CELULA
{
	ITEM item;

	CELULA *proximo;
};

typedef struct
{
	CELULA *inicio;
	CELULA *fim;
} LISTA;

typedef LISTA DICIONARIO[M];

// Prototipo

int converter(CHAVE chave);
void criar(DICIONARIO d);
int inserir(DICIONARIO d, ITEM x);
int remover(DICIONARIO d, CHAVE chave);
int pesquisa(DICIONARIO d, CHAVE chave);
int alterarPreco(DICIONARIO d, CHAVE chave, double preco);

#endif /* BIBLIOTECA_H_ */
