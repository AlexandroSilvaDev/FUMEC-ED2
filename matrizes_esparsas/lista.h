/*
 * lista.h
 *
 *  Created on: 16 de jun. de 2023
 *      Author: Alexandro Silva
 */

#ifndef LISTA_H_
#define LISTA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct CELULA_TAG *PONT;

typedef struct {
   int linha, coluna;
   double valor;
} ITEM;

typedef struct CELULA_TAG {
   ITEM item;
   PONT direita;
   PONT abaixo;
} CELULA;

typedef struct {
   PONT primeiro, ultimo;
} LISTA;

void cria(LISTA*);
int  insereLinha(LISTA*,PONT);
int  insereColuna(LISTA*,PONT);
void imprimeLinha(LISTA*,int);

#endif /* LISTA_H_ */
