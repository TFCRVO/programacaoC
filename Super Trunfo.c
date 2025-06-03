#include <stdio.h>

// Definindo o tamanho máximo para strings (nome da cidade e código da carta)
#define TAM_MAX 100

int main() {
    // Variáveis para a primeira carta
    char estado1;                       // Letra do estado (A a H)
    char codigo1[4];                    // Código da carta (ex: A01)
    char nomeCidade1[TAM_MAX];         // Nome da cidade
    int populacao1;                    // Número de habitantes
    float area1;                       // Área em km²
    float pib1;                        // PIB da cidade
    int pontosTuristicos1;             // Número de pontos turísticos

    // Variáveis para a segunda carta
    char estado2;
    char codigo2[4];
    char nomeCidade2[TAM_MAX];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
