#include "racionais.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
/* acrescente demais includes que voce queira ou precise */

/* 
 * Implemente aqui as funcoes definidas no racionais.h.
 * Caso queira, você pode definir neste arquivo funcoes
 * adicionais que serao internas a este arquivo.
 *
 * Por exemplo, as funções aleat, mdc e mmc devem ser
 * implementadas neste arquivo.
*/

/* retorna um numero aleatorio entre min e max, inclusive. */
int aleat (int min, int max){
    return (min + rand() % (max - min + 1));
}

/* Maximo Divisor Comum entre a e b      */
/* calcula o mdc pelo metodo de Euclides */
int mdc (int a, int b){
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

/* Minimo Multiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
int mmc (int a, int b){
    return a * (b / mdc(a, b));
}

struct racional cria_r(int numerador, int denominador)
{
    struct racional r;
    r.num = numerador;
    r.den = denominador;
    if (r.den == 0)
    {
        r.valido = 0;
        return r;
    }
    return r;
}

struct racional sorteia_r(int n)
{
    struct racional r;
    r.num = aleat(0, n);
    r.den = aleat(0, n);
    if (r.den == 0)
    {
        r.valido = 0;
    }
    simplifica_r(&r);
    return r;
}

int simplifica_r(struct racional *r)
{
    int maiorDivisor = mdc(r->num, r->den);
    r->num = r->num / maiorDivisor;
    r->den = r->den / maiorDivisor;
    return 1;
}

void imprime_r(struct racional r)
{
    if ((r.num == 0) || (r.den == 1))
    {
        printf("%d  ", r.num);
        return;
    }
    if ((r.den == (-1)) && (r.num > 0))
    {
        printf("%d ", r.num*(-1));
    }
    if ((r.den < (-1)) && (r.num < 0))
    {
        printf("%d/%d ", r.num*(-1), r.den*(-1));
    }
    if ((r.den < (-1)) && (r.num > 0))
    {
        printf("%d/%d ", r.num*(-1), r.den*(-1));
    }
    else
    {
        printf("%d/%d ", r.num, r.den);
    }
}

int valido_r(struct racional r)
{
    return (r.den != 0);
}

int soma_r(struct racional r1, struct racional r2, struct racional *r3)
{
    int minMC = mmc(r1.den, r2.den);
    r3->num = minMC/r1.den*r1.num + minMC/r2.den*r2.num;
    r3->den = minMC;
    simplifica_r(r3);
    return 1;
}
int subtrai_r(struct racional r1, struct racional r2, struct racional *r3)
{
    int minMC = mmc(r1.den, r2.den);
    r3->num = minMC/r1.den*r1.num - minMC/r2.den*r2.num;
    r3->den = minMC;
    simplifica_r(r3);
    return 1;
}

int multiplica_r(struct racional r1, struct racional r2, struct racional *r3)
{
    r3->num = r1.num * r2.num;
    r3->den = r1.den * r2.den;
    simplifica_r(r3);
    return 1;
}

int divide_r(struct racional r1, struct racional r2, struct racional *r3)
{
    r3->num = r1.num * r2.den;
    r3->den = r1.den * r2.num;
    if (r3->den == 0)
    {
        r3->valido = 0;
        return 0;
    }
    simplifica_r(r3);
    return 1;
}

int compara_r (struct racional r1, struct racional r2)
{
    int MMC = mmc(r1.den, r2.den);
    int num1 = MMC/r1.den*r1.num;
    int num2 = MMC/r2.den*r2.num;
    if (num1 == num2)
    {
        return 0;
    }
    if (num1 > num2)
    {
        return 1;
    }
    return -1;
}

int numerador_r (struct racional r)
{
    return r.num;
}

/* Retorna o denominador de um racional */
int denominador_r (struct racional r)
{
    return r.den;
}

void criar_vetor(struct racional vetor[], int tam)
{
    for (int i=0; i <= tam-1; i++)
    {
        vetor[i] = sorteia_r(123);
    }
}

void imprimir_vetor(struct racional vetor[], int tam)
{
    for (int i=0; i <= tam-1; i++)
    {
        imprime_r(vetor[i]);
    }
    printf("\n");
}

void ordenar_vetor(struct racional vetor[], int tam)
{
    struct racional menor = vetor[0];
    for (int i = 0; i <=tam-2; i++)
    {
        if (compara_r(vetor[i], vetor[i+1]) == (1))
        {
            menor = vetor[i+1];
            vetor[i+1] = vetor[i];
            vetor[i] = menor;
        }
    }
}