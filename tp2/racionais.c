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

/*Gera um racional a partir de um numerador e denominadora dados*/
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
    r.valido = 1;
    return r;
}


/*Gera um racional aleatório com os numeradores e denominadores entre o intervalo [0..n]*/
struct racional sorteia_r(int n)
{
    struct racional r;
    r.num = aleat(0, n);
    r.den = aleat(0, n);
    if (r.den == 0)
    {
        r.valido = 0;
    }
    else
    {
        r.valido = 1;
    }
    simplifica_r(&r);
    return r;
}

/*Simplifica um numero racional dividindo tanto o numerador quanto o denominador pelo MDC entre eles*/
int simplifica_r(struct racional *r)
{
    if (valido_r(*r))
    {
        int maiorDivisor = mdc(r->num, r->den);
        r->num = r->num / maiorDivisor;
        r->den = r->den / maiorDivisor;
        return 1;
    }
    else{
        return 0;
    }
}


/*Imprime o número racional no formato "numerador/denominador" considerando os casos:
    * x/x
    * x/1
    * x/0 nesse caso imprime INVALIDO
    * sinal é sempre movido para o numerador 
*/
void imprime_r(struct racional r)
{
    if (!valido_r(r))
    {
        printf("INVALIDO ");
        return;
    }
    else if ((r.num == 0) || (r.den == 1))
    {
        printf("%d ", r.num);
        return;
    }
    else if (((r.num < 0) && (r.num < 0)) || ((r.num > 0) && (r.den < 0)))
    {
        printf("%d/%d ", -r.num, -r.den);
        return;
    }
    printf("%d/%d ", r.num, r.den);
}

/*Retorna 1 se denominador != 0 e 0 se denominador = 0*/
int valido_r(struct racional r)
{
    return (r.den != 0);
}

/*Soma 2 números racionais e salva em um endereço de memória*/
int soma_r(struct racional r1, struct racional r2, struct racional *r3)
{
    int minMC = mmc(r1.den, r2.den);
    r3->num = minMC/r1.den*r1.num + minMC/r2.den*r2.num;
    r3->den = minMC;
    simplifica_r(r3);
    return 1;
}

/*subtrai 2 números racionais e salva em um endereço de memória*/
int subtrai_r(struct racional r1, struct racional r2, struct racional *r3)
{
    int minMC = mmc(r1.den, r2.den);
    r3->num = minMC/r1.den*r1.num - minMC/r2.den*r2.num;
    r3->den = minMC;
    simplifica_r(r3);
    return 1;
}

/*multiplica 2 números racionais e salva em um endereço de memória*/
int multiplica_r(struct racional r1, struct racional r2, struct racional *r3)
{
    r3->num = r1.num * r2.num;
    r3->den = r1.den * r2.den;
    simplifica_r(r3);
    return 1;
}

/*Divide 2 números racionais e salva em um endereço de memória (quem chama a função deve garantir que os operandos são válidos)*/
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

/*Após aplicar um mesmo denominador comum em ambos os racionais, a função compara os numeradores*/
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

/*acessa e retorna o númerador de um número racional*/
int numerador_r (struct racional r)
{
    return r.num;
}

/* acessa e retorna o denominador de um racional */
int denominador_r (struct racional r)
{
    return r.den;
}