#include <stdio.h>
#include <locale.h>
int somaRecursiva(int n) {
	setlocale(LC_ALL, "portuguese");
    if (n == 1) {
        return 1;
    }
    return n + somaRecursiva(n - 1); 
}
int main() {
    int n;
    printf("Digite o valor de N: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("N deve ser maior ou igual a 1.\n");
    } else {
        int resultado = somaRecursiva(n);
        printf("A somatória dos números de 1 a %d é: %d\n", n, resultado);
    }
    return 0;
}

