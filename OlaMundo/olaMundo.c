#include <stdio.h>
#include <locale.h> // Biblioteca para acentuação

int main(){
    setlocale(LC_ALL, "Portuguese"); // Configura a localidade para Português
    printf("olá, Mundo! Usando a Linguagem c\n");
}