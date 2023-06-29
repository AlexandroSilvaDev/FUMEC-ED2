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

//Typedef

typedef struct NO_TAG *PONT;

// Estrutura

// Definição da estrutura de um nó da árvore
typedef struct NO_TAG
{
    int chave;
    int cor; // 0 para vermelho, 1 para preto
    int deletado; // 0 para não deletado, 1 para deletado

    PONT esq;
    PONT dir;
} NO;

// Prototipo

NO* criar			(int chave);
NO* rotateLeft		(NO* no);
NO* rotateRight		(NO* no);
void flipColors		(NO* no);
int isRed			(NO* no);
NO* inserir			(NO* raiz, int chave);
NO* findMin			(NO* no);
void undeleteNode	(NO* node);
void deleteNode		(NO* node);
NO* remover			(NO* raiz, int chave);
NO* pesquisa		(NO* raiz, int chave);
void percorreIn		(NO* raiz);
NO* refreshTree     (NO* raiz);

#endif /* BIBLIOTECA_H_ */
