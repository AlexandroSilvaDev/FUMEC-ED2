/*
 * biblioteca.h
 *
 *  Created on: 30 de mai. de 2023
 *      Author: 13A226889818
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Bibliotecas

#include <stdio.h>
#include <stdlib.h>

// Macros

#define MAXNUMVERTICES 100
#define MAXNUMARESTAS 4500
#define TRUE 1
#define FALSE 0

// Typedefs

typedef int TipoValorVertice;
typedef int TipoPeso;

// Estruturas

typedef struct TipoGrafo
{
	TipoPeso Mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
	int NumVertices;
	int NumArestas;
} TipoGrafo;

typedef int TipoApontador;

// Prototipos

void FGVazio(TipoGrafo *Grafo);
void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo);
short ExisteAresta(TipoValorVertice Vertice1, TipoValorVertice Vertice2, TipoGrafo *Grafo);
short ListaAdjVazia(TipoValorVertice *Vertice , TipoGrafo *Grafo);
TipoApontador PrimeiroListaAdj ( TipoValorVertice *Vertice , TipoGrafo *Grafo);
void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo, TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox, short *FimListaAdj);
void RetiraAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo);
void LiberaGrafo(TipoGrafo *Grafo);
void ImprimeGrafo(TipoGrafo *Grafo);

#endif /* BIBLIOTECA_H_ */
