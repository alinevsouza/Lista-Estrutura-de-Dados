#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

void printTabuleiro(char tabuleiro[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

bool verificaVencedor(char tabuleiro[SIZE][SIZE], char jogador) {
    for (int i = 0; i < SIZE; i++) {
        if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) ||
            (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)) {
            return true;
        }}
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
        return true;
    }
    return false;
}

int main() {
    char tabuleiro[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    char jogadorAtual = 'X';
    int jogadas = 0;
    while (true) {
        printTabuleiro(tabuleiro);
        printf("Jogador %c, escolha uma posicao: ", jogadorAtual);
        int escolha;
        scanf("%d", &escolha);
        if (escolha < 1 || escolha > 9) {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }
        int linha = (escolha - 1) / SIZE;
        int coluna = (escolha - 1) % SIZE;
        if (tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O') {
            printf("Posição já ocupada. Tente novamente.\n");
            continue;
        }
        tabuleiro[linha][coluna] = jogadorAtual;
        jogadas++;
        if (verificaVencedor(tabuleiro, jogadorAtual)) {
            printTabuleiro(tabuleiro);
            printf("Jogador %c venceu!\n", jogadorAtual);
            break;
        }
        if (jogadas == SIZE * SIZE) {
            printTabuleiro(tabuleiro);
            printf("Empate!\n");
            break;
        }
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }
    return 0;
}

