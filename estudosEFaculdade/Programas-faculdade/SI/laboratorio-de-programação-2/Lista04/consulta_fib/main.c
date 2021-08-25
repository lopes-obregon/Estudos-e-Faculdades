#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *file;
   int n;
   int valor_lido;
   file = fopen("30_fib.txt", "r");
   if(file == NULL){
        printf("Error ao abrir o programa");
   }else{
        printf("Digite um numero\n");
        scanf("%d", &n);
        if((n >= 1) && (n <= 30)){

            if(n == 1){
                fscanf(file, "%d", &valor_lido);
                printf("Valor eh %d\n", valor_lido);
            }else{
                printf("Valores lidos\n");
                fscanf(file, "%d", &valor_lido);
                printf("%d ", valor_lido);
                while((!feof(file)) && (n >= 2) ){
                    fscanf(file, "%d ", &valor_lido);
                    printf("%d ", valor_lido);
                    n--;
                }
                fclose(file);
            }

        }else{
            printf("Valor invalido!\n");
        }

   }
    return 0;
}
