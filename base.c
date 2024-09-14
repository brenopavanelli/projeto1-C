#include <stdio.h>

int main() {
    // Guardar a opçao escolhida
    int opcao;
    // preciso primeiro apresentar o menu
    do {
        // imprimir as opcoes
        printf("Escolha uma opcao: \n");
        printf("0. **Sair** \n");
        printf("1. **Inserir mais contratos** \n");
        printf("2. **Apresentar resultados \n**");
        printf("3. **Ordenar os contratos pelo valor total (decrescente)**");
        printf("4. **Imprimir registros de contratos**");
        scanf("%d", &opcao);
        // quando a opçao for 0, saida
        if (opcao == 0){
            printf("Tchau \n");
            break;
        } else if (opcao == 1){
            printf("Você selecionou: Inserir mais contratos \n");
        } else if (opcao == 2){
            printf("Você selecionou: Apresentar resultados");
        } else if (opcao == 3){
            printf("Você selecionou: Ordenar os contratos pelo valor total");
        } else if (opcao == 4){
            printf("Você selecionou: Imprimir registros de contratos");
        } else {
            printf("Opcao invalida! \n");
        }

    } while (opcao != 0);


    return 0;
}

/*

printf("|Número do Contrato|Tipo de Lavagem|Tipo de Veículo|Tipo de Veículo|Frequência (vezes por mês)|Valor Base|Desconto por Tipo de Veículo|Desconto Adicional|Adicionais|Valor Total|\n")
printf("|------------------|----------------|----------------|----------------|--------------------------|-----------|----------------------------|-------------------|----------|-----------|")
