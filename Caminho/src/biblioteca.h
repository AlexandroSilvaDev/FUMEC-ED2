/*
 * biblioteca.h
 *
 *  Created on: 12 de jun. de 2023
 *      Author: Alexandro Silva
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define INFINITY 99999

typedef struct
{
    int num_cidades;
    int origem;
    int destino;
} GrafoInfo;

typedef struct
{
    int cidade1;
    int cidade2;
    int distancia;
} Arco;

typedef struct
{
    int cidade;
    int distancia;
} Caminho;

void exibirUtilizacao();
void lerArquivo(char* nome_arquivo, GrafoInfo* grafo_info, Arco** arcos);
void dijkstra(int** matriz_distancias, int num_cidades, int origem, int destino, Caminho** caminho_minimo);
void exibirCaminhoMinimo(Caminho* caminho_minimo, int num_cidades, int origem, int destino);
void liberarMemoria(int** matriz_distancias, Arco* arcos, Caminho* caminho_minimo);

#endif /* BIBLIOTECA_H_ */
