#include <stdio.h>

int main() {
    float notas[5][4];
    float mediaA[5], mediaT = 0;
    for (int i = 0; i < 5; i++) {
        printf("\nDigite as notas do aluno %d:\n", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }}
    for (int i = 0; i < 5; i++) {
        float soma = 0;
        for (int j = 0; j < 4; j++) {
            soma += notas[i][j];
        }
        mediaA[i] = soma / 4;
        mediaT += mediaA[i];
    }
    mediaT /= 5;
    printf("\nMedias dos alunos:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nAluno %d: %.2f\n", i + 1, mediaA[i]);
    }
    printf("\nMedia da turma: %.2f\n", mediaT);
    return 0;
}

