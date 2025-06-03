#include <stdio.h>
#define TAM_MAX 100

int main() {
    // Dados da Carta 1
    char nomeCidade1[TAM_MAX] = "São Paulo";
    char estado1 = 'S';
    unsigned long int populacao1 = 12300000;
    float area1 = 1521.11;
    float pib1 = 2.2; // em bilhões
    int pontosTuristicos1 = 15;
    float densidadePop1 = populacao1 / area1;
    float pibPerCapita1 = (pib1 * 1000000000) / populacao1;

    // Dados da Carta 2
    char nomeCidade2[TAM_MAX] = "Rio de Janeiro";
    char estado2 = 'R';
    unsigned long int populacao2 = 6700000;
    float area2 = 1200.27;
    float pib2 = 1.4; // em bilhões
    int pontosTuristicos2 = 20;
    float densidadePop2 = populacao2 / area2;
    float pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    int opcao;

    // Menu interativo
    printf("\n====== SUPER TRUNFO - COMPARAÇÃO DE CIDADES ======\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("6 - PIB per Capita\n");
    printf("Digite a opção desejada (1 a 6): ");
    scanf("%d", &opcao);

    printf("\nComparação entre:\n");
    printf("Carta 1 - %s (%c)\n", nomeCidade1, estado1);
    printf("Carta 2 - %s (%c)\n\n", nomeCidade2, estado2);

    // Switch para comparar atributos
    switch (opcao) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %lu\n", nomeCidade1, populacao1);
            printf("%s: %lu\n", nomeCidade2, populacao2);
            if (populacao1 > populacao2) {
                printf("Resultado: %s venceu!\n", nomeCidade1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: %s venceu!\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", nomeCidade1, area1);
            printf("%s: %.2f km²\n", nomeCidade2, area2);
            if (area1 > area2) {
                printf("Resultado: %s venceu!\n", nomeCidade1);
            } else if (area2 > area1) {
                printf("Resultado: %s venceu!\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões\n", nomeCidade1, pib1);
            printf("%s: %.2f bilhões\n", nomeCidade2, pib2);
            if (pib1 > pib2) {
                printf("Resultado: %s venceu!\n", nomeCidade1);
            } else if (pib2 > pib1) {
                printf("Resultado: %s venceu!\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n", nomeCidade1, pontosTuristicos1);
            printf("%s: %d\n", nomeCidade2, pontosTuristicos2);
            if (pontosTuristicos1 > pontosTuristicos2) {
                printf("Resultado: %s venceu!\n", nomeCidade1);
            } else if (pontosTuristicos2 > pontosTuristicos1) {
                printf("Resultado: %s venceu!\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade Populacional (menor vence)
            printf("Atributo: Densidade Populacional (menor vence)\n");
            printf("%s: %.2f hab/km²\n", nomeCidade1, densidadePop1);
            printf("%s: %.2f hab/km²\n", nomeCidade2, densidadePop2);
            if (densidadePop1 < densidadePop2) {
                printf("Resultado: %s venceu!\n", nomeCidade1);
            } else if (densidadePop2 < densidadePop1) {
                printf("Resultado: %s venceu!\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 6: // PIB per Capita
            printf("Atributo: PIB per Capita\n");
            printf("%s: %.2f reais\n", nomeCidade1, pibPerCapita1);
            printf("%s: %.2f reais\n", nomeCidade2, pibPerCapita2);
            if (pibPerCapita1 > pibPerCapita2) {
                printf("Resultado: %s venceu!\n", nomeCidade1);
            } else if (pibPerCapita2 > pibPerCapita1) {
                printf("Resultado: %s venceu!\n", nomeCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida. Por favor, selecione um número de 1 a 6.\n");
    }

    return 0;
}