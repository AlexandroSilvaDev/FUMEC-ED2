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
	setbuf(stdin, NULL);

	FILE *arq;
	DICIONARIO d;
	ITEM item;

	criar(&d);
	arq = fopen("entrada.txt", "r");

	while (fscanf(arq, "%s", item.nome) != EOF)
	{
		if (inserir(&d, item) == -1)
		{
			printf("Erro na insercao de %s\n", item.nome);
		}
	}

	printf("Pre ordem:\n");
	percorrePre(d);

	printf("Pos ordem:\n");
	percorrePos(d);

	printf("In ordem:\n");
	percorreIn(d);

	while (1)
	{
		printf("Favor informar o item a retirar(nome): ");
		fflush(stdout);
		scanf("%s", item.nome);

		if (strncmp(item.nome, "fim", N + 1) == 0)
		{
			break;
		}

		if (retirar(&d, item) == -1)
		{
			printf("Elemento nao existe na arvore\n");
		}
		else
		{
			printf("Elemento retirado. Arvore:\n");
			percorreIn(d);
		}
	}

	return EXIT_SUCCESS;
}
