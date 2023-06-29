/*
 * matriz.h
 *
 *  Created on: 16 de jun. de 2023
 *      Author: Alexandro Silva
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct {
  int nLinhas, nColunas;
  LISTA *linha;
  LISTA *coluna;
} MATRIZ;

void criaMatriz(MATRIZ*);
void insereMatriz(MATRIZ*,int,int,double);
int  vaziaMatriz(MATRIZ*);
void leMatriz(MATRIZ*);
void somaMatriz(MATRIZ*,MATRIZ*,MATRIZ*);
void multiplicaMatriz(MATRIZ*,MATRIZ*,MATRIZ*);
void imprimeMatriz(MATRIZ*);
void apagaMatriz(MATRIZ*);
void apaga(PONT *p);
void leMatrizFromFile(MATRIZ* matriz, const char* filename);

#endif /* MATRIZ_H_ */
