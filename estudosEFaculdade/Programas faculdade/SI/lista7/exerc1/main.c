//programa que recebe 10 inteiros encontra e imprime o segundo menor valor desse inteiro
#include <stdio.h>
#define TAMANHO 10

int main(){
    int vector[TAMANHO];
    int i, j, auxiliar;
    printf("Informe os valores para armazenar!\n");
    for(i = 0; i < TAMANHO; i++){
        scanf("%d", &vector[i]);
    } 
    // ordena o vetor
    for(i = 0; i < TAMANHO; i++){
        for(j = 0; j < TAMANHO - 1; j++){
            if(vector[j] > vector[j + 1]){
                auxiliar = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = auxiliar;
            }
        }
    }
    //imprime o segundo menor valor do vetor
    printf("Segundo menor %d\n", vector[1]);

    return 0;
}