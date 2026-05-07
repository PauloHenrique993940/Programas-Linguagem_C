//Realizando calculo de média de alunos
#include <stdio.h>

int main(){
    float nota1, nota2, nota3, media;
    char nomeDoAluno[50];

    printf("Insira o nome do aluno: ");
    scanf("%s", nomeDoAluno);

    printf("Insira a primeira nota: ");
    scanf("%f", &nota1);

    printf("Insira a segunda nota: ");
    scanf("%f", &nota2);

    printf("Insira a Terceira nota: ");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3) /3;
    printf("A média do aluno %s é: %.2f\n", nomeDoAluno, media);

    return 0;
}