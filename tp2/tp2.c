/* Arquivo MAIN que usa o TAD racionais */

/* coloque seus includes aqui */
#include "racionais.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX 100

int n;
struct racional v[MAX];
struct racional soma;


int main (){

    /* coloque seu codido aqui */
    srand(0);

    scanf("%d", &n);

    criar_vetor(v, n);
    imprimir_vetor(v, n);
    elimina_invalido(v, &n);
    imprimir_vetor(v, n);
    ordenar_vetor(v, n);
    imprimir_vetor(v, n);
    soma_e_imprime_vetor(v, n, &soma);
    return 0;
}