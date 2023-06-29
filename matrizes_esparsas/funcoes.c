/*
 * funcoes.c
 *
 *  Created on: 16 de jun. de 2023
 *      Author: Alexandro Silva
 */

#include "lista.h"
#include "matriz.h"

/* Função para alocar memória para o primeiro nó da lista. Define o último nó como sendo o primeiro nó e define os ponteiros direita e abaixo do primeiro nó como NULL.*/
void cria(LISTA* lista) 
{
   lista->primeiro = (PONT) malloc(sizeof(CELULA));
   lista->ultimo = lista->primeiro;
   lista->primeiro->direita = NULL;
   lista->primeiro->abaixo = NULL;
}

/* Função que cria uma nova célula, define os ponteiros direita e abaixo da nova célula e atualiza os ponteiros da posição atual */
int insereLinha(LISTA* lista, PONT posicao) 
{
   if (posicao == NULL || posicao == lista->ultimo) return 0;

   PONT novaCelula = (PONT) malloc(sizeof(CELULA));
   novaCelula->direita = posicao->direita;
   novaCelula->abaixo = posicao->abaixo;
   posicao->direita = novaCelula;
   posicao->abaixo = novaCelula;

   return 1;
}

/* Função para criar uma nova célula, definir os ponteiros direita da nova célula, atualiza o ponteiro da posição atual para a nova célula e define o ponteiro abaixo da nova célula com base no ponteiro da posição atual */
int insereColuna(LISTA* lista, PONT posicao) 
{
   if (posicao == NULL || posicao == lista->ultimo) return 0;

   PONT novaCelula = (PONT) malloc(sizeof(CELULA));
   novaCelula->direita = posicao->direita;
   posicao->direita = novaCelula;
   novaCelula->abaixo = posicao->abaixo;
   posicao = novaCelula;

   return 1;
}

/* Essa função irá pegar a posição inicial da linha, percorrer a linha e imprimir as células correspondentes */
void imprimeLinha(LISTA* lista, int linha) 
{
   PONT posicao = lista->primeiro->direita;

   while (posicao != NULL) {
      if (posicao->item.linha == linha) {
         printf("Coluna: %d, Valor: %.2lf\n", posicao->item.coluna, posicao->item.valor);
      }
      posicao = posicao->direita;
   }
}

/* Função para inicializar a estrutura de dados da matriz, definindo o número de linhas e colunas como zero e atribuindo NULL aos ponteiros linha e coluna. */
void criaMatriz(MATRIZ* matriz) 
{
   matriz->nLinhas = 0;
   matriz->nColunas = 0;
   matriz->linha = NULL;
   matriz->coluna = NULL;
}

/*Essa função vai inserir um elemento na matriz, armazenando o valor na posição especificada pelas coordenadas linha e coluna. Ela também atualiza os valores de nLinhas e nColunas 
caso sejam maiores do que os valores anteriores. A função aloca memória e inicializa as listas de linhas e colunas se necessário. */
void insereMatriz(MATRIZ* matriz, int linha, int coluna, double valor) 
{
   if (linha > matriz->nLinhas)
   {
      matriz->nLinhas = linha;
   }
   if (coluna > matriz->nColunas)
   {
      matriz->nColunas = coluna;
   }
   if (matriz->linha == NULL) 
   {
      matriz->linha = (LISTA*) malloc((linha + 1) * sizeof(LISTA));

      for (int i = 0; i <= linha; i++)
      {
         cria(&matriz->linha[i]);
      }
   }
   if (matriz->coluna == NULL) 
   {
      matriz->coluna = (LISTA*) malloc((coluna + 1) * sizeof(LISTA));

      for (int i = 0; i <= coluna; i++)
      {
         cria(&matriz->coluna[i]);
      }
   }
   ITEM item;
   item.linha = linha;
   item.coluna = coluna;
   item.valor = valor;

   insereLinha(&matriz->linha[linha], matriz->linha[linha].ultimo);
   insereColuna(&matriz->coluna[coluna], matriz->coluna[coluna].ultimo);
}

/*Função para verificar se a matriz está vazia, ou seja, se o número de linhas ou colunas é igual a zero. Retorna 1 se a matriz estiver vazia e 0 caso contrário. */
int vaziaMatriz(MATRIZ* matriz) 
{
   return matriz->nLinhas == 0 || matriz->nColunas == 0;
}

/* Essa função lê os valores de entrada do usuário para preencher a matriz. Ela solicita o número de linhas e colunas da matriz e, em seguida,
solicita os elementos da matriz por meio de um loop de entrada. Ela chama a função insereMatriz para inserir os valores não nulos na matriz. */
void leMatriz(MATRIZ* matriz) 
{
   int linha, coluna;
   double valor;

   printf("Digite o número de linhas da matriz: ");
   scanf("%d", &matriz->nLinhas);
   printf("Digite o número de colunas da matriz: ");
   scanf("%d", &matriz->nColunas);

   printf("Digite os elementos da matriz (linha coluna valor):\n");

   for (linha = 0; linha < matriz->nLinhas; linha++) 
   {
      for (coluna = 0; coluna < matriz->nColunas; coluna++) 
      {
         scanf("%lf", &valor);
         if (valor != 0)
         {
            insereMatriz(matriz, linha, coluna, valor);
         }
      }
   }
}

