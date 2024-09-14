#include <stdio.h> 
int contador;
#define NUMERO_DE_CONTRATOS 10

// Dados que o usuário irá fornecer
int tipo_de_lavagem[NUMERO_DE_CONTRATOS]; // (1-Simples, 2-Completa, 3-Premium)
int tipo_de_veiculo[NUMERO_DE_CONTRATOS]; // (1-Moto, 2-Carro, 3-SUV/Van, 4-Caminhão)
int tamanho_do_veiculo[NUMERO_DE_CONTRATOS]; // (1-Pequeno, 2-Médio, 3-Grande)
int frequencia[NUMERO_DE_CONTRATOS]; 

// Dados que serão calculados com base nas informações que o usuário fornecer
int custo_da_lavagem[NUMERO_DE_CONTRATOS];
    // 1 = R$ 60, 2 = R$ 120, 3 = R$ 180
int desconto_tipo_veiculo[NUMERO_DE_CONTRATOS];
    // 1 = 10%, 2 = Sem desconto, 3 = 5%, 4 = 15%
int adicional_por_tamanho[NUMERO_DE_CONTRATOS];
    // 1 = Sem adicional, 2 = R$ 30, 3 = R$ 60

int contratos_cadastrados = 0;

void adicionar_contratos(int lavagem[], int veiculo[], int tamanho[], int freq[],int comprimento) {
    for (int i=0;i<comprimento;i++) {
        printf("Insira o tipo de lavagem: \n");
        printf("1 - Simples \n");
        printf("2 - Completa \n");
        printf("3 - Premium \n");
        scanf("%d", &lavagem[i]);

        printf("Insira o tipo de veiculo: \n");
        printf("1 - Moto \n");
        printf("2 - Carro \n");
        printf("3 - SUV\Van \n");
        printf("4 - Caminhão \n");
        scanf("%d", &veiculo[i]);

        printf("Insira o tamanho do veiculo: \n");
        printf("1 - Pequeno \n");
        printf("1 - Médio \n");
        printf("1 - Grande \n");
        scanf("%d", &tamanho[i]);
        
        printf("Insira a frequencia: \n");
        scanf("%d", &freq[i]);

        
    }
}
/*
void coletardados(int vetor[], int comprimento) {
    for (int i=0;i<comprimento;i++) {
        scanf("%d", &vetor[i]);
    }
}
*/

void exibir_dados(int vetor[], int comprimento) {
    for (int i=0;i<comprimento;i++) {
        printf("%d", vetor[i]);
    }
}

