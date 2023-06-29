/*
 * biblioteca.h
 *
 *  Created on: 17 de fev. de 2023
 *      Author: xande
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Biblioteca

#include <stdio.h>
#include <stdlib.h>

// Typedef

typedef struct Item Item;
typedef struct Celula_Tag *PONT;
typedef struct Lista Lista;
typedef struct Matriz Matriz;

// Estrutura

struct Item
{
	int linha;
	int coluna;
	double valor;
};

typedef struct Celula_Tag
{
	Item item;

	PONT direita;
	PONT abaixo;
} Celula;

struct Lista
{
	PONT primeiro;
	PONT ultimo;
};

struct Matriz
{
	int nLinhas;
	int nColunas;

	Lista *linha;
	Lista *coluna;
};

// Prototipo

void criaMatriz( Matriz *a );
void inicializaMatriz( Matriz *a, int linhas, int colunas );
void leMatriz( Matriz *a );
void imprimeMatriz( Matriz *a );
void somaMatriz( Matriz *ma, Matriz *mb, Matriz *mc );
void multiplicaMatriz( Matriz *ma, Matriz *mb, Matriz *mc );
void apagaMatriz( Matriz *a );

#endif /* BIBLIOTECA_H_ */
