#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a, b;
    FILE *file;
    FILE *file_resultado_soma;
    file = fopen("entrada.dat", "rb");
    if(file == NULL){
        printf("ERROR");
    }else{
        fseek(file, sizeof(int), SEEK_SET);
        fread(&a, sizeof(int), 1, file);
        fread(&b, sizeof(int), 1, file);
        a += b;
        file_resultado_soma = fopen("saida.dat", "wb");
        if(file_resultado_soma == NULL){
            printf("ERROR");
        }else{
            //APONTA PARA O INICIO
            fseek(file_resultado_soma, sizeof(int), SEEK_SET);
            fwrite(&a, sizeof(int), 1, file_resultado_soma);
        }
    }
    fclose(file);
    fclose(file_resultado_soma);
    return 0;
}
