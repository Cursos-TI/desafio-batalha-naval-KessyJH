#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Pt-BR.UTF-8");

    int tabluleiro[10][10] = {0}; // Tabuleiro de 10x10, inicializado com zeros
    int navio[3][1] = {{1}, {1}, {1}};
    char letra[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char *numero[10] = {"1","2","3","4","5","6","7","8","9","10"};


    //Exibindo o tabuleiro

    printf("Tabuleiro de Batalha Naval:\n");
    printf("  ");

    //Posiciona o navio no tabuleiro.
    for (int i = 0; i < 3; i++) {
        tabluleiro[i][0] = navio[i][0]; // Posiciona o navio na primeira coluna do tabuleiro
        tabluleiro[i][2] = navio[i][1]; // Posiciona o navio na segunda coluna do tabuleiro
        tabluleiro[i][4] = navio[i][1]; // Posiciona o navio na terceira coluna do tabuleiro
    }
    for (int k = 0; k < 10; k++) {
        printf(" %2c", letra[k]);// Exibe as letras de A a J no topo do tabuleiro
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%2s|", numero[i]);
        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabluleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}