/*
 ============================================================================
 Name        : An�lise.c
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

	char expressao[50] = "51 13 12 * +"; // (51 + 13 * 12) - resultado = 207

	/* EXPRESSOES TESTES
	 * (5 * (3 + 2) / 4 - 6) | 5 3 2 + * 4 / 6 | resultado = 0,25
	 * (5 + 3 + 2 * 4 - 6 * 7 * 1) | 5 3 + 2 4 * + 6 7 * 1 * - | resultado = -26
	 * (5 * (3 + (2 * (4 + (6 * (7 + 1)))))) | 5 3 2 4 6 7 1 + * + * + * | resultado = 535
	 */

	printf("Resultado de %s: %f\n", expressao, resolverExpressao(expressao));

	return EXIT_SUCCESS;
}
