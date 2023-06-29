/*
 ============================================================================
 Name        : 8.c
 Author      : Alexandro Silva
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "biblioteca.h"

int main(void) {
	DICIONARIO d;
	CHAVE nome;
	ITEM item;
	int resultado;
	//FILE *input;

	//input = fopen("entrada.txt", "r");

	criar(d);
	for (;;)
	{
		//fscanf(input, "%s", nome);
		//fclose(input);
		printf("Digite um nome: ");
		fflush(stdout);
		scanf("%s", nome);

		if (!strcmp(nome, "fim"))
		{
			break;
		}
		resultado = pesquisa(d, nome);

		if (resultado == -1)
		{
			memset(item.nome, ' ', N);
			strncpy(item.nome, nome, N);
			item.preco = 0;
			resultado = inserir(d, item);
		}
		if (resultado == -1)
		{
			printf("Dicionario cheio\n");
		}
		else
		{
			d[resultado].preco = rand();
			printf("%s - %lf\n", d[resultado].nome,
					d[resultado].preco);
		}
/*
		if (resultado >= 0)
		{
			printf("Já cadastrado!\n");
		}
		else if (resultado == -1)
		{
			item.nome = nome;
			item.preco = rand();
			inserir(d, item);
		}
		else
		{
			printf("Erro na pesquisa!\n");
		}
*/
	}
	//alterarPreco(d, nome, rand());
	//remover(d, nome);

	return EXIT_SUCCESS;
}
