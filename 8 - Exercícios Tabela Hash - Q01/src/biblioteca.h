/*
 * biblioteca.h
 *
 *  Created on: 15 de abr. de 2023
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

// Typedef

typedef char CHAVE[N + 1];

// Estrutura

typedef struct
{
	CHAVE nome;
	double preco;
} ITEM;
/*
typedef struct
{
	ITEM item;
} DICIONARIO;
*/
typedef ITEM DICIONARIO[M];

// Prototipo

int converter(CHAVE chave);
void criar(DICIONARIO d);
int inserir(DICIONARIO d, ITEM x);
int remover(DICIONARIO d, CHAVE chave);
int pesquisa(DICIONARIO d, CHAVE chave);
int alterarPreco(DICIONARIO d, CHAVE chave, double preco);

#endif /* BIBLIOTECA_H_ */
