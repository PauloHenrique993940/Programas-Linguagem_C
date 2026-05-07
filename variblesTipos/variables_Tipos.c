// Variaveis e Tipos na Linguagem C

#include <stdio.h>
#include <string.h>

int main()
{
    int idade, quantidade;
    float salario, altura;
    char letra;
    char nome[50];
    char sobrenome[50];

    idade = 35;
    quantidade = 100;
    salario = 2500.50f;
    altura = 1.75f;
    letra = 'A';

    strcpy(nome, "João");
    strcpy(sobrenome, "Silva");

    printf("Idade: %d\n", idade);
    printf("Quantidade: %d\n", quantidade);
    printf("Salário: %.2f\n", salario);
    printf("Altura: %.2f\n", altura);
    printf("Letra: %c\n", letra);
    printf("Nome: %s %s\n", nome, sobrenome);
    printf("Dados: idade=%d, salario=%.2f, altura=%.2f\n", idade, salario, altura);

    return 0;
}