/*mostra os primeiros numeros de fibo*/
#include <stdio.h>

int main(){
    int n, i, aux , anterior, temporario;
    printf("Informe a quantidade de numeros que deseja imprimir: ");
    scanf("%d", &n);
   
    for(i = 0; i < n; i++){
        if(i == 0){
            aux = 1;
        }else if(i == 1){
            anterior = aux;
            aux = 1;
        }else if (i == 2){
            anterior = aux;
            aux = aux + anterior;
        }else{
            temporario = aux;
            aux = aux + anterior;
            anterior = temporario;
        }
        printf("%d", aux);
        if(i +1 < n){
            printf(", ");
        }
    }
    printf("\n");
    
    return 0;
}

/*

1, 1, 2, 3, 5, 8, 13, 21, ...
0, 1, 2, 3, 4, 5, 6, 7, 8, ...
*/