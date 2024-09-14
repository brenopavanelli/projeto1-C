#include <stdio.h>
int tipoLavagem[10];

int tipoVeic[10];
int descontoTipo[10];

int tamanhoVeic[10];
int adicionalTamanho[10];

int frequencia[10];
int descontoFreq[10];

int valorTotal[10];

int i = 0;

int main () {
    for(i=0; i<10; i++){
        printf("Tipo de lavagem (1 para Simples, 2 para Completa, 3 para Premium)");
        scanf("%d", &tipoLavagem);
        printf("Tipo de veículo (1 para Moto, 2 para Carro, 3 para SUV/Van, 4 para Caminhão)");
        scanf("%d", &tipoVeic);
        printf("Tipo de veículo (1 para Pequeno, 2 para Médio, 3 para Grande);");
        scanf("%d", &tamanhoVeic);
        printf("Frequência de serviços no mês (em número de vezes)");
        scanf("%d", &frequencia);
        int valorTotal[i] = 0;

        if (tipoLavagem == 1){
            valorTotal = valorTotal + 60;
        } else if (tipoLavagem == 2){
            valorTotal = valorTotal + 120;
        } else if (tipoLavagem == 3){
            valorTotal = valorTotal + 180;
        }

        if (tipoVeic[i] == 1){
            descontoTipo[i] = 10;
        } else if (tipoVeic == 2){
            descontoTipo[i] = 0;
        } else if (tipoVeic == 3){
            descontoTipo[i] = 0;
        } else if (tipoVeic == 4){
            descontoTipo[i] = 15;
        }

        if (tamanhoVeic == 1){
            adicionalTamanho = 0;
        } else if (tamanhoVeic == 2){
            adicionalTamanho = 30;
        } else if (tamanhoVeic == 3){
            adicionalTamanho = 60;
        }



    }

    return 0;
}
