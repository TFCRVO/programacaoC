#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Matriz que representa o tabuleiro: 0 = água, 3 = parte do navio
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa todas as posições do tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Vetores que representam os navios (conteúdo não importa aqui, só tamanho)
    int navio_horizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_vertical[TAMANHO_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais definidas diretamente no código
    int linha_h = 2, coluna_h = 4; // início do navio horizontal
    int linha_v = 5, coluna_v = 7; // início do navio vertical

    // Validação: garantir que os navios não ultrapassem os limites
    if (coluna_h + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio horizontal fora dos limites!\n");
        return 1;
    }

    if (linha_v + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio vertical fora dos limites!\n");
        return 1;
    }

    // Validação simples: garantir que os navios não se sobreponham
    int sobreposicao = 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_h][coluna_h + i] == 3 ||
            tabuleiro[linha_v + i][coluna_v] == 3) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao) {
        printf("Erro: os navios estão se sobrepondo!\n");
        return 1;
    }

    // Posiciona o navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
    }

    // Posiciona o navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro Batalha Naval (0 = Água, 3 = Navio):\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}