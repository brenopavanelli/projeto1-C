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
void apresentar_resultado(int numero[], int tipo_de_lavagem[], int tipo_de_veiculo[], int tamanho_do_veiculo[], int frequencia[], float vlr_total[], int *contador);
float calcular_vlr(int tipo_de_lavagem,int tipo_de_veiculo,int tamanho_do_veiculo,int frequencia);

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
            system("cls");
            puts("apresente resultados");
            
            apresentar_resultado(numero, tipo_de_lavagem, tipo_de_veiculo, tamanho_do_veiculo, frequencia, vlr_total, contador);
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
    
    vlr_total[*contador] = calcular_vlr(tipo_de_lavagem[*contador], tipo_de_veiculo[*contador], tamanho_do_veiculo[*contador], frequencia[*contador]);
    
    numero[*contador] = *contador +1 ;
    
    (*contador)++; //Atuliza o numero do contrato
    } while (opcao_adc != 'n');
}

float calcular_vlr(int tipo_de_lavagem,int tipo_de_veiculo,int tamanho_do_veiculo,int frequencia){
    float valor_base, total, desconto = 0, adicional = 0;
    
    if (tipo_de_lavagem == 1) {
        valor_base = SIMPLES;
    } else if (tipo_de_lavagem == 2) {
        valor_base = COMPLETA;
    } else {
        valor_base = PREMIUM;
    }
    
    if (tipo_de_veiculo == 1) {
        desconto = 0.10; //moto
    } else if (tipo_de_veiculo == 2) {
        desconto = 0; //carro
    } else if (tipo_de_veiculo == 3) {
        desconto = 0.05; //suv/van
    } else if (tipo_de_veiculo == 4) {
        desconto = 0.15; //caminhão
    }
    
    if (tamanho_do_veiculo == 2) {
        adicional = 30.00;
    } else if (tamanho_do_veiculo == 3) {
        adicional = 60.00;
    } else {
        adicional = 0;
    }
    
    
    total = valor_base - (desconto * valor_base) - adicional;
    if (frequencia > 10) {
        total = total - (total * 0.10);
    }
    
    return total;
}

void apresentar_resultado(int numero[], int tipo_de_lavagem[], int tipo_de_veiculo[], int tamanho_do_veiculo[], int frequencia[], float vlr_total[], int *contador){
    
}



