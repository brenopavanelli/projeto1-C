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
            puts("Insights de contrato:");
            
            apresentar_resultado(numero, tipo_de_lavagem, tipo_de_veiculo, tamanho_do_veiculo, frequencia, vlr_total, &contador);
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

void apresentar_resultado(int numero[], int tipo_de_lavagem[], int tipo_de_veiculo[], int tamanho_do_veiculo[], int frequencia[], float vlr_total[], int *contador) {
    float somaTotal = 0, somaFrequentes = 0, percentual;
    int maiorValor = 0, contratosFrequentes = 0;
    int totalTiposVeiculo[4] = {0, 0, 0, 0};  // Para Moto, Carro, SUV, Caminhão
    int totalTamanhosVeiculo[3] = {0, 0, 0};  // Para Pequeno, Médio, Grande

    // Calcular soma total, soma dos contratos frequentes e o contrato com maior valor
    for (int i = 0; i < *contador; i++) {
        somaTotal += vlr_total[i];  // Soma o valor total dos contratos
        
        // Verifica se o cliente é frequente (> 10 lavagens)
        if (frequencia[i] > 10) {
            contratosFrequentes++;
        }

        // Encontra o contrato com o maior valor
        if (vlr_total[i] > vlr_total[maiorValor])
            maiorValor = i;

        // Conta o número de contratos por tipo de veículo
        totalTiposVeiculo[tipo_de_veiculo[i] - 1]++;

        //Conta o número de veículos lavados por tamanho (Pequeno, Médio, Grande)
        totalTamanhosVeiculo[tamanho_do_veiculo[i] - 1]++;
    }

    //Média do valor total dos contratos
    printf("Media Total: R$ %.2f\n", somaTotal / *contador);

    //Média dos contratos para clientes frequentes (mais de 10 lavagens no mês)
    printf("Media de clientes frequente: %d\n", contratosFrequentes );

    // 3. Número do contrato com maior valor total
    printf("Contrato com maior valor: %d\n", numero[maiorValor]);

    //Percentual dos contratos para cada tipo de veículo em relação ao número total de contratos
    printf("Percentual de contratos por tipo de veiculo:\n");
    for (int i = 0; i < 4; i++) {
        percentual = (totalTiposVeiculo[i] / (float)*contador) * 100;
        printf(" - Tipo de Veiculo %d: %.2f%%\n", i + 1, percentual);
    }

    // Total de veículos lavados por tamanho (Pequeno, Médio, Grande)
    printf("Total de veiculos lavados por tamanho:\n");
    printf(" - Pequenos: %d\n", totalTamanhosVeiculo[0]);
    printf(" - Medios: %d\n", totalTamanhosVeiculo[1]);
    printf(" - Grandes: %d\n", totalTamanhosVeiculo[2]);
    
    int teste;
    scanf("%d", &teste);
}



