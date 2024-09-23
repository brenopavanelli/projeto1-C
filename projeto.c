#include <stdio.h> 
#include <stdlib.h>

int contador;
#define NUMERO_DE_CONTRATOS 100

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
int desconto_tipo_veiculo[NUMERO_DE_CONTRATOS];
int adicional_por_tamanho[NUMERO_DE_CONTRATOS];
int numero_do_contrato[NUMERO_DE_CONTRATOS];
float total[NUMERO_DE_CONTRATOS];

int contratos_cadastrados = 0;
int retorno;

// Função para adicionar contratos
void adicionar_contratos(int lavagem[], int veiculo[], int tamanho[], int freq[], int comprimento) {
    for (int i = contratos_cadastrados; i < comprimento; i++) {
        system("cls");
        
        do {
            printf("Insira o tipo de lavagem: \n");
            printf("1 - Simples \n");
            printf("2 - Completa \n");
            printf("3 - Premium \n");
            scanf("%d", &lavagem[i]);
            if (lavagem[i] < 1 || lavagem[i] > 3) {
                printf("Opcao invalida! Tente novamente.\n");
            }
        } while (lavagem[i] < 1 || lavagem[i] > 3);

        switch (lavagem[i]) {
            case 1: custo_da_lavagem[i] = SIMPLES; break;
            case 2: custo_da_lavagem[i] = COMPLETA; break;
            case 3: custo_da_lavagem[i] = PREMIUM; break;
        }

        do {
            system("cls");
            printf("Insira o tipo de veiculo: \n");
            printf("1 - Moto \n");
            printf("2 - Carro \n");
            printf("3 - SUV/Van \n");
            printf("4 - Caminhao \n");
            scanf("%d", &veiculo[i]);
            if (veiculo[i] < 1 || veiculo[i] > 4) {
                printf("Opcao invalida! Tente novamente.\n");
            }
        } while (veiculo[i] < 1 || veiculo[i] > 4);

        switch (veiculo[i]) {
            case 1: desconto_tipo_veiculo[i] = custo_da_lavagem[i] * MOTO; break;
            case 2: desconto_tipo_veiculo[i] = custo_da_lavagem[i] * CARRO; break;
            case 3: desconto_tipo_veiculo[i] = custo_da_lavagem[i] * SUVVAN; break;
            case 4: desconto_tipo_veiculo[i] = custo_da_lavagem[i] * CAMINHAO; break;
        }

        do {
            system("cls");
            printf("Insira o tamanho do veiculo: \n");
            printf("1 - Pequeno \n");
            printf("2 - Medio \n");
            printf("3 - Grande \n");
            scanf("%d", &tamanho[i]);
            if (tamanho[i] < 1 || tamanho[i] > 3) {
                printf("Opcao invalida! Tente novamente.\n");
            }
        } while (tamanho[i] < 1 || tamanho[i] > 3);

        switch (tamanho[i]) {
            case 1: adicional_por_tamanho[i] = PEQUENO; break;
            case 2: adicional_por_tamanho[i] = MEDIO; break;
            case 3: adicional_por_tamanho[i] = GRANDE; break;
        }

        do {
            system("cls");
            printf("Insira a frequencia (número de lavagens): \n");
            scanf("%d", &freq[i]);
            if (freq[i] < 0) {
                printf("Opcao invalida! Frequencia não pode ser negativa.\n");
            }
        } while (freq[i] < 0);

        float desconto_frequencia = (freq[i] > 10) ? (custo_da_lavagem[i] * FREQUENTE) : 0;

        total[i] = custo_da_lavagem[i] - desconto_tipo_veiculo[i] + adicional_por_tamanho[i] - desconto_frequencia;

        contratos_cadastrados++;
        numero_do_contrato[i] = i + 1;

        system("cls");
        printf("Deseja continuar inserindo contratos? \n");
        printf("Digite qualquer numero para continuar ou digite 0 para retornar ao menu. \n");
        scanf("%d", &retorno);

        if (retorno == 0) break;
    }
}

