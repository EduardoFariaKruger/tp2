#include <stdio.h>
#include <stdbool.h>

#define N 3

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para verificar se é seguro colocar uma dama em tabuleiro[l][c]
bool eSeguro(int tabuleiro[N][N], int l, int c) {
    // Verificar a linha na esquerda
    for (int i = 0; i < c; i++) {
        if (tabuleiro[l][i] == 1) {
            return false;
        }
    }

    // Verificar a diagonal superior na esquerda
    for (int i = l, j = c; i >= 0 && j >= 0; i--, j--) {
        if (tabuleiro[i][j] == 1) {
            return false;
        }
    }

    // Verificar a diagonal inferior na esquerda
    for (int i = l, j = c; i < N && j >= 0; i++, j--) {
        if (tabuleiro[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Função para resolver o problema das Damas usando backtracking
bool resolverDamas(int tabuleiro[N][N], int coluna) {
    if (coluna >= N) {
        // Todas as damas estão colocadas, a solução é válida
        imprimirTabuleiro(tabuleiro);
        return true;
    }

    // Tentar colocar uma dama em cada linha na coluna atual
    for (int i = 0; i < N; i++) {
        if (eSeguro(tabuleiro, i, coluna)) {
            // Colocar a dama e recursivamente tentar a próxima coluna
            tabuleiro[i][coluna] = 1;

            // Se a recursão encontrar uma solução, retornar true
            if (resolverDamas(tabuleiro, coluna + 1)) {
                return true;
            }

            // Se a recursão não encontrar uma solução, retroceder e tentar outra linha
            tabuleiro[i][coluna] = 0;
        }
    }

    // Se nenhuma linha funcionar nesta coluna, retornar false
    return false;
}

// Função principal
int main() {
    int tabuleiro[N][N] = {0};

    if (!resolverDamas(tabuleiro, 0)) {
        printf("Não há solução possível.\n");
    }

    return 0;
}
