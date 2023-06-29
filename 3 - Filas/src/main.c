/*
 ============================================================================
 Name        : Filas.c
 Author      : Alexandro Silva
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "fila.h"

int main(void)
{
	setbuf(stdin, NULL);

	FILA fila;
	ITEM i1, i2, i3;

	cria(&fila);

	i1.chave = 5;
	i2.chave = 2;
	i3.chave = 3;

	enfileira(i1, &fila);
	enfileira(i2, &fila);
	desenfileira(&fila, &i1);
	enfileira(i3, &fila);
	desenfileira(&fila, &i2);
	desenfileira(&fila, &i3);

	 if ( vazia(fila) )
	 {
		 printf("\n A fila esta vazia!");
	 }

	return EXIT_SUCCESS;
}
