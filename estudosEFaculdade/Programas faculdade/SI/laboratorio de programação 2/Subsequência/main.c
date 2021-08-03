#include <stdio.h>
#include <stdlib.h>
//PROTÓTIPO
int subsequencia(int maior, int menor);
int main()
{
   int numero_a, numero_b;
   printf("Entre com o numeros: ");
   scanf("%d%d", &numero_a, &numero_b);
   //a menor que b
    if(numero_a < numero_b){
         if(subsequencia(numero_b, numero_a)){
            printf("%d   %d -> b eh subsequencia de a", numero_a, numero_b);
        }else{
            printf("um nao eh subsequencia do outro");
        }
    }
    //a maior que b
    else if( numero_a > numero_b){
             if(subsequencia(numero_a, numero_b)){
            printf("%d   %d -> b eh subsequencia de a", numero_a, numero_b);
        }else{
            printf("um nao eh subsequencia do outro");
        }
    }
    //b menor que a
    else if (numero_b < numero_a){
        if(subsequencia(numero_a, numero_b)){
            printf("%d   %d -> b eh subsequencia de a", numero_a, numero_b);
        }else{
            printf("um nao eh subsequencia do outro");
        }
    }
    //b maior que a
    else if (numero_b > numero_a){
         if(subsequencia(numero_b, numero_a)){
            printf("%d   %d -> b eh subsequencia de a", numero_a, numero_b);
        }else{
            printf("um nao eh subsequencia do outro");
        }
    }
    return 0;
}
int subsequencia(int maior, int menor){
    int digito_a[100], digito_b[100], i, j, tamanho_a, tamanho_b;
    int flag = 0;
    i = 0;
    j = 0;
    tamanho_a = 0;
    tamanho_b = 0;
    while(maior !=0){
        //obter o digito mais a direita
        digito_a[i] = maior % 10;
        if(menor != 0){
            digito_b[j] = menor % 10;
            j++;
            tamanho_b++;
        }

        //remove o digito
        maior = maior /10;
        menor = menor /10;
        i++;
        tamanho_a++;
        /*if(digito_a != digito_b){
            return 0;
        }*/
    }
    for(j = 0; j < tamanho_b; j++ ){
        for(i = 0; i < tamanho_a; i++){
            if(digito_a[i] == digito_b[j]){
                printf("%d    %d\n", digito_a[i], digito_b[j]);
                flag ++;
            }
        }
    }
    //se flag igual ao tamanho do menor então é subsequencia
    if(flag == tamanho_b){
        return 1;
    }else{
        return 0;
    }
}
