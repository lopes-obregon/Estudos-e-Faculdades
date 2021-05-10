//dado dois vetores n elementos calcular o produto escalar
#include<stdio.h>
#define TAMANHO 1000
int main(){
    int i, vector_a[TAMANHO], vector_b[TAMANHO], entrada, contador = 0, produto_escalar;
     printf("Informe os valores! ou Informe 1001 para sair\n");
    for(i = 0; i < TAMANHO; i++){
        scanf("%d", &entrada);
        if(entrada == 1001){
            i = TAMANHO;
        }else{
            contador++;
            vector_a[i] = entrada;
            printf("Informe a segunda elemento do vetor B: ");
            scanf("%d", &entrada);
            vector_b[i] = entrada;
        }
    }

    //contador para calcular a multiplicação
    for(i = 0; i < contador; i++){
        produto_escalar += (vector_a[i] * vector_b[i]);
    }
    printf("Produto escalar de A por B eh: %d\n", produto_escalar);
    return 0;
}