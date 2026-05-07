//Entrada de Dados em C
//scanf é a função mais utilizada para ler dados do teclado em C. Ela é parte da biblioteca padrão de entrada e saída (stdio.h) e permite ler diferentes tipos de dados, como inteiros, caracteres, strings, etc.

#include <stdio.h>

int main(){
    char nome[50];
    char senha[50];

    printf("Digite seu nome: ");
    scanf("%49s", nome);

    printf("Digite sua senha de acesso: ");
    scanf("%49s", senha);

    printf("Olá, Usuário %s\nSua senha de acesso é: %s\n",
        nome, senha);

    return 0;
}