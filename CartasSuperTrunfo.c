#include <stdio.h>

    typedef struct {
    int populacao, pontosTuristicos;
    char numero[20];
    float area, pib;
    char codigo;
    } carta;

    void cadastro(carta *card){
        printf("Por favor, digite o código do estado (A-H): ");
        scanf(" %c", &card->codigo);
        printf("Por favor, digite o número da cidade(0-4): ");
        scanf("%s", card->numero);
        printf("Por favor, digite o número da população: ");
        scanf("%d", &card->populacao);
        printf("Por favor, digite a area da cidade: ");
        scanf("%f", &card->area);
        printf("Por favor, digite o PIB per capita da cidade ");
        scanf("%f", &card->pib);
        printf("Por favor, digite o número de pontos turísticos na cidade: ");
        scanf("%d", &card->pontosTuristicos);
    }

int main() {
    carta varCarta;

    cadastro(&varCarta);

    printf("Código: %c-0%s \n", varCarta.codigo, varCarta.numero);
    printf("População: %d \n", varCarta.populacao);
    printf("Área em Km²: %.2f \n", varCarta.area);
    printf("PIB per Capita: %.2f \n", varCarta.pib);
    printf("Número de pontos turistícos: %d\n", varCarta.pontosTuristicos);

    return 0;
}
