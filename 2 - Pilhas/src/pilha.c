/*
 * pilha.c
 *
 *  Created on: 28 de fev. de 2023
 *      Author: 13A226889818
 */

#include "pilha.h"

void cria( PILHA *pilha )
{
	//pilha->topo = ( PONT ) malloc( sizeof( CELULA ) );
	CELULA *cabecalho = ( CELULA * ) malloc( sizeof(CELULA) );
	pilha->topo = cabecalho;
	pilha->fundo = cabecalho;
	cabecalho->prox = NULL;
	pilha->tamanho = 0;
}

int vazia( PILHA pilha )
{
	return ( pilha.topo == pilha.fundo );
}

int push( ITEM item, PILHA *pilha )
{
	// aloca uma celula na memoria
	CELULA *celula = ( CELULA * ) malloc( sizeof( CELULA ) );

	// O item da nova celula assumindo o item passado como parametro da funcao.
	celula->item = item;

	// Fazendo push em uma pilha que ja tem celulas empilhadas.
	if ( pilha->topo )
	{
		celula->prox = pilha->topo;
	}
	// Fazendo push em uma pilha vazia.
	else
	{
		pilha->fundo = celula;
		celula->prox = NULL;
	}
	// Apontando o proximo da celula cabecalho para a nova celula.
	pilha->topo = celula;

	// Incrementando 1 no tamanho da pilha.
	pilha->tamanho++;

	// Retornando o valor guardado no item da celula criada.
	//return celula->item.chave;
	return 0;
}

int pop( PILHA *pilha, ITEM *item )
{
	PONT aux; // Ponteiro auxiliar.

	// Testando se a pilha e vazia.
	if ( vazia( *pilha ) )
	{
		return -1;
	}
	// Auxiliar recebe o topo da pilha.
	aux = pilha->topo;

	// O ponteiro.
	pilha->topo = aux->prox;
	/*
		O ponteiro item recebido como parametro, armazena o valor
		do item referente a celula que sera retirada da pilha (POP).
	*/
	*item = aux->item;

	// Retira a celula do topo da lista.
	free(aux);

	// Decrementa 1 do tamanho da pilha.
	pilha->tamanho--;

	return 0;
}

int look( PILHA *pilha, ITEM *item )
{
	// Testando se a pilha e vazia.
	if ( vazia( *pilha ) )
	{
		return -1;
	}
	/*
		O ponteiro item recebi como parametro, armazena o valor
		do item referente a celula do topo da pilha.
	*/
	*item = pilha->topo->item;

	// Retorna o valor guardado no item da celula do topo da pilha.
	//return item->chave;
	return 0;
}

int tamanho( PILHA pilha )
{
	// Retorna o tamanho da pilha.
	return pilha.tamanho;
}
