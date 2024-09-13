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
            printf("Inserir \n");
        } else if (opcao == 2){
            printf("Apresentar");
        } else if (opcao == 3){
            printf("Ordenar");
        } else if (opcao == 4){
            printf("Imprimir");
        } else {
            printf("Opcao invalida! \n");
        }

    } while (opcao != 0);


    return 0;
}

dasda
