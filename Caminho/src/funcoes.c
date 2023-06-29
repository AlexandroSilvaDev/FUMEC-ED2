/*
 * funcoes.c
 *
 *  Created on: 12 de jun. de 2023
 *      Author: Alexandro Silva
 */

#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>

// Função para exibir a utilização do programa
void exibirUtilizacao()
{
    printf("Utilizacao: caminho <nome>\n");
    printf("<nome>: nome do arquivo contendo as informacoes do grafo\n");
}

// Função para ler o arquivo de entrada e obter as informações do grafo
void lerArquivo(char* nome_arquivo, GrafoInfo* grafo_info, Arco** arcos)
{
	// Abre o arquivo para leitura
	FILE* arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Lê o número de cidades, cidade de origem e cidade de destino
    if (fscanf(arquivo, "%d %d %d\n", &(grafo_info->num_cidades), &(grafo_info->origem), &(grafo_info->destino)) != 3)
    {
        printf("Formato do arquivo incorreto.\n");
        exit(1);
    }

    // Aloca memória para o vetor de arcos
    *arcos = (Arco*)malloc(grafo_info->num_cidades * sizeof(Arco));

    if (*arcos == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    // Lê os arcos do grafo do arquivo
    int i = 0;

    while (fscanf(arquivo, "%d %d %d\n", &((*arcos)[i].cidade1), &((*arcos)[i].cidade2), &((*arcos)[i].distancia)) == 3)
    {
        if ((*arcos)[i].cidade1 == -1 && (*arcos)[i].cidade2 == -1 && (*arcos)[i].distancia == -1)
        {
            break;
        }
        i++;
    }

    // Fecha o arquivo
    fclose(arquivo);
}

// Função para executar o algoritmo de Dijkstra para encontrar o caminho mínimo
void dijkstra(int** matriz_distancias, int num_cidades, int origem, int destino, Caminho** caminho_minimo)
{
	// Aloca memória para os vetores auxiliares
	int* visitado = (int*)malloc(num_cidades * sizeof(int));
    int* distancia = (int*)malloc(num_cidades * sizeof(int));
    int i, j, min_distancia, prox_cidade;

    // Aloca memória para o vetor de caminho mínimo
    *caminho_minimo = (Caminho*)malloc(num_cidades * sizeof(Caminho));

    // Inicializa os vetores auxiliares
    for (i = 0; i < num_cidades; i++)
    {
        visitado[i] = 0;
        distancia[i] = INFINITY;
        (*caminho_minimo)[i].cidade = -1;
        (*caminho_minimo)[i].distancia = INFINITY;
    }

    // Define a distância da origem como 0
    distancia[origem - 1] = 0;
    prox_cidade = origem;

    // Executa o algoritmo de Dijkstra
    while (prox_cidade != destino)
    {
        visitado[prox_cidade - 1] = 1;

        // Atualiza as distâncias e o caminho mínimo
        for (j = 0; j < num_cidades; j++)
        {
            if (!visitado[j] && matriz_distancias[prox_cidade - 1][j] != INFINITY)
            {
                if (distancia[prox_cidade - 1] + matriz_distancias[prox_cidade - 1][j] < distancia[j])
                {
                    distancia[j] = distancia[prox_cidade - 1] + matriz_distancias[prox_cidade - 1][j];
                    (*caminho_minimo)[j].cidade = prox_cidade;
                    (*caminho_minimo)[j].distancia = distancia[j];
                }
            }
        }

        // Encontra a cidade não visitada com a menor distância
        min_distancia = INFINITY;
        for (j = 0; j < num_cidades; j++)
        {
            if (!visitado[j] && distancia[j] < min_distancia)
            {
                min_distancia = distancia[j];
                prox_cidade = j + 1;
            }
        }
    }

    // Libera a memória dos vetores auxiliares
    free(visitado);
    free(distancia);
}

// Função para exibir o caminho mínimo encontrado
void exibirCaminhoMinimo(Caminho* caminho_minimo, int num_cidades, int origem, int destino)
{
    int i, cidade_atual;

    cidade_atual = destino;
    if (caminho_minimo[destino - 1].cidade == -1)
    {
        printf("Nao existe caminho de %d para %d.\n", origem, destino);
        return;
    }
    printf("Caminho de %d para %d: ", origem, destino);

    while (cidade_atual != origem)
    {
        printf("%d(%d) ", cidade_atual, caminho_minimo[cidade_atual - 1].distancia);
        cidade_atual = caminho_minimo[cidade_atual - 1].cidade;
    }
    printf("%d(%d)\n", origem, caminho_minimo[origem - 1].distancia);
}

// Função para liberar a memória alocada
void liberarMemoria(int** matriz_distancias, Arco* arcos, Caminho* caminho_minimo)
{
    free(*matriz_distancias);
    free(arcos);
    free(caminho_minimo);
}
