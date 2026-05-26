#include <stdio.h>
#include <locale.h>
#include <conio.h>

// Definindo o tamanho do tabuleiro e o tamanho do navio
#define TAM 10
#define NAVIO 3 

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, char orientacao) {
    for (int i = 0; i < NAVIO; i++) {
        if (orientacao == 'H' && coluna <= 7) { // Horizontal
            tabuleiro[linha][coluna + i] = NAVIO;
        } else if (orientacao == 'V' && linha <= 7) { // Vertical
            tabuleiro[linha + i][coluna] = NAVIO;
        }else if (orientacao == 'D' && linha <= 7 && coluna <= 7) { // Diagonal
            tabuleiro[linha + i][coluna + i] = NAVIO;
        }else {
            printf("Posição inválida para o navio. Tente novamente.\n");
            return;// Se a posição for inválida, a função retorna sem posicionar o navio
        }
    }
}

int main() {
    setlocale(LC_ALL, "Pt-BR.UTF-8");

    int tabuleiro[TAM][TAM];
    char letra[TAM] = {'A','B','C','D','E','F','G','H','I','J'};

    // Chama a função para posicionar os navios no tabuleiro H = horizontal, V = vertical e D = diagonal
    posicionarNavio(tabuleiro, 7, 9, 'V');
    posicionarNavio(tabuleiro, 3, 0, 'D');
    posicionarNavio(tabuleiro, 0, 1, 'D');
    posicionarNavio(tabuleiro, 5, 4, 'H');

    // Exibindo o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    printf("   ");

    // Imprime as letras das colunas
    for (int k = 0; k < TAM; k++) {
        printf("\x1b[33m %2c\x1b[0m", letra[k]);// Imprime as letras das colunas em azul
    }
    printf("\n");

    // Imprime o tabuleiro com os números das linhas
    for (int i = 0; i < TAM; i++) {
        printf("\x1b[32m %2d\x1b[0m|", i);// Imprime os números das linhas em verde
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == NAVIO) {
            // Navio em vermelho
                printf(" \x1b[31m%d\x1b[0m ", NAVIO);
            } else {
            // Mar em azul com símbolo 0
                printf(" \x1b[36m0\x1b[0m ");
            }
        }
        printf("\n");
    }

    return 0;
}
