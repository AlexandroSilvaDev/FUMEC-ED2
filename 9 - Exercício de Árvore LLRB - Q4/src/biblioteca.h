/*
 * biblioteca.h
 *
 *  Created on: 16 de mai. de 2023
 *      Author: xande
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Biblioteca

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Typedef

typedef char CHAVE[21];
typedef struct NO_TAG *PONT;

// Estrutura

typedef struct
{
    CHAVE nome;
    double preco;
} ITEM;

// Definição da estrutura de um nó da árvore
typedef struct NO_TAG
{
    ITEM item;
    int cor; // 0 para vermelho, 1 para preto

    PONT esq;
    PONT dir;
} NO;

// Prototipo

NO* criar(ITEM item);
int isRed(NO* no);
NO* rotateLeft(NO* no);
NO* rotateRight(NO* no);
void flipColors(NO* no);
NO* inserir(NO* raiz, ITEM item);
NO* pesquisa(NO* raiz, CHAVE nome);
void percorreIn(NO* raiz);

#endif /* BIBLIOTECA_H_ */
