/*
 ============================================================================
 Name        : Pilhas.c
 Author      : Alexandro Silva
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "pilha.h"

int main(void)
{
	setbuf(stdin, NULL);

	PILHA p;
	cria(&p);

	if ( vazia(p) )
	{

	}
	ITEM i;
	i.chave = 5;

	push(i, &p);

	return EXIT_SUCCESS;
}
