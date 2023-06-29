/*
 * funcoes.c
 *
 *  Created on: 17 de fev. de 2023
 *      Author: xande
 */

#include "biblioteca.h"

void criaMatriz( Matriz *a )
{
	a->nLinhas = 0;
	a->nColunas = 0;

	a->linha = NULL;
	a->coluna = NULL;
}

void inicializaMatriz( Matriz *a, int linhas, int colunas )
{
	if ( ! a->linha )
	{
		a->linha = ( Lista * ) malloc( sizeof( Lista ) * linhas );
		a->coluna = ( Lista * ) malloc( sizeof( Lista ) * colunas );
		a->nLinhas = linhas;
		a->nColunas = colunas;
	}
	else
	{
		printf("\nPrimeiro a matriz deve ser criada!");
	}
}

void leMatriz( Matriz *a )
{

}

void imprimeMatriz( Matriz *a )
{

}

void somaMatriz( Matriz *ma, Matriz *mb, Matriz *mc )
{
	if ( (ma->nLinhas == mb->nLinhas) && (ma->nColunas == mb->nColunas)
			&& (! mc->linha) )
	{
		inicializaMatriz(mc, ma->nLinhas, ma->nColunas);

		for ( int i = 0 ; i < ((ma->nLinhas < ma->nColunas) ? ma->nColunas : ma->nLinhas) ; i++ )
		{
			mc->linha->primeiro->item.valor = ma->linha->primeiro->item.valor + mb->linha->primeiro->item.valor;
			mc->coluna->primeiro->item.valor = ma->coluna->primeiro->item.valor + mb->coluna->primeiro->item.valor;

			mc->linha->primeiro++;
			ma->linha->primeiro++;
			mb->linha->primeiro++;

			mc->coluna->primeiro++;
			ma->coluna->primeiro++;
			mb->coluna->primeiro++;
		}
	}
}

void multiplicaMatriz( Matriz *ma, Matriz *mb, Matriz *mc )
{
	if ( (ma->nColunas == mb->nLinhas) && (! mc->linha) )
	{
		inicializaMatriz(mc, ma->nLinhas, mb->nColunas);



		mc->linha->primeiro++;
		ma->linha->primeiro++;
		mb->linha->primeiro++;

		mc->coluna->primeiro++;
		ma->coluna->primeiro++;
		mb->coluna->primeiro++;
	}
}

void apagaMatriz( Matriz *a )
{

}
