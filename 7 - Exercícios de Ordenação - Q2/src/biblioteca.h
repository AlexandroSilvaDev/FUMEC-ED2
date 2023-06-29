/*
 * biblioteca.h
 *
 *  Created on: 28 de mar. de 2023
 *      Author: xande
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Biblioteca

#include <stdlib.h>
#include <stdio.h>

// Prototipo

void quicksort(int *v, int tam);
void ordenaQuick(int *v, int esq, int dir);
void particaoQuick(int *v, int esq, int dir, int *i, int *j);
void insercao(int *v, int tam);
void ordenaInsercao(int *v, int index);
void imprime(int *v, int tam);

#endif /* BIBLIOTECA_H_ */
