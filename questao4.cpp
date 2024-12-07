#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "portuguese");
    float i_cidades[7][6];
    float m_Cidade[7] = {0};
    float m_Mes[6] = {0};
    for (int cidade = 0; cidade < 7; cidade++) {
        printf("Digite os �ndices pluviom�tricos para a cidade %d (em mm):\n", cidade + 1);
        for (int mes = 0; mes < 6; mes++) {
            printf("M�s %d: ", mes + 1);
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
    printf("\nM�dia mensal de cada cidade:\n");
    for (int cidade = 0; cidade < 7; cidade++) {
        printf("Cidade %d: %.2f mm\n", cidade + 1, m_Cidade[cidade]);
    }
    printf("\nM�dia de pluviosidade para cada m�s na regi�o:\n");
    for (int mes = 0; mes < 6; mes++) {
        printf("M�s %d: %.2f mm\n", mes + 1, m_Mes[mes]);
    }
    return 0;
}

