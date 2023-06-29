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
	ARVORE *arv;
	ITEM item;
	int i;

	cria(&arv);
	arq = fopen("arq.txt", "r");

	while (fscanf(arq, "%d", &i) != EOF)
	{
		item.chave = i;

		if (insere(&arv, item) == -1)
		{
			printf("Erro na insercao de %d\n", i);
		}
	}
	printf("Pre ordem:\n");
	percorrePre(arv);

	printf("Pos ordem:\n");
	percorrePos(arv);

	printf("In ordem:\n");
	percorreIn(arv);

	while (1)
	{
		printf("Favor informar o item a retirar: ");
		fflush(stdout);
		scanf("%d", &item.chave);

		if (item.chave == -1)
		{
			break;
		}

		if (retira(&arv, item) == -1)
		{
			printf("Elemento nao existe na arvore\n");
		}
		else
		{
			printf("Elemento retirado. Arvore:\n");
			percorreIn(arv);
		}
	}

	return EXIT_SUCCESS;
}
