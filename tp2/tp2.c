/* Arquivo MAIN que usa o TAD racionais */

/* coloque seus includes aqui */
#include "racionais.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX 100

int n;
struct racional v[MAX];


int main (){

    /* coloque seu codido aqui */
    srand(0);

    n = 10;

    criar_vetor(v, n);
    imprimir_vetor(v, n);
    ordenar_vetor(v, n);
    imprimir_vetor(v, n);
    return 0;
}