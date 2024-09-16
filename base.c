#include <stdio.h>
#include <stdlib.h>

//Contantes
#define NUMERO_DE_CONTRATOS 10
#define SIMPLES 60.0
#define COMPLETA 120.0
#define PREMIUM 180.0

// VARIAVEIS/VETORES
int numero[NUMERO_DE_CONTRATOS], tipo_de_lavagem[NUMERO_DE_CONTRATOS], tipo_de_veiculo[NUMERO_DE_CONTRATOS], tamanho_do_veiculo[NUMERO_DE_CONTRATOS], frequencia[NUMERO_DE_CONTRATOS];
float vlr_total[NUMERO_DE_CONTRATOS];

//declarar funções
void adicionar_contratos(int numero[], int tipo_de_lavagem[], int tipo_de_veiculo[], int tamanho_do_veiculo[], int frequencia[], float vlr_total[], int *contador);


int main() {

    int contador = 0, opcao;

    do {
        // Exibe o menu
        printf("Escolha uma opcao: \n");
        printf("0. Sair \n");
        printf("1. Inserir mais contratos \n");
        printf("2. Apresentar resultados \n");
        printf("3. Ordenar os contratos pelo valor total (decrescente) \n");
        printf("4. Imprimir registros de contratos \n");
        // Coleta a opção escolhida
        scanf("%d", &opcao);

        switch (opcao) {
        case 0:
            puts("Saindo...");
            break;
        case 1:
            // Opção de Inserir mais contratos
            system("cls");
            printf("ADICIONAR CONTRATOS \n");
            printf("Digite 0 para retornar ao menu. \n");

            adicionar_contratos(numero, tipo_de_lavagem, tipo_de_veiculo, tamanho_do_veiculo, frequencia, vlr_total, &contador);
            break;

        case 2:
            puts("apresente resultados");
            break;
        case 3:
            puts("Ordene os contratos pelo valor toral");
            break;
        case 4:
            puts("Imprima os registros");
            break;
        default:
            puts("opcao invalida");
            break;
        }
        // Limpa o histórico do terminal
        system("cls");
    } while (opcao!=0);

    return 0;
}

//função de adicionar contrato
void adicionar_contratos(int numero[], int tipo_de_lavagem[], int tipo_de_veiculo[], int tamanho_do_veiculo[], int frequencia[], float vlr_total[], int *contador) {
    char opcao_adc;
    //Menu de inserção
    do {
    printf("\nContrato #%d\nTipo Lavagem (1-Simples, 2-Completa, 3-Premium): \n", *contador + 1);
    scanf("%d", &tipo_de_lavagem[*contador]);
   
    puts("Tipo Veiculo (1-Moto, 2-Carro, 3-SUV, 4-Caminhao): ");
    scanf("%d", &tipo_de_veiculo[*contador]);
  
    puts("Tamanho Veiculo (1-Pequeno, 2-Medio, 3-Grande): ");
    scanf("%d", &tamanho_do_veiculo[*contador]);
   
    puts("Frequencia: ");
    scanf("%d", &frequencia[*contador]);
    
    puts("Deseja continuar inserindo contrato? (s/n) ");
    scanf(" %c", &opcao_adc);
    
    (*contador)++; //Atuliza o numero do contrato
    } while (opcao_adc != 'n');
}
