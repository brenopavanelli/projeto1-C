#include <stdio.h> 
#include <stdlib.h>

int contador;
#define NUMERO_DE_CONTRATOS 10

// Define os preços fixos 
#define SIMPLES 60.0
#define COMPLETA 120.0
#define PREMIUM 180.0

#define MOTO 0.10
#define CARRO 0
#define SUVVAN 0.05
#define CAMINHAO 0.15

#define PEQUENO 0
#define MEDIO 30
#define GRANDE 60

#define FREQUENTE 0.10

// Dados que o usuário irá fornecer
int tipo_de_lavagem[NUMERO_DE_CONTRATOS]; // (1-Simples, 2-Completa, 3-Premium)
int tipo_de_veiculo[NUMERO_DE_CONTRATOS]; // (1-Moto, 2-Carro, 3-SUV/Van, 4-Caminhão)
int tamanho_do_veiculo[NUMERO_DE_CONTRATOS]; // (1-Pequeno, 2-Médio, 3-Grande)
int frequencia[NUMERO_DE_CONTRATOS]; // Naior que 10 = Frequente (10% de desconto)

// Dados que serão calculados com base nas informações que o usuário fornecer
int custo_da_lavagem[NUMERO_DE_CONTRATOS];
    // 1 = R$ 60, 2 = R$ 120, 3 = R$ 180
int desconto_tipo_veiculo[NUMERO_DE_CONTRATOS];
    // 1 = 10%, 2 = Sem desconto, 3 = 5%, 4 = 15%
int adicional_por_tamanho[NUMERO_DE_CONTRATOS];
    // 1 = Sem adicional, 2 = R$ 30, 3 = R$ 60

int numero_do_contrato[NUMERO_DE_CONTRATOS];
float total[NUMERO_DE_CONTRATOS];

int contratos_cadastrados = 0;
int retorno;

void adicionar_contratos(int lavagem[], int veiculo[], int tamanho[], int freq[],int comprimento) {
    for (int i=contratos_cadastrados;i<comprimento;i++) {
        
        //  Pergunta qual o tipo de lavagem até atender a regra
        system("cls");
        printf("Insira o tipo de lavagem: \n");
        printf("1 - Simples \n");
        printf("2 - Completa \n");
        printf("3 - Premium \n");
        scanf("%d", &lavagem[i]);

        // Seleciona a opção de lavagem
        switch (lavagem[i]) {
            case 1:
                custo_da_lavagem[i] = SIMPLES;
                break;
            case 2:
                custo_da_lavagem[i] = COMPLETA;
                break;
            case 3:
                custo_da_lavagem[i] = PREMIUM;
                break;
        }

        //  Pergunta qual o modelo do veículo até atender a regra
        system("cls");
        printf("Insira o tipo de veiculo: \n");
        printf("1 - Moto \n");
        printf("2 - Carro \n");
        printf("3 - SUV/Van \n");
        printf("4 - Caminhão \n");
        scanf("%d", &veiculo[i]);

        // Seleciona a opção
        switch (veiculo[i]) {
        case 1:
            desconto_tipo_veiculo[i] = (custo_da_lavagem[i] * MOTO);
            break;
        case 2:
            desconto_tipo_veiculo[i] = (custo_da_lavagem[i] * CARRO);
            break;
        case 3:
            desconto_tipo_veiculo[i] = (custo_da_lavagem[i] * SUVVAN);
            break;
        case 4:
            desconto_tipo_veiculo[i] = (custo_da_lavagem[i] * CAMINHAO);
            break;
        }

        //  Pergunta qual o tamanho do veículo até atender a regra
        system("cls");
        printf("Insira o tamanho do veiculo: \n");
        printf("1 - Pequeno \n");
        printf("2 - Médio \n");
        printf("3 - Grande \n");
        scanf("%d", &tamanho[i]);

        // Seleciona a opção
        switch (tamanho[i]) {
            case 1:
                adicional_por_tamanho[i] = PEQUENO;
                break;
            case 2:
                adicional_por_tamanho[i] = MEDIO;
                break;
            case 3:
                adicional_por_tamanho[i] = GRANDE;
                break;
        }
        
        // Solicita a frequencia
        int desconto_frequencia;
        system("cls");
        printf("Insira a frequencia: \n");
        scanf("%d", &freq[i]);

        // Calcula o desconto baseado na frequencia
        if (frequencia[i] > 10) {
            desconto_frequencia = custo_da_lavagem[i] * FREQUENTE;
        } else {
            desconto_frequencia = 0;
        }
        
        // Calcula o valor total
        total[i] = custo_da_lavagem[i] - desconto_tipo_veiculo[i] + adicional_por_tamanho[i] - desconto_frequencia;

        contratos_cadastrados++;
        numero_do_contrato[i]++;

        system("cls");
        printf("Deseja continuar inserindo contratos? \n");
        printf("Digite qualquer número para continuar ou digite 0 para retornar ao menu. \n");
        scanf("%d", &retorno);

        if (retorno==0) break;
    } 
}

