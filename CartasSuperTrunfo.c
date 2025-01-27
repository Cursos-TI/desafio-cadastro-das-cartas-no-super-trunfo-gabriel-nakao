#include <stdio.h>
#define maxCarta 32

    int contCard = 0, escolha, cartaIndice1, cartaIndice2, verif= 0, listarJ1, listarJ2;

    typedef struct { //estrutura das cartas
    int populacao, pontosTuristicos;
    int numero;
    float area, pib, densidade, pibPerC;
    char codigo;
    } carta;

    carta varCarta[maxCarta]; //variável varCarta do tipo carta

    void menu(){
        printf("========================================");
        printf("= Por favor, escolha uma das opções:   =");
        printf("= [1] Cadastrar uma carta              =");
        printf("= [2] Comparar cartas                  =");
        printf("= [3] Finalizar programa               =");
        printf("========================================");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                cadastro(&varCarta[contCard]);
                menu();
                break;
            case 2:
                menu();
        };
    }

    void listar(){
        printf("Selecione a carta do jogador 1: \n");
        for (int c=1; c<=contCard; c++){
            printf("[%d] Carta %c-0%d", c, varCarta[c].codigo, varCarta[c].numero);
        }
        scanf("%d", listarJ1);
        if (listarJ1 < 1 || listarJ1 > contCard){
            printf("Escolha uma opção válida, por favor.\n");
        }
        
    }

    void cadastro(carta *card){
        do{
        printf("Por favor, digite o código do estado (A-H): ");
        scanf(" %c", &card->codigo);
        printf("Por favor, digite o número da cidade(1-4): ");
        scanf("%d", &card->numero);
        while (card->numero<1 || card->numero>4){
            printf("Digite um número válido, por favor.\n");
            printf("Por favor, digite o número da cidade(1-4): ");
            scanf("%d", &card->numero);
        }
        for (int i=0; i<contCard; i++){
            if (varCarta[i].codigo == card->codigo && varCarta[i].numero == card->numero){
                printf("código %c-0%d repetido, por favor, digite um número diferente!\n", card->codigo, card->numero);
                int verif = 1;
                break;
            }
            else {
                verif = 0;
            }
        }
        }
        while (verif == 1);
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

    void imprimir(int indice1, int indice2){
        printf("Carta %c-0%d \n", varCarta[indice1].codigo, varCarta[indice1].numero);
        printf("População: %d habitantes\n", varCarta[indice1].populacao);
        printf("Área em Km²: %.2f Km²\n", varCarta[indice1].area);
        printf("PIB: R$ %.2f \n", varCarta[indice1].pib);
        printf("Número de pontos turistícos: %d\n", varCarta[indice1].pontosTuristicos);
        printf("Densidade demográfica: %.2f hab/km²\n", varCarta[indice1].densidade);
        printf("PIB per capita: %.2f R$/hab\n", varCarta[indice1].pibPerC);

        printf("Carta %c-0%d \n", varCarta[indice2].codigo, varCarta[indice2].numero);
        printf("População: %d habitantes\n", varCarta[indice2].populacao);
        printf("Área em Km²: %.2f Km²\n", varCarta[indice2].area);
        printf("PIB: R$ %.2f \n", varCarta[indice2].pib);
        printf("Número de pontos turistícos: %d\n", varCarta[indice2].pontosTuristicos);
        printf("Densidade demográfica: %.2f hab/km²\n", varCarta[indice2].densidade);
        printf("PIB per capita: %.2f R$/hab\n", varCarta[indice2].pibPerC);
    }

    void compararCartas(){
        listar();

    }

int main() {

    cadastro(&varCarta[contCard]);
    return 0;
}

