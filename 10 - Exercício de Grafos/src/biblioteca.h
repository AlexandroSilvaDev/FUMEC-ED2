/*
 * biblioteca.h
 *
 *  Created on: 30 de mai. de 2023
 *      Author: xande
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Bibliotecas

#include <stdio.h>
#include <stdlib.h>

// Estrutura de nó para lista de adjacências
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

// Estrutura de grafo
struct Graph
{
    int num_vertices;
    struct AdjListNode** adj_list;
};

// Estrutura de fila para busca em largura
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

#endif /* BIBLIOTECA_H_ */
