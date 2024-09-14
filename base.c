#include <stdio.h>

int main() {
    // Guardar a op�ao escolhida
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
        // quando a op�ao for 0, saida
        if (opcao == 0){
            printf("Tchau \n");
            break;
        } else if (opcao == 1){
            printf("Voc� selecionou: Inserir mais contratos \n");
        } else if (opcao == 2){
            printf("Voc� selecionou: Apresentar resultados");
        } else if (opcao == 3){
            printf("Voc� selecionou: Ordenar os contratos pelo valor total");
        } else if (opcao == 4){
            printf("Voc� selecionou: Imprimir registros de contratos");
        } else {
            printf("Opcao invalida! \n");
        }

    } while (opcao != 0);


    return 0;
}

/*

printf("|N�mero do Contrato|Tipo de Lavagem|Tipo de Ve�culo|Tipo de Ve�culo|Frequ�ncia (vezes por m�s)|Valor Base|Desconto por Tipo de Ve�culo|Desconto Adicional|Adicionais|Valor Total|\n")
printf("|------------------|----------------|----------------|----------------|--------------------------|-----------|----------------------------|-------------------|----------|-----------|")
