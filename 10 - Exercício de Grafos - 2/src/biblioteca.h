/*
 * biblioteca.h
 *
 *  Created on: 16 de jun. de 2023
 *      Author: Alexandro Silva
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
void VisitaDFS(TipoValorVertice *Vertice, TipoGrafo *Grafo, int *Visitado);
void BuscaEmProfundidade(TipoGrafo *Grafo);
void VisitaBFS(TipoValorVertice *Vertice, TipoGrafo *Grafo, int *Visitado);
void BuscaEmLargura(TipoGrafo *Grafo);
void OrdenacaoTopologica(TipoGrafo *Grafo);
void VisitaDFSTopo(TipoValorVertice *Vertice, TipoGrafo *Grafo, int *Visitado, int *Pilha, int *TopoPilha);
int ExisteCiclo(TipoGrafo *Grafo);
int VerificaCicloDFS(TipoValorVertice *Vertice, TipoGrafo *Grafo, int *Visitado, int *Pilha, int *TopoPilha);
int PilhaContains(int *Pilha, int TopoPilha, int Vertice);

#endif /* BIBLIOTECA_H_ */
