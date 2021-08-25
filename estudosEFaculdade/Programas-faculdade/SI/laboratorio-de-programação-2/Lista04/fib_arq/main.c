#include <stdio.h>
#include <stdlib.h>
//prototipos
void fib(FILE *file, int n, int trinta_primeiros, int ultimo_numero, int atual);
int main()
{
    FILE *file;
    file = fopen("30_fib.txt", "w");
    if(file == NULL){
        printf("Error ao criar o arquivo\n");
    }else{
        fib(file, 1, 30, 0, 0);
        fclose(file);
    }
    printf("Gerado com sucesso!\n");
    return 0;
}
void fib(FILE *file, int n, int trinta_primeiros, int ultimo_numero, int atual){
   if(n == 1){
        fprintf(file, "%d ", atual);
         fib(file, n+1, trinta_primeiros -1, ultimo_numero, atual);
   }else if(n <= 3){
       ultimo_numero = atual = 1;
        fprintf(file, "%d ", atual);
         fib(file, n+1, trinta_primeiros -1, ultimo_numero, atual);
   }else if(trinta_primeiros <= 0){
        return;
   }else{
        fprintf(file, "%d ",ultimo_numero + atual );
        fib(file, n+1, trinta_primeiros -1,atual, ultimo_numero + atual);
   }
}
