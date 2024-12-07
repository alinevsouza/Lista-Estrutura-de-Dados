#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
    int x, y, *p;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;
    printf("Valor de x: %d\n", x);
    printf("Valor de y: %d\n", y);
    printf("Valor apontado por p (*p): %d\n", *p);
    printf("\n-----------------------------:\n");
    printf("1. Inicializamos y = 0 e p apontando para y.\n");
    printf("2. x = *p atribui o valor de y (0) para x.\n");
    printf("3. Atualizamos x para 4 diretamente.\n");
    printf("4. (*p)++ incrementa o valor de y para 1 usando p.\n");
    printf("5. --x decrementa x de 4 para 3.\n");
    printf("6. (*p) += x soma o valor de x (3) ao valor de y (1), resultando em y = 4.\n");
    return 0;
}

