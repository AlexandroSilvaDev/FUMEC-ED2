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
	NO* dicionario = NULL;

	// Inserção de elementos no dicionário
	ITEM item1 = {"item1", 10.50};
	ITEM item2 = {"item2", 5.75};
	ITEM item3 = {"item3", 20.00};
	ITEM item4 = {"item4", 15.25};
	dicionario = inserir(dicionario, item1);
	dicionario = inserir(dicionario, item2);
	dicionario = inserir(dicionario, item3);
	dicionario = inserir(dicionario, item4);

	// Pesquisa de um elemento no dicionário
	CHAVE chavePesquisa = "item3";
	NO* resultado = pesquisa(dicionario, chavePesquisa);

	if (resultado != NULL)
	{
	    printf("Elemento encontrado: %s - %.2f\n", resultado->item.nome, resultado->item.preco);
	}
	else
	{
	    printf("Elemento não encontrado.\n");
	}

	// Percorrimento inorder do dicionário
	printf("Dicionário:\n");
	percorreIn(dicionario);

	return 0;
}
