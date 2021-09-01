#include <stdio.h>
#include <stdlib.h>
//prototipos
void fib(FILE *file, int n, int trinta_primeiros, int ultimo_numero, int atual);
int main()
{
    FILE *file;
    int n, valor_lido;
    file = fopen("seq_fib.dat", "rb");
    if(file == NULL){
        printf("Error ao criar o arquivo\n");
    }else{
        printf("Informe qual valor deseja ler: ");
        scanf("%d", &n);
        if((n>= 1) && (n <= 30)){
            //operação valida
            fseek(file, n * sizeof(int), SEEK_CUR);
            fread(&valor_lido, sizeof(int), 1, file);
            printf("o %d elemento do fibo eh %d\n", n, valor_lido);
        }else{
            printf("Impossivel realizar operacao\n");
        }
       
    }
    fclose(file);
   
    return 0;
}