#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
// Exerc�cio 6 - Estrutura do voo

typedef struct voo {

    int numeroVoo;
    int dataVoo;
    int hora, min;
    int aeroportoSaida;
    int aeroportoChegada;
    int rota;
    float tempoEstimado;
    int passageiros;
    struct voo *prox;
} Voo;
Voo* criarVoo() {
    Voo *novo = (Voo*)malloc(sizeof(Voo));
    if (!novo) {
        printf("Erro.\n");
        exit(1);
    }
    novo->prox = NULL;
    return novo;
}

// Exerc�cio 7 - Fun��o para cadastrar um novo voo

Voo* cadastrarVoo(Voo *lista) {
    Voo *novo = criarVoo();
    printf("\n=== Cadastro de Novo Voo ===\n");
    printf("N�mero do voo: ");
    scanf("%d", &novo->numeroVoo);
    printf("Data do voo (1-seg, ..., 8-di�rio): ");
    scanf("%d", &novo->dataVoo);
    printf("Hor�rio (hora min): ");
    scanf("%d %d", &novo->hora, &novo->min);
    printf("Aeroporto de sa�da (ID): ");
    scanf("%d", &novo->aeroportoSaida);
    printf("Aeroporto de chegada (ID): ");
    scanf("%d", &novo->aeroportoChegada);
    printf("Rota (ID): ");
    scanf("%d", &novo->rota);
    printf("Tempo estimado de voo (em horas): ");
    scanf("%f", &novo->tempoEstimado);
    printf("Passageiros a bordo: ");
    scanf("%d", &novo->passageiros);
    novo->prox = lista;
    printf("Voo cadastrado com sucesso!\n");
    return novo;
}

// Exerc�cio 8 - Fun��o para consultar um voo

void consultaVoo(Voo *lista, int numero) {
    Voo *atual = lista;
    while (atual != NULL) {
        if (atual->numeroVoo == numero) {
            printf("\n=== Informa��es do Voo ===\n");
            printf("N�mero do voo: %d\n", atual->numeroVoo);
            printf("Data do voo: %d\n", atual->dataVoo);
            printf("Hor�rio: %02d:%02d\n", atual->hora, atual->min);
            printf("Aeroporto de sa�da: %d\n", atual->aeroportoSaida);
            printf("Aeroporto de chegada: %d\n", atual->aeroportoChegada);
            printf("Rota: %d\n", atual->rota);
            printf("Tempo estimado: %.2f horas\n", atual->tempoEstimado);
            printf("Passageiros a bordo: %d\n", atual->passageiros);
            return;
        }
        atual = atual->prox;
    }
    printf("Voo n�o encontrado!\n");
}

// Exerc�cio 9 - Fun��o para remover um voo

Voo* removeVoo(Voo *lista, int numero) {
    Voo *atual = lista;
    Voo *anterior = NULL;

    while (atual != NULL) {
        if (atual->numeroVoo == numero) {
            if (anterior == NULL) {
                lista = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Voo removido com sucesso!\n");
            return lista;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Voo n�o encontrado!\n");
    return lista;
}

// Fun��o principal
int main() {
	setlocale(LC_ALL, "portuguese");
    Voo *lista = NULL;
    int opcao, numero;
	// menu
    do {
        printf("\n=== Sistema VOEBEM ===\n");
        printf("1. Cadastrar voo\n");
        printf("2. Consultar voo\n");
        printf("3. Remover voo\n");
        printf("4. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // 7 - Cadastrar voo
                lista = cadastrarVoo(lista);
                break;
            case 2: // 8 - Consultar voo
                printf("Digite o n�mero do voo para consultar: ");
                scanf("%d", &numero);
                consultaVoo(lista, numero);
                break;
            case 3: // 9 - Remover voo
                printf("Digite o n�mero do voo para remover: ");
                scanf("%d", &numero);
                lista = removeVoo(lista, numero);
                break;
            case 4: // Encerrar o programa
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Op��o inv�lida!\n");
        }
    } while (opcao != 4);

    while (lista != NULL) {
        Voo *temp = lista;
        lista = lista->prox;
        free(temp);
    }
    return 0;
}

