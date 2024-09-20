#include <stdio.h>
#include <stdlib.h>

int main() {

    // Variável que armazena a opção escolhida
    int opcao;
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
            puts("Insira mais contratos"); 
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