//Programa que calcula o fatorial de um numero
#include <stdio.h>

int main(){
    int n, i, temporario;
    printf("Entre com um inteiro para calular o fatorial: ");
    scanf("%d", &n);
    if( n == 0){
        printf("%d! = %d\n", n, 1);
    }else if(n == 1){
        printf("%d! = %d\n", n, 1);
    }else{
       /* temporario = 1;
        for(i = 1; i < n; i++){
            temporario = temporario*i;
        }
        temporario *= n;
         printf("%d! = %d\n",n, temporario    );
        */
        temporario = n;
        for(i = 1; i < n; i++){
            temporario *=(n-i);
        }
       printf("%d! = %d\n",n, temporario    );
    }
    return 0;
}