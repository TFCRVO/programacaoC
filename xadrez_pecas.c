#include <stdio.h>

int main() {
    // Movimento da Torre: 5 casas para a direita usando for
    printf("Movimento da Torre (5 casas para a Direita):\n");
    
    // Usando o loop for para repetir o movimento da torre
    for (int i = 1; i <= 5; i++) {
        printf("Direita\n");
    }

    printf("\n");

    // Movimento do Bispo: 5 casas na diagonal (Cima Direita) usando while
    printf("Movimento do Bispo (5 casas na Diagonal para Cima e Direita):\n");

    // Variável de controle para o loop while
    int j = 1;

    // Usando while para repetir o movimento diagonal do bispo
    while (j <= 5) {
        printf("Cima Direita\n");
        j++;
    }

    printf("\n");

    // Movimento da Rainha: 8 casas para a esquerda usando do-while
    printf("Movimento da Rainha (8 casas para a Esquerda):\n");

    // Variável de controle para o loop do-while
    int k = 1;

    // Usando do-while para repetir o movimento da rainha
    do {
        printf("Esquerda\n");
        k++;
    } while (k <= 8);

    return 0;
}