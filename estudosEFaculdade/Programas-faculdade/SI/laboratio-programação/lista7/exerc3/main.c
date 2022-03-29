//imprime a ordem inversa da leitura
#include <stdio.h>
#define TAMANHO 1000
int main(){
    //contador para saber o tamanho exato armazenado
    int i, vector[TAMANHO], entrada, contador = 0;

    printf("Informe os valores! ou Informe 1001 para sair\n");
    for(i = 0; i < TAMANHO; i++){
        scanf("%d", &entrada);
        if(entrada == 1001){
            i = TAMANHO;
        }else{
            contador++;
            vector[i] = entrada;
        }
    }

    //imprimindo da forma inversa da entrada
    printf("Forma inversa!\n");
    for(i = contador -1; i > 0; i-- ){
        printf("%d\n", vector[i]);
    }

    return 0;
}