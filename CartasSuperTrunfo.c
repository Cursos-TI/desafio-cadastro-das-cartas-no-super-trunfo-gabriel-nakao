#include <stdio.h>
#define maxCarta 32

    int contCard = 0, escolha, cartaSel;

    typedef struct {
    int populacao, pontosTuristicos;
    char numero[20];
    float area, pib, densidade, pibPerC;
    char codigo;
    } carta;

    carta varCarta[maxCarta];

    void menu(){
        printf("========================================");
        printf("=Por favor, escolha uma das opções:    =");
        printf("= [1] Cadastrar uma carta              =");
        printf("= [2] Comparar cartas                  =");
        printf("= [3] Finalizar programa               =");
        printf("========================================");
    }

    void cadastro(carta *card){
        printf("Por favor, digite o código do estado (A-H): ");
        scanf(" %c", &card->codigo);
        printf("Por favor, digite o número da cidade(0-4): ");
        scanf("%s", card->numero);
        printf("Por favor, digite o número da população: ");
        scanf("%d", &card->populacao);
        printf("Por favor, digite a area da cidade: ");
        scanf("%f", &card->area);
        printf("Por favor, digite o PIB da cidade ");
        scanf("%f", &card->pib);
        printf("Por favor, digite o número de pontos turísticos na cidade: ");
        scanf("%d", &card->pontosTuristicos);
        card->densidade=card->populacao/card->area;
        card->pibPerC=card->pib/card->populacao;
        contCard++;
    }

    void imprimir(){
        printf("Código: %c-0%s \n", varCarta[cartaSel].codigo, varCarta[cartaSel].numero);
        printf("População: %d habitantes\n ", varCarta[cartaSel].populacao);
        printf("Área em Km²: %.2f Km²\n ", varCarta[cartaSel].area);
        printf("PIB: R$ %.2f \n", varCarta[cartaSel].pib);
        printf("Número de pontos turistícos: %d\n", varCarta[cartaSel].pontosTuristicos);
        printf("Densidade demográfica: %.2f hab/km²\n", varCarta[cartaSel].densidade);
        printf("PIB per capita: %.2f R$/hab\n", varCarta[cartaSel].pibPerC);
    }

int main() {

    menu();
    switch(escolha){
        case 1:
            cadastro(&varCarta[contCard]);
            menu();
            break;
        case 2:
            menu()


    };
    

    return 0;
}

