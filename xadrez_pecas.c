#include <stdio.h>

int main() {
    // Movimento da Torre: 5 casas para a Direita
    printf("Movimento da Torre (5 casas para a Direita):\n");

    // Usando loop for para mover a torre
    for (int i = 1; i <= 5; i++) {
        printf("Direita\n");
    }

    printf("\n");

    // Movimento do Bispo: 5 casas na diagonal Cima Direita
    printf("Movimento do Bispo (5 casas na Diagonal para Cima e Direita):\n");

    int j = 1; // contador para o loop while
    while (j <= 5) {
        printf("Cima Direita\n");
        j++;
    }

    printf("\n");

    // Movimento da Rainha: 8 casas para a Esquerda
    printf("Movimento da Rainha (8 casas para a Esquerda):\n");

    int k = 1; // contador para o loop do-while
    do {
        printf("Esquerda\n");
        k++;
    } while (k <= 8);

    printf("\n");

    // Movimento do Cavalo: 2 casas para Baixo, 1 para a Esquerda (em "L")
    printf("Movimento do Cavalo (em 'L': 2 casas para Baixo e 1 para a Esquerda):\n");

    // Loop externo com for: controla as duas casas para baixo
    for (int passo_baixo = 1; passo_baixo <= 2; passo_baixo++) {
        printf("Baixo\n"); // imprime a movimentação vertical
    }

    // Loop interno com while: controla o movimento horizontal de 1 casa para a esquerda
    int passo_esquerda = 1;
    while (passo_esquerda <= 1) {
        printf("Esquerda\n"); // imprime a movimentação horizontal
        passo_esquerda++;
    }

    return 0;
}