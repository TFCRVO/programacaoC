#include <stdio.h>

// Função recursiva para movimentar a Torre para a Direita
void moverTorre(int casas) {
    if (casas <= 0) return; // condição de parada
    printf("Direita\n");
    moverTorre(casas - 1); // chamada recursiva
}

// Função recursiva para movimentar o Bispo para Cima Direita
void moverBispoRecursivo(int casas) {
    if (casas <= 0) return;
    printf("Cima Direita\n");
    moverBispoRecursivo(casas - 1);
}

// Função recursiva para movimentar a Rainha para a Esquerda
void moverRainha(int casas) {
    if (casas <= 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// Movimento do Cavalo em "L": 2 para cima e 1 para direita com loops aninhados
void moverCavaloComplexo() {
    printf("Movimento do Cavalo (em 'L': 2 casas para Cima e 1 para a Direita):\n");

    int movimentosRealizados = 0;

    // Loop externo para movimento vertical (Cima)
    for (int i = 0; i < 3; i++) {
        if (i >= 2) {
            // Quando já foram feitas 2 casas para cima, interrompe o loop vertical
            break;
        }

        printf("Cima\n");
        movimentosRealizados++;

        // Loop interno para verificar se já fez os dois passos para cima
        for (int j = 0; j < 2; j++) {
            if (movimentosRealizados < 2) {
                // Continue enquanto não alcançar 2 casas para cima
                continue;
            } else {
                // Após as 2 casas para cima, faz 1 para a direita
                printf("Direita\n");
                break;
            }
        }
    }

    printf("\n");
}

// Bispo com loops aninhados: vertical (fora), horizontal (dentro)
void moverBispoLoops(int casas) {
    printf("Movimento do Bispo com loops aninhados (Cima Direita):\n");

    // Cada iteração representa uma casa diagonal
    for (int i = 1; i <= casas; i++) {
        for (int j = 1; j <= 1; j++) { // sempre 1 passo horizontal para cada vertical
            printf("Cima Direita\n");
        }
    }

    printf("\n");
}

int main() {
    // Movimento da Torre usando recursão
    printf("Movimento da Torre (5 casas para a Direita):\n");
    moverTorre(5);
    printf("\n");

    // Movimento do Bispo usando recursão
    printf("Movimento do Bispo (5 casas para a Diagonal Cima Direita - Recursivo):\n");
    moverBispoRecursivo(5);
    printf("\n");

    // Movimento da Rainha usando recursão
    printf("Movimento da Rainha (8 casas para a Esquerda):\n");
    moverRainha(8);
    printf("\n");

    // Movimento complexo do Cavalo
    moverCavaloComplexo();

    // Movimento do Bispo com loops aninhados
    moverBispoLoops(5);

    return 0;
}