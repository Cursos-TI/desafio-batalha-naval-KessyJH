#include <stdio.h>
#include <locale.h>


// Definindo o tamanho do tabuleiro
#define TAM 10

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int tamanho, int linha, int coluna, char orientacao) {
    for (int i = 0; i < tamanho; i++) {
        if (orientacao == 'H') { // Horizontal
            tabuleiro[linha][coluna + i] = 3;
        } else if (orientacao == 'V') { // Vertical
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Pt-BR.UTF-8");

    int tabuleiro[TAM][TAM] = {0}; // Tabuleiro inicializado com zeros
    char letra[TAM] = {'A','B','C','D','E','F','G','H','I','J'};
    char *numero[TAM] = {"1","2","3","4","5","6","7","8","9","10"};

    // Posicionar navio de tamanho 3 na linha 6, coluna 7, vertical
    posicionarNavio(tabuleiro, 3, 3, 6, 'V');

    // Exibindo o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    printf("   ");

    // Imprime as letras das colunas
    for (int k = 0; k < TAM; k++) {
        printf(" %2c", letra[k]);
    }
    printf("\n");

    // Imprime o tabuleiro com os números das linhas
    for (int i = 0; i < TAM; i++) {
        printf(" %2s|", numero[i]);
        for (int j = 0; j < TAM; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
