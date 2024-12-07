#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
// Exercício 6 - Estrutura do voo

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

// Exercício 7 - Função para cadastrar um novo voo

Voo* cadastrarVoo(Voo *lista) {
    Voo *novo = criarVoo();
    printf("\n=== Cadastro de Novo Voo ===\n");
    printf("Número do voo: ");
    scanf("%d", &novo->numeroVoo);
    printf("Data do voo (1-seg, ..., 8-diário): ");
    scanf("%d", &novo->dataVoo);
    printf("Horário (hora min): ");
    scanf("%d %d", &novo->hora, &novo->min);
    printf("Aeroporto de saída (ID): ");
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

// Exercício 8 - Função para consultar um voo

void consultaVoo(Voo *lista, int numero) {
    Voo *atual = lista;
    while (atual != NULL) {
        if (atual->numeroVoo == numero) {
            printf("\n=== Informações do Voo ===\n");
            printf("Número do voo: %d\n", atual->numeroVoo);
            printf("Data do voo: %d\n", atual->dataVoo);
            printf("Horário: %02d:%02d\n", atual->hora, atual->min);
            printf("Aeroporto de saída: %d\n", atual->aeroportoSaida);
            printf("Aeroporto de chegada: %d\n", atual->aeroportoChegada);
            printf("Rota: %d\n", atual->rota);
            printf("Tempo estimado: %.2f horas\n", atual->tempoEstimado);
            printf("Passageiros a bordo: %d\n", atual->passageiros);
            return;
        }
        atual = atual->prox;
    }
    printf("Voo não encontrado!\n");
}

// Exercício 9 - Função para remover um voo

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
    printf("Voo não encontrado!\n");
    return lista;
}

// Função principal
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
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // 7 - Cadastrar voo
                lista = cadastrarVoo(lista);
                break;
            case 2: // 8 - Consultar voo
                printf("Digite o número do voo para consultar: ");
                scanf("%d", &numero);
                consultaVoo(lista, numero);
                break;
            case 3: // 9 - Remover voo
                printf("Digite o número do voo para remover: ");
                scanf("%d", &numero);
                lista = removeVoo(lista, numero);
                break;
            case 4: // Encerrar o programa
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    while (lista != NULL) {
        Voo *temp = lista;
        lista = lista->prox;
        free(temp);
    }
    return 0;
}

