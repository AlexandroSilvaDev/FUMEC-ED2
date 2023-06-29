/*
 * funcoes.c
 *
 *  Created on: 16 de jun. de 2023
 *      Author: Alexandro Silva
 */

#include "biblioteca.h"

void FGVazio(TipoGrafo *Grafo)
{
    short i, j;

    for (i = 0; i <= Grafo->NumVertices; i++)
    {
        for (j = 0; j <= Grafo->NumVertices; j++)
        {
            Grafo->Mat[i][j] = 0;
        }
    }
}

void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo)
{
    Grafo->Mat[*V1][*V2] = *Peso;
}

short ExisteAresta(TipoValorVertice Vertice1, TipoValorVertice Vertice2, TipoGrafo *Grafo)
{
    return (Grafo->Mat[Vertice1][Vertice2] > 0);
}

short ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo)
{
    TipoApontador Aux = 0;
    short ListaVazia = TRUE;

    while (Aux < Grafo->NumVertices && ListaVazia)
    {
        if (Grafo->Mat[*Vertice][Aux] > 0)
        {
            ListaVazia = FALSE;
        }
        else
        {
            Aux++;
        }
    }
    return (ListaVazia == TRUE);
}

TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo)
{
    TipoValorVertice Result;
    TipoApontador Aux = 0;
    short ListaVazia = TRUE;

    while (Aux < Grafo->NumVertices && ListaVazia)
    {
        if (Grafo->Mat[*Vertice][Aux] > 0)
        {
            Result = Aux;
            ListaVazia = FALSE;
        }
        else
        {
            Aux++;
        }
    }
    if (Aux == Grafo->NumVertices)
    {
        printf("Erro: Lista de adjacência vazia (PrimeiroListaAdj)\n");
    }
    return Result;
}

void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo, TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox, short *FimListaAdj)
{
    *Adj = *Prox;
    *Peso = Grafo->Mat[*Vertice][*Prox];
    (*Prox)++;

    while (*Prox < Grafo->NumVertices && Grafo->Mat[*Vertice][*Prox] == 0)
    {
        (*Prox)++;
    }
    if (*Prox == Grafo->NumVertices)
    {
        *FimListaAdj = TRUE;
    }
}

void RetiraAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo)
{
    if (Grafo->Mat[*V1][*V2] == 0)
    {
        printf("Aresta não existe\n");
    }
    else
    {
        *Peso = Grafo->Mat[*V1][*V2];
        Grafo->Mat[*V1][*V2] = 0;
    }
}

void LiberaGrafo(TipoGrafo *Grafo)
{
    // Não faz nada no caso de matrizes de adjacência
}

void ImprimeGrafo(TipoGrafo *Grafo)
{
    short i, j;
    printf(" ");

    for (i = 0; i <= Grafo->NumVertices - 1; i++)
    {
        printf("%3d", i);
    }
    printf("\n");

    for (i = 0; i <= Grafo->NumVertices - 1; i++)
    {
        printf("%3d", i);

        for (j = 0; j <= Grafo->NumVertices - 1; j++)
        {
            printf("%3d", Grafo->Mat[i][j]);
        }
        printf("\n");
    }
}

// Busca em Profundidade

void VisitaDFS(TipoValorVertice *Vertice, TipoGrafo *Grafo, int *Visitado)
{
    Visitado[*Vertice] = TRUE;
    printf("%d ", *Vertice);

    TipoApontador Apontador;

    for (Apontador = PrimeiroListaAdj(Vertice, Grafo); Apontador < Grafo->NumVertices; ProxAdj(Vertice, Grafo, &Apontador, NULL, &Apontador, NULL))
    {
        if (!Visitado[Apontador])
        {
            VisitaDFS(&Apontador, Grafo, Visitado);
        }
    }
}

void BuscaEmProfundidade(TipoGrafo *Grafo)
{
    int Visitado[MAXNUMVERTICES];
    TipoValorVertice Vertice;

    for (Vertice = 0; Vertice < Grafo->NumVertices; Vertice++)
    {
        Visitado[Vertice] = FALSE;
    }

    for (Vertice = 0; Vertice < Grafo->NumVertices; Vertice++)
    {
        if (!Visitado[Vertice])
        {
            VisitaDFS(&Vertice, Grafo, Visitado);
        }
    }
}

// Busca em Largura

