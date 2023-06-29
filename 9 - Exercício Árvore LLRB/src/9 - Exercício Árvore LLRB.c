/*
 ============================================================================
 Name        : 9.c
 Author      : Alexandro Silva
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "biblioteca.h"

int main(void)
{
	setbuf(stdout, NULL);

	NO* raiz = NULL;

	// Inserção de elementos na árvore
	raiz = inserir(raiz, 7);
	raiz = inserir(raiz, 3);
	raiz = inserir(raiz, 18);
	raiz = inserir(raiz, 10);
	raiz = inserir(raiz, 22);
	raiz = inserir(raiz, 8);
	raiz = inserir(raiz, 11);
	raiz = inserir(raiz, 26);

	// Percorrimento inorder da árvore
	printf("Árvore: ");
	percorreIn(raiz);
	printf("\n");

	// Pesquisa de um valor na árvore
	int chave = 10;
	NO* resultado = pesquisa(raiz, chave);

	if (resultado != NULL)
	{
	    printf("Chave %d encontrada na árvore.\n", chave);
	}
	else
	{
		printf("Chave %d não encontrada na árvore.\n", chave);
	}
	return 0;
}
