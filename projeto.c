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