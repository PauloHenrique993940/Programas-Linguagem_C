// Game Super Trunfo
#include <stdio.h>

int main()
{
    // Carta 1
    char estado1;
    char codigoCarta1[10];
    char nomeCidade1[50];
    int populacao1;
    float areaKm21;
    float pib1;
    int numeroPontosTuristicos1;

    // Carta 2
    char estado2;
    char codigoCarta2[10];
    char nomeCidade2[50];
    int populacao2;
    float areaKm22;
    float pib2;
    int numeroPontosTuristicos2;

    // ===== CARTA 1 =====
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Digite o estado da cidade: ");
    scanf(" %c", &estado1);

    printf("Digite o codigo da carta: ");
    scanf("%s", codigoCarta1);

    printf("Digite o nome da cidade: ");
    scanf("%s", nomeCidade1);

    printf("Digite a populacao da cidade: ");
    scanf("%d", &populacao1);

    printf("Digite a area da cidade em km²: ");
    scanf("%f", &areaKm21);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &numeroPontosTuristicos1);

    // Exibição Carta 1
    printf("\n=== Carta 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigoCarta1);
    printf("Cidade: %s\n", nomeCidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km²\n", areaKm21);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos Turisticos: %d\n", numeroPontosTuristicos1);

    // ===== CARTA 2 =====
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Digite o estado da cidade: ");
    scanf(" %c", &estado2);

    printf("Digite o codigo da carta: ");
    scanf("%s", codigoCarta2);

    printf("Digite o nome da cidade: ");
    scanf("%s", nomeCidade2);

    printf("Digite a populacao da cidade: ");
    scanf("%d", &populacao2);

    printf("Digite a area da cidade em km²: ");
    scanf("%f", &areaKm22);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &numeroPontosTuristicos2);

    // Exibição Carta 2
    printf("\n=== Carta 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigoCarta2);
    printf("Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km²\n", areaKm22);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turisticos: %d\n", numeroPontosTuristicos2);

    return 0;
}