/* Função que calcula a soma de duas matrizes matriz1 e matriz2. Ela verifica se as matrizes têm o mesmo número de linhas e colunas antes de realizar a soma.
A matriz de resultado é inicializada chamando a função criaMatriz. Os elementos não nulos são somados individualmente e inseridos na matriz de resultado usando a função insereMatriz. */
void somaMatriz(MATRIZ* matriz1, MATRIZ* matriz2, MATRIZ* resultado) 
{
   if (matriz1->nLinhas != matriz2->nLinhas || matriz1->nColunas != matriz2->nColunas) 
   {
      printf("Erro: As matrizes devem ter o mesmo número de linhas e colunas para somar.\n");
      return;
   }
   criaMatriz(resultado);

   for (int linha = 0; linha < matriz1->nLinhas; linha++) 
   {
      for (int coluna = 0; coluna < matriz1->nColunas; coluna++) 
      {
         double valor1 = 0, valor2 = 0;
         PONT celula1 = matriz1->linha[linha].primeiro->direita;
         PONT celula2 = matriz2->linha[linha].primeiro->direita;

         while (celula1 != NULL) 
         {
            if (celula1->item.coluna == coluna) 
            {
               valor1 = celula1->item.valor;
               break;
            }
            celula1 = celula1->direita;
         }
         while (celula2 != NULL) 
         {
            if (celula2->item.coluna == coluna) 
            {
               valor2 = celula2->item.valor;
               break;
            }
            celula2 = celula2->direita;
         }
         double soma = valor1 + valor2;
         if (soma != 0)
         {
            insereMatriz(resultado, linha, coluna, soma);
         }
      }
   }
}

/*Função para calcular o produto de duas matrizes matriz1 e matriz2. Ela verifica se o número de colunas da matriz1 é igual ao número de linhas da matriz2
//antes de realizar a multiplicação. A matriz de resultado é inicializada chamando a função criaMatriz. Os elementos do produto são calculados e inseridos na matriz de resultado usando a função insereMatriz. */
void multiplicaMatriz(MATRIZ* matriz1, MATRIZ* matriz2, MATRIZ* resultado) 
{
   if (matriz1->nColunas != matriz2->nLinhas) 
   {
      printf("Erro: O número de colunas da matriz1 deve ser igual ao número de linhas da matriz2 para multiplicar.\n");
      return;
   }
   criaMatriz(resultado);

   for (int linha = 0; linha < matriz1->nLinhas; linha++) 
   {
      for (int coluna = 0; coluna < matriz2->nColunas; coluna++) 
      {
         double valor = 0;

         for (int k = 0; k < matriz1->nColunas; k++) 
         {
            PONT celula1 = matriz1->linha[linha].primeiro->direita;
            PONT celula2 = matriz2->coluna[coluna].primeiro->direita;

            while (celula1 != NULL && celula1->item.coluna != k)
            {
               celula1 = celula1->direita;
            }
            while (celula2 != NULL && celula2->item.linha != k)
            {
               celula2 = celula2->abaixo;
            }
            if (celula1 != NULL && celula2 != NULL)
            {
               valor += celula1->item.valor * celula2->item.valor;
            }
         }
         if (valor != 0)
         {
            insereMatriz(resultado, linha, coluna, valor);
         }
      }
   }
}

/* Função que imprime os elementos da matriz. Primeiro, ela verifica se a matriz está vazia. Em seguida, itera sobre cada linha da matriz e chama a função imprimeLinha para imprimir os elementos não nulos dessa linha. */
void imprimeMatriz(MATRIZ* matriz) 
{
   if (vaziaMatriz(matriz)) 
   {
      printf("A matriz está vazia.\n");
      return;
   }
   printf("Matriz (%d x %d):\n", matriz->nLinhas, matriz->nColunas);

   for (int linha = 0; linha < matriz->nLinhas; linha++)
   {
      imprimeLinha(&matriz->linha[linha], linha);
   }
   printf("\n");
}

//Função para remover um nó de uma lista encadeada simples
void apaga(PONT *p) 
{
   PONT aux = *p;
   *p = (*p)->direita;
   free(aux);
}

/*Função para liberar a memória alocada para as listas de linhas e colunas da matriz, além de redefinir o número de linhas e colunas como zero.
//Ela chama a função apaga para liberar cada lista individualmente e, em seguida, libera a memória dos ponteiros linha e coluna usando free. */
void apagaMatriz(MATRIZ* matriz) 
{
   if (matriz->linha != NULL) 
   {
      for (int i = 0; i <= matriz->nLinhas; i++)
      {
         apaga(&matriz->linha[i]);
      }
      free(matriz->linha);
      matriz->linha = NULL;
   }
   if (matriz->coluna != NULL) 
   {
      for (int i = 0; i <= matriz->nColunas; i++)
      {
         apaga(&matriz->coluna[i]);
      }
      free(matriz->coluna);
      matriz->coluna = NULL;
   }
   matriz->nLinhas = 0;
   matriz->nColunas = 0;
}

//Função para ler os elementos de uma matriz a partir de um arquivo de texto
void leMatrizFromFile(MATRIZ* matriz, const char* filename) 
{
   FILE* file = fopen(filename, "r");
   if (file == NULL) 
   {
      printf("Erro ao abrir o arquivo\n");
      return;
   }
   int nLinhas, nColunas;

   fscanf(file, "%d %d", &nLinhas, &nColunas);
   criaMatriz(matriz);
   matriz->nLinhas = nLinhas;
   matriz->nColunas = nColunas;

   int linha, coluna;
   double valor;

   while (fscanf(file, "%d %d %lf", &linha, &coluna, &valor) == 3) 
   {
      insereMatriz(matriz, linha, coluna, valor);
   }
   fclose(file);
}
