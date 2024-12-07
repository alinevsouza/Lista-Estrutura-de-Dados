#include <stdio.h>

int main() {
	
    int matriz[3][3];
    int n_maior, n_menor;
    printf("Digite os elementos: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            if (i == 0 && j == 0) {
                n_maior = n_menor = matriz[i][j];
            } else {
                if (matriz[i][j] > n_maior) {
                    n_maior = matriz[i][j];
                }
                if (matriz[i][j] < n_menor) {
                    n_menor = matriz[i][j];
                }}}}
    printf("\nMaior elemento: %d\n", n_maior);
    printf("\nMenor elemento: %d\n", n_menor);
    return 0;
}
