/* Arquivo MAIN que usa o TAD racionais */

/* coloque seus includes aqui */
#include "racionais.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX 100


/*Gera um vetor de tam posições que contenha números do tipo racional*/
void criar_vetor(struct racional vetor[], int tam)
{
    for (int i=0; i <= tam-1; i++)
    {
        vetor[i] = sorteia_r(10);
    }
}

/*imprime os elementos de um vetor de racionais*/
void imprimir_vetor(struct racional vetor[], int tam)
{
    for (int i=0; i <= tam-1; i++)
    {
        imprime_r(vetor[i]);
    }
    printf("\n");
}

/*ordena um vetor de racionais do menor para o maior*/
void ordenar_vetor(struct racional vetor[], int tam)
{
    for (int i = 0; i <=tam-1; i++)
    {
        int menor = i;
        for (int j = i + 1; j <= tam-1; j++)
        {
            if (compara_r(vetor[j], vetor[menor]) == -1)
            {
                menor = j;
            }
        }
        struct racional aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
}

/*identifica e elimina todos os números racionais inválidos dentro do vetor*/
void elimina_invalido(struct racional vetor[], int *tam)
{
    for (int i = 0; i <= *tam -1; i ++)
    {
        if (vetor[i].valido == 0)
        {
            for (int j = i; j <= *tam -2; j++)
            {
                vetor[j] = vetor[j+1];
            }
            *tam = *tam - 1;
        }
    }
}

/*realiza a operação de soma de todos os elementos do vetor e imprime esse resultado na tela*/
void soma_e_imprime_vetor(struct racional vetor[], int tam)
{
    struct racional soma = cria_r(0, 1);
    for (int i = 0; i <= tam-1; i++)
    {
        soma_r(soma, vetor[i], &soma);
    }
    printf("A soma de todos os elementos do vetor eh: ");
    imprime_r(soma);
    printf("\n");
}


int main (){
    
    int n;
    struct racional v[MAX];

    /*geração da semente aleatória*/
    srand(0);

    /*leitura do tamanho do vetor*/
    scanf("%d", &n);

    /*criação do vetor de N posições e impressão deste*/
    criar_vetor(v, n);
    imprimir_vetor(v, n);

    /*eliminação de todos os elementos inválidos (denominador = 0) e a impressão deste vetor "limpo"*/
    elimina_invalido(v, &n);
    imprimir_vetor(v, n);

    /*Ordenação do vetor do menor para o maior e a impressão desse vetor ordenado*/
    ordenar_vetor(v, n);
    imprimir_vetor(v, n);

    /*Impressão da soma de todos os elementos do vetor*/
    soma_e_imprime_vetor(v, n);
    return 0;
}