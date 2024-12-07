#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
    float i_cidades[7][6];
    float m_Cidade[7] = {0};
    float m_Mes[6] = {0};
    for (int cidade = 0; cidade < 7; cidade++) {
        printf("Digite os índices pluviométricos para a cidade %d (em mm):\n", cidade + 1);
        for (int mes = 0; mes < 6; mes++) {
            printf("Mês %d: ", mes + 1);
            scanf("%f", &i_cidades[cidade][mes]);
        }}
    for (int cidade = 0; cidade < 7; cidade++) {
        for (int mes = 0; mes < 6; mes++) {
            m_Cidade[cidade] += i_cidades[cidade][mes];
            m_Mes[mes] += i_cidades[cidade][mes];
        }
        m_Cidade[cidade] /= 6;
    }
    for (int mes = 0; mes < 6; mes++) {
        m_Mes[mes] /= 7;
    }
    printf("\nMédia mensal de cada cidade:\n");
    for (int cidade = 0; cidade < 7; cidade++) {
        printf("Cidade %d: %.2f mm\n", cidade + 1, m_Cidade[cidade]);
    }
    printf("\nMédia de pluviosidade para cada mês na região:\n");
    for (int mes = 0; mes < 6; mes++) {
        printf("Mês %d: %.2f mm\n", mes + 1, m_Mes[mes]);
    }
    return 0;
}

