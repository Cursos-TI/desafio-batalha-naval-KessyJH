#include <stdio.h>
#include <locale.h>
#include <conio.h>

// Definindo o tamanho do tabuleiro e o tamanho do navio
#define TAM 10
#define NAVIO 3 
#define HABILIDADECRUZ 5
#define HABILIDADEOCTA 7
#define HABILIDADECONE 8

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
// Funcao para aplicar a habilidade de Cruz
void aplicar_habilidade_cruz (int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (linha <= 9 &&coluna <= 9 && linha > 0 && coluna > 0) {
            tabuleiro[linha + i][coluna] = HABILIDADECRUZ;
            tabuleiro[linha][coluna + j] = HABILIDADECRUZ;
            tabuleiro[linha - i][coluna] = HABILIDADECRUZ;
            tabuleiro[linha][coluna - j] = HABILIDADECRUZ;
            } else {
            printf("Valor invalido\n");
            return;
            }
        }
    }
}
//Funcao para aplicar a habilidade Octagonal
void aplicar_habilidade_octa (int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (linha <= 9 &&coluna <= 9 && linha > 0 && coluna > 0) {
            tabuleiro[linha + i][coluna] = HABILIDADEOCTA;
            tabuleiro[linha][coluna + j] = HABILIDADEOCTA;
            tabuleiro[linha - i][coluna] = HABILIDADEOCTA;
            tabuleiro[linha][coluna - j] = HABILIDADEOCTA;
            } else {
            printf("Valor invalido\n");
            return;
            }
        }
    }
}
//Funcao para aplicar habilidade de Cone
void aplicar_habilidade_cone (int tabuleiro[TAM][TAM], int linha, int coluna) {
     for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {
            if (linha <= 7 && coluna >= 2){
            tabuleiro[linha][coluna] = HABILIDADECONE;
            tabuleiro[linha + i][coluna - j] = HABILIDADECONE;  
            } else {
                printf("Valor invalido\n");
                return;
            } 
        }
    }
}


int main() {
    setlocale(LC_ALL, "Pt-BR.UTF-8");
    int tabuleiro[TAM][TAM] = {0}; // Inicializa o tabuleiro com 0 (mar)
    char letra[TAM] = {'A','B','C','D','E','F','G','H','I','J'};

    // Chama a função para posicionar os navios no tabuleiro H = horizontal, V = vertical e D = diagonal
    posicionarNavio(tabuleiro, 7, 9, 'V');
    posicionarNavio(tabuleiro, 3, 0, 'D');
    posicionarNavio(tabuleiro, 0, 1, 'D');
    posicionarNavio(tabuleiro, 5, 4, 'H');
    //Chama a funcao da habilidade Octagonal
    aplicar_habilidade_octa(tabuleiro, 7, 8);
    //Chama a habilidade de Cruz
    aplicar_habilidade_cruz(tabuleiro, 4, 5);
    //Chama a habilidade de Cone
    aplicar_habilidade_cone(tabuleiro, 7, 2);

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
            } else if (tabuleiro[i][j] == HABILIDADECRUZ) {
            // Área atingida pela habilidade em amarelo
                printf(" \x1b[33m%d\x1b[0m ", HABILIDADECRUZ);
            } else if (tabuleiro[i][j] == HABILIDADEOCTA) {
            // Área atingida pela habilidade em amarelo
                printf(" \x1b[35m%d\x1b[0m ", HABILIDADEOCTA);
            } else if (tabuleiro[i][j] == HABILIDADECONE) {
            // Área atingida pela habilidade em amarelo
                printf(" \x1b[37m%d\x1b[0m ", HABILIDADECONE);
            } else {
            // Mar em azul com símbolo 0
                printf(" \x1b[36m0\x1b[0m ");
            }
        }
        printf("\n");
    }

    return 0;
}
