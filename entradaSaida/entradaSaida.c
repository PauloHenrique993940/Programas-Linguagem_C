// entrada e saida de dados
#include <stdio.h>
#include <stdlib.h>

// printf - saida de dados
// scanf - entrada de dados
// outras funcoes
/*
Outras funcoes para entrada de dados:
gets() - para ler uma string (não recomendado devido a problemas de segurança)

fgets() - para ler uma string com controle de tamanho

getchar() - para ler um único caractere

getc() - para ler um único caractere sem esperar por Enter (disponível em algumas bibliotecas)

Outras funcoes para saida de dados:
puts() - para imprimir uma string seguida de uma nova linha
putchar() - para imprimir um único caractere
putc() - para imprimir um único caractere sem esperar por Enter (disponível em algumas bibliotecas)
fputs() - para imprimir uma string em um arquivo

Manipulação de arquivos

leittura de dados em arquivos

fscanf() - para ler dados formatados de um arquivo
fgets() - para ler uma linha de texto de um arquivo

escrita de dados em arquivos

fprintf() - para escrever dados formatados em um arquivo
fputs() - para escrever uma string em um arquivo
*/

int main()
{
    /*
    %d: Imprime um inteiro  no formato decimal
    %i: Equivalente a %d, também imprime um inteiro no formato decimal,
    %f: Imprime um número de ponto flutuante (float) com precisão padrão
    %e: Imprime um número de ponto flutuante em notação científica
    %s: Imprime uma string (sequência de caracteres)
    %c: Imprime um único caractere
    
    */
    int idade = 35;
    char nome[50] = "Paulo Henrique Ferreira França";
    float altura = 1.75;
    char sexo = 'M';
    int dataNascimento[3] = {5, 8, 1990};
    char opcao = 's';

    printf("Estou aprendendo a Linguagem C\n");
    printf("meu nome é %s e minha idade é %d anos\n", nome, idade);
    printf("Minha altura é %e metros\n", altura);
    printf("Meu sexo é %c\n", sexo);
    printf("Minha data de nascimento é %d/%d/%d\n",
        dataNascimento[0], dataNascimento[1],
        dataNascimento[2]
    );

    printf("Deseja continuar? %c\n", opcao);//Imprimi um único caractere
}