/*
 ============================================================================
 Name        : matrizes_esparsas.c
 Author      : Alexandro Silva
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "matriz.h"

int main() {
   MATRIZ a, b, c;

   // Exemplo 1
   printf("Exemplo 1:\n");
   criaMatriz(&a);
   leMatrizFromFile(&a, "entrada.txt");
   imprimeMatriz(&a);

   criaMatriz(&b);
   leMatrizFromFile(&b, "entrada.txt");
   imprimeMatriz(&b);

   criaMatriz(&c);
   somaMatriz(&a, &b, &c);
   printf("Soma:\n");
   imprimeMatriz(&c);

   apagaMatriz(&c);
   multiplicaMatriz(&a, &b, &c);
   printf("Produto:\n");
   imprimeMatriz(&c);

   apagaMatriz(&a);
   apagaMatriz(&b);
   apagaMatriz(&c);

   // Exemplo 2
   printf("Exemplo 2:\n");
   criaMatriz(&a);
   leMatrizFromFile(&a, "entrada.txt");
   imprimeMatriz(&a);

   criaMatriz(&b);
   leMatrizFromFile(&b, "entrada.txt");
   imprimeMatriz(&b);

   criaMatriz(&c);
   somaMatriz(&a, &b, &c);
   printf("Soma:\n");
   imprimeMatriz(&c);

   apagaMatriz(&c);
   multiplicaMatriz(&a, &b, &c);
   printf("Produto:\n");
   imprimeMatriz(&c);

   apagaMatriz(&a);
   apagaMatriz(&b);
   apagaMatriz(&c);

   return 0;
}
