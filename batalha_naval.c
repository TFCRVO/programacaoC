#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define TAM_HAB 5  // Tamanho fixo para matrizes de habilidade (5x5)

// Função para verificar sobreposição
int verificarSobreposicao(int tabuleiro[TAM][TAM], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[linha[i]][coluna[i]] == 3) {
            return 1; // Sobreposição detectada
        }
    }
    return 0;
}

// Função para posicionar navios no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int linha[], int coluna[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha[i]][coluna[i]] = 3;
    }
}

// Função para aplicar uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int tabLinha = origemLinha - TAM_HAB/2 + i;
            int tabColuna = origemColuna - TAM_HAB/2 + j;
            // Verifica se está dentro dos limites do tabuleiro
            if (tabLinha >= 0 && tabLinha < TAM && tabColuna >= 0 && tabColuna < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[tabLinha][tabColuna] == 0) {
                    tabuleiro[tabLinha][tabColuna] = 5; // Marca área afetada
                }
            }
        }
    }
}

// Funções para construir matrizes de habilidade
void construirCone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Cria uma forma triangular apontando para baixo
            if (j >= (TAM_HAB/2 - i) && j <= (TAM_HAB/2 + i))
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

void construirCruz(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

void construirOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Cria um losango (vista frontal de um octaedro)
            if (abs(i - TAM_HAB/2) + abs(j - TAM_HAB/2) <= TAM_HAB/2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro Final:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) printf(". ");
            else if (tabuleiro[i][j] == 3) printf("N ");
            else if (tabuleiro[i][j] == 5) printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // -------------------- POSICIONAMENTO DOS NAVIOS --------------------

    // Horizontal
    int l1 = 1, c1 = 2;
    int linha1[TAM_NAVIO], coluna1[TAM_NAVIO];
    for (int i = 0; i < TAM_NAVIO; i++) {
        linha1[i] = l1;
        coluna1[i] = c1 + i;
    }

    // Vertical
    int l2 = 5, c2 = 5;
    int linha2[TAM_NAVIO], coluna2[TAM_NAVIO];
    for (int i = 0; i < TAM_NAVIO; i++) {
        linha2[i] = l2 + i;
        coluna2[i] = c2;
    }

    // Diagonal ↘
    int l3 = 0, c3 = 0;
    int linha3[TAM_NAVIO], coluna3[TAM_NAVIO];
    for (int i = 0; i < TAM_NAVIO; i++) {
        linha3[i] = l3 + i;
        coluna3[i] = c3 + i;
    }

    // Diagonal ↙
    int l4 = 0, c4 = 9;
    int linha4[TAM_NAVIO], coluna4[TAM_NAVIO];
    for (int i = 0; i < TAM_NAVIO; i++) {
        linha4[i] = l4 + i;
        coluna4[i] = c4 - i;
    }

    // Verificação de sobreposição
    if (verificarSobreposicao(tabuleiro, linha1, coluna1, TAM_NAVIO) ||
        verificarSobreposicao(tabuleiro, linha2, coluna2, TAM_NAVIO) ||
        verificarSobreposicao(tabuleiro, linha3, coluna3, TAM_NAVIO) ||
        verificarSobreposicao(tabuleiro, linha4, coluna4, TAM_NAVIO)) {
        printf("Erro: sobreposição de navios detectada.\n");
        return 1;
    }

    // Posicionar navios
    posicionarNavio(tabuleiro, linha1, coluna1, TAM_NAVIO);
    posicionarNavio(tabuleiro, linha2, coluna2, TAM_NAVIO);
    posicionarNavio(tabuleiro, linha3, coluna3, TAM_NAVIO);
    posicionarNavio(tabuleiro, linha4, coluna4, TAM_NAVIO);

    // -------------------- HABILIDADES ESPECIAIS --------------------

    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // Aplicar habilidades em posições fixas
    aplicarHabilidade(tabuleiro, cone, 2, 4);       // Cone centrado em (2,4)
    aplicarHabilidade(tabuleiro, cruz, 6, 6);       // Cruz centrado em (6,6)
    aplicarHabilidade(tabuleiro, octaedro, 8, 2);   // Octaedro centrado em (8,2)

    // -------------------- IMPRIMIR O TABULEIRO FINAL --------------------
    imprimirTabuleiro(tabuleiro);

    return 0;
}