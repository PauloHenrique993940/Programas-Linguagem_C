// Game Super Trunfo
#include <stdio.h>

static void logicGame(
    int populacao1,
    int populacao2,
    float areaKm21,
    float areaKm22,
    float pib1,
    float pib2,
    int numeroPontosTuristicos1,
    int numeroPontosTuristicos2)
{
    char jogador1[50];
    char jogador2[50];
    int atributoEscolhido;

    printf("Digite o nome do Jogador 1: ");
    scanf("%49s", jogador1);

    printf("Digite o nome do Jogador 2: ");
    scanf("%49s", jogador2);

    printf("Escolha um atributo para comparar:\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    scanf("%d", &atributoEscolhido);

    switch (atributoEscolhido)
    {
    case 1:
        if (populacao1 > populacao2)
        {
            printf("%s vence com a maior populacao!\n", jogador1);
        }
        else if (populacao2 > populacao1)
        {
            printf("%s vence com a maior populacao!\n", jogador2);
        }
        else
        {
            printf("Empate na populacao!\n");
        }
        break;
    case 2:
        if (areaKm21 > areaKm22)
        {
            printf("%s vence com a maior area!\n", jogador1);
        }
        else if (areaKm22 > areaKm21)
        {
            printf("%s vence com a maior area!\n", jogador2);
        }
        else
        {
            printf("Empate na area!\n");
        }
        break;
    case 3:
        if (pib1 > pib2)
        {
            printf("%s vence com o maior PIB!\n", jogador1);
        }
        else if (pib2 > pib1)
        {
            printf("%s vence com o maior PIB!\n", jogador2);
        }
        else
        {
            printf("Empate no PIB!\n");
        }
        break;
    case 4:
        if (numeroPontosTuristicos1 > numeroPontosTuristicos2)
        {
            printf("%s vence com mais pontos turisticos!\n", jogador1);
        }
        else if (numeroPontosTuristicos2 > numeroPontosTuristicos1)
        {
            printf("%s vence com mais pontos turisticos!\n", jogador2);
        }
        else
        {
            printf("Empate nos pontos turisticos!\n");
        }
        break;
    default:
        printf("Opcao invalida! Escolha um atributo valido.\n");
        break;
    }
}

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
    scanf("%9s", codigoCarta1);

    printf("Digite o nome da cidade: ");
    scanf("%49s", nomeCidade1);

    printf("Digite a populacao da cidade: ");
    scanf("%d", &populacao1);

    printf("Digite a area da cidade em km2: ");
    scanf("%f", &areaKm21);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &numeroPontosTuristicos1);

    // Exibicao Carta 1
    printf("\n=== Carta 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigoCarta1);
    printf("Cidade: %s\n", nomeCidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km2\n", areaKm21);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Pontos Turisticos: %d\n", numeroPontosTuristicos1);

    // ===== CARTA 2 =====
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Digite o estado da cidade: ");
    scanf(" %c", &estado2);

    printf("Digite o codigo da carta: ");
    scanf("%9s", codigoCarta2);

    printf("Digite o nome da cidade: ");
    scanf("%49s", nomeCidade2);

    printf("Digite a populacao da cidade: ");
    scanf("%d", &populacao2);

    printf("Digite a area da cidade em km2: ");
    scanf("%f", &areaKm22);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &numeroPontosTuristicos2);

    // Exibicao Carta 2
    printf("\n=== Carta 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigoCarta2);
    printf("Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km2\n", areaKm22);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Pontos Turisticos: %d\n", numeroPontosTuristicos2);
    logicGame(
        populacao1,
        populacao2,
        areaKm21,
        areaKm22,
        pib1,
        pib2,
        numeroPontosTuristicos1,
        numeroPontosTuristicos2);

    return 0;
}