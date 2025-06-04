#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

// Função para verificar se há sobreposição
int verificarSobreposicao(int tabuleiro[TAM][TAM], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[linha[i]][coluna[i]] == 3) {
            return 1; // Sobreposição detectada
        }
    }
    return 0;
}

// Função para posicionar um navio
void posicionarNavio(int tabuleiro[TAM][TAM], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha[i]][coluna[i]] = 3;
    }
}

int main() {
    // Tabuleiro inicializado com 0 (água)
    int tabuleiro[TAM][TAM] = {0};

    // ----------------------------
    // NAVIO 1 - HORIZONTAL
    // ----------------------------
    int l1 = 1, c1 = 2; // coordenada inicial
    int linha1[TAM_NAVIO], coluna1[TAM_NAVIO];
    for (int i = 0; i < TAM_NAVIO; i++) {
        linha1[i] = l1;
        coluna1[i] = c1 + i;
    }

    // ----------------------------
    // NAVIO 2 - VERTICAL
    // ----------------------------
    int l2 = 5, c2 = 5;
    int linha2[TAM_NAVIO], coluna2[TAM_NAVIO];
    for (int i = 0; i < TAM_NAVIO; i++) {
        linha2[i] = l2 + i;
        coluna2[i] = c2;
    }

    // ----------------------------
    // NAVIO 3 - DIAGONAL ( ↘ )
    // ----------------------------
    int l3 = 0, c3 = 0;
    int linha3[TAM_NAVIO], coluna3[TAM_NAVIO];
    for (int i = 0; i < TAM_NAVIO; i++) {
        linha3[i] = l3 + i;
        coluna3[i] = c3 + i;
    }

    // ----------------------------
    // NAVIO 4 - DIAGONAL ( ↙ )
    // ----------------------------
    int l4 = 0, c4 = 9;
    int linha4[TAM_NAVIO], coluna4[TAM_NAVIO];
    for (int i = 0; i < TAM_NAVIO; i++) {
        linha4[i] = l4 + i;
        coluna4[i] = c4 - i;
    }

    // Validação de sobreposição e posicionamento
    if (verificarSobreposicao(tabuleiro, linha1, coluna1, TAM_NAVIO) ||
        verificarSobreposicao(tabuleiro, linha2, coluna2, TAM_NAVIO) ||
        verificarSobreposicao(tabuleiro, linha3, coluna3, TAM_NAVIO) ||
        verificarSobreposicao(tabuleiro, linha4, coluna4, TAM_NAVIO)) {
        printf("Erro: sobreposição de navios detectada.\n");
        return 1;
    }

    // Posicionamento dos navios
    posicionarNavio(tabuleiro, linha1, coluna1, TAM_NAVIO);
    posicionarNavio(tabuleiro, linha2, coluna2, TAM_NAVIO);
    posicionarNavio(tabuleiro, linha3, coluna3, TAM_NAVIO);
    posicionarNavio(tabuleiro, linha4, coluna4, TAM_NAVIO);

    // Impressão do tabuleiro
    printf("\nTabuleiro Batalha Naval (0 = Água, 3 = Navio):\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}