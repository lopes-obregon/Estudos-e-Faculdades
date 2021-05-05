//programa que calcula o maximo divisor comum entre os n primeiros numeros
#include <stdio.h>

int main(){
    int n, i = 0, numero_para_calcular, j, k, n2, auxiliar ;
    printf("Informe a quantidade de numeros para calcular: ");
    scanf("%d", &numero_para_calcular);
    //for para quantidade de vezes que se deseja calcular 
    //tecnica para calcular sem array
    while( i < numero_para_calcular){
        printf("Informe o numero que deseja encontrar o MDC: ");
        scanf("%d", &n);
        if(i < 2){
            printf("Informe o proximo numero  que deseja encontrar o MDC: ");
            scanf("%d", &n2);
        }
       //inicio apartir do 1 porque não tem divisão por zero indeterminado ou infinito
        for(j = 1; j <= n; j++){
            if(n % j == 0){
                //primeiro numero
                if(i == 0){
                    for(k = 1; k <= n2; k++){
                        if(n2 % k == 0){
                            if(j == k){
                                auxiliar = k;
                            }
                        }
                    }
                }else if(j == auxiliar){
                    auxiliar = j;
                }
            }
        }
      if(i < 2){
        i = 2; 
      }else{
          i++;
      }
    }
    printf("\nMaior MDC dos numeros eh %d\n", auxiliar);
    return 0;
}