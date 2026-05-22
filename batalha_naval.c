#include <stdio.h>
#include <locale.h>

// Definindo o tamanho do tabuleiro e o tamanho do navio
#define TAM 10
#define NAVIO 3

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, char orientacao) {
    for (int i = 0; i < NAVIO; i++) {
        if (orientacao == 'H') { // Horizontal
            tabuleiro[linha][coluna + i] = NAVIO;
        } else if (orientacao == 'V') { // Vertical
            tabuleiro[linha + i][coluna] = NAVIO;
        }else if (orientacao == 'D') { // Diagonal
            tabuleiro[linha + i][coluna + i] = NAVIO;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Pt-BR.UTF-8");

    int tabuleiro[TAM][TAM] = {0}; // Tabuleiro inicializado com zeros
    char letra[TAM] = {'A','B','C','D','E','F','G','H','I','J'};
    char *numero[TAM] = {"0","1","2","3","4","5","6","7","8","9"};

    // Chama a função para posicionar os navios no tabuleiro H = horizontal, V = vertical e D = diagonal
    posicionarNavio(tabuleiro, 0, 9, 'V');
    posicionarNavio(tabuleiro, 3, 0, 'D');
    posicionarNavio(tabuleiro, 0, 1, 'D');
    posicionarNavio(tabuleiro, 5, 4, 'H');

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
