#include <stdio.h>
#define TAM_MAX 100

int main() {
    // Dados das Cartas (Pré-cadastradas)
    char nomeCidade1[TAM_MAX] = "São Paulo";
    char estado1 = 'S';
    unsigned long int populacao1 = 12300000;
    float area1 = 1521.11;
    float pib1 = 2.2; // em bilhões
    int pontosTuristicos1 = 15;
    float densidadePop1 = populacao1 / area1;
    float pibPerCapita1 = (pib1 * 1000000000) / populacao1;

    char nomeCidade2[TAM_MAX] = "Rio de Janeiro";
    char estado2 = 'R';
    unsigned long int populacao2 = 6700000;
    float area2 = 1200.27;
    float pib2 = 1.4; // em bilhões
    int pontosTuristicos2 = 20;
    float densidadePop2 = populacao2 / area2;
    float pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    int opcao1, opcao2;
    float valor1_c1, valor1_c2;
    float valor2_c1, valor2_c2;
    float soma1, soma2;

    // Exibir menu com os atributos
    printf("\n====== SUPER TRUNFO - NÍVEL MESTRE ======\n");
    printf("Atributos disponíveis:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per Capita\n");

    // Escolha do primeiro atributo
    printf("\nEscolha o primeiro atributo para comparar (1 a 6): ");
    scanf("%d", &opcao1);

    // Verificação da primeira opção
    if (opcao1 < 1 || opcao1 > 6) {
        printf("Opção inválida! Encerrando o programa.\n");
        return 1;
    }

    // Escolha do segundo atributo com menu dinâmico
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != opcao1) {
            switch (i) {
                case 1: printf("%d - População\n", i); break;
                case 2: printf("%d - Área\n", i); break;
                case 3: printf("%d - PIB\n", i); break;
                case 4: printf("%d - Pontos Turísticos\n", i); break;
                case 5: printf("%d - Densidade Demográfica\n", i); break;
                case 6: printf("%d - PIB per Capita\n", i); break;
            }
        }
    }

    printf("Digite sua escolha: ");
    scanf("%d", &opcao2);

    if (opcao2 < 1 || opcao2 > 6 || opcao2 == opcao1) {
        printf("Opção inválida ou repetida! Encerrando o programa.\n");
        return 1;
    }

    // Função auxiliar: seleciona valor da carta com base na opção
    float getValor(int opcao, int carta) {
        switch (opcao) {
            case 1: return carta == 1 ? populacao1 : populacao2;
            case 2: return carta == 1 ? area1 : area2;
            case 3: return carta == 1 ? pib1 : pib2;
            case 4: return carta == 1 ? pontosTuristicos1 : pontosTuristicos2;
            case 5: return carta == 1 ? densidadePop1 : densidadePop2;
            case 6: return carta == 1 ? pibPerCapita1 : pibPerCapita2;
            default: return 0;
        }
    }

    // Captura valores para comparação
    valor1_c1 = getValor(opcao1, 1);
    valor1_c2 = getValor(opcao1, 2);
    valor2_c1 = getValor(opcao2, 1);
    valor2_c2 = getValor(opcao2, 2);

    // Soma final de cada carta (respeitando inversão para densidade)
    float v1_c1 = (opcao1 == 5) ? -valor1_c1 : valor1_c1;
    float v1_c2 = (opcao1 == 5) ? -valor1_c2 : valor1_c2;
    float v2_c1 = (opcao2 == 5) ? -valor2_c1 : valor2_c1;
    float v2_c2 = (opcao2 == 5) ? -valor2_c2 : valor2_c2;

    soma1 = v1_c1 + v2_c1;
    soma2 = v1_c2 + v2_c2;

    // Mostrar resultado
    printf("\n===== RESULTADO DA COMPARAÇÃO =====\n");
    printf("Carta 1 - %s (%c)\n", nomeCidade1, estado1);
    printf("Carta 2 - %s (%c)\n\n", nomeCidade2, estado2);

    printf("Atributo 1: %s\n", 
        opcao1 == 1 ? "População" :
        opcao1 == 2 ? "Área" :
        opcao1 == 3 ? "PIB" :
        opcao1 == 4 ? "Pontos Turísticos" :
        opcao1 == 5 ? "Densidade Demográfica" :
        "PIB per Capita");

    printf(" - %s: %.2f\n", nomeCidade1, valor1_c1);
    printf(" - %s: %.2f\n\n", nomeCidade2, valor1_c2);

    printf("Atributo 2: %s\n", 
        opcao2 == 1 ? "População" :
        opcao2 == 2 ? "Área" :
        opcao2 == 3 ? "PIB" :
        opcao2 == 4 ? "Pontos Turísticos" :
        opcao2 == 5 ? "Densidade Demográfica" :
        "PIB per Capita");

    printf(" - %s: %.2f\n", nomeCidade1, valor2_c1);
    printf(" - %s: %.2f\n\n", nomeCidade2, valor2_c2);

    printf("Soma final dos atributos:\n");
    printf(" - %s: %.2f\n", nomeCidade1, soma1);
    printf(" - %s: %.2f\n", nomeCidade2, soma2);

    // Resultado final com operador ternário
    printf("\nResultado: %s\n", 
        soma1 > soma2 ? nomeCidade1 :
        soma2 > soma1 ? nomeCidade2 :
        "Empate!");

    return 0;
}