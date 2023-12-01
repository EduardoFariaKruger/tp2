#include <stdio.h>

void imprime_vetor(int set[], int v[], int n) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            printf("%d ", set[i]);
        }
    }
    printf("}\n");
}

void bt(int set[], int v[], int n, int i, int B, int currentSum) {
    if (currentSum >= B) {
        return;
    }

    if (i == n) {
        imprime_vetor(set, v, n);
        return;
    }

    v[i] = 0;
    bt(set, v, n, i + 1, B, currentSum);
    v[i] = 1;
    bt(set, v, n, i + 1, B, currentSum + set[i]);
}

void subconjuntos(int set[], int n, int B) {
    int v[n];
    bt(set, v, n, 0, 0, 0);
}

int main() {
    int set[] = {23, 10, 20, 11, 12, 6, 7};
    int n = 7;
    int B = 40; // Exemplo de valor para B
    subconjuntos(set, n, B);
    return 0;
}