void VisitaBFS(TipoValorVertice *Vertice, TipoGrafo *Grafo, int *Visitado)
{
    int Fila[MAXNUMVERTICES];
    int InicioFila = 0;
    int FimFila = 0;

    Visitado[*Vertice] = TRUE;
    printf("%d ", *Vertice);
    Fila[FimFila++] = *Vertice;

    while (InicioFila < FimFila)
    {
        TipoValorVertice V = Fila[InicioFila++];
        TipoApontador Apontador;

        for (Apontador = PrimeiroListaAdj(&V, Grafo); Apontador < Grafo->NumVertices; ProxAdj(&V, Grafo, &Apontador, NULL, &Apontador, NULL))
        {
            if (!Visitado[Apontador])
            {
                Visitado[Apontador] = TRUE;
                printf("%d ", Apontador);
                Fila[FimFila++] = Apontador;
            }
        }
    }
}

void BuscaEmLargura(TipoGrafo *Grafo)
{
    int Visitado[MAXNUMVERTICES];
    TipoValorVertice Vertice;

    for (Vertice = 0; Vertice < Grafo->NumVertices; Vertice++)
    {
        Visitado[Vertice] = FALSE;
    }

    for (Vertice = 0; Vertice < Grafo->NumVertices; Vertice++)
    {
        if (!Visitado[Vertice])
        {
            VisitaBFS(&Vertice, Grafo, Visitado);
        }
    }
}

// Ordenação Topológica

void OrdenacaoTopologica(TipoGrafo *Grafo)
{
    int Visitado[MAXNUMVERTICES];
    int Pilha[MAXNUMVERTICES];
    int TopoPilha = -1;

    TipoValorVertice Vertice;

    for (Vertice = 0; Vertice < Grafo->NumVertices; Vertice++)
    {
        Visitado[Vertice] = FALSE;
    }

    for (Vertice = 0; Vertice < Grafo->NumVertices; Vertice++)
    {
        if (!Visitado[Vertice])
        {
            VisitaDFSTopo(&Vertice, Grafo, Visitado, Pilha, &TopoPilha);
        }
    }
    printf("Ordenação topológica: ");

    while (TopoPilha >= 0)
    {
        printf("%d ", Pilha[TopoPilha]);
        TopoPilha--;
    }
    printf("\n");
}

void VisitaDFSTopo(TipoValorVertice *Vertice, TipoGrafo *Grafo, int *Visitado, int *Pilha, int *TopoPilha)
{
    Visitado[*Vertice] = TRUE;

    TipoApontador Apontador;

    for (Apontador = PrimeiroListaAdj(Vertice, Grafo); Apontador < Grafo->NumVertices; ProxAdj(Vertice, Grafo, &Apontador, NULL, &Apontador, NULL))
    {
        if (!Visitado[Apontador])
        {
            VisitaDFSTopo(&Apontador, Grafo, Visitado, Pilha, TopoPilha);
        }
    }
    (*TopoPilha)++;
    Pilha[*TopoPilha] = *Vertice;
}

// Verificação de Ciclo

int ExisteCiclo(TipoGrafo *Grafo)
{
    int Visitado[MAXNUMVERTICES];
    int Pilha[MAXNUMVERTICES];
    int TopoPilha = -1;

    TipoValorVertice Vertice;

    for (Vertice = 0; Vertice < Grafo->NumVertices; Vertice++)
    {
        Visitado[Vertice] = FALSE;
    }

    for (Vertice = 0; Vertice < Grafo->NumVertices; Vertice++)
    {
        if (!Visitado[Vertice] && VerificaCicloDFS(&Vertice, Grafo, Visitado, Pilha, &TopoPilha))
        {
            return TRUE;
        }
    }
    return FALSE;
}

int VerificaCicloDFS(TipoValorVertice *Vertice, TipoGrafo *Grafo, int *Visitado, int *Pilha, int *TopoPilha)
{
    Visitado[*Vertice] = TRUE;

    Pilha[++(*TopoPilha)] = *Vertice;

    TipoApontador Apontador;

    for (Apontador = PrimeiroListaAdj(Vertice, Grafo); Apontador < Grafo->NumVertices; ProxAdj(Vertice, Grafo, &Apontador, NULL, &Apontador, NULL))
    {
        if (!Visitado[Apontador])
        {
            if (VerificaCicloDFS(&Apontador, Grafo, Visitado, Pilha, TopoPilha))
            {
                return TRUE;
            }
        }
        else if (PilhaContains(Pilha, *TopoPilha, Apontador))
        {
            return TRUE;
        }
    }
    (*TopoPilha)--;
    return FALSE;
}

int PilhaContains(int *Pilha, int TopoPilha, int Vertice)
{
    int i;

    for (i = 0; i <= TopoPilha; i++)
    {
        if (Pilha[i] == Vertice)
        {
            return TRUE;
        }
    }
    return FALSE;
}
