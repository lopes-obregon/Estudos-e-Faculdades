//armazena valores no array conta e imprime os numeros de inteiros pares e impares
#include <stdio.h>
#include <stdlib.h> // srand e rand
#include <time.h> //time
#define TAMANHO 10

int main(){
    int i, pares = 0, impares = 0, vector[TAMANHO];
    printf("Informe os valores para armazenar");
    //leitura
    
    for(i =0; i < TAMANHO; i++){
        scanf("%d", &vector[i]);
    }
    /*srand(time(NULL));
    for(i = 0; i < TAMANHO; i++){
        vector[i] = rand()% 1000;
        printf("%d ", vector[i]);
    }
    printf("\n");*/

    //conta os pares e impares
    for(i = 0; i < TAMANHO; i++){
        //se o resto da divisao por dois for zero então é par caso contrario é impar
        if(vector[i] % 2 == 0){
            pares++;
            printf("Par: %d\n", vector[i]);
        }else{
            impares++;
            printf("impar: %d\n", vector[i]);
        }
    }
    printf("Numeros de Pares %d numero de Impares %d\n", pares, impares);

    return 0;
}