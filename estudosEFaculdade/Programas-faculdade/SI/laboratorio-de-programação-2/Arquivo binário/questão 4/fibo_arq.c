#include <stdio.h>
#include <stdlib.h>
//prototipos
void fib(FILE *file, int n, int trinta_primeiros, int ultimo_numero, int atual);
int main()
{
    FILE *file;
    file = fopen("seq_fib.dat", "wb");
    if(file == NULL){
        printf("Error ao criar o arquivo\n");
    }else{
        //para inicio do arquivo
        fseek(file, sizeof(int), SEEK_SET);
        fib(file, 1, 30, 0, 0);
    }
    fclose(file);
    printf("Gerado com sucesso!\n");
    return 0;
}
void fib(FILE *file, int n, int trinta_primeiros, int ultimo_numero, int atual){
   if(n == 1){
        fwrite(&atual, sizeof(int), 1, file);
        printf("%d ", atual);
        fib(file, n+1, trinta_primeiros -1, ultimo_numero, atual);
   }else if((n > 1) && (n <=3)){
        ultimo_numero = atual = 1;
        printf("%d ", atual);

        fwrite(&atual , sizeof(int),1, file);
        fib(file, n+1, trinta_primeiros -1, atual,ultimo_numero +  atual);
   }else if(trinta_primeiros <= 0){
        printf("\n");
        return;
   }else{
        printf("%d ", atual);
        fwrite(&atual , sizeof(int),1, file);
        fib(file, n+1, trinta_primeiros -1,atual, ultimo_numero + atual);
   }
}