// Função para apresentar os resultados
void apresentar_resultados(int contratos, int tipoV[], int tamanho[], int numero[]) {
    float soma_total = 0, soma_frequentes = 0, percentual;
    int maior_valor = 0, contratos_frequentes = 0;
    int total_tipos_veiculo[4] = {0, 0, 0, 0};
    int total_tamanhos_veiculo[3] = {0, 0, 0};
    
    for (int i = 0; i < contratos; i++) {
        soma_total += total[i]; 

        if (frequencia[i] > 10) {
            contratos_frequentes++;
            soma_frequentes += total[i];
        }

        if (total[i] > total[maior_valor]) 
            maior_valor = i;

        total_tipos_veiculo[tipoV[i] - 1]++;
        total_tamanhos_veiculo[tamanho[i] - 1]++;
    }

    printf("Media Total: R$ %.2f\n", soma_total / contratos);

    if (contratos_frequentes > 0) {
        printf("Media de clientes frequente: %.2f\n", soma_frequentes / contratos_frequentes);
    } else {
        printf("Nenhum cliente frequente.\n");
    }

    printf("Contrato com maior valor: %d - Valor: R$ %.2f\n", numero[maior_valor], total[maior_valor]);

    printf("Percentual de contratos por tipo de veiculo:\n");
    for (int i = 0; i < 4; i++) {
        percentual = ((float)total_tipos_veiculo[i] / contratos) * 100;
        printf(" - Tipo de Veiculo %d: %.2f%%\n", i + 1, percentual);
    }

    printf("Total de veiculos lavados por tamanho:\n");
    printf(" - Pequenos: %d\n", total_tamanhos_veiculo[0]);
    printf(" - Medios: %d\n", total_tamanhos_veiculo[1]);
    printf(" - Grandes: %d\n", total_tamanhos_veiculo[2]);
}

// Função para ordenar os contratos por valor total (decrescente)
void ordenar_contratos(int contratos) {
    for (int i = 0; i < contratos - 1; i++) {
        for (int j = 0; j < contratos - i - 1; j++) {
            if (total[j] < total[j + 1]) {
                // Troca o valor total
                float temp_total = total[j];
                total[j] = total[j + 1];
                total[j + 1] = temp_total;

                // Troca os tipos de lavagem, veículos, tamanhos e números de contrato
                int temp_lavagem = tipo_de_lavagem[j];
                tipo_de_lavagem[j] = tipo_de_lavagem[j + 1];
                tipo_de_lavagem[j + 1] = temp_lavagem;

                int temp_veiculo = tipo_de_veiculo[j];
                tipo_de_veiculo[j] = tipo_de_veiculo[j + 1];
                tipo_de_veiculo[j + 1] = temp_veiculo;

                int temp_tamanho = tamanho_do_veiculo[j];
                tamanho_do_veiculo[j] = tamanho_do_veiculo[j + 1];
                tamanho_do_veiculo[j + 1] = temp_tamanho;

                int temp_numero = numero_do_contrato[j];
                numero_do_contrato[j] = numero_do_contrato[j + 1];
                numero_do_contrato[j + 1] = temp_numero;
            }
        }
    }

    printf("Contratos ordenados com sucesso!\n");
}

// Função para imprimir os contratos cadastrados
void imprimir_contratos(int contratos) {
    printf("Contratos cadastrados:\n");
    for (int i = 0; i < contratos; i++) {
        printf("Contrato %d: Tipo de Lavagem: %d, Tipo de Veículo: %d, Tamanho: %d, Total: R$ %.2f\n",
               numero_do_contrato[i], tipo_de_lavagem[i], tipo_de_veiculo[i], tamanho_do_veiculo[i], total[i]);
    }
}

// Função principal com o menu de opções
int main() {
    int opcao;
    do {
        printf("\n--- Menu ---\n");
        printf("1 - Adicionar contrato\n");
        printf("2 - Apresentar resultado\n");
        printf("3 - Ordenar contratos por valor total\n");
        printf("4 - Imprimir contratos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_contratos(tipo_de_lavagem, tipo_de_veiculo, tamanho_do_veiculo, frequencia, NUMERO_DE_CONTRATOS);
                break;
            case 2:
                apresentar_resultados(contratos_cadastrados, tipo_de_veiculo, tamanho_do_veiculo, numero_do_contrato);
                break;
            case 3:
                ordenar_contratos(contratos_cadastrados);
                break;
            case 4:
                imprimir_contratos(contratos_cadastrados);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
