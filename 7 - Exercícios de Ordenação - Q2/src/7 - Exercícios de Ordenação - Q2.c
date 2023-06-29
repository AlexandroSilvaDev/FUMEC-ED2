/*
 ============================================================================
 Name        : 7.c
 Author      : Alexandro Silva
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int vet[] = {7,42,76,8,-1,995,72,3,44,0,1,15,28,77,100,98,105,44,36};
	int tam = sizeof(vet) / sizeof(int);

	imprime(vet,tam);

	quicksort(vet, tam);

	imprime(vet,tam);

	return EXIT_SUCCESS;
}
