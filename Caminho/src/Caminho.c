/*
 ============================================================================
 Name        : caminho.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	// Verifica se o número de argumentos é válido
    if (argc != 2)
    {
        exibirUtilizacao();
        return 0;
    }

    // Obtém o nome do arquivo a partir do segundo argumento
    char* nome_arquivo = argv[1];
    GrafoInfo grafo_info;
    Arco* arcos;
    Caminho* caminho_minimo;

    // Lê as informações do grafo do arquivo
    lerArquivo(nome_arquivo, &grafo_info, &arcos);

    // Aloca memória para a matriz de distâncias
    int num_cidades = grafo_info.num_cidades;
    int** matriz_distancias = (int**)malloc(num_cidades * sizeof(int*));

    if (matriz_distancias == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        liberarMemoria(matriz_distancias, arcos, caminho_minimo);
        exit(1);
    }

    // Inicializa a matriz de distâncias com valores infinitos
    for (int i = 0; i < num_cidades; i++)
    {
        matriz_distancias[i] = (int*)malloc(num_cidades * sizeof(int));

        if (matriz_distancias[i] == NULL)
        {
            printf("Erro ao alocar memoria.\n");
            liberarMemoria(matriz_distancias, arcos, caminho_minimo);
            exit(1);
        }
    }

    for (int i = 0; i < num_cidades; i++)
    {
        for (int j = 0; j < num_cidades; j++)
        {
            matriz_distancias[i][j] = i == j ? 0 : INFINITY;
        }
    }

    // Preenche a matriz de distâncias com os valores dos arcos
    for (int i = 0; i < num_cidades; i++)
    {
        matriz_distancias[arcos[i].cidade1 - 1][arcos[i].cidade2 - 1] = arcos[i].distancia;
    }

    // Executa o algoritmo de Dijkstra para encontrar o caminho mínimo
    dijkstra(matriz_distancias, num_cidades, grafo_info.origem, grafo_info.destino, &caminho_minimo);

    // Exibe o caminho mínimo encontrado
    exibirCaminhoMinimo(caminho_minimo, num_cidades, grafo_info.origem, grafo_info.destino);

    // Libera a memória alocada
    liberarMemoria(matriz_distancias, arcos, caminho_minimo);

    return 0;
}
