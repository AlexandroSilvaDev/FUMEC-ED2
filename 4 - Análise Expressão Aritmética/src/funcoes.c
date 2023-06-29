/*
 * funcoes.c
 *
 *  Created on: 11 de mar. de 2023
 *      Author: xande
 */

#include "biblioteca.h"

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

int push( float valor, PILHA *pilha )
{
	// aloca uma celula na memoria
	CELULA *celula = ( CELULA * ) malloc( sizeof( CELULA ) );

	// O item da nova celula assumindo o item passado como parametro da funcao.
	celula->valor = valor;

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

int pop( PILHA *pilha )
{
	PONT aux; // Ponteiro auxiliar.

	// Testando se a pilha e vazia.
	if ( vazia( *pilha ) )
	{
		return -1;
	}
	// Auxiliar recebe o topo da lista.
	aux = pilha->topo;

	// O ponteiro .
	pilha->topo = aux->prox;

	// Retira a celula do topo da lista.
	free(aux);

	// Decrementa 1 do tamanho da pilha.
	pilha->tamanho--;

	return 0;
}

int look( PILHA *pilha, float *valor )
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
	*valor = pilha->topo->valor;

	// Retorna o valor guardado no item da celula do topo da pilha.
	//return item->chave;
	return 0;
}

int tamanho( PILHA pilha )
{
	// Retorna o tamanho da pilha.
	return pilha.tamanho;
}

float operacao( float a, float b, char x )
{
	switch ( x )
	{
		case '+':
			return a + b;
			break;

		case '-':
			return a - b;
			break;

		case '/':
			return a / b;
			break;

		case '*':
			return a * b;
			break;

		default:
			return 0;
	}
}

float resolverExpressao( char vet[] )
{
	char *pont;
	PONT n1, n2, pilha = NULL;
	float num;

	pont = strtok(vet, " ");

	while ( pont )
	{
		if ( pont[0] == '+' || pont[0] == '-' ||
				pont[0] == '/' || pont[0] == '*' )
		{
			n1 = pop( pilha );
			n2 = pop( pilha );
			num = operacao( n2->valor, n1->valor, pont[0] );
			pilha = push(num, pilha);
			free(n1);
			free(n2);
		}
		else
		{
			num = strtol(pont, NULL, 10);
			pilha = push(num, pilha);
		}
		pont = strtok(NULL, " ");
	}
	n1 = pop( pilha );
	num = n1->valor;
	free(n1);

	return num;
}
