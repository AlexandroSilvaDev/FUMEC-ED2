/*
 * funcoes.c
 *
 *  Created on: 30 de mai. de 2023
 *      Author: xande
 */

#include "biblioteca.h"

// Função auxiliar para criar um novo nó de lista de adjacências
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Função auxiliar para criar um grafo com um número fixo de vértices
struct Graph* createGraph(int num_vertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;

    graph->adj_list = (struct AdjListNode**)malloc(num_vertices * sizeof(struct AdjListNode*));
    for (int i = 0; i < num_vertices; ++i)
    {
        graph->adj_list[i] = NULL;
    }

    return graph;
}

// Função para adicionar uma aresta ao grafo direcionado
void addEdge(struct Graph* graph, int src, int dest)
{
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->adj_list[src];
    graph->adj_list[src] = newNode;
}

// Algoritmo de busca em profundidade
void DFS(struct Graph* graph, int vertex, int* visited, int* stack, int* stack_index)
{
    visited[vertex] = 1;

    struct AdjListNode* temp = graph->adj_list[vertex];
    while (temp != NULL)
    {
        int adj_vertex = temp->dest;
        if (!visited[adj_vertex])
        {
            DFS(graph, adj_vertex, visited, stack, stack_index);
        }
        temp = temp->next;
    }

    stack[(*stack_index)++] = vertex;
}

// Função auxiliar para criar uma fila
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// Verifica se a fila está vazia
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Verifica se a fila está cheia
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Insere um elemento na fila
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Remove um elemento da fila
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Algoritmo de busca em largura (BFS)
void BFS(struct Graph* graph, int start_vertex) {
    int* visited = (int*)calloc(graph->num_vertices, sizeof(int));
    struct Queue* queue = createQueue(graph->num_vertices);

    visited[start_vertex] = 1;
    enqueue(queue, start_vertex);

    while (!isEmpty(queue)) {
        int current_vertex = dequeue(queue);
        printf("%d ", current_vertex);

        struct AdjListNode* temp = graph->adj_list[current_vertex];
        while (temp != NULL) {
            int adj_vertex = temp->dest;
            if (!visited[adj_vertex]) {
                visited[adj_vertex] = 1;
                enqueue(queue, adj_vertex);
            }
            temp = temp->next;
        }
    }

    free(visited);
    free(queue->array);
    free(queue);
}

// Ordenação topológica usando busca em profundidade
void topologicalSort(struct Graph* graph)
{
    int* visited = (int*)calloc(graph->num_vertices, sizeof(int));
    int* stack = (int*)malloc(graph->num_vertices * sizeof(int));
    int stack_index = 0;

    for (int i = 0; i < graph->num_vertices; ++i)
    {
        if (!visited[i])
        {
            DFS(graph, i, visited, stack, &stack_index);
        }
    }

    // Imprimir a ordem topológica
    printf("Ordem topologica: ");
    while (stack_index > 0)
    {
        printf("%d ", stack[--stack_index]);
    }

    free(visited);
    free(stack);
}
