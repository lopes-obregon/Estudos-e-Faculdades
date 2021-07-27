#include <stdio.h>

/*Programa que calcula o ano bissexto
*de  4 em 4 anos bissexto
* 100 em 100 não é bissexto
*400 em 400 é bissexto
*prevalece a ultima regra sobre a primeira*/

int main(){
    unsigned int ano;
    printf("Informe o ano para saber se é bissexto ou não: ");
    scanf("%d", &ano);
   if(ano % 400 == 0){
       printf("\nAno é bissexto\n");
   }else{
       if(ano % 100 == 0){
           printf("\nAno não é bissexto\n");
       }else{
           if(ano % 4 == 0){
               printf("\nAno é bissexto\n");
           }else{
                printf("\nAno não é bissexto\n");
            }
       }
   }
    
    return 0;
}