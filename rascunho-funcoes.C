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

float total[NUMERO_DE_CONTRATOS];

int contratos_cadastrados = 0;

void adicionar_contratos(int lavagem[], int veiculo[], int tamanho[], int freq[],int comprimento) {
    for (int i=0;i<comprimento;i++) {
        do {
            //  Pergunta qual o tipo de lavagem até atender a regra
            system("cls");
            printf("Insira o tipo de lavagem: \n");
            printf("1 - Simples \n");
            printf("2 - Completa \n");
            printf("3 - Premium \n");
            scanf("%d", &lavagem[i]);
        }  while (lavagem[i]!= 1 || lavagem[i]!=2 || lavagem[i]!=3);

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

        do {
            //  Pergunta qual o modelo do veículo até atender a regra
            system("cls");
            printf("Insira o tipo de veiculo: \n");
            printf("1 - Moto \n");
            printf("2 - Carro \n");
            printf("3 - SUV\Van \n");
            printf("4 - Caminhão \n");
            scanf("%d", &veiculo[i]);
        }  while (veiculo[i]!= 1 || veiculo[i]!=2 || veiculo[i]!=3 || veiculo[i]!=4);

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

        do {
            //  Pergunta qual o tamanho do veículo até atender a regra
            system("cls");
            printf("Insira o tamanho do veiculo: \n");
            printf("1 - Pequeno \n");
            printf("2 - Médio \n");
            printf("3 - Grande \n");
            scanf("%d", &tamanho[i]);
        }  while (tamanho[i]!= 1 || tamanho[i]!=2 || tamanho[i]!=3);

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
        
    }
}


/*
void coletardados(int vetor[], int comprimento) {
    for (int i=0;i<comprimento;i++) {
        scanf("%d", &vetor[i]);
    }
}
*/

// void exibir_dados(int vetor[], int comprimento) {
//     for (int i=0;i<comprimento;i++) {
//         printf("%d", vetor[i]);
//     }
// }