// Recebe: total de contratos, Vetor de tipos de veiculo, vetor de tamanho,
// vetor de numero do contrato
void apresentar_resultados(int contratos, int tipoV[], int tamanho[], int numero[]) {
    float soma_total = 0, soma_frequentes = 0, percentual;
    int maior_valor = 0, contratos_frequentes = 0;
    int total_tipos_veiculo[4] = {0, 0, 0, 0};  // Para Moto, Carro, SUV, Caminhão
    int total_tamanhos_veiculo[3] = {0, 0, 0};  // Para Pequeno, Médio, Grande
    
    for (int i = 0; i < contratos; i++) {
        // Soma o valor total dos contratos
        soma_total += total[i]; 

         // Verifica se o cliente é frequente (> 10 lavagens)
        if (frequencia[i] > 10) {
            contratos_frequentes++;
            soma_frequentes += total[i];
        }

         // Encontra o contrato com o maior valor
        if (total[i] > total[maior_valor]) 
            maior_valor = i;

        // Conta o número de contratos por tipo de veículo
        total_tipos_veiculo[tipoV[i] - 1]++;

        // Conta o número de veículos lavados por tamanho (Pequeno, Médio, Grande)
        total_tamanhos_veiculo[tamanho[i] - 1]++;
    }

    // Média do valor total dos contratos
    printf("Media Total: R$ %.2f\n", soma_total / contratos);

    // Média dos contratos para clientes frequentes (mais de 10 lavagens no mês)
    printf("Media de clientes frequente: %d\n", soma_frequentes / contratos_frequentes );

    // Número do contrato com maior valor total
    printf("Contrato com maior valor: %d\n", numero[maior_valor]);

    printf("Percentual de contratos por tipo de veiculo:\n");
    for (int i = 0; i < 4; i++) {
        percentual = (total_tipos_veiculo[i] / contratos) * 100;
        printf(" - Tipo de Veiculo %d: %.2f%%\n", i + 1, percentual);
    }

    // Total de veículos lavados por tamanho (Pequeno, Médio, Grande)
    printf("Total de veiculos lavados por tamanho:\n");
    printf(" - Pequenos: %d\n", total_tamanhos_veiculo[0]);
    printf(" - Medios: %d\n", total_tamanhos_veiculo[1]);
    printf(" - Grandes: %d\n", total_tamanhos_veiculo[2]);
}


int main() {
    // Variável que armazena opções escolhidas
    int opcao, qntd_de_contratos;
    // Limpa o histórico do terminal
    system("cls");

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

            do {
                printf("Digite a quantidade de contratos que deseja adicionar: \n");
                scanf("%d", &qntd_de_contratos);
                if (qntd_de_contratos > 0) {
                    printf("Opcao invalida! \n");
                } else if (qntd_de_contratos == 0) {
                    printf("Retornando para o menu... \n");
                    break;
                }
            } while (qntd_de_contratos < 0);

            adicionar_contratos(tipo_de_lavagem, tipo_de_veiculo, tamanho_do_veiculo, frequencia, qntd_de_contratos);

        case 2:
            apresentar_resultados(contratos_cadastrados, tipo_de_veiculo, tamanho_do_veiculo, numero_do_contrato);
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
        // system("cls");
    } while (opcao!=0);

    return 0;
}


