/*
 * fila.c
 *
 *  Created on: 7 de mar. de 2023
 *      Author: 13A226889818
 */

#include "fila.h"

void cria( FILA *fila )
{
	CELULA *cabecalho = ( CELULA * ) malloc( sizeof( CELULA ) );

	fila->inicio = cabecalho;
	fila->fim = cabecalho;
	cabecalho->prox = NULL;
	fila->tamanho = 0;
}

int vazia( FILA fila )
{
	return ( fila.inicio == fila.fim );
}

int enfileira( ITEM item , FILA *fila )
{
	CELULA *celula = ( CELULA * ) malloc( sizeof( CELULA ) );

	celula->item = item;

	fila->fim->prox = celula;
	fila->fim = celula;
	celula->prox = NULL;
	fila->tamanho++;

	return 0;
}

int desenfileira( FILA *fila , ITEM *item )
{
	PONT aux;

	if ( vazia( fila ) )
	{
		return -1;
	}
	aux = fila->inicio;
	fila->inicio = aux->prox;

	*item = aux->item;
	free(aux);
	fila->tamanho--;

	return 0;
